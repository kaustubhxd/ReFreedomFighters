#include "ff.h"
extern "C" void* ext_634df4(u32,u32);
extern "C" void ext_634d52(void*);
static long double sin15(long double f){asm("fsin":"+t"(f));return f;}
static float window_lane15(s32 numerator,s32 count){
 long double x=(long double)numerator+G(float,0x6bdffc);
 x=x/(long double)count;x=x*G(float,0x6be0cc);x=x*G(double,0x6be020);
 x=sin15(x);x=x*x;x=x*G(float,0x6be0c8);return (float)sin15(x);
}
static float* window15(s32 type,s32 n,s32 left,s32 right){
 float* out=(float*)ext_634df4(n,4);
 if(type){ext_634d52(out);return nullptr;}
 s32 begin=n/4-left/2; s32 end=n-right/2-n/4;
 for(s32 i=0;i<left;++i)out[begin+i]=window_lane15(i,left);
 for(s32 i=begin+left;i<end;++i)out[i]=1.0f;
 for(s32 i=0;i<right;++i)out[end+i]=window_lane15(right-i-1,right);
 return out;
}
PCREG(406470,window15);
