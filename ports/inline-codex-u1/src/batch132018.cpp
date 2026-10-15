#include "ff.h"
extern "C" void THISCALL ext_5233a0(void*,float*,float);
extern "C" float FASTCALL ext_4e0030(void*,void*);
static void norm18(float* v){
 if(v[0]==0.0f && v[2]==0.0f)return;
 long double l=(long double)v[0]*v[0];l=l+(long double)v[1]*v[1];l=l+(long double)v[2]*v[2];
 long double inv=1.0L/fsqrt_x87(l);for(int k=0;k<3;++k)v[k]=(float)((long double)v[k]*inv);
}
static u8 THISCALL aligned18(u8* self,float time){
 float a[3]={*(float*)(self+0x6c),0,*(float*)(self+0x74)};norm18(a);
 float b[3];ext_5233a0(*(void**)(self+0x5c),b,time);b[1]=0;norm18(b);
 float angle=ext_4e0030(a,b);return G(float,0x683770)>angle;
}
PCREG(5133d0,aligned18);
