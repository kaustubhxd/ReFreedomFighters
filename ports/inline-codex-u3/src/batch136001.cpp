#include "ff.h"
static float mn(float a,float b){return _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(a),_mm_set_ss(b)));}
static float mx(float a,float b){return _mm_cvtss_f32(_mm_max_ss(_mm_set_ss(a),_mm_set_ss(b)));}
static void THISCALL fn4bce60(u8*s){
 u8*sys=G(u8*,0x70039c);void* manager=*(void**)(sys+0x1a9f);if(!manager)return;
 void*target;
 if(vcall<u32>(manager,0xec)==3){
  void* tab=*(void**)(sys+0x9b);void* query=vcall<void*>(tab,0x138);u32 key=0;
  vcall<void>(query,0x88,0x681320u,&key);target=vcall<void*>(*(void**)(G(u8*,0x70039c)+0x9b),0x58,key);
 }else target=vcall<void*>(*(void**)(G(u8*,0x70039c)+0x1a9f),0xc0);
 if(!target)return;
 float xyz[3]={0,0,0};vcall<void>(target,0x84,xyz);void* local=*(void**)(s+0x44);vcall<void>(local,0x8c,xyz);
 float f[3]={G(float,0x678858),G(float,0x678858),G(float,0x678858)};
 for(int i=0;i<3;i++){
  float range=*(float*)(s+0x48+i*4);
  if(range!=0.0f && !__builtin_isnan(range)){
   double d=(double)xyz[i];u64 bits=__builtin_bit_cast(u64,d)&G(u64,0x67cd50);double abs=__builtin_bit_cast(double,bits);
   f[i]=(float)(((double)range-abs)/(double)range);
  }
 }
 float v=mn(G(float,0x678858),mx(0.0f,mn(f[2],mn(f[1],f[0]))));
 *(float*)(*(u8**)((u8*)local+0x18)+0x84)=v;
}
PCREG(4bce60,fn4bce60);
