#include "ff.h"
extern "C" void THISCALL ext_516230(void*,void*);
extern "C" void FASTCALL ext_43e960(void*,void*);
extern "C" void FASTCALL ext_441a60(void*,void*);
extern "C" void THISCALL ext_52a270(void*,float);
static u8 THISCALL fn43dff0(u8*s,u8*query,u32 unused){
 u32 hit[18];hit[0]=0x3f800000;
 u32 from[3],to[3];for(int i=0;i<3;i++){from[i]=*(u32*)(query+4*i);to[i]=*(u32*)(query+12+4*i);}
 u8 *sys=G(u8*,0x70039c),*manager=*(u8**)(sys+0x1aa3);
 if(!vcall<u8>(*(void**)(manager+0x1c),0x64,hit,*(u32*)(s+8),from,to,(u32)query[0x6c],0xffffffffu))return 0;
 sys=G(u8*,0x70039c);u32 object=vcall<u32>(*(void**)(sys+0x9b),0x50,hit[4]);
 *(u32*)(query+0x34)=hit[0];*(u32*)(query+0x44)=object;
 for(int i=0;i<3;i++)*(u32*)(query+0x28+4*i)=hit[1+i];
 *(u32*)(query+0x3c)=hit[16];*(u32*)(query+0x40)=hit[17];
 return 1;
}
PCREG(43dff0,fn43dff0);
static void THISCALL fn529660(u8*s){
 for(s32 i=0;i<*(s32*)(s+0x8d);i++){
  float p[3];ext_516230(s+0x95+0xde*i,p);ext_43e960(p,s);ext_441a60(p,s+0xc);ext_52a270(s+0xe75+0x133*i,p[1]);
 }
 for(s32 i=0;i<*(s32*)(s+0x91);i++){
  float p[3];ext_516230(s+0x785+0xde*i,p);ext_43e960(p,s);ext_441a60(p,s+0xc);ext_52a270(s+0x180d+0x133*i,p[1]);
 }
}
PCREG(529660,fn529660);
static s32 truncf(float f){return _mm_cvtt_ss2si(_mm_set_ss(f));}
static void THISCALL fn4678f0(u8*s,u32 id,float duration,u32 a,u32 b,u32 c,u32 d){
 if(s[0x158])return;
 float start=*(float*)(s+0x1a2);
 if(start>=0 && *(u32*)(s+0x1a6)==id)return;
 *(u32*)(s+0x16e)=0x7fffffff;*(u32*)(s+0x192)=0x7fffffff;*(u32*)(s+0x1a6)=id;
 u32 record[4]={a,b,c,d};for(int i=0;i<4;i++)*(u32*)(s+0x1aa+4*i)=record[i];
 if(!(*(u32*)(s+0x136)&0x200000) || !(start>=0)){
  u8 *sys=G(u8*,0x70039c);u32 now=*(u32*)(sys+0x40);
  float elapsed=(float)(s32)(now-(u32)truncf(__builtin_fabsf(start)*G(float,0x678620)))*G(float,0x6785e4);
  float old=*(float*)(s+0x19e),factor=0;
  if(start>=0){factor=old>elapsed?elapsed/old:G(float,0x678858);}
  else if(!(elapsed>old) && old!=0)factor=G(float,0x678858)-elapsed/old;
  *(float*)(s+0x19e)=duration;
  sys=G(u8*,0x70039c);now=*(u32*)(sys+0x40);
  if(factor!=G(float,0x678858))now-=(u32)truncf((factor*duration)*G(float,0x678620));
  *(float*)(s+0x1a2)=(float)(s32)now*G(float,0x6785e4);
 }
 *(u32*)(s+0x136)|=0x200000;
}
PCREG(4678f0,fn4678f0);
