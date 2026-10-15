#include "ff.h"
extern "C" s32 VECTORCALL ext_633910(float);
static u32 THISCALL fn4bf200(u8*s,u32 id,s32 *data){
 if((u16)id==*(u16*)(s+0x48)){
  float t=vcall<float>(G(void*,0x70039c),0x1c0,0x693c40u,0xc5cu);
  if(!(*(float*)(s+0x66)>=t))return 0;
  if(data){
   *(float*)(s+0x52)=(float)data[0];*(float*)(s+0x56)=(float)data[1];*(u32*)(s+0x5e)=data[2];
   float y=*(float*)(s+0x56);
   if(y==0 || !(y>*(float*)(s+0x52)))return 0;
  }
  *(u16*)(s+0x4c)=1;*(u32*)(s+0x4e)=0;
  vcall<void>(s,0x64,0x10u);
 }else if((u16)id==*(u16*)(s+0x4a)){
  s[0x4c]=0;vcall<void>(s,0x68,0x10u,0u);
 }
 return 0;
}
PCREG(4bf200,fn4bf200);
static void STDCALL fn528f50(u8*s,float value){
 for(u32 i=0;i<2;i++){
  u8 *sys=G(u8*,0x70039c),*manager=*(u8**)(sys+0x1aa3),*table=*(u8**)(manager+0x18);
  u32 id=vcall<u32>(table,0x60,*(u32*)(*(u8**)(s+8)+0x6c),i);
  sys=G(u8*,0x70039c);manager=*(u8**)(sys+0x1aa3);table=*(u8**)(manager+0x18);
  u32 key=vcall<u32>(table,0xe4,id,0x678d04u);
  sys=G(u8*,0x70039c);manager=*(u8**)(sys+0x1aa3);
  u8 *result=vcall<u8*>(manager,0x80,key);
  if(!result)return;
  *(float*)(result+0x10)=value;
 }
}
PCREG(528f50,fn528f50);
static void THISCALL fn657cc0(void*s,u32 node,u32 destination){
 float lo=G(float,0x678858),hi=0;
 while(node){
  u8 *record=vcall<u8*>(s,0xc,node);
  if(!*(u16*)(record+2)){
   lo=_mm_cvtss_f32(_mm_min_ss(_mm_set_ss(*(float*)(record+0x54)),_mm_set_ss(lo)));
   hi=_mm_cvtss_f32(_mm_max_ss(_mm_set_ss(*(float*)(record+0x58)),_mm_set_ss(hi)));
  }
  node=*(u32*)(record+8);
 }
 u8 *out=vcall<u8*>(s,0xc,destination);
 if(!*(u16*)(out+2)){
  float t=G(float,0x678858)-lo;t*=G(float,0x68af18);t/=G(float,0x686080);t+=G(float,0x67a6ac);
  u32 n=(u32)ext_633910(t)+1;if(n>64)n=64;
  float q=(float)(s32)n;q*=G(float,0x686080);q/=G(float,0x68af18);
  *(float*)(out+0x54)=G(float,0x678858)-q;*(float*)(out+0x58)=hi;
 }
}
PCREG(657cc0,fn657cc0);
