#include "ff.h"
extern "C" void THISCALL ext_49b3a0(void*,u32,u32,u32,u32,u32,u32,u32,u32);
extern "C" void THISCALL serialize_record(u8* me,void* stream){
 ext_49b3a0(stream,me[0x19],me[8],me[0x7e],0,0,0,0,0);
 vcall<void>(stream,0x3c,*(u32*)(me+4));vcall<void>(stream,0x3c,*(u32*)(me+9));vcall<void>(stream,0x3c,*(u32*)(me+0xd));
 vcall<void>(stream,0x44,*(u32*)(me+0x11));vcall<void>(stream,0x44,*(u32*)(me+0x15));vcall<void>(stream,0x4c,*(float*)(me+0x7a));
 for(u32 i=0;i<*(u32*)(me+0x7f);++i){
  vcall<void>(stream,0x64,*(u32*)(me+0x1a+4*i));
  if(me[0x19])vcall<void>(stream,0x64,*(u32*)(me+0x42+4*i));
 }
 if(me[0x7e])vcall<void>(*(void**)(me+0x6a),0x10,stream);
 vcall<void>(stream,0x3c,(u32)((s32)(*(u32*)(me+0x72)-*(u32*)(me+0x6e))>>4));
 for(u8* it=*(u8**)(me+0x6e);it!=*(u8**)(me+0x72);it+=16){
  vcall<void>(stream,0x44,*(u32*)it);vcall<void>(stream,0x40,(u32)*(u16*)(it+4));vcall<void>(stream,0x40,(u32)*(u16*)(it+6));
 }
}
PCREG(5ac4b0,serialize_record);
