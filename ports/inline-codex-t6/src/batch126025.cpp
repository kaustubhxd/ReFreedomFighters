#include "ff.h"
static double absolute(float f){return __builtin_bit_cast(double,__builtin_bit_cast(u64,(double)f)&0x7fffffffffffffffULL);}
static void THISCALL transfer(u8* me){
 float speed=G(float,me+0x6c),product=speed*G(float,me+0x78);float left=0,right=0;
 if(0>product)left=(float)(absolute(speed)/(double)G(float,me+0x21ad));if(product>0)right=(float)(absolute(speed)/(double)G(float,me+0x21ad));
 for(s32 i=0;i<G(s32,me+0x8d);++i)G(float,me+0xa1+0xde*i)=left+G(float,0x678858);
 for(s32 i=0;i<G(s32,me+0x91);++i)G(float,me+0x791+0xde*i)=right+G(float,0x678858);
 float longitudinal=G(float,me+0x74);u32 parity=(0>=longitudinal*G(float,me+0x78))?1:0;
 float ratio=(float)(absolute(longitudinal)/(double)G(float,me+0x21b1));float add=0;
 if(!(0>ratio))add=_mm_cvtss_f32(_mm_min_ss(_mm_set_ss(G(float,0x680a68)),_mm_set_ss(ratio)));
 for(s32 i=0;i<G(s32,me+0x8d);i+=2){u8* p=me+0xa1+0xde*(parity+i);G(float,p)=G(float,p)+add;}
 for(s32 i=0;i<G(s32,me+0x91);i+=2){u8* p=me+0x791+0xde*(parity+i);G(float,p)=G(float,p)+add;}
}
PCREG(529450,transfer);
