#include <Gamer.h>

Gamer gamer;

byte bounce1[] = {
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

byte bounce2[] = {
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

byte bounce3[] = {
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000
};

byte bounce4[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000
};

byte bounce5[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000
};

byte bounce6[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000
};

byte* frames[6] = {bounce1,bounce2,bounce3,bounce4,bounce5,bounce6};
int initial_volume = 5;
int initial_speed = 300;

void setup() {
  gamer.begin();
}

void loop() {
  int min_frame = 0;
  int volume = initial_volume;
  int speed = initial_speed;
  for(int max_frame=0; max_frame<6; max_frame++) {
    for(int x=max_frame; x<6; x++) {
      gamer.printImage(frames[x]);
      if(x!=5) {
        delay(speed);
      }
    }
    
    beep(volume--);
    delay(speed);
  
    for(int x=4; x>min_frame; x--) {
      gamer.printImage(frames[x]);
      delay(speed);
    }
    
    min_frame++;
    speed=speed-(min_frame*20);
  }
  delay(1000);
}

void beep(int duration) {
  digitalWrite(BUZZER, true);
  delay(duration);
  digitalWrite(BUZZER, false);
}
