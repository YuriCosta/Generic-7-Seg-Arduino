/*************************************************************
Exemple of implementation of the class, fully tested on arduino uno rev3
0 to 7 are the pins that will be used as LED and 8 & 9 will be used as VCC of 2 different
	7-segment LEDs. In this exemple 1 to 7 will be used as font of information to 2 different LEDs,
	so modifying the state of 1 LED will change the state of the other one.
*************************************************************/

#include "7seg_duplo_main.h"
#include "S_Seg.h"

int led1[9] =
    {
        0, 1, 2, 3, 4, 5, 6, 7, 8
    };
    
    int led2[9] =
    {
        0, 1, 2, 3, 4, 5, 6, 7, 9
    };

S_Seg * L1, *L2;

void setup() {                	

	L1 = new S_Seg( led1, ANODE);
	L2 = new S_Seg( led2, ANODE);
	
	L1->turn(ON);
	L2->turn(ON);
	
}

void loop() {

	for(int i = 0; i<16; i++)
	{
		L1-> hex_to_7seg(i);
		delay(1000);
	}
}
