#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_5002f0(void*,u32);
static void THISCALL choose(u8*me,u8*args){
 auto owner=*(u8**)(me+12);if(!owner){auto lo=vcall<void*>(G(void*,0x700390),0x20,(u32)0x69d214,0x93);typedef void(*P)(void*,u32);(*(P*)(*(u8**)lo+0x2c))(lo,0x69d274);ext_5002f0(ext_5003d0(*(void**)(args+8),0),0);return;}
 auto list=*(void**)(owner+24);s32 count=vcall<s32>(list,0x14);
 if(!count){auto lo=vcall<void*>(G(void*,0x700390),0x20,(u32)0x69d214,0x9a);u32 name=*(u32*)(owner+4);if(!name)name=0x67c8e8;typedef void(*P)(void*,u32,u32);(*(P*)(*(u8**)lo+0x30))(lo,0x69d2a8,name);ext_5002f0(ext_5003d0(*(void**)(args+8),0),0);return;}
 s32 index=vcall<s32>(G(void*,0x70039c),0x1bc,(u32)0x69d214,0x9e)%count;auto avoid=ext_5003d0(*(void**)(args+4),0);list=*(void**)(*(u8**)(me+12)+24);
 if(vcall<u32>(list,0x30,index)==*(u32*)avoid)index=(index+1)%count;
 list=*(void**)(*(u8**)(me+12)+24);u32 result=vcall<u32>(list,0x30,index);ext_5002f0(ext_5003d0(*(void**)(args+8),0),result);
}
PCREG(509970,choose);
