#include "game.hpp"
#include <vector>

Game::Game()
{

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
    
    ryan.Draw();

    //DrawText(TextFormat("Score: %i", balls.score), 10, 10, 30, WHITE);

}

void Game::Update()
{
    for(auto& ball: enemy.balls){
        ball.Update();
    }

    DeleteInactiveBalls();
}

void Game::HandleInput()
{
    ryan.moveRyan();

    if(IsKeyPressed(KEY_SPACE)){
        enemy.SpawnBall();
    }
}

void Game::DeleteInactiveBalls()
{
    for(auto it = enemy.balls.begin(); it != enemy.balls.end();){
        if(!it -> active){
            UnloadTexture(it->GetTexture());
            it = enemy.balls.erase(it);
        } else{
            ++it;
        }
    }
}
