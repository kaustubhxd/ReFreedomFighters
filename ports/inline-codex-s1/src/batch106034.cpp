#include "ff.h"
extern "C" void ext_633654(u32);
static u32 THISCALL choose_minimum(u8* me){
 u32 selected=0xffffffff;
 s32 n=*(s32*)(me+0x44);u32 off=*(u32*)(me+0x48);
 if(n && off){
  u8* tied[16];tied[0]=*(u8**)(me+4);u8 least=tied[0][off];int count=1;
  for(int i=1;i<n;i++){
   u8* item=*(u8**)(me+4+4*i);u8 value=item[off];
   if(value<least){least=value;tied[0]=item;count=1;}
   else if(value==least)tied[count++]=item;
  }
  long double r=vcall<long double>(G(void*,0x70039c),0x1c0,0x6b3d34,0x30);
  float product=(float)(r*(long double)(float)count);
  s32 idx=_mm_cvttss_si32(_mm_set_ss(product));if(idx==count && idx)idx--;
  u8* ptr=tied[idx];ptr[*(u32*)(me+0x48)]++;selected=(u32)ptr;
 }
 ext_633654(0);return selected;
}
PCREG(5c2cb0,choose_minimum);
