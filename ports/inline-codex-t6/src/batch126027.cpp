#include "ff.h"
extern "C" void* THISCALL ext_49df60(void*,void*,void*);
extern "C" void THISCALL ext_49df30(void*);
extern "C" u32 THISCALL ext_49e0d0(void*);
static void THISCALL setupEvent(u8* me){
 u32 id=0;void* cfg=vcall<void*>(G(void*,G(u32,0x70039c)+0x9b),0x138);vcall<void>(cfg,0x88,0x68c070,(void*)&id);G(void*,me+0x78)=vcall<void*>(G(void*,G(u32,0x70039c)+0x9b),0x58,id);
 id=0;cfg=vcall<void*>(G(void*,G(u32,0x70039c)+0x9b),0x138);vcall<void>(cfg,0x88,0x69268c,(void*)&id);G(void*,me+0x7c)=vcall<void*>(G(void*,G(u32,0x70039c)+0x9b),0x58,id);
 G(u16,me+0x74)=(u16)vcall<u32>(G(void*,G(u32,0x70039c)+0x9b),0x114,0x692668,0,0x693c40,0xb92);
 void* text=G(void*,G(u32,G(u32,0x70039c)+0x9b)+0xae4);if(!text||!G(u32,me+0x78))return;
 u8 buffer[512];void* handle=ext_49df60(text,me+0x80,buffer);if(!handle)return;
 ext_49df30(handle);G(u8,me+0x72)=1;u32 params[3];params[0]=G(u32,G(u32,G(u32,me+0x44)+0x18)+0x70);params[1]=ext_49e0d0(handle);params[2]=(u32)(me+0x180);
 void* target=G(void*,me+0x78);typedef void(STDCALL *fn)(void*,u32,void*);(*(fn*)(*(u8**)target+0x130))(target,(u32)G(u16,me+0x74),params);
}
PCREG(4c2f00,setupEvent);
