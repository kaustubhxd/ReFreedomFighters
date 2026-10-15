#include "ff.h"
extern "C" void FASTCALL ext_4de4b0(float*,const float*,const float*);
extern "C" void FASTCALL ext_4de420(float*,const float*);
extern "C" void FASTCALL ext_4e2c60(float*,float*);
extern "C" void FASTCALL ext_43e920(float*,const float*,const float*);
extern "C" void FASTCALL ext_43e8e0(float*,const float*,const float*);
extern "C" void FASTCALL ext_441a60(float*,const float*);
extern "C" void FASTCALL ext_441940(float*,const float*);
extern "C" void THISCALL ext_6359d0(void*);
#define A17(T,o) (*(T*)(t+(o)))
static void THISCALL bounds17(u8*t,const float*p,const float*m,const float*h,u8 force){
 t[0x18]=1;
 if(!force){float rel[9],half[3]={h[0],h[1],h[2]},delta[3],lo[3],hi[3];
 ext_4de4b0(rel,m,(float*)(t+0x29));ext_4e2c60(rel,half);ext_43e920(delta,p,(float*)(t+0x1d));ext_441a60(delta,rel);ext_43e920(lo,delta,half);ext_43e8e0(hi,delta,half);
 bool inside=true;for(int i=0;i<3;i++){float b=A17(float,0x4d+4*i);if(!(lo[i]>=-b)||!(b>=hi[i]))inside=false;}if(inside)return;
 }
 for(int i=0;i<3;i++)A17(u32,0x1d+4*i)=((const u32*)p)[i];
 ext_4de420((float*)(t+0x29),m);
 for(int i=0;i<3;i++)A17(u32,0x4d+4*i)=((const u32*)h)[i];
 float margin[3]={A17(float,0x66),A17(float,0x66),A17(float,0x66)};ext_441940((float*)(t+0x4d),margin);
 if(t[0x18]){vcall<void>(A17(void*,0x14),0xc);ext_6359d0(t);}
}
PCREG(635eb0,bounds17);
