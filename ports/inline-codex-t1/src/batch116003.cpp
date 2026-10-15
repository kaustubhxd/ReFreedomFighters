#include "ff.h"
extern "C" void *THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_5002f0(void*,u32);
extern "C" void THISCALL ext_461570(void*,float,u32,u32);
static void *cell(void*s,u32 n){return ext_5003d0(s,n);}
static void THISCALL fn505720(u8*s,u8*args){
 void *input=*(void**)(args+4);
 u32 *c4=(u32*)cell(input,4),*c3=(u32*)cell(input,3),*c2=(u32*)cell(input,2),*c1=(u32*)cell(input,1),*c0=(u32*)cell(input,0);
 u8 *sys=G(u8*,0x70039c);u8 *table=*(u8**)(sys+0x9b);
 u32 result=vcall<u32>(s,0x50,*(u32*)(table+0x44)+*c0,*c1,*c2,*c3,*c4,0x3f800000u);
 void *out=cell(*(void**)(args+8),0);
 ext_5002f0(out,result);
}
PCREG(505720,fn505720);
static u8 THISCALL fn4864e0(u8*s){
 void *target=vcall<void*>(*(void**)(s+8),0x2e8);
 u32 choice=vcall<u32>(target,0x1e0,0x1007d4u);
 u32 item=*(u32*)(s+((choice&255)?0x18:0x14));
 if(!item)return vcall<u8>(s,0xc);
 long double r=vcall<long double>(G(void*,0x70039c),0x1c0,0x68cdc4u,0x4cu);
 float speed=(float)(r*(long double)G(float,0x67c19c)+(long double)G(float,0x67c1a8));
 void *action=vcall<void*>(*(void**)(s+0xc),0x228,item,1u,0u,0xbf800000u,fbits(speed));
 ext_461570(action,5.f,0x465710u,0);
 return 1;
}
PCREG(4864e0,fn4864e0);
static u32 THISCALL fn4684c0(u8*s,u32 id,void*arg){
 if((u16)id==*(u16*)(s+0x4a)){
  // Save slot before the nested call, as the original does.
  typedef void(THISCALL *setter)(void*,u32);
  setter set=*(setter*)(*(u8**)s+0x84);
  u32 result=vcall<u32>(*(void**)(s+0x44),0x20,arg);set(s,result);
 }else if((u16)id==*(u16*)(s+0x4c)){
  u32 name=id;vcall<void>(arg,0x88,0x688a30u,&name);
  u8 *sys=G(u8*,0x70039c);void *actor=vcall<void*>(*(void**)(sys+0x9b),0x58,name);
  vcall<void>(s,0x88,arg);
  float t=*(float*)(s+0x57)*G(float,0x67862c);
  s32 ticks=_mm_cvtt_ss2si(_mm_set_ss(t));
  sys=G(u8*,0x70039c);s32 delta=(s32)(*(u32*)(sys+0x40)-(u32)ticks);
  float time=(float)delta*G(float,0x6785e4);
  vcall<void>(actor,0x310,s,time);
 }
 return 0;
}
PCREG(4684c0,fn4684c0);
static void THISCALL fn504fc0(u8*s,u8*args){
 void *input=*(void**)(args+4);
 if(*(u32*)cell(input,0)){
  u32 key=*(u32*)cell(input,0);u8 *sys=G(u8*,0x70039c);
  if(vcall<u32>(*(void**)(sys+0x9b),0x54,key)){
   key=*(u32*)cell(input,0);
   vcall<void>(*(void**)(s+0x14),0x3c4,key,0u,0u,0u,0u,0xffffffffu);return;
  }
 }
 vcall<void>(*(void**)(s+0x14),0x3c8,0u,0u,0u,0u,0xffffffffu);
}
PCREG(504fc0,fn504fc0);
