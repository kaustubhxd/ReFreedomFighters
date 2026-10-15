#include "ff.h"
static u32 packbyte(float f){s32 x=_mm_cvttss_si32(_mm_set_ss(f));return x<0?0u:x>255?255u:(u32)x;}
extern "C" void STDCALL copy_vertex_color(u8* dst,const u8* src,u32 count){
 u32 group=0;
 do{
  __m128 scale=_mm_load_ps((float*)0x6bde60);
  float c0[4],c1[4],c2[4],c3[4];
  _mm_storeu_ps(c0,_mm_mul_ps(_mm_load_ps((float*)(0x812a40+0x300+group*16)),scale));
  _mm_storeu_ps(c1,_mm_mul_ps(_mm_load_ps((float*)(0x812a40+0x500+group*16)),scale));
  _mm_storeu_ps(c2,_mm_mul_ps(_mm_load_ps((float*)(0x812a40+0x580+group*16)),scale));
  _mm_storeu_ps(c3,_mm_mul_ps(_mm_load_ps((float*)(0x812a40+0x600+group*16)),scale));
  for(u32 lane=0;lane<4;++lane){
   u32 color=packbyte(c3[lane]) | (packbyte(c2[lane])<<8) | (packbyte(c1[lane])<<16) | (packbyte(c0[lane])<<24);
   u64 a=*(const u64*)src,b=*(const u64*)(src+8),c=*(const u64*)(src+16),d=*(const u64*)(src+28);
   *(u64*)dst=a;*(u64*)(dst+8)=b;*(u64*)(dst+16)=c;*(u32*)(dst+24)=color;*(u64*)(dst+28)=d;
   if(--count==0)return;
   src+=36;dst+=36;
  }
  ++group;
 }while(true);
}
PCREG(61a980,copy_vertex_color);
