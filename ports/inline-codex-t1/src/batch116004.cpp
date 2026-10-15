#include "ff.h"
extern "C" double ext_634dca(double);
extern "C" void* THISCALL ext_5003d0(void*,u32);
static void fn404fd0(float a,float b,float c,float d,float e,float f,float g,float*out,u32*other){
 long double ac=(long double)a*c,bd=(long double)b*d;
 long double len=fsqrt_x87(bd*bd+ac*ac);
 if(g==G(float,0x6bdfd4)||g!=g){*(u32*)out=0;*other=0;return;}
 float aa=__builtin_fabsf(a),bb=__builtin_fabsf(b);
 *out=(!(bb>=aa))?a:b;
 long double cg=(long double)c*g,dg=(long double)d*g;
 long double den=fsqrt_x87(dg*dg+cg*cg);
 double value=(double)(len/den*(long double)*out*(long double)f+(long double)G(float,0x6bdffc));
 *out=(float)((long double)ext_634dca(value)*(long double)e);*other=0;
}
PCREG(404fd0,fn404fd0);
static void THISCALL fn51e940(u8*s,u8*args){
 const u32 offsets[3]={0x2c3,0x2ec,0x315};
 for(int i=0;i<3;i++){
  u32 *one=(u32*)ext_5003d0(*(void**)(args+4),1);
  u32 *zero=(u32*)ext_5003d0(*(void**)(args+4),0);
  u8 *component=*(u8**)(s+0x18);
  vcall<void>(component+offsets[i],0,*zero,0u,*one);
 }
}
PCREG(51e940,fn51e940);
static void STDCALL fn656c60(u8*out,u8*in){
 float one=G(float,0x678858);
 *(u32*)(out+0x10)=*(u32*)(in+0x10);*(u32*)(out+0x14)=*(u32*)(in+0x14);
 float limit=*(float*)(in+0x1c)-one,inner=*(float*)(in+0x18);
 *(float*)(out+0x18)=inner>limit?limit:inner;
 *(float*)(out+0x1c)=*(float*)(in+0x1c);
 *(float*)(out+0x20)=one/(*(float*)(out+0x1c)-*(float*)(out+0x18));
 *(u32*)(out+0x28)=*(u32*)(in+0x28);*(u32*)(out+0x24)=*(u32*)(in+0x24);
 *(float*)(out+0x30)=(float)crt::cos((double)*(float*)(in+0x28));
 float c24=(float)crt::cos((double)*(float*)(in+0x24));*(float*)(out+0x2c)=c24;
 float delta=*(float*)(in+0x24)-*(float*)(in+0x28);
 *(float*)(out+0x34)=delta==G(float,0x6785d0)?1.f:one/(*(float*)(out+0x30)-c24);
 *(u32*)(out+0x38)=*(u32*)(in+0x38);
}
PCREG(656c60,fn656c60);
