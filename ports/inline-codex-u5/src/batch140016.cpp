#include "ff.h"
extern "C" double VECTORCALL ext_634d70(double);
extern "C" double VECTORCALL ext_634dac(double);
extern "C" double VECTORCALL ext_634d7c(double);
extern "C" void FASTCALL ext_43e8e0(void*,void*,void*);
extern "C" void THISCALL ext_4e0d00(void*,float);
extern "C" void THISCALL ext_4dc600(void*,void*);
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" void THISCALL ext_4dce50(void*,float);
extern "C" void THISCALL ext_4dd060(void*,void*);
extern "C" void THISCALL refresh_bounds(u8* me){
 u8* node=*(u8**)(me+8);u32 id=*(u32*)(node+0x6c);if(!id)return;
 float info[15];
 vcall<void>(*(void**)(*(u8**)(G(u8*,0x70039c)+0x1aa3)+0x18),0x88,id,info);
 float x=(float)ext_634d70((double)info[9])*info[7];
 x=x*(float)ext_634dac((double)info[9]);
 float lo[3]={x,x,info[7]},hi[3]={bitsf(fbits(x)^0x80000000),bitsf(fbits(x)^0x80000000),0};
 float center[3];ext_43e8e0(center,lo,hi);ext_4e0d00(center,0.5f);ext_4dc600(*(void**)(me+8),center);
 ext_43e920(center,lo,center);
 float total=center[0]*center[0]+center[1]*center[1];total=total+center[2]*center[2];
 float radius=(float)ext_634d7c((double)total)+G(float,0x678858);
 ext_4dce50(*(void**)(me+8),radius);ext_4dd060(*(void**)(me+8),center);
}
PCREG(448590,refresh_bounds);
