#ifndef SOUND_H
#define SOUND_H

#include <SDL2/SDL_mixer.h>
#include "mainwindow.h"

class SDLSound {

public:
    static void _playSFX();
    static void playMusic();
};



#endif // SOUND_H
