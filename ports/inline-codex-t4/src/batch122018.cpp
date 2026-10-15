#include "ff.h"
extern "C" void THISCALL ext_4db500(u8*,float*);
extern "C" void FASTCALL ext_43e920(float*,u8*,u8*);
extern "C" void THISCALL ext_543810(u8*,float*,float);
extern "C" void THISCALL ext_634e90(u8*,u32);
static void THISCALL fn53efd0(u8* s,float* arg){
 float pos[3]={arg[0],arg[1],arg[2]},cur[3],d[3];
 ext_4db500(*(u8**)(*(u8**)(s+0x44)+8),cur);
 ext_43e920(d,(u8*)pos,(u8*)cur);
 float sum=d[0]*d[0];float y=d[1]*d[1];sum=sum+y;sum=sum+d[2]*d[2];
 float len=(float)(*(crt::libm1*)0x676330)((double)sum);
 if(len>G(float,0x6ec38c))return;
 ext_543810(*(u8**)(s+0xcf),pos,G(float,0x6ec388));
 u32 saved=*(u32*)(s+0x141);s[0x10f]=1;*(u32*)(s+0xf7)=1000;*(u32*)(s+0xfb)=0x45480000;*(u32*)(s+0xff)=0x43c80000;*(u32*)(s+0x13d)=saved;
 ext_634e90(s,0x10);
}
PCREG(53efd0,fn53efd0);
