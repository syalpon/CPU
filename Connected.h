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
#define DESTINATION_MAX     ((U1)15)
#define DESTINATION_MIN     ((U1)1)
#define IS_WELL_DEFINED(x)  ((DESTINATION_MIN<=x)&&(x<=DESTINATION_MAX))

class Connected : public Object
{
protected :
    Destination *destination;
    
public : 
    Connected();
    Connected(U1);
    ~Connected();
    virtual VD InputVoltageTriger(Destination *);
    virtual VD ConnectTriger(Destination *);

    VD Setdestination(Destination *,U1);
};


#endif
