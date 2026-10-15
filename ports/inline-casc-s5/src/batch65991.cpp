#include "ff.h"
extern "C" u8 *THISCALL ext_5003d0(u32,u32);
extern "C" void FASTCALL ext_43e920(float*,float*,float*);
extern "C" void THISCALL ext_4e0d00(float*,float);
extern "C" void FASTCALL ext_441940(float*,float*);
extern "C" double VECTORCALL ext_634d7c(double);
extern "C" double VECTORCALL ext_634dac(double);
typedef u8 *(THISCALL *get1_65001)(u8*,u32);
typedef u8 *(THISCALL *get0_65001)(u8*);
typedef void (THISCALL *vec_65001)(u8*,float*);
typedef void (THISCALL *emit_65001)(u8*,u32,float*,float,u32,u32,u32,u32);
static void THISCALL fn557d70(u8 *self,u8 *arg){
  u32 id=*(u32*)ext_5003d0(*(u32*)(arg+4),0);
  float angle=*(float*)ext_5003d0(*(u32*)(arg+4),1);
  u8 *tab=*(u8**)(G(u8*,0x70039c)+0x9b);
  u8 *target=(*(get1_65001**)tab)[0x58/4](tab,id);
  float p[3]={0,0,0},q[3]={0,0,0};
  (*(vec_65001**)target)[0x84/4](target,p);
  u8 *owner=*(u8**)(self+0x1c);
  (*(vec_65001**)owner)[0x84/4](owner,q);
  if((*(get0_65001**)owner)[0x50c/4](owner)){
    u8 *sub=(*(get0_65001**)owner)[0x50c/4](owner);
    *(u32*)(sub+0xcd)=0;
  }
  float d[3]; ext_43e920(d,p,q);
  float x2=d[1]*d[1],z2=d[0]*d[0],y2=d[2]*d[2];
  float sum=(x2+z2)+y2;
  double length=(float)ext_634d7c((double)sum);
  float scaledAngle=angle*G(float,0x67da04);
  float magnitude=(float)(length*ext_634dac((double)scaledAngle));
  float v[3]={bitsf(fbits(d[2])^G(u32,0x67af40)),0,d[0]};
  float planar=(float)ext_634d7c((double)((v[0]*v[0]+0.0f)+z2));
  ext_4e0d00(v,magnitude/planar);
  v[1]=100.0f;
  ext_441940(p,v);
  (*(vec_65001**)owner)[0x8c/4](owner,p);
  (*(emit_65001**)owner)[0x4ac/4](owner,0,p,0.05f,0,0,0,0xffffffffu);
}
PCREG(557d70,fn557d70);
