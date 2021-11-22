// Onur YONTAR 2021

#include <Adafruit_NeoPixel.h> 
#include <SoftwareSerial.h>
#define PIN 9
#define LEDNUM 5
SoftwareSerial btKontrol(2,3);  

int brightness = 255;
char karakterVeri;
bool kalkis = false;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDNUM, PIN, NEO_BRG + NEO_KHZ800);
 
 
void setup() {
  btKontrol.begin(9600);
  strip.begin();
  strip.setBrightness(brightness);
  strip.show();
}
 
void loop() {
  verial();
  leddurum();

}

void verial()
{
  if(btKontrol.available()){
      karakterVeri=btKontrol.read();
      btKontrol.println(karakterVeri);
       
}
}
void leddurum()
{
   if ((karakterVeri)==('0')){
      strip.clear();
      strip.show();
    }

    else if((karakterVeri)==('1')){
        kalkis = true;
          while(kalkis == true){
          karakterVeri=btKontrol.read();
            if ((karakterVeri)==('0')){
                kalkis = false;
                }
            parlaklik();
              
            
        int r = 255, g = 60, b = 0;
      //int r = 158, g = 8, b = 148;
      //int r = 74, g = 150, b = 12;
 
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
      strip.clear();
      strip.show();
    }
}
void parlaklik()
{
   if((karakterVeri)==('2')){
    brightness = 50;
    strip.setBrightness(brightness);
   }
   else if((karakterVeri)==('3')){
    brightness = 100;
    strip.setBrightness(brightness);
   }
   else if((karakterVeri)==('4')){
    brightness = 150;
    strip.setBrightness(brightness);
   }
   else if((karakterVeri)==('5')){
    brightness = 200;
    strip.setBrightness(brightness);
   }
   else if((karakterVeri)==('6')){
    brightness = 255;
    strip.setBrightness(brightness);
   }
}
