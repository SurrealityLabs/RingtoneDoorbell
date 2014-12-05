#pragma once

#include "Arduino.h"

#include <avr/pgmspace.h>
#include "trinkettone.h"

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

#define isdigit(n) (n >= '0' && n <= '9')

inline char read_byte(const char *p, bool pgm)
{
	if (pgm)
		return pgm_read_byte(p);
	else
		return *p;
}

const prog_uint16_t notes[] PROGMEM =
{	0, //
	NOTE_C1, //
	NOTE_CS1, //
	NOTE_D1, //
	NOTE_DS1, //
	NOTE_E1, //
	NOTE_F1, //
	NOTE_FS1, //
	NOTE_G1, //
	NOTE_GS1, //
	NOTE_A1, //
	NOTE_AS1, //
	NOTE_B1, //

	NOTE_C2, //
	NOTE_CS2, //
	NOTE_D2, //
	NOTE_DS2, //
	NOTE_E2, //
	NOTE_F2, //
	NOTE_FS2, //
	NOTE_G2, //
	NOTE_GS2, //
	NOTE_A2, //
	NOTE_AS2, //
	NOTE_B2, //

	NOTE_C3, //
	NOTE_CS3, //
	NOTE_D3, //
	NOTE_DS3, //
	NOTE_E3, //
	NOTE_F3, //
	NOTE_FS3, //
	NOTE_G3, //
	NOTE_GS3, //
	NOTE_A3, //
	NOTE_AS3, //
	NOTE_B3, //

	NOTE_C4, //
	NOTE_CS4, //
	NOTE_D4, //
	NOTE_DS4, //
	NOTE_E4, //
	NOTE_F4, //
	NOTE_FS4, //
	NOTE_G4, //
	NOTE_GS4, //
	NOTE_A4, //
	NOTE_AS4, //
	NOTE_B4, //

	NOTE_C5, //
	NOTE_CS5, //
	NOTE_D5, //
	NOTE_DS5, //
	NOTE_E5, //
	NOTE_F5, //
	NOTE_FS5, //
	NOTE_G5, //
	NOTE_GS5, //
	NOTE_A5, //
	NOTE_AS5, //
	NOTE_B5, //

	NOTE_C6, //
	NOTE_CS6, //
	NOTE_D6, //
	NOTE_DS6, //
	NOTE_E6, //
	NOTE_F6, //
	NOTE_FS6, //
	NOTE_G6, //
	NOTE_GS6, //
	NOTE_A6, //
	NOTE_AS6, //
	NOTE_B6, //

	NOTE_C7, //
	NOTE_CS7, //
	NOTE_D7, //
	NOTE_DS7, //
	NOTE_E7, //
	NOTE_F7, //
	NOTE_FS7, //
	NOTE_G7, //
	NOTE_GS7, //
	NOTE_A7, //
	NOTE_AS7, //
	NOTE_B7, //

	2*NOTE_C7, //
	2*NOTE_CS7, //
	2*NOTE_D7, //
	2*NOTE_DS7, //
	2*NOTE_E7, //
	2*NOTE_F7, //
	2*NOTE_FS7, //
	2*NOTE_G7, //
	2*NOTE_GS7, //
	2*NOTE_A7, //
	2*NOTE_AS7, //
	2*NOTE_B7, //
	0
};

/*
 *
 * playing RTTTL music files in blocking mode
 * http://en.wikipedia.org/wiki/Ring_Tone_Transfer_Language
 *
 * based on Tone library demo
 *
 */
class TrinketRtttl
{
	uint8_t _pinSpk;
#ifdef _Tone_h
	Tone m_tone;
#endif

public:
	TrinketRtttl()
	{
		//		this->begin(tonePin);
	}

	void begin()
	{
		 pinMode(1, OUTPUT); // enable OUTPUT (PB1, #1)
	}

	void play_P(const prog_char *p, uint8_t octave_offset = 0)
	{
		_play(p, octave_offset, true);
	}
	void play(const char *p, uint8_t octave_offset = 0)
	{
		_play(p, octave_offset, false);
	}

	void _play(const prog_char *p, uint8_t octave_offset, bool pgm)
	{
		// Absolutely no error checking in here

		byte default_dur = 4;
		byte default_oct = 6;
		int bpm = 63;
		int num;
		long wholenote;
		long duration;
		byte note;
		byte scale;

		// format: d=N,o=N,b=NNN:
		// find the start (skip name, etc)

		while (read_byte(p, pgm) != ':')
			p++; // ignore name
		p++; // skip ':'

		// get default duration
		if (read_byte(p, pgm) == 'd')
		{
			p++;
			p++; // skip "d="
			num = 0;
			while (isdigit(read_byte(p, pgm)))
			{
				num = (num * 10) + (read_byte(p, pgm) - '0');
				p++;
			}
			if (num > 0)
				default_dur = num;
			p++; // skip comma
		}

		// get default octave
		if (read_byte(p, pgm) == 'o')
		{
			p++;
			p++; // skip "o="
			num = read_byte(p, pgm) - '0';
			p++;
			if (num >= 3 && num <= 7)
				default_oct = num;
			p++; // skip comma
		}

		// get BPM
		if (read_byte(p, pgm) == 'b')
		{
			p++;
			p++; // skip "b="
			num = 0;
			while (isdigit(read_byte(p, pgm)))
			{
				num = (num * 10) + (read_byte(p, pgm) - '0');
				p++;
			}
			bpm = num;
			p++; // skip colon
		}

		// BPM usually expresses the number of quarter notes per minute
		wholenote = (60 * 1000L / bpm) * 4; // this is the time for whole note (in milliseconds)

		// now begin note loop
		while (read_byte(p, pgm))
		{
			// first, get note duration, if available
			num = 0;
			while (isdigit(read_byte(p, pgm)))
			{
				num = (num * 10) + (read_byte(p, pgm) - '0');
				p++;
			}

			if (num)
				duration = wholenote / num;
			else
				duration = wholenote / default_dur; // we will need to check if we are a dotted note after

			// now get the note
			note = 0;

			switch (read_byte(p, pgm))
			{
			case 'c':
				note = 1;
				break;
			case 'd':
				note = 3;
				break;
			case 'e':
				note = 5;
				break;
			case 'f':
				note = 6;
				break;
			case 'g':
				note = 8;
				break;
			case 'a':
				note = 10;
				break;
			case 'b':
				note = 12;
				break;
			case 'p':
			default:
				note = 0;
			}
			p++;

			// now, get optional '#' sharp
			if (read_byte(p, pgm) == '#')
			{
				note++;
				p++;
			}

			// now, get optional '.' dotted note
			if (read_byte(p, pgm) == '.')
			{
				duration += duration / 2;
				p++;
			}

			// now, get scale
			if (isdigit(read_byte(p, pgm)))
			{
				scale = read_byte(p, pgm) - '0';
				p++;
			}
			else
			{
				scale = default_oct;
			}

			scale += octave_offset;

			if (read_byte(p, pgm) == ',')
				p++; // skip comma for next note (or we may be at the end)

			// now play the note

			if (note)
			{
				TrinketTone((uint16_t)(pgm_read_word(&notes[(scale - 1) * 12 + note])), duration);
			}
			else
			{
				delay(duration);
			}
		}
	}
};

