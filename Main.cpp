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
#include "Destination.h"

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
static VD DebugDisplay();
static VD DebugSettingShow();

int main( void )
{
    //オブジェクト生成
    Connecter c1 = Connecter();
    Connecter c2 = Connecter();
    Connecter c3 = Connecter();
    Connecter c4 = Connecter();
    Connecter c5 = Connecter();
    Power P12V   = Power(12.0);
    Power P5V    = Power(5.0);
    Power P0V    = Power(0.0);
    Power GND    = Power();
    Nand nand    = Nand();

    //接続
    c1.Connect(&nand,  PIN( 1), DIRECTION_IN);  //NANDとVCCへのコネクタ
    c2.Connect(&nand,  PIN( 2), DIRECTION_IN);  //NANDと5Vへのコネクタ
    c3.Connect(&nand,  PIN( 3), DIRECTION_IN);  //NANDと0Vへのコネクタ
    c4.Connect(&nand,  PIN( 4), DIRECTION_OUT); //NANDとOUTPUTへのコネクタ
    c5.Connect(&nand,  PIN(14), DIRECTION_OUT); //NANDとGNDへのコネクタ

    c1.Connect(&P12V,  PIN( 1), DIRECTION_OUT);  //NANDからのコネクタとVCC
    c5.Connect(&GND,   PIN( 1), DIRECTION_IN );  //NANDからのコネクタとGND
    c4.Connect(nullptr,      0, DIRECTION_IN );  //NANDからのコネクタとOUTPUTへのコネクタ
    c3.Connect(&P0V,   PIN( 1), DIRECTION_OUT);  //NANDからのコネクタと0Vへのコネクタ 
    c2.Connect(&P5V,   PIN( 1), DIRECTION_OUT);  //NANDからのコネクタと5Vへのコネクタ

    //デバッグ：全オブジェクト一覧表示
    DebugDisplay();

    // 全体図表示
    DebugSettingShow();

    c3.SetVoltage(5.0);

    //デバッグ：全オブジェクト一覧表示
    DebugDisplay();

    return 0;
}



static VD DebugDisplay()
{
    //デバッグ：全オブジェクト一覧表示
    printf("--------------------------------------------\n");
    printf("Id |  アドレス  |  オブジェクト名  | 電圧    \n");
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
}

static VD DebugSettingShow()
{
    printf("\n");
    printf("                   -------------               \n");
    printf("  [PW12V] --(c1)-- + 1      8  +               \n");
    printf("  [PW 5V] --(c2)-- + 2      9  +               \n");
    printf("  [PW 0V] --(c3)-- + 3      10 +               \n");
    printf("  ( OUT ) --(c4)-- + 4 NAND 11 +               \n");
    printf("                   + 5      12 +               \n");
    printf("                   + 6      13 +               \n");
    printf("                   + 7      14 + --(c5)-- [GND]\n");
    printf("                   -------------               \n");
    printf("\n");

}