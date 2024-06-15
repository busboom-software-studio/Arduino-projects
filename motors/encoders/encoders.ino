#include <Encoder.h>

// Define the pins for the encoder
const int encoderPinA = 2;
const int encoderPinB = 4;

// Create an encoder object
Encoder myEncoder(encoderPinA, encoderPinB);

// Variables to store encoder position and velocity

long last_x = 0, this_x = 0, dx; 
long last_t=0, this_t=0, dt;
float velocity;

void setup() {
  // Start the serial communication
  Serial.begin(9600);
  Serial.println("Encoder Test:");
  last_t = millis();
}

void loop() {
  // Read the current position of the encoder
  this_x = myEncoder.read();
  this_t = millis();

  dx = this_x - last_x;
  dt = this_t - last_t;


  // Calculate velocity (change in position over change in time)
  if (dt > 100) {
    velocity =  (float)dx / ( (float)dt/1000.0);
    last_x = this_x;
    last_t = this_t;

    Serial.print(this_x);
    Serial.print(" ");
    Serial.print(velocity);
    Serial.print(" ");
    Serial.print(dx);
    Serial.print(" ");
    Serial.println(dt);

  }



  
}