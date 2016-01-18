#include <SoftwareSerial.h>

SoftwareSerial Genotronex(2, 3); //(Rx, Dx)
int bluetoothData;
int ledpin=13;

void setup() {
  Genotronex.begin(9600);
  Genotronex.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(ledpin,OUTPUT);
}

void loop() {
  if (Genotronex.available()){
    bluetoothData=Genotronex.read();
    if(bluetoothData=='1'){   // if number 1 pressed ....
      digitalWrite(ledpin,1);
      Genotronex.println("LED  On D13 ON ! ");
    }
    if (bluetoothData=='0'){// if number 0 pressed ....
      digitalWrite(ledpin,0);
      Genotronex.println("LED  On D13 Off ! ");
    }
  }
  delay(100);// prepare for next data ...
}
