#include "ff.h"
extern "C" void THISCALL ext_422ed0(void*,const char*,u32);
static void THISCALL frame17(u8* self,u32 input){
 void* sys=G(void*,0x70039c);const char* file=(const char*)0x677fb4;
 u64 start=vcall<u64>(sys,0x1c8,file,0x71bu);
 vcall<void>(self,0x15c);
 void* db=*(void**)(self+0x9b);
 if(*(s32*)(self+0x40)<0){
  vcall<void>(db,0xa4);u32 h=vcall<u32>(db,0xb0);vcall<void>(db,0xa0,h);vcall<void>(db,0x18c,1u);
 }else{
  if(*(u32*)(self+0x1b44)){
   void* p=G(void*,0x7003a0);if(p)vcall<void>(p,0x1c);
   ext_422ed0(G(void*,0x70039c),file,0x726);
   p=*(void**)(self+0x1907);if(p)vcall<void>(p,0x54);
  }
  u8* s=G(u8*,0x70039c);
  if(!s[0x6d] && *(u32*)(self+0x1b44) && *(void**)(s+0x190f)){
   s32 pos[2];typedef s32(STDCALL*Get)(s32*);typedef s32(STDCALL*Client)(u32,s32*);
   (*(Get*)0x6761c0)(pos);u8* mouse=*(u8**)(G(u8*,0x70039c)+0x190f);
   (*(Client*)0x6761c4)(*(u32*)(mouse+0x133),pos);
   vcall<void>(*(void**)(G(u8*,0x70039c)+0x190f),0x230,0u,pos[0],pos[1]);
  }
  vcall<void>(*(void**)(self+0x9b),0x9c,input);
 }
 vcall<void>(self,0xd0);
 for(;;){
  u64 elapsed=vcall<u64>(G(void*,0x70039c),0x1c8,file,0x738u)-start;
  double ticks=(double)(u32)elapsed+(double)(s32)(elapsed>>32)*G(double,0x6c1618);
  float ratio=(float)ticks/(*(float*)(self+0x58));
  if(!(G(double,0x6785f0)>(double)ratio))break;
 }
}
PCREG(421d20,frame17);
