#include "TrinketRtttl.h"
#include <Bounce.h>

#define BUTTON 0
#define SPEAKER 1

const int octave = 0;

// this solution is recommended:
// the song is stored in program memory only
const char song_P[] PROGMEM =
"RockyThe:d=4,o=5,b=112:16e,8g,16p,2a,8p,16a,8b,16p,2e,16p,32p,16e,8g,16p,2a,16p,32p,16a,8b,16p,1e,8p,16p,16d6,16c6,8d6,16p,16c6,16d6,4e6,4p,16c6,16c6,8b,16b,8a,16a,4g,8f6,1e6";
TrinketRtttl player;

Bounce bouncer = Bounce( BUTTON, 5 ); 

void setup(void)
{
  pinMode(BUTTON, INPUT);
  pinMode(SPEAKER, INPUT);
}

void loop(void)
{
  if (bouncer.update()) { // is true when the state changes
    if (bouncer.read() == false) { // button is active low
      pinMode(SPEAKER, OUTPUT); // set up the output
      player.begin(); // play the ringtone
      player.play_P(song_P, octave);
      pinMode(SPEAKER, INPUT); // disable and set a delay
      delay(2000);
    }
  }
}


