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

#define PIN(x) ((U4)x)
#define CONNECTER ((U4)0)


typedef enum DIRECTION_T
{
    DIRECTION_INIT, //初期値
    DIRECTION_IN,   //入力
    DIRECTION_OUT,  //出力
    DIRECTION_BOTH, //入出力
}DIRECTION ;

class Destination
{
public :
    Object      *address;  // init:NULL
    U1          channel;   // Connecter:0 , Connected:1~7
    DIRECTION   direction; // Difinition DICRECTION Enum
};

#endif
