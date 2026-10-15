#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(void*,u32);
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
static void THISCALL fn510bf0(void*,u8*arg){
 void*list=*(void**)(arg+4);u8*key=ext_5003d0(list,0);void*o=vcall<void*>(*(void**)(G(u8*,0x70039c)+0x9b),0x58,*(u32*)key);
 float matrix[9],position[3];vcall<void>(o,0x80,matrix,position);
 float *z=(float*)ext_5003d0(list,3),*y=(float*)ext_5003d0(list,2),*x=(float*)ext_5003d0(list,1);
 float v[3]={*x,*y,*z};ext_43e920(position,position,v);
 float sum=(position[0]*position[0]+position[1]*position[1])+position[2]*position[2];float distance=(float)crt::sqrt((double)sum);
 u8*out=ext_5003d0(*(void**)(arg+8),0);
 if(out[4]!=0 && out[4]!=2){
  void*log=vcall<void*>(G(void*,0x700390),0x20,0x69c8e0u,0x104u);typedef void(*Print)(void*,u32,u32);(*(Print*)(*(u8**)log+0x2c))(log,0x69c6b0u,0x69c938u);
  typedef void(*Assert)();G(Assert,0x7003b0)();
 }
 out[4]=2;*(float*)out=distance;
}
PCREG(510bf0,fn510bf0);
