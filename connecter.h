#ifndef _CONNECTER_H_
#define _CONNECTER_H_

#include <list>
#include "object.h"
#include "type.h"

/*�R�l�N�^�N���X*/
class Connecter : Object
{
public :
    Connecter();

protected:
    virtual std:list<Object *> DistinationAddressList(2);     /*�ڑ���̃A�h���X*/
    virtual std:list<float >   DistinationVoltageList(2);     /*�ڑ���̓d��*/
    virtual U4 length;         /*����*/
    virtual F4 Resistance;     /*��R�l*/
    virtual U1 Direction;      /*�L����� : 0=�≏,1=small->big,2=small<-big,3=small<->big*/
};


#endif