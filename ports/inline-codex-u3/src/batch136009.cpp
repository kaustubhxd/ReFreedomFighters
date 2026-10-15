#include "ff.h"
static void THISCALL fn51d8f0(u8*s){
 const u32 off[3]={0x2c3,0x2ec,0x315};
 for(int i=0;i<3;i++)vcall<void>(s+off[i],8,s+0x276+4*i);
 for(int i=0;i<3;i++)if(vcall<bool>(s+off[i],0x20)){
  float random=vcall<float>(G(void*,0x70039c),0x1c4,0x69f8b8u,0x262u+6u*i);
  float value=(float)((long double)random*(long double)*(float*)(s+0x28e + 4*i));
  *(float*)(s+0x282+4*i)=value;
  vcall<void>(s+off[i],4,*(float*)(s+0x276+4*i),value,0u);
 }
}
PCREG(51d8f0,fn51d8f0);
