#include <raylib.h>
#include "scenes.hpp"
#include "button.hpp"
#include "game.hpp"

void Scenes::drawLogoScreen()
{
    DrawTexture(background, 0, 0, WHITE);
    DrawTextureRec(logo, logoSource, logoPosition, WHITE);
}

void Scenes::drawTitleScreen() 
{
    DrawTexture(background, 0, 0, WHITE);
    DrawTextureRec(logo, logoSource, logoPosition, WHITE);
    
    Button playButton = Button({ 350, 694, 200, 50 }, RED, BLACK, "Play");
    playButton.drawButton(); 
    
}

void Scenes::drawGameplayScreen()
{
    if(!Paused){
        DrawTexture(court, 0, 0, WHITE);    
        game.Draw();
        game.HandleInput();
        game.Update();
    }

    if(Paused){
        DrawTexture(court, 0, 0, WHITE);
        game.Draw();
        DrawRectangle(0, 0, 900, 900, CLITERAL(Color){ 255, 255, 255, 60 });
        DrawText("Paused", 430, 430, 40, BLACK);
    }
}

void Scenes::drawEndingScreen()
{
    DrawRectangle(0, 0, screenwidth, screenheight, BLUE);
    DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
}

void Scenes::updateLogoScreen(int framesCounter, GameScreen* currentScreen)
{
    framesCounter++;
    if (framesCounter > 180) {
        *currentScreen = TITLE;
    }
}

void Scenes::updateTitleScreen(GameScreen* currentScreen, Button& playButton) 
{
    if (playButton.isPressed()) {
        *currentScreen = GAMEPLAY;
    }
}

void Scenes::updateGameplayScreen(GameScreen* currentScreen) 
{
    if(IsKeyPressed(KEY_TAB)){
            Paused = !Paused;
    }

    if(IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        *currentScreen = GAMEPLAY;
    }     
}   


void Scenes::updateEndingScreen(GameScreen* currentScreen) 
{
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        *currentScreen = GAMEPLAY;
    }     
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
      drawGameplayScreen();
      break;
    case GameScreen::ENDING:
      drawEndingScreen();
      break;
    default:
      break;
  }
}
