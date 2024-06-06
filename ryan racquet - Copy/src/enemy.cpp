#include "enemy.hpp"
#include "ball.hpp"

Enemy::Enemy()
{
  
}

void Enemy::SpawnBall()
{
  Vector2 position = GetSpawnPoint();
  Texture2D ballImage = LoadTexture("media/ball.png");
  balls.push_back(Ball(position, ballImage, UpdateSpeed()));
}

int Enemy::UpdateSpeed()
{
  return GetRandomValue(3,7);
}

void Enemy::Reset()
{
  balls.clear();
}

Vector2 Enemy::GetSpawnPoint() {
  int randomIndex = GetRandomValue(0,3);
  return positions[randomIndex];
}
