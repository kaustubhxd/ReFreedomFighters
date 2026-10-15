#include "ff.h"
extern "C" void *ext_41e290(u32);
extern "C" void THISCALL ext_4e3d60(void *,const u8 *);
extern "C" void THISCALL ext_4e3360(void *,const u32 *);
static u8 *THISCALL loadFiveEntries(u8 *self,u8 *p) {
 vcall<void>(self,0x330);
 for(u32 i=0;i<5;++i) {
  u32 size=*(u32 *)p;
  if(size) {
   u32 f=*(u32 *)(p+4),v[3]={*(u32 *)(p+8),*(u32 *)(p+12),*(u32 *)(p+16)};
   p+=32;
   u8 *e=(u8 *)ext_41e290(24);
   if(e) {__builtin_memset(e,0,24);*(u32 *)e=0x67d138;}
   ext_4e3d60(e,p);*(u32 *)(e+16)=f;ext_4e3360(e,v);
   *(u8 **)(self+0x5d+4*i)=e;
   p+=(size+15u)&~15u;
   vcall<void>(e,0x14,0x443ac0u);
  } else {*(u32 *)(self+0x5d+4*i)=0;p+=16;}
 }
 return p;
}
PCREG(443570,loadFiveEntries);
