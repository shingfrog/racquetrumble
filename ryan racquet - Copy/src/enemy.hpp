#pragma once
#include <raylib.h>
#include <vector>

class Ball;

class Enemy
{
    public:
    Enemy();
    //Rectangle getEnemyRec(Vector2 position, float width, float height);
    void SpawnBall();

    std::vector<Ball> balls;

    private:
    Vector2 GetSpawnPoint();
    Vector2 positions[4] = {{450.0f, 32.0f}, {27.0f, 450.0f}, {872.0f, 450.0f}, {450.0f, 866.0f}};
};