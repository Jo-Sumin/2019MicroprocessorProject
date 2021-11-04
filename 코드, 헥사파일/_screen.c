
#include "_main.h"
#include "_glcd.h"
#include "_screen.h"
#include "_bitmap.h"
#include "_buzzer.h"

void start_screen(void) {
	lcd_string(0, 0, " * STUDENT  MAKER * ");
	
	lcd_string(3, 1, "<UP> to ENDING LIST");
	lcd_string(4, 3, "<DOWN> to START");

	lcd_string(7, 0, "made by Sumin");
}

void todo_screen(void) {
	lcd_string(2, 10, "To-do list");
	lcd_string(3, 10, "1.STUDYING");
	lcd_string(4, 10, "2.SINGING");
	lcd_string(5, 10, "3.SPORTS");
	lcd_string(6, 10, "4.CHURCH");
	lcd_string(7, 10, "5.GAMBLING");
}

void common_ending_screen(void) {
	lcd_string(0, 0, "Day 9");
	_delay_ms(700);
	lcd_string(2, 0, "From Today,");
	lcd_string(3, 0, "I leave home!");
	_delay_ms(700);
	lcd_string(4, 0, "Thanks to");
	lcd_string(5, 0, "Bring me up.");
	_delay_ms(700);
	lcd_string(7, 0, "Bye Bye!");
	_delay_ms(2000);
	lcd_clear();
	lcd_string(4, 3, "2 Years Later...");
	_delay_ms(2000);
	lcd_clear();
	lcd_string(0, 0, "LONG TIME NO SEE!");
	_delay_ms(700);
	lcd_string(1, 0, "How is it going?");
	_delay_ms(700);
}

void best_ending_screen(void) {
	lcd_string(3, 0, "I live");
	lcd_string(4, 0, "WONDERFUL LIFE XD");
	_delay_ms(700);
	lcd_string(5, 0, "Do you know");
	lcd_string(6, 0, "What I'm doing?");
	_delay_ms(2000);
	lcd_clear();
}
void good_ending_screen(void) {
	lcd_string(3, 0, "I'm doing Fine :D");
	_delay_ms(700);
	lcd_string(5, 0, "Do you know");
	lcd_string(6, 0, "What I'm doing?");
	_delay_ms(2000);
	lcd_clear();
}
void normal_ending_screen(void) {
	lcd_string(3, 0, "I live a quite life");
	_delay_ms(700);
	lcd_string(5, 0, "Do you know");
	lcd_string(6, 0, "What I'm doing?");
	_delay_ms(2000);
	lcd_clear();
}
void bad_ending_screen(void) {
	lcd_string(3, 0, "I'm doing BAD :(");
	_delay_ms(700);
	lcd_string(5, 0, "Do you know");
	lcd_string(6, 0, "What I'm doing?");
	_delay_ms(2000);
	lcd_clear();
}

void select1_screen(void) {
	lcd_string(2, 10, "          ");
	lcd_string(4, 10, "          ");
	lcd_string(5, 10, "          ");
	lcd_string(6, 10, "          ");
	lcd_string(7, 10, "          ");
}

void select2_screen(void) {
	lcd_string(2, 10, "          ");
	lcd_string(3, 10, "          ");
	lcd_string(5, 10, "          ");
	lcd_string(6, 10, "          ");
	lcd_string(7, 10, "          ");
}

void select3_screen(void) {
	lcd_string(2, 10, "          ");
	lcd_string(3, 10, "          ");
	lcd_string(4, 10, "          ");
	lcd_string(6, 10, "          ");
	lcd_string(7, 10, "          ");
}

void select4_screen(void) {
	lcd_string(2, 10, "          ");
	lcd_string(3, 10, "          ");
	lcd_string(4, 10, "          ");
	lcd_string(5, 10, "          ");
	lcd_string(7, 10, "          ");
}

void select5_screen(void) {
	lcd_string(2, 10, "          ");
	lcd_string(3, 10, "          ");
	lcd_string(4, 10, "          ");
	lcd_string(5, 10, "          ");
	lcd_string(6, 10, "          ");
}

