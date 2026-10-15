#include "ff.h"
extern "C" void THISCALL ext_4e1b60(u8*);
extern "C" void FASTCALL ext_43e8e0(float*,float*,float*);
static u8 THISCALL fn445e90(u8* s,u32* out,u32 ignored,u32 index,float offset){
 u8 hit[112];ext_4e1b60(hit);*(u32*)hit=0;*(u32*)(hit+4)=0;*(float*)(hit+8)=*(float*)(s+0x64)+offset;
 vcall<void>(s,0x84,hit);*(u32*)(hit+12)=0;*(u32*)(hit+16)=0;*(float*)(hit+20)=*(float*)(s+0x68);vcall<void>(s,0x88,hit+12);hit[108]=0;
 u8* tab=*(u8**)(G(u8*,0x70039c)+0x9b);u8* mgr=*(u8**)(tab+0xadc);
 if(vcall<u8>(mgr,0x2e0,hit,(u32)0,index,(u32)-1,(u32)1,(u32)1)){
  tab=*(u8**)(G(u8*,0x70039c)+0x9b);if(vcall<u32>(tab,0x54,*(u32*)(hit+68))){out[0]=*(u32*)(hit+40);out[1]=*(u32*)(hit+44);out[2]=*(u32*)(hit+48);out[3]=*(u32*)(hit+68);return 1;}}
 ext_43e8e0((float*)out,(float*)hit,(float*)(hit+12));return 0;
}
PCREG(445e90,fn445e90);
