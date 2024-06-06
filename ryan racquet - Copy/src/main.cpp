#include <raylib.h>
#include "scenes.hpp"
#include "button.hpp"

int main() {
    InitWindow(900, 900, "Ryan VS The Forces of Evil");
    SetTargetFPS(60); 

    int framesCounter = 0;
    GameScreen currentScreen = LOGO;
    Scenes scenes;

    Button playButton = Button({ 350, 694, 200, 50 }, GREEN, BLACK, "Play");
    Button restartButton = Button({ 350, 500, 200, 50 }, RED, BLACK, "Restart");

    while (!WindowShouldClose()) {
        switch (currentScreen) {
        case LOGO:
            scenes.updateLogoScreen(framesCounter, &currentScreen);
            break;
        case TITLE:
            scenes.updateTitleScreen(&currentScreen, playButton);
            break;
        case GAMEPLAY:
            scenes.updateGameplayScreen(&currentScreen, restartButton);
            break;
        case ENDING:
            scenes.updateEndingScreen(&currentScreen, restartButton);
            break;
        default: 
            break;
        }

        framesCounter++;

        BeginDrawing();
        ClearBackground(RAYWHITE); 

        scenes.drawCurrentScreen(currentScreen);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
