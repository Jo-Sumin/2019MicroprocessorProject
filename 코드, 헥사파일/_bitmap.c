#include <avr/io.h>
#include "_main.h"
#include "_bitmap.h"
#include "_glcd.h"

void char_clear(void) {
	for (int i = 22; i < 64; i++) {
		for (int j = 0; j < 63; j++) {
			GLCD_Delete_Dot(i, j);
		}
	}
}

void char_head_display(void) {
	for (int j = 28; j < 40; j++) {
		GLCD_Dot(22, j);
		GLCD_Dot(47, j);
	}
	
	for (int i = 32; i <40; i++) {
		GLCD_Dot(i, 20);
		GLCD_Dot(i, 47);
	}
	
	GLCD_Dot(23, 22);GLCD_Dot(23, 23);GLCD_Dot(23, 24);GLCD_Dot(23, 26);GLCD_Dot(23, 27);
	GLCD_Dot(23, 40);GLCD_Dot(23, 41);GLCD_Dot(23, 43);GLCD_Dot(23, 44);GLCD_Dot(23, 45);
	
	GLCD_Dot(24, 21);GLCD_Dot(24, 24);GLCD_Dot(24, 25);GLCD_Dot(24, 26);
	GLCD_Dot(24, 41);GLCD_Dot(24, 42);GLCD_Dot(24, 43);GLCD_Dot(24, 44);GLCD_Dot(24, 46);
	
	GLCD_Dot(25, 20);GLCD_Dot(25, 24); GLCD_Dot(25, 44);GLCD_Dot(25, 47);
	GLCD_Dot(26, 20);GLCD_Dot(26, 23); GLCD_Dot(26, 45);GLCD_Dot(26, 48);
	
	GLCD_Dot(27, 19);GLCD_Dot(27, 22); GLCD_Dot(27, 46);GLCD_Dot(27, 49);
	GLCD_Dot(28, 18);GLCD_Dot(28, 22); GLCD_Dot(28, 46);GLCD_Dot(28, 50);
	GLCD_Dot(29, 17);GLCD_Dot(29, 20);GLCD_Dot(29, 21); GLCD_Dot(29, 46);GLCD_Dot(29, 47);GLCD_Dot(29, 50);
	
	GLCD_Dot(30, 18);GLCD_Dot(30, 19);GLCD_Dot(30, 21); GLCD_Dot(30, 46);GLCD_Dot(30, 48);GLCD_Dot(30, 49);
	GLCD_Dot(31, 21); GLCD_Dot(31, 46);

	GLCD_Dot(40, 21);GLCD_Dot(40, 46); GLCD_Dot(41, 21);GLCD_Dot(41, 46);
	GLCD_Dot(42, 22);GLCD_Dot(42, 45);
	GLCD_Dot(43, 23);GLCD_Dot(43, 44); GLCD_Dot(44, 24); GLCD_Dot(44, 43);
	GLCD_Dot(45, 25);GLCD_Dot(45, 42);
	GLCD_Dot(46, 26);GLCD_Dot(46, 27); GLCD_Dot(46, 40);GLCD_Dot(46,41);
	
}

