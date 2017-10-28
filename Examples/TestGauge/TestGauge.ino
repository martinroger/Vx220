
#include "Nextion.h"

NexGauge z0 = NexGauge(0, 1, "z0");
NexProgressBar j0 = NexProgressBar(0, 2, "j0");
int number = 0;
int prev_number = 0;
int potar = 0;

void setup() {
  nexInit();
  z0.setValue(0);
  j0.setValue(0);

}

void loop() {
  //delay(100);
  if (number != prev_number)
  {
    z0.setValue(number);
    j0.setValue(map(potar,1023,0,0,100));
  }
  
//  number += 1;
  dbSerialPrintln(number);
  potar = analogRead(A12);
  
  dbSerialPrintln(potar);
  delay(10);
  prev_number = number;
  number = map(potar,1023,0,0,359);
}
