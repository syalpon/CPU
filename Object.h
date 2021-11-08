//--------------------------------------------------
// file   | object.h
// date   | 2021/11/07
// anthor | syalpon
//--------------------------------------------------
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Type.h"

#define OBJECT_NAME_MAX (32)
#define OBJECT_NUM_MAX  (32)

class Object
{
protected : 
    U4 id;                     //オブジェクト番号
    C1 name[OBJECT_NAME_MAX];  //オブジェクト名
    F4 voltage;                //電圧

public :
    //コンストラクタ
    Object();

    //名前の変更
    VD Rename(const C1 *str);

    //電荷ゲッターセッター
    virtual F4 GetVoltage();
    virtual VD SetVoltage(F4);

    //idのゲッター
    virtual U4 GetId();
    virtual C1 *GetName();
};

#endif