#include "ff.h"
static void* table(){return *(void**)(G(u8*,0x70039c)+0x9b);}
static u8 flag(u32 key){u8 value=0;auto svc=vcall<void*>(table(),0x134);vcall<void>(svc,0x90,key,&value);return value;}
static void THISCALL init(u8*me){
 auto state=*(u8**)(me+0x94);
 if(state[0x103f]){const u32 keys[4]={0x6a7cf0,0x6a7d48,0x6a7da0,0x6a7df8};for(s32 i=0;i<4;++i){if(flag(keys[i]))*(s32*)(me+0x184+4*i)=i;else{*(s32*)(me+0x184+4*i)=-1;vcall<void>(G(void*,0x7003a0),0x24,i>0?1:0,i>0?i-1:0,0);}}}
 else{if(!flag(0x6a9eb4))G(u32,G(u32,0x7003a0)+0x6c)=0;*(u32*)(me+0x184)=G(u32,G(u32,0x7003a0)+0x70);}
 vcall<void>(me,0x64,0x10);vcall<void>(me,0x68,0x10,0);if(state[0x103c])vcall<void>(me,0x68,0x10,0);
 *(u32*)(state+0x132ab)=vcall<u32>(table(),0x4c,*(void**)(me+0x44));*(void**)(me+0x180)=vcall<void*>(*(void**)(me+0x54),0x25c,(u32)0x6a69e0,0);
}
PCREG(57a760,init);
