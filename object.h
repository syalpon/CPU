#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "type.h"

class Object
{
public:
    U4 object_number;       
    S1 *object_name;     
    Object();               /*�R���X�g���N�^*/
    Object(S1 *);           /*�R���X�g���N�^(���O�t��)*/
};

#endif