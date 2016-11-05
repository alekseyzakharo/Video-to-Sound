#include "AudioManager.h"

void AudioManager::open()
{
	Mix_Init(0);

	int rc = Mix_OpenAudio(
		8000, // Frequency
		AUDIO_F32,      // Format. Note: several formats are not portable.
		1,              // Channels
		1024);          // Chunk size. Should not be too small.
	if (rc == -1) perror("Could not open audio.");

	int frequency;
	Uint16 format;
	int channels;
	Mix_QuerySpec(&frequency, &format, &channels);
	if (format != AUDIO_F32) perror("Audio format is not correct.");
}

void AudioManager::close()
{
	Mix_CloseAudio();
	for (auto iter = chunk_list_.begin(); iter != chunk_list_.end(); iter++)
		Mix_FreeChunk((*iter).first);
	Mix_Quit();
}

void AudioManager::play(float * signal, int length, int frequence)
{
	for (auto iter = chunk_list_.begin(); iter != chunk_list_.end();)
	{
		if (Mix_GetChunk((*iter).second) != (*iter).first)
		{
			Mix_FreeChunk((*iter).first);
			iter = chunk_list_.erase(iter);
		}
		else
			iter++;
	}

	//make copy of signal data
	float *signal_copy = (float*)SDL_malloc(sizeof(float) * length);
	memcpy(signal_copy, signal, length * sizeof(float));

	//create chunk from signal
	Mix_Chunk* chunk = Mix_QuickLoad_RAW((Uint8*)signal_copy, length * sizeof(float));
	chunk->allocated = true;
	
	//play the chunk
	int channel = Mix_PlayChannel(-1, chunk, 0);
	if (channel == -1)
		perror("could not play the chunk");
	else
		chunk_list_.push_back(pair<Mix_Chunk*, int>(chunk, channel));

}

void AudioManager::wait()
{
	while (Mix_Playing(-1))
		SDL_Delay(1);
}
