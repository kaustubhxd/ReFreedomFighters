#include "ff.h"
extern "C" void THISCALL ext_5aee60(void*,u32);
extern "C" void THISCALL ext_5afed0(void*,void*,void*);
extern "C" void THISCALL ext_5af8f0(void*,u32,u32);
extern "C" void THISCALL ext_5af990(void*,u32,u32,u32,u32);
static void THISCALL configure(u8* me) {
 u8* sys=G(u8*,0x70039c);
 void* table=*(void**)(sys+0x9b);
 void* config=vcall<void*>(table,0x138);
 u32 value=0;vcall<void>(config,0x88,0x6a7374,&value);
 if(value)ext_5aee60(me+0x95b,value);
 ext_5afed0(me+0x9af,me,me+0x95b);
 if(*(u32*)(G(u8*,0x70039c)+0x1b5d)==1) {
  void* dst=me+0x9c7;
  ext_5af8f0(dst,0x10,2);
  ext_5af990(dst,1,0,0,0);
  if(*(u32*)(*(u8**)(me+0x54)+4)==3) {
   ext_5af990(dst,0xd,0,0,0); ext_5af990(dst,0xc,8,0,0);
   ext_5af990(dst,3,0,0,1); ext_5af990(dst,5,0,1,1);
  }else{
   ext_5af990(dst,0xd,2,0,0);ext_5af990(dst,4,0x14,0,1);ext_5af990(dst,6,0,1,1);
  }
 }
}
PCREG(595100,configure);
