#include <cstdio>
#include "nand.h"

int main(void)
{
    /*�C���X�^���X��*/
    NandIC NandIC = new NandIC();

    /* NAND-IC �Ɠd���AGND�̐ڑ� */
    
    /* NAND-IC �̓���m�F */
    printf("a",NandIC.Pin[0].GetVoltage());

    return 0;
}