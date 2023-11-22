#include <Servo.h>
Servo servo4; //hipr;
Servo servo1; //hipl;

Servo servo5; //kneer;
Servo servo2; //kneel;

Servo servo6; //footr;
Servo servo3; //footl;

int neutralAngles[] = {90, 90, 90, 90, 90, 90};

void setup() {

  servo4.attach(11); 
  servo1.attach(6);
  
  servo5.attach(10);
  servo2.attach(5);
  
  servo6.attach(9);
  servo3.attach(3);

// variable to store the servo position
  
  Serial.begin(9600);

    for (int i = 0; i < 6; i++) {
    setServoAngle(i, neutralAngles[i]);
    delay(500); // Delay to allow servos to reach the neutral position
  }
  setServoAngle(4,70);
  setServoAngle(1,120);
}

void loop() {
  moveForward();
//  attention();
}

void setServoAngle(int servoIndex, int angle) {
  if (angle >= 0 && angle <= 180) {
    switch (servoIndex) {
      case 0: servo1.write(angle); break;//hipl
      case 1: servo2.write(angle); break;//kneel
      case 2: servo3.write(angle); break;//footl
      case 3: servo4.write(angle); break;//hipr
      case 4: servo5.write(angle); break;//kneer
      case 5: servo6.write(angle); break;//footr
    }
    delay(200);
  }
}


void moveForward() {
      setServoAngle(3,110);
      setServoAngle(0,110);
      delay(200);
      setServoAngle(3,70);
      setServoAngle(0,70);
      
//    delay(500);

//  
//  delay(500); // Delay to complete the step
//
//  // Reset right leg to neutral position
//  setServoAngle(3, 90);  // Right hip
//  setServoAngle(1, 90);  // Right knee
//  setServoAngle(5, 90);  // Right foot
//  
//  delay(500); // Delay to reset the leg
//
//  // Left leg forward
//  setServoAngle(0, 120); // Left hip
//  setServoAngle(2, 60);  // Left knee
//  setServoAngle(4, 90);  // Left foot
//  
//  delay(500); // Delay to complete the step
//
//  // Reset left leg to neutral position
//  setServoAngle(0, 90);  // Left hip
//  setServoAngle(2, 90);  // Left knee
//  setServoAngle(4, 90);  // Left foot
//  
//  delay(500);  
}
