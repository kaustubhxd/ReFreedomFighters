#include "ff.h"
extern "C" void FASTCALL ext_43e920(float*,float*,float*);
extern "C" void FASTCALL ext_446ee0(float*,float*,float*);
extern "C" void FASTCALL ext_4419f0(float*,float*);
extern "C" void FASTCALL ext_441970(float*,float*,float*);
extern "C" void FASTCALL ext_441940(float*,float*);
static u8 THISCALL fn64cb10(u8 *self,float *plane,float *out,float *mat,float *shift,float *in){
  float u[3],v[3];
  ext_43e920(u,in+3,in);
  ext_43e920(v,in+6,in);
  ext_446ee0(plane,u,v);
  ext_4419f0(plane,mat);
  ext_441970(out,in,mat);
  ext_441940(out,shift);
  float dot=(out[1]*plane[1]+out[0]*plane[0])+out[2]*plane[2];
  float d=bitsf(fbits(dot)^G(u32,0x67af40));
  plane[3]=d;
  if(0.0f>=d)return 0;
  bool hit=false;
  for(int k=0;k<4;++k){
    float *p=(float*)(self+0x181c9+12*k);
    float side=((p[1]*plane[1]+p[0]*plane[0])+p[2]*plane[2])+d;
    if(!(side>=0.0f)){hit=true;break;}
  }
  if(!hit)return 0;
  for(int k=1;k<4;++k){
    ext_441970(out+3*k,in+3*k,mat);
    ext_441940(out+3*k,shift);
  }
  return 1;
}
PCREG(64cb10,fn64cb10);
