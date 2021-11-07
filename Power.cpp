//--------------------------------------------------
// file   | Power.cpp
// date   | 2021/11/07
// anthor | syalpon
//--------------------------------------------------
//Include Files
//--------------------------------------------------
#include "Power.h"

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
Power::Power()
{
    Rename("Power");
}

Power::Power(F4 v)
{
    voltage = v;
    Power();
}


//-----------------
//接続時、電荷を与える
//-----------------
VD Power::ConnectTriger(Destination *destination)
{ 
    destination->address->SetVoltage(voltage);
}