#include "IconButton.h"
#include "ProgressBar.h"
#include "raylib.h"
#include "Rectangle.h"
#include "Song.h"
#include "TextButton.h"
#include <iostream>

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Music Player");

    stu::Song song;
    stu::ProgressBar bar(220, 300, 350, 20);
    stu::TextButton button("Change song");

    Color textColor = { 228, 24, 78, 255 };

    stu::IconButton play_button("Data/play_icon.png");
    play_button.setPosition(220 + 350 / 2 - 50 / 2, 350);          // x = progress bar center - icon radius

    stu::IconButton pause_button("Data/pause_icon.png");
    pause_button.setPosition(220 + 350 / 2 - 50 / 2, 350);

    SetTargetFPS(30);               // Set our game to run at 30 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        
        song.updateStream();
        bar.setProgress(
            song.getProgress()
        );

        // Play/Pause the music
        if (play_button.isPressed() || pause_button.isPressed()) {

            if (song.isPaused()) {
                song.play();
            }
            else {
                song.pause();
            }

        }

        if (button.isPressed()) {

            if (!song.loadFromFile()) {
                std::cerr << "Failed to load the song!\n";
            }

        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        bar.draw();
        button.draw(GRAY, textColor);

        if (song.isPaused()) {
            play_button.draw();
        }
        else {
            pause_button.draw();
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }


    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();               // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}