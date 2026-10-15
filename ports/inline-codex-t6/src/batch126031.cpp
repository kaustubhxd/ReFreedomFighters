#include "ff.h"
extern "C" void THISCALL ext_487c70(void*,void*,u32,void*,float);
extern "C" void FASTCALL ext_451890(void*,void*,float);
extern "C" void THISCALL ext_4e09b0(void*);
extern "C" void THISCALL ext_4e0d80(void*,float);
static void THISCALL movement(u8* me,u8* basis,u32 arg,float* output,float original){
 ext_487c70(me,basis,arg,output,original);u32 mode=G(u32,G(u32,me+4)+0x417);output[0]=0;output[1]=0;output[2]=0;
 if(!(mode&0x18))G(u16,me+0x3bb)=0;
 if(!(mode&3)){
  if(!G(u8,me+0x3ad)){if(G(u8,me+0x3bb)||G(u8,me+0x3bc)||G(u8,me+0x3be))mode=G(u8,me+0x3be)?1:5;}
  else if((G(u8,me+0x3bb)&&(mode&8))||(G(u8,me+0x3bc)&&(mode&0x10)))mode=5;
  else{if(G(u8,me+0x3be)){ext_4e09b0(me+0x3af);G(u8,me+0x3be)=0;}return;}
 }
 float speed=G(float,0x678858);if(G(u8,me+0x3ad))speed=G(float,0x68d458);else if(G(u32,me+0x21))speed=G(float,G(u32,me+0x21)+4);
 bool forward=(mode&4)!=0;ext_451890(output,me+0x3af,forward?1.0f:-1.0f);bool reverse=G(u8,me+0x3be)!=0;
 ext_451890(output,basis+0xc,(forward==reverse)?1.0f:-1.0f);ext_4e0d80(output,speed);
}
PCREG(487e50,movement);
