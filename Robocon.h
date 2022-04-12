#ifndef	_ROBOCON_BKIT_
#define _ROBOCON_BKIT_

#include "define.h"
#include "Encoder/encoder.h"
#include "Physical/physical.h"
#include "ADC/adc.h"
#include "Delay/delay.h"
//#include "Led/led.h"
#include "Speed/speed.h"
#include "Timer/timer.h"
#include "Pid/pid.h"
#include "forward/forward.h"
#include "EEPROM/eeprom.h"
#include "Lcd/lcd.h"
#include "Spi/spi.h"
//#include "I2C/i2c.h"
//#include "Manual/manual.h"
#include "run/run.h"
#include "gamepad/gamepad.h"

void Atmega64_init();
void Init();

void test();

#endif
