#include "Robocon.h"

unsigned char run_flag = 0;	//begin with test period

unsigned char cnt_lcd = 20;
unsigned char count_timer =0;
void lcd_handler(){
	if(cnt_lcd == 0)
	{

		cnt_lcd = 20;
	} else {
		cnt_lcd--;
	}
}

ISR (TIMER1_OVF_vect)
{
// Reinitialize Timer 1 value
    TCNT1H = 0xD8;
    TCNT1L = 0x30;
    
    Virtual_timer();
	read_sensor();
	update_Input();
	update_sensor();//update value line,we can put it in test_forward_pd()
	check_cross_line();
	//update_gamepad;//update gamepad
    
	forward_mode1();
	forward_mode2();
	count_timer++;
	if (count_timer == 1)
	{
		count_timer = 0;
		Sample_LR();
		if(bool_hold_vel)
			Hold_vel();
	}
	

//vuhai1904
	hand_mode();
	time_counter();
	push_block_handler();
	run_forward_distance_handler();
	keep_forward_line_handler();
}

void test(){
//	unsigned char tmp_uchar = 0;
//	int tmp_int = 0;
	
}

int main()
{
	Init();
	asm("sei");		//interrupt enable
	run();
	while(1);
	return 1;
}

void Init()
{
	Atmega64_init();
	init_motors();
	init_physical();
	init_encoder();
//	led_init();
	spi_init();
	lcd_init();
	timer_init();	
	read_Vcompare();	//adc	
}

void Atmega64_init(){
    // Port A initialization
	// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
	// State7=1 State6=1 State5=1 State4=1 State3=1 State2=1 State1=1 State0=1 
	PORTA=0xFF;
	DDRA=0xFF;

	// Port B initialization
	// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
	// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
	PORTB=0xFF;
	DDRB=0x97;

	// Port C initialization
	// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
	// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
	PORTC=0x00;
	DDRC=0x00;

	// Port D initialization
	// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
	// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
	PORTD=0x00;
	DDRD=0x00;

	// Port E initialization
	// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
	// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
	PORTE=0x00;
	DDRE=0x38;

	// Port F initialization
	// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
	// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
	PORTF=0x00;
	DDRF=0x00;

	// Port G initialization
	// Func4=In Func3=In Func2=Out Func1=Out Func0=Out 
	// State4=T State3=T State2=1 State1=1 State0=1 
	PORTG=0x1f;
	DDRG=0x07;

    // Timer/Counter 0 initialization
    // Clock source: System Clock
    // Clock value: 2000.000 kHz
    // Mode: Phase correct PWM top=FFh
    // OC0 output: Non-Inverted PWM
    ASSR=0x00;
    TCCR0=0x72;
    TCNT0=0x00;
    OCR0=0x00;
    
    // Timer/Counter 1 initialization
    // Clock source: System Clock
    // Clock value: 16000.000 kHz
    // Mode: Normal top=FFFFh
    // OC1A output: Discon.
    // OC1B output: Discon.
    // OC1C output: Discon.
    // Noise Canceler: Off
    // Input Capture on Falling Edge
    // Timer 1 Overflow Interrupt: On
    // Input Capture Interrupt: Off
    // Compare A Match Interrupt: Off
    // Compare B Match Interrupt: Off
    // Compare C Match Interrupt: Off
    TCCR1A=0x00;
    TCCR1B=0x02;
    TCNT1H=0xd8;
    TCNT1L=0x30;
    ICR1H=0x00;
    ICR1L=0x00;
    OCR1AH=0x00;
    OCR1AL=0x00;
    OCR1BH=0x00;
    OCR1BL=0x00;
    OCR1CH=0x00;
    OCR1CL=0x00;
    
    // Timer/Counter 2 initialization
    // Clock source: System Clock
    // Clock value: 2000.000 kHz
    // Mode: Phase correct PWM top=FFh
    // OC2 output: Non-Inverted PWM
    TCCR2=0x72;
    TCNT2=0x00;
    OCR2=0x00;
    
    // Timer/Counter 3 initialization
    // Clock source: System Clock
    // Clock value: 2000.000 kHz
    // Mode: Ph. correct PWM top=00FFh
    // Noise Canceler: Off
    // Input Capture on Falling Edge
    // OC3A output: Inverted
    // OC3B output: Inverted
    // OC3C output: Inverted
    // Timer 3 Overflow Interrupt: Off
    // Input Capture Interrupt: Off
    // Compare A Match Interrupt: Off
    // Compare B Match Interrupt: Off
    // Compare C Match Interrupt: Off
    TCCR3A=0xFD;
    TCCR3B=0x02;
    TCNT3H=0x00;
    TCNT3L=0x00;
    ICR3H=0x00;
    ICR3L=0x00;
    OCR3AH=0x00;
    OCR3AL=0x00;
    OCR3BH=0x00;
    OCR3BL=0x00;
    OCR3CH=0x00;
    OCR3CL=0x00;
    
    // External Interrupt(s) initialization
	// INT0: Off
	// INT1: Off
	// INT2: On
	// INT2 Mode: Rising Edge
	// INT3: On
	// INT3 Mode: Rising Edge
	// INT4: Off
	// INT5: Off
	// INT6: On
	// INT6 Mode: Rising Edge
	// INT7: On
	// INT7 Mode: Rising Edge
	EICRA=0xF0;
	EICRB=0xF0;
	EIMSK=0xCC;
	EIFR=0xCC;
    
    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK=0x04;
    ETIMSK=0x00;
	SREG = SREG | 0x80;

	// ADC initialization
    // ADC Clock frequency: 1000.000 kHz
    // ADC Voltage Reference: AVCC pin
    // Only the 8 most significant bits of
    // the AD conversion result are used
    ADMUX=ADC_VREF_TYPE & 0xff;
    ADCSRA=0x84;
}
