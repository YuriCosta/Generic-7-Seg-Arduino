/*************************************************************
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
*************************************************************/

#define ANODE 1
#define CATHODE 0
#define ON 1
#define OFF 0

int table[2][16][7] =
    {
        {
            {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW },
            {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},
            {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH },
            {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH },
            {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH },
            {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH },
            {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH },
            {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW },
            {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH },
            {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH },
            {HIGH, HIGH, HIGH, LOW, HIGH, HIGH, HIGH },
            {LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH },
            {HIGH, LOW, LOW, HIGH, HIGH, HIGH, LOW },
            {LOW, HIGH, HIGH, HIGH, HIGH, LOW, HIGH },
            {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH },
            {HIGH, LOW, LOW, LOW, HIGH, HIGH, HIGH }
        },
        {
            {LOW, LOW, LOW, LOW, LOW, LOW, HIGH,},
            {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH },
            {LOW, LOW, HIGH, LOW, LOW, HIGH, LOW},
            {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW },
            {HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW },
            {LOW, HIGH, LOW, LOW, HIGH, LOW, LOW },
            {LOW, HIGH, LOW, LOW, LOW, LOW, LOW },
            {LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH },
            {LOW, LOW, LOW, LOW, LOW, LOW, LOW },
            {LOW, LOW, LOW, LOW, HIGH, LOW, LOW },
            {LOW, LOW, LOW, HIGH, LOW, LOW, LOW },
            {HIGH, HIGH, LOW, LOW, LOW, LOW, LOW },
            {LOW, HIGH, HIGH, LOW, LOW, LOW, HIGH },
            {HIGH, LOW, LOW, LOW, LOW, HIGH, LOW },
            {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW },
            {LOW, HIGH, HIGH, HIGH, LOW, LOW, LOW }
        }
    };

class S_Seg
{
protected:

    int mode;

private:

	int* led;

public:
    ////led[9] = { a, b, c, d, e, f, g, (dot), (Vcc or GND) };
    S_Seg (int* _led, int _mode)
    {
        mode = _mode;
        led = _led;
        
        int i;
        for(i = 0; i < 9; i++)
        {
            pinMode( led[ i ], OUTPUT);
        }
    }
    
    S_Seg(){}

    void hex_to_7seg(int hex )
    {
        int i ;
        for(i = 0; i <7; i++)
        {
            digitalWrite( led[ i ], table[mode][hex][ i ] );
        }
    }

    void turn(int on_off)
    {
        if(on_off == ON )
        {
            if(mode == ANODE)
            {
                digitalWrite(led[8], HIGH);
            }
            else
            {
                digitalWrite(led[8], LOW);
            }
        }
        else
        {
            if(mode == ANODE)
            {
                digitalWrite(led[8], LOW);
            }
            else
            {
                digitalWrite(led[8], HIGH);
            }
        }
    }

};