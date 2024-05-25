#include <raylib.h>
#include "scene.hpp"

int main() {
    InitWindow(900, 900, "Racquet Rumble");
    SetTargetFPS(60); 

    int framesCounter = 0;
    GameScreen currentScreen = LOGO;
    Scenes scenes; 

    while (!WindowShouldClose()) {
        switch (currentScreen) {
        case LOGO:
            scenes.updateLogoScreen(framesCounter, &currentScreen);
            break;
        case TITLE:
            scenes.updateTitleScreen(&currentScreen);
            break;
        case GAMEPLAY:
            scenes.updateGameplayScreen(&currentScreen);
            break;
        case ENDING:
            scenes.updateEndingScreen(&currentScreen);
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
