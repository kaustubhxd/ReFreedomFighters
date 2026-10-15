#include "ff.h"
extern "C" void THISCALL ext_4863c0(void*,void*);
static u8 THISCALL chamberUpdate(u8* me){
 void* actor=vcall<void*>(G(void*,me+0xc),0x10);if(!actor)return 0;
 if(!G(u32,me+0x28)){vcall<void>(actor,0x2d0,6,0);ext_4863c0(me,actor);return 0;}
 float now=(float)G(s32,G(u32,0x70039c)+0x40)*G(float,0x6785e4);if(G(float,me+0x2c)>now)return 1;
 vcall<void>(actor,0x2d0,6,0);u8* info=G(u8*,me+0x28);s32 span=(s32)(G(u32,info+0x64)-G(u32,info+0x60));float progress=0;
 if(span){float duration=(float)span/G(float,0x685270);progress=(now-G(float,me+0x2c))/duration;if(progress>G(float,0x678858)){ext_4863c0(me,actor);return 0;}}
 if(vcall<u8>(G(void*,me+8),0x474,actor)){info=G(u8*,me+0x28);float ratio=(float)G(s32,info+0x5c)/(float)G(s32,info+0x6c);vcall<void>(G(void*,me+8),0x244,(void*)info,progress,ratio,0,1);}
 vcall<void>(G(void*,me+8),0x458,0);return 1;
}
PCREG(487110,chamberUpdate);
