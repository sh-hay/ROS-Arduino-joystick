// #define motorPinA 8
// #define motorPinB 9
#define motorPWMpinA1 5
#define motorPWMpinA2 6
#define motorPWMpinB1 7
#define motorPWMpinB2 8

const int analogPin = 0; 
int val = 0;           
const int vol_lim = 800;
const int vol_mid = vol_lim/2;
const int dead_range_half = 20;

void setup() {
  Serial.begin(115200);  
}

void loop() {
  val = analogRead(analogPin);    // アナログピンを読み取る
  if(val > vol_lim) val = vol_lim;
  int pwm_val = map(val,0,vol_lim,0,255);

  if( val>(vol_mid+dead_range_half) ){
    analogWrite( motorPWMpinA1, pwm_val*2-255 );
    analogWrite( motorPWMpinA2, 0 );
  }
  else if( val<(vol_mid-dead_range_half) ){
    analogWrite( motorPWMpinA1, 0 );
    analogWrite( motorPWMpinA2, 255-pwm_val*2 );
  }
  else{
    analogWrite( motorPWMpinA1, 0 );
    analogWrite( motorPWMpinA2, 0 );
  }
  
  Serial.print(val);
  Serial.print("\t");
  Serial.print(pwm_val);
  Serial.print("\n");
}

