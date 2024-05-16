#include <raylib.h>
#include <iostream>
#include "elements.hpp"

int score = 0;

//int UpdateMultiplier() {
//  static int speedMultiplier = 1;
//  if (int(GetFrameTime()) % 10000 == 0) {
//    speedMultiplier++;
//  }
//  return speedMultiplier;
//}


void Ball::UpdateX(Ryan* ryan, int& score) 
{
        position.x += speed;
        if (CheckCollisionCircleRec(Vector2{position.x, position.y}, radius, Rectangle{ryan->x, ryan->y, ryan->width, ryan->height})) {
            speed *= -1;
            score++;
        }
        if (position.x + radius >= GetScreenWidth() || position.x - radius <= 0){
            speed *= -1;
        }
}

void Ball::UpdateY(Ryan* ryan, int& score) 
{
        position.y += speed;
        if (CheckCollisionCircleRec(Vector2{position.x, position.y}, radius, Rectangle{ryan->x, ryan->y, ryan->width, ryan->height})) {
            speed *= -1;
            score++;
        }
        if (position.y + radius >= GetScreenHeight() || position.y - radius <= 0){
            speed *= -1;
        }
}

Ryan ryan;
Ball ball_one = Ball({450, 225}, 5, 5, PINK);
Ball ball_two = Ball({225, 450}, 5, 5, BLACK);
Ball ball_three = Ball({675, 450}, 5, 5, SKYBLUE);
Ball ball_four = Ball({450, 675}, 5, 5, MAROON);


int main()
{
    const int screenWidth = 900;
    const int screenHeight = 900;
    InitWindow(screenWidth, screenHeight, "Racquet Rumble");
    SetTargetFPS(60);

    //Texture2D ballTexture = LoadTexture("./media//tennis exp.png");

    // ball_one.ballTexture = ballTexture;
    // ball_two.ballTexture = ballTexture;
    // ball_three.ballTexture = ballTexture;
    // ball_four.ballTexture = ballTexture;

    ryan.x = 450;
    ryan.y = 450;
    ryan.width = 10;
    ryan.height = 10;


    while (!WindowShouldClose())
    {
        BeginDrawing();

        ryan.Update();
        ball_one.UpdateY(&ryan, score);
        ball_two.UpdateX(&ryan, score);
        ball_three.UpdateX(&ryan, score);
        ball_four.UpdateY(&ryan, score);
        //DrawTextureEx(ball, Vector2{200, 200}, 0, .02, WHITE);

        if(CheckCollisionCircleRec(Vector2{ball_one.position.x, ball_one.position.y}, ball_one.radius, Rectangle{440, 200, 20, 10})){
            ball_one.speed *= -1;
        }

        if(CheckCollisionCircleRec(Vector2{ball_two.position.x, ball_two.position.y}, ball_two.radius, Rectangle{200, 440, 10, 20})){
            ball_two.speed *= -1;
        }

        if(CheckCollisionCircleRec(Vector2{ball_three.position.x, ball_three.position.y}, ball_three.radius, Rectangle{700, 440, 10, 20})){
            ball_three.speed *= -1;
        }

        if(CheckCollisionCircleRec(Vector2{ball_four.position.x, ball_four.position.y}, ball_four.radius, Rectangle{440, 700, 20, 10})){
            ball_four.speed *= -1;
        }

        ClearBackground(LIGHTGRAY);
        
        ryan.Draw();
        ball_one.Draw(); // ball up
        ball_two.Draw(); // ball left
        ball_three.Draw(); // ball right
        ball_four.Draw(); // ball down

        DrawText(TextFormat("%.2f", GetFrameTime()), 40, 40 , 30, WHITE);
        DrawText(TextFormat("%.i", score), 450, 100, 30, WHITE);

        DrawRectangle(440, 200, 20, 10, WHITE); //enemy 1
        DrawRectangle(200, 440, 10, 20, WHITE); //enemy 2
        DrawRectangle(700, 440, 10, 20, WHITE); //enemy 3
        DrawRectangle(440, 700, 20, 10, WHITE); //enemy 4

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
