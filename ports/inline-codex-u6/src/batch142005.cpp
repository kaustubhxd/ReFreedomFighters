#include "ff.h"
extern "C" float ext_4050a0(u32);
extern "C" int ext_4053f0(s32*);
extern "C" void* ext_634df4(u32,u32);
static float* table(s32* p){
 if(p[3]!=1 && p[3]!=2)return 0;
 float bias=ext_4050a0(p[4]),scale=ext_4050a0(p[5]);
 float* dst=(float*)ext_634df4((u32)p[0]*(u32)p[1],4);
 int root=0;if(p[3]==1)root=ext_4053f0(p);
 for(int row=0;row<p[1];row++){
  float accum=0;int divisor=1;
  for(int col=0;col<p[0];col++){
   int k=p[3]==2 ? row*p[0]+col : (row/divisor)%root;
   s32 value=((s32*)p[8])[k];long double v=(long double)value;if(v<0)v=-v;
   v=v*(long double)scale+(long double)accum+(long double)bias;
   if(p[7])accum=(float)v;
   dst[row*p[0]+col]=(float)v;
   if(p[3]==1)divisor=(s32)((u32)divisor*(u32)root);
  }
 }
 return dst;
}
PCREG(405460,table);
