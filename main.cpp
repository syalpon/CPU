#include <cstdio>
#include "nand.h"

int main(void)
{
    /*インスタンス化*/
    NandIC NandIC = new NandIC();

    /* NAND-IC と電源、GNDの接続 */
    
    /* NAND-IC の動作確認 */
    printf("a",NandIC.Pin[0].GetVoltage());

    return 0;
}