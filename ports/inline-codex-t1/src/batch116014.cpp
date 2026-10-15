#include "ff.h"
extern "C" void* THISCALL ext_5003d0(void*,u32);
extern "C" void FASTCALL ext_43e960(void*,void*);
extern "C" void FASTCALL ext_441a60(void*,void*);
extern "C" void FASTCALL ext_4419f0(void*,void*);
extern "C" void FASTCALL ext_441940(void*,void*);
static void FASTCALL fn5df4d0(u32*out,float*in){
 double angle=crt::asin((double)in[1]);angle+=G(double,0x6b72f8);angle*=G(double,0x68c740);angle/=G(double,0x6b72f8);angle*=G(double,0x6b7300);
 u32 upper=(u16)_mm_cvttsd_si32(_mm_set_sd(angle));
 float x=in[0],z=in[2];
 if(!(x==0.f && z==0.f)){
  long double xx=x,zz=z;long double norm=fsqrt_x87(xx*xx+0.L+zz*zz),inv=1.L/norm;
  x=(float)(inv*(long double)x);z=(float)(inv*(long double)z);
 }
 float a=(float)crt::acos((double)x);
 if(0.f>z)a=G(float,0x68aef8)-a;
 a*=G(float,0x67a6ac);a/=G(float,0x67da18);a*=G(float,0x6b7308);
 u32 lower=(u16)_mm_cvtt_ss2si(_mm_set_ss(a));*out=lower|(upper<<16);
}
PCREG(5df4d0,fn5df4d0);
static void THISCALL fn502490(u8*s,u8*args){
 u32 vector[3];for(u32 i=0;i<3;i++)vector[i]=*(u32*)ext_5003d0(*(void**)(args+4),i+2);
 u8 *value=(u8*)ext_5003d0(*(void**)(args+4),1);u32 key;
 if(value[4]==3)key=*(u32*)value;
 else if(value[4]==4)key=vcall<u32>(*(void**)value,0x34);
 else{
  void *report=vcall<void*>(G(void*,0x700390),0x20,0x69c8e0u,0x111u);
  typedef void(*logfn)(void*,u32,u32);(*(logfn*)(*(u8**)report+0x2c))(report,0x69c6b0,0x69c9b0);
  typedef void(*assertfn)();assertfn hook=G(assertfn,0x7003b0);if(hook)hook();else __builtin_trap();key=0;
 }
 u8 *sys=G(u8*,0x70039c);u16 handle=(u16)vcall<u32>(*(void**)(sys+0x9b),0x114,key,0u,0x69ca10u,0x266u);
 u32 first=*(u32*)ext_5003d0(*(void**)(args+4),0);vcall<void>(*(void**)(s+0xc),0x12c,first,(u32)handle,vector);
}
PCREG(502490,fn502490);
static void THISCALL fn515270(u8*s){
 float p[3];for(int i=0;i<3;i++)((u32*)p)[i]=*(u32*)(s+0x2b3+4*i);
 ext_43e960(p,s+0x25b);ext_441a60(p,s+0x237);
 for(int i=0;i<3;i++)if((double)__builtin_fabsf(p[i])>(double)*(float*)(s+0x227+4*i))return;
 float width=*(float*)(s+0x227);u32 record[7];float *v=(float*)record;
 v[0]=width+width;v[1]=p[1];v[2]=p[2];v[3]=width*G(float,0x692b60);v[4]=p[1];v[5]=p[2];
 u8 *sys=G(u8*,0x70039c);record[6]=vcall<u32>(*(void**)(sys+0x9b),0x4c,s);
 ext_4419f0(v,s+0x237);ext_441940(v,s+0x25b);ext_4419f0(v+3,s+0x237);ext_441940(v+3,s+0x25b);
 vcall<void>(s,0x130,*(u32*)(s+0x2af),(u32)*(u16*)(s+0x2d2),record);
}
PCREG(515270,fn515270);
