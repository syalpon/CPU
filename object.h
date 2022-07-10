#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "type.h"

class Object
{
public:
    U4 object_number;       
    S1 *object_name;     
    Object();               /*コンストラクタ*/
    Object(S1 *);           /*コンストラクタ(名前付き)*/
};

#endif