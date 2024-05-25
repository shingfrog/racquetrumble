#pragma once
#include <raylib.h>
#include "elements.hpp"


enum GameScreen 
{ 
    LOGO = 0, TITLE, GAMEPLAY, ENDING 
};

class Scenes
{
    public:
    int framesCounter;
    int screenwidth = 900;
    int screenheight = 900;
    
    void updateLogoScreen(int framesCounter, GameScreen* currentScreen);
    void updateTitleScreen(GameScreen* currentScreen);
    void updateGameplayScreen(GameScreen* currentScreen);
    void updateEndingScreen(GameScreen* currentScreen);
    void drawCurrentScreen(GameScreen currentScreen);

    void drawLogoScreen();
    void drawTitleScreen();
    void drawGameplayScreen(Ryan*, Ball*, Ball*, Ball*, Ball*, int&, Rectangle&, Rectangle&, Rectangle&, Rectangle&);
    void drawEndingScreen();
};

