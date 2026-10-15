#include "ff.h"
extern "C" void THISCALL ext_610100(u8*,u8*);
extern "C" void THISCALL ext_4e12e0(u8*,u32*,u32);
extern "C" void THISCALL ext_4e1b30(u8*);
extern "C" u8* ext_602d30();
extern "C" u8 THISCALL ext_602c50(u8*,u8*);
extern "C" u8* ext_5fa630();
static u8 THISCALL read6(u8* s,u8* stream){
 for(u32 i=0;i<6;i++) vcall<u32>(stream,0x50,s+i*4);
 return 1;
}
PCREG(524780,read6);
static void THISCALL broadcast(u8*,u8* arg,u32 value){
 if(!arg || !vcall<u8>(arg,0x1e0,0x10002eu)) return;
 for(u8* node=G(u8*,arg+0x50);node;node=G(u8*,node+0x60)){
 u8* item=G(u8*,node+0x54);
 if(vcall<u8>(item,0x1e0,0x20002du)) vcall<u32>(item,0x284,value);
 }
}
PCREG(563650,broadcast);
static void THISCALL readstate(u8* s,u8* input){
 ext_610100(s,input); u32 a,b;
 ext_4e12e0(input,&a,1); ext_4e12e0(input,&b,1);
 G(u32,s+0x18)=a ? 2 : (b!=0); ext_4e1b30(input);
}
PCREG(5a65f0,readstate);
static u8 THISCALL check(u8* s){
 u8* ctx=ext_602d30(); if(ext_602c50(ctx,s+0x28)) return 1;
 typedef u32(*log2)(u8*,u32); typedef u32(*log3)(u8*,u32,u32);
 u8* log=ext_5fa630(); G(log2,G(u8*,log)+0xc)(log,0x6b9518);
 log=ext_5fa630(); G(log2,G(u8*,log)+0xc)(log,0x6b9568);
 log=ext_5fa630(); G(log3,G(u8*,log)+0xc)(log,0x6b95b4,G(u32,s+0x98));
 log=ext_5fa630(); G(log2,G(u8*,log)+0xc)(log,0x6b9518);
 return 0;
}
PCREG(5fe4e0,check);
