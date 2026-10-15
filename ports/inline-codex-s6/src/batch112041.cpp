#include "ff.h"
extern "C" u8 THISCALL ext_4da3a0(void*);
extern "C" u8 THISCALL ext_4e1600(void*);
extern "C" u8* THISCALL ext_5f2de0(void*);
extern "C" void THISCALL ext_4e1b30(void*);
extern "C" void* ext_41e290(u32);
extern "C" void* ext_634d22(void*,void*,u32);
static void THISCALL read(void*,u8*obj,void*reader){
 if(!ext_4da3a0(*(void**)(obj+8)))return;auto list=*(void**)(*(u8**)(obj+16)+8);if(!list)return;u32 it[3];vcall<void>(list,0x4c,it);auto row=vcall<u32*>(list,0x64,it);
 while(row){auto resource=vcall<u8*>(G(void*,0x70038c),0xcc,*row);if(resource){if(ext_4e1600(reader)==255)return;auto data=ext_5f2de0(reader);ext_4e1b30(reader);u32 n=ext_5f2de0(reader)-data;if(n){
 auto info=*(u8**)(resource+0x40);auto table=*(u8**)(G(u8*,0x70039c)+0x9b);auto holder=*(u8**)(table+8);
 if((*(u32*)(info+0x2b)&0x800)&&holder&&*(u32*)(holder+4)){auto copy=ext_41e290(n);ext_634d22(copy,data,n);auto cache=*(void**)(*(u8**)(*(u8**)(G(u8*,0x70039c)+0x9b)+8)+4);vcall<void>(cache,4,copy);cache=*(void**)(*(u8**)(*(u8**)(G(u8*,0x70039c)+0x9b)+8)+4);*(u32*)(resource+0x38)=vcall<u32>(cache,0x14);}
 u8*local=data;vcall<void>(resource,4,&local);
 }}
 list=*(void**)(*(u8**)(obj+16)+8);row=vcall<u32*>(list,0x64,it);
 }
}
PCREG(48da10,read);
