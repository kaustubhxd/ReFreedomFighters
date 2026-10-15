#include "ff.h"
static u32 rd2(void* p,u32 o){return *(u32*)((u8*)p+o);}
static void* p2(void* p,u32 o){return (void*)rd2(p,o);}
extern "C" void* ext_41e290(u32);
extern "C" void* ext_634d10(void*,u32,u32);
extern "C" void ext_634273(void*,u32);
extern "C" u32 ext_42ac56(void*,const void*,u32);
extern "C" void THISCALL f59fb50(void* self){
 if(*((u8*)self+0x93e))return;
 u32 set=vcall<u32>(self,0x680);
 *((u8*)self+0x143)=3;
 u32* table=(u32*)ext_41e290(0x188);
 ext_634d10(table,0,0x188);
 u32* old=(u32*)p2(self,0x936);
 for(u32 i=0;i<0x26;i++)table[i]=old[i];
 ext_634273(old,4);
 *(u32*)((u8*)self+0x936)=(u32)table;
 if(p2(G(void*,0x70039c),0x1a9f)&&set){
  u8 buf[20];
  for(u32 i=1;i<=59;i++){
   ext_42ac56(buf,(const void*)(i<=9?0x6aed14:0x6aed1c),i);
   void* sound=p2(G(void*,0x70039c),0x1a9f);
   *(u32*)((u8*)p2(self,0x936)+0x98+4*i)=vcall<u32>(sound,0x60,set,buf);
  }
 }
 *((u8*)self+0x93e)=1;
}
PCREG(59fb50,f59fb50);
extern "C" void THISCALL f5b7350(void* self,u32 formation,u32 member,u32 kind,u32 event){
 void* group=vcall<void*>(p2(self,0x48),0x2c,formation);
 if(!group)return;
 void* members=p2(group,4);
 if(member){
  void* entry=vcall<void*>(members,0x2c,member);
  if(!entry)return;
  void* actor=vcall<void*>(p2(G(void*,0x70039c),0x9b),0x58,rd2(entry,0));
  vcall<void>(actor,0x128,kind,event,0u);
 }else if(members){
  u32 it[3];vcall<void>(members,0x4c,it);
  members=p2(group,4);
  void* entry=vcall<void*>(members,0x64,it);
  while(entry){
   void* actor=vcall<void*>(p2(G(void*,0x70039c),0x9b),0x58,rd2(entry,0));
   vcall<void>(actor,0x128,kind,event,0u);
   members=p2(group,4);
   entry=vcall<void*>(members,0x64,it);
  }
 }
}
PCREG(5b7350,f5b7350);
