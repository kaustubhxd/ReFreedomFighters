#include "ff.h"
extern "C" void* THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_528100(void*,void*,void*);
extern "C" void THISCALL ext_525380(void*,void*,void*);
static void THISCALL fn558cb0(u8*s,u8*args){
 u32 *two=(u32*)ext_5003d0(*(void**)(args+4),2);
 u32 *one=(u32*)ext_5003d0(*(void**)(args+4),1);
 u32 *zero=(u32*)ext_5003d0(*(void**)(args+4),0);
 u32 vector[3]={*zero,*one,*two},position[3]={0,0,0};
 vcall<void>(*(void**)(s+0x1c),0x84,position);
 u8 *sys=G(u8*,0x70039c);u8 *render=*(u8**)(sys+0x9b);void *service=*(void**)(render+0xadc);
 typedef void(THISCALL *emit)(void*,void*,void*,u32);
 emit fn=*(emit*)(*(u8**)service+0x218);
 u32 random=vcall<u32>(sys,0x1bc,0x6a5eb0u,0x22au);
 sys=G(u8*,0x70039c);render=*(u8**)(sys+0x9b);service=*(void**)(render+0xadc);
 fn(service,position,vector,0u-random);
}
PCREG(558cb0,fn558cb0);
static u8 FASTCALL fn65cb80(float*normal,float*extent,float offset){
 float low[3],high[3];u32 sign=G(u32,0x67af40);
 for(int i=0;i<3;i++){
  float neg=bitsf(fbits(extent[i])^sign);
  if(normal[i]>0){low[i]=neg;high[i]=extent[i];}
  else {low[i]=extent[i];high[i]=neg;}
 }
 float a=normal[1]*low[1]+normal[0]*low[0];a+=normal[2]*low[2];a+=offset;
 if(a>0)return 0;
 float b=normal[1]*high[1]+normal[0]*high[0];b+=normal[2]*high[2];b+=offset;
 return b>=0;
}
PCREG(65cb80,fn65cb80);
static void THISCALL fn5212f0(u8*s){
 if(s[0x133]){
  u8 *sys=G(u8*,0x70039c);u32 now=*(u32*)(sys+0x40);
  if(*(s32*)(s+0x382)<(s32)now)*(u32*)(s+0x382)=now+0x400;
  return;
 }
 u8 *source=*(u8**)(s+0x5c);
 float position[3]={*(float*)(source+8),*(float*)(source+0xc),*(float*)(source+0x10)};
 position[1]+=G(float,0x67cd40);
 ext_528100(s+0x2fd,position,s+0x2d8);
 ext_525380(s+0x2fd,s+0x6c,s+0x60);
 for(int i=0;i<3;i++)*(u32*)(s+0x90+4*i)=*(u32*)(s+0x60+4*i);
}
PCREG(5212f0,fn5212f0);
