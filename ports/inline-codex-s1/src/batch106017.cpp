#include "ff.h"
extern "C" void ext_633654(u32);
static void THISCALL update_color(u8* me){
 void* table=*(void**)(G(u8*,0x70039c)+0x9b);
 void* obj=vcall<void*>(table,0x58,*(u32*)(me+0x48));
 if(obj){
  float v[3]={0,0,0};vcall<void>(obj,0x84,v);
  u32 packed=vcall<u32>(*(void**)(me+0x44),0x218,v,0);
  table=*(void**)(G(u8*,0x70039c)+0x9b);
  void* cfg=vcall<void*>(table,0x138);
  float high=(float)((double)((packed>>16)&0xff)+G(double,0x680aa0))*G(float,0x682eb8);
  vcall<void>(cfg,0x58,0x6954e8,high,3);
  table=*(void**)(G(u8*,0x70039c)+0x9b);cfg=vcall<void*>(table,0x138);
  float low=(float)((double)(packed&0xff)+G(double,0x680aa0))*G(float,0x682eb8);
  vcall<void>(cfg,0x58,0x6954f8,low,3);
 }
 ext_633654(0);
}
PCREG(4c91c0,update_color);
