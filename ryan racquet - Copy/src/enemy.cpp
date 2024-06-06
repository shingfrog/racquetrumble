#include "enemy.hpp"
#include "ball.hpp"

Enemy::Enemy()
{
}

// Enemy Rectangle Enemy::getEnemyRec(Vector2 position, float width, float height)
// {
//     return Enemy Rectangle(position.x, position.y, width, height);
// }


void Enemy::SpawnBall()
{
    Vector2 position = GetSpawnPoint();
    Texture2D ballImage = LoadTexture("media/ball.png");
    balls.push_back(Ball(position, ballImage, 3));
}

Vector2 Enemy::GetSpawnPoint() {
  int randomIndex = GetRandomValue(0,3);
  return positions[randomIndex];
}