#include "ff.h"
extern "C" void FASTCALL ext_4de4b0(void*,void*,void*);
extern "C" void THISCALL ext_4e0d00(void*,float);
extern "C" void FASTCALL ext_4419f0(void*,void*);
extern "C" void FASTCALL ext_4de480(void*,void*);
static void THISCALL updateGeometry(u8* s,void* renderer,u32 arg,void* basis,float* pos,u32 flags){
 if(!*(u32*)(s+0x3a))return;
 float* old=(float*)(s+0x46);
 if(old[0]!=pos[0] || old[1]!=pos[1] || old[2]!=pos[2])s[0x90]=1;
 if(s[0x90]){
  for(int i=0;i<3;++i)old[i]=pos[i];
  float matrix[9]; ext_4de4b0(matrix,basis,*(void**)(s+8));
  float adjusted[3]={pos[0]-G(float,0x67a6ac),pos[1]-G(float,0x67a6ac),pos[2]};
  vcall<void>(s,0x220,renderer,arg,matrix,adjusted,s+0x76,s+0x82,s+0x52);
  ext_4e0d00(s+0x6a,*(float*)(s+0x82));
  long double f=vcall<long double>(renderer,8);
  float product=(float)(f*(long double)*(float*)(s+0x86));
  ext_4e0d00(s+0x5e,bitsf(fbits(product)^G(u32,0x67af40)));
  ext_4419f0(s+0x76,s+0x52);
  ext_4de480(s+0x52,*(void**)(s+8));
  *(u32*)(s+0x7a)^=G(u32,0x67af40);
  s[0x90]=0;
 }
 for(u32 i=0;i<*(u32*)(s+0x32);++i)
  vcall<void>(renderer,0x2c,(*(u32**)(s+0x36))[i],*(u8**)(s+0x3a)+i*8,s+0x52,s+0x76,flags);
}
PCREG(4efe00,updateGeometry);
