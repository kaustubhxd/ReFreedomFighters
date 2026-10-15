#include "ff.h"
extern "C" void THISCALL ext_658c20(u8*,float);
static void THISCALL fn610350(u8* s,float gamma){
 ext_658c20(s,gamma);u16 ramp[768];
 typedef double(VECTORCALL* Pow)(double,double);
 for(u32 i=0;i<256;++i){
  float value=0;
  if(i){float x=(float)i*G(float,0x697890);double p=(*(Pow*)0x67634c)((double)x,(double)gamma);value=(float)(p*G(double,0x6b7300));}
  __m128 out=_mm_setzero_ps();
  if(!(value<0))out=_mm_min_ss(_mm_set_ss(G(float,0x6b7308)),_mm_set_ss(value));
  u16 v=(u16)_mm_cvttss_si32(out);ramp[i]=v;ramp[i+256]=v;ramp[i+512]=v;
 }
 u8* dev=*(u8**)(s+0x1377);
 typedef void(STDCALL*Set)(u8*,u32,u16*);(*(Set*)(*(u8**)dev+0x48))(dev,0,ramp);
}
PCREG(610350,fn610350);
