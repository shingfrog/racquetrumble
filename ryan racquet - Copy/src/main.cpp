#include <raylib.h>
#include "scenes.hpp"
#include "button.hpp"

int main() {
    InitWindow(900, 900, "Ryan VS The Forces of Evil");
    SetTargetFPS(60); 
    InitAudioDevice();

    int framesCounter = 0;
    GameScreen currentScreen = LOGO;
    Scenes scenes;

    Button playButton = Button({ 350, 694, 200, 50 }, GREEN, BLACK, "Play");
    Button restartButton = Button({ 350, 500, 200, 50 }, RED, BLACK, "Restart");

    Music bgm = LoadMusicStream("sound/title or instruction screen.mp3");
    Music gameplayMusic = LoadMusicStream("sound/I've Got Your Back! (Main Loop).ogg");

    PlayMusicStream(bgm);
    PlayMusicStream(gameplayMusic);
    SetMusicVolume(gameplayMusic, 0.0f);

    while (!WindowShouldClose()) {
        switch (currentScreen) {
        case LOGO:
            UpdateMusicStream(bgm);
            scenes.updateLogoScreen(framesCounter, &currentScreen);
            break;
        case TITLE:
            UpdateMusicStream(bgm);
            scenes.updateTitleScreen(&currentScreen, playButton);
            break;
        case GAMEPLAY:
            UpdateMusicStream(gameplayMusic);
            UpdateMusicStream(bgm);
            SetMusicVolume(bgm, 0.0f);
            SetMusicVolume(gameplayMusic, 0.5f);
            if(scenes.Paused == true){
                SetMusicVolume(gameplayMusic, 0.0f);
            }
            if (!IsMusicStreamPlaying(gameplayMusic)){
                UpdateMusicStream(gameplayMusic);
            }
            scenes.updateGameplayScreen(&currentScreen, restartButton);
            break;
        case ENDING:
            UpdateMusicStream(gameplayMusic);
            UpdateMusicStream(bgm);
            SetMusicVolume(bgm, 1.0f);
            SetMusicVolume(gameplayMusic, 0.0f);
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

    UnloadMusicStream(bgm);
    UnloadMusicStream(gameplayMusic);

    CloseWindow();
    CloseAudioDevice();
    return 0;
}