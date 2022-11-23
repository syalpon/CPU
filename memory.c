#include "type.h"

/* idx   28  24  20  16  12   8   4   0 */
/* 0b  00000000000000000000000000000000 */
/* 0x     0   0   0   0   0   0   0   0 */
/* ------------------------------------ */
/* [i:2][rf:3][mf:3][t:8][op2:8][op1:8] */

/*�I�t�Z�b�g*/
#define OF_IR  30
#define OF_RF  27
#define OF_MF  24
#define OF_T   16
#define OF_OP2 8
#define OF_OP1 0
#define Fmt(i,rf,mf,t,op2,op1) ( i<<OF_IR | rf<<OF_RF | mf<<OF_MF | t<<OF_T | op2<<OF_OP2 | op1<<OF_OP1 )
/*����*/
#define IR_MOV 0
#define IR_ADD 1
#define IR_AND 2
#define IR_CMP 3

/*���W�X�^���ʔԍ�*/
#define NUM_PC  0
#define NUM_R1  1
#define NUM_R2  2
#define NUM_R3  3
#define NUM_R4  4
#define NUM_R5  5
#define NUM_IR  6
#define NUM_ACC 7

/*�v���O����*/ /*34(=*0xF0[R0M])+67(=*0xF1[R0M])���s���B���ʂ�RAM[0]�Ɋi�[*/
U4 ROM[256] = {
/*0x00*/ 0,
/*0x01*/ Fmt(IR_ADD , 0, 0, 0,   0xF1,   0xF0) , /* ADD(ROM[0xF1],ROM[0xF0]) */
/*0x02*/ Fmt(IR_MOV , 2, 1, 0,NUM_ACC,   0x00) , /* MOV(RAM[0],ACC) */
/*0x03*/ 0,
/*0x04*/ 0,
/*0x05*/ 0,
/*0x06*/ 0,
/*0x07*/ 0,
/*0x08*/ 0,
/*0x09*/ 0,
/*0x0A*/ 0,
/*0x0B*/ 0,
/*0x0C*/ 0,
/*0x0D*/ 0,
/*0x0E*/ 0,
/*0x0F*/ 0,
/*0x10*/ 0,
/*0x11*/ 0,
/*0x12*/ 0,
/*0x13*/ 0,
/*0x14*/ 0,
/*0x15*/ 0,
/*0x16*/ 0,
/*0x17*/ 0,
/*0x18*/ 0,
/*0x19*/ 0,
/*0x1A*/ 0,
/*0x1B*/ 0,
/*0x1C*/ 0,
/*0x1D*/ 0,
/*0x1E*/ 0,
/*0x1F*/ 0,
/*0x20*/ 0,
/*0x21*/ 0,
/*0x22*/ 0,
/*0x23*/ 0,
/*0x24*/ 0,
/*0x25*/ 0,
/*0x26*/ 0,
/*0x27*/ 0,
/*0x28*/ 0,
/*0x29*/ 0,
/*0x2A*/ 0,
/*0x2B*/ 0,
/*0x2C*/ 0,
/*0x2D*/ 0,
/*0x2E*/ 0,
/*0x2F*/ 0,
/*0x30*/ 0,
/*0x31*/ 0,
/*0x32*/ 0,
/*0x33*/ 0,
/*0x34*/ 0,
/*0x35*/ 0,
/*0x36*/ 0,
/*0x37*/ 0,
/*0x38*/ 0,
/*0x39*/ 0,
/*0x3A*/ 0,
/*0x3B*/ 0,
/*0x3C*/ 0,
/*0x3D*/ 0,
/*0x3E*/ 0,
/*0x3F*/ 0,
/*0x40*/ 0,
/*0x41*/ 0,
/*0x42*/ 0,
/*0x43*/ 0,
/*0x44*/ 0,
/*0x45*/ 0,
/*0x46*/ 0,
/*0x47*/ 0,
/*0x48*/ 0,
/*0x49*/ 0,
/*0x4A*/ 0,
/*0x4B*/ 0,
/*0x4C*/ 0,
/*0x4D*/ 0,
/*0x4E*/ 0,
/*0x4F*/ 0,
/*0x50*/ 0,
/*0x51*/ 0,
/*0x52*/ 0,
/*0x53*/ 0,
/*0x54*/ 0,
/*0x55*/ 0,
/*0x56*/ 0,
/*0x57*/ 0,
/*0x58*/ 0,
/*0x59*/ 0,
/*0x5A*/ 0,
/*0x5B*/ 0,
/*0x5C*/ 0,
/*0x5D*/ 0,
/*0x5E*/ 0,
/*0x5F*/ 0,
/*0x60*/ 0,
/*0x61*/ 0,
/*0x62*/ 0,
/*0x63*/ 0,
/*0x64*/ 0,
/*0x65*/ 0,
/*0x66*/ 0,
/*0x67*/ 0,
/*0x68*/ 0,
/*0x69*/ 0,
/*0x6A*/ 0,
/*0x6B*/ 0,
/*0x6C*/ 0,
/*0x6D*/ 0,
/*0x6E*/ 0,
/*0x6F*/ 0,
/*0x70*/ 0,
/*0x71*/ 0,
/*0x72*/ 0,
/*0x73*/ 0,
/*0x74*/ 0,
/*0x75*/ 0,
/*0x76*/ 0,
/*0x77*/ 0,
/*0x78*/ 0,
/*0x79*/ 0,
/*0x7A*/ 0,
/*0x7B*/ 0,
/*0x7C*/ 0,
/*0x7D*/ 0,
/*0x7E*/ 0,
/*0x7F*/ 0,
/*0x80*/ 0,
/*0x81*/ 0,
/*0x82*/ 0,
/*0x83*/ 0,
/*0x84*/ 0,
/*0x85*/ 0,
/*0x86*/ 0,
/*0x87*/ 0,
/*0x88*/ 0,
/*0x89*/ 0,
/*0x8A*/ 0,
/*0x8B*/ 0,
/*0x8C*/ 0,
/*0x8D*/ 0,
/*0x8E*/ 0,
/*0x8F*/ 0,
/*0x90*/ 0,
/*0x91*/ 0,
/*0x92*/ 0,
/*0x93*/ 0,
/*0x94*/ 0,
/*0x95*/ 0,
/*0x96*/ 0,
/*0x97*/ 0,
/*0x98*/ 0,
/*0x99*/ 0,
/*0x9A*/ 0,
/*0x9B*/ 0,
/*0x9C*/ 0,
/*0x9D*/ 0,
/*0x9E*/ 0,
/*0x9F*/ 0,
/*0xA0*/ 0,
/*0xA1*/ 0,
/*0xA2*/ 0,
/*0xA3*/ 0,
/*0xA4*/ 0,
/*0xA5*/ 0,
/*0xA6*/ 0,
/*0xA7*/ 0,
/*0xA8*/ 0,
/*0xA9*/ 0,
/*0xAA*/ 0,
/*0xAB*/ 0,
/*0xAC*/ 0,
/*0xAD*/ 0,
/*0xAE*/ 0,
/*0xAF*/ 0,
/*0xB0*/ 0,
/*0xB1*/ 0,
/*0xB2*/ 0,
/*0xB3*/ 0,
/*0xB4*/ 0,
/*0xB5*/ 0,
/*0xB6*/ 0,
/*0xB7*/ 0,
/*0xB8*/ 0,
/*0xB9*/ 0,
/*0xBA*/ 0,
/*0xBB*/ 0,
/*0xBC*/ 0,
/*0xBD*/ 0,
/*0xBE*/ 0,
/*0xBF*/ 0,
/*0xC0*/ 0,
/*0xC1*/ 0,
/*0xC2*/ 0,
/*0xC3*/ 0,
/*0xC4*/ 0,
/*0xC5*/ 0,
/*0xC6*/ 0,
/*0xC7*/ 0,
/*0xC8*/ 0,
/*0xC9*/ 0,
/*0xCA*/ 0,
/*0xCB*/ 0,
/*0xCC*/ 0,
/*0xCD*/ 0,
/*0xCE*/ 0,
/*0xCF*/ 0,
/*0xD0*/ 0,
/*0xD1*/ 0,
/*0xD2*/ 0,
/*0xD3*/ 0,
/*0xD4*/ 0,
/*0xD5*/ 0,
/*0xD6*/ 0,
/*0xD7*/ 0,
/*0xD8*/ 0,
/*0xD9*/ 0,
/*0xDA*/ 0,
/*0xDB*/ 0,
/*0xDC*/ 0,
/*0xDD*/ 0,
/*0xDE*/ 0,
/*0xDF*/ 0,
/*0xE0*/ 0,
/*0xE1*/ 0,
/*0xE2*/ 0,
/*0xE3*/ 0,
/*0xE4*/ 0,
/*0xE5*/ 0,
/*0xE6*/ 0,
/*0xE7*/ 0,
/*0xE8*/ 0,
/*0xE9*/ 0,
/*0xEA*/ 0,
/*0xEB*/ 0,
/*0xEC*/ 0,
/*0xED*/ 0,
/*0xEE*/ 0,
/*0xEF*/ 0,
/*0xF0*/ 34,
/*0xF1*/ 67,
/*0xF2*/ 0,
/*0xF3*/ 0,
/*0xF4*/ 0,
/*0xF5*/ 0,
/*0xF6*/ 0,
/*0xF7*/ 0,
/*0xF8*/ 0,
/*0xF9*/ 0,
/*0xFA*/ 0,
/*0xFB*/ 0,
/*0xFC*/ 0,
/*0xFD*/ 0,
/*0xFE*/ 0,
/*0xFF*/ 0
};








