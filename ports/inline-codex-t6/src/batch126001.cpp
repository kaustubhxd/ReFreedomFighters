#include "ff.h"
extern "C" void THISCALL ext_460aa0(void*,void*,float);
extern "C" float FASTCALL ext_4e0830(void*,void*);
static float THISCALL nearest(u8* me,u32 unused,void* point,float step){
 float best=G(float,0x67cd44), result=0, t=-step;
 if(G(float,0x678858)>t){do{
 t=t+step; t=_mm_cvtss_f32(_mm_min_ss(_mm_set_ss(G(float,0x678858)),_mm_set_ss(t)));
 float v[3];ext_460aa0(me+0x1c,v,t);vcall<void>(me,0x84,(void*)v);
 float d=ext_4e0830(v,point);if(best>d){best=d;result=t;}
 }while(G(float,0x678858)>t);}
 return result;
}
PCREG(44ac00,nearest);
