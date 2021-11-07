//--------------------------------------------------
// file   | Power.h
// date   | 2021/11/07
// anthor | syalpon
//--------------------------------------------------
#ifndef _POWER_H_
#define _POWER_H_
//--------------------------------------------------
//Include Files
//--------------------------------------------------
#include "Connected.h"
#include "Type.h"
//--------------------------------------------------
class Power : public Connected
{
public :
    Power();
    Power(F4);
    VD ConnectTriger(Destination *); //override
};



#endif