U4 RAM[256] = {
/*0x00*/ 0,
/*0x01*/ 0,
/*0x02*/ 0,
/*0x03*/ 0,
/*0x04*/ 0,
/*0x05*/ 0,
/*0x06*/ 0,
/*0x07*/ 0,
/*0x08*/ 0,
/*0x09*/ 0,
/*0x0A*/ 0,
/*0x0B*/ 0,
/*0x0C*/ 0,
/*0x0D*/ 0,
/*0x0E*/ 0,
/*0x0F*/ 0,
/*0x10*/ 0,
/*0x11*/ 0,
/*0x12*/ 0,
/*0x13*/ 0,
/*0x14*/ 0,
/*0x15*/ 0,
/*0x16*/ 0,
/*0x17*/ 0,
/*0x18*/ 0,
/*0x19*/ 0,
/*0x1A*/ 0,
/*0x1B*/ 0,
/*0x1C*/ 0,
/*0x1D*/ 0,
/*0x1E*/ 0,
/*0x1F*/ 0,
/*0x20*/ 0,
/*0x21*/ 0,
/*0x22*/ 0,
/*0x23*/ 0,
/*0x24*/ 0,
/*0x25*/ 0,
/*0x26*/ 0,
/*0x27*/ 0,
/*0x28*/ 0,
/*0x29*/ 0,
/*0x2A*/ 0,
/*0x2B*/ 0,
/*0x2C*/ 0,
/*0x2D*/ 0,
/*0x2E*/ 0,
/*0x2F*/ 0,
/*0x30*/ 0,
/*0x31*/ 0,
/*0x32*/ 0,
/*0x33*/ 0,
/*0x34*/ 0,
/*0x35*/ 0,
/*0x36*/ 0,
/*0x37*/ 0,
/*0x38*/ 0,
/*0x39*/ 0,
/*0x3A*/ 0,
/*0x3B*/ 0,
/*0x3C*/ 0,
/*0x3D*/ 0,
/*0x3E*/ 0,
/*0x3F*/ 0,
/*0x40*/ 0,
/*0x41*/ 0,
/*0x42*/ 0,
/*0x43*/ 0,
/*0x44*/ 0,
/*0x45*/ 0,
/*0x46*/ 0,
/*0x47*/ 0,
/*0x48*/ 0,
/*0x49*/ 0,
/*0x4A*/ 0,
/*0x4B*/ 0,
/*0x4C*/ 0,
/*0x4D*/ 0,
/*0x4E*/ 0,
/*0x4F*/ 0,
/*0x50*/ 0,
/*0x51*/ 0,
/*0x52*/ 0,
/*0x53*/ 0,
/*0x54*/ 0,
/*0x55*/ 0,
/*0x56*/ 0,
/*0x57*/ 0,
/*0x58*/ 0,
/*0x59*/ 0,
/*0x5A*/ 0,
/*0x5B*/ 0,
/*0x5C*/ 0,
/*0x5D*/ 0,
/*0x5E*/ 0,
/*0x5F*/ 0,
/*0x60*/ 0,
/*0x61*/ 0,
/*0x62*/ 0,
/*0x63*/ 0,
/*0x64*/ 0,
/*0x65*/ 0,
/*0x66*/ 0,
/*0x67*/ 0,
/*0x68*/ 0,
/*0x69*/ 0,
/*0x6A*/ 0,
/*0x6B*/ 0,
/*0x6C*/ 0,
/*0x6D*/ 0,
/*0x6E*/ 0,
/*0x6F*/ 0,
/*0x70*/ 0,
/*0x71*/ 0,
/*0x72*/ 0,
/*0x73*/ 0,
/*0x74*/ 0,
/*0x75*/ 0,
/*0x76*/ 0,
/*0x77*/ 0,
/*0x78*/ 0,
/*0x79*/ 0,
/*0x7A*/ 0,
/*0x7B*/ 0,
/*0x7C*/ 0,
/*0x7D*/ 0,
/*0x7E*/ 0,
/*0x7F*/ 0,
/*0x80*/ 0,
/*0x81*/ 0,
/*0x82*/ 0,
/*0x83*/ 0,
/*0x84*/ 0,
/*0x85*/ 0,
/*0x86*/ 0,
/*0x87*/ 0,
/*0x88*/ 0,
/*0x89*/ 0,
/*0x8A*/ 0,
/*0x8B*/ 0,
/*0x8C*/ 0,
/*0x8D*/ 0,
/*0x8E*/ 0,
/*0x8F*/ 0,
/*0x90*/ 0,
/*0x91*/ 0,
/*0x92*/ 0,
/*0x93*/ 0,
/*0x94*/ 0,
/*0x95*/ 0,
/*0x96*/ 0,
/*0x97*/ 0,
/*0x98*/ 0,
/*0x99*/ 0,
/*0x9A*/ 0,
/*0x9B*/ 0,
/*0x9C*/ 0,
/*0x9D*/ 0,
/*0x9E*/ 0,
/*0x9F*/ 0,
/*0xA0*/ 0,
/*0xA1*/ 0,
/*0xA2*/ 0,
/*0xA3*/ 0,
/*0xA4*/ 0,
/*0xA5*/ 0,
/*0xA6*/ 0,
/*0xA7*/ 0,
/*0xA8*/ 0,
/*0xA9*/ 0,
/*0xAA*/ 0,
/*0xAB*/ 0,
/*0xAC*/ 0,
/*0xAD*/ 0,
/*0xAE*/ 0,
/*0xAF*/ 0,
/*0xB0*/ 0,
/*0xB1*/ 0,
/*0xB2*/ 0,
/*0xB3*/ 0,
/*0xB4*/ 0,
/*0xB5*/ 0,
/*0xB6*/ 0,
/*0xB7*/ 0,
/*0xB8*/ 0,
/*0xB9*/ 0,
/*0xBA*/ 0,
/*0xBB*/ 0,
/*0xBC*/ 0,
/*0xBD*/ 0,
/*0xBE*/ 0,
/*0xBF*/ 0,
/*0xC0*/ 0,
/*0xC1*/ 0,
/*0xC2*/ 0,
/*0xC3*/ 0,
/*0xC4*/ 0,
/*0xC5*/ 0,
/*0xC6*/ 0,
/*0xC7*/ 0,
/*0xC8*/ 0,
/*0xC9*/ 0,
/*0xCA*/ 0,
/*0xCB*/ 0,
/*0xCC*/ 0,
/*0xCD*/ 0,
/*0xCE*/ 0,
/*0xCF*/ 0,
/*0xD0*/ 0,
/*0xD1*/ 0,
/*0xD2*/ 0,
/*0xD3*/ 0,
/*0xD4*/ 0,
/*0xD5*/ 0,
/*0xD6*/ 0,
/*0xD7*/ 0,
/*0xD8*/ 0,
/*0xD9*/ 0,
/*0xDA*/ 0,
/*0xDB*/ 0,
/*0xDC*/ 0,
/*0xDD*/ 0,
/*0xDE*/ 0,
/*0xDF*/ 0,
/*0xE0*/ 0,
/*0xE1*/ 0,
/*0xE2*/ 0,
/*0xE3*/ 0,
/*0xE4*/ 0,
/*0xE5*/ 0,
/*0xE6*/ 0,
/*0xE7*/ 0,
/*0xE8*/ 0,
/*0xE9*/ 0,
/*0xEA*/ 0,
/*0xEB*/ 0,
/*0xEC*/ 0,
/*0xED*/ 0,
/*0xEE*/ 0,
/*0xEF*/ 0,
/*0xF0*/ 0,
/*0xF1*/ 0,
/*0xF2*/ 0,
/*0xF3*/ 0,
/*0xF4*/ 0,
/*0xF5*/ 0,
/*0xF6*/ 0,
/*0xF7*/ 0,
/*0xF8*/ 0,
/*0xF9*/ 0,
/*0xFA*/ 0,
/*0xFB*/ 0,
/*0xFC*/ 0,
/*0xFD*/ 0,
/*0xFE*/ 0,
/*0xFF*/ 0
};