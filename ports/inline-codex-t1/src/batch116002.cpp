#include "ff.h"
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" double ext_634da6(double);
extern "C" void ext_634670();
extern "C" double VECTORCALL ext_634d7c(double);
extern "C" void THISCALL ext_4e0d00(void*,float);
extern "C" long double THISCALL ext_5243a0(void*);
extern "C" float THISCALL ext_5246a0(void*,float);
extern "C" void THISCALL ext_5245c0(void*,float);
extern "C" void THISCALL ext_524540(void*,float);
extern "C" u32 THISCALL ext_524370(void*);
static s32 ftol(double x){s32 r;asm volatile("fldl %1\n\tcall ext_634670":"=a"(r):"m"(x):"ecx","edx","memory","st");return r;}
static void THISCALL fn530db0(u8*s,u16*out,float*v){
 float extent[3];ext_43e920(extent,s+0x12,s+6);
 const u32 field[3]={0x3c,0x44,0x40};const u32 dest[3]={0,2,1};
 for(int i=0;i<3;i++){
  float q=v[i]/extent[i];q*=(float)*(s32*)(s+field[i]);
  out[dest[i]]=(u16)ftol(ext_634da6((double)q));
 }
}
PCREG(530db0,fn530db0);
static void THISCALL fn451250(float*s){
 float length;
 do{
  for(int i=0;i<3;i++){
   long double value=vcall<long double>(G(void*,0x70039c),0x1c0,0x681348u,0x42du);
   s[i]=(float)(value-(long double)G(float,0x67a6ac));
  }
  float sum=s[0]*s[0]+s[1]*s[1];sum+=s[2]*s[2];length=(float)ext_634d7c((double)sum);
 }while(G(float,0x681370)>length);
 ext_4e0d00(s,G(float,0x678858)/length);
}
PCREG(451250,fn451250);
static void THISCALL fn516070(u8*s,float dt){
 float scale=*(float*)(s+0x11)* *(float*)(s+0xc);
 *(float*)(s+0x49)=(float)((long double)ext_5243a0(s+0x41)*(long double)scale);
 *(float*)(s+0x5d)=(float)((long double)ext_5243a0(s+0x55)*(long double)scale);
 ext_5246a0(s+0x21,dt);ext_5245c0(s+0x41,dt);ext_524540(s+0x55,dt);
 float diff=*(float*)(s+0x55)-*(float*)(s+0x41);
 s[0x10]=*(float*)(s+0x1d)>=diff;
 float bound=*(float*)(s+0x15);
 if(!(bound>diff)){
  bound=*(float*)(s+0x19);if(!(diff>bound))return;
 }
 diff-=bound;if(0.f>diff)ext_524370(s+0x41);
}
PCREG(516070,fn516070);
static u32 THISCALL fn5d90c0(u8*s,u32 id,u32 unused){
 u32 state;
 if((u16)id==*(u16*)(s+0x50))state=1;
 else if((u16)id==*(u16*)(s+0x52))state=2;
 else return 0;
 u8 *sys=G(u8*,0x70039c);if(s+0x48!=sys+0x40)*(u32*)(s+0x48)=*(u32*)(sys+0x40);
 *(u32*)(s+0x4c)=state;
 float a=*(float*)(s+0x60),b=*(float*)(s+0x64);
 float rect[4]={a*0.f+*(float*)(s+0x58),b*0.f+*(float*)(s+0x5c),a,b};
 vcall<void>(*(void**)(s+0x44),0x23c,rect);
 vcall<void>(*(void**)(s+0x44),0x250);
 return 0;
}
PCREG(5d90c0,fn5d90c0);
