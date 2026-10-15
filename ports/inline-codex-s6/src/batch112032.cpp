#include "ff.h"
extern "C" u8 THISCALL ext_4db9a0(void*,u32);
static void THISCALL update(u8*me){
 auto r=vcall<void*>(me,0x84);vcall<void>(r,0x34c,0x14,0,*(void**)(me+0x44),(u32)0x41200000,0);
 auto list=*(u8**)(me+0x310);u8*entry=*(u8**)(list+8);while(entry){if(ext_4db9a0(entry,0x20002c))vcall<void>(*(void**)(entry+0x54),0x250,0x20);vcall<void>(*(void**)(me+0x310),0x50,&entry);}
 vcall<void>(me,0x64,0x110);r=vcall<void*>(me,0x84);vcall<void>(r,0x30c,0);
 auto id=vcall<u32>(me+0x23c,0x30,*(u32*)(me+0x33c)-1);auto controls=vcall<u8*>(G(void*,0x70038c),0xcc,id);
 for(u32 i=0;i<8;++i)vcall<void>(*(void**)(controls+12+4*i),0x28c);
 auto table=*(u8**)(G(u8*,0x70039c)+0x9b);auto text=vcall<u32>(*(void**)(table+0xae4),0,(u32)0x6a67e8,(u32)0x6aad84);
 for(u32 i=0;i<2;++i){u32 offset=12+16*i;auto control=*(void**)(controls+offset);vcall<void>(control,0x284,text);vcall<void>(control,0x26c,(u32)0x43aa0000,0,0);}
}
PCREG(57d000,update);
