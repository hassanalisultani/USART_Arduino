//// Include the Software Serial library 
//#include <SoftwareSerial.h>
//// Define a Software Serial object and the used pins 
//SoftwareSerial softSerial(8, 9);  // RX, TX
//int val;
//char mystr[5]="";
//
//send_data(val)
//{
//  mystr = char(val);
//  Serial.write(mystr,5);
//}
//
//void setup()  {
//  Serial.begin(9600); 
//  softSerial.begin(9600);
//} 
//void loop()
//{
//  val = -100;
//  softSerial.write(val);
//  send_data(val)
//  delay(1000);
//}

char mystr[5] = "Hello"; //String data

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
}

void loop() {
  Serial.write(mystr,5); //Write the serial data
  delay(1000);
}
