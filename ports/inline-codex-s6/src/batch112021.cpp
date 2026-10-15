#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(void*,u32);
static void error(u32 line,u32 why){auto lo=vcall<void*>(G(void*,0x700390),0x20,(u32)0x69c8e0,line);typedef void(*P)(void*,u32,u32);(*(P*)(*(u8**)lo+0x2c))(lo,0x69c6b0,why);typedef void(*A)();auto a=G(A,0x7003b0);if(a)a();else asm volatile("int3");}
static void THISCALL broadcast(u8*me,u8*args){
 auto a=ext_5003d0(*(void**)(args+4),0);u32 name=0;if(a[4]==3)name=*(u32*)a;else if(a[4]==4)name=vcall<u32>(*(void**)a,0x34);else error(0x111,0x69c9b0);
 auto table=*(void**)(G(u8*,0x70039c)+0x9b);u32 id=vcall<u16>(table,0x114,name,0,(u32)0x69d214,0xba);
 a=ext_5003d0(*(void**)(args+4),1);if(a[4]>1)error(0x104,0x69c938);u32 value=*(u32*)a;
 auto owner=*(u8**)(me+12);auto list=*(void**)(owner+24);if(!list)return;
 u32 it[3];vcall<void>(list,0x4c,it);list=*(void**)(*(u8**)(me+12)+24);auto entry=vcall<u32>(list,0x5c,it);
 while(it[0]){owner=*(u8**)(me+12);vcall<void>(owner,0x12c,entry,id,value);list=*(void**)(*(u8**)(me+12)+24);entry=vcall<u32>(list,0x5c,it);}
}
PCREG(509d10,broadcast);
