#include "MusicPlayer.h"


MusicPlayer::MusicPlayer(std::string appName) : mainWindow(screenWidth, screenHeight, appName), changeSongButton("Change song"), playButton("Data/play_icon2.png"), pauseButton("Data/pause_icon2.png"), songProgressBar(progressBarX, progressBarY, progressBarWidth, progressBarHeight) {
	
    changeSongButton.setPosition(
        progressBarX + progressBarWidth / 2 - buttonWidth / 2,
        progressBarY + 130
    );

    playButton.setPosition(
        progressBarX + progressBarWidth / 2 - buttonRadius / 2,         // x = progress bar center - icon radius
        progressBarY + 50
    );

    pauseButton.setPosition(
        progressBarX + progressBarWidth / 2 - buttonRadius / 2,
        progressBarY + 50
    );
}

void MusicPlayer::run() {
    SetTargetFPS(30);               // Set our app to run at 30 frame per second
    //--------------------------------------------------------------------------------------

    // Main loop
    while (!WindowShouldClose()) {  // Detect window close button or ESC key

        // Update
        //----------------------------------------------------------------------------------
        updateStates();

        // Events
        //----------------------------------------------------------------------------------
        eventHandling();

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(appBackground);

        drawing();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
}

void MusicPlayer::updateStates() {
    musicTrack.updateStream();
    songProgressBar.setProgress(musicTrack);

    songName = musicTrack.getSongName();

    elapsedTime = static_cast<int>(musicTrack.getElapsedTime());
    songLength = static_cast<int>(musicTrack.getTotalLength());
    progressInNumbers = std::to_string(elapsedTime / 60) + ":" + std::to_string(elapsedTime % 60)
                        + "/"
                        + std::to_string(songLength / 60) + ":" + std::to_string(songLength % 60);
}

void MusicPlayer::eventHandling() {
    // Play/Pause the music
    if (playButton.isPressed() || pauseButton.isPressed() || IsKeyPressed(KEY_SPACE)) {

        if (musicTrack.isPaused()) {
            musicTrack.play();
        }
        else {
            musicTrack.pause();
        }

    }

    if (changeSongButton.isPressed()) {

        if (!musicTrack.loadFromFile()) {
            std::cerr << "Failed to load the song!\n";
        }

    }
}

void MusicPlayer::drawing() {
    changeSongButton.draw(buttonBackground, WHITE);
    songProgressBar.draw(ProgressBarBackground, progressBackground);

    DrawText(progressInNumbers.c_str(),
        progressBarX + progressBarWidth + 10,
        progressBarY, 20,
        ProgressBarBackground
    );

    DrawText(songName.c_str(),
        screenWidth / 2 - MeasureText(songName.c_str(), fontSize) / 2,
        progressBarY - fontSize - 20,
        fontSize,
        ProgressBarBackground
    );

    if (musicTrack.isPaused()) {
        playButton.draw();
    }
    else {
        pauseButton.draw();
    }
}