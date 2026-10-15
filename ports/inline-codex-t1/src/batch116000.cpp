#include "ff.h"
extern "C" void* THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_5002f0(void*,u32);
extern "C" void THISCALL ext_500360(void*,float);
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" void FASTCALL ext_4ddfa0(void*,void*);
static u32 STDCALL fn5519d0(void *a,u32 b,u32 *c){
 void *o=vcall<void*>(a,0x18,b); if(!o)return 0;
 void *p=vcall<void*>(o,0x4c);
 for(u32 i=0;i<4;i++)ext_5002f0(ext_5003d0(p,i),c[i]);
 ext_500360(ext_5003d0(p,4),bitsf(c[4]));
 return (u32)o;
}
PCREG(5519d0,fn5519d0);
static void THISCALL fn493b80(u8 *s,u8 *n){
 u8 *prev=*(u8**)(n+12),*next=*(u8**)(n+16);
 if(prev)*(u8**)(prev+16)=next;
 else {*(u8**)(s+0xa04)=next;if(next)*(u32*)(next+12)=0;}
 next=*(u8**)(n+16);if(next)*(u8**)(next+12)=*(u8**)(n+12);
 u32 count=--*(u32*)(s+0xa0c);
 s32 index=((s32)((u32)n-(u32)s-4))/20;
 if((u32)index!=count){
  u8 *last=s+4+count*20;
  for(int i=0;i<5;i++)((u32*)n)[i]=((u32*)last)[i];
  prev=*(u8**)(n+12);if(prev)*(u8**)(prev+16)=n;else *(u8**)(s+0xa04)=n;
  next=*(u8**)(n+16);if(next)*(u8**)(next+12)=n;
 }
}
PCREG(493b80,fn493b80);
static void THISCALL fn5216a0(u8 *s){
 float *out=(float*)(s+0x2630);
 if(!s[0x260b] || (!*(u32*)(s+0x2610) && *(float*)(*(u8**)(s+0x5c)+0x24)>G(float,0x68af14))){
  for(int i=0;i<3;i++)((u32*)out)[i]=*(u32*)(s+0x6c+4*i);
 }else{
  float tmp[3]={0,0,0};void *target=*(void**)(s+0x25d1);
  if(target)vcall<void>(target,0x84,tmp);
  ext_43e920(out,s+0x25fd,tmp);
 }
 ext_4ddfa0(out,s+0x78);
 vcall<void>(s,0x90,out);
}
PCREG(5216a0,fn5216a0);
