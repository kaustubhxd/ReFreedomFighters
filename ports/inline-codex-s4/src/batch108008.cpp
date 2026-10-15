#include "ff.h"
static u32 rd8(void* p,u32 o){return *(u32*)((u8*)p+o);}
static void* ptr8(void* p,u32 o){return (void*)rd8(p,o);}
extern "C" void THISCALL ext_440e10(void*,void*);
extern "C" u8 THISCALL f46f6e0(void* self,void* reader){
 ext_440e10(self,reader);
 vcall<void>(reader,0x70,rd8(self,0x70));
 vcall<void>(reader,0x74,(u8*)self+0xdb);
 vcall<void>(reader,0x6c,(u8*)self+0xff);
 vcall<void>(reader,0x50,(u8*)self+0x10b);
 vcall<void>(reader,0x50,(u8*)self+0x10f);
 for(u32 offset=0x11b;offset<=0x127;offset+=4){
  u32 ref;vcall<void>(reader,0x40,&ref);
  void* target=vcall<void*>(ptr8(G(void*,0x70039c),0x9b),0x58,ref);
  *(u32*)((u8*)self+offset)=(u32)target;
 }
 return 1;
}
PCREG(46f6e0,f46f6e0);
extern "C" void* ext_41e290(u32);
extern "C" void ext_634273(void*,u32);
extern "C" void THISCALL f4d0b30(void* self){
 void** list=(void**)ext_41e290(rd8(self,0x8224)*4);
 u32 n=0;
 for(void* node=ptr8(self,0x8220);node;node=ptr8(node,4))list[n++]=node;
 for(u32 i=0;i<n;i++){
  u8* at=(u8*)list[i]+0x10;
  s32 size=(s32)rd8(at,8);
  while(size){
   if(size>0)at+=0x10+(u32)size;
   else{
    u8* next=at-(u32)size;
    s32 following=(s32)rd8(next,0x18);
    next+=0x10;
    if(following>0)next+=0x10+(u32)following;
    if(rd8(at,4)!=0xffffffff){
     void* log=vcall<void*>(G(void*,0x700390),0x20,0x695dc0u,0xf9u);
     typedef void(*Print)(void*,u32,u32,u32);
     ((Print)*(u32*)(*(u32*)log+0x2c))(log,0x695e30u,rd8(at,4),0u-rd8(at,8));
    }
    at=next;
   }
   size=(s32)rd8(at,8);
  }
 }
 ext_634273(list,4);
}
PCREG(4d0b30,f4d0b30);
