#include "ff.h"
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" void THISCALL ext_453a50(void*,float*);
static float FASTCALL fn53bec0(float*position,u32 ref){
 void*target=vcall<void*>(*(void**)(G(u8*,0x70039c)+0x9b),0x58,ref);float p[3]={0,0,0};vcall<void>(target,0x84,p);
 float v[3];ext_43e920(v,p,position);
 if(v[0]!=0 || v[1]!=0 || v[2]!=0){long double x=v[0],y=v[1],z=v[2];long double inv=1.0L/fsqrt_x87((x*x+y*y)+z*z);for(int i=0;i<3;i++)v[i]=(float)((long double)v[i]*inv);}
 float velocity[3];ext_453a50(target,velocity);return (velocity[0]*v[0]+velocity[1]*v[1])+velocity[2]*v[2];
}
PCREG(53bec0,fn53bec0);
