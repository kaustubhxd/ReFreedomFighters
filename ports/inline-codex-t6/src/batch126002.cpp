#include "ff.h"
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" double VECTORCALL ext_634d7c(double);
extern "C" void THISCALL ext_543810(void*,void*,float);
extern "C" void THISCALL ext_634e90(void*,u32);
static void THISCALL proximity(u8* me,float* point){
 float zero[3]={0,0,0},copy[3]={point[0],point[1],point[2]},diff[3];
 vcall<void>((void*)G(u32,me+0x44),0x84,(void*)zero);
 ext_43e920(diff,copy,zero);
 float d=diff[0]*diff[0];d=d+diff[1]*diff[1];d=d+diff[2]*diff[2];
 float distance=(float)ext_634d7c((double)d);
 if(!(distance>G(float,0x6ec38c))){
 ext_543810((void*)G(u32,me+0xcf),copy,5.0f);
 G(u8,me+0x10f)=1;G(u32,me+0xf7)=1000;G(u32,me+0xfb)=0x45480000;G(u32,me+0xff)=0x43c80000;G(u32,me+0x13d)=G(u32,me+0x141);ext_634e90(me,0x10);
 }
}
PCREG(53eeb0,proximity);
