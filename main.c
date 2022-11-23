#include <stdio.h>
#include "type.h"

/*����*/
/* 0 : halt *//* ���s��~ */
/* 1 : nand *//* nand(a) := NAND(ACC,a) */
/* 2 : move *//* move(a)  := *a �� ACC */
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


/*������*/ /*4+8��0x30�֊i�[*/ 
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
    /*���l�A�h���X�w��*/
    return ( op & 0X3F );
}

U1 Read(U1 op)
{
    return AddressCalculation(op);
}

void Execution(U1 ir, U1 op,U1 *acc)
{
    /*�f�R�[�h*/
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
    U1 PC = 0;              /*�v���O�����J�E���^�F�����s���閽�߂������Ă���A�h���X���w��*/
    U1 IR = 0;              /*���߃��W�X�^�F�v���O�����J�E���^���w���Ă����A�h���X��̖��߂��󂯎��o�b�t�@�B���߂ƃI�y�����h���i�[�����*/
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