
int IRSensorL = 6; // left ir sensor connected to pin 6
int IRSensorR = 7; // right ir sensor connected to pin 7

int motorL = 11; // left motor is connected to pin 11
int motorR = 9; // right motor is connected to pin 10

int statusSensorL = 0;
int statusSensorR = 0;

void setup() {
  
  pinMode (IRSensorL, INPUT); // sensor pin INPUT
  pinMode (IRSensorR, INPUT); // sensor pin INPUT

  pinMode (motorL, OUTPUT); // sensor pin OUTPUT
  pinMode (motorR, OUTPUT); // sensor pin OUTPUT
  
  Serial.begin(9600); // open the serial port at 9600 bps
  
}


void loop() {
  
  // put your main code here, to run repeatedly:
  
  statusSensorL = digitalRead (IRSensorL);
  statusSensorR = digitalRead (IRSensorR);

  straight();
  
  if (statusSensorL <= .5) {

    // on the table
    Serial.println("HIGH - LEFT SENSOR ON THE TABLE"); 
    straight();
    
  } else { 

    // off of the table
    Serial.print("LOW - LEFT SENSOR OFF OF THE TABLE");
    halt();
    delay(1000);
    turnRight();
    delay(1500);
    halt();
  }

    
  if (statusSensorR <= .5) {

    // on the table
    Serial.println("HIGH - RIGHT SENSOR ON THE TABLE");
    straight();
     
  } else { 

    // off of the table
    Serial.print("LOW - RIGHT SENSOR OFF OF THE TABLE");
    halt();
    delay(1000);
    turnLeft();
    delay(1500);
    halt();
    
  }

}

void straight() {
  analogWrite(motorL, 150);
  analogWrite(motorR, 150);
}

void halt() {
  analogWrite(motorL, 0);
  analogWrite(motorR, 0);
}

void turnLeft() {
  analogWrite(motorL, 0);
  analogWrite(motorR, 150);
  
}

void turnRight() {
  analogWrite(motorL, 150);
  analogWrite(motorR, 0);
}
