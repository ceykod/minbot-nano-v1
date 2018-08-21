
void loop() {

  switch (mode) {
    case BEGIN:
      buttonStatus = digitalRead(BUTTON_1);

      if (buttonStatus == 0) {
        //mode = TEST; Serial.println(">> Mode : Test");
        mode = BLUETOOTH; Serial.println(">> Mode : Bluetooth Control");
        beep(2);


      } else {
        delay(100);
      }

      break;

    case TEST:
      motorWrite(150, 150);
      break;

    case BLUETOOTH:
      // Nothing to do here, see SerialEvent() in 'serial' tab
      break;

    default:
      delay(50);
      break;
  }
}
