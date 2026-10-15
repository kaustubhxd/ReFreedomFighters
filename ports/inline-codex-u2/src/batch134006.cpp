#include "ff.h"
template<class R,class... A>static R comcall(void* o,u32 off,A...a){typedef R(STDCALL*Fn)(void*,A...);return (*(Fn*)(*(u8**)o+off))(o,a...);}
static u32 THISCALL fn54edb0(u8* s,void* device,void* buffer,u32 activate){
 G(u32,s+0x80)=1;
 const u32 offsets[]={0xecu,0xdcu,0x9cu,0xa8u,0xbcu,0xe8u,0xa4u,0xb8u,0x90u,0x8cu};
 for(u32 off: offsets)G(u32,s+off)=0;
 G(float,s+0x98)=1;G(float,s+0x88)=1;G(float,s+0x84)=1;
 if(!buffer){
  u8 wave[20]={};G(u32,wave)=0x10001;G(u32,wave+4)=0xac44;G(u32,wave+8)=0x15888;G(u16,wave+12)=2;G(u32,wave+14)=0x10;
  u32 desc[9]={0x24,0x14,0x40,0,(u32)wave,0,0,0,0};
  if(comcall<s32>(device,0xc,desc,(void**)(s+8),0u)!=0){
   void* log=vcall<void*>(G(void*,0x700390),0x20,0x6a4168u,0xe2u);
   typedef void(*Print)(void*,u32);(*(Print*)(*(u8**)log+0x2c))(log,0x6a4244u);return 0;
  }
  buffer=G(void*,s+8);
 }
 if(comcall<s32>(buffer,0,0x6be1b0u,(void**)(s+4))<0)return 0;
 if((u8)activate)vcall<void>(s,0x10);
 u32 prop=0;comcall<void>(G(void*,s+4),0x14,0x6bdf60u,1u,&prop);return 1;
}
PCREG(54edb0,fn54edb0);
