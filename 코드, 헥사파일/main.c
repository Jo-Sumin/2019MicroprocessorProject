/*
 * GameProject.c
 *
 * Created: 2019-12-18 오전 1:38:39
 * Author : JoSumin
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include "_main.h"
#include "_glcd.h"
#include "_adc.h"
#include "_buzzer.h"
#include "_bitmap.h"
#include "_screen.h"

#define ADC_VREF_TYPE 0x00	// AD 컨버터 사용 기준 전압 REFS 설정
#define ADC_AVCC_TYPE 0x40	// AD 컨버터 사용 기준 전압 AVCC 설정
#define ADC_RES_TYPE 0x80	// AD 컨버터 사용 기준 전압 RES 설정
#define ADC_2_56 0xC0		// AD 컨버터 사용 기준 전압 2.56V 설정

unsigned int Data_ADC0 = 0;

unsigned int Data_ADC3 = 0;
unsigned int Data_ADC4 = 0;

int ability[4] = {0, 0, 0, 0};	// 체력, 지능, 도덕성, 감수성 수치
int ending[8] = {0, 0, 0, 0, 0, 0, 0, 0};	// 본 엔딩은 1로 체크


void endlist_screen(void) {
	if (ending[0] == 0) {
		lcd_string(0, 0, "- ??????");
	}
	else lcd_string(0, 0, "- RULER OF THE EARTH");
	
	if (ending[1] == 0) {
		lcd_string(1, 0, "- ??????");
	}
	else lcd_string(1, 0, "- PATIENT");
	
	if (ending[2] == 0) {
		lcd_string(2, 0, "- ??????");
	}
	else lcd_string(2, 0, "- SPORTS ADDICT");
	
	if (ending[3] == 0) {
		lcd_string(3, 0, "- ??????");
	}
	else lcd_string(3, 0, "- GAMBLER");
	
	if (ending[4] == 0) {
		lcd_string(4, 0, "- ??????");
	}
	else lcd_string(4, 0, "- IDOL");
	
	if (ending[5] == 0) {
		lcd_string(5, 0, "- ??????");
	}
	else lcd_string(5, 0, "- GRADUATE STUDENT");
	
	if (ending[6] == 0) {
		lcd_string(6, 0, "- ??????");
	}
	else lcd_string(6, 0, "- CLERIC");
	
	if (ending[7] == 0) {
		lcd_string(7, 0, "- ??????");
	}
	else lcd_string(7, 0, "- JUST CITIZEN");
	
	lcd_string(7, 19, "<<");
}

void ability_screen(void) {
	lcd_string(0, 0, "SRT: ");
	lcd_xy(0, 4); GLCD_4DigitDecimal(ability[0]);
	
	lcd_string(0, 10, "INT: ");
	lcd_xy(0, 14); GLCD_4DigitDecimal(ability[1]);
	
	lcd_string(1, 0, "MOR: ");
	lcd_xy(1, 4); GLCD_4DigitDecimal(ability[2]);
	
	lcd_string(1, 10, "SEN: ");
	lcd_xy(1, 14); GLCD_4DigitDecimal(ability[3]);
}


void Port_init(void) {
	DDRA = 0xFF; PORTA = 0x00;
	DDRB = 0xFF; PORTB = 0xFF;
	DDRC = 0xF0; PORTC = 0x00;
	DDRD = 0x00; PORTD = 0x00;
	DDRE = 0xFF; PORTE = 0x00;
	DDRF = 0x00; PORTF = 0x00;
}

void ADC_init(void) {
	ADCSRA = 0x00;	// disable ADC, 나중에 enable 시킬 것임
	ADMUX = 0x00;	// select ADC input 0
	
	ACSR = 0x80;	// 1000 0000
	ADCSRA = 0xC3;	// 1100 0011
	// ADC 허가, ADC 변환 시작, 분주비 8
}

void Device_init(void) {
	cli();
	Port_init();
	lcd_init();
	ADC_init();
	sei();
}

// 가변저항 값을 받는 함수
unsigned int read_adc_resistor() {
	Data_ADC0 = Read_Adc_Data(0);
	_delay_ms(10);
	return Data_ADC0;
}

unsigned int read_adc_joystick(unsigned char input) {
	unsigned int adc = 0;
	ADCSRA = 0xC3;
	ADMUX = input | ADC_AVCC_TYPE;	// ADC 사용 핀 설정
	ADCSRA |= 0x40;	// ADC Start Conversion
	
	// wait for the AD conversion to complete
	while((ADCSRA & 0x10) != 0x10) {	// 종료를 알려주는 인터럽트 플래그
		adc += ADCL + (ADCH * 256);	//	하위 8비트, 상위 2비트
	}
	
	ADCSRA = 0x00;
	
	return adc;
}

int main(void)
{
	Device_init();
	lcd_clear();
	
	// 가변저항을 seed로 받아서 능력치 값을 랜덤으로 설정한다
	srand(read_adc_resistor());
	int i;
	char select;

	int day = -1;
	
	S_Start();
	
	/* Replace with your application code */
    while (1) 
    {
		// 시작화면
		if (day == -1) {
			start_screen();
			Data_ADC3 = read_adc_joystick(3) / 14;
			Data_ADC4 = read_adc_joystick(4) / 8;
			_delay_ms(20);
			
			if (Data_ADC3 > 1000) {	// 아래
				S_Good();
				day++;
				lcd_clear();
				char_clear();
				_delay_ms(100);
			}
			
			else if (Data_ADC3 < 30) {	// 위
				SError();
				day--;
				lcd_clear();
				_delay_ms(100);
			}
		}
		
		if (day == -2) {
			endlist_screen();
			Data_ADC3 = read_adc_joystick(3) / 14;
			Data_ADC4 = read_adc_joystick(4) / 8;
			_delay_ms(200);
			
			if (Data_ADC3 > 1000) {	// 아래
				SError();
				day++;
				lcd_clear();
				_delay_ms(500);
			}
		}
		
		if (day == 0) {
			for (i = 0; i < 4; i++) {
				ability[i] = rand() % 15 + 41;
			}
			day ++;
			lcd_clear();
		}
		
		if (day < 9 && day > 0){
			ability_screen();
			todo_screen();
			char0_screen();
			
			PORTB = (0xFF & ~(1 << (day - 1)));
			
			select = (PIND & 0x1F);
			switch(select) {
				case 0x1E:	// 0001 1110
					S_Push1();
					select1_screen();
					char_clear();
					char1_screen();
					ability[0] -= 3;
					ability[1] += 6;
					ability[2] += 2;
					ability[3] -= 1;
					ability_screen();
					_delay_ms(2000);
					char_clear();
					day++;
					break;
					
				case 0x1D:	// 0001 1101
					S_Push1();
					select2_screen();
					char_clear();
					char2_screen();
					ability[0] += 2;
					ability[1] -= 2;
					ability[2] -= 2;
					ability[3] += 6;
					ability_screen();
					_delay_ms(2000);
					char_clear();
					day++;
					break;
					
				case 0x1B:	// 0001 1011
					S_Push1();
					select3_screen();
					char_clear();
					char3_screen();
					ability[0] += 6;
					ability[1] -= 1;
					ability[2] += 2;
					ability[3] -= 2;
					ability_screen();
					_delay_ms(2000);
					char_clear();
					day++;
					break;
					
				case 0x17:	// 0001 0111
					S_Push1();
					select4_screen();
					char_clear();
					char4_screen();
					ability[0] -= 2;
					ability[2] += 6;
					ability[3] += 3;
					ability_screen();
					_delay_ms(2000);
					char_clear();
					day++;
					break;
					
				case 0x0F:	// 0000 1111
					S_Push1();
					select5_screen();
					char_clear();
					char5_screen();
					ability[1] += 3;
					ability[2] -= 5;
					ability[3] -= 2;
					ability_screen();
					_delay_ms(2000);
					char_clear();
					day++;
					break;
			}
		}
		
		if(day == 9) {
			PORTB = 0x00;
			lcd_clear();
			_delay_ms(2000);
			common_ending_screen();
			day ++;
		}
		
		if(day == 10) {
			// 지구 정복
			if (ability[0] >= 57 && ability[1] >= 57 && ability[2] >= 57 && ability[3] >= 57) {
				day = -1;
				ending[0] = 1;
				end0_screen();
			}
			
			// 환자
			else if (ability[0] < 30) {
				day = -1;
				ending[1] = 1;
				end1_screen();
			}
			
			// 운동 마니아
			else if (ability[0] > 75) {
				day = -1;
				ending[2] = 1;
				end2_screen();
			}
			
			// 도박꾼
			else if (ability[1] > 40 && ability[2] <= 27) {
				day = -1;
				ending[3] = 1;
				end3_screen();
			}
			
			// 아이돌
			else if (ability[3] >= 60 && ability[2] > 27 && ability[2] < 68) {
				day = -1;
				ending[4] = 1;	
				end4_screen();
			}
			
			// 대학원생
			else if (ability[1] >= 60 && ability[2] > 27 && ability[2] < 68) {
				day = -1;
				ending[5] = 1;
				end5_screen();
			}
			
			// 성직자
			else if (ability[2] >= 68 && ability[3] > 50) {
				day = -1;
				ending[6] = 1;
				end6_screen();
			}
			
			// 선량한 소시민
			else {
				day = -1;
				ending[7] = 1;
				end7_screen();
			}
			lcd_clear();
			lcd_string(4, 0, "====== THE END ======");
			_delay_ms(4000);
			DDRB = 0xFF;
			lcd_clear();
		}
    }
}