void char_arm0_display(void) {
	GLCD_Dot(45, 23); GLCD_Dot(45, 44); GLCD_Dot(46, 22); GLCD_Dot(46, 45); GLCD_Dot(47, 22); GLCD_Dot(47, 45); GLCD_Dot(48, 22); GLCD_Dot(48,45);
	GLCD_Dot(49, 21);GLCD_Dot(50, 21);GLCD_Dot(51, 21);GLCD_Dot(49, 46);GLCD_Dot(50, 46);GLCD_Dot(51, 46);
	
	for (int i = 52; i < 56; i++) {
		GLCD_Dot(i, 20); GLCD_Dot(i, 47);
	}
	
	for (int i = 56; i < 61; i++) {
		GLCD_Dot(i, 19); GLCD_Dot(i, 48);
	}
	
	GLCD_Dot(61, 20);GLCD_Dot(61, 21); GLCD_Dot(61, 46);GLCD_Dot(61, 47);
	GLCD_Dot(62, 22);GLCD_Dot(62, 23); GLCD_Dot(62, 44);GLCD_Dot(62, 45);
	
	for (int i = 58; i < 62; i++) {
		GLCD_Dot(i, 24); GLCD_Dot(i, 43);
	}
		
	for (int i = 54; i < 58; i++) {
		GLCD_Dot(i, 25); GLCD_Dot(i, 42);
	}
}
void char_arm3_display(void) {
	for(int j = 20; j < 24; j++) {
		GLCD_Dot(45, j);
	}
	for(int j = 44; j < 48; j++) {
		GLCD_Dot(45, j);
	}
	
	for(int j = 17; j < 20; j++) {
		GLCD_Dot(46, j);
	}
	for(int j = 48; j < 51; j++) {
		GLCD_Dot(46, j);
	}
	GLCD_Dot(47, 16); GLCD_Dot(47, 51);
	
	for(int i = 48; i < 51; i++) {
		GLCD_Dot(i, 15); GLCD_Dot(i, 52);
	}
	for(int i = 51; i < 54; i++) {
		GLCD_Dot(i, 14); GLCD_Dot(i, 53);
	}
	
	GLCD_Dot(54, 15); GLCD_Dot(54, 52);
	GLCD_Dot(55, 16); GLCD_Dot(55, 17); GLCD_Dot(55, 50); GLCD_Dot(55, 51);
	
	GLCD_Dot(53, 18); GLCD_Dot(54, 18); GLCD_Dot(53, 49);GLCD_Dot(54, 49);
	
	GLCD_Dot(52, 19); GLCD_Dot(52, 48);
	
	for(int j = 20; j < 23; j++) {
		GLCD_Dot(51, j);
	}
	for(int j = 45; j < 48; j++) {
		GLCD_Dot(51, j);
	}
	
	for(int j = 23; j < 26; j++) {
		GLCD_Dot(50, j);
	}
	for(int j = 42; j < 45; j++) {
		GLCD_Dot(50, j);
	}
}
void char_arm4_display(void) {
	GLCD_Dot(46, 24); GLCD_Dot(46, 43);
	GLCD_Dot(47, 23); GLCD_Dot(47, 44);
	
	for(int i = 48; i < 54; i++) {
		GLCD_Dot(i, 22); GLCD_Dot(i, 45);
	}
	
	GLCD_Dot(54, 23); GLCD_Dot(54, 44);
	GLCD_Dot(55, 23); GLCD_Dot(55, 44);
	
	for(int j = 24; j < 33; j++) {
		GLCD_Dot(56, j);
	}
	for(int j = 36; j < 44; j++) {
		GLCD_Dot(56, j);
	}
	
	for(int i = 52; i < 56; i++) {
		GLCD_Dot(i, 34); GLCD_Dot(i, 35);
	}
	
	for(int j = 29; j < 34; j++) {
		GLCD_Dot(51, j);
	}
	for(int j = 36; j < 41; j++) {
		GLCD_Dot(51, j);
	}
}

void char_body0_display(void) {
	for (int i = 56; i < 64; i++) {
		GLCD_Dot(i, 26); GLCD_Dot(i, 41);
	}
}
void char_body3_display(void) {
	for (int i = 50; i < 64; i++) {
		GLCD_Dot(i, 26); GLCD_Dot(i, 41);
	}
}
void char_body4_display(void) {
	for (int i = 57; i < 64; i++) {
		GLCD_Dot(i, 26); GLCD_Dot(i, 41);
	}
}

