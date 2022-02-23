#define motorPinA 7
#define motorPinB 8
#define motorPWM  9

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPinA, OUTPUT);
  pinMode(motorPinB, OUTPUT);
  

}

void loop() {
  digitalWrite( motorPinA, HIGH );
  digitalWrite( motorPinB, LOW  );
  analogWrite( motorPWM, 100 );
  delay( 3000 );
  analogWrite( motorPWM, 0 );
  delay( 1000 );

  digitalWrite( motorPinA, LOW );
  digitalWrite( motorPinB, HIGH  );
  analogWrite( motorPWM, 100 );
  delay( 1000 );
  analogWrite( motorPWM, 0 );
  delay( 3000 );
}
