#include "APP_ReadTemperature.h"

rom unsigned int T16bit[TABLE_LEN] = {0x653E,0x65E4,0x668A,0x6730,0x67D6,0x687C,0x6923,0x69C9,0x6A70,0x6B17,0x6BBD,0x6C64,0x6D0B,0x6DB1,0x6E58,0x6EFF,0x6FA6,0x704C,0x70F3,0x719A,
                                      0x7241,0x72E7,0x738E,0x7434,0x74DB,0x7581,0x7628,0x76CE,0x7774,0x781A,0x78C0,0x7966,0x7A0C,0x7AB2,0x7B57,0x7BFD,0x7CA2,0x7D47,0x7DEC,0x7E91,
                                      0x7F36,0x7FDA,0x807E,0x8123,0x81C6,0x826A,0x830E,0x83B1,0x8454,0x84F7,0x859A,0x863D,0x86DF,0x8781,0x8823,0x88C5,0x8966,0x8A07,0x8AA8,0x8B49,
                                      0x8BE9,0x8C89,0x8D29,0x8DC8,0x8E68,0x8F07,0x8FA5,0x9044,0x90E2,0x9180,0x921D,0x92BB,0x9358,0x93F4,0x9491,0x952D,0x95C8,0x9664,0x96FF,0x979A,
                                      0x9834,0x98CE,0x9968,0x9A01,0x9A9A,0x9B33,0x9BCB,0x9C63,0x9CFB,0x9D92,0x9E29,0x9EC0,0x9F56,0x9FEC,0xA082,0xA117,0xA1AC,0xA240,0xA2D4,0xA368,
                                      0xA3FB,0xA48E,0xA521,0xA5B3,0xA645,0xA6D6,0xA767,0xA7F8,0xA888,0xA918,0xA9A7,0xAA36,0xAAC5,0xAB53,0xABE1,0xAC6F,0xACFC,0xAD89,0xAE15,0xAEA1,
                                      0xAF2C,0xAFB8,0xB042,0xB0CC,0xB156,0xB1DE,0xB266,0xB2ED,0xB373,0xB3F8,0xB47C,0xB4FF,0xB580,0xB601,0xB680,0xB6FD,0xB779,0xB7F3,0xB86C,0xB8E3,
                                      0xB959,0xB9CD,0xBA3F,0xBAAF,0xBB1D,0xBB89,0xBBF4,0xBC5C,0xBCC2,0xBD26,0xBD88,0xBDE8,0xBE45,0xBEA0,0xBEF9,0xBF4F,0xBFA3,0xBFF5,0xC044,0xC090};

char TEMP1 = 0;
char TEMP2 = 0;
char TEMP3 = 0;
char TEMP4 = 0;

signed int TdC(unsigned int tp_temp)    //Temperatura iz LOOK-up tabele
{
    signed int temp = -20;
    unsigned char cnt =1;
//    tp_temp = tp_temp >> 4;
    while ((T16bit[cnt] < tp_temp)&&(cnt < TABLE_LEN))
    {
        cnt++;
        temp++;
    }

    if (temp > -20)
    {
        temp = temp *10 +((tp_temp -T16bit[cnt -1])*10)/(T16bit[cnt] -T16bit[cnt -1]);
    }    
    else
    {
        temp = -999;
    }    
    return(temp);
}

