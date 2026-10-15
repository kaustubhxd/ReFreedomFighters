#include "ff.h"
extern "C" void FASTCALL ext_4e0d40(float*,const float*,float);
extern "C" void FASTCALL ext_43e960(float*,const float*);
extern "C" double VECTORCALL ext_634db2(double,double);
#define A36(T,o) (*(T*)(t+(o)))
static void THISCALL verlet36(u8*t,float*p,const float*force,const float*sub,float dt){
 float ratio=1.f;if(A36(s32,0xc0)>0)ratio=dt/A36(float,0xc0);A36(float,0xc0)=dt;
 s32 rb=(s32)fbits(ratio);if(rb>0x40a00000)ratio=5.f;else if(rb<0x3e4ccccd)ratio=bitsf(0x3e4ccccd);
 float acc[3];ext_4e0d40(acc,force,A36(float,0x38)*G(float,0x681374));if(sub)ext_43e960(acc,sub);
 float base=G(float,0x678858)-A36(float,0x3c);float damp=(float)ext_634db2((double)base,(double)ratio);
 u32 n=A36(u32,0x44);for(u32 i=0;i<n;i++)if(A36(u32*,0x64)[i]){
 float diff[3];for(int j=0;j<3;j++)diff[j]=p[3*i+j]-p[3*(i+n)+j];
 for(int j=0;j<3;j++)((u32*)p)[3*(i+n)+j]=((u32*)p)[3*i+j];
 for(int j=0;j<3;j++)p[3*i+j]=(diff[j]*damp+p[3*i+j])+acc[j];
 }
}
PCREG(44ef80,verlet36);
