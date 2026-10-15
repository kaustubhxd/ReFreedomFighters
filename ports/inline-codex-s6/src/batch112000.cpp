#include "ff.h"
static void copystr(u8*d,const u8*s){do{*d++=*s;}while(*s++);}
static void THISCALL refresh(u8* me){
 auto resource=vcall<u8*>(*(void**)(me+0x54),0x25c,(u32)0x6a674c,0);
 if(!resource){auto log=vcall<void*>(G(void*,0x700390),0x20,(u32)0x6a64b4,0x677);typedef void(*Print)(void*,u32);(*(Print*)(*(u8**)log+0x2c))(log,0x6a6780);return;}
 if(!me[0x100])copystr(me+0x100,*(u8**)(resource+0x97));
 u8 text[0x200];copystr(text,me+0x100);
 auto state=*(u8**)(me+0x94);
 if(state[0x1043]){
 auto fmt=vcall<void*>(G(void*,0x70039c),0x190);
 auto table=*(u8**)(G(u8*,0x70039c)+0x9b);
 auto lookup=vcall<u32>(*(void**)(table+0xae4),0,(u32)0x6a6760);
 u8 extra[0x100];
 u32 args[6]={(u32)fmt,(u32)extra,0x6a6774,lookup,0x6a6758,*(u32*)(state+0x132b7)};void* fn=*(void**)(*(u8**)fmt+0x198);
 asm volatile("push 20(%[a]); push 16(%[a]); push 12(%[a]); push 8(%[a]); push 4(%[a]); push 0(%[a]); call *%[fn]; add $20, %%esp" : : [a]"r"(args),[fn]"r"(fn) : "eax","ecx","edx","memory","cc");
 u8* end=text;while(*end)++end;copystr(end,extra);
 }
 vcall<void>(resource,0x284,text);
}
PCREG(5638e0,refresh);
