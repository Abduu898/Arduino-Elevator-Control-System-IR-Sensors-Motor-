// ----------- 7 SEGMENT PINS -----------
int pin_A = 9;
int pin_b = 1;
int pin_c = 2;
int pin_d = 3;
int pin_e = 4;
int pin_f = 5;
int pin_g = 6;

// ----------- MOTOR PINS -----------
int OUT_Motor_1 = 7; // DOWN
int OUT_Motor_2 = 8; // UP

// ----------- BUTTONS -----------
int floor_0 = A0;
int floor_1 = A1;
int floor_2 = A2;

// ----------- SENSORS -----------
int sensor_0 = A3;
int sensor_1 = A4;
int sensor_2 = A5;

int speed_ = 150;

void setup() {

  // Sensors & Buttons
  pinMode(sensor_0, INPUT_PULLUP);
  pinMode(sensor_1, INPUT_PULLUP);
  pinMode(sensor_2, INPUT_PULLUP);

  pinMode(floor_0, INPUT_PULLUP);
  pinMode(floor_1, INPUT_PULLUP);
  pinMode(floor_2, INPUT_PULLUP);

  // Motors
  pinMode(OUT_Motor_1, OUTPUT);
  pinMode(OUT_Motor_2, OUTPUT);

  // 7-seg
  pinMode(pin_A, OUTPUT);
  pinMode(pin_b, OUTPUT);
  pinMode(pin_c, OUTPUT);
  pinMode(pin_d, OUTPUT);
  pinMode(pin_e, OUTPUT);
  pinMode(pin_f, OUTPUT);
  pinMode(pin_g, OUTPUT);

  // Initial move (as in original)
  analogWrite(OUT_Motor_2, HIGH);
  delay(500);
}

// ----------- DISPLAY FUNCTIONS -----------

void display0() {
  digitalWrite(pin_A, 1);
  digitalWrite(pin_b, 1);
  digitalWrite(pin_c, 1);
  digitalWrite(pin_d, 1);
  digitalWrite(pin_e, 1);
  digitalWrite(pin_f, 1);
  digitalWrite(pin_g, 0);
}

void display1() {
  digitalWrite(pin_A, 0);
  digitalWrite(pin_b, 1);
  digitalWrite(pin_c, 1);
  digitalWrite(pin_d, 0);
  digitalWrite(pin_e, 0);
  digitalWrite(pin_f, 0);
  digitalWrite(pin_g, 0);
}

void display2() {
  digitalWrite(pin_A, 1);
  digitalWrite(pin_b, 1);
  digitalWrite(pin_c, 0);
  digitalWrite(pin_d, 1);
  digitalWrite(pin_e, 1);
  digitalWrite(pin_f, 0);
  digitalWrite(pin_g, 1);
}

// ----------- MAIN LOOP -----------

void loop() {

  // ---- GO TO FLOOR 0 ----
  if (digitalRead(floor_0) == 0) {
    if (digitalRead(sensor_0) == 1) {
      analogWrite(OUT_Motor_1, speed_);
      while (digitalRead(sensor_0)) {}
      digitalWrite(OUT_Motor_1, 0);
    }
  }

  // ---- GO TO FLOOR 2 ----
  if (digitalRead(floor_2) == 0) {
    if (digitalRead(sensor_2) == 1) {
      analogWrite(OUT_Motor_2, speed_);
      while (digitalRead(sensor_2)) {}
      delay(400);
      digitalWrite(OUT_Motor_2, 0);
    }
  }

  // ---- GO TO FLOOR 1 ----
  if (digitalRead(floor_1) == 0) {
    if (digitalRead(sensor_1) == 1) {

      if (digitalRead(sensor_2) == 0) {
        analogWrite(OUT_Motor_1, speed_);
        while (digitalRead(sensor_1)) {}
        digitalWrite(OUT_Motor_1, 0);
      }

      else if (digitalRead(sensor_0) == 0) {
        analogWrite(OUT_Motor_2, speed_);
        while (digitalRead(sensor_1)) {}
        delay(400);
        digitalWrite(OUT_Motor_2, 0);
      }
    }
  }

  // ---- DISPLAY CURRENT FLOOR ----
  if (digitalRead(sensor_0) == 0) {
    display0();
  }
  else if (digitalRead(sensor_1) == 0) {
    display1();
  }
  else if (digitalRead(sensor_2) == 0) {
    display2();
  }
}
