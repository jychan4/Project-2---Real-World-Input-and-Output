/*
 * Yew Journ Chan
 * Project 2 - Real World Input and Output
 * This function is supposed to measure the temperature of the room and output a certain color on the RGB LED
 * - Since I do not have all the necessary parts to complete my intended project, I have decided to use the light sensor to substitute the thermometer.
 * - In a room temperature state (regular room light): the light will constantly blink blue and green
 * - In a warmer temperature state(when light is shined on sensor): the red light will constantly stay on.
 * - In a cooler temperature state(when sensor is completely covered): the green light will constantly stay on.
 */


 int HoverButton = A0;
 int red = 12;
 int green = 27;
 int blue = 33;
 int delayTime = 100;

 void setup() { 
  Serial.begin(9600); // set to initialize serial communication at 9600bps

  //set pins as an input & output
  pinMode(HoverButton, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
 }


 void loop() {  //main loop
 int sensorValue = analogRead(HoverButton); //to define sensor values as an int
 sensorValue = constrain(sensorValue, 1300, 3700); //the light will work only under following inputs established on the terminal
 Serial.println(sensorValue);
 delay(1); 

 if(sensorValue > 3000) { //HIGH TEMPERATURE STATE: when light is flashed on sensor, LED will shine red
  digitalWrite(red, HIGH); //will turn the light on constantly
 }

 else if(sensorValue > 1300 && sensorValue < 2500) { //ROOM TEMPERATURE STATE: neautral state, LED will blink
  digitalWrite(green, HIGH);
  delay(300);
  digitalWrite(green, LOW);
  delay(300);
 }else if(sensorValue > 1300) { // LOW TEMPERATURE STATE: LED will shine blue
  digitalWrite(blue, HIGH);
  }
 }
