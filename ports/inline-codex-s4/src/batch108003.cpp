#include "ff.h"
static u32 rd3(void* p,u32 o){return *(u32*)((u8*)p+o);}
static void* p3(void* p,u32 o){return (void*)rd3(p,o);}
extern "C" void THISCALL f5c2b00(void* self,const u8* name,u32 value,u32 flag,u32 other,u32 otherflag){
 s32 n=(s32)rd3(self,0x2c0);
 for(s32 i=0;i<n;i++){
  const u8* stored=(const u8*)p3(self,8+14*i);
  u32 j=0;while(name[j]==stored[j] && name[j])j++;
  if(name[j]==stored[j])return;
 }
 if(n>=16)return;
 u8* entry=(u8*)self+8+14*n;
 *(u32*)entry=(u32)name;
 *(u32*)(entry+4)=value;
 entry[12]=(u8)flag;
 *(u32*)(entry+8)=other?other:value;
 entry[13]=(u8)(other?otherflag:flag);
 *((u8*)self+0xe8+n)=0;
 *(u32*)((u8*)self+0x2c0)=n+1;
}
PCREG(5c2b00,f5c2b00);
extern "C" u32 THISCALL ext_5ffb00(void*,u32);
extern "C" u32 THISCALL f5fffc0(void* self,u32 key){
 void* node=self;
 while(node){
  u32 count=rd3(node,0xd0);
  u32* keys=(u32*)p3(node,0xe0);
  for(u32 i=0;i<count;i++)if(keys[i]==key){
   u32 index=((u16*)p3(node,0xf0))[i];
   if(rd3(node,0xa8)&&rd3(node,0xa0)<=index){
    index=(u16)(index-rd3(node,0xa0));
    if(index<rd3(node,0xa8))return ((u32*)p3(node,0xac))[index]+rd3(node,0xb0);
    void* log=vcall<void*>(G(void*,0x700390),0x20,(u32)0x6b9420,0x137u);
    // This logger slot is cdecl, with the log object also on the stack.
    typedef void(*Print)(void*,u32,u32);
    ((Print)*(u32*)(*(u32*)log+0x2c))(log,0x69c6b0,0x6b9474);
   }else{
    void* parent=p3(node,0x9c);
    if(parent)return ext_5ffb00(parent,index);
   }
   typedef void(*Assert)();((Assert)G(u32,0x7003b0))();
   return key;
  }
  node=p3(node,0x9c);
 }
 return 0x6b963c;
}
PCREG(5fffc0,f5fffc0);
