#include "ff.h"
struct Callback4{u32 a,b,c,d;};
extern "C" void THISCALL ext_4678e0(u8*,Callback4);
extern "C" void THISCALL ext_467b00(u8*,float,u32);
extern "C" u8 THISCALL ext_467700(u8*);
static void THISCALL fn475140(u8* s,float time,u32 a,u32 b,u32 c,u32 d){
 if(s[0x3e8])return;
 u32 id=vcall<u32>(s,0x3b0);u32 flags=vcall<u32>(s,0x320,id);if(flags&0x100)time=0;
 u8* owner=vcall<u8*>(s,0x50c);if(owner){u32 v[3]={0,0,0};vcall<void>(owner,0x32c,v);}
 ext_4678e0(s+0x26a,Callback4{a,b,c,d});
 if(time==G(float,0x6785d0)){ext_467b00(s+0x26a,0.f,1);vcall<void>(s,0x4a8);return;}
 if(!ext_467700(s+0x26a))ext_467b00(s+0x26a,time,1);
}
PCREG(475140,fn475140);
