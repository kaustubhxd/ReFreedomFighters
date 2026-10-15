#include "ff.h"
extern "C" void THISCALL ext_4db7c0(void*,float*);
extern "C" void THISCALL ext_4db500(void*,float*);
extern "C" void THISCALL ext_573c70(void*,u32,float*);
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" void FASTCALL ext_43e8e0(void*,void*,void*);
static void THISCALL fn574ff0(u8*s){
 s[0x21b]=0;
 for(int k=0;k<5;k++){
  u8*slot=s+0x228+0x24*k;u8*o=*(u8**)(slot+0x18);if(!o)continue;
  float extent[3]={0,0,0},center[3]={0,0,0};ext_4db7c0(*(void**)(o+8),extent);
  for(int i=0;i<3;i++)center[i]=*(float*)(*(u8**)(o+8)+0x30+4*i);
  ext_43e920(slot,center,extent);ext_573c70(s,*(u32*)(s+0x1b8),(float*)slot);
  ext_43e8e0(slot+0xc,center,extent);ext_573c70(s,*(u32*)(s+0x1b8),(float*)(slot+0xc));
  for(int i=0;i<2;i++)if(*(float*)(slot+4*i)>*(float*)(slot+0xc+4*i)){float f=*(float*)(slot+4*i);*(float*)(slot+4*i)=*(float*)(slot+0xc+4*i);*(float*)(slot+0xc+4*i)=f;}
  o=*(u8**)(slot-4);float pos[3]={0,0,0};if(o){ext_4db500(*(void**)(o+8),pos);*(float*)(slot+8)=pos[2];}
 }
}
PCREG(574ff0,fn574ff0);
