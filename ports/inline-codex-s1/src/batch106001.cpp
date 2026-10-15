#include "ff.h"
extern "C" void FASTCALL ext_43e920(float*,const float*,const float*);
extern "C" void FASTCALL ext_43e8e0(float*,const float*,const float*);
extern "C" void FASTCALL ext_4de040(float*,const float*,u32);
extern "C" void THISCALL ext_4e0d00(float*,float);
extern "C" void THISCALL ext_4690b0(void*);
extern "C" void ext_633654(u32);
extern "C" double VECTORCALL ext_634d7c(double);
static void THISCALL update_direction(u8* self,const float* a,const float* b,u32 tag) {
 if(self[0x18]&4) {
  float delta[3], basis[9];
  ext_43e920(delta,b,a);
  float square=(delta[0]*delta[0]+delta[1]*delta[1])+delta[2]*delta[2];
  *(float*)(self+0x34)=(float)ext_634d7c((double)square);
  ext_4de040(basis,delta,0);
  ext_43e8e0(delta,a,b);
  ext_4e0d00(delta,0.5f);
  vcall<void>(self,0x74,basis,delta);
  *(u32*)(self+0x38)=tag;
  ext_4690b0(*(void**)(self+8));
 }
 ext_633654(0);
}
PCREG(43e740,update_direction);
