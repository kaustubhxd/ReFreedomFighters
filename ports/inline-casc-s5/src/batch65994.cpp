#include "ff.h"
static void FASTCALL fn63a580(s32 n,u32 *samples,u32 *order){
  float inv=G(float,0x678858)/(float)n;
  float variance[3];
  for(int axis=0;axis<3;++axis){
    order[axis]=axis;
    u32 sum=0,squares=0;
    for(s32 j=0;j<n;++j){u32 x=samples[4*j+axis];sum+=x;squares+=x*x;}
    variance[axis]=(float)(s32)squares*inv-((float)(s32)(sum*sum)*inv)*inv;
  }
  float big=variance[0],small=variance[1],last=variance[2];
  if(small>big){u32 t=order[0];order[0]=order[1];order[1]=t;float f=big;big=small;small=f;}
  if(last>big){u32 t=order[0];order[0]=order[2];order[2]=t;last=big;}
  if(last>small){u32 t=order[1];order[1]=order[2];order[2]=t;}
}
PCREG(63a580,fn63a580);
