/*
 * 
 * motorBegin()
 * motorWrite(leftSpeed, rightSpeed)
 * motorStop()
 * wait()
 * wait(timeInMiliSeconds)
 * 
 */
void motorBegin() {

  Serial.println(">> MotorControl : Begin...");

  pinMode(leftMotorA, OUTPUT);
  pinMode(leftMotorB, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);

  pinMode(rightMotorA, OUTPUT);
  pinMode(rightMotorB, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);

  motorWrite(0, 0);

}

void motorWrite(int leftSpeed, int rightSpeed) {

  // map  the speed with correct & acceptable range
  leftSpeed = constrain(leftSpeed, -1 * MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
  rightSpeed = constrain(rightSpeed , -1 * MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);

  // Adjust motor speeds for backward direction
  //leftSpeed = (leftSpeed < 0) ? leftSpeed * MOTOR_REVERSE_FACTOR : leftSpeed;
  //rightSpeed = (rightSpeed < 0) ? rightSpeed * MOTOR_REVERSE_FACTOR : rightSpeed;

  // check motor directions
  leftMotorDir = (leftSpeed != 0) ? leftSpeed / abs(leftSpeed) : 1;
  rightMotorDir = (rightSpeed != 0) ? rightSpeed / abs(rightSpeed) : 1;

  //---------------------------------------------------------------------------------------------
  if (leftMotorDir !=  leftMotorDirOld) {
    // Direction changed
    digitalWrite(leftMotorA, (leftSpeed >= 0) ? HIGH : LOW);
    digitalWrite(leftMotorB, (leftSpeed >= 0) ? LOW : HIGH);
    leftMotorDirOld = leftMotorDir;
  }

  //---------------------------------------------------------------------------------------------
  if (rightMotorDir !=  rightMotorDirOld) {
    // Direction changed
    digitalWrite(rightMotorA, (rightSpeed >= 0) ? HIGH : LOW);
    digitalWrite(rightMotorB, (rightSpeed >= 0) ? LOW : HIGH);
    rightMotorDirOld = rightMotorDir;
  }

  //---------------------------------------------------------------------------------------------

  // Write PWM Speeds
  analogWrite(leftMotorPWM, abs(leftSpeed));
  analogWrite(rightMotorPWM, abs(rightSpeed));

}


void motorStop() {
  motorWrite(0, 0);
}

void wait() {
  motorWrite(0, 0);
}

void wait(int t) {
  motorWrite(0, 0);
  delay(t);
}

