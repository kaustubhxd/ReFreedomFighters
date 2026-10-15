#include "ff.h"
extern "C" void THISCALL ext_439e50(void*,u32);
extern "C" u8* THISCALL ext_4cc1d0(void*);
extern "C" void* ext_41e290(u32);
extern "C" void THISCALL ext_4386a0(void*,u32,u32);
static u8* THISCALL construct(u8*me,u32 arg,u8*src){
 for(u32 off=4;off<=12;off+=4)*(u32*)(me+off)=0;*(u32*)me=0x67a7dc;
 for(u32 off=0x1d;off<=0x2d;off+=4)*(u32*)(me+off)=0;me[0x32]|=2;ext_439e50(me,arg);
 if(ext_4cc1d0(src)){auto s=ext_4cc1d0(src);u32 n=0;while(s[n])++n;auto d=(u8*)ext_41e290(n+1);*(u8**)(me+8)=d;s=ext_4cc1d0(src);do{*d++=*s;}while(*s++);}
 if(*(u32*)(src+0x80)==0xffffffff&&*(u32*)(src+0x90)==0xffffffff&&!*(u32*)(src+0xa7)&&!*(u32*)(src+0xab))me[0x32]|=4;else me[0x32]&=~4;
 me[0x32]&=~8;*(u32*)(me+0x35)=*(u32*)(src+0xa1);*(u32*)(me+0x3e)=0;
 if(*(u32*)(src+0xa7))ext_4386a0(me,*(u32*)(src+0xa7),1);if(*(u32*)(src+0xab))ext_4386a0(me,*(u32*)(src+0xab),0);
 for(u32 group=0;group<2;++group)for(u32 i=0;i<4;++i){u32 v=*(u32*)(src+0x80+16*group+4*i);if(v==0xffffffff)break;vcall<void>(me,4,v,group?0:1);}
 return me;
}
PCREG(436640,construct);