void char_face0_display(void) {
	for(int j = 28; j < 32; j++) {
		GLCD_Dot(31, j);
	}
	for(int j = 38; j < 42; j++) {
		GLCD_Dot(31, j);
	}
	GLCD_Dot(32, 27); GLCD_Dot(32, 32);
	GLCD_Dot(32, 37); GLCD_Dot(32, 42);
	
	for(int j = 33; j < 37; j++) {
		GLCD_Dot(35, j);
	}
	GLCD_Dot(36, 33); GLCD_Dot(37, 33);
	GLCD_Dot(36, 36); GLCD_Dot(37, 36);
	GLCD_Dot(38, 34); GLCD_Dot(38, 35);
}
void char_face1_display(void) {
	for(int j = 27; j < 31; j++) {
		GLCD_Dot(29, j);
	}
	GLCD_Dot(29, 33);
	for(int j = 27; j < 33; j++) {
		GLCD_Dot(31, j);
		GLCD_Dot(33, j);
	}
	GLCD_Dot(32, 30);
	for(int j = 27; j < 31; j++) {
		GLCD_Dot(34, j);
	}
	for(int j = 27; j < 30; j++) {
		GLCD_Dot(35, j);
	}
	
	
	GLCD_Dot(29, 36);
	for(int j = 38; j < 43; j++) {
		GLCD_Dot(29, j);
	}
	for(int j = 37; j < 43; j++) {
		GLCD_Dot(31, j);
		GLCD_Dot(33, j);
	}
	GLCD_Dot(32, 39);
	for(int j = 39; j < 43; j++) {
		GLCD_Dot(34, j);
	}
	for(int j = 40; j < 43; j++) {
		GLCD_Dot(35, j);
	}

	for(int j = 33; j < 37; j++) {
		GLCD_Dot(37, j);
		GLCD_Dot(39, j);
	}
	GLCD_Dot(38, 32); GLCD_Dot(38, 37);
}
void char_face3_display(void) {
	GLCD_Dot(31, 31); GLCD_Dot(31, 32);
	GLCD_Dot(30, 30); GLCD_Dot(30, 29); GLCD_Dot(32, 30); GLCD_Dot(32, 29);
	GLCD_Dot(29, 28); GLCD_Dot(29, 27); GLCD_Dot(33, 28); GLCD_Dot(33, 27);
	
	GLCD_Dot(31, 37); GLCD_Dot(31, 38);
	GLCD_Dot(30, 39); GLCD_Dot(30, 40); GLCD_Dot(32, 39); GLCD_Dot(32, 40);
	GLCD_Dot(29, 41); GLCD_Dot(29, 42); GLCD_Dot(33, 41); GLCD_Dot(33, 42);
	
	for(int j = 30; j < 40; j++) {
		GLCD_Dot(35, j);
	}
	GLCD_Dot(36, 30); GLCD_Dot(36, 39);
	GLCD_Dot(37, 30); GLCD_Dot(37, 39);
	GLCD_Dot(38, 31); GLCD_Dot(38, 38);
	GLCD_Dot(39, 31); GLCD_Dot(39, 38);
	GLCD_Dot(40, 32); GLCD_Dot(40, 37);
	for(int j = 33; j < 37; j++) {
		GLCD_Dot(41, j);
	}
}
void char_face2_display(void) {
	for(int j = 28; j < 32; j++) {
		GLCD_Dot(31, j);
	}
	for(int j = 38; j < 42; j++) {
		GLCD_Dot(31, j);
	}
	GLCD_Dot(32, 27); GLCD_Dot(32, 32);
	GLCD_Dot(32, 37); GLCD_Dot(32, 42);
	
	for(int j = 26; j < 29; j++) {
		GLCD_Dot(34, j); GLCD_Dot(35, j);
	}
	for(int j = 40; j < 43; j++) {
		GLCD_Dot(34, j); GLCD_Dot(35, j);
	}
	
	for(int j = 33; j < 37; j++) {
		GLCD_Dot(35, j);
	}
	GLCD_Dot(36, 33); GLCD_Dot(37, 33);
	GLCD_Dot(36, 36); GLCD_Dot(37, 36);
	GLCD_Dot(38, 34); GLCD_Dot(38, 35);
}
void char_face4_display(void) {
	for(int j = 28; j < 32; j++) {
		GLCD_Dot(33, j);
	}
	for(int j = 38; j < 42; j++) {
		GLCD_Dot(33, j);
	}
	GLCD_Dot(32, 27); GLCD_Dot(32, 32);
	GLCD_Dot(32, 37); GLCD_Dot(32, 42);
	
	for(int j = 33; j < 37; j++) {
		GLCD_Dot(35, j);
	}
	GLCD_Dot(36, 33); GLCD_Dot(37, 33);
	GLCD_Dot(36, 36); GLCD_Dot(37, 36);
	GLCD_Dot(38, 34); GLCD_Dot(38, 35);
}
void char_face5_display(void) {
	
	for(int j = 27; j < 31; j++) {
		GLCD_Dot(29, j);
	}
	GLCD_Dot(30, 26); GLCD_Dot(30, 31);
	GLCD_Dot(31, 29);
	for(int j = 26; j < 32; j++) {
		GLCD_Dot(33, j);
	}
	
	for(int j = 38; j < 42; j++) {
		GLCD_Dot(29, j);
	}
	GLCD_Dot(30, 37); GLCD_Dot(30, 42);
	GLCD_Dot(31, 39);
	for(int j = 37; j < 43; j++) {
		GLCD_Dot(33, j);
	}
	
	
	for(int j = 33; j < 38; j++) {
		GLCD_Dot(35, j);
	}
	GLCD_Dot(36, 33); GLCD_Dot(36, 37);
	GLCD_Dot(37, 34); GLCD_Dot(37, 36);
	GLCD_Dot(38, 35);
}


