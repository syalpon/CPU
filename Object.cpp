//--------------------------------------------------
// file   | object.cpp
// date   | 2021/11/07
// anthor | syalpon
//--------------------------------------------------
//Include Files
//--------------------------------------------------
#include "Object.h"
#include <cstring>
#include <cstdio>

//--------------------------------------------------
//Global variables
//--------------------------------------------------
U4 object_id;
C1 object_name[OBJECT_NUM_MAX][OBJECT_NAME_MAX];
VD *object_addr[OBJECT_NUM_MAX];

//--------------------------------------------------
//Local variables
//--------------------------------------------------


//--------------------------------------------------
//Functions
//--------------------------------------------------
//-----------------
//コンストラクタ
//-----------------
Object::Object()
{
    object_id++;
    id = object_id;
    object_addr[id] = this;
    if( id < OBJECT_NUM_MAX )
    {
        Rename("Object");
    }
}

//-----------------
//名前の変更
//-----------------
VD Object::Rename(const C1 *str)
{
    strcpy(object_name[id],str);
    strcpy(name,str);
}

//-----------------
//表示
//-----------------
VD Object::ShowId()
{
    printf("ID:%d\n",id);
}

VD Object::ShowName()
{
    printf("Name:%s\n",name);
}

VD Object::ShowVoltage()
{
    printf("Voltage:%fV\n",voltage);
}

VD Object::ShowStatus()
{
    ShowId();
    ShowName();
    ShowVoltage();
}

//-----------------
//セッターゲッター
//-----------------
F4 Object::GetVoltage()
{
    return voltage;
}

VD Object::SetVoltage(F4 v)
{
    voltage = v;
}