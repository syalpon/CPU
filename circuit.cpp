#include <cstdio>
#include <cstring>
#define OBJECT_NUM_MAX (256)
#define DIRECTION_IN  (true)
#define DIRECTION_OUT (false)

//-------------------
//内部グローバル変数
//-------------------
static int   object_id = 0;
static char  object_name[OBJECT_NUM_MAX][32];
static void *object_addr[OBJECT_NUM_MAX];

//-------------------
//オブジェクトクラス
//-------------------
class Object
{
protected : 
    int id;
    char name[32];
    virtual float voltage;

public :
    //コンストラクタ
    Object() : voltage(0.0)
    {
        object_id++;
        id = object_id;
        if( id < OBJECT_NUM_MAX )
        {
            this->Rename("Object");
            object_addr[id] = this;
        }
    }

    //名前の変更
    void Rename(const char *str)
    {
        strcpy(object_name[id],str);
        strcpy(name,str);
    }

    //状態表示
    void ShowId()
    {
        printf("ID:%d\n",id);
    }

    void ShowName()
    {
        printf("Name:%s\n",name);
    }

    void ShowVoltage()
    {
        printf("Voltage:%fV\n",voltage);
    }

    //電荷ゲッターセッター
    virtual float GetVoltage(){return voltage;}
    virtual void  SetVoltage(float v){voltage = v;}
};



//-------------------
//宛先クラス
//-------------------
class Destination 
{
public :
    Object *addr;       //接続先アドレス
    int  channel;       //接続先の番号(0 to 7)
    bool direction;     //false:out  true:in

    //コンストラクタ
    Destination() : 
        addr(nullptr) ,
        channel(0),
        direction(false)
    {

    }

    void SetAttrbute(Object *a,int c,bool d)
    {
        this->addr      = a;
        this->channel   = c;
        this->direction = d;
    }

    void OverWrite(Destination *renew)
    {
        this->SetAttrbute(
            renew->addr,
            renew->channel,
            renew->direction
        );
    }
};



//-------------------
//電源クラス
//-------------------
class Power : public Object
{

public :
    //コンストラクタ
    Power()
    {
        Power(0.0);
    }

    Power(float v)
    {
        this->voltage = v;
        Object::Rename("POWER");
    }

};



//-------------------
//コネクタクラス
//-------------------
class Connecter : public Object
{
private :
    unsigned int length;    // 長さ
    Destination destination1;   // 接続先1
    Destination destination2;   // 接続先2

public :
    //コンストラクタ
    Connecter() :
        length(120)  
    {
        destination1 = Destination();
        destination2 = Destination();
        Object::Rename("Connecter");
    }

    // ゲッターセッター
    void SetVoltage(float v); //Gateクラス参照の為、外定義
    unsigned int GetLength(){return length;}
    void SetLength(unsigned int l){length = l;}
    Destination *GetDestination1(){return &destination1;}
    void SetDestination1(Destination *d){destination1.OverWrite(d);}
    void SetDestination1(Object *a,int c,bool d)
    {
        //TODO:ここで繋がった際に電圧を変異させる

        //繋げる
        destination1.SetAttrbute(a,c,d);
        //TODO:aをGateへキャストして双方向繋げる
    }

    Destination *GetDestination2(){return &destination2;}
    void SetDestination2(Destination *d){destination2.OverWrite(d);}
    void SetDestination2(Object *a,int c,bool d){destination2.SetAttrbute(a,c,d);}
};



//-------------------
//ゲート抽象クラス
//-------------------
class Gate : public Object
{
private :
    Destination in[8];  //入力系接続先
    Destination out[8];  //出力系接続先

protected :
    //入出力系ゲッターセッター
    float GetVoltage(int index);          //Connecerクラス参照の為、外定義
    void  SetVoltage(float v,int index);  //Connecerクラス参照の為、外定義

public : 
    //コンストラクタ
    Gate()
    {
        Object::Rename("Gate");
    }

    //入力電圧が変異した際のトリガ
    virtual void InputVoltageTriger(float v) = 0;

    //接続ゲッターセッター
    void ConnectToInput(Destination *c ,int index){in[index].OverWrite(c);}
    Destination *GetInputConnecter(int index){return &in[index];}
    void ConnectToOutput(Destination *c ,int index){out[index].OverWrite(c);}
    Destination *GetOutputConnecter(int index){return &out[index];}
};



//-------------------
//NANDクラス
// pin 0 : [VCC]     | pout : [VCC]
// pin 1 : NAND1_in1 | pout : NAND1_out
// pin 2 : NAND1_in2 | pout : GPIO
// pin 3 : GPIO      | pout : GPIO
// pin 4 : GPIO      | pout : GPIO
// pin 5 : GPIO      | pout : GPIO
// pin 6 : GPIO      | pout : GPIO
// pin 7 : [GND]     | pout : [GND]
//-------------------
class Nand : public Gate
{
private :

public :
    //コンストラクタ
    Nand()
    {
        Object::Rename("NAND");
    }

    //トリガによる処理のオーバーライド
    void InputVoltageTriger(float v)
    {
        float in1;
        float in2;
        in1 = Gate::GetVoltage(1);
        in2 = Gate::GetVoltage(2);

        if( in1 >= 5.0 && in2 >= 5.0 )
        {
            Gate::SetVoltage(0.0,1);
        }
        else
        {
            Gate::SetVoltage(5.0,1);
        }
    }
};



//-------------------
//相互参照の為の外定義
//-------------------
void  Connecter::SetVoltage(float v)
{
    voltage = v;

    //電圧が変わった時、GateのINに繋がっているならトリガを出す
    //更新順番は長さに依存するので長さをディレイとして渡す:TODO
    if( destination1.addr != nullptr && destination1.direction == DIRECTION_IN )
    {
        ((Gate *)(destination1.addr))->InputVoltageTriger(v);
    }
    if( destination2.addr != nullptr && destination2.direction == DIRECTION_IN )
    {
        ((Gate *)(destination2.addr))->InputVoltageTriger(v);
    }
}

float Gate::GetVoltage(int index)
{
    float ret = 0.0;
    if( in[index].addr != nullptr )
    {
        ret = ((Connecter *)(in[index].addr))->GetVoltage() ;
    }
    return ret;
}

void Gate::SetVoltage(float v,int index)
{
    if( out[index].addr != nullptr )
    {
        ((Connecter *)(out[index].addr))->SetVoltage(v);
    }
}


//-------------------
//main
//-------------------
int main()
{
    //物体の定義
    Power GND(0.0);
    Power power5V(5.0);
    Nand nand ;
    Connecter connecter0;
    Connecter connecter1;
    Connecter connecter2;

    //結線
    // [ 5V] --(0)-- | 1        |
    //               |   NAND 1 | --(2)--
    // [GND] --(1)-- | 2        |
    connecter0.SetDestination1(&power5V,0,DIRECTION_OUT);
    connecter0.SetDestination2(&nand,1,DIRECTION_IN);
    printf("out0:%fV\n",connecter0.GetVoltage());

    connecter1.SetDestination1(&GND,0,DIRECTION_OUT);
    connecter1.SetDestination2(&nand,2,DIRECTION_IN);
    printf("out1:%fV\n",connecter1.GetVoltage());

    connecter2.SetDestination1(&nand,0,DIRECTION_OUT);
    connecter2.SetDestination2(nullptr,0,DIRECTION_OUT);
    printf("out2:%fV\n",connecter2.GetVoltage());


    return 0;
}