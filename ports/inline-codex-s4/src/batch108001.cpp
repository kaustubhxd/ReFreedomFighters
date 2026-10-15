#include "ff.h"
static u32 rd1(void* p,u32 off){return *(u32*)((u8*)p+off);}
static void* p1(void* p,u32 off){return (void*)rd1(p,off);}
extern "C" void THISCALL f56ac30(void* self){
 u32 mask=vcall<u32>(G(void*,0x7003a0),0x4c);
 void* pending[4];u32 n=0;
 for(u32 i=0;i<4;i++){
  void* item=vcall<void*>(p1(G(void*,0x70039c),0x9b),0x58,rd1(self,0x19c+4*i));
  if(!mask){vcall<void>(self,0xd0,0u);return;}
  if(mask&(1u<<i))vcall<void>(item,0x2d8);
  else pending[n++]=item;
 }
 for(u32 i=0;i<n;i++)vcall<void>(pending[i],0x2dc);
}
PCREG(56ac30,f56ac30);
extern "C" void THISCALL ext_56fb10(void*);
extern "C" void THISCALL f56ef50(void* self,const u8* text){
 u8* buf=(u8*)self+0x1c9;
 s32 oldlen=0,newlen=0;
 while(buf[oldlen])oldlen++;
 while(text[newlen])newlen++;
 if(oldlen<32-newlen && (oldlen || text[0]!=0x20)){
  for(s32 i=0;i<=newlen;i++)buf[oldlen+i]=text[i];
  u32 count=rd1(self,0x4b2);
  *(u32*)((u8*)self+0x3b2+4*count)=newlen;
  *(u32*)((u8*)self+0x4b2)=count+1;
  vcall<void>(p1(self,0x5ce),0x284,buf);
  ext_56fb10(self);
 }else vcall<void>(p1(self,0x5ca),0x248,0xff0000u);
 *((u8*)self+0x195)=1;
 vcall<void>(p1(self,0x5da),0xbc,0u);
}
PCREG(56ef50,f56ef50);
