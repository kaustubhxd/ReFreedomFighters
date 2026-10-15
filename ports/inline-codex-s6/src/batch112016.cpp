#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_5002f0(void*,u32);
static void log(u32 line,u32 format,u32 value,bool arg){auto lo=vcall<void*>(G(void*,0x700390),0x20,(u32)0x69d420,line);typedef void(*P2)(void*,u32);typedef void(*P3)(void*,u32,u32);if(arg)(*(P3*)(*(u8**)lo+0x2c))(lo,format,value);else (*(P2*)(*(u8**)lo+0x2c))(lo,format);}
static void THISCALL assign(void*,u8*args){
 ext_5002f0(ext_5003d0(*(void**)(args+8),0),0);
 auto a=ext_5003d0(*(void**)(args+4),1);auto table=*(void**)(G(u8*,0x70039c)+0x9b);auto actor=vcall<u8*>(table,0x58,*(u32*)a);
 if(!actor){log(0x175,0x69d6dc,0,false);return;}
 if(!vcall<u8>(actor,0x1e0,0x1007d1)){log(0x17a,0x69d5fc,*(u32*)(actor+4),true);return;}
 if(vcall<u32>(actor,0x2f4)){log(0x182,0x69d70c,*(u32*)(actor+4),true);return;}
 a=ext_5003d0(*(void**)(args+4),0);table=*(void**)(G(u8*,0x70039c)+0x9b);auto other=vcall<void*>(table,0x58,*(u32*)a);u32 ref=other?vcall<u32>(other,0x20):0;
 a=ext_5003d0(*(void**)(args+4),0);vcall<void>(actor,0x2f0,*(u32*)a,ref,1);
 ext_5002f0(ext_5003d0(*(void**)(args+8),0),1);
}
PCREG(50bbb0,assign);
