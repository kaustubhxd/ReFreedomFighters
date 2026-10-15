#include "ff.h"
extern "C" void THISCALL ext_545d10(void*,u32,void*,void*,void*);
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" void FASTCALL ext_43e960(void*,void*);
extern "C" u8 FASTCALL ext_547860(void*,void*,void*);
extern "C" void THISCALL ext_53f3b0(void*,void*,float,float,float,float,float);
static void THISCALL weights22(u8* self,float* point,void* out){
 float vertices[4][3],other[4][3];u32 ids[4];
 for(u32 i=0;i<4;++i)ext_545d10(*(void**)(self+0xcf),i+1,vertices[i],other[i],ids+i);
 float basis[3][3];for(int i=0;i<3;++i)ext_43e920(basis[i],vertices[i+1],vertices[0]);
 float delta[3]={point[0],point[1],point[2]};ext_43e960(delta,vertices[0]);
 float weights[3];ext_547860(basis,delta,weights);
 float w0=G(float,0x678858)-weights[0];w0=w0-weights[1];w0=w0-weights[2];
 float sum=weights[0]*weights[0]+w0*w0;sum=sum+weights[1]*weights[1];sum=sum+weights[2]*weights[2];
 ext_53f3b0(self,out,w0,weights[0],weights[1],weights[2],sum);
}
PCREG(53f230,weights22);
