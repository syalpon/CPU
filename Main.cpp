//--------------------------------------------------
// file   | Main.cpp
// date   | 2021/11/07
// anthor | syalpon
//--------------------------------------------------
//Include Files
//--------------------------------------------------
#include "Main.h"
#include "Nand.h"
#include "Power.h"
#include "Connecter.h"

//--------------------------------------------------
//Global variables
//--------------------------------------------------

//--------------------------------------------------
//Local variables
//--------------------------------------------------

//--------------------------------------------------
//Functions
//--------------------------------------------------
int main( void )
{
    Power P5V    = Power(5.0);
    Power GND    = Power();
    Nand nand    = Nand();
    Connecter c1 = Connecter();
    Connecter c2 = Connecter();
    Connecter c3 = Connecter();

    // [P5V( 1)] --[c2]-- | (2)            |
    //                    |     [NAND] (7) | --[c1]--
    // [GND(14)] --[c3]-- | (3)            |
    c1.Connect(&nand,7,2);
    c2.Connect(&nand,2,1);
    c3.Connect(&nand,3,1);
    c2.Connect(&P5V ,1,1);
    c3.Connect(&GND ,14,1);

    printf("c1:%fv\n",c1.GetVoltage());
    printf("c2:%fv\n",c2.GetVoltage());
    printf("c3:%fv\n",c3.GetVoltage());
    return 0;
}