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
    
    Button restartButton = Button({ 350, 500, 200, 50 }, RED, BLACK, "Restart");

    if(Paused){
        DrawTexture(court, 0, 0, WHITE);
        game.Draw();
        DrawRectangle(0, 0, 900, 900, CLITERAL(Color){ 255, 255, 255, 60 });
        DrawText("Paused", 400, 400, 40, BLACK);
        restartButton.drawButton(); 
    }
}

void Scenes::drawEndingScreen()
{
    DrawTexture(background, 0, 0, WHITE);
    Button restartButton = Button({ 350, 500, 200, 50 }, RED, BLACK, "Play Again");
    restartButton.drawButton(); 

    DrawText("YOU DIED", 400, 400, 40, BLACK);

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

void Scenes::updateGameplayScreen(GameScreen* currentScreen, Button& restartButton) 
{
    if(IsKeyPressed(KEY_TAB)){
        Paused = !Paused;
    }

    if (restartButton.isPressed()) {
        Paused = !Paused;
        game.Reset();
    }   

    if(game.run == false){
        *currentScreen = ENDING;
    }
}   


void Scenes::updateEndingScreen(GameScreen* currentScreen, Button& restartButton) 
{
    if (restartButton.isPressed()) {
        *currentScreen = GAMEPLAY;
        game.Reset();
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
