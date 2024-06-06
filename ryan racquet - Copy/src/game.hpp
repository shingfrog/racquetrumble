#pragma once
#include <raylib.h>
#include <vector>
#include "ball.hpp"
#include "ryan.hpp"
#include "enemy.hpp"

class Game
{
public:
    Game();
    ~Game();
    
    void Draw();
    void Update();
    void HandleInput();
    void Reset();
    void GameOver();
    int GetFinalScore();

    bool run;
private:
    Ryan ryan = Ryan({455,455});
    Enemy enemy;
    int score = 0;
    int lastScore;
    void DeleteInactiveBalls();
    Sound ballSound = LoadSound("sound/tennis-ball-hit-01.mp3");
    Sound hit = LoadSound("sound/8-Bit Hit Sound Effect.wav");
};