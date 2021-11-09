//--------------------------------------------------
// file   | Connected.cpp
// date   | 2021/11/07
// anthor | syalpon
//--------------------------------------------------
//Include Files
//--------------------------------------------------
#include "Connected.h"

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
Connected::Connected() : Connected(1)
{

}

Connected::Connected(U1 destinationNum)
{
    destination = new Destination[destinationNum];
    for(int i=0;i<7;i++)
    {
        destinationIn[i].address = nullptr;
        destinationIn[i].channel = 0;
        destinationIn[i].direction = DIRECTION_INIT;
        destinationOut[i].address = nullptr;
        destinationOut[i].channel = 0;
        destinationOut[i].direction = DIRECTION_INIT;
    }
    Rename("Connected");
}

//-----------------
//入力電圧変化時に呼び出されるメソッド
//-----------------
VD Connected::InputVoltageTriger(Destination *destination)
{
    // No Process
}

//-----------------
//接続時に呼び出されるメソッド
//-----------------
VD Connected::ConnectTriger(Destination *destination)
{

}

//-----------------
//ゲッター
//-----------------
VD Connected::Setdestination(Destination *destination,U1 channel)
{
    if( destination->address != nullptr )
    {
        //TODO:Destation一本化
        if(channel > 7)
        {
            destinationOut[channel-7] = *destination;
        }
        else
        {
            destinationIn[channel] = *destination;
        }
    }    
}

//-----------------
//デストラクタ
//-----------------
Connected::~Connected()
{
    delete destination;
}