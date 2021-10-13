#include <stdio.h>
class BaseCircuit
{
public :
    bool Relay(bool , bool);
    bool Nand(bool , bool);
    bool Not(bool);
    bool And(bool , bool);
    bool Or(bool , bool);
    bool Xor(bool , bool);
};

//Relay回路(default = on)
// mlt  in1  out  | すなわち
//  0    0    0   | mlt=0 ⇒ Relay=0 
//  0    1    1   | mlt=1 ⇒ Relay=in1
//  1    0    0   | in1=0 ⇒ Relay=0
//  1    1    0   | in1=1 ⇒ Relay=!mlt
bool BaseCircuit::Relay(bool mlt, bool in1)
{
    return mlt ? false : in1 ;
}


//NAND回路
// in1  in2 |!in1  in2 |  and  | out
//  0    0  |  1    0  |   0   |  1 
//  0    1  |  1    1  |   0   |  1
//  1    0  |  0    0  |   0   |  1
//  1    1  |  0    1  |   1   |  0
bool BaseCircuit::Nand(bool in1 , bool in2)
{
    bool not_in1 = Relay(in1,true);
    bool and_in1_in2 = Relay(not_in1,in2);
    return Relay(and_in1_in2,true);
}

//NOT回路
// in1  out
//  0    1 
//  1    0
bool BaseCircuit::Not(bool in1)
{
    return Nand(in1,in1);
}


//AND回路
// in1  in2  out
//  0    0    0 
//  0    1    0
//  1    0    0
//  1    1    1
bool BaseCircuit::And(bool in1 , bool in2)
{
    return Not(Nand(in1,in2));
}

//OR回路
// in1  in2  out
//  0    0    0 
//  0    1    1
//  1    0    1
//  1    1    1
bool BaseCircuit::Or(bool in1 , bool in2)
{
    bool temp1 = Nand(in1,in1);
    bool temp2 = Nand(in2,in2);
    return Nand(temp1,temp2);
}

//XOR回路
// in1  in2  out
//  0    0    0 
//  0    1    1
//  1    0    1
//  1    1    0
bool BaseCircuit::Xor(bool in1 , bool in2)
{
    bool temp0 = Nand(in1,in2);
    bool temp1 = Nand(temp0,in1);
    bool temp2 = Nand(temp0,in2);
    return Nand(temp1,temp2);
}



int main(void)
{
    BaseCircuit base;
    bool (BaseCircuit::* func)(bool,bool) = &BaseCircuit::Or;
    printf(" in1 in2 out \n");
    printf("  0   0   %d  \n", (base.*func)(false,false));
    printf("  0   1   %d  \n", (base.*func)(false,true ));
    printf("  1   0   %d  \n", (base.*func)(true ,false));
    printf("  1   1   %d  \n", (base.*func)(true ,true ));
    return 0;
}