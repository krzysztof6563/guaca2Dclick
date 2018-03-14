#include "sound.h"

void SDLSound::playMusic(){
    if (!gGl.muted){
        std::string s = __FILE__;
        s += " :SDL_Mixer Error:";
        if (gGl.newMusic != ""){    //spr czy potrzebna jest muzyka
            if (gGl.newMusic != gGl.currentMusic){      //spr czy nowa muzyka != obecna muzyka
                Mix_FadeOutChannel(1, 500);         //jeśli tak to wyciszenie
                if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096))      //inicjalizacja audio
                {
                    s += Mix_GetError();
                    MainWindow::showMsgBox(QString::fromStdString(s), "Błąd krytyczny", 30);
                } else {
                    const char* c = gGl.newMusic.c_str();
                    Mix_Chunk* bgmusic = Mix_LoadWAV(c);        //załadowanie pliku
                    if (!bgmusic)
                    {
                        s += Mix_GetError();
                        MainWindow::showMsgBox(QString::fromStdString(s), "Błąd krytyczny", 30);
                    } else {
                        if (gGl.loopMusic != "false"){
                            if (Mix_FadeInChannel(1, bgmusic, -1, 500) < 0)     //jeśli muzyka ma się powtarzać
                            {
                                s += Mix_GetError();
                                MainWindow::showMsgBox(QString::fromStdString(s), "Błąd krytyczny", 30);
                            }
                        } else {
                            if (Mix_FadeInChannel(1, bgmusic, 0, 500) < 0)      //jeśli ma być odegrana jeden raz
                            {
                                s += Mix_GetError();
                                MainWindow::showMsgBox(QString::fromStdString(s), "Błąd krytyczny", 30);
                            }
                        }
                        gGl.currentMusic = gGl.newMusic;
                    }
                }
            }
        } else {    //zatrzymanie knału, jeśli nie ma być muzyki i zmianna currentMusic na null, aby można było ponownie załadować ten sam utwór
            Mix_HaltChannel(1);
            gGl.currentMusic = "null";
        }
    } else {
        Mix_HaltChannel(1);
        gGl.currentMusic = "null";
    }
}


void SDLSound::_playSFX(){
    std::string s = __FILE__;
    s += " :SDL_Mixer Error:";
    if (!gGl.muted){
        if (gGl.SFX != ""){
            if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096))
            {
                s += Mix_GetError();
                MainWindow::showMsgBox(QString::fromStdString(s), "Błąd krytyczny", 30);
            }
            const char* c = gGl.SFX.c_str();
            Mix_Chunk* sfx = Mix_LoadWAV(c);
            if (!sfx)
            {
                s += Mix_GetError();
                MainWindow::showMsgBox(QString::fromStdString(s), "Błąd krytyczny", 30);
            }
            if (Mix_PlayChannel(2, sfx, 0) < 0)
            {
                s += Mix_GetError();
                MainWindow::showMsgBox(QString::fromStdString(s), "Błąd krytyczny", 30);
            }
        }
    }
}
