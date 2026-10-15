#include "ff.h"
extern "C" void THISCALL ext_644e70(void*,void*);
extern "C" void THISCALL ext_45d380(void*,u32,u32);
extern "C" void* THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_5002f0(void*,u32);
extern "C" void THISCALL ext_500360(void*,float);
static u8 THISCALL fn650d00(u8*s,void*stream){
 vcall<void>(stream,8,0x13u);
 u8 *base=*(u8**)(s+0x20);u8 *start=base+*(u32*)(base+4);
 u32 size=(u32)*(u8**)(s+0x28)-(u32)start;
 vcall<void>(stream,0x3c,size);
 if(size){
  void *report=vcall<void*>(G(void*,0x700390),0x20,0x6c3180u,0x623u);
  double d=(double)(s32)size+G(double,0x680aa0+8*(size>>31));
  float amount=(float)d*G(float,0x6c2800);
  typedef void(*logfn)(void*,u32,double);
  (*(logfn*)(*(u8**)report+0x2c))(report,0x6c35a4,(double)amount);
  vcall<void>(stream,0x10,start,size);
 }
 ext_644e70(*(void**)(s+0x38),stream);
 u8 *sys=G(u8*,0x70039c);vcall<void>(*(void**)(sys+0x190f),0x1a8,stream);
 return 1;
}
PCREG(650d00,fn650d00);
static u32 THISCALL fn44ba90(u8*s,u32 id,u32 arg){
 ext_45d380(s,id,arg);
 if((u16)id==G(u16,0x6ff96c)){
  u8 *state=*(u8**)(s+0x18);u32 mode=*(u32*)(state+4);
  if(mode==1 || mode==8){
   state[0xec]=1;u8 *sys=G(u8*,0x70039c);
   *(float*)(state+0xed)=(float)*(s32*)(sys+0x40)*G(float,0x6785e4);
   float value=*(float*)(state+0x88);*(float*)(state+0xf1)=value;
   *(float*)(state+0xf5)=value*G(float,0x67a6ac);
  }else{
   *(u32*)(state+4)=12;u8 *sys=G(u8*,0x70039c);void *service=*(void**)(sys+0x1a9f);
   if(service)vcall<void>(service,0x50,*(u32*)(s+0x1c));
  }
 }else if((u16)id==G(u16,0x6ff970))vcall<void>(s,0x24,1u);
 else if((u16)id==G(u16,0x6ff974))vcall<void>(s,0x24,0u);
 return 0;
}
PCREG(44ba90,fn44ba90);
static u32 STDCALL fn551430(void*a,u32 id,u32*values){
 void *o=vcall<void*>(a,0x18,id);if(!o)return 0;
 void *cells=vcall<void*>(o,0x4c);
 for(u32 i=0;i<4;i++)ext_500360(ext_5003d0(cells,i),bitsf(values[i]));
 for(u32 i=4;i<6;i++)ext_5002f0(ext_5003d0(cells,i),values[i]);
 return (u32)o;
}
PCREG(551430,fn551430);
static void THISCALL fn502100(u8*s,u8*args){
 u8 *value=(u8*)ext_5003d0(*(void**)(args+4),1);u32 key;
 if(value[4]==3)key=*(u32*)value;
 else if(value[4]==4)key=vcall<u32>(*(void**)value,0x34);
 else{
  void *report=vcall<void*>(G(void*,0x700390),0x20,0x69c8e0u,0x111u);
  typedef void(*logfn)(void*,u32,u32);
  (*(logfn*)(*(u8**)report+0x2c))(report,0x69c6b0,0x69c9b0);
  typedef void(*assertfn)();assertfn hook=G(assertfn,0x7003b0);if(hook)hook();else __builtin_trap();
  key=0;
 }
 u8 *sys=G(u8*,0x70039c);
 u16 handle=(u16)vcall<u32>(*(void**)(sys+0x9b),0x114,key,0u,0x69ca10u,0x291u);
 u32 f=*(u32*)ext_5003d0(*(void**)(args+4),2);
 u32 first=*(u32*)ext_5003d0(*(void**)(args+4),0);
 vcall<void>(*(void**)(s+0xc),0x12c,first,(u32)handle,&f);
}
PCREG(502100,fn502100);
