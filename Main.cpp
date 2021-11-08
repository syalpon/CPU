//--------------------------------------------------
// file   | Main.cpp
// date   | 2021/11/07
// anthor | syalpon
//--------------------------------------------------
//Include Files
//--------------------------------------------------
#include "Main.h"
#include "Nand.h"
#include "Power.h"
#include "Connecter.h"

//--------------------------------------------------
//Global variables
//--------------------------------------------------
extern U4 object_id;
extern C1 object_name[OBJECT_NUM_MAX][OBJECT_NAME_MAX];
extern VD *object_addr[OBJECT_NUM_MAX];

//--------------------------------------------------
//Local variables
//--------------------------------------------------

//--------------------------------------------------
//Functions
//--------------------------------------------------
int main( void )
{
    //オブジェクト生成
    Power P5V    = Power(5.0);
    Power GND    = Power();
    Nand nand    = Nand();
    Connecter c1 = Connecter();
    Connecter c2 = Connecter();
    Connecter c3 = Connecter();

    // [P5V( 1)] --[c2]-- | (2)            |
    //                    |     [NAND] (7) | --[c1]--
    // [GND(14)] --[c3]-- | (3)            |

    //接続
    c1.Connect(&nand,7,2);
    c2.Connect(&nand,2,1);
    c3.Connect(&nand,3,1);
    c2.Connect(&P5V ,1,1);
    c3.Connect(&GND ,14,1);



    //memo
    printf("\n");
    printf("  [PW5V] --(c5)-- |      |          \n");
    printf("                  | NAND | --(c4)-- \n");
    printf("  [PW0V] --(c6)-- |      |          \n");
    printf("\n");
    //デバッグ：全オブジェクト一覧表示
    printf("--------------------------------------------\n");
    printf("Id |  アドレス  |  オブジェクト名  | 電圧   \n");
    printf("--------------------------------------------\n");
    for(int i = 1 ; i <= object_id ; i++ )
    {
        printf("%2d | 0x%8p | %16s | %.2fV\n",
            i,
            object_addr[i],
            object_name[i],
            ((Object *)object_addr[i])->GetVoltage()
        );
    }
    printf("--------------------------------------------\n");
    

    return 0;
}