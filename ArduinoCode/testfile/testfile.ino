// necessaries forthe NeoPixel
#include <Adafruit_NeoPixel.h>
#define pixelPin D5
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, pixelPin,NEO_GRB + NEO_KHZ800);

void setup(){
strip.begin();
strip.show();

Serial.begin(115200);

strip.setPixelColor(0, Wheel(255));
strip.show();

}

void loop(){
    for (int i = 0; 1< 255; i++){
        strip.setPixelColor(0, Wheel(i));
        strip.show();
        delay(50);
    }
}

uint32_t Wheel(byte WheelPos) {
    WheelPos = 255 - WheelPos;
    if(WheelPos < 85) {
     return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    } else if(WheelPos < 170) {
      WheelPos -= 85;
     return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    } else {
     WheelPos -= 170;
     return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    }
  }
  test