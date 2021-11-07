//--------------------------------------------------
// file   | Connecter.cpp
// date   | 2021/11/07
// anthor | syalpon
//--------------------------------------------------
//Include Files
//--------------------------------------------------
#include "Connecter.h"
#include "Connected.h"
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
Connecter::Connecter()
{
    destination1 = {nullptr,0,0};
    destination2 = {nullptr,0,0};
    length       = 0;

    Rename("Connecter");
}

//-----------------
//接続
//-----------------
VD Connecter::Connect(Connected *connected,U1 channel, U1 direction)
{
    bool isConnected;
    Destination temp1 = {connected,channel,direction};
    Destination temp2 = {this,0,direction};

    //接続
    isConnected = SetDestination(&temp1);
    if( true == isConnected )
    {
        connected->ConnectTriger(&temp2);
    }
}

BO Connecter::SetDestination(Destination *destination)
{
    BO ret = false;
    // 1  2 |   result
    // -  - | o - |   t 
    // x  - | x o |   t
    // -  x | o x |   t
    // x  x | x x |   f
    if( nullptr == destination1.address )
    {
        SetDestination1(destination);
        ret = true;
    }
    else
    if( nullptr == destination2.address )
    {
        SetDestination2(destination);
        ret = true;
    }
    else
    {
        printf("Connect Error : In SetDestination of Connecter Class\n");
    }
    return ret;
}

//-----------------
//セッター
//-----------------
VD Connecter::SetDestination1(Destination *destination)
{
    destination1 = *destination;
}

VD Connecter::SetDestination2(Destination *destination)
{
    destination2 = *destination;
}

VD Connecter::SetLength(U4 l)
{
    length = l;
}

VD Connecter::SetVoltage(F4 v)
{  
    if( voltage != v )
    {
        //接続トリガの呼び出し
        if( nullptr != destination1.address && destination1.direction == 2 )
        {
            ((Connected *)destination1.address)->InputVoltageTriger(&destination1);
        }

        if( nullptr != destination2.address && destination2.direction == 2  )
        {
            ((Connected *)destination2.address)->InputVoltageTriger(&destination2);
        }

        voltage = v;
    }
}

//-----------------
//ゲッター
//-----------------
Destination* Connecter::GetDestination1()
{
    return &destination1;
}

Destination* Connecter::GetDestination2()
{
    return &destination2;
}

U4 Connecter::GetLength()
{
    return length;
}