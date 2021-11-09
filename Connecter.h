//--------------------------------------------------
// file   | Connecter.h
// date   | 2021/11/07
// anthor | syalpon
//--------------------------------------------------
#ifndef _CONNECTER_H_
#define _CONNECTER_H_
//--------------------------------------------------
//Include Files
//--------------------------------------------------
#include "Object.h"
#include "Destination.h"
#include "Type.h"

//--------------------------------------------------
class Connected;
class Connecter : public Object
{
protected :
    Destination destination1;
    Destination destination2;    
    U4          length;

public :
    Connecter();
    VD Connect(Connected * ,U1 , DIRECTION );
    BO SetDestination(Destination *);

    // Setter
    VD SetDestination1(Destination *);
    VD SetDestination2(Destination *);
    VD SetLength(U4 );
    VD SetVoltage(F4 ); //override

    // getter
    Destination* GetDestination1();
    Destination* GetDestination2();
    U4 GetLength();
};


#endif
