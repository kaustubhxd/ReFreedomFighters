#include "ff.h"
extern "C" u8* THISCALL ext_566360(u8*,u32);
extern "C" u32 THISCALL ext_467260(u8*,u32,u32,u32);
struct Payload{float duration;u32 text;u32 name;};
static float THISCALL fn5668d0(u8* s,u32 a,u32 b,u32 sound){
 u8* target=ext_566360(s,b);if(!target)return 0;
 Payload data;
 if(sound){
  u32 handle=ext_467260(target,sound,0,0);G(u32,s+0xa1b)=handle;
  u8* sys=G(u8*,0x70039c);u8* entry=vcall<u8*>(G(void*,sys+0x9b),0x60,handle);
  if(entry){G(u32,entry+0x40)|=0x80;G(float,entry+0x88)=100;G(u32,entry+0x2c)=2;}
  data.duration=vcall<float>(G(void*,G(u8*,0x70039c)+0x1a9f),0x74,sound);
 }else data.duration=5;
 u8* table=G(u8*,G(u8*,0x70039c)+0x9b);
 data.text=vcall<u32>(G(void*,table+0xae4),0,a,b);
 const u8* name=G(u8*,s+0x94)+0x48;const u8* sentinel=(const u8*)0x6a6e5c;
 bool equal=true;for(u32 i=0;;++i){if(name[i]!=sentinel[i]){equal=false;break;}if(!name[i])break;}
 if(equal)data.name=0x6a6e64;
 else{u8* named=vcall<u8*>(target,0x20);data.name=G(u32,named+4);if(!data.name)data.name=0x67c8e8;}
 vcall<void>(G(void*,s+0x44),0x130,target,(u32)G(u16,s+0x194),&data);
 vcall<void>(s,0x44,(u32)G(u16,s+0x184),&data);
 return data.duration;
}
PCREG(5668d0,fn5668d0);
