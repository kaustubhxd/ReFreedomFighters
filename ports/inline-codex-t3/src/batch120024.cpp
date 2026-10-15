#include "ff.h"
extern "C" void THISCALL ext_4db500(void *,float *);
static void THISCALL applyWind(u8 *self,u8 *geom) {
 float scale[3]={0,0,0};ext_4db500(geom,scale);
 float average=((scale[1]+scale[0])+scale[2])*G(float,0x67da00);
 u32 base,unused,flags;
 void *ctl=*(void **)(*(u8 **)(G(u8 *,0x70039c)+0x1aa3)+0x18);
 vcall<void>(ctl,0xd4,*(u32 *)(geom+0x6c),&base,&unused,&flags);
 if(flags&1u) {
  u32 width=flags>>1;
  u8 *sys=G(u8 *,0x70039c);
  s32 phaseTicks=(s32)(*(u32 *)(sys+0x40)-(u32)_mm_cvttss_si32(_mm_set_ss(average*G(float,0x67862c))));
  float phase=(float)phaseTicks*G(float,0x6785e4);
  float value=(float)crt::sin((double)phase);
  value=value* *(float *)(self+0x58);
  value=value*(float)(double)width;
  value=value+(float)(double)(u32)(base+width);
  ctl=*(void **)(*(u8 **)(sys+0x1aa3)+0x18);
  vcall<void>(ctl,0xd8,geom,value);
 }
}
PCREG(4c3740,applyWind);
