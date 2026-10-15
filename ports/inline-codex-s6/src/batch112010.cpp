#include "ff.h"
extern "C" void THISCALL ext_4dc630(void*,u32,u32);
static void* THISCALL spawn(void*me,u32 a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g){
 auto table=*(void**)(G(u8*,0x70039c)+0x9b);
 if(vcall<u8>(table,0x10))return vcall<void*>(me,0x1bc,a,c,d,e,f,0,g);
 auto o=vcall<u8*>(me,0x1c0,a,b,e,f,g);if(c&&d)vcall<void>(o,0x74,c,d);
 table=*(void**)(G(u8*,0x70039c)+0x9b);auto id=vcall<u32>(table,0x4c,o);
 if(!o||(*(u32*)(*(u8**)(o+8)+0x3c)&0x800000))return 0;
 vcall<void>(o,0x154);
 table=*(void**)(G(u8*,0x70039c)+0x9b);if(!vcall<u32>(table,0x58,id))return 0;
 vcall<void>(o,0x124,1,0,0,0);
 table=*(void**)(G(u8*,0x70039c)+0x9b);if(!vcall<u32>(table,0x58,id))return 0;
 vcall<void>(o,0x124,2,0,0,0);
 table=*(void**)(G(u8*,0x70039c)+0x9b);if(!vcall<u32>(table,0x54,id))return 0;
 ext_4dc630(*(void**)(o+8),0x800000,0);vcall<void>(o,0x158);
 table=*(void**)(G(u8*,0x70039c)+0x9b);return vcall<u32>(table,0x54,id)?o:nullptr;
}
PCREG(45dfb0,spawn);
