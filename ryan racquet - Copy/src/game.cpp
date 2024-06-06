#include "game.hpp"
#include <vector>

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

    ryan.Draw();

}

void Game::Update()
{
    if(run){
        for(auto& ball: enemy.balls){
            ball.Update(&ryan);
            
        }

        if(enemy.balls.empty() || !enemy.balls.back().active) {
            enemy.SpawnBall();
            if(score >= 20){
                enemy.SpawnBall();
            }
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
