#include "ff.h"
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" void FASTCALL ext_441a60(void*,void*);
extern "C" void FASTCALL ext_43e8e0(void*,void*,void*);
extern "C" void FASTCALL ext_441970(void*,void*,void*);
extern "C" void FASTCALL ext_441940(void*,void*);
static double abs13(float f){return _mm_cvtsd_f64(_mm_and_pd(_mm_set_sd((double)f),*(const __m128d*)0x67cd50));}
static u8 THISCALL eject(u8* self,float* point,float* extra){
 if(!self[0xa4])return 0;
 float v[3],extent[3];ext_43e920(v,point,self+0x8c);ext_441a60(v,self+0x68);ext_43e8e0(extent,extra,self+0x98);
 if(!((double)extent[0]>abs13(v[0]) && (double)extent[1]>abs13(v[1]) && (double)extent[2]>abs13(v[2])))return 0;
 float dx=extent[0]-v[0];if(v[0]<0.0f)dx=bitsf(fbits(extent[0])^0x80000000u)-v[0];
 float dz=extent[2]-v[2];if(v[2]<0.0f)dz=bitsf(fbits(extent[2])^0x80000000u)-v[2];
 float epsilon=G(float,0x67da00);
 if(abs13(dz)>abs13(dx))v[0]=v[0]+(dx<0.0f?dx-epsilon:dx+epsilon);
 else v[2]=v[2]+(dz<0.0f?dz-epsilon:dz+epsilon);
 ext_441970(point,v,self+0x68);ext_441940(point,self+0x8c);return 1;
}
PCREG(4ea900,eject);
