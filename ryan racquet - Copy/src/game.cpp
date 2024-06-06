#include "game.hpp"
#include <vector>
#include <iostream>

Game::Game()
{
    run = true;
}

Game::~Game()
{
    for(auto& ball: enemy.balls){
        UnloadTexture(ball.GetTexture());
    }
}

void Game::Draw()
{
    for(auto& ball: enemy.balls){
        ball.Draw();
    }

    DrawText(TextFormat("Score: %i", score), 10, 10, 30, WHITE);
    DrawText(TextFormat("Health: %i", ryan.health), 10, 50, 30, WHITE);

    DrawText("Press WASD or Arrow Keys to move Ryan", 10, 830, 15, WHITE);
    DrawText("Press TAB to pause the game", 10, 860, 20, WHITE);



    ryan.Draw();

    if (ryan.healthDecreased) {
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(RED, 0.6f));
        ryan.healthDecreased = false; 
        PlaySound(hit);
    }

}

void Game::Update()
{
    if(run){
        for(auto& ball: enemy.balls){
            ball.Update(&ryan);
            
        }

        SetSoundVolume(ballSound, 0.5f);
        if(enemy.balls.empty() || !enemy.balls.back().active) {
            enemy.SpawnBall();
            PlaySound(ballSound);
            if(score >= 20){
                PlaySound(ballSound);
                enemy.SpawnBall();
            }
        }

        if(score > lastScore && score % 25 == 0){
            ryan.health++;
            lastScore = score;
        }

        if(ryan.health <= 0){
            GameOver();
        }

        DeleteInactiveBalls();
    }
}

void Game::HandleInput()
{
    if(run){
        ryan.moveRyan();
    }
}

void Game::Reset()
{
    ryan.Reset();
    enemy.Reset();
    score = 0;
    run = true;
}

void Game::GameOver()
{
    run = false;
}

int Game::GetFinalScore()
{
    if(ryan.health == 0){
        return score;
    }
    return score;
}

void Game::DeleteInactiveBalls()
{
    for(auto it = enemy.balls.begin(); it != enemy.balls.end();){
        if(!it -> active){
            UnloadTexture(it->GetTexture());
            if (it->getBallPosition().x >= 433 && it->getBallPosition().x <= 450 && 
                it->getBallPosition().y >= 433 && it->getBallPosition().y <= 450) {
            } else {
                score++; 
            }
            it = enemy.balls.erase(it);
        } else{
            ++it;
        }
    }
}
