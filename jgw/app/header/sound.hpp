// script of sound.hpp
#ifndef _SOUND_H
#define _SOUND_H
	class sound {
	private:
		// make variable for Hz_S
		double Hz_S; // variable for frequency (Hz)
		int duration_S; // variable for duration (cs)
	public:
		// function constructor
		void tone(double Hz_Ss, int duration_Ss);
	};
#endif // end of _SOUND_H