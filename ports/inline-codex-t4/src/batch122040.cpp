#include "ff.h"
extern "C" u32 VECTORCALL ext_633910(float);
extern "C" void THISCALL ext_5ac640(u8*,u32,u32);
extern "C" void THISCALL ext_5ac5b0(u8*,float);
static void THISCALL fn5f09b0(u8* s){
 float v=*(float*)(G(u8*,0x70039c)+0x48)*G(float,0x6b7f68);v=v+*(float*)(s+0x78);*(float*)(s+0x78)=v;
 s32 count=((s32)(*(u32*)(s+0x80)-*(u32*)(s+0x7c)))/12;
 *(u32*)(s+0x88)=ext_633910(v*G(float,0x680a54))%(u32)count;
 float phase=(float)(double)(ext_633910(*(float*)(s+0x78))&15);
 for(u32 i=0;i<28;++i){float x=(float)(double)i*G(float,0x6a60a0);float pos=*(float*)(s+0x8c)+x;pos=pos-phase;
  ext_5ac640(*(u8**)(s+4+4*i),1,(u32)_mm_cvttss_si32(_mm_set_ss(pos)));
  float q=x-phase;float alpha=_mm_cvtss_f32(_mm_max_ss(_mm_setzero_ps(),_mm_set_ss(q)));
  if(i<5)alpha=alpha*G(float,0x6b82ec);else if(i>23){alpha=G(float,0x6b82f0)-alpha;alpha=alpha*G(float,0x6b82ec);}else alpha=1;
  ext_5ac5b0(*(u8**)(s+4+4*i),alpha);
 }
}
PCREG(5f09b0,fn5f09b0);
