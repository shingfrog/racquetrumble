#include <raylib.h>
#include "scene.hpp"
#include "elements.hpp"
//#include "button.hpp"

    int score = 0;

    Ryan ryan = Ryan({450, 450}, 10, 10, 3);
    Ball ball_one = Ball({450, 173}, 1, 5, PINK);
    Ball ball_two = Ball({256, 450}, 1, 5, BLACK);
    Ball ball_three = Ball({600, 450}, 1, 5, SKYBLUE);
    Ball ball_four = Ball({450, 700}, 1, 5, MAROON);

    Rectangle enemy1 = {440, 100, 20, 10};
    Rectangle enemy2 = {100, 440, 10, 20};
    Rectangle enemy3 = {800, 440, 10, 20};
    Rectangle enemy4 = {440, 800, 20, 10};

void Scenes::updateLogoScreen(int framesCounter, GameScreen* currentScreen)
{
    framesCounter++;
    if (framesCounter > 180) {
        *currentScreen = TITLE;
    }
}

void Scenes::updateTitleScreen(GameScreen* currentScreen) 
{
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        *currentScreen = GAMEPLAY;
    }     
}

void Scenes::updateGameplayScreen(GameScreen* currentScreen) 
{
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        *currentScreen = ENDING;
    }    
}

void Scenes::updateEndingScreen(GameScreen* currentScreen) 
{
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        *currentScreen = GAMEPLAY;
    }     
}

void Scenes::drawLogoScreen()
{
    DrawText("Racquet Rumble Logo", screenwidth/4, screenheight/3, 40, BLACK);
    //DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);
}

void Scenes::drawTitleScreen()
{
    DrawRectangle(0, 0, screenwidth, screenheight, GREEN);
    DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
    DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);
}

void Scenes::drawGameplayScreen(Ryan* ryan, Ball* ball_one, Ball* ball_two, Ball* ball_three, Ball* ball_four, int& score, Rectangle& enemy1, Rectangle& enemy2, Rectangle& enemy3, Rectangle& enemy4)
{
        ryan->Update();
        ball_one->UpdateY(ryan, score, enemy1);
        ball_two->UpdateX(ryan, score, enemy2);
        ball_three->UpdateX(ryan, score, enemy3);
        ball_four->UpdateY(ryan, score, enemy4);

        ClearBackground(LIGHTGRAY);

        ryan->Draw();
        ball_one->Draw(); // ball up
        ball_two->Draw(); // ball left
        ball_three->Draw(); // ball right
        ball_four->Draw(); // ball down

        DrawText(TextFormat("%.1f", GetTime()), 40, 40, 30, WHITE);
        DrawText(TextFormat("%i", ryan->health), 100, 40, 30, WHITE);
        DrawText(TextFormat("%i", score), 300, 100, 30, WHITE);

        DrawRectangle(enemy1.x, enemy1.y, enemy1.width, enemy1.height, WHITE); 
        DrawRectangle(enemy2.x, enemy2.y, enemy2.width, enemy2.height, WHITE); 
        DrawRectangle(enemy3.x, enemy3.y, enemy3.width, enemy3.height, WHITE); 
        DrawRectangle(enemy4.x, enemy4.y, enemy4.width, enemy4.height, WHITE);
}

void Scenes::drawEndingScreen()
{
    DrawRectangle(0, 0, screenwidth, screenheight, BLUE);
    DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
}


void Scenes::drawCurrentScreen(GameScreen currentScreen) {
  switch (currentScreen) {
    case GameScreen::LOGO:
      drawLogoScreen();
      break;
    case GameScreen::TITLE:
      drawTitleScreen();
      break;
    case GameScreen::GAMEPLAY:
      drawGameplayScreen(&ryan, &ball_one, &ball_two, &ball_three, &ball_four, score, enemy1, enemy2, enemy3, enemy4);
      break;
    case GameScreen::ENDING:
      drawEndingScreen();
      break;
    default:
      break;
  }
}
