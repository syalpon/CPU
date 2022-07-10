#ifndef _CONNECTER_H_
#define _CONNECTER_H_

#include <list>
#include "object.h"
#include "type.h"

/*コネクタクラス*/
class Connecter : Object
{
public :
    Connecter();

protected:
    virtual std:list<Object *> DistinationAddressList(2);     /*接続先のアドレス*/
    virtual std:list<float >   DistinationVoltageList(2);     /*接続先の電位*/
    virtual U4 length;         /*長さ*/
    virtual F4 Resistance;     /*抵抗値*/
    virtual U1 Direction;      /*有向情報 : 0=絶縁,1=small->big,2=small<-big,3=small<->big*/
};


#endif