#include "ff.h"
extern "C" void THISCALL ext_4658d0(void*,void*);
extern "C" void THISCALL reset_facing(u8* s,u32 unused,u32 a,u32 b,u32 c,u32 d){
 if(s[0x158])return;
 u8* state=s+0x16d;ext_4658d0(state,s);
 *(u32*)(s+0x136)&=0xffdfffff;
 *(u32*)(s+0x1aa)=a;*(u32*)(s+0x1ae)=b;*(u32*)(s+0x1b2)=c;*(u32*)(s+0x1b6)=d;
 float start=*(float*)(state+0x35),dur=*(float*)(state+0x31);
 float absolute=bitsf(fbits(start)&0x7fffffff);
 s32 ticks=_mm_cvttss_si32(_mm_set_ss(absolute*G(float,0x678620)));
 u32 delta=G(u32,G(u32,0x70039c)+0x40)-(u32)ticks;
 float elapsed=(float)(s32)delta*G(float,0x6785e4),blend;
 if(start>=0.0f){blend=(dur>elapsed)?elapsed/dur:G(float,0x678858);}
 else if(elapsed>dur || dur==0.0f)blend=0.0f;
 else blend=G(float,0x678858)-elapsed/dur;
 *(u32*)(state+0x31)=0;*(u32*)(state+0x39)=0;
 u32 clock=0u-G(u32,G(u32,0x70039c)+0x40);
 if(!(blend==G(float,0x678858))){
  float f=G(float,0x678858)-blend;f=f*0.0f;f=f*G(float,0x67862c);
  clock-=(u32)_mm_cvttss_si32(_mm_set_ss(f));
 }
 *(float*)(state+0x35)=(float)(s32)clock*G(float,0x6785e4);
 vcall<void>(s,0x408);
}
PCREG(4675e0,reset_facing);
extern "C" void THISCALL init_sound(u8* s){
 G(u8,0x711b70)=0;s[0xc]=0;
 u8* sys=G(u8*,0x70039c);
 *(u16*)(s+0x50a7)=(u16)vcall<u32>(*(void**)(sys+0x9b),0x114,0x69f024u,0u,0x6a1e2cu,0x100u);
 void* config=vcall<void*>(G(void*,0x70039c),0xbc);
 if(config){
  u32 a=vcall<u32>(config,0x7c,0u);vcall<void>(s,0x104,0u,a);
  u32 b=vcall<u32>(config,0x84,0u);vcall<void>(s,0x104,1u,b);
  u32 c=vcall<u32>(config,0x8c,0u);vcall<void>(s,0x104,2u,c);
  *(float*)(s+0x87)=(float)vcall<s32>(config,0x5c,0x67a048u,3u);
 }
 if(vcall<u8>(s,0x1f8)){s[0x50ba]=1;return;}
 void* log=vcall<void*>(G(void*,0x700390),0x20,0x6a1e2cu,0x117u);
 typedef void(*print)(void*,u32);(*(print*)(*(u8**)log+0x2c))(log,0x6a1e5c);
}
PCREG(5378a0,init_sound);
extern "C" void THISCALL ext_4e09b0(void*);
extern "C" void THISCALL ext_4e0d80(void*,float);
extern "C" void FASTCALL ext_441940(void*,void*);
extern "C" void THISCALL shadow_pos(u8* s,u32* pos,u32* direction,float distance,u32 filter){
 *(u32*)(s+0xb8f)=0x3f800000;s[0xbc7]=1;
 u32 delta[3]={direction[0],direction[1],direction[2]};ext_4e09b0(delta);ext_4e0d80(delta,distance);
 u32 p[3]={pos[0],pos[1],pos[2]};ext_441940(p,delta);
 for(u32 i=0;i<3;++i){pos[i]=p[i];*(u32*)(s+0xb5b+4*i)=pos[i];}
 *(u32*)(s+0xb67)=0;*(u32*)(s+0xb6b)=0xc59c4000;*(u32*)(s+0xb6f)=0;
 u8* table=*(u8**)(G(u8*,0x70039c)+0x9b);
 if(vcall<u8>(*(void**)(table+0xadc),0x2e0,s+0xb5b,0u,filter,0xffffffffu,1u,0u))
  for(u32 i=0;i<3;++i)pos[i]=*(u32*)(s+0xb83+4*i);
}
PCREG(5cefc0,shadow_pos);
extern "C" void THISCALL ext_562260(void*);
extern "C" void THISCALL ext_4db500(void*,void*);
extern "C" void FASTCALL ext_43e8e0(void*,void*,void*);
extern "C" void THISCALL ext_4f7950(void*);
extern "C" void THISCALL frame_vectors(u8* s){
 ext_562260(s);
 if(*(u32*)(s+0xdc)!=2){
  u32 base[3],sum[3];ext_4db500(*(void**)(*(u8**)(s+0x54)+8),base);
  ext_43e8e0(sum,s+0x34b,base);
  vcall<void>(*(void**)(s+0x310),0x70,sum);
  base[0]^=G(u32,0x67af40);base[1]^=G(u32,0x67af40);
  vcall<void>(*(void**)(s+0x314),0x70,base);
  ext_4f7950(*(void**)(s+0x310));
 }
 if(*(u32*)(s+0x33c)){
  u8* sys=G(u8*,0x70039c);
  if(vcall<u8>(*(void**)(sys+0x1907),0x2c,*(u32*)(s+0x324),0u)){
   vcall<void>(s,0x98,0x2710u);vcall<void>(s,0x94,0x2710u);
  }
  sys=G(u8*,0x70039c);
  if(vcall<u8>(*(void**)(sys+0x1907),0x2c,*(u32*)(s+0x328),0u)){
   vcall<void>(s,0x98,0x2711u);vcall<void>(s,0x94,0x2711u);
  }
 }
}
PCREG(57d340,frame_vectors);
extern "C" void FASTCALL ext_4df9f0(float*,float*,float);
extern "C" void THISCALL axis_angle(float* out,float angle,float x,float y,float z){
 float sine,cosine;ext_4df9f0(&sine,&cosine,angle*G(float,0x67da04));
 float w=G(float,0x678858)-cosine;
 out[6]=(x*x)*w+cosine;
 out[7]=(x*y)*w-z*sine;
 out[8]=(x*z)*w+y*sine;
 out[3]=(y*x)*w+z*sine;
 out[4]=(y*y)*w+cosine;
 out[5]=(y*z)*w-x*sine;
 out[0]=(z*x)*w-y*sine;
 out[1]=(z*y)*w+x*sine;
 out[2]=(z*z)*w+cosine;
}
PCREG(4deb20,axis_angle);
