<<<<<<< HEAD
Class: S_Seg.h
Exemple: 7seg_duplo_main.h

author: <Yuri Costa (yurioor@hotmail.com)>
description: <Simple 7-segment LED object>

ports = { a, b, c, d, e, f, g, (dot), (Vcc or GND) };
type = ANODE;// = CATHODE;
S_Seg mS_Seg = new S_Seg(int* ports, type);

create your LED 7-segment and turn it on.
mS_Seg->turn(ON); //turn off with OFF argument

Change it's displaying value
mS_Seg->hex_to_7seg(16); //15, 14, 13... 0

Dot modifier function not implemented yet.

Be aware: DO NOT: DON'T, send a pointer as argument with less than 9 ints, because pointers.
=======
author: <Yuri Costa (yurioor@hotmail.com)>
description:
Provides internal interruptions at desired frequency
	
Use like this:
		
	Timer_Interruption_Provider *mTimer_Interruption_Provider;
	mTimer_Interruption_Provider = new Timer_Interruption_Provider();
	mTimer_Interruption_Provider->set_timer( double frequency, int timer );
		
	Where	 0.23828125 < frequency  < 8000000 if you are using timer1 [set_timer( frequency, 1 );]
               61.275390625 < frequency  < 8000000 if you are using timer0 or 2 [set_timer( frequency, 1//2 );]
		
Check out the exemple to see how implement this class.

Tested with sucess in Arduino uno rev3
>>>>>>> 66ccfdaff078acfc445627d47279af8a01c087be
