#include "ff.h"
static void THISCALL flags(u8*me){
 const u32 names[4]={0x6a9ac8,0x6a9adc,0x6a9af0,0x6a9afc};
 for(u32 i=0;i<4;++i){
 auto fmt=vcall<void*>(G(void*,0x70039c),0x190);u8 text[64];
 typedef void(*Format)(void*,u8*,u32,u32);
 (*(Format*)(*(u8**)fmt+0x198))(fmt,text,names[i],*(u32*)(me+0x194));
 auto table=*(void**)(G(u8*,0x70039c)+0x9b);auto settings=vcall<void*>(table,0x134);
 u8 value=0;vcall<void>(settings,0x90,text,&value);me[0x1b4+i]=value;
 }
}
PCREG(578900,flags);
