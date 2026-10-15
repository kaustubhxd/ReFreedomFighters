#include "ff.h"
extern "C" u32 THISCALL ext_4e5ea0(u8*);
extern "C" u32 THISCALL ext_4e5e60(u8*);
extern "C" float THISCALL ext_4e5e80(u8*);
static void THISCALL fn4afdd0(u8* s,u8* stream){
 *(u32*)(s+0x48)=ext_4e5ea0(stream);*(u32*)(s+0x4d)=ext_4e5e60(stream);*(u32*)(s+0x55)=ext_4e5ea0(stream);
 *(float*)(s+0x59)=ext_4e5e80(stream);*(float*)(s+0x5d)=ext_4e5e80(stream);*(u32*)(s+0x51)=ext_4e5e60(stream);
 s[0x63]=ext_4e5e60(stream)!=0;s[0x61]=ext_4e5e60(stream)!=0;s[0x64]=ext_4e5e60(stream)!=0;
 u8* tab=*(u8**)(G(u8*,0x70039c)+0x9b);s[0x4c]=vcall<u32>(tab,0x58,*(u32*)(s+0x4d))!=0;
 float delta=*(float*)(s+0x5d)-*(float*)(s+0x59);s[0x65]=**(u8**)(s+0x55)!=0;s[0x62]=delta!=G(float,0x6785d0);
 tab=*(u8**)(G(u8*,0x70039c)+0x9b);*(u16*)(s+0x66)=(u16)vcall<u32>(tab,0x114,(u32)0x691f80,(u32)0,(u32)0x691edc,(u32)0x927);
}
PCREG(4afdd0,fn4afdd0);
