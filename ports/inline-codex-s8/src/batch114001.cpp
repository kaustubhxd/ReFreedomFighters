#include "ff.h"
extern "C" u32 THISCALL ext_51aba0(void *,void *);
static u32 THISCALL register522940(void *s,u8 *a) {
 const u32 methods[]={0x522820,0x51b0e0,0x522850,0x5227f0,0x5227c0,0x610100,0x522910,0x522770,0x522880,0x5228b0,0x5228e0};
 for(u32 i=0;i<11 && a[12];i++) {
  u32 n=G(u32,0x701a78);
  if(n<50) {G(u32,0x701a80+n*4)=methods[i];G(u32,0x701a78)=n+1;}
  else {vcall<void>(s,0x44,0x6a0744); ((void(*)())G(u32,0x7003b0))();}
 }
 a[12]=0;
 return ext_51aba0(s,a);
}
PCREG(522940,register522940);
