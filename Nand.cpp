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
    U1 Partner[] = {0, 14,3 ,2 ,0 ,6 ,5 ,0, 9, 8, 0 , 12, 11, 0 , 1 }; //入力１に対する入力２、入力２に対する入力１の添え字番号を返す。
    U1 InToOut[] = {0, 0 ,4 ,4 ,0 ,7 ,7 ,0,10,10, 0 , 13, 13, 0 , 0 }; //入力１，２に対して出力となる添え字番号を返す。
    U1 ch1 = destination->channel; 
    U1 ch2 = Partner[ch1];
    U1 cho = InToOut[ch1];
    Connecter *c1 = (Connecter *)destinationIn[ch1].address;
    Connecter *c2 = (Connecter *)destinationIn[ch2].address;
    Connecter *co = (Connecter *)destinationIn[cho].address;
    printf("%p\n",destination);
    printf("%p,%p,%p\n",c1,c2,co);
    
    F4 v1 = c1->GetVoltage();
    F4 v2 = c2->GetVoltage();
    if( v1 > 4.5 && v2 > 4.5 )
    {
        result = false;
    }

    if( nullptr != co )
    {
        co->SetVoltage(result);
    }
}
