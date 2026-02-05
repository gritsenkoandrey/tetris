#include "audio.h"

Audio::Audio() {
    InitAudioDevice();
    music = LoadMusicStream("Sounds/music.mp3");
    rotate = LoadSound("Sounds/rotate.mp3");
    clear = LoadSound("Sounds/clear.mp3");
    PlayMusicStream(music);
}

Audio::~Audio() {
    UnloadMusicStream(music);
    UnloadSound(rotate);
    UnloadSound(clear);
    CloseAudioDevice();
}

Music Audio::GetMusic() const {
    return music;
}

Sound Audio::GetRotate() const {
    return rotate;
}

Sound Audio::GetClear() const {
    return clear;
}