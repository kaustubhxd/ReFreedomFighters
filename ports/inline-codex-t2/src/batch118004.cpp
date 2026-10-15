#include "ff.h"
extern "C" void THISCALL ext_5a2860(void*);
extern "C" void THISCALL remove_follower(u8* s,u8* follower){
 u8* list=s+0xa16;u32 i=0;
 for(;i<*(u32*)list;++i)if(*(u32*)(list+4+0x30*i)==(u32)follower)break;
 if(i==*(u32*)list){
  void* log=vcall<void*>(G(void*,0x700390),0x20,0x6ac6d0u,0x595u);
  typedef void(*print)(void*,u32,u32);
  (*(print*)(*(u8**)log+0x2c))(log,0x6aca58,*(u32*)(follower+4)?*(u32*)(follower+4):0x67c8e8);
  return;
 }
 for(;i+1<*(u32*)list;++i)for(u32 k=0;k<3;++k)
  _mm_storeu_ps((float*)(list+4+0x30*i+16*k),_mm_loadu_ps((float*)(list+4+0x30*(i+1)+16*k)));
 --*(u32*)list;ext_5a2860(follower);
}
PCREG(594460,remove_follower);
extern "C" double VECTORCALL ext_634dd6(double);
extern "C" double VECTORCALL ext_634db2(double,double);
extern "C" void THISCALL volume_ramp(u8* s){
 if(!s[0x4c])return;
 if(*(float*)(s+0x4e)==0.0f)*(float*)(s+0x4e)=(float)G(s32,G(u32,0x70039c)+0x40)*G(float,0x6785e4);
 float end=(*(float*)(s+0x52)+*(float*)(s+0x4e))*G(float,0x678620);
 u8* sys=G(u8*,0x70039c);
 if(*(s32*)(sys+0x40)<_mm_cvttss_si32(_mm_set_ss(end)))return;
 if(!s[0x4d]){
  float initial=(float)(ext_634dd6(*(float*)(*(u8**)(*(u8**)(s+0x44)+0x18)+0x84))*G(double,0x693d50));
  s[0x4d]=1;*(float*)(s+0x5a)=initial;
  *(float*)(s+0x62)=(*(float*)(s+0x5e)-initial)/(*(float*)(s+0x56)-*(float*)(s+0x52));
  sys=G(u8*,0x70039c);
 }
 float slope=*(float*)(s+0x62);
 float value=G(float,0x678858)/(*(float*)(sys+0x48)*slope);
 value=value+*(float*)(s+0x5a);
 *(float*)(s+0x5a)=value;
 float target=*(float*)(s+0x5e);
 if((slope<0.0f)?target>value:value>target)*(float*)(s+0x5a)=target;
 float exponent=*(float*)(s+0x5a)/G(float,0x67da20);
 double power=ext_634db2(G(double,0x692790),(double)exponent);
 *(float*)(*(u8**)(*(u8**)(s+0x44)+0x18)+0x84)=(float)power;
 end=(*(float*)(s+0x56)+*(float*)(s+0x4e))*G(float,0x678620);
 if(G(s32,G(u32,0x70039c)+0x40)>=_mm_cvttss_si32(_mm_set_ss(end)))vcall<void>(s,0x68,0x10u,0u);
}
PCREG(4c0010,volume_ramp);
extern "C" void* THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_5002f0(void*,u32);
extern "C" u8* THISCALL ext_5a46f0(void*,u32);
extern "C" void STDCALL unpack_record(u8* args){
 u32 key=*(u32*)ext_5003d0(*(void**)(args+4),0);
 u8* rec=ext_5a46f0(*(void**)(G(u8*,0x7003b8)+0x2c21),key);
 ext_5002f0(ext_5003d0(*(void**)(args+8),0),(u32)rec[0]);
 ext_5002f0(ext_5003d0(*(void**)(args+8),1),*(u32*)(rec+2));
 ext_5002f0(ext_5003d0(*(void**)(args+8),2),*(u32*)(rec+6));
 ext_5002f0(ext_5003d0(*(void**)(args+8),3),*(u32*)(rec+10));
 u32 value=*(u32*)(rec+14);
 u8* out=(u8*)ext_5003d0(*(void**)(args+8),4);
 if(out[4]!=0 && out[4]!=2){
  void* log=vcall<void*>(G(void*,0x700390),0x20,0x69c8e0u,0x104u);
  typedef void(*print)(void*,u32,u32);
  (*(print*)(*(u8**)log+0x2c))(log,0x69c6b0,0x69c938);
  typedef void(*assert_fn)();G(assert_fn,0x7003b0)();
 }
 out[4]=2;*(u32*)out=value;
}
PCREG(55fd40,unpack_record);
