//--------------------------------------------------
// file   | Connected.h
// date   | 2021/11/07
// anthor | syalpon
//--------------------------------------------------
#ifndef _CONNECTED_H_
#define _CONNECTED_H_

#define PIN_NUM (7)

//--------------------------------------------------
//Include Files
//--------------------------------------------------
#include "Object.h"
#include "Destination.h"
#include "Type.h"

//--------------------------------------------------
class Connected : public Object
{
protected :
    Destination destinationIn[PIN_NUM];
    Destination destinationOut[PIN_NUM];
    
public : 
    Connected();
    virtual VD InputVoltageTriger(Destination *);
    virtual VD ConnectTriger(Destination *);
};


#endif