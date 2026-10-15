#include "ff.h"
extern "C" void THISCALL ext_562440(void*);
extern "C" void THISCALL ext_563510(void*,u32);
static void THISCALL setup(u8*me){
 ext_562440(me);auto table=*(void**)(G(u8*,0x70039c)+0x9b);auto service=vcall<void*>(table,0x138);
 auto value=vcall<u32>(table,0x4c,*(void**)(me+0x44),0x10);vcall<void>(service,0x60,(u32)0x6a7564,value);
 vcall<void>(*(void**)(me+0x44),0xbc,1);ext_563510(me,0x6a6850);
 table=*(void**)(G(u8*,0x70039c)+0x9b);auto settings=vcall<void*>(table,0x134);vcall<void>(settings,0x68,(u32)0x6a757c,0,0);
 u32 text;u32 scale=0;if(vcall<u8>(G(void*,0x70039c),0x5c,(u32)0x6a7584,&text)){typedef u32(*Atoi)(u32);scale=G(Atoi,0x6762d8)(text);}s32 threshold=(s32)(scale*10);
 auto root=vcall<u8*>(*(void**)(me+0x54),0x25c,(u32)0x6a7590,0);
 for(u8*node=*(u8**)(root+0x50);node;node=*(u8**)(node+0x60)){
 auto obj=*(u8**)(node+0x54);u32 tag=obj?*(u32*)(*(u8**)(obj+12)+0x23):0x200002;if(!(tag&0x100000))break;
 if(vcall<u8>(obj,0x1e0,0x100033)){
 if(vcall<s32>(obj,0x310)<threshold&&vcall<s32>(obj,0x310)!=1)vcall<void>(obj,0x2dc);
 if(threshold&&vcall<s32>(obj,0x310)==0x5b)vcall<void>(obj,0x2dc);
 }
 }
}
PCREG(569430,setup);
