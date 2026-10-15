#include "ff.h"
extern "C" u32 THISCALL ext_41e680(void*);
static u8 THISCALL load(u8*me,void*stream){u32 flags,mask;vcall<void>(stream,0x18,me+4,4);vcall<void>(stream,0x18,me+8,4);vcall<void>(stream,0x18,&flags,4);vcall<void>(stream,0x18,&mask,4);vcall<void>(stream,0x18,me+12,4);vcall<void>(stream,0x18,me+16,4);vcall<void>(stream,0x18,me+28,4);vcall<void>(stream,0x18,me+56,4);vcall<void>(me,0x64,mask);vcall<void>(me,0x68,~mask,0);*(u32*)(me+20)=flags;
 if(flags&8){auto table=*(u8**)(G(u8*,0x70039c)+0x9b);if(vcall<u32>(table+0xcc,8)){u32 id=ext_41e680(me);table=*(u8**)(G(u8*,0x70039c)+0x9b);auto item=vcall<u32>(table+0xcc,4,id);if(item){table=*(u8**)(G(u8*,0x70039c)+0x9b);vcall<void>(table+0xcc,0,item,*(u32*)(me+16));}}}return 1;}
PCREG(468fa0,load);
