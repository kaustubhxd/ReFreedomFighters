#include "ff.h"
extern "C" void THISCALL ext_5243f0(void*,float);
extern "C" void THISCALL ext_5243d0(void*,float);
extern "C" float THISCALL ext_516130(void*,float,u32);
extern "C" double THISCALL ext_5243a0(void*);
extern "C" void THISCALL ext_524980(void*,void*,void*);
extern "C" void THISCALL ext_5247e0(void*);
static void THISCALL init_ground(u8* me,const u32* src){
 for(int i=0;i<3;i++)*(u32*)(me+4*i)=src[i];
 ext_5243f0(me+0x41,0.0f);ext_5243d0(me+0x41,0.0f);
 float ground=ext_516130(me,*(float*)(me+4),0);
 ext_5243f0(me+0x41,ground);ext_5243d0(me+0x41,ground);
 float denominator=*(float*)(me+0x2d);
 double response=ext_5243a0(me+0x55);
 float ratio=(float)((__builtin_fabs((double)*(float*)(me+0x11))*response)/(double)denominator);
 float clipped=0.0f;
 if(!(0.0f>ratio))clipped=_mm_cvtss_f32(_mm_min_ss(_mm_set_ss(*(float*)(me+0x35)),_mm_set_ss(ratio)));
 float height=(*(float*)(me+0x35)-clipped)+ground;
 *(float*)(me+4)=height;ext_5243f0(me+0x55,height);
 ext_524980(me+0x21,me+0x41,me+0x55);ext_5247e0(me+0x21);
}
PCREG(516360,init_ground);
