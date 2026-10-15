#include "ff.h"
static float matrixDot(long double a0,long double a1,long double a2,long double a3,const float* b,u32 stride){
 long double p0=a0*(long double)b[0],p1=a1*(long double)b[stride],p2=a2*(long double)b[stride*2],p3=a3*(long double)b[stride*3];
 return (float)((p0+p2)+(p1+p3));
}
static void STDCALL matrixMultiply(float* dst,const float* left,const float* right){
 float local[16];
 if(dst==right && left!=dst){
  for(u32 col=0;col<4;++col){
   long double a0=right[col],a1=right[col+4],a2=right[col+8],a3=right[col+12];
   for(u32 row=0;row<4;++row)dst[row*4+col]=matrixDot(a0,a1,a2,a3,left+row*4,1);
  }
  return;
 }
 if(dst==right && left==dst){for(int i=0;i<16;++i)local[i]=right[i];right=local;}
 for(u32 row=0;row<4;++row){
  long double a0=left[row*4],a1=left[row*4+1],a2=left[row*4+2],a3=left[row*4+3];
  for(u32 col=0;col<4;++col)dst[row*4+col]=matrixDot(a0,a1,a2,a3,right+col,4);
 }
}
PCREG(410f26,matrixMultiply);
