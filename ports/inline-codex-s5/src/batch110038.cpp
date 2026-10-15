#include "ff.h"
#define A38(T,p,o) (*(T*)((u8*)(p)+(o)))
static void THISCALL apply38(u8*t,u8*src){
 const u32 offsets[4]={0x63,0x60,0x61,0x5f};for(u32 o:offsets)A38(u8,t,o)=A38(u8,src,o);
 A38(u16,t,0x48)=A38(u16,src,0x48);A38(u32,t,0x5a)=A38(u32,src,0x5a);A38(u8,t,0x5e)=A38(u8,src,0x5e);A38(u8,t,0x62)=A38(u8,src,0x62);
 A38(u32,t,0x4e)=A38(u32,src,0x4e);A38(u32,t,0x52)=A38(u32,src,0x52);A38(u8,t,0x64)=A38(u8,src,0x64);
 u8*owner=A38(u8*,t,0x44);vcall<void>(owner,0x40);A38(u32,A38(u8*,owner,0x10),0x18)|=2;
 if(!t[0x64])vcall<void>(t,0x68,0x10u,0u);
 u8*s=G(u8*,0x70039c);A38(u32,t,0x56)=A38(u32,s,0x40);
 u32 width,h,z;u32 id=A38(u32,A38(u8*,owner,8),0x6c);void*mgr=A38(void*,A38(u8*,s,0x1aa3),0x18);
 if(!vcall<u8>(mgr,0xd4,id,&width,&h,&z)){vcall<void>(t,0x58);return;}
 A38(float,t,0x4a)=(float)width;vcall<void>(owner,0x3c,1u);
 if(!t[0x5e])vcall<void>(t,0x68,0x10u,0u);
}
PCREG(4a49c0,apply38);
