Class: S_Seg.h
Exemple: 7seg_duplo_main.h

author: <Yuri Costa>
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
