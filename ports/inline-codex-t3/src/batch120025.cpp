#include "ff.h"
extern "C" void FASTCALL ext_4e09b0(float *);
extern "C" void FASTCALL ext_451890(float *,const float *,float);
static void *standTable() {return *(void **)(G(u8 *,0x70039c)+0x9b);}
static void STDCALL gunStandPosition(u32 ref,u32 unused,float *out) {
 void *nest=vcall<void *>(standTable(),0x58,ref);
 u32 center;u8 *vt=*(u8 **)nest;
 u16 msg=(u16)vcall<u32>(standTable(),0x114,0x6a585cu,0u,0x6a57fcu,0x3f0u);
 typedef void(THISCALL *Send)(void *,u32,u32 *,u32);
 (*(Send *)(vt+0x128))(nest,msg,&center,0);
 void *geom=vcall<void *>(standTable(),0x58,center);
 float m[9],p[3];vcall<void>(geom,0x80,m,p);
 for(u32 i=0;i<3;++i) {float t=m[3+i];m[3+i]=m[6+i];m[6+i]=t;}
 ext_4e09b0(m);ext_451890(p,m,58.0f);ext_451890(p,m+3,-106.0f);ext_451890(p,m+6,3.66f);
 __builtin_memcpy(out,p,12);
}
PCREG(5520c0,gunStandPosition);
