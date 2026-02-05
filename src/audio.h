#pragma once
#include <raylib.h>

class Audio {
public:
    Audio();
    ~Audio();
    [[nodiscard]] Music GetMusic() const;
    [[nodiscard]] Sound GetRotate() const;
    [[nodiscard]] Sound GetClear() const;

private:
    Music music {};
    Sound rotate {};
    Sound clear {};
};