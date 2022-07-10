#ifndef _NAND_H_
#define _NAND_H_

#include <vector>
#include "connecter.h"

/*---------概要図--------*/
/*       _________       */
/*     -|0       7|-     */
/*     -|1       8|-     */
/*     -|2       9|-     */
/*     -|3      10|-     */
/*     -|4      11|-     */
/*     -|5      12|-     */
/*     -|6______13|-     */
/*                       */
/*-----------------------*/

/*------ピンアサイン------*/
/* 0:VCC  12V電源入力端子 */
/* 1:NAND1 IN1           */
/* 2:NAND1 IN2           */
/* 3:NAND1 OUT           */
/* 4:NAND2 IN1           */
/* 5:NAND2 IN2           */
/* 6:NAND2 OUT           */
/* 7:NAND3 IN1           */
/* 8:NAND3 IN2           */
/* 9:NAND3 OUT           */
/*10:NAND4 IN1           */
/*11:NAND4 IN2           */
/*12:NAND4 OUT           */
/*13:GND グランド出力端子 */
/*-----------------------*/

/*概要*/
/*このICはNAND回路を４つ内包している。*/
/*各NANDは二つの入力(High:5V,Low:5V)に対し、NANDの結果(High:5V,Low:0V)を出力する。*/
/*VCC-GNDピン間に12V-0Vの電位があれば5Vと0Vを出力する。*/
/*VCC-GNDピン間が0Vから12V未満のxV場合、x/12とした値が出力される。*/
/*各入力は3Vを超えているとHigh,2V未満の場合Lowとして扱い、High-Z状態の場合はラッチアップする(クラッシュ)。*/



/*Nandクラス*/
/*二つのダイオード、１つのトランジスタ、二つの抵抗から生成*/
class Nand{
    /**/
}

/*NandICクラス*/
class NandIC{
public:
    Connecter Pin[14];          /*ピン*/
    std::vector<Nand> Nand(4);  /*内包するNand回路*/
    NandIC();                   /*コンストラクタ*/

private:

};

/*公開関数*/


#endif