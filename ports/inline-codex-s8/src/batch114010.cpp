#include "ff.h"
extern "C" u32 THISCALL ext_503770(void *,void *);
static u32 THISCALL register505a00(void *s,u8 *a) {
 const u32 methods[]={0x504880,0x5059f0,0x50487b,0x5059f0,0x505df0,0x50488a,0x54dcd0,0x504885,0x50488f,0x504960,0x504c90,0x505110};
 for(u32 i=0;i<12 && a[12];i++) {
  u32 n=G(u32,0x700f7c);
  if(n<50) {G(u32,0x700f80+n*4)=methods[i];G(u32,0x700f7c)=n+1;}
  else {vcall<void>(s,0x44,0x69cd14); ((void(*)())G(u32,0x7003b0))();}
 }
 a[12]=0;
 return ext_503770(s,a);
}
PCREG(505a00,register505a00);
