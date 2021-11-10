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

#define PIN(x)          ((U4)x)         //ピン番号
#define CONNECTER       ((U4)0)         //コネクタのチャンネル(0固定)
#define ADDRESS_INIT    (nullptr)       //アドレス初期値
#define CHANNEL_INIT    ((U1)0xFF)      //チャンネルの初期値

//方向定義
typedef enum DIRECTION_T
{
    DIRECTION_INIT, //DIRECTION初期値
    DIRECTION_IN,   //入力
    DIRECTION_OUT,  //出力
    DIRECTION_BOTH, //入出力
}DIRECTION ;

//接続情報
class Destination
{
public :
    Object      *address;  // init:NULL
    U1          channel;   // Connecter:0 , Connected:1~14
    DIRECTION   direction; // Difinition DICRECTION Enum
};

#endif
