#include "ff.h"
extern "C" {
 u32 THISCALL ext_50b620(void*);u32 THISCALL ext_50d880(void*);u32 THISCALL ext_510f30(void*);u32 THISCALL ext_5117d0(void*);
 u32 THISCALL ext_5045c0(void*);u32 THISCALL ext_5060f0(void*);u32 THISCALL ext_509630(void*);u32 THISCALL ext_50a4a0(void*);
}
static u32 THISCALL dispatch(void*,u32 name,void*target){
 const u32 names[8]={0x69c770,0x69c77c,0x69c784,0x69c790,0x685230,0x69c754,0x69c75c,0x69c768};typedef u32(THISCALL *Fn)(void*);const Fn fns[8]={ext_50b620,ext_50d880,ext_510f30,ext_5117d0,ext_5045c0,ext_5060f0,ext_509630,ext_50a4a0};typedef s32(*Compare)(u32,u32);
 for(u32 i=0;i<8;++i)if(!G(Compare,0x676414)(names[i],name))return fns[i](target);
 typedef void(*Assert)();auto a=G(Assert,0x7003b0);if(a)a();else asm volatile("int3");return 0;
}
PCREG(4fff00,dispatch);
