#include "ff.h"
extern "C" void THISCALL ext_4de7a0(void*);
extern "C" void THISCALL ext_4db2a0(void*,void*);
static void THISCALL setup(u8*me,u8*source,s32 index){
 auto target=*(u8**)(me+0x10b);if(!target||!source)return;s32 first=index*2;auto list=*(void**)(source+24);if(vcall<s32>(list,0x14)<=first)return;
 auto state=*(u8**)(me+0x10f);*(u32*)(state+0x48)=0;u32 a=vcall<u32>(list,0x30,first),b=vcall<u32>(*(void**)(source+24),0x30,first+1);
 auto table=*(void**)(G(u8*,0x70039c)+0x9b);auto x=vcall<void*>(table,0x58,a);table=*(void**)(G(u8*,0x70039c)+0x9b);auto y=vcall<void*>(table,0x58,b);if(!x||!y)return;
 u32 pos[3]={0,0,0},dest[3]={0,0,0},mat[9];ext_4de7a0(mat);auto camera=vcall<u8*>(state,0x8c);
 vcall<void>(x,0x84,pos);vcall<void>(y,0x84,dest);vcall<void>(target,0x78,pos);vcall<void>(target,0x268,dest,0);
 ext_4db2a0(*(void**)(target+8),mat);vcall<void>(camera,0x7c,mat,pos);*(u32*)(camera+0x5c)=0x3f5f66f3;
}
PCREG(5a4f70,setup);
