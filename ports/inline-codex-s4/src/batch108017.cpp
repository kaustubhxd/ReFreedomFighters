#include "s4_mem.h"
extern "C" void ext_40fa40(void*);
extern "C" void ext_403ee0(void*);
extern "C" void ext_634d52(void*);
extern "C" void f407a10(void* self){
 if(!self)return;
 ext_40fa40(self);
 for(s32 i=0;i<(s32)s4r(s4p(self,0x10),0);i++){
  typedef void(*Destroy)(u32);
  for(u32 group=0;group<3;group++){
   void* descriptor=s4p(s4p(self,0x28+4*group),4*i);
   u32 value=s4r(s4p(self,0x14+4*group),4*i);
   ((Destroy)s4r(descriptor,0x14))(value);
  }
 }
 void* second=s4p(self,0x24);
 if(second&&second!=s4p(self,0x20)){ext_403ee0(second);ext_634d52(s4p(self,0x24));}
 if(s4p(self,0x20)){ext_403ee0(s4p(self,0x20));ext_634d52(s4p(self,0x20));}
 for(u32 i=0;i<3;i++)ext_634d52(s4p(self,0x28+4*i));
 for(u32 i=0;i<3;i++)ext_634d52(s4p(self,0x14+4*i));
 for(u32 i=0;i<15;i++)s4w(self,4*i,0);
 ext_634d52(self);
}
PCREG(407a10,f407a10);
static u32 address17(u32 base,u32 index){return base+12*index;}
extern "C" u32 THISCALL f4320e0(void* self,u32 node){
 u32 key=vcall<u32>(self,0x10,node),category=key>>16,index=(u16)key;
 u32 base,count;
 if(category<=2){
  void* table=s4p(G(void*,0x70039c),0x190b);
  base=s4r(table,8+16*category);count=s4r(table,12+16*category);
 }else{
  if(category==0x42){
   void* table=s4p(G(void*,0x70039c),0x190b);
   for(u32 i=0;i<3;i++){
    u32 start=s4r(table,16*i),length=s4r(table,12+16*i);
    if((s32)start<=(s32)index&&(s32)(start+length)>(s32)index)return address17(s4r(table,8+16*i),index-start);
   }
  }
  base=node;count=node;
 }
 if((s32)count>0&&index<count)return address17(base,index);
 return 0;
}
PCREG(4320e0,f4320e0);
