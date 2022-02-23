#include <ros.h>
// #include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

// #define motorPinA 7
// #define motorPinB 8
#define motorPWMpin  13
// #define motorPWMpin  9

const int pwm_range = 128;

ros::NodeHandle nh;

// void messageCb( const std_msgs::Empty& toggle_msg) {
void messageCb( const geometry_msgs::Twist& cmd_vel) {
  float PWM_val = pwm_range*cmd_vel.linear.x;
  analogWrite( motorPWMpin, PWM_val );
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", &messageCb );
// ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb );

void setup(){
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH); 
  nh.initNode();
  nh.subscribe(sub);
}

void loop(){
  nh.spinOnce();
  delay(1);
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
