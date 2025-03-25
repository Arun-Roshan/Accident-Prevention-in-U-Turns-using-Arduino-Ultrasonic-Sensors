#define TRIG_LEFT 6   // Left ultrasonic sensor
#define ECHO_LEFT 8
#define TRIG_RIGHT 7  // Right ultrasonic sensor
#define ECHO_RIGHT 9

#define RED_LEFT 10
#define YELLOW_LEFT 11
#define GREEN_LEFT 12

#define RED_RIGHT 13
#define YELLOW_RIGHT A1
#define GREEN_RIGHT A2

#define BUZZER A3  // Buzzer for alerting

void setup() {
  pinMode(TRIG_LEFT, OUTPUT);
  pinMode(ECHO_LEFT, INPUT);
  pinMode(TRIG_RIGHT, OUTPUT);
  pinMode(ECHO_RIGHT, INPUT);
  
  pinMode(RED_LEFT, OUTPUT);
  pinMode(YELLOW_LEFT, OUTPUT);
  pinMode(GREEN_LEFT, OUTPUT);
  
  pinMode(RED_RIGHT, OUTPUT);
  pinMode(YELLOW_RIGHT, OUTPUT);
  pinMode(GREEN_RIGHT, OUTPUT);

  pinMode(BUZZER, OUTPUT);
  
  Serial.begin(9600);
}

long getDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  long duration = pulseIn(echo, HIGH);
  
  if (duration == 0) return 100; // Default to max prototype range if no echo
  return duration * 0.034 / 2;   // Convert to cm
}

bool controlTrafficLight(int distance, int red, int yellow, int green) {
  if (distance > 20) {  // Safe distance → Green ON
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    return false;  // No buzzer needed
  } 
  else if (distance > 10) { // Medium range → Yellow ON
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    return false;  // No buzzer needed
  } 
  else { // Danger zone → Red ON
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    return true;  // Buzzer needed
  }
}

void loop() {
  int leftDistance = getDistance(TRIG_LEFT, ECHO_LEFT);
  int rightDistance = getDistance(TRIG_RIGHT, ECHO_RIGHT);
  
  Serial.print("Left Distance: "); Serial.print(leftDistance); Serial.println(" cm");
  Serial.print("Right Distance: "); Serial.print(rightDistance); Serial.println(" cm");

  // Control both traffic lights and check if buzzer should be ON
  bool leftClose = controlTrafficLight(rightDistance, RED_LEFT, YELLOW_LEFT, GREEN_LEFT);
  bool rightClose = controlTrafficLight(leftDistance, RED_RIGHT, YELLOW_RIGHT, GREEN_RIGHT);

  // Turn ON buzzer if either side detects an object too close
  digitalWrite(BUZZER, (leftClose || rightClose) ? HIGH : LOW);

  delay(200); // Faster updates for real-time response
}
