#include "ff.h"
static u32 rd6(void* p,u32 o){return *(u32*)((u8*)p+o);}
static void* ptr6(void* p,u32 o){return (void*)rd6(p,o);}
static void* resolve6(u32 id){return vcall<void*>(ptr6(G(void*,0x70039c),0x9b),0x58,id);}
extern "C" void THISCALL f51cae0(void* self,void* hit){
 void* source=resolve6(rd6(hit,0xc));
 if(!source||source==self)return;
 resolve6(rd6(hit,8));
 void* projectile=resolve6(rd6(hit,0x10));
 if(!projectile)return;
 u32 kind=vcall<u32>(projectile,0x330);
 u32 event;
 if(kind==7)event=*(u16*)((u8*)self+0x5d3);
 else if(kind==4){
  if(!(u8)vcall<u32>(projectile,0x32c)||!rd6(self,0x479))return;
  void* target=resolve6(rd6(self,0x479));
  vcall<void>(target,0x8c,(u8*)ptr6(hit,0)+0x28);
  if(!(u8)vcall<u32>(target,0x184,(u8*)ptr6(hit,0)+0x28))return;
  event=*(u16*)((u8*)self+0x5d5);
 }else return;
 vcall<void>(self,0x130,self,event,0u);
}
PCREG(51cae0,f51cae0);
extern "C" void* ext_41e290(u32);
extern "C" void* ext_634d22(void*,void*,u32);
extern "C" void* THISCALL f5333f0(void* self,u32* outsize){
 void* data=ptr6(self,0x52fe);
 u32 count0=rd6(data,0x11e9),count1=rd6(data,0x11f1),count2=rd6(data,0x11ed),count3=rd6(data,0x11f5);
 u32 len0=count0*0xa4,len1=count1*12,len2=count2*8,len3=count3*4;
 u32 total=16+len0+len1+len2+len3;
 u8* buffer=(u8*)ext_41e290(total);
 *(u32*)buffer=count0;*(u32*)(buffer+4)=count1;*(u32*)(buffer+8)=count2;*(u32*)(buffer+12)=count3;
 u8* cursor=buffer+16;
 ext_634d22(cursor,ptr6(ptr6(self,0x52fe),0x11f9),len0);cursor+=len0;
 ext_634d22(cursor,ptr6(ptr6(self,0x52fe),0x11fd),len1);cursor+=len1;
 ext_634d22(cursor,ptr6(ptr6(self,0x52fe),0x1201),len2);cursor+=len2;
 ext_634d22(cursor,ptr6(ptr6(self,0x52fe),0x1205),len3);
 *outsize=total;return buffer;
}
PCREG(5333f0,f5333f0);
