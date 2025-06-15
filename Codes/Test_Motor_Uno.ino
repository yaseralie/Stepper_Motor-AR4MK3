/* Stepper DM320T, Arduino Uno
 * For Motor stepper 24v test AR4 MK3 Robot
 * Wiring arduino:
 *  Pin 2 and Pin 3 with ground as common
 *  Pin 9 to Pull driver
 *  Pin 8 to Dir driver
 * Stepper Driver:
 *  Pull  : Pin 9
 *  Dir   : Pin 8
 *  Opto  : 3.3v
 *  
 *  A+    : Black
 *  A-    : Green 
 *  B+    : Red
 *  B-    : Blue
 */

#define PUL_PIN 9      // Pulsa ke driver
#define DIR_PIN 8      // Direction
#define BTN_CW 2       // Clockwise
#define BTN_CCW 3      // Counter-Clockwise

void setup() {
  Serial.begin(115200);
  pinMode(PUL_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(BTN_CW, INPUT_PULLUP);
  pinMode(BTN_CCW, INPUT_PULLUP);
}

void loop() {
  // Cek tombol CW
  if (digitalRead(BTN_CW) == LOW) {
    digitalWrite(DIR_PIN, HIGH); // CW Direction
    //Serial.println("Clock Wise");
    stepMotor();
  }

  // Cek tombol CCW
  if (digitalRead(BTN_CCW) == LOW) {
    digitalWrite(DIR_PIN, LOW); // CCW Direction
    //Serial.println("Counter Clock Wise");
    stepMotor();
  }
}

void stepMotor() {
  digitalWrite(PUL_PIN, HIGH);
  delayMicroseconds(500); // speed
  digitalWrite(PUL_PIN, LOW);
  delayMicroseconds(500);
}
