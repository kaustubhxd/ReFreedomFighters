#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_5002f0(void*,u32);
extern "C" void FASTCALL ext_43e920(float*,const float*,const float*);
static void THISCALL distance(void*,u8* args){
 u8* v=ext_5003d0(*(void**)(args+4),0);
 void* a=vcall<void*>(*(void**)(G(u8*,0x70039c)+0x9b),0x58,*(u32*)v);
 v=ext_5003d0(*(void**)(args+4),1);
 void* b=vcall<void*>(*(void**)(G(u8*,0x70039c)+0x9b),0x58,*(u32*)v);
 if(!a||!b){
  void* log=vcall<void*>(G(void*,0x700390),0x20,0x69db34u,0x15fu);
  typedef void(*Print)(void*,u32);(*(Print*)(*(u8**)log+0x2c))(log,0x69db88u);
  ext_5002f0(ext_5003d0(*(void**)(args+8),0),0xffffffffu);
 }
 float mat[9],p[3],q[3];vcall<void>(a,0x80,mat,p);vcall<void>(b,0x80,mat,q);ext_43e920(p,p,q);
 float sum=p[0]*p[0]+p[1]*p[1];sum=sum+p[2]*p[2];float result=(float)crt::sqrt((double)sum);
 v=ext_5003d0(*(void**)(args+8),0);
 if(v[4]!=0 && v[4]!=2){
  void* log=vcall<void*>(G(void*,0x700390),0x20,0x69c8e0u,0x104u);
  typedef void(*Print)(void*,u32,u32);(*(Print*)(*(u8**)log+0x2c))(log,0x69c6b0u,0x69c938u);
  typedef void(*Assert)();G(Assert,0x7003b0)();
 }
 v[4]=2;*(float*)v=result;
}
PCREG(510d40,distance);
