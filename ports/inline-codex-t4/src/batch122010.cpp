#include "ff.h"
extern "C" void THISCALL ext_4dffb0(u8*,float);
extern "C" void FASTCALL ext_4dfd80(float*,u8*);
extern "C" float THISCALL ext_4dfda0(u8*);
static u32 THISCALL fn4f3b20(u8* s){
 u8* sys=G(u8*,0x70039c);
 *(float*)(s+0x87)=*(float*)(sys+0x9e7)-*(float*)(s+0x7f);
 u8* sys2=G(u8*,0x70039c);
 *(float*)(s+0x8b)=*(float*)(sys2+0x9eb)-*(float*)(s+0x83);
 *(u32*)(s+0x7f)=*(u32*)(sys+0x9e7);*(u32*)(s+0x83)=*(u32*)(sys2+0x9eb);
 ext_4dffb0(s+0x87,*(float*)(s+0x97));
 float v[2];vcall<void>(s,0x308,v);ext_4dfd80(v,s+0x87);
 float len=ext_4dfda0(s+0x87);
 if(len==G(float,0x6785d0)&&!s[0x63b])return *(u32*)(s+0x1d3);
 s[0x63b]=0;return vcall<u32>(s,0x304,v);
}
PCREG(4f3b20,fn4f3b20);
