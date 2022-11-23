
#include <stdio.h>
#include "type.h"

typedef U4 Register;

Register PC = 1;
Register R1 = 0;
Register R2 = 0;
Register R3 = 0;
Register R4 = 0;
Register R5 = 0;
Register IR = 0;
Register ACC = 0;
Register *Table[] = {&PC,&R1,&R2,&R3,&R4,&R5,&IR,&ACC};

extern U4 RAM[256];
extern U4 ROM[256];

/*R1,2,3の読み出しマクロ*/
#define ReadRegister(i) ( R5 & (1<<i)>>1 ? *Table[ (R ## i) & 0x07 ] : ( R4 & (1<<i)>>1 ? RAM : ROM ) [  (R ## i) & 0xFF ] )

void cpu(void)
{
    do
    {
        /*fetch*/
        IR = ROM[PC++];
        printf("  feach:PC=%u,\tIR=%x\n",PC-1,IR);

        /*decode*/
        R5 =   IR >> 27 & 0x07 ; /* rf*/
        R4 =   IR >> 24 & 0x07 ; /* mf*/
        R3 =   IR >> 16 & 0xFF ; /* t */
        R2 =   IR >>  8 & 0xFF ; /*op2*/
        R1 =   IR       & 0xFF ; /*op1*/
        IR =   IR >> 30 & 3 ;    /* i */
        printf(" decode:op1=%x,\top2=%x,\tt=%x,\tmf=%x,\trf=%x,\ti=%x\n",R1,R2,R3,R4,R5,IR);

        /*execute*/
        if( R3 ? !ReadRegister(3) : 1 )
        {
            switch ( IR )
            {
            case 0:/* MOV */
                if( R5 & 0x01 )
                {
                    *Table[ R1 & 0x07 ] = ReadRegister(2);
                    break;
                }

                if( R4 & 0x01 )
                {
                    RAM[ R1 & 0xFF ] = ReadRegister(2);
                    break;
                }         
                /*ここまで到達した場合、ROMへの書き込みを行っている*/
                //printf("-- ERROR:Writing of ROM --\n");
                printf("execute: << exit >>\n");
                return;
            case 1:/* ADD */
                ACC  = ReadRegister(1); /*R1*/
                ACC += ReadRegister(2); /*R2*/
                break;

            case 2:/* AND */
                ACC  = ReadRegister(1); /*R1*/
                ACC &= ReadRegister(2); /*R2*/
                break;

            case 3:/* CMP */
                ACC  = ReadRegister(1); /*R1*/
                ACC -= ReadRegister(2); /*R2*/
                break;
            }
        }
        printf("execute:ACC=%u\n",ACC);
        
        /*デバッグ*/
        printf("----------------------------------------------------------\n");
        printf(" PC : %08x  |  RAM[0] : %08x |  ROM[0] : %08x\n",PC,RAM[0],ROM[0]);
        printf(" R1 : %08x  |  RAM[1] : %08x |  ROM[1] : %08x\n",R1,RAM[1],ROM[1]);
        printf(" R2 : %08x  |  RAM[2] : %08x |  ROM[2] : %08x\n",R2,RAM[2],ROM[2]);
        printf(" R3 : %08x  |  RAM[3] : %08x |  ROM[3] : %08x\n",R3,RAM[3],ROM[3]);
        printf(" R4 : %08x  |  RAM[4] : %08x |  ROM[4] : %08x\n",R4,RAM[4],ROM[4]);
        printf(" R5 : %08x  |  RAM[5] : %08x |  ROM[5] : %08x\n",R5,RAM[5],ROM[5]);
        printf(" IR : %08x  |  RAM[6] : %08x |  ROM[6] : %08x\n",IR,RAM[6],ROM[6]);
        printf(" ACC: %08x  |  RAM[7] : %08x |  ROM[7] : %08x\n",ACC,RAM[7],ROM[7]);
        getchar();
    }while( PC );
}
