#ifndef _NAND_H_
#define _NAND_H_

#include <vector>
#include "connecter.h"

/*---------�T�v�}--------*/
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

/*------�s���A�T�C��------*/
/* 0:VCC  12V�d�����͒[�q */
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
/*13:GND �O�����h�o�͒[�q */
/*-----------------------*/

/*�T�v*/
/*����IC��NAND��H���S����Ă���B*/
/*�eNAND�͓�̓���(High:5V,Low:5V)�ɑ΂��ANAND�̌���(High:5V,Low:0V)���o�͂���B*/
/*VCC-GND�s���Ԃ�12V-0V�̓d�ʂ������5V��0V���o�͂���B*/
/*VCC-GND�s���Ԃ�0V����12V������xV�ꍇ�Ax/12�Ƃ����l���o�͂����B*/
/*�e���͂�3V�𒴂��Ă����High,2V�����̏ꍇLow�Ƃ��Ĉ����AHigh-Z��Ԃ̏ꍇ�̓��b�`�A�b�v����(�N���b�V��)�B*/



/*Nand�N���X*/
/*��̃_�C�I�[�h�A�P�̃g�����W�X�^�A��̒�R���琶��*/
class Nand{
    /**/
}

/*NandIC�N���X*/
class NandIC{
public:
    Connecter Pin[14];          /*�s��*/
    std::vector<Nand> Nand(4);  /*�����Nand��H*/
    NandIC();                   /*�R���X�g���N�^*/

private:

};

/*���J�֐�*/


#endif