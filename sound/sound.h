#ifndef SOUND_H
#define SOUND_H

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_audio.h>
    #include <queue>
    #include <cmath>

    struct BeepObject
    {
        double freq;
        int samplesLeft;
    };

    class Beeper {
    	private:
        	double v;
        	std::queue<BeepObject> beeps;
    	public:
        	Beeper();
        	~Beeper();
        	void beep(double freq, int duration);
        	void generateSamples(Sint16 *stream, int length);
        	void wait();
    };

    void audio_callback(void*, Uint8*, int);
#endif

void tone(double Hz_S, int duration_S);

#endif
