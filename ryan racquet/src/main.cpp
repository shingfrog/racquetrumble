#include <raylib.h>

int score = 0;

class Ryan {
    public:
        float x,y;
        float width, height;

        void Draw() {
            DrawRectangle(x, y, width, height, WHITE);
        }

        void Update() {
            if(IsKeyDown(KEY_UP)){
                y = 350;
                x = 635;
            }

            if(IsKeyDown(KEY_LEFT)){
                y = 395;
                x = 590;
            }

            if(IsKeyDown(KEY_RIGHT)){
                y = 395;
                x = 690;
            }

            if(IsKeyDown(KEY_DOWN)){
                y = 450;
                x = 635;
            }
        }
};

class Ball {
    public:
        float x, y;
        int speed_x, speed_y;
        int radius;
        Color color;

        void Draw() {
            DrawCircle(x, y, radius, color);
        }

        void Update(Ryan* ryan) {
            x += speed_x;
            y += speed_y;

        if (CheckCollisionCircleRec(Vector2{x, y}, radius, Rectangle{ryan->x, ryan->y, ryan->width, ryan->height})) {
            speed_x *= -1;
            speed_y *= -1;
            score++;
        }

        if (x + radius >= GetScreenWidth() || x - radius <= 0){
            speed_x *= -1;
        }
        if (y + radius >= GetScreenHeight() || y - radius <= 0){
            speed_y *= -1;
        }
    }
};

Ryan ryan;

Ball ball_one;
Ball ball_two;
Ball ball_three;
Ball ball_four;


int main()
{
    const int screenWidth = 1280;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Racquet Rumble");
    SetTargetFPS(60);

    ball_one.radius = 5;
    ball_one.x = 640;
    ball_one.y = 200;
    ball_one.speed_x = 0;
    ball_one.speed_y = 5;
    ball_one.color = PINK;

    ball_two.radius = 5;
    ball_two.x = 320;
    ball_two.y = 400;
    ball_two.speed_x = 5;
    ball_two.speed_y = 0;
    ball_two.color = WHITE;

    ball_three.radius = 5;
    ball_three.x = 960;
    ball_three.y = 400;
    ball_three.speed_x = 5;
    ball_three.speed_y = 0;
    ball_three.color = SKYBLUE;

    ball_four.radius = 5;
    ball_four.x = 640;
    ball_four.y = 600;
    ball_four.speed_x = 0;
    ball_four.speed_y = 5;
    ball_four.color = MAROON;

    ryan.x = 635;
    ryan.y = 395;
    ryan.width = 10;
    ryan.height = 10;


    while (!WindowShouldClose())
    {
        BeginDrawing();

        ryan.Update();
        ball_one.Update(&ryan);
        ball_two.Update(&ryan);
        ball_three.Update(&ryan);
        ball_four.Update(&ryan);

        if(CheckCollisionCircleRec(Vector2{ball_one.x, ball_one.y}, ball_one.radius, Rectangle{630, 150, 20, 10})){
            ball_one.speed_y *= -1;
        }

        if(CheckCollisionCircleRec(Vector2{ball_two.x, ball_two.y}, ball_two.radius, Rectangle{270, 390, 10, 20})){
            ball_two.speed_x *= -1;
        }

        if(CheckCollisionCircleRec(Vector2{ball_three.x, ball_three.y}, ball_three.radius, Rectangle{1010, 390, 10, 20})){
            ball_three.speed_x *= -1;
        }

        if(CheckCollisionCircleRec(Vector2{ball_four.x, ball_four.y}, ball_four.radius, Rectangle{630, 650, 20, 10})){
            ball_four.speed_y *= -1;
        }

        // if (CheckCollisionCircleRec(Vector2{ball_one.x, ball_one.y}, ball_one.radius, Rectangle{635, 350, 10, 10})) {
        //     ball_one.speed_y *= -1;
        // } 

        // if(CheckCollisionCircleRec(Vector2{ball_two.x, ball_two.y}, ball_two.radius, Rectangle{590, 395, 10, 10})){
        //     ball_two.speed_x *= -1;
        // }

        // if(CheckCollisionCircleRec(Vector2{ball_three.x, ball_three.y}, ball_three.radius, Rectangle{690, 395, 10, 10})){
        //     ball_three.speed_x *= -1;
        // }

        // if(CheckCollisionCircleRec(Vector2{ball_four.x, ball_four.y}, ball_four.radius, Rectangle{635, 450, 10, 10})){
        //     ball_four.speed_y *= -1;
        // }

        ClearBackground(LIGHTGRAY);
        
        ryan.Draw();
        ball_one.Draw(); // ball up
        ball_two.Draw(); // ball left
        ball_three.Draw(); // ball right
        ball_four.Draw(); // ball down

        DrawText(TextFormat("%f", GetTime()), 40, 40 , 30, WHITE);
        DrawText(TextFormat("%i", score), 40, 400 , 30, WHITE);

        DrawRectangle(630, 150, 20, 10, WHITE); //enemy 1
        DrawRectangle(270, 390, 10, 20, WHITE); //enemy 2
        DrawRectangle(1010, 390, 10, 20, WHITE); //enemy 3
        DrawRectangle(630, 650, 20, 10, WHITE); //enemy 4

        EndDrawing();
    }

    CloseWindow();
    return 0;
}