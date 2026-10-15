#include "ff.h"
extern "C" u32 THISCALL ext_519ea0(void*,void*);
static u32 THISCALL heliMethods(void *self,u8 *arg) {
 const u32 entries[]={0x51e900,0x51e910,0x51ec70,0x51e940,0x51ea20,0x51eaf0,0x51eb80,0x51eab0,0x51ebe0,0x51ec40,0x51e840,0x51eb50,0x51ea70,0x51ecd0,0x51ed00,0x51e870};
 for(unsigned i=0;i<16 && arg[12];++i){
  u32 n=G(u32,0x7018d8);
  if(n<50){G(u32,0x7018e0+4*n)=entries[i];G(u32,0x7018d8)=n+1;}
  else {vcall<void>(self,0x44,0x69fab4u); ((void(*)())G(u32,0x7003b0))();}
 }
 arg[12]=0;
 return ext_519ea0(self,arg);
}
PCREG(51ed20,heliMethods);
