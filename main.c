#include <stdio.h>
#include "type.h"

/*命令*/
/* 0 : halt *//* 実行停止 */
/* 1 : nand *//* nand(a) := NAND(ACC,a) */
/* 2 : move *//* move(a)  := *a ← ACC */
/* 3 : add  *//* add(a)  := ACC += a */
#define OP_HALT (U1)0x00
#define OP_NAND (U1)0x40
#define OP_MOVE (U1)0x80
#define OP_ADD  (U1)0xC0


/*---------------------------------------------------------*/
typedef struct _St_Instruct_
{
    U1 operand     : 6 ; 
    U1 instruction : 2 ;
}St_Instruct;

typedef union 
{
    U1 ir;
    St_Instruct instruct;
}Instruct;


/*メモリ*/ /*4+8を0x30へ格納*/ 
U1 memory[256] = {
    OP_ADD | 0x04, OP_ADD | 0x08, OP_MOVE | 0x30, 
};


U1 Fetch(U1 *pc)
{
    return memory[(*pc)++];
}

U1 Decoder(U1 ir)
{
    return ir;
}

U1 AddressCalculation(U1 op)
{
    /*即値アドレス指定*/
    return ( op & 0X3F );
}

U1 Read(U1 op)
{
    return AddressCalculation(op);
}

void Execution(U1 ir, U1 op,U1 *acc)
{
    /*デコード*/
    switch( ir )
    {
        case OP_HALT :
            break; 
        case OP_NAND :
            *acc = !( (*acc) & op );
            break;
        case OP_MOVE :
            memory[op] = *acc;
            break;
        case OP_ADD  :
            *acc += op;
            break;
        default:
            break;
    }
}

int main(void)
{
    U1 PC = 0;              /*プログラムカウンタ：次実行する命令が入っているアドレスを指す*/
    U1 IR = 0;              /*命令レジスタ：プログラムカウンタが指していたアドレス先の命令を受け取るバッファ。命令とオペランドが格納される*/
    U1 ACC = 0;

    do
    {
        IR = Fetch(&PC);
        Execution(Decoder(IR&0XC0),Read(IR&0x3F),&ACC);

        printf("PC:%d\tIR:%x\tGR:%x\tACC:%x\t%d\n\n>>",PC,IR,GR,ACC,memory[0x30]);
        getchar();
    }while( PC );

    return 0;
}