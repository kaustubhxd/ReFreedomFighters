#include "ff.h"
extern "C" u32 THISCALL ext_4e5e60(void*);
extern "C" long double THISCALL ext_4e5e80(void*);
extern "C" u32 THISCALL ext_4e5e40(void*);
extern "C" u8 THISCALL ext_4e8c00(void*,void*,void*,void*,u32);
extern "C" long double THISCALL ext_524390(void*);
static bool kind(u8*reader,u8 k){u8 b=**(u8**)reader;return b!=255&&(b&63)==k;}
static void THISCALL fn4a24a0(u8*s,u8*reader){
 *(u32*)(s+0x51)=0;*(u32*)(s+0x55)=0xbf800000;*(u16*)(s+0x11c)=0x100;*(u32*)(s+0x11e)=0x41c80000;s[0x48]=1;
 if(!*(u32*)reader)return;
 bool first=ext_4e5e60(reader)!=0;s[0x11d]=first;
 if(kind(reader,2))s[0x11c]=0;
 else{s[0x11c]=first;s[0x11d]=ext_4e5e60(reader)!=0;}
 *(float*)(s+0x11e)=(float)ext_4e5e80(reader);s[0x48]=ext_4e5e60(reader)!=0;
 if(kind(reader,10))*(u16*)(s+0x11a)=(u16)ext_4e5e40(reader);
 if(kind(reader,2)){
  *(float*)(s+0x51)=(float)ext_4e5e80(reader);float second=(float)ext_4e5e80(reader);
  *(float*)(s+0x51)/=G(float,0x685270);*(float*)(s+0x55)=second/G(float,0x685270);
 }
}
PCREG(4a24a0,fn4a24a0);
static void THISCALL fn4362f0(u8*s){
 if(!*(u32*)(s+0x1c))return;
 u8 *sys=G(u8*,0x70039c);
 if(!sys[0x6d]){
  *(float*)(sys+0x9f3)=*(float*)(sys+0x9e7)-G(float,0x6ff958);
  u8 *now=G(u8*,0x70039c);*(float*)(now+0x9f7)=*(float*)(now+0x9eb)-G(float,0x6ff95c);
  G(u32,0x6ff958)=*(u32*)(sys+0x9e7);G(u32,0x6ff95c)=*(u32*)(sys+0x9eb);G(u32,0x6ff960)=*(u32*)(sys+0x9ef);
 }
 if(!*(u32*)(s+0x1c))return;
 float *delta=vcall<float*>(*(void**)(s+0x10),0x10);if(!delta)return;
 *(float*)(s+0x64)+=delta[0];*(float*)(s+0x68)=delta[1]+*(float*)(s+0x68);
 if(0.f>*(float*)(s+0x64))*(u32*)(s+0x64)=0;
 sys=G(u8*,0x70039c);s32 width=vcall<s32>(*(void**)(sys+0x190f),0xd8);
 if(*(float*)(s+0x64)>(float)width){sys=G(u8*,0x70039c);*(float*)(s+0x64)=(float)vcall<s32>(*(void**)(sys+0x190f),0xd8);}
 if(0.f>*(float*)(s+0x68))*(u32*)(s+0x68)=0;
 sys=G(u8*,0x70039c);s32 height=vcall<s32>(*(void**)(sys+0x190f),0xdc);
 if(*(float*)(s+0x68)>(float)height){sys=G(u8*,0x70039c);*(float*)(s+0x68)=(float)vcall<s32>(*(void**)(sys+0x190f),0xdc);}
}
PCREG(4362f0,fn4362f0);
static long double THISCALL fn516130(u8*s,float y,void*box){
 if(box){
  u8 hit[0x48];*(u32*)hit=0x3f800000;u32 direction[3]={0,0xc4fa0000,0};
  if(ext_4e8c00(box,hit,s,direction,0))return *(float*)(hit+8);
 }else{
  *(u32*)(s+0x9d)=0x3f800000;
  for(int i=0;i<3;i++)*(u32*)(s+0x69+4*i)=*(u32*)(s+4*i);
  *(float*)(s+0x6d)=y;*(u32*)(s+0x75)=0;*(u32*)(s+0x79)=0xc4fa0000;*(u32*)(s+0x7d)=0;
  u8 *sys=G(u8*,0x70039c),*render=*(u8**)(sys+0x9b);
  if(vcall<u8>(*(void**)(render+0xadc),0x2e0,s+0x69,0u,0x20u,0x200000u,1u,0u))return *(float*)(s+0x95);
 }
 return ext_524390(s+0x41);
}
PCREG(516130,fn516130);
