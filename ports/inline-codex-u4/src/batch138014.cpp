#include "ff.h"
extern "C" void THISCALL ext_4e0d00(void*,float);
static float clampChannel(float x){return 0.f>x?0.f:_mm_cvtss_f32(_mm_min_ss(_mm_load_ss((float*)0x68af18),_mm_set_ss(x)));}
static void THISCALL scaleColor(void* s,u32 id,float factor){
 u8* color=vcall<u8*>(s,0xc,id);
 if(color[0xd]&1)return;
 color[0xd]|=1;
 float rgb[3]={(float)color[0x12],(float)color[0x11],(float)((double)color[0x10]+G(double,0x680aa0))};
 float alpha=(float)color[0x13];ext_4e0d00(rgb,factor);alpha=alpha*factor;
 float red=clampChannel(rgb[0]),green=clampChannel(rgb[1]),blue=clampChannel(rgb[2]);alpha=clampChannel(alpha);
 u32 g=(u32)_mm_cvttss_si32(_mm_set_ss(green*G(float,0x6b7248)))&0xff00u;
 u32 r=(u32)_mm_cvttss_si32(_mm_set_ss(red*G(float,0x6c3e1c)))&0xff0000u;
 u32 b=(u32)_mm_cvttss_si32(_mm_set_ss(blue))&0xffu;
 u32 a=(u32)_mm_cvttss_si32(_mm_set_ss(alpha*G(float,0x6c3e20)))&0xff000000u;
 *(u32*)(color+0x10)=g|r|b|a;
}
PCREG(656970,scaleColor);
