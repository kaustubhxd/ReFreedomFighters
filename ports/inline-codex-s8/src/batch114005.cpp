#include "ff.h"
static void THISCALL register50a060(void *s,u8 *a) {
 const u32 methods[]={0x5098b0,0x509970,0x509840,0x509870,0x509c20,0x509d10,0x509d10,0x509b10,0x509aa0,0x509ff0,0x5097b0,0x509e50};
 for(u32 i=0;i<12 && a[12];i++) {
  u32 n=G(u32,0x701128);
  if(n<50) {G(u32,0x701130+n*4)=methods[i];G(u32,0x701128)=n+1;}
  else {vcall<void>(s,0x44,0x69d20c); ((void(*)())G(u32,0x7003b0))();}
 }

}
PCREG(50a060,register50a060);
