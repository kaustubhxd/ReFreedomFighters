#include "ff.h"
extern "C" void FASTCALL ext_441970(void*,void*,void*);
extern "C" void FASTCALL ext_441940(void*,void*);
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" void FASTCALL ext_441a60(void*,void*);
extern "C" void FASTCALL ext_459fc0(void*,void*,void*);
extern "C" void FASTCALL ext_43e8e0(void*,void*,void*);
extern "C" u8 THISCALL ext_4e2800(void*,float,float,float,float,float,float,float,float,float,float,float,float);
static u32 THISCALL closest(u8* self,float* best,void* point,void* direction,void* origin){
 u8* a=vcall<u8*>(*(void**)(self+0x6c),0x58,self);
 u8* b=vcall<u8*>(self,0x2cc);
 u32 answer=0;
 for(u32 i=1;i!=*(u32*)(self+0x20);++i){
  u8* s=a+0x50+(i-1)*0x30;u8* t=b+0x5e +(i-1)*0x30;
  float v[3];ext_441970(v,t-0x2e,s-0x20);ext_441940(v,s+4);ext_43e920(v,point,v);
  if(!(*(float*)(s-8)==0.0f && *(float*)(s-4)==0.0f && *(float*)s==0.0f)){
   ext_441a60(v,s-0x20);float d[3],o[3];ext_459fc0(d,direction,s-0x20);ext_43e8e0(o,origin,t-0x1e);
   float hit;
   if(ext_4e2800(&hit,bitsf(fbits(o[0])^G(u32,0x67af40)),bitsf(fbits(o[1])^G(u32,0x67af40)),bitsf(fbits(o[2])^G(u32,0x67af40)),o[0],o[1],o[2],v[0],v[1],v[2],d[0],d[1],d[2]) && *best>hit){answer=*t;*best=hit;}
  }
 }
 return answer;
}
PCREG(461aa0,closest);
