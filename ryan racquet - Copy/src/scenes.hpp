#pragma once
#include <raylib.h>
#include "button.hpp"
#include "game.hpp"


enum GameScreen 
{ 
    LOGO = 0, TITLE, GAMEPLAY, ENDING 
};

class Scenes
{
    public:
    void updateLogoScreen(int framesCounter, GameScreen* currentScreen);
    void updateTitleScreen(GameScreen* currentScreen, Button& playButton);
    void updateGameplayScreen(GameScreen* currentScreen, Button& restartButton);
    void updateEndingScreen(GameScreen* currentScreen, Button& restartButton);
    void drawCurrentScreen(GameScreen currentScreen);

    void drawLogoScreen();
    void drawTitleScreen();
    void drawGameplayScreen();
    void drawEndingScreen();

    private:
    Game game;
    int framesCounter;
    int screenwidth = 900;
    int screenheight = 900;
    bool Paused = false;
    
    Texture2D background= LoadTexture("media/bg.png");
    Texture2D court = LoadTexture("media/courtsFinal.png");

    Texture2D logo = LoadTexture("media/logo atlas.png");
    Rectangle logoSource {1634.25f, 0.f, (float)logo.width / 4, (float)logo.height};
    Vector2 logoPosition {177.625f, 200.f};
};

