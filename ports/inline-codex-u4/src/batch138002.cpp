#include "ff.h"
extern "C" void THISCALL ext_534010(void*,float);
static s32 scaleTime(s32 x,bool second){
 __m128 a=_mm_cvtepi32_ps(_mm_cvtsi32_si128(x));
 a=_mm_mul_ss(a,_mm_load_ss((float*)0x6785e4));
 if(second)a=_mm_mul_ss(a,_mm_load_ss((float*)0x678620));
 return _mm_cvttss_si32(a);
}
static void THISCALL togglePause(u8* s,u8 enabled){
 if(s[0x50a9]==enabled)return;
 s[0x50a9]=enabled;
 u8* sys=G(u8*,0x70039c);
 if(enabled)*(u32*)(s+0x50b6)=*(u32*)(sys+0x1c);
 else *(u32*)(s+0x50b6)=*(u32*)(sys+0x1c)-*(u32*)(s+0x50b6);
 u32 iter[2];void* tab=s+0x53b2;
 vcall<void>(tab,0x4c,iter);
 u32 id=vcall<u32>(tab,0x5c,iter);
 while(iter[0]){
  u8* actor=vcall<u8*>(*(void**)(G(u8*,0x70039c)+0x9b),0x60,id);
  if(actor){
   if(enabled)*(u32*)(actor+0x40)|=0x40;
   else if(*(u32*)(actor+0x40)&0x40){
    *(u32*)(actor+0x40)&=~0x40u;
    *(s32*)(actor+0x6c)=scaleTime(*(s32*)(actor+0x6c),true);
   }
  }
  id=vcall<u32>(tab,0x5c,iter);
 }
 if(!enabled){
  __m128 t=_mm_cvtepi32_ps(_mm_cvtsi32_si128(*(s32*)(s+0x50b6)));
  ext_534010(s+0x8b,_mm_cvtss_f32(_mm_mul_ss(t,_mm_load_ss((float*)0x6785e4))));
 }
}
PCREG(5380a0,togglePause);
