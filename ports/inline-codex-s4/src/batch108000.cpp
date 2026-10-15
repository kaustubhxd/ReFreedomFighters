#include "ff.h"
extern "C" void THISCALL ext_4db7c0(void*,void*);
extern "C" void THISCALL ext_44b850(void*,u32);
extern "C" void THISCALL ext_44b880(void*,u32);
static u32 rd4(void* p,u32 o){return *(u32*)((u8*)p+o);}
static void* ptr4(void* p,u32 o){return (void*)rd4(p,o);}
extern "C" void THISCALL f4c5770(void* self,u32 flag){
 void* tab=ptr4(self,0x48);
 if(!tab)return;
 u32 it[3];
 vcall<void>(tab,0x4c,it);
 u32 id=vcall<u32>(ptr4(self,0x48),0x5c,it);
 while(it[0]){
  void* sys=G(void*,0x70039c);
  void* item=vcall<void*>(ptr4(sys,0x9b),0x58,id);
  u32 pos[3], bounds[9], size[3];
  ext_4db7c0(ptr4(item,8),pos);
  vcall<void>(item,0x80,bounds,size);
  vcall<void>(ptr4(self,0x53),0x21c,size,pos,flag);
  id=vcall<u32>(ptr4(self,0x48),0x5c,it);
 }
}
PCREG(4c5770,f4c5770);
extern "C" u32 THISCALL f4c24b0(void* self){
 void* owner=ptr4(self,0x44);
 u32 it[3];
 void* first=(u8*)self+0x54;
 if(vcall<u32>(first,0x14)){
  vcall<void>(first,0x4c,it);
  u32 id=vcall<u32>(first,0x5c,it);
  while(it[0]){ext_44b850(ptr4(owner,0x18),id);id=vcall<u32>(first,0x5c,it);}
 }
 void* second=(u8*)self+0x100;
 if(vcall<u32>(second,0x14)){
  vcall<void>(second,0x4c,it);
  u32 id=vcall<u32>(second,0x5c,it);
  while(it[0]){ext_44b880(ptr4(owner,0x18),id);id=vcall<u32>(second,0x5c,it);}
 }
 return vcall<u32>(self,0x58);
}
PCREG(4c24b0,f4c24b0);
