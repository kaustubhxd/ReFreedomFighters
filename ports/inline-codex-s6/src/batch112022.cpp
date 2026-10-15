#include "ff.h"
extern "C" void THISCALL ext_4dc630(void*,u32,u32);
static void* table(){return *(void**)(G(u8*,0x70039c)+0x9b);}
static void register_(u8*me,u32 key){auto svc=vcall<void*>(table(),0x138);auto id=vcall<u32>(table(),0x4c,*(void**)(me+0x44),4);vcall<void>(svc,0x5c,key,id);}
static void THISCALL init(u8*me){
 const u32 keys[3]={0x6903d8,0x6903f0,0x6903fc},offsets[3]={0x67,0x48,0x89};
 for(u32 i=0;i<3;++i)*(u16*)(me+offsets[i])=vcall<u16>(table(),0x114,keys[i],0,(u32)0x690354,0x6b+i);
 *(u32*)(me+0xc9)=0;register_(me,0x690410);
 u32 id=0;vcall<void>(vcall<void*>(table(),0x138),0x88,(u32)0x690418,&id);if(!id)register_(me,0x690418);
 if(!*(u32*)(me+0x52)){id=0;vcall<void>(vcall<void*>(table(),0x138),0x88,(u32)0x685a0c,&id);*(u32*)(me+0x52)=id;}
 *(void**)(me+0x56)=vcall<void*>(table(),0x58,*(u32*)(me+0x52));auto parent=*(u8**)(me+0x44);*(u8**)(me+0x4e)=parent;ext_4dc630(*(void**)(parent+8),0,3);
}
PCREG(4a8f20,init);
