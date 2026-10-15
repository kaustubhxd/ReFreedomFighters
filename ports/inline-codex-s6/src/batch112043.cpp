#include "ff.h"
extern "C" s32 STDCALL ext_62f9d0(void*,s32,u32,u32);
extern "C" s32 STDCALL ext_62f5d0(void*,u32);
extern "C" void STDCALL ext_62f980(void*);
static void* THISCALL unpack(u8*me,u8*header,void*out,u32,u32 capacity){
 u8 buffer[0x20000];u16 mode=*(u16*)(header+4);
 if(!mode){vcall<u32>(*(void**)(me+0x15),0x14,out,capacity,*(u32*)(me+0x11));return out;}
 if(mode!=8){auto lo=vcall<void*>(G(void*,0x700390),0x20,(u32)0x696924,0x1ff);typedef void(*P)(void*,u32);(*(P*)(*(u8**)lo+0x2c))(lo,0x696998);return 0;}
 u32 stream[14];stream[3]=(u32)out;stream[4]=capacity;stream[8]=0;stream[9]=0;
 s32 status=ext_62f9d0(stream,-15,0x69688c,0x38);*(s32*)(me+4)=status;if(status)return 0;
 u32 remaining=*(u32*)(header+14);while(remaining){u32 chunk=remaining>0x20000?0x20000:remaining;stream[0]=(u32)buffer;stream[1]=vcall<u32>(*(void**)(me+0x15),0x14,buffer,chunk,*(u32*)(me+0x11));status=ext_62f5d0(stream,chunk<remaining?1:4);*(s32*)(me+4)=status;remaining-=chunk;}
 ext_62f980(stream);status=*(s32*)(me+4);if(status==1||(status==-5&&!remaining&&!stream[4]))return out;return 0;
}
PCREG(4d62c0,unpack);
