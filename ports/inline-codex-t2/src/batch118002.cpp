#include "ff.h"
extern "C" void THISCALL ext_451d00(u8*,void*);
extern "C" void THISCALL ext_4e14a0(void*,void*,u32);
extern "C" void THISCALL ext_4e12f0(void*,void*,u32);
extern "C" void THISCALL ext_4e11e0(void*,void*,u32);
extern "C" void THISCALL ext_4e12e0(void*,void*,u32);
extern "C" void THISCALL ext_4e1b30(void*);
extern "C" long double FASTCALL ext_4e0870(void*,void*);
extern "C" void THISCALL ext_516040(void*,float);
extern "C" void THISCALL ext_4de7a0(void*);
extern "C" void THISCALL ext_4daf90(void*,void*);
extern "C" void THISCALL ext_4db600(void*,void*,void*);
extern "C" void THISCALL ext_4db7c0(void*,void*);
extern "C" void FASTCALL ext_4e2c60(void*,void*);
extern "C" void THISCALL ext_4e4ef0(void*,u32,void*,void*);
extern "C" void THISCALL ext_5cc880(void*,u32);
extern "C" void THISCALL ext_5a7530(void*,u32);
extern "C" void FASTCALL ext_4de040(void*,void*,u32);
extern "C" void FASTCALL ext_4de420(void*,void*);
extern "C" void THISCALL begin_effect(u8* s) {
 vcall<void>(*(void**)(s+0x44),0x40);
 *(u32*)(*(u8**)(*(u8**)(s+0x44)+0x10)+0x18)|=2u;
 if(!s[0x64]) vcall<void>(s,0x68,0x10u,0u);
 u8* sys=G(u8*,0x70039c);*(u32*)(s+0x56)=*(u32*)(sys+0x40);
 u32 a,b,c;
 void* mgr=*(void**)(*(u8**)(sys+0x1aa3)+0x18);
 u32 id=*(u32*)(*(u8**)(*(u8**)(s+0x44)+8)+0x6c);
 u8 ok=vcall<u8>(mgr,0xd4,id,&a,&b,&c);
 if(!ok){vcall<void>(s,0x58);return;}
 *(float*)(s+0x4a)=(float)a;
 vcall<void>(*(void**)(s+0x44),0x3c,1u);
 if(!s[0x5e]) vcall<void>(s,0x68,0x10u,0u);
}
PCREG(4a4db0,begin_effect);
extern "C" void THISCALL read_overlay(u8* s,void* reader) {
 ext_451d00(s,reader);
 ext_4e14a0(reader,s+0xbc,1);
 ext_4e12f0(reader,s+0xa0,3);
 ext_4e12f0(reader,s+0xb8,1);
 ext_4e12f0(reader,s+0xbd,1);
 ext_4e11e0(reader,s+0x88,2);
 ext_4e12f0(reader,s+0x90,2);
 ext_4e12f0(reader,s+0x98,2);
 ext_4e12e0(reader,s+0x80,1);
 ext_4e1b30(reader);
 if(!*(u32*)(s+0x88))*(u32*)(s+0x88)=1;
 if(!*(u32*)(s+0x8c))*(u32*)(s+0x8c)=1;
 float factor=G(float,0x67da04);
 for(u32 i=0;i<4;++i)*(float*)(s+0x90+4*i)=*(float*)(s+0x90+4*i)*factor;
}
PCREG(4583d0,read_overlay);
extern "C" void THISCALL receive_impact(u8* s,float amount,void* point) {
 *(u32*)(s+0x84)=G(u32,G(u32,0x70039c)+0x40)+0x1c00u;
 for(s32 i=0;i<*(s32*)(s+0x8c);++i) {
  long double dist=ext_4e0870(s+0x7c9+0x163*i,point);
  float inv=(float)((long double)G(float,0x67cd40)/dist);
  float capped=_mm_cvtss_f32(_mm_min_ss(_mm_set_ss(G(float,0x678858)),_mm_set_ss(inv)));
  ext_516040(s+0xbd+0xde*i,capped*amount);
 }
 for(s32 i=0;i<*(s32*)(s+0x90);++i) {
  long double dist=ext_4e0870(s+0xd55+0x133*i,point);
  float inv=(float)((long double)G(float,0x67cd40)/dist);
  float capped=_mm_cvtss_f32(_mm_min_ss(_mm_set_ss(G(float,0x678858)),_mm_set_ss(inv)));
  ext_516040(s+0x435+0xde*i,capped*amount);
 }
}
PCREG(525e20,receive_impact);
extern "C" void THISCALL update_bounds(u8* s,u8* geometry) {
 if(!*(u32*)(geometry+0x64))return;
 void* target=vcall<void*>(s,0x314);
 float matrix[18],center[3],extent[3],lo[3],hi[3];
 ext_4de7a0(matrix);
 ext_4daf90(geometry,center);
 ext_4db600(geometry,matrix,center);
 ext_4db7c0(geometry,extent);
 vcall<void>(s,0x94,matrix,center);
 ext_4e2c60(matrix,extent);
 for(u32 i=0;i<3;++i){lo[i]=center[i]-extent[i];hi[i]=center[i]+extent[i];}
 ext_4e4ef0(target,*(u32*)(geometry+0x64),lo,hi);
}
PCREG(4439b0,update_bounds);
extern "C" void THISCALL relax_aim(u8* s) {
 for(u32 i=0;i<4;++i)*(u32*)(s+0xb1f+4*i)=0;
 ext_5cc880(*(void**)(s+0xb54),0);
 *(u32*)(s+0xad5)=0;
 if(*(void**)(s+0xe18))ext_5a7530(*(void**)(s+0xe18),0);
 float angle=*(float*)(s+0xaed),goal=G(float,0x6b4ff0);
 float step=G(float,G(u32,0x70039c)+0x48)*G(float,0x68af1c);
 step=step*G(float,0x67da04);
 if(angle>goal){angle=angle-step;*(float*)(s+0xaed)=angle;if(goal>angle)*(u32*)(s+0xaed)=0xbf9c61aa;}
 else if(goal>angle){angle=angle+step;*(float*)(s+0xaed)=angle;if(angle>goal)*(u32*)(s+0xaed)=0xbf9c61aa;}
 double cp=crt::cos(*(float*)(s+0xaed));
 float vec[3];
 vec[0]=(float)(crt::cos(*(float*)(s+0xae9))*cp);
 vec[1]=(float)crt::sin(*(float*)(s+0xaed));
 vec[2]=(float)(crt::sin(*(float*)(s+0xae9))*cp);
 u32 matrix[9];ext_4de040(matrix,vec,0);ext_4de420(s+0xc89,matrix);
}
PCREG(5cff20,relax_aim);
