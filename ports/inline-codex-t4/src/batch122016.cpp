#include "ff.h"
static void STDCALL fn61a700(u32* out,u32 unused,u32 n){
 for(u32 i=0;i<n;++i){
  s32 v[4];for(u32 j=0;j<4;++j){float f=G(float,0x812640+16*i+4*j)*G(float,0x6bdf00);v[j]=_mm_cvttss_si32(_mm_set_ss(f));}
  for(u32 j=0;j<3;++j){if(v[j]<0)v[j]=0;else if(v[j]>255)v[j]=255;}
  u32 word=(u32)v[3];word=(word<<8)+(u32)v[0];word=(word<<8)+(u32)v[1];word=(word<<8)+(u32)v[2];out[i]=word;
 }
}
PCREG(61a700,fn61a700);
