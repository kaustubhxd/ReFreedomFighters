#include "ff.h"
extern "C" void FASTCALL ext_43e920(float*,const float*,const float*);
extern "C" int THISCALL ext_530e80(void*,u16*,const u16*,u32,u32,float);
extern "C" int THISCALL ext_530bf0(void*,u16*,float*,u8*);
extern "C" u8 THISCALL ext_52dfc0(void*,const u16*,const u16*);
static u8 THISCALL worldLine(u8* self,float* a,float* b,u32 snap){
 u8 it[0x30]; *(u8**)it=self; *(u8**)(it+4)=self+0x96; *(u32*)(it+8)=0x40;
 float extent[3]; ext_43e920(extent,(float*)(self+0x12),(float*)(self+6));
 u16 c[3],ca[4],cb[4];
 float x=(a[0]-*(float*)(self+6))/extent[0]*(float)*(s32*)(self+0x3c);
 float y=(a[1]-*(float*)(self+10))/extent[1]*(float)*(s32*)(self+0x44);
 float z=(a[2]-*(float*)(self+14))/extent[2]*(float)*(s32*)(self+0x40);
 c[0]=(u16)_mm_cvtt_ss2si(_mm_set_ss(x)); c[1]=(u16)_mm_cvtt_ss2si(_mm_set_ss(z)); c[2]=(u16)_mm_cvtt_ss2si(_mm_set_ss(y));
 if(!ext_530e80(self,ca,c,10,1,1.0f))return 0;
 u8 flag; if(!ext_530bf0(it,cb,b,&flag))return 0;
 if((u8)snap){
  float e[3]; ext_43e920(e,(float*)(self+0x12),(float*)(self+6));
  float ay=e[1]*(float)(u16)(*(u32*)((u8*)ca+4)+1)/(float)*(s32*)(self+0x44)+*(float*)(self+10);
  ext_43e920(e,(float*)(self+0x12),(float*)(self+6));
  float by=e[1]*(float)(u16)(*(u32*)((u8*)cb+4)+1)/(float)*(s32*)(self+0x44)+*(float*)(self+10);
  a[1]=ay; b[1]=by;
 }
 return ext_52dfc0(self,ca,cb);
}
PCREG(52e0a0,worldLine);
