#include "ff.h"
extern "C" void THISCALL ext_4e1b60(void *);
extern "C" void *THISCALL ext_5003d0(void *,u32);
extern "C" void FASTCALL ext_441a60(float *,const float *);
extern "C" void THISCALL ext_5002f0(void *,u32);
static void THISCALL scriptRayTest(u8 *self,u8 *args) {
 u8 ray[0x70];ext_4e1b60(ray);*(u32 *)(ray+0x44)=0;
 float frame[12];vcall<void>(*(void **)(self+0x14),0x80,frame,frame+9);
 frame[10]+=G(float,0x685270);
 __builtin_memcpy(ray,frame+9,12);
 u32 *z=(u32 *)ext_5003d0(*(void **)(args+4),2);
 u32 *y=(u32 *)ext_5003d0(*(void **)(args+4),1);
 u32 *x=(u32 *)ext_5003d0(*(void **)(args+4),0);
 u32 dir[3]={*x,*y,*z};ext_441a60((float *)dir,frame);
 __builtin_memcpy(ray+12,dir,12);
 void *phys=*(void **)(*(u8 **)(G(u8 *,0x70039c)+0x9b)+0xadc);
 u32 hit=vcall<u8>(phys,0x2e0,ray,0u,1u,0xffffffffu,1u,0u);
 ext_5002f0(ext_5003d0(*(void **)(args+8),0),hit);
}
PCREG(504e70,scriptRayTest);
