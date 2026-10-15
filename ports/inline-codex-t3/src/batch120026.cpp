#include "ff.h"
extern "C" u32 THISCALL ext_5c94a0(void *,u32);
extern "C" u8 THISCALL ext_5c82a0(void *,const float *);
static u8 THISCALL aimWeaponRef(u8 *self,u32 ref) {
 void *target=vcall<void *>(*(void **)(G(u8 *,0x70039c)+0x9b),0x58,ref);
 float p[3]={0,0,0};vcall<void>(target,0x84,p);
 p[1]+=G(float,0x67cd40);vcall<void>(target,0x8c,p);
 u8 *sys=G(u8 *,0x70039c);
 if(*(float *)(self+0x84)>0.0f) {
  long double random=vcall<long double>(sys,0x1c0,0x6b49b8u,0x1d5u);
  float jitter=(float)(random*(long double)G(float,0x68af1c)-(long double)G(float,0x68af14));
  float error=*(float *)(self+0x84);
  p[0]=error*jitter+p[0];p[1]-=error*G(float,0x67da2c);
  float dt=*(float *)(G(u8 *,0x70039c)+0x48);
  *(float *)(self+0x84)=error-dt*G(float,0x67a288);
 } else {
  float random=(float)vcall<long double>(sys,0x1c0,0x6b49b8u,0x1d9u);
  float dt=*(float *)(G(u8 *,0x70039c)+0x48);
  if(dt*G(float,0x67a284)>random && (u8)ext_5c94a0(self,ref)) *(u32 *)(self+0x84)=0x3f800000;
 }
 vcall<void>(target,0x84,p);return ext_5c82a0(self,p);
}
PCREG(5c8470,aimWeaponRef);
