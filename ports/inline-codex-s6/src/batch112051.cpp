#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(void*,u32);
static u32 name(u8*v){if(v[4]==3)return *(u32*)v;if(v[4]==4)return vcall<u32>(*(void**)v,0x34);auto lo=vcall<void*>(G(void*,0x700390),0x20,(u32)0x69c8e0,0x111);typedef void(*P)(void*,u32,u32);(*(P*)(*(u8**)lo+0x2c))(lo,0x69c6b0,0x69c9b0);typedef void(*A)();G(A,0x7003b0)();return 0;}
static void THISCALL send(u8*me,u8*args){auto params=*(void**)(args+4);u32 data[3];data[0]=*(u32*)ext_5003d0(params,2);data[1]=*(u32*)ext_5003d0(params,3);data[2]=name(ext_5003d0(params,4));u32 label=name(ext_5003d0(params,1));auto table=*(void**)(G(u8*,0x70039c)+0x9b);u32 msg=vcall<u16>(table,0x114,label,0,(u32)0x69ca10,0x284);auto target=ext_5003d0(params,0);vcall<void>(*(void**)(me+12),0x12c,*(u32*)target,msg,data);}
PCREG(502670,send);
