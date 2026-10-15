#include "ff.h"
extern "C" void THISCALL ext_460af0(void*,float*,float*,float);
extern "C" float FASTCALL ext_4e0030(void*,void*);
extern "C" void FASTCALL ext_446ee0(void*,void*,void*);
extern "C" void ext_633654(u32);
static float THISCALL sample_angle(u8* me,float a,float b){
 float result=0.0f;
 u8* map=*(u8**)(me+0x4b);
 if(map){
  float scratch[3],first[3],second[3],cross[3];
  ext_460af0(map+0x1c,scratch,first,a);
  float t=(b/(*(float*)(me+0x53)))*(*(float*)(me+0x20))+a;
  if(0.0f>t)t=0.0f;else t=_mm_cvtss_f32(_mm_min_ss(_mm_set_ss(1.0f),_mm_set_ss(t)));
  ext_460af0(map+0x1c,scratch,second,t);
  result=ext_4e0030(first,second);
  ext_446ee0(cross,first,second);
  if(0.0f>cross[1])result=bitsf(fbits(result)^G(u32,0x67af40));
 }
 ext_633654(0);
 return result;
}
PCREG(522f60,sample_angle);
