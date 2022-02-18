#include <Adafruit_CircuitPlayground.h>

float X, Y, Z;


float getacc(float X,float Y,float Z){
  return  pow(pow(X,2)+pow(Y,2)+pow(Z,2),0.5);
  }

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void lightNPixels(int n){
   for(int i=0; i<10; i++){
    CircuitPlayground.setPixelColor(i, 0,0,0);
    }

  for(int i=0; i<4 && i<n; i++){
    CircuitPlayground.setPixelColor(i, 255,255,0);
    }

  for(int i=4; i<7 && i<n; i++){
    CircuitPlayground.setPixelColor(i, 0,255,0);
    }

   for(int i=7; i<10 && i<n; i++){
    CircuitPlayground.setPixelColor(i, 255,0,0);
    }
  
  }

void loop() {
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();

  
  Serial.println((int)(map(getacc(X,Y,Z),5,30,0,10)));
  lightNPixels((int)(map(getacc(X,Y,Z),5,30,0,10)));
  delay(50);
}
