#include "ff.h"
extern "C" void* THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_4deb20(void*,float,float,float,float);
extern "C" void FASTCALL ext_4de4f0(void*,void*);
static void THISCALL rotation(u8* me,u8* input){
 float matrix[9],position[3],rot[9];void* o=G(void*,me+0xc);vcall<void>(o,0x80,(void*)matrix,(void*)position);
 void* values=G(void*,input+4);
 float* w=(float*)ext_5003d0(values,3);float* z=(float*)ext_5003d0(values,2);float* y=(float*)ext_5003d0(values,1);float* x=(float*)ext_5003d0(values,0);
 ext_4deb20(rot,*x,*y,*z,*w);ext_4de4f0(matrix,rot);
 vcall<void>(G(void*,me+0xc),0x7c,(void*)matrix,(void*)position);
}
PCREG(501cd0,rotation);
