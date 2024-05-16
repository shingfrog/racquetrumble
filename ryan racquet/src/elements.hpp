#pragma once
#include <raylib.h>

class Ryan {
    public:
        float x,y;
        float width, height;

        void Draw();
        void Update();
};

class Ball {
    public:
        Vector2 position;
        int radius;
        double speed;

        Ball(Vector2 position, double speed, int radius, Color color);
        void Draw();
        void UpdateX(Ryan* ryan, int&);
        void UpdateY(Ryan* ryan, int&);
    private:
        float scale;
        Color color;
        Texture2D ballTexture;
};

class Enemy {
    public:
        float x,y;
        float width, height;

        void Draw();
};

