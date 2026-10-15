#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(void*,u32);
static u32 name(u8*v){if(v[4]==3)return *(u32*)v;if(v[4]==4)return vcall<u32>(*(void**)v,0x34);auto lo=vcall<void*>(G(void*,0x700390),0x20,(u32)0x69c8e0,0x111);typedef void(*P)(void*,u32,u32);(*(P*)(*(u8**)lo+0x2c))(lo,0x69c6b0,0x69c9b0);typedef void(*A)();G(A,0x7003b0)();return 0;}
static void THISCALL assign(void*,u8*args){auto svc=vcall<void*>(*(void**)(G(u8*,0x70039c)+0x9b),0x138);u32 value=name(ext_5003d0(*(void**)(args+4),1));u32 key=name(ext_5003d0(*(void**)(args+4),0));vcall<void>(svc,0x40,key,value,12);}
PCREG(50fd00,assign);
