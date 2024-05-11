// #include "game.h"
// #include <raylib.h>

// void Ball::Update()
// {
//     x += speed_x;
//     y += speed_y;

//     if (x + radius >= GetScreenWidth() || x - radius <= 0)
//         speed_x *= -1;

//     if (y + radius >= GetScreenHeight() || y - radius <= 0)
//         speed_y *= -1;
// }

// void Ball::Draw()
// {
//     DrawCircle(x, y, radius, WHITE);
// }

// void Ryan::Draw()
// {
//     DrawRectangle(x, y, width, height, WHITE);
// }

// void Ryan::Update()
// {
//     if(IsKeyDown(KEY_UP)){
//         y = 350;
//         x = 635;
//     }

//     if(IsKeyDown(KEY_LEFT)){
//         y = 395;
//         x = 590;
//     }

//     if(IsKeyDown(KEY_RIGHT)){
//         y = 395;
//         x = 690;
//     }

//     if(IsKeyDown(KEY_DOWN)){
//         y = 450;
//         x = 635;
//     }
// }

// void Enemy::Draw()
// {
//     DrawRectangle(x, y, width, height, WHITE);
// }