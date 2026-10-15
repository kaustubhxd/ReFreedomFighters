#include "ff.h"
extern "C" void* THISCALL ext_44d250(void*,u32,u32);
extern "C" float FASTCALL ext_4e0870(void*,void*);
extern "C" void FASTCALL ext_4de520(void*,void*,void*,float);
extern "C" void FASTCALL ext_4de420(void*,void*);
static void THISCALL sample(void* self,u32 a,u32 b,void* target,u32 enabled,void* frame,float* pos,u32 unused){
 if(!enabled) return;
 u8* s=(u8*)ext_44d250(self,a,b); if(!s)return;
 if(!s[0x40]){
  float v=(float)((long double)ext_4e0870(pos,s+0xc)*G(float,0x67a288)+G(float,0x678858));
  u32 count=(u32)(s32)v;
  float step=G(float,0x678858)/(float)count;
  u32 n=count>16?16:count;
  float t=G(float,0x678858);
  for(u32 i=0;i<n;++i){
   float p[3]; for(int k=0;k<3;++k) p[k]=(pos[k]-((float*)(s+0xc))[k])*t+((float*)(s+0xc))[k];
   float f[9]; ext_4de520(f,s+0x18,frame,t);
   u8* info=*(u8**)((u8*)self+8);
   vcall<void>(target,0x50,*(u32*)((u8*)self+0x470+4*i),f,p,info+0x30,*(float*)(info+0x4c));
   t=t-step;
  }
 }
 s[0x40]=0; ext_4de420(s+0x18,frame);
 for(int k=0;k<3;++k) ((u32*)(s+0xc))[k]=((u32*)pos)[k];
}
PCREG(44d360,sample);
