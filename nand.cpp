#include "nand.h"

/*コンストラクタ*/
NandIC::NandIC()
{
    Pin[0] = Connecter();
    Pin[1] = Connecter();
}