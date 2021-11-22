#include <Adafruit_NeoPixel.h>

#define PIN 9
#define LEDNUM 5


int brightness = 255;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDNUM, PIN, NEO_BRG + NEO_KHZ800); //NEO_BRG - NEO_RGB - NEO_GRB
 
 
void setup() {
  strip.begin();
  strip.setBrightness(brightness);
  strip.show();
}
 
void loop() {


      int r = 255, g = 60, b = 0; // color 1
    //int r = 158, g = 8, b = 148; // color 2
    //int r = 74, g = 150, b = 12; // color 3
 
  for(int i=0; i<strip.numPixels(); i++) {
    int flicker = random(0,55);
    int r1 = r-flicker;
    int g1 = g-flicker;
    int b1 = b-flicker;
    if(g1<0) g1=0;
    if(r1<0) r1=0;
    if(b1<0) b1=0;
    strip.setPixelColor(i,r1,g1, b1);
  }
  strip.show();
 
  delay(random(25,1 ));
      
}
