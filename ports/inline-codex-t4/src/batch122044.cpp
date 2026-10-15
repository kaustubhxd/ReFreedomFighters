#include "ff.h"
static float rem44(double a,double b){float v;asm volatile("fldl %1; fldl %2; fxch %%st(1); 1: fprem; fnstsw %%ax; test $0x400,%%ax; jnz 1b; fstp %%st(1); fstps %0":"=m"(v):"m"(a),"m"(b):"ax","cc","st","st(1)");return v;}
static void THISCALL fn646220(u8* s,u8* obj,u8* out){
 if(*(u32*)(s+0x291)||s[0x295])return;u8* data=*(u8**)(obj+0x1c);vcall<void>(obj,0x2cc);*(u32*)(out+0x18)=*(u32*)(data+0xc);
 for(u32 i=1;i!=*(u32*)(s+0x11);++i){u8* p=data+24*i;u8* d=out+29*i;*(u32*)(d+24)=*(u32*)(p+12);
  if(p[4]&3){u8* a=*(u8**)(p+20);float hi=*(float*)(a+24),time=*(float*)(a+8),n=(float)*(s32*)(a+12);
   if(hi>time){float q=*(float*)(a+32)*time;s32 k=_mm_cvttss_si32(_mm_set_ss(q));float t=(float)k*n;time=time-t;}
   else if(hi!=n)time=rem44((double)hi,(double)n);else time=hi;
   d[28]=1;*(u32*)(d+8)=*(u32*)(a+44);*(float*)(d+4)=time;*(u32*)d=*(u32*)(p+16);
  }else{d[28]=0;*(u32*)(d+8)=0;u32 id=*(u32*)(p+16);*(u32*)d=id;if(id)*(u32*)(d+4)=*(u32*)p;}
  *(u32*)(d+12)=0;
 }
}
PCREG(646220,fn646220);
