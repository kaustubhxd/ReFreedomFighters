#include "ff.h"
extern "C" u32 THISCALL ext_4ce7b0(void*);
static void assertion(){typedef void(*fn)();G(fn,0x7003b0)();}
static void* THISCALL drawslot(u8* me,u8* input,u32 unused){
 u32 id=G(u16,input+0x40);if(id)return G(void*,G(u32,me+0x68)+4*(id&0xfff));
 void* slot=vcall<void*>(G(void*,me+0x22c),8);if(!slot)return slot;
 id=(ext_4ce7b0(me+0xb990)+1)&0xfff;if(!id)assertion();
 G(void*,G(u32,me+0x68)+4*id)=slot;G(u16,input+0x40)=(u16)id;G(void*,(u8*)slot+0xc)=input;
 if(G(float,input+0x18)!=0||G(float,input+0x1c)!=0){u32 count=G(u32,me+0x170);if(count+1>16)assertion();count=G(u32,me+0x170);G(void*,me+0x174+4*count)=slot;G(u32,me+0x170)=count+1;}
 vcall<void>(me,0xb0,slot);return slot;
}
PCREG(63f3e0,drawslot);
