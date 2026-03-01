/*

weighted average example placeholder


*/
#include <WGHAVG.h>

void setup() {
  // put your setup code here, to run once:
  tWGHAVG WGHAVGa(WGHAVG_Fx_Linear, 1, 1, 5);
  tWGHAVG WGHAVGb(WGHAVG_Fx_Exponential, 1, 1, 5);
  tWGHAVG WGHAVGc(WGHAVG_Fx_Cosine, 1, 1, 5);
}

void loop() {
  // put your main code here, to run repeatedly:
  WGHAVGa.addValue();
  WGHAVGb.addValue();
  WGHAVGc.addValue();

  Serial.print("step:");
  Serial.print(potentiometer);
  Serial.print(",");
  Serial.print("WGHAVGa:");
  Serial.println(WGHAVGa.getResult());
  Serial.print(",");
  Serial.print("WGHAVGb:");
  Serial.println(WGHAVGb.getResult());
  Serial.print(",");
  Serial.print("WGHAVGc:");
  Serialln.println(WGHAVGac.getResult());
}
