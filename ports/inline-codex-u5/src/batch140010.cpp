#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(void*,u32);
extern "C" char* THISCALL ext_506040(void*);
extern "C" void* ext_5fa630();
extern "C" void THISCALL debug_log(void*,u8* arg){
 if(!G(u8*,0x70039c)[0x1b3d])return;
 char buf[100];char* str=0;
 u8 tag=ext_5003d0(*(void**)(arg+4),0)[4];
 if(tag==4)str=ext_506040(ext_5003d0(*(void**)(arg+4),0));
 else if(tag==1 || tag==2){
  void* fmt=ext_5fa630();u8* value=ext_5003d0(*(void**)(arg+4),0);
  if(tag==1)(*(void(**)(void*,char*,u32,u32))(*(u8**)fmt+0x14))(fmt,buf,0x69d384,*(u32*)value);
  else (*(void(**)(void*,char*,u32,double))(*(u8**)fmt+0x14))(fmt,buf,0x6792bc,(double)*(float*)value);
  str=buf;
 }else{
  void* logger=vcall<void*>(G(void*,0x700390),0x20,0x69d350u,0x98u);
  (*(void(**)(void*,u32,u32))(*(u8**)logger+0x2c))(logger,0x69c6b0,0x69d388);
  (*(void(*)())G(void*,0x7003b0))();
 }
 void* logger=vcall<void*>(G(void*,0x700390),0x20,0x69d350u,0x9cu);
 float time=(float)*(s32*)(G(u8*,0x70039c)+0x40)*G(float,0x6785e4);
 (*(void(**)(void*,u32,double,char*))(*(u8**)logger+0x2c))(logger,0x69d39c,(double)time,str);
}
PCREG(50aac0,debug_log);
