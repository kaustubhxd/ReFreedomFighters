#include "ff.h"
static u8 THISCALL fn463ff0(u8* s,u8* stream){
 vcall<void>(stream,0x10,s,(u32)0x6c);vcall<void>(stream,0x24,*(u32*)(s+0x70));vcall<void>(stream,0x24,*(u32*)(s+0x10));
 u8* list=*(u8**)(s+0x6c);if(!list){vcall<void>(stream,0x3c,(u32)0);return 1;}
 vcall<void>(stream,0x3c,vcall<u32>(list,0x14));list=*(u8**)(s+0x6c);if(!list)return 1;
 u32 it[3];vcall<void>(list,0x4c,it);u8* entry=vcall<u8*>(*(u8**)(s+0x6c),0x64,it);
 while(entry){float f=vcall<float>(*(u8**)(s+0x6c),0x9c,entry);vcall<void>(stream,0x4c,f);vcall<void>(stream,0x44,*(u32*)(entry+4));vcall<void>(stream,0x3c,*(u32*)entry);
  u32 value=0;u32 ref=*(u32*)(entry+8);if(ref)value=vcall<u32>(*(u8**)(s+0x74),0x314,ref);vcall<void>(stream,0x3c,value);entry=vcall<u8*>(*(u8**)(s+0x6c),0x64,it);
 }
 return 1;
}
PCREG(463ff0,fn463ff0);
