#include "ff.h"
extern "C" float THISCALL ext_4e5e80(u8*);
static void THISCALL fn4bbd00(u8* s,u8* stream){
 float a=ext_4e5e80(stream);if(0.f>a)a=0.f-a;a=a/G(float,0x67da20);
 typedef double(VECTORCALL* Pow)(double,double);
 double power=(*(Pow*)0x67634c)(G(double,0x692790),(double)a);
 double one=G(double,0x678610);*(float*)(s+0x50)=(float)(one-one/power);
 a=ext_4e5e80(stream);*(float*)(s+0x54)=0.f>a?0.f:a;
 *(float*)(s+0x58)=ext_4e5e80(stream);
 a=ext_4e5e80(stream);*(float*)(s+0x5c)=0.f>a?0.f:a;
 a=ext_4e5e80(stream);*(float*)(s+0x60)=0.f>a?0.f:a;
 if(*(float*)(s+0x5c)>*(float*)(s+0x60))*(u32*)(s+0x60)=*(u32*)(s+0x5c);
 a=ext_4e5e80(stream);*(float*)(s+0x6c)=G(float,0x67da00)>a?bitsf(0x3c23d70a):a;
}
PCREG(4bbd00,fn4bbd00);