void char0_screen(void) {
	char_head_display();
	char_body0_display();
	char_arm0_display();
	char_face0_display();
}

// 공부
void char1_screen(void) {
	char_head_display();
	char_arm0_display();
	char_body0_display();
	char_face1_display();
	state1_display();
}
// 노래
void char2_screen(void) {
	char_head_display();
	char_arm4_display();
	char_body4_display();
	char_face2_display();
	state2_display();
}
// 운동
void char3_screen(void) {
	char_head_display();
	char_arm3_display();
	char_body3_display();
	char_face3_display();
	state3_display();
}
// 교회
void char4_screen(void) {
	char_head_display();
	char_arm4_display();
	char_body4_display();
	char_face4_display();
	state4_display();
}
// 도박
void char5_screen(void) {
	char_head_display();
	char_arm3_display();
	char_body3_display();
	char_face5_display();
	state5_display();
}

// 지구정복
void end0_screen(void) {
	best_ending_screen();
	char_head_display();
	char_face3_display();
	char_body3_display();
	char_arm3_display();
	twinkle_display();
	_delay_ms(700);
	
	lcd_string(1, 4, "Now, I am a");
	_delay_ms(700);
	lcd_string(3, 10, "RULER OF");
	lcd_string(4, 10, "THE EARTH!");
	_delay_ms(2000);
	
	lcd_clear();
	S_S1();
}
// 환자
void end1_screen(void) {
	bad_ending_screen();
	char_head_display();
	char_face1_display();
	char_body0_display();
	char_arm0_display();
	_delay_ms(700);
	
	lcd_string(1, 4, "Now, I am a");
	_delay_ms(700);
	lcd_string(3, 10, "PATIENT");
	lcd_string(4, 13, ":(");
	_delay_ms(2000);
	
	lcd_clear();
	SError();
}
// 운동 마니아
void end2_screen(void) {
	good_ending_screen();
	char3_screen();
	_delay_ms(700);
	
	lcd_string(1, 4, "Now, I am a");
	_delay_ms(700);
	lcd_string(3, 10, "SPORTS");
	lcd_string(4, 10, "ADDICT!!");
	_delay_ms(2000);
	
	lcd_clear();
	S_S1();
}
// 도박꾼
void end3_screen(void) {
	good_ending_screen();
	char5_screen();
	_delay_ms(700);
	
	lcd_string(1, 4, "Now, I am a");
	_delay_ms(700);
	lcd_string(3, 10, "GAMBLER!");
	_delay_ms(700);
	lcd_string(5, 10, "I love");
	lcd_string(6, 10, "MONEY!");
	_delay_ms(2000);
	
	lcd_clear();
	SError();
}
// 아이돌
void end4_screen(void) {
	good_ending_screen();
	char2_screen();
	_delay_ms(700);
	
	lcd_string(1, 4, "Now, I am an");
	_delay_ms(700);
	lcd_string(3, 10, "IDOL!!!!");
	_delay_ms(2000);
	
	lcd_clear();
	S_S1();
}
// 대학원생
void end5_screen(void) {
	bad_ending_screen();
	char1_screen();
	_delay_ms(700);
	
	lcd_string(1, 4, "Now, I am a");
	_delay_ms(700);
	lcd_string(3, 10, "GRADUATE");
	lcd_string(4, 10, "STUDENT");
	lcd_string(5, 13, ":(");
	_delay_ms(2000);
	
	lcd_clear();
	SError();
}
// 성직자
void end6_screen(void) {
	normal_ending_screen();
	char4_screen();
	_delay_ms(700);
	
	lcd_string(1, 4, "Now, I am a");
	_delay_ms(700);
	lcd_string(3, 10, "CLERIC");
	_delay_ms(2000);
	
	lcd_clear();
	S_S5();	
}
// 선량한 소시민
void end7_screen(void) {
	normal_ending_screen();
	char0_screen();	
	_delay_ms(700);
	
	lcd_string(1, 4, "Now, I am a");
	_delay_ms(700);
	lcd_string(3, 10, "JUST");
	lcd_string(4, 10, "CITIZEN");
	_delay_ms(2000);
	
	lcd_clear();
	S_S5();
}