#include "ff.h"
extern "C" void FASTCALL ext_441940(float*,const float*);
extern "C" void THISCALL ext_461570(void*,float,u32,u32);
#define A19(T,p,o) (*(T*)((u8*)(p)+(o)))
static u8 THISCALL throw19(u8*t){
 u8*sys=G(u8*,0x70039c);A19(float,t,0x10)=(float)A19(s32,sys,0x40)*G(float,0x6785e4);t[0x14]=0;
 A19(u32,t,0x15)=0;A19(u32,t,0x19)=0x42c80000;A19(u32,t,0x1d)=0;
 void*actor=A19(void*,t,8);vcall<void>(actor,0x4cc,t+0x15);
 long double r1=vcall<long double>(G(void*,0x70039c),0x1c0,0x6b80b4u,0xcfu);
 float x=(float)((long double)G(float,0x67cd40)-r1*(long double)G(float,0x67da2c));
 long double r2=vcall<long double>(G(void*,0x70039c),0x1c0,0x6b80b4u,0xcfu);
 float z=(float)((long double)G(float,0x67cd40)-r2*(long double)G(float,0x67da2c));float d[3]={x,0,z};ext_441940((float*)(t+0x15),d);
 u8*item=A19(u8*,t,0xc);
 void*anim=vcall<void*>(actor,0x228,item,1u,0u,0xbf800000u,0x3f800000u);if(!anim)return 0;
 float span=(float)(s32)(A19(u32,item,0x64)-A19(u32,item,0x60));ext_461570(anim,span,0x465710u,0);
 float wait=G(float,0x6b80ec)/(float)A19(s32,item,0x6c);wait=wait*G(float,0x67862c);s32 delay=_mm_cvttss_si32(_mm_set_ss(wait));
 u8*s=G(u8*,0x70039c);A19(float,t,0x10)=(float)(s32)(A19(u32,s,0x40)-(u32)delay)*G(float,0x6785e4);
 u32 id=vcall<u32>(A19(void*,s,0x9b),0x114,0x6a5694u,0u,0x6b80b4u,0xd8u,0u,0u);
 vcall<void>(A19(void*,t,8),0x128,(u32)(u16)id);return 1;
}
PCREG(5eb380,throw19);
