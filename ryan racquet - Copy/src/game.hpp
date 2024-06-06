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

    private:
    Ryan ryan = Ryan({445,445});
    Enemy enemy;

    void DeleteInactiveBalls();
};