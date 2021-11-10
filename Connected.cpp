//--------------------------------------------------
// file   | Connected.cpp
// date   | 2021/11/07
// anthor | syalpon
//--------------------------------------------------
//Include Files
//--------------------------------------------------
#include "Connected.h"
#include <stdio.h>

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
Connected::Connected() : Connected(DESTINATION_MIN)
{
    //DO NOTHING
}

Connected::Connected(U1 destinationNum)
{
    //インスタンス化時に接続先情報の数を増やせるようにする。
    if( IS_WELL_DEFINED(destinationNum) )
    {
        destination = new Destination[destinationNum];
        for( int i = 0 ; i < destinationNum ; i++ )
        {
            destination[i].address   = ADDRESS_INIT;
            destination[i].channel   = CHANNEL_INIT;
            destination[i].direction = DIRECTION_INIT;
        }
    }
    else
    {
        //数が範囲外の入力の際はエラーMSG表示
        printf("ERROR : channel = %d IS DESTINATION OVER IN CONNECTED CONSTRUCTOR\n",destinationNum);
    }

    Rename("Connected");
}

//-----------------
//コネクタオブジェクトの電圧変化時に呼び出されるメソッド(入力ポートのみ)
//-----------------
VD Connected::InputVoltageTriger(Destination *destination)
{
    //DO NOTHING
}

//-----------------
//コネクタオブジェクトと接続時に呼び出されるメソッド
//-----------------
VD Connected::ConnectTriger(Destination *destination)
{
    //DO NOTHING
}

//-----------------
//ゲッター
//-----------------
VD Connected::Setdestination(Destination *dest,U1 channel)
{
    if( dest->address != nullptr )
    {
        if( IS_WELL_DEFINED(channel) )
        {
            destination[channel] = *dest;    
        }
        else
        {
            //数が範囲外の入力の際はエラーMSG表示
            printf("ERROR : channel = %d IS DESTINATION OVER IN CONNECTED Setdestination\n",channel);            
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