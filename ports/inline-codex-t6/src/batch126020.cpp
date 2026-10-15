#include "ff.h"
extern "C" void THISCALL ext_5f56f0(void*);
extern "C" void THISCALL ext_5fd120(void*,void*);
static void THISCALL budget(u8* me,u8* list){
 float dt=G(float,G(u32,0x70039c)+0x48)*G(float,0x67885c);dt=dt*G(float,0x680a84);u32 limit=(u32)_mm_cvttss_si32(_mm_set_ss(dt));u32 used=0;
 if(G(u8,me+0xc)){for(s32 i=0;i<G(s32,list+8);++i){u8* entry=G(u8*,G(u32,list)+4*i);G(u16,entry+8)=50;}limit=0xffffffff;}
 if(G(s32,me+8)>=G(s32,list+8))G(u32,me+8)=0;
 while(G(s32,me+8)<G(s32,list+8)){u32 idx=G(u32,me+8);u8* entry=G(u8*,G(u32,list)+4*idx);ext_5f56f0(entry);if(G(u16,entry+0xac)&0x4000)ext_5fd120(G(void*,me+4),entry);
 used+=G(u32,entry+0xe);++G(u32,me+8);if(used>limit)break;}
 G(u8,me+0xc)=0;
}
PCREG(550f30,budget);
