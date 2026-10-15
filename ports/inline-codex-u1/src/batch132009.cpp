#include "ff.h"
extern "C" float FASTCALL ext_44e630(void*,void*);
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
static void THISCALL turn(u8* self){
 float* speed=(float*)(self+0x23e);
 float len=speed[0]*speed[0]+speed[1]*speed[1];len=len+speed[2]*speed[2];
 float v[3];ext_44e630(v,len>G(float,0x679540)?speed:(float*)(self+0x256));
 u32 target=*(u32*)(self+0x34a);
 if(target){
  void* object=vcall<void*>(*(void**)(G(u8*,0x70039c)+0x9b),0x58,target);
  float pos[3]={0,0,0};vcall<void>(object,0x84,pos);ext_43e920(v,pos,self+0x60);
  if(!(v[0]==0.0f && v[1]==0.0f && v[2]==0.0f)){
   long double l=(long double)v[0]*v[0];l=l+(long double)v[1]*v[1];l=l+(long double)v[2]*v[2];
   long double inv=1.0L/fsqrt_x87(l);
   for(int k=0;k<3;++k)v[k]=(float)((long double)v[k]*inv);
  }
 }
 float dt=*(float*)(G(u8*,0x70039c)+0x48);float t=dt+dt;
 float* facing=(float*)(self+0x222);
 facing[0]=(v[0]-facing[0])*t+facing[0];
 facing[1]=(0.0f-facing[1])*t+facing[1];
 facing[2]=(v[2]-facing[2])*t+facing[2];
}
PCREG(51e560,turn);
