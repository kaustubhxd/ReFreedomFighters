#include "ff.h"
extern "C" void THISCALL ext_4daf90(void*,void*);
extern "C" void THISCALL ext_5bda50(void*,u32,void*);
static void THISCALL tick(u8*me){
 auto found=vcall<u8*>(*(void**)(me+0x81),0x8c,me+0x70,*(u32*)(me+0x79));if(!found)return;
 u32 p[3];ext_4daf90(*(void**)(found+8),p);vcall<void>(found,0x84,p);vcall<void>(*(void**)(me+0x44),0x8c,p);
 u8 inside=vcall<u8>(*(void**)(me+0x44),0x180,p,(u32)0xc1200000);s32 index=*(s32*)(me+0x70),word=index/32;u32 mask=1u<<((index-word*32)&31);auto bits=(u32*)(me+0x48+word*4);u16 event;
 if(inside){if(*bits&mask)return;index=*(s32*)(me+0x70);word=index/32;bits=(u32*)(me+0x48+word*4);mask=1u<<((index-word*32)&31);*bits|=mask;event=*(u16*)(me+0x75);}
 else{if(!(*bits&mask))return;*bits&=~mask;event=*(u16*)(me+0x77);}
 if(event)ext_5bda50(me,event,found);
}
PCREG(5bd7b0,tick);
