#include "ff.h"
extern "C" void THISCALL ext_562750(void*);
static void THISCALL fn562440(u8*s){
 vcall<void>(*(void**)(s+0x44),0xbc,1u);
 float p[3]={0,0,0};void*back=*(void**)(s+0x4c);
 if(back){p[1]=-1.0f;vcall<void>(back,0x70,p);vcall<void>(*(void**)(s+0x50),0xbc,1u);}
 void*front=*(void**)(s+0x50);
 if(front){p[1]=(float)(s32)(G(u32,(u32)G(u8*,0x70039c)+0x73)+1u);vcall<void>(front,0x70,p);vcall<void>(*(void**)(s+0x50),0xbc,1u);}
 *(u32*)(s+0xdc)=3;vcall<void>(s,0x64,0x10u);
 u8*o=vcall<u8*>(s,0x84);vcall<void>(*(void**)(o+0x6f),0x250);
 o=vcall<u8*>(s,0x84);vcall<void>(o,0x110,0x110u,0u);
 o=vcall<u8*>(s,0x84);vcall<void>(o,0x30c,1u);
 vcall<void>(s,0x68,0x10u,0u);
 o=vcall<u8*>(s,0x84);
 if(!vcall<u32>(o+0xcb,0x14)){
  o=vcall<u8*>(s,0x84);vcall<void>(o,0x114,0x10u);
  o=vcall<u8*>(s,0x84);vcall<void>(*(void**)(o+0x6f),0x254);
  o=vcall<u8*>(s,0x84);vcall<void>(o,0x30c,0u);
 }
 ext_562750(s);
}
PCREG(562440,fn562440);
