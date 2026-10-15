#include "ff.h"
static float maxss7(float a,float b){return _mm_cvtss_f32(_mm_max_ss(_mm_set_ss(a),_mm_set_ss(b)));}
static double abs7(float a){return _mm_cvtsd_f64(_mm_and_pd(_mm_set_sd((double)a),*(const __m128d*)0x67cd50));}
static u8 THISCALL contains(void* self,u32 handle,float* matrix,float* center,float* radius){
 float bound=maxss7(radius[2],maxss7(radius[1],radius[0]));
 while(handle){
  u8* node=vcall<u8*>(self,0xc,handle);
  u32 planes=*(u32*)(node+0x24);
  if(planes){
   u8* block=vcall<u8*>(self,0xc,planes);u32 count=*(u32*)block;
   for(u32 i=0;i<count;++i){
    float* p=(float*)(block+4+i*16);
    float dist=center[0]*p[0]+center[1]*p[1];dist=dist+center[2]*p[2];dist=dist+p[3];
    if(dist>bound)return 0;
    float a=matrix[7]*p[1]+p[0]*matrix[6];a=a+p[2]*matrix[8];
    float b=matrix[3]*p[0]+matrix[4]*p[1];b=b+p[2]*matrix[5];
    float d=p[1]*matrix[1]+matrix[0]*p[0];d=d+p[2]*matrix[2];
    float support=(float)((abs7(radius[1]*b)+abs7(radius[0]*a))+abs7(d*radius[2]));
    if(dist>support)return 0;
   }
  }
  handle=*(u32*)(node+8);
 }
 return 1;
}
PCREG(655dd0,contains);
