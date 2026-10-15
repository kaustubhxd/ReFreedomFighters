#include "ff.h"
extern "C" void FASTCALL ext_43e920(float*,u8*,u8*);
static void THISCALL fn545d60(u8* s,s32 index,u32 a,u32 b){
 if(index<0||index>=*(s32*)(s+0x2c)){
  u8* log=vcall<u8*>(G(u8*,0x700390),0x20,(u32)0x6a2e20,(u32)0xbd2);
  typedef void(*Log)(u8*,u32);(*(Log*)(*(u8**)log+0x2c))(log,0x6a2ed0);return;
 }
 u8* out=*(u8**)(s+0x13)+12*index;
 *(u32*)(out+4)=b;*(u32*)out=a;
 u8* points=*(u8**)(s+0xf);float d[3];
 ext_43e920(d,points+52*a+12,points+52*b+12);
 float sum=d[1]*d[1];float x=d[0]*d[0];sum=sum+x;sum=sum+d[2]*d[2];
 double root=(*(crt::libm1*)0x676330)((double)sum);
 *(float*)(out+8)=(float)root;
}
PCREG(545d60,fn545d60);
