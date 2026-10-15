#include "ff.h"
extern "C" void THISCALL ext_562440(void*);
extern "C" void THISCALL ext_4db500(void*,void*);
static void THISCALL layout(u8* me){
 ext_562440(me);void* child=vcall<void*>(G(void*,me+0x54),0x25c,0x6a66cc,0);
 u32 engine=G(u32,0x70039c);float dimensions[2]={(float)(G(s32,engine+0x6f)/16+1),(float)(G(s32,engine+0x73)/16+1)};
 vcall<void>(child,0x258,(void*)dimensions,0);float pos[3];ext_4db500(G(void*,G(u32,me+0x54)+8),pos);pos[0]=bitsf(fbits(pos[0])^0x80000000);pos[1]=bitsf(fbits(pos[1])^0x80000000);vcall<void>(child,0x70,(void*)pos);
 u8* state=G(u8*,me+0x94);if(state&&G(u8,state+0x103f)){void* cfg=vcall<void*>(G(void*,G(u32,0x70039c)+0x9b),0x134);u8 flag=0;vcall<void>(cfg,0x90,0x6a8028,(void*)&flag);G(u8,me+0x199)=flag;}
}
PCREG(57a8e0,layout);
