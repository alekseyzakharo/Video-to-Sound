#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <list>
#include <SDL.h>
#include <SDL_thread.h>
#include "SDL_mixer.h"

using namespace std;

class AudioManager {
private:
	list<pair<Mix_Chunk*, int>> chunk_list_;
public:
	void open();
	void close();
	void play(float * signal, int length, int frequence);
	void wait();
};



#endif