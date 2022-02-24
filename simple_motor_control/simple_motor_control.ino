#define motorPWMpinA1 5
#define motorPWMpinA2 6
#define motorPWMpinB1 7
#define motorPWMpinB2 8

const int analogPinA = 0; 
const int analogPinB = 1; 
int analogValA = 0;          
int analogValB = 0;          

const int vol_lim = 800;
const int vol_mid = vol_lim/2;
const int dead_range_half = 20;

void setup() {
  Serial.begin(115200);  
}

void loop() {
  // モーターA
  // アナログの入力1024（900くらいまでしか上がらない）を255に
  analogValA = analogRead(analogPinA);
  if(analogValA > vol_lim) analogValA = vol_lim;
  int pwmValA = map(analogValA,0,vol_lim,0,255);

  if( analogValA>(vol_mid+dead_range_half) ){
    analogWrite( motorPWMpinA1, pwmValA*2-255 );
    analogWrite( motorPWMpinA2, 0 );
  }
  else if( analogValA<(vol_mid-dead_range_half) ){
    analogWrite( motorPWMpinA1, 0 );
    analogWrite( motorPWMpinA2, 255-pwmValA*2 );
  }
  else{
    analogWrite( motorPWMpinA1, 0 );
    analogWrite( motorPWMpinA2, 0 );
  }

  // モーターB
  analogValB = analogRead(analogPinB);
  if(analogValB > vol_lim) analogValB = vol_lim;
  int pwmValB = map(analogValB,0,vol_lim,0,255);

  if( analogValB>(vol_mid+dead_range_half) ){
    analogWrite( motorPWMpinB1, pwmValB*2-255 );
    analogWrite( motorPWMpinB2, 0 );
  }
  else if( analogValB<(vol_mid-dead_range_half) ){
    analogWrite( motorPWMpinB1, 0 );
    analogWrite( motorPWMpinB2, 255-pwmValB*2 );
  }
  else{
    analogWrite( motorPWMpinB1, 0 );
    analogWrite( motorPWMpinB2, 0 );
  }

  // デバッグ用
  Serial.print(analogValA);
  Serial.print("\t");
  Serial.print(analogValB);
  Serial.print("\t");
  Serial.print(pwmValA);
  Serial.print("\t");
  Serial.print(pwmValB);
  Serial.print("\n");
}

