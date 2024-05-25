#pragma once
#include <raylib.h>

class Ryan {
public:
    Vector2 position;
    float width, height;
    int health;

    Ryan(Vector2 position, float width, float height, int health);
    void Draw();
    void Update();
};

class Ball {
public:
    Vector2 position;
    int radius;
    double speed;
    Color color;

    Ball(Vector2 position, double speed, int radius, Color color);
    void Draw();
    void UpdateX(Ryan* ryan, int& score, Rectangle& enemy);
    void UpdateY(Ryan* ryan, int& score, Rectangle& enemy);
    //void Reset(Ryan* ryan, int& score);
};

class Enemy {
public:
    Rectangle rect; 

    Enemy(const Rectangle& rect); 
    void Draw();
};
