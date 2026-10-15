#include "ff.h"
extern "C" void FASTCALL ext_4419f0(void*,void*);
extern "C" void FASTCALL ext_441940(void*,void*);
extern "C" void THISCALL ext_5162e0(void*,void*);
extern "C" void THISCALL ext_460af0(void*,void*,void*,float);
extern "C" long double FASTCALL ext_4e0830(void*,void*);
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" s32 VECTORCALL ext_633910(float);
extern "C" void FASTCALL ext_54f2b0(s32,u32);
static void THISCALL fn5279f0(u8*s){
 const u32 counts[]={0x8d,0x91},dampers[]={0x95,0x785},sources[]={0xe91,0x1829};
 for(int group=0;group<2;group++)for(s32 i=0;i<*(s32*)(s+counts[group]);i++){
  u8 *d=s+dampers[group]+0xde*i;
  float delta=*(float*)(d+0x55)-*(float*)(d+0x41);
  if(0.f>delta){
   u32 p[3];for(int j=0;j<3;j++)p[j]=*(u32*)(s+sources[group]+0x133*i+4*j);
   ext_4419f0(p,s+0xc);ext_441940(p,s);ext_5162e0(d,p);
  }
 }
}
PCREG(5279f0,fn5279f0);
static float clamp(float x){if(0.f>x)return 0.f;return _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(G(float,0x678858)),_mm_set_ss(x)));}
static void THISCALL fn523520(u8*s,float*out,float t,float window){
 u8 *path=*(u8**)(s+0x4b);if(!path){((u32*)out)[0]=0x3f800000;((u32*)out)[1]=0;((u32*)out)[2]=0;return;}
 float p0[3],d0[3],p1[3],d1[3];
 float offset=window/ *(float*)(s+0x53);offset*=*(float*)(s+0x20);
 ext_460af0(path+0x1c,p0,d0,clamp(t-offset));
 offset=window/ *(float*)(s+0x53);offset*=*(float*)(s+0x20);
 path=*(u8**)(s+0x4b);ext_460af0(path+0x1c,p1,d1,clamp(t+offset));
 float distance=(float)ext_4e0830(p0,p1);
 if(G(float,0x679540)>distance)for(int i=0;i<3;i++)((u32*)out)[i]=((u32*)d0)[i];
 else ext_43e920(out,p1,p0);
 path=*(u8**)(s+0x4b);vcall<void>(path,0x88,out);
}
PCREG(523520,fn523520);
static void THISCALL fn54c7a0(u8*s,u8*event){
 if(*(u32*)(event+0x24)==10){
  s32 force=vcall<s32>(s,0x7c,event);if(force<-10000)force=-10000;else if(force>10000)force=10000;
  void *device=*(void**)(s+0x63ec);typedef s32(STDCALL *apply)(void*,s32);
  s32 hr=(*(apply*)(*(u8**)device+0x40))(device,force);if(hr<0)ext_54f2b0(hr,0x6a3c44);
 }else if(*(u32*)(event+0x24)==1){
  void *effect=*(void**)(s+0x63f0);if(!effect)return;
  u32 p[16];p[0]=0x40;p[7]=(u32)ext_633910(*(float*)(event+0xb4));p[8]=(u32)ext_633910(*(float*)(event+0xb8));
  p[14]=*(u32*)(event+0xb0);p[13]=*(u32*)(event+0xac);
  for(int i=0;i<3;i++)p[9+i]=*(u32*)(event+0x70+4*i);
  for(int i=0;i<4;i++)p[1+i]=*(u32*)(event+0x94+4*i);
  p[12]=(u32)_mm_cvtt_ss2si(_mm_set_ss(*(float*)(event+0xbc)));p[15]=0;
  p[5]=*(u32*)(event+0xa4);p[6]=*(u32*)(event+0xa8);
  typedef void(STDCALL *submit)(void*,u32*,u32);(*(submit*)(*(u8**)effect+0x30))(effect,p,1);
 }
}
PCREG(54c7a0,fn54c7a0);