void state1_display(void) {
	for(int j = 4; j < 8; j++) {
		GLCD_Dot(27, j);
		GLCD_Dot(34, j);
	}
	
	GLCD_Dot(28, 3); GLCD_Dot(28, 8); GLCD_Dot(29, 2); GLCD_Dot(30, 1); GLCD_Dot(31, 1);
	
	for(int i = 29; i < 33; i++){
		GLCD_Dot(i, 9);
	}
	
	GLCD_Dot(33, 8);
	
	for(int i = 31; i < 34; i++){
		GLCD_Dot(i, 3);
	}
	
	GLCD_Dot(30, 4); GLCD_Dot(29, 5); GLCD_Dot(29, 6); GLCD_Dot(30, 7); GLCD_Dot(31, 7); GLCD_Dot(32, 6);
	
	GLCD_Dot(42, 7); GLCD_Dot(42, 13);
	for(int j = 8; j < 13; j++) {
		GLCD_Dot(41, j); GLCD_Dot(50, j);
	}
	for(int j = 9; j < 12; j++) {
		GLCD_Dot(43, j);
	}
	GLCD_Dot(43, 14);
	for(int i = 44; i < 48; i++) {
		GLCD_Dot(i, 15);
	}
	
	GLCD_Dot(44, 8); GLCD_Dot(44, 12);
	GLCD_Dot(45, 7); GLCD_Dot(45, 10); GLCD_Dot(45, 13);
	for(int i = 46; i < 49; i++) {
		GLCD_Dot(i, 6);
	}
	GLCD_Dot(46, 9); GLCD_Dot(46, 13);
	GLCD_Dot(47, 9); GLCD_Dot(47, 12);
	GLCD_Dot(48, 10); GLCD_Dot(48, 11); GLCD_Dot(48, 14);
	GLCD_Dot(49, 7); GLCD_Dot(49, 13);	
}
void state2_display(void) {
	for(int j = 4; j < 10; j++) {
		GLCD_Dot(28, j);
	}
	
	for(int i = 29; i < 34; i++) {
		GLCD_Dot(i, 4); GLCD_Dot(i, 9);
	}
	
	GLCD_Dot(32, 2); GLCD_Dot(32, 3); GLCD_Dot(32, 7); GLCD_Dot(32, 8);
	GLCD_Dot(33, 2); GLCD_Dot(33, 3); GLCD_Dot(33, 7); GLCD_Dot(33, 8);
	
	for(int i = 37; i < 44; i++) {
		GLCD_Dot(i, 12);
	}
	GLCD_Dot(42, 9); GLCD_Dot(42, 10); GLCD_Dot(42, 11);
	GLCD_Dot(43, 9); GLCD_Dot(43, 10); GLCD_Dot(43, 11);
	
	GLCD_Dot(38, 13); GLCD_Dot(38, 14);
	GLCD_Dot(39, 15); GLCD_Dot(40, 15);
}
void state3_display(void) {
	GLCD_Dot(26, 12); GLCD_Dot(26, 13); GLCD_Dot(26, 14);
	GLCD_Dot(27, 10); GLCD_Dot(27, 11); GLCD_Dot(27, 13);
	GLCD_Dot(28, 9); GLCD_Dot(28, 12);
	GLCD_Dot(29, 9); GLCD_Dot(29, 12);
	GLCD_Dot(30, 10); GLCD_Dot(30, 11);
	
	GLCD_Dot(33, 12); GLCD_Dot(33, 13); GLCD_Dot(33, 14);
	GLCD_Dot(34, 10); GLCD_Dot(34, 11); GLCD_Dot(34, 13);
	GLCD_Dot(35, 9); GLCD_Dot(35, 12);
	GLCD_Dot(36, 9); GLCD_Dot(36, 12);
	GLCD_Dot(37, 10); GLCD_Dot(37, 11);
}
void state4_display(void) {
	for(int i = 34; i < 49; i++) {
		GLCD_Dot(i, 7); GLCD_Dot(i, 8);
	}
	for(int j = 3; j < 7; j++) {
		GLCD_Dot(37, j); GLCD_Dot(38, j);
	}
	for(int j = 9; j < 13; j++) {
		GLCD_Dot(37, j); GLCD_Dot(38, j);
	}
}
void state5_display(void) {
	for(int j = 5; j < 10; j++) {
		GLCD_Dot(27, j); GLCD_Dot(35, j);
	}
	for(int i = 26; i < 37; i++) {
		GLCD_Dot(i, 7);
	}
	GLCD_Dot(28, 4); GLCD_Dot(28, 9);
	GLCD_Dot(29, 4); GLCD_Dot(29, 10);
	GLCD_Dot(30, 5); GLCD_Dot(30, 10);
	GLCD_Dot(31, 6); GLCD_Dot(31, 8);
	GLCD_Dot(32, 4); GLCD_Dot(32, 9);
	GLCD_Dot(33, 4); GLCD_Dot(33, 10);
	GLCD_Dot(34, 5); GLCD_Dot(34, 10);
}

