#include "ff.h"
extern "C" u8* THISCALL ext_44d250(u8*,u32,u32);
extern "C" float FASTCALL ext_4e0870(void*,void*);
extern "C" void FASTCALL ext_4de520(void*,void*,void*,float);
extern "C" void FASTCALL ext_4de420(void*,void*);
static void THISCALL fn44d070(u8*s,void*render,u32 enabled,float*mat,float*pos){
 if(!enabled)return;u8*rec=ext_44d250(s,*(u32*)(s+8),0);if(!rec)return;
 if(!rec[0x40]){
  long double distance=ext_4e0870(pos,rec+0xc);
  float value=(float)(distance*(long double)G(float,0x67a288)+(long double)G(float,0x678858));
  u32 n=(u32)(s32)_mm_cvtt_ss2si(_mm_set_ss(value));
  float original=(float)((double)(s32)n+G(double,0x680aa0 + 8*(n>>31)));
  float step=G(float,0x678858)/original;u32 count=n>16?16:n;float t=G(float,0x678858);
  for(u32 i=0;i<count;i++){
   float p[3],m[9];for(int j=0;j<3;j++)p[j]=(*(float*)(rec+0xc + 4*j)+(pos[j]-*(float*)(rec+0xc + 4*j))*t);
   ext_4de520(m,rec+0x18,mat,t);vcall<void>(render,0x30,*(u32*)(s+8),m,p,0xffu);t=t-step;
  }
 }
 rec[0x40]=0;ext_4de420(rec+0x18,mat);for(int i=0;i<3;i++)*(u32*)(rec+0xc + 4*i)=((u32*)pos)[i];
}
PCREG(44d070,fn44d070);
