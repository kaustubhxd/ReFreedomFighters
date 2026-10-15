#include "ff.h"
extern "C" void THISCALL ext_4e0d80(float *,float);
extern "C" u32 THISCALL ext_5ceed0(void *,void *,const void *,const void *,u32,u32,u32);
extern "C" void THISCALL ext_5d0bd0(void *,const void *,float,u32);
static void THISCALL setSlowPointer(u8 *self,u32 on) {
 u8 c=self[0xb46]?0:(u8)on;
 bool change=c?!self[0xb45]:self[0xb45]!=0;
 if(change) {
  *(u32 *)(self+0xa54)=*(u32 *)(self+0xae9);
  *(u32 *)(self+0xa5c)=*(u32 *)(self+0xaed);
  if(c || G(u8 *,0x70039c)[0x6c]) {
   long double length=vcall<long double>(*(void **)(self+0xb54),0xac);
   ext_4e0d80((float *)(self+0xa72),(float)(length+G(float,0x67ff1c)));
   ext_5ceed0(self,self+0xa7e,self+0xcad,self+0xa72,0x10u,1u,1u);
   if(c) __builtin_memcpy(*(u8 **)(self+0xb54)+0x4cb,self+0xa7e,12);
   else ext_5d0bd0(self,self+0xa7e,bitsf(0x3f860a92),0);
  }
 }
 self[0xb45]=c!=0;
}
PCREG(5d24c0,setSlowPointer);
