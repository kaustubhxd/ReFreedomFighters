#include "ff.h"
static u32 rd9(void* p,u32 o){return *(u32*)((u8*)p+o);}
static void* ptr9(void* p,u32 o){return (void*)rd9(p,o);}
extern "C" void* THISCALL ext_5003d0(void*,u32);
extern "C" void* THISCALL ext_5002f0(void*,u32);
static void bad9(){
 void* log=vcall<void*>(G(void*,0x700390),0x20,0x69c8e0u,0x111u);
 typedef void(*Print)(void*,u32,u32);
 ((Print)*(u32*)(*(u32*)log+0x2c))(log,0x69c6b0u,0x69c9b0u);
 typedef void(*Assert)();((Assert)G(u32,0x7003b0))();
}
static void* lookup9(){return vcall<void*>(ptr9(G(void*,0x70039c),0x9b),0x138);}
extern "C" void STDCALL f50fe30(void* input){
 u8* value=(u8*)ext_5003d0(ptr9(input,4),0);
 u32 ref=0;
 if(value[4]==3)ref=*(u32*)value;
 else if(value[4]==4)ref=vcall<u32>(*(void**)value,0x34);
 else bad9();
 u8 found=0;
 vcall<void>(lookup9(),0x90,ref,&found);
 void* manager=lookup9();
 value=(u8*)ext_5003d0(ptr9(input,4),1);
 vcall<void>(manager,0x68,ref,(u32)(*(u32*)value!=0),0u);
 value=(u8*)ext_5003d0(ptr9(input,8),0);
 ext_5002f0(value,found);
}
PCREG(50fe30,f50fe30);
extern "C" void THISCALL ext_515c70(void*);
extern "C" void THISCALL ext_518bc0(void*);
extern "C" void THISCALL ext_519280(void*);
extern "C" void THISCALL ext_518960(void*);
extern "C" void THISCALL ext_5251c0(void*,void*,void*,void*,void*,u32,u32,u32,u32);
static bool flagged9(void* target){return (rd9(ptr9(target,8),0x3c)&0x1000)!=0;}
extern "C" void THISCALL f518850(void* self){
 ext_515c70(self);
 u32 id=rd9(self,0x123);
 if(*((u8*)self+0x133)){
  if(!id)return;
  void* target=vcall<void*>(ptr9(G(void*,0x70039c),0x9b),0x58,id);
  if(!flagged9(target))return;
  u8* pos=(u8*)self+0x60;u8* basis=(u8*)self+0x6c;
  vcall<void>(self,0x80,basis,pos);
  ext_5251c0((u8*)self+0x2d8,basis,pos,pos,basis,0,0,0,0);
  vcall<void>(self,0x7c,basis,pos);
  return;
 }
 void* target=vcall<void*>(ptr9(G(void*,0x70039c),0x9b),0x58,id);
 if(target&&flagged9(target)){
  ext_518bc0(self);ext_519280(self);ext_518960(self);return;
 }
 *(u32*)((u8*)self+0x1603)=0;
 ext_518bc0(self);
 void* source=ptr9(self,0x5c);
 for(u32 i=0;i<3;i++)*(u32*)((u8*)self+0x60+4*i)=rd9(source,8+4*i);
 vcall<void>(self,0x78,(u8*)self+0x60);
}
PCREG(518850,f518850);
