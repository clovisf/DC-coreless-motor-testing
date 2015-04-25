// Multiwii motor testing sketch! (essentially a PWM voltage).
// made by Clovis Fritzen in 04/25/2015


// Variables used on this code
unsigned long time;
unsigned long previousTime;
boolean enterFunction= true;
int motorPin = 5; // pin where my motor is connected
unsigned long pwmValue = 0;
unsigned long int subjecttime = 29998;
unsigned long entertimes = 0;
unsigned long entercounter = 0;
unsigned long entertime = 0;
unsigned long voltage = 0.00;
//-----------------------



void setup() {
  Serial.begin(115200); 
}

void loop() {
  time = micros();
  if (enterFunction == true){ // "delay" function without an actual useless real delay (your code
                              // can do other stuff instead of just sit and wait).
    previousTime= time;
    entercounter = entercounter +1;
    
    // Start your code below 
    //-----------------------
    
  voltage = analogRead(A2);
  pwmValue = voltage/4; // reading potentiometer reference (0-1024) and transforming
                        // it to values usable by the analogWrite function (0-255)
  voltage = voltage * 0.004887586;
  
                               
  if (pwmValue < 14) { // if the adjusted voltage is smaller than 30% the DC voltage,
  // makes it be 30% of DC voltage (it means the smallest voltage value applied to 
  // the motor is 30% of VDC.
    pwmValue = 0;
  } else {
    if (pwmValue < 76) { // if the reference voltage is smaller
                         // than 5%, turn the motor off
      pwmValue = 76;
    }
  }
  
  analogWrite(motorPin, pwmValue); // write the required pwm to the output
  

    //-----------------------
    // End of your code
  }
  
  entertimes = 1000000/subjecttime;
   
    if (entercounter > entertimes) {
      entercounter = 0;
    Serial.print("time: "); // for debugging
    Serial.println(previousTime/1000000,1); // for debugging
    Serial.print("voltage: ");
    Serial.println(voltage,1);
    }
    
  // The DELAY time is adjusted in the constant below >> 
  if (time - previousTime < subjecttime){ // 1 million microsencods= 1 second delay
     
    enterFunction= false;
  } 
  else {
    enterFunction= true;
  }





}
