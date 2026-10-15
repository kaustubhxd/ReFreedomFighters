#include "ff.h"
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" float FASTCALL ext_4e2120(void*,void*);
extern "C" void FASTCALL ext_441a60(void*,void*);
extern "C" float THISCALL closest_volume(u8* me,float* point){
 void* list=*(void**)(me+0x44);
 if(!list){float d[3];ext_43e920(d,me+0x24,point);return ext_4e2120(d,me+0x18);}
 float best=G(float,0x67cd44);u32 it[5];
 vcall<void>(list,0x4c,it);u32 id=vcall<u32>(list,0x5c,it);
 while(it[0]){
  u8* target=vcall<u8*>(*(void**)(G(u8*,0x70039c)+0x9b),0x58,id);
  if(target){
   float p[3];u8* data=*(u8**)(target+8);
   ext_43e920(p,point,data+0x24);ext_441a60(p,data);
   float d=vcall<float>(target,0x18c,p);
   best=_mm_cvtss_f32(_mm_min_ss(_mm_set_ss(d),_mm_set_ss(best)));
  }else vcall<void>(*(void**)(me+0x44),0x44,it);
  id=vcall<u32>(*(void**)(me+0x44),0x5c,it);
 }
 return best;
}
PCREG(440b20,closest_volume);
