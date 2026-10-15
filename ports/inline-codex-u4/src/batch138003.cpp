#include "ff.h"
template<class R,class... A> static R comcall(void* s,u32 off,A... a){typedef R(STDCALL*Fn)(void*,A...);return (*(Fn*)(*(u8**)s+off))(s,a...);}
static void THISCALL pollInput(u8* s){
 if(!s[0xc]||!s[0x1b1])return;
 void* gate=vcall<void*>(G(void*,0x70039c),0x1b0);
 if(gate && vcall<u8>(gate,0xc))return;
 u32 n=0x14;void* device=*(void**)(s+0xd);
 u32 result=comcall<u32>(device,0x28,0x14u,s+0x11,&n,0u);
 if(result){
  if(result==0x8007001e || result==0x8007000c){
   s[0x1b1]=0;
   do {result=comcall<u32>(*(void**)(s+0xd),0x1c);}while(result==0x8007001e || result==0x8007000c);
   s[0x1b1]=1;
  }
  return;
 }
 u8* event=s+0x11;
 if(n==2 && *(u32*)event==0x1d && *(u32*)(s+0x25)==0xb8){
  n=1;*(u32*)(s+0x15)=*(u32*)(s+0x29);*(u32*)event=0xb8;
 }
 for(u32 i=0;i<n;++i,event+=0x14){
  u32 key=*(u32*)event;u8* sys=G(u8*,0x70039c);u8* state=sys+0xf07+key*5;
  if(event[4]&0x80){
   state[4]|=0xe0;
   s32 old=_mm_cvttss_si32(_mm_mul_ss(_mm_load_ss((float*)state),_mm_load_ss((float*)0x678620)));
   s32 elapsed=(s32)(*(u32*)(sys+0x40)-(u32)old);
   if(elapsed<0x100)state[4]|=0x10;else state[4]&=0xef;
  }else state[4]&=0x5f;
  __m128 t=_mm_cvtepi32_ps(_mm_cvtsi32_si128(*(s32*)(sys+0x40)));
  _mm_store_ss((float*)state,_mm_mul_ss(t,_mm_load_ss((float*)0x6785e4)));
 }
}
PCREG(42a180,pollInput);
