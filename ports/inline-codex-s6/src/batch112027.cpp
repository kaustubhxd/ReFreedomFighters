#include "ff.h"
extern "C" void* ext_41e290(u32);
extern "C" void THISCALL ext_4d7c30(void*,u32,u32,void*,u32);
extern "C" void ext_634273(void*,u32);
static void log(u32 line,u32 fmt,u32 name,bool arg){auto o=vcall<void*>(G(void*,0x700390),0x20,(u32)0x696924,line);typedef void(*P2)(void*,u32);typedef void(*P3)(void*,u32,u32);if(arg)(*(P3*)(*(u8**)o+0x2c))(o,fmt,name);else (*(P2*)(*(u8**)o+0x2c))(o,fmt);}
static u8 THISCALL load(u8*me,u32 name,u32 option){
 u32 mode=*(u32*)(me+9);if(mode!=1&&mode!=4){log(0x37c,0x696948,0,false);return 0;}
 auto io=*(void**)(me+0x15);auto file=vcall<u32>(io,0,name,(u32)0x678ccc);if(!file)return 0;
 vcall<void>(io,0x10,file,0,2);u32 size=vcall<u32>(io,12,file);
 if(size){auto p=ext_41e290(size);if(!p){log(0x386,0x696a30,name,true);return 0;}
 vcall<void>(io,0x10,file,0,0);vcall<void>(io,0x14,p,size,file);ext_4d7c30(me,option,0,p,size);ext_634273(p,1);
 }
 vcall<void>(io,4,file);return 1;
}
PCREG(4d5770,load);
