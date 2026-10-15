#include "ff.h"
extern "C" float THISCALL ext_4e5e80(u8*);
static void THISCALL fn4bd040(u8* s,u32 ignored,u8* stream){
 float a=ext_4e5e80(stream);if(0.f>a)a=0.f-a;a=a/G(float,0x67da20);
 typedef double(VECTORCALL* Pow)(double,double);
 double power=(*(Pow*)0x67634c)(G(double,0x692790),(double)a);
 double one=G(double,0x678610);*(float*)(s+0x58)=(float)(one-one/power);
 a=ext_4e5e80(stream);*(float*)(s+0x5c)=0.f>a?0.f:a;
 *(float*)(s+0x60)=ext_4e5e80(stream);
 a=ext_4e5e80(stream);*(float*)(s+0x64)=0.f>a?0.f:a;
 a=ext_4e5e80(stream);*(float*)(s+0x68)=0.f>a?0.f:a;
 if(*(float*)(s+0x64)>*(float*)(s+0x68))*(u32*)(s+0x68)=*(u32*)(s+0x64);
 a=ext_4e5e80(stream);*(float*)(s+0x78)=G(float,0x67da00)>a?bitsf(0x3c23d70a):a;
 *(u32*)(s+0x48)=0;*(u32*)(s+0x4c)=0x3f800000;*(u32*)(s+0x54)=0x3f800000;*(u32*)(s+0x50)=0x3f800000;
 *(u32*)(s+0x74)=*(u32*)(s+0x78);*(u32*)(s+0x6c)=1;*(u32*)(s+0x70)=0;*(u32*)(s+0x7c)=0xbf800000;
}
PCREG(4bd040,fn4bd040);
