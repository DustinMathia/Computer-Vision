class Motor {

  public:

  int DIR, STP, MS1, MS2, MS3, ENABLE;
  
    void InitDriverPins() {
  pinMode(STP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(MS3, OUTPUT);
  pinMode(ENABLE, OUTPUT);
  
  // Step and direction
  digitalWrite(STP, LOW);
  digitalWrite(DIR, LOW);
  
  // Setup microstepping: full step (LOW,LOW,LOW),..., Sixteenth step (HIGH,HIGH,HIGH)
  digitalWrite(MS1, HIGH); delay(1);
  digitalWrite(MS2, HIGH); delay(1);
  digitalWrite(MS3, HIGH); delay(1);

  // Initial state after startup: motor drive disabled
  digitalWrite(ENABLE, LOW);   // bit = HIGH: motor drive is disabled
  delay(1);
  }

  void Move(float deg){
  int steps = deg / 0.1125;
  digitalWrite(DIR, HIGH);   // ecmdDirectionure tracmdDirectionition from HIGH to LOW: start with HIGH
  digitalWrite(DIR, LOW);    // tracmdDirectionition to LOW
  for (int x = 1; x < steps; x++)   // Loop through the specified number of steps
  {
    // Move one step; the DIR bit specifies the direction 
    digitalWrite(STP, HIGH);      // set step bit: LOW->HIGH, start step
    delayMicroseconds(500);
    digitalWrite(STP, LOW);       // reset step bit: HIGH->LOW, stop step
    delayMicroseconds(500);
  } // end for 
}
};

float xAngle (float A, float b, float c) {
  float x = c * sin(A);
  float y = c * cos(A);
  float b1 = asin(y/c);
  float b2 = asin(b-y/x);
  float B = b1 + b2;
  return B;
}

float yAngle (float c, float b) {
  float C = asin(c/b);
  return C;
  
}


void setup() {
  // put your setup code here, to run once:
Motor MotorX;
Motor MotorY;

MotorX.DIR = 8;
MotorX.STP = 9;
MotorX.MS1 = 12;
MotorX.MS2 = 11;
MotorX.MS3 = 10;
MotorX.ENABLE = 13;

MotorX.DIR = 14;
MotorX.STP = 15;
MotorX.MS1 = 18;
MotorX.MS2 = 17;
MotorX.MS3 = 16;
MotorX.ENABLE = 13;

MotorX.InitDriverPins();
MotorY.InitDriverPins();
}

void loop() {
  // put your main code here, to run repeatedly:

}
