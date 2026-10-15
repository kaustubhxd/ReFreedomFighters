#include "ff.h"
extern "C" void THISCALL ext_4db7c0(void*,float*);
extern "C" void THISCALL ext_4e0d00(float*,float);
extern "C" void THISCALL ext_53f230(void*,void*,float*);
extern "C" void THISCALL ext_634e90(void*,u32);
static void THISCALL fn53f0e0(u8*s,u8**arg){
 float v[3];for(int i=0;i<3;i++)v[i]=*(float*)(*arg+0xc+4*i);
 if(v[0]!=0 || v[1]!=0 || v[2]!=0){
  long double x=v[0],y=v[1],z=v[2];long double length=fsqrt_x87((x*x+y*y)+z*z);long double inv=1.0L/length;
  for(int i=0;i<3;i++)v[i]=(float)((long double)v[i]*inv);
 }
 float dimensions[3];ext_4db7c0(*(void**)(*(u8**)(s+0x44)+8),dimensions);
 for(int i=0;i<3;i++)if(dimensions[i]<G(float,0x679544))dimensions[i]=5.0f;
 ext_4e0d00(v,G(float,0x6ec390));ext_53f230(s,*arg+0x28,v);
 s[0x10f]=1;*(u32*)(s+0xf7)=1000;*(u32*)(s+0xfb)=0x45480000;*(u32*)(s+0xff)=0x43c80000;*(u32*)(s+0x13d)=*(u32*)(s+0x141);ext_634e90(s,0x10);
}
PCREG(53f0e0,fn53f0e0);