void twinkle_display(void) {
	for(int i = 24; i < 27; i++) {
		GLCD_Dot(i, 11);
	}
	for(int i = 30; i < 33; i++) {
		GLCD_Dot(i, 11);
	}
	for(int j = 7; j < 10; j++) {
		GLCD_Dot(28, j);
	}
	for(int j = 13; j < 16; j++) {
		GLCD_Dot(28, j);
	}
	GLCD_Dot(27, 10); GLCD_Dot(27, 12);
	GLCD_Dot(29, 10); GLCD_Dot(29, 12);
	
	for(int i = 49; i < 52; i++) {
		GLCD_Dot(i, 7);
	}
	for(int i = 55; i < 58; i++) {
		GLCD_Dot(i, 7);
	}
	for(int j = 3; j < 6; j++) {
		GLCD_Dot(53, j);
	}
	for(int j = 9; j < 12; j++) {
		GLCD_Dot(53, j);
	}
	GLCD_Dot(52, 6); GLCD_Dot(52, 8);
	GLCD_Dot(54, 6); GLCD_Dot(54, 8);
	
	for(int i = 41; i < 44; i++) {
		GLCD_Dot(i, 53);
	}
	for(int i = 47; i < 50; i++) {
		GLCD_Dot(i, 53);
	}
	for(int j = 49; j < 52; j++) {
		GLCD_Dot(28, j);
	}
	for(int j = 55; j < 58; j++) {
		GLCD_Dot(28, j);
	}
	GLCD_Dot(44, 52); GLCD_Dot(44, 54);
	GLCD_Dot(48, 52); GLCD_Dot(48, 54);
}