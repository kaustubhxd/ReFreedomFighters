#include "ff.h"
extern "C" void FASTCALL ext_43e920(float*,const float*,const float*);
extern "C" void THISCALL ext_4e0d00(float*,float);
extern "C" void THISCALL ext_521600(void*,float*);
extern "C" float THISCALL ext_44c840(float*);
extern "C" void ext_633654(u32);
extern "C" double VECTORCALL ext_634d7c(double);
static void THISCALL update_motion(u8* me) {
 float* out=(float*)(me+0x2d8);void* ctl=me+0x2695;
 vcall<void>(ctl,8,out);
 if(*(u32*)(me+0x216)!=1 && *(float*)(*(u8**)(me+0x5c)+0x24)>G(float,0x680a70)) {
  float v[3];ext_43e920(v,(float*)(me+0x60),(float*)(me+0x90));v[1]=0;
  float square=(v[0]*v[0]+0.0f)+v[2]*v[2];
  if((float)ext_634d7c((double)square)>G(float,0x697880)) {
   ext_4e0d00(v,*(float*)(me+0x2f0));ext_521600(me,v);
   if(*(float*)(*(u8**)(me+0x5c)+0x24)>G(float,0x680a84))
    for(int i=0;i<3;i++)out[i]=*(float*)(me+0x2e4+4*i);
  }
 }
 if(vcall<u8>(ctl,0xc)) {
  *(u32*)(me+0x2e8)=0;
  (void)ext_44c840((float*)(me+0x2e4));
  vcall<void>(ctl,4,out,me+0x2e4);
  if(*(u32*)(me+0x216)==1)vcall<void>(me,0x130,me,(u32)*(u16*)(me+0x270b),0);
 }
 out[1]=0;
 if(out[0]!=0.0f || out[1]!=0.0f || out[2]!=0.0f) {
  long double x=out[0],y=out[1],z=out[2];
  long double len=fsqrt_x87((x*x+y*y)+z*z),inv=1.0L/len;
  out[0]=(float)(x*inv);out[1]=(float)(y*inv);out[2]=(float)(z*inv);
 }
 ext_633654(0);
}
PCREG(521bd0,update_motion);
