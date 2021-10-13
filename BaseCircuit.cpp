#include <stdio.h>

//-----------------------------------------------------------------------
//二次元ベクトル(bool)
typedef struct Vector2dim_T
{
    bool h;
    bool l;
}Vector2;

//-----------------------------------------------------------------------
//ゲート回路クラス
class Gate
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
bool Gate::Relay(bool mlt, bool in1)
{
    return mlt ? false : in1 ;
}


//NAND回路
// in1  in2 |!in1  in2 |  and  | out
//  0    0  |  1    0  |   0   |  1 
//  0    1  |  1    1  |   0   |  1
//  1    0  |  0    0  |   0   |  1
//  1    1  |  0    1  |   1   |  0
bool Gate::Nand(bool in1 , bool in2)
{
    bool not_in1 = Relay(in1,true);
    bool and_in1_in2 = Relay(not_in1,in2);
    return Relay(and_in1_in2,true);
}

//NOT回路
// in1 | out
//  0  |  1 
//  1  |  0
bool Gate::Not(bool in1)
{
    return Nand(in1,in1);
}


//AND回路
// in1  in2 | out
//  0    0  |  0 
//  0    1  |  0
//  1    0  |  0
//  1    1  |  1
bool Gate::And(bool in1 , bool in2)
{
    return Not(Nand(in1,in2));
}

//OR回路
// in1  in2 | out
//  0    0  |  0 
//  0    1  |  1
//  1    0  |  1
//  1    1  |  1
bool Gate::Or(bool in1 , bool in2)
{
    bool temp1 = Nand(in1,in1);
    bool temp2 = Nand(in2,in2);
    return Nand(temp1,temp2);
}

//XOR回路
// in1  in2 | out
//  0    0  |  0 
//  0    1  |  1
//  1    0  |  1
//  1    1  |  0
bool Gate::Xor(bool in1 , bool in2)
{
    bool temp0 = Nand(in1,in2);
    bool temp1 = Nand(temp0,in1);
    bool temp2 = Nand(temp0,in2);
    return Nand(temp1,temp2);
}

//-----------------------------------------------------------------------
//算術クラス
class Arithmetics : public virtual Gate
{
public :
    Vector2 HalfAdder(bool , bool);
    Vector2 FullAdder(bool , bool , bool);
};

//半加算回路(繰り上がり無視)
// in1  in2 | outh outl
//  0    0  |  0    0
//  0    1  |  0    1
//  1    0  |  0    1
//  1    1  |  1    0
Vector2 Arithmetics::HalfAdder(bool in1 , bool in2)
{
    Vector2 vector2;
    vector2.h = And(in1,in2);
    vector2.l = Xor(in1,in2);
    return vector2;
}

//全加算回路(繰り上がりあり)
// in1  in2   p  |  outh outl
//  0    0    0  |   0    0
//  0    1    0  |   0    1
//  1    0    0  |   0    1
//  1    1    0  |   1    0
//  0    0    1  |   0    1
//  0    1    1  |   1    0
//  1    0    1  |   1    0
//  1    1    1  |   1    1
Vector2 Arithmetics::FullAdder(bool in1 , bool in2 , bool p)
{
    Vector2 vector2_1 = HalfAdder(in1,in2);
    Vector2 vector2_2 = HalfAdder(vector2_1.l , p);
    Vector2 vector2;
    vector2.h = Or(vector2_1.h , vector2_2.h);
    vector2.l = vector2_2.l;
    return vector2;
}

//-----------------------------------------------------------------------
class Plumbing : public virtual Gate
{
public :
    bool Selector(bool , bool , bool);
    Vector2 Switch(bool , bool);
};

//セレクタ(s=0のときin2を返す)
//  s   in1  in2 |  out
//  0    0    0  |   0 
//  0    1    0  |   0 
//  0    0    1  |   1 
//  0    1    1  |   1 
//  1    0    0  |   0 
//  1    0    1  |   0 
//  1    1    0  |   1 
//  1    1    1  |   1 
bool Plumbing::Selector(bool s , bool in1 , bool in2)
{
    bool b1 = And(s,in1);
    bool b2 = Not(s);
    bool b3 = And(b2,in2);
    return    Or(b1,b3);
}

//スイッチ(s=0のときlへ、s=1のときhへdを出力する)
//  s   d  |  h   l
//  0   0  |  0   0
//  0   1  |  0   1
//  1   0  |  0   0
//  1   1  |  1   0
Vector2 Plumbing::Switch(bool s , bool d)
{
    Vector2 vector2;
    bool ns   = Not(s);
    vector2.h = And(s,d);
    vector2.l = And(ns,d);
    return vector2;
}

//-----------------------------------------------------------------------
//記憶回路クラス
class Memory : public Plumbing , public Arithmetics
{
public :
    bool Latch(bool , bool);
    bool DataFlipFlop(bool , bool , bool);
    Vector2 Register(bool , Vector2 , bool);
};

//ラッチ回路
bool Memory::Latch(bool s, bool d1)
{
    static bool d0 = false;
    d0 = Selector(s , d1 , d0);
    return d0;
}

//DFF回路
bool Memory::DataFlipFlop(bool st , bool d , bool cl )
{
    bool a1 = And(st,cl);
    bool a2 = And(st,Not(cl));
    bool lt = Latch(a2,d);
    return Latch(a1,lt);
}

//レジスタ
Vector2 Memory::Register(bool st, Vector2 vc, bool cl)
{
    Vector2 vector2;
    vector2.h = DataFlipFlop(st,vc.h,cl);
    vector2.l = DataFlipFlop(st,vc.l,cl);
    return vector2;
}

//-----------------------------------------------------------------------
int main(void)
{
    Gate base;
    bool (Gate::* func)(bool,bool) = &Gate::Or;
    printf(" in1 in2 out \n");
    printf("  0   0   %d  \n", (base.*func)(false,false));
    printf("  0   1   %d  \n", (base.*func)(false,true ));
    printf("  1   0   %d  \n", (base.*func)(true ,false));
    printf("  1   1   %d  \n", (base.*func)(true ,true ));
    return 0;
}