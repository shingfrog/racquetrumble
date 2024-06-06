#pragma once
#include <raylib.h>
#include "button.hpp"
#include "game.hpp"


enum GameScreen 
{ 
    LOGO = 0, TITLE, GAMEPLAY, ENDING, INSTRUCTION 
};

class Scenes
{
    public:
    void updateLogoScreen(int framesCounter, GameScreen* currentScreen);
    void updateTitleScreen(GameScreen* currentScreen, Button& playButton);
    void updateInstructionScreen(GameScreen* currentScreen, Button& nextButton);
    void updateGameplayScreen(GameScreen* currentScreen, Button& restartButton);
    void updateEndingScreen(GameScreen* currentScreen, Button& restartButton);
    void drawCurrentScreen(GameScreen currentScreen);

    void drawLogoScreen();
    void drawTitleScreen();
    void drawInstructionScreen();
    void drawGameplayScreen();
    void drawEndingScreen();

    void DrawTextCentered(const char *text, int fontSize, float posY, Color color);

    bool Paused = false;

    private:
    Game game;
    int framesCounter;
    int screenwidth = 900;
    int screenheight = 900;

    Sound click = LoadSound("sound/click .wav");
    Texture2D background= LoadTexture("media/bg.png");
    Texture2D court = LoadTexture("media/courtsFinal.png");
    Texture2D instruct = LoadTexture("media/instruct.png");

    Texture2D logo = LoadTexture("media/logo atlas.png");
    Rectangle logoSource {1634.25f, 0.f, (float)logo.width / 4, (float)logo.height};
    Vector2 logoPosition {164.0f, 171.0f};
};

