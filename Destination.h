//--------------------------------------------------
// file   | Destination.h
// date   | 2021/11/07
// anthor | syalpon
//--------------------------------------------------
#ifndef _DESTINATION_H_
#define _DESTINATION_H_
//--------------------------------------------------
//Include Files
//--------------------------------------------------
#include "Object.h"
#include "Type.h"

//--------------------------------------------------
class Destination
{
public :
    Object *address;   // init:NULL
    U1      channel;   // Connecter:0 , Connected:1~7
    U1      direction; // 0:unknown , 1:in , 2:out
};

#endif
