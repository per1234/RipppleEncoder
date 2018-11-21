#include <RipppleEncoder.h>
#define PROG_FREQ 20
uint32_t currentMillis;
uint32_t lastMillis;

RipppleEncoder encoder(PB13,PB14,PB15);

void enc_isr(){
	encoder.encoderRead();
}

void but_isr(){
	encoder.buttonState();
}

void setup(){
	Serial.begin(115200);

	attachInterrupt(PB13,enc_isr,CHANGE);
	attachInterrupt(PB15,but_isr,CHANGE);
}

void loop(){
	currentMillis=millis();	
	if((currentMillis-lastMillis)>=PROG_FREQ){
	Serial.print(encoder.encoderCount());
	Serial.print("  ");
	Serial.println(encoder.buttonState());
	lastMillis=currentMillis;
	}
}