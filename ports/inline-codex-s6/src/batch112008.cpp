#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(void*,u32);
static void logmsg(u32 file,u32 line,u32 format,u32 arg){auto lo=vcall<void*>(G(void*,0x700390),0x20,file,line);typedef void(*P)(void*,u32,u32);(*(P*)(*(u8**)lo+0x2c))(lo,format,arg);}
static void assertmsg(){typedef void(*Fn)();auto fn=G(Fn,0x7003b0);if(fn)fn();else asm volatile("int3");}
static void THISCALL find(void*,u8*args){
 auto a=ext_5003d0(*(void**)(args+4),0);u32 name;
 if(a[4]==3)name=*(u32*)a;
 else if(a[4]==4)name=vcall<u32>(*(void**)a,0x34);
 else{logmsg(0x69c8e0,0x111,0x69c6b0,0x69c9b0);assertmsg();name=0;}
 a=ext_5003d0(*(void**)(args+4),1);auto table=*(void**)(G(u8*,0x70039c)+0x9b);
 auto actor=vcall<void*>(table,0x58,*(u32*)a);void*found=0;
 if(actor&&vcall<u8>(actor,0x1e0,0x100001))found=vcall<void*>(actor,0x25c,name,0);
 if(!found)logmsg(0x69db34,0xf9,0x69db64,name);
 table=*(void**)(G(u8*,0x70039c)+0x9b);u32 id=vcall<u32>(table,0x4c,found);
 auto out=ext_5003d0(*(void**)(args+8),0);
 if(out[4]<=1){*(u32*)out=id;out[4]=1;}
 else{logmsg(0x69c8e0,0xc4,0x69c6b0,0x69c938);assertmsg();}
}
PCREG(50de50,find);
