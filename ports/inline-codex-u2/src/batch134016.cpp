#include "ff.h"
static s32 cvtt(float f){return _mm_cvttss_si32(_mm_set_ss(f));}
static void THISCALL fn4bc910(u8* s){
 u8* sys=G(u8*,0x70039c);if(!G(u32,sys+0x1a9f))return;
 s32 now=G(s32,sys+0x40);s32 then=cvtt(G(float,s+0x9c)*G(float,0x678620));
 float dt=float((s32)((u32)now-(u32)then))*G(float,0x6785e4);
 if(G(float,s+0x98)>=dt)return;
 G(float,s+0x9c)=float(now)*G(float,0x6785e4);
 u32 mode=G(u32,s+0x60);
 if((mode==0&&G(u32,s+0x64)==1)||(mode==1&&G(u32,s+0x64)==0)){
  G(u32,s+0x64)=mode;float start=G(float,G(u8*,G(u8*,s+0x44)+0x18)+0x84);
  G(u32,s+0xb4)=0;G(float,s+0x68)=start;G(float,s+0x6c)=G(float,s+0xd5)-start;
 }
 float elapsed=float(G(s32,s+0xb4))*dt;float duration=G(float,s+0xb8);
 if(duration>=elapsed){
  float value=(G(float,s+0x6c)/duration)*elapsed+G(float,s+0x68);
  if(mode==0||(mode==1&&G(float,s+0xd5)>value))G(float,G(u8*,G(u8*,s+0x44)+0x18)+0x84)=value;
  else if(mode==1)G(s32,s+0xb4)=cvtt(duration/dt+G(float,0x678858));
  ++G(u32,s+0xb4);
 }else if(G(u32,s+0xa8)==2||G(u32,s+0xa8)==3)vcall<void>(s,0x8c,G(float,s+0xd5),G(float,s+0xd1));
}
PCREG(4bc910,fn4bc910);
