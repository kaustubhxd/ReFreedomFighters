#include "ff.h"
extern "C" void THISCALL ext_4daf90(void*,float*);
static void THISCALL frame(u8* me){
 if(!me[0x54] || !*(void**)(me+0x48))return;
 u32 it[3];vcall<void>(*(void**)(me+0x48),0x4c,it);u32 id=vcall<u32>(*(void**)(me+0x48),0x5c,it);
 while(it[0]){
  void* sys=G(void*,0x70039c);void* ob=vcall<void*>(*(void**)((u8*)sys+0x9b),0x58,id);
  float p[3];ext_4daf90(*(void**)((u8*)ob+8),p);vcall<void>(ob,0x84,p);vcall<void>(*(void**)(me+0x44),0x8c,p);
  u8 hit=vcall<u8>(*(void**)(me+0x44),0x180,p,-10.0f);float dt=*(float*)(G(u8*,0x70039c)+0x48);
  if(hit){
   float t=dt+*(float*)(me+0x8b);*(float*)(me+0x8b)=t;
   if(t>*(float*)(me+0x50)){
    float threshold=G(float,0x678858)/ *(float*)(me+0x97);
    float repeat=*(float*)(G(u8*,0x70039c)+0x48)+*(float*)(me+0x9b);*(float*)(me+0x9b)=repeat;
    if(repeat>threshold){
     *(u32*)(me+0x7f)=*(u32*)(me+0x93);
     void* tab=*(void**)(G(u8*,0x70039c)+0x9b);
     u16 effect=vcall<u32>(tab,0x114,0x69eaacu,0u,0x6b695cu,0x83u,me+0x57,0u);
     vcall<void>(ob,0x128,(u32)effect);*(u32*)(me+0x9b)=0;*(u32*)(me+0x8f)=0;
    }
   }
  }else{
   float t=dt+*(float*)(me+0x8f);*(float*)(me+0x8f)=t;
   if(t>*(float*)(me+0x87)){*(u32*)(me+0x8b)=0;*(u32*)(me+0x8f)=0;}
  }
  id=vcall<u32>(*(void**)(me+0x48),0x5c,it);
 }
}
PCREG(5dba60,frame);
