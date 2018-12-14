#ifndef RipppleEncoder_h
#define RipppleEncoder_h
#define LIBRARY_VERSION 1.0.1

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class RipppleEncoder{

public:
	RipppleEncoder(int pinA, int pinB, int buttonPin);
	int32_t encoderCount();
	void encoderRead();
	int32_t encoderSpeed();
	bool buttonState();
	void encoderWrite(int32_t);

private:
	bool _pinAState,_pinBState,_buttonPinState,_pinA_last;
	volatile int32_t _currentCount;
	volatile int32_t _currentSpeed;
	int _pinA,_pinB,_buttonPin;

};

#endif //RipppleEncoder_h