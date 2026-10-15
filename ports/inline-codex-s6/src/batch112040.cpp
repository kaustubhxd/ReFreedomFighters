#include "ff.h"
extern "C" {
 void THISCALL ext_5aede0(void*);void THISCALL ext_5aee60(void*,u32);void THISCALL ext_65e090(void*);
 void THISCALL ext_5afbb0(void*,u32,void*);u32 THISCALL ext_5af1d0(void*,u32);
 void THISCALL ext_5af990(void*,u32,u32,u32,u32);void THISCALL ext_5af8f0(void*,u32,u32);
}
static void* service(){return vcall<void*>(*(void**)(G(u8*,0x70039c)+0x9b),0x138);}
static void THISCALL apply(u8*me,u32 value){
 u8 temp[96],state[12];ext_5aede0(temp);u32 id=0;vcall<void>(service(),0x88,(u32)0x6a7374,&id);ext_5aee60(temp,id);
 ext_65e090(state);id=0;vcall<void>(service(),0x88,(u32)0x681320,&id);auto table=*(void**)(G(u8*,0x70039c)+0x9b);auto owner=vcall<u32>(table,0x58,id);ext_5afbb0(state,owner,temp);
 ext_5af990(state,13,ext_5af1d0(me+24,13),0,0);ext_5af990(state,12,ext_5af1d0(me+24,12),0,0);
 ext_5af8f0(state,14,ext_5af1d0(me+24,14));ext_5af8f0(state,16,ext_5af1d0(me+24,16));ext_5af8f0(state,15,ext_5af1d0(me+24,15));
 ext_5af990(state,*(u32*)(me+8),*(u32*)(me+16),value,0);ext_5af990(state,*(u32*)(me+12),*(u32*)(me+20),value,0);ext_5af990(state,1,0,value,0);
}
PCREG(5b0560,apply);
