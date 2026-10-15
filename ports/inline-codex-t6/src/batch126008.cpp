#include "ff.h"
extern "C" long double THISCALL ext_4dfda0(void*);
extern "C" u32 VECTORCALL ext_633910(float);
static u32 THISCALL opacity(u8* me,void* object,float* point){
 float a[3],b[3]={0.5f,-0.5f,0},unused=point[2];(void)unused;vcall<void>(object,0x274,(void*)a,(void*)b);
 float denominator=_mm_cvtss_f32(_mm_min_ss(_mm_set_ss(a[0]),_mm_set_ss(a[1])));denominator=denominator+G(float,me+0x1c);
 float ratio=(float)(ext_4dfda0(point)/(long double)denominator);float upper=G(float,me+0x20),lower=G(float,me+0x24);
 if(ratio>upper)return 0;if(lower>ratio)return 255;
 float fraction=(ratio-lower)/(upper-lower);float alpha=(G(float,0x678858)-fraction)*G(float,0x68af18);return ext_633910(alpha);
}
PCREG(47ff20,opacity);
