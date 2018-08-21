
// This function is a Serial Inteerru

void serialEvent() {

  while (Serial.available()) {

    digitalWrite(LED_1, HIGH);
    int r = Serial.read();
    char inChar = (char)r;

    if (inChar == 'b') {
      beep(1);

    } else if (mode == BLUETOOTH) {

      if (inChar == '5')motorStop();
      else if (inChar == '8')motorWrite(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
      else if (inChar == '2')motorWrite(-1 * MAX_MOTOR_SPEED, -1 * MAX_MOTOR_SPEED);
      else if (inChar == '6')motorWrite(MAX_MOTOR_SPEED / 2, -1 * MAX_MOTOR_SPEED / 2);
      else if (inChar == '4')motorWrite(-1 * MAX_MOTOR_SPEED / 2, MAX_MOTOR_SPEED / 2);
      else if (inChar == '9')motorWrite(MAX_MOTOR_SPEED / 2, 0);
      else if (inChar == '7')motorWrite(0, MAX_MOTOR_SPEED / 2);
      else if (inChar == '1')motorWrite(-1 * MAX_MOTOR_SPEED / 2, 0);
      else if (inChar == '3')motorWrite(0, -1 * MAX_MOTOR_SPEED / 2);
      delay(100);
      motorStop();
    }
    digitalWrite(LED_1, LOW);
  }
}



