#include "RipppleEncoder.h"

RipppleEncoder::RipppleEncoder(int pinA, int pinB, int buttonPin){
	_pinA = pinA;
	_pinB = pinB;
	_buttonPin = buttonPin;

	pinMode(_pinA, INPUT_PULLUP);
	pinMode(_pinB, INPUT_PULLUP);
	pinMode(_buttonPin, INPUT_PULLUP);
}

void RipppleEncoder::encoderRead(){
	bool n = digitalRead(_pinA);
  	if ((_pinA_last == LOW) && (n == HIGH)) {
    	if (digitalRead(_pinB) == LOW) {
      		_currentCount--;
    	} else {
      		_currentCount++;
    	}
 	}
  	_pinA_last = n;
}


int32_t RipppleEncoder::encoderCount(){
  	return _currentCount;
}

int32_t RipppleEncoder::encoderSpeed(){
	//does nothing atm
	return 0;
}

bool RipppleEncoder::buttonState(){
	bool b = digitalRead(_buttonPin);
	return b;
}

void RipppleEncoder::encoderWrite(int32_t newCount){
	_currentCount=newCount;
}

