#define motorPinA 8
#define motorPinB 9
#define motorPWMpin 10

const int analogPin = 0; // ポテンショメータのワイプ(中央の端子)を接続する
                       // 両端はグランドと+5Vに接続
int val = 0;           // 読み取った値を格納する変数

void setup() {
  pinMode(motorPinA, OUTPUT);
  pinMode(motorPinB, OUTPUT);
  Serial.begin(115200);        // シリアル通信の初期化
}

void loop() {
  val = analogRead(analogPin);    // アナログピンを読み取る
  if(val > 800) val = 800;
  val = map(val,0,800,0,255);
  Serial.println(val);
  // delay(200);
  digitalWrite( motorPinA, HIGH );
  digitalWrite( motorPinB, LOW  );
  analogWrite( motorPWMpin, val );
}

// #define motorPinA 7
// #define motorPinB 8
// #define motorPWMpin  9



// void setup() {
//   // put your setup code here, to run once:
//   pinMode(motorPinA, OUTPUT);
//   pinMode(motorPinB, OUTPUT);
  

// }

// void loop() {
//   int pwm_val = analogRead()
//   digitalWrite( motorPinA, HIGH );
//   digitalWrite( motorPinB, LOW  );
//   analogWrite( motorPWMpin, 100 );
//   delay( 3000 );
//   analogWrite( motorPWMpin, 0 );
//   delay( 1000 );

//   digitalWrite( motorPinA, LOW );
//   digitalWrite( motorPinB, HIGH  );
//   analogWrite( motorPWMpin, 100 );
//   delay( 1000 );
//   analogWrite( motorPWMpin, 0 );
//   delay( 3000 );
// }
