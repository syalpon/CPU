//--------------------------------------------------
// file   | Nand.h
// date   | 2021/11/07
// anthor | syalpon
//--------------------------------------------------
#ifndef _NAND_H_
#define _NAND_H_
//--------------------------------------------------
//Include Files
//--------------------------------------------------
#include "Connected.h"
#include "Type.h"
//--------------------------------------------------
//  1  : VCC       |  8 : NAND3_IN1
//  2  : NAND1_IN1 |  9 : NAND3_IN2
//  3  : NAND1_IN2 | 10 : NAND3_OUT
//  4  : NAND1_OUT | 11 : NAND4_IN1
//  5  : NAND2_IN1 | 12 : NAND4_IN2
//  6  : NAND2_IN2 | 13 : NAND4_OUT
//  7  : NAND2_OUT | 14 : GND
class Nand : public Connected
{
public :
    Nand();
    VD InputVoltageTriger(Destination *destination); //override
};

#endif
