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

void Scenes::drawInstructionScreen()
{
    DrawTexture(instruct, 0, 0, WHITE);
    Button nextButton = Button({ 660, 810, 200, 50 }, GREEN, BLACK, "Continue");
    nextButton.drawButton(); 
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
        DrawRectangle(0, 0, 900, 900, CLITERAL(Color){ 255, 255, 255, 80 });
        DrawTextCentered("PAUSED", 40, 400, BLACK);
        restartButton.drawButton(); 
    }
}

void Scenes::drawEndingScreen()
{
    DrawTexture(background, 0, 0, WHITE);
    Button restartButton = Button({ 350, 500, 200, 50 }, RED, BLACK, "Play Again");    
    restartButton.drawButton(); 

    DrawTextCentered("YOU DIED", 60, 400, BLACK);
    DrawTextCentered(TextFormat("Final Score: %i", game.GetFinalScore()), 50, 300, BLACK);

}

void Scenes::DrawTextCentered(const char *text, int fontSize, float posY, Color color)
{
    int textWidth = MeasureText(text, fontSize);
    int x = (GetScreenWidth() - textWidth) / 2;
    DrawText(text, x, posY, fontSize, color);
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
        PlaySound(click);
        *currentScreen = INSTRUCTION;
    }
}

void Scenes::updateInstructionScreen(GameScreen *currentScreen, Button& nextButton)
{
    if (nextButton.isPressed()) {
        PlaySound(click);
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
        PlaySound(click);
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
        PlaySound(click);
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
    case GameScreen::INSTRUCTION:
      drawInstructionScreen();
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
