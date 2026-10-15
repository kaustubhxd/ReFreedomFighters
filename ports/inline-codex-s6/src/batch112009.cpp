#include "ff.h"
extern "C" void THISCALL ext_4f9af0(void*);
extern "C" u8 THISCALL ext_4db9a0(void*,u32);
extern "C" u8* THISCALL ext_4db520(void*);
extern "C" void THISCALL ext_4dc630(void*,u32,u32);
static void THISCALL create(u8*me){
 ext_4f9af0(me);if(!*(u32*)(me+0x1c3))return;
 for(u8*node=*(u8**)(me+0x54);node;node=ext_4db520(node)){
 auto o=*(u8**)(node+0x54);u32 tag=o?*(u32*)(*(u8**)(o+12)+0x23):0x200002;if(tag&0x100000)break;
 if(ext_4db9a0(node,0x20002d)){auto table=*(void**)(G(u8*,0x70039c)+0x9b);u32 id=vcall<u32>(table,0x4c,o);vcall<void>(me+0x10f,4,id);}
 }
 if(vcall<u32>(me+0x10f,0x14)){
 auto table=*(void**)(G(u8*,0x70039c)+0x9b);u32 id=vcall<u32>(me+0x10f,0x30,0);*(void**)(me+0x1bb)=vcall<void*>(table,0x58,id);
 }else *(u32*)(me+0x1bb)=0;
 auto created=vcall<u8*>(me,0x294,(u32)0x69b698,(u32)0x6978a0,0,1);*(u8**)(me+0x1bf)=created;
 vcall<void>(created,0x124,1,0,0,0);ext_4dc630(*(void**)(created+8),0x800000,0);
 vcall<void>(created,0x27c,*(u32*)(me+0x1c3));vcall<void>(created,0xbc,1);vcall<void>(created,0x260,1);
 vcall<void>(created,0x248,*(u32*)(me+0x1cb));vcall<void>(created,0x284,(u32)0x67b080);
 vcall<void>(created,0x26c,(u32)0x40800000,(u32)0xc0800000,0);
}
PCREG(4f89b0,create);
