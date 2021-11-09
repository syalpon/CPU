//--------------------------------------------------
// file   | Nand.cpp
// date   | 2021/11/07
// anthor | syalpon
//--------------------------------------------------
//Include Files
//--------------------------------------------------
#include "Nand.h"
#include "Connecter.h"
#include "Destination.h"

#include <cstdio>

//--------------------------------------------------
//Global variables
//--------------------------------------------------

//--------------------------------------------------
//Local variables
//--------------------------------------------------

//--------------------------------------------------
//Functions
//--------------------------------------------------
//-----------------
//コンストラクタ
//-----------------
Nand::Nand()
{
    Rename("NAND");
}

//-----------------
//NAND出力
//-----------------
VD Nand::InputVoltageTriger(Destination *destination)
{
    BO result = true;
    //              0  1  2  3  4  5  6  7  8  9  10  11  12  13  14
    U1 Partner[] = {0, 0 ,3 ,2 ,0 ,6 ,5 ,0, 9, 8, 0 , 12, 11, 0 , 0 }; //入力１に対する入力２、入力２に対する入力１の添え字番号を返す。
    U1 InToOut[] = {0, 0 ,4 ,4 ,0 ,7 ,7 ,0,10,10, 0 , 13, 13, 0 , 0 }; //入力１，２に対して出力となる添え字番号を返す。
    U1 ch1 = destination->channel; 
    U1 ch2 = Partner[ch1];
    U1 cho = InToOut[ch1];
    //入力と出力のコネクタ取得
    if( cho != 0)
    {
        Connecter *c1 = (Connecter *)destinationIn[ch1].address;
        Connecter *c2 = (Connecter *)destinationIn[ch2].address;
        Connecter *co = (Connecter *)destinationOut[cho].address;
            printf("%d,%d,%d\n",ch1,ch2,cho);
            printf("%p,%p,%p\n",c1,c2,co);       
        if(  c1 != nullptr && c2 != nullptr && co != nullptr )
        {
            //NAND計算した結果を返す
            if( c1->GetVoltage() > 4.5 && c2->GetVoltage() > 4.5 )
            {
                result = false;
            }

            voltage = result == false ? 0.0 : 5.0; 
            if( nullptr != co )
            {
                co->SetVoltage(result);
            }
            else
            {
                //出力エラー
            }
        }
        else
        {
            //入力しているが、もう片方の入力もしくは出力が繋がってない状態
        }
    }
}
