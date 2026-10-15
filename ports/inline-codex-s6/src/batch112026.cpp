#include "ff.h"
extern "C" u32 THISCALL ext_41e680(void*);
extern "C" void* THISCALL ext_589c20(void*,u32);
extern "C" void THISCALL ext_59a5e0(void*,u32);
static void notify(u32 n){ext_59a5e0(ext_589c20(G(void*,0x7003b8),0),n);}
static u32 THISCALL event(u8*me,u32 code,u32*data){
 u16 id=code;if(id==*(u16*)(me+0xf9)&&data)*data=ext_41e680(me);
 if(id==*(u16*)(me+0xfb)){for(u32 i=0;i<4;++i)me[0x61+0x12*i]=0;s32 n=data[1];if(n>=3&&n<=6){me[0x2b+18*n]=1;auto o=ext_589c20(G(void*,0x7003b8),0);if(data[1]==3)ext_59a5e0(o,13);if(data[1]==4)ext_59a5e0(o,14);}}
 if(id==*(u16*)(me+0x103)){for(u32 i=0;i<4;++i){auto list=*(void**)(me+0xe9+4*i);if(vcall<u32>(list,0x28,data[0]))vcall<void>(list,0x3c,data[0]);}vcall<void>(*(void**)(me+0xdd+4*data[1]),4,data[0]);notify(11);}
 if(id==*(u16*)(me+0x107)){auto list=*(void**)(me+0xe9+4*(data[1]-3));if(vcall<u32>(list,0x14)&&vcall<u32>(list,0x28,data[0])){auto owner=*(void**)(me+0x44);u32 msg=*(u16*)(me+0x105);auto table=*(void**)(G(u8*,0x70039c)+0x9b);auto item=vcall<void*>(table,0x58,data[0]);vcall<void>(owner,0x130,item,msg,data);}}
 return 0;
}
PCREG(5a3f50,event);
