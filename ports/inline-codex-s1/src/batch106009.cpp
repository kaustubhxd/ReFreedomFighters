#include "ff.h"
extern "C" u32 THISCALL ext_45b620(void*);
static u32 THISCALL submit(u8* me,u8* input,u32 arg,float x,float y,u32 flags) {
 if(*(u32*)(me+0x44)==0xffffffff){
  void* service=vcall<void*>(*(void**)(G(u8*,0x70039c)+0x190f),0x20);
  *(u32*)(me+0x44)=vcall<u32>(service,0x38,me+0x48,*(u32*)(me+0x1c));
 }
 void* service=vcall<void*>(*(void**)(G(u8*,0x70039c)+0x190f),0x20);
 u32 result=vcall<u32>(service,0x3c,input+0x28,input+0xc,*(u32*)(me+0x44),arg,x,y,flags);
 if(result){u32 i=ext_45b620(me);(*(u32**)(me+0x40))[i]=result;return i;}
 return result;
}
PCREG(45bb10,submit);
