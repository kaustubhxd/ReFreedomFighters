#include "ff.h"
extern "C" void* ext_634d10(void*,u32,u32);
extern "C" void ext_42ac56(void*,u32,u32);
extern "C" void ext_633654();
static void THISCALL describe(u8*me){
 u8 text[512];for(s32 i=0;i<*(s32*)(me+0x8065);++i){
 ext_634d10(text,0,512);ext_42ac56(text,0x6a348c,i);
 u8*entry=me+0x807d+0x110*i;for(s32 j=0;j<*(s32*)(entry-12);++j){
 u8*p=text;while(*p)++p;u32 kind=*(u32*)(entry+8*j),src,n;
 if(kind==1){src=0x6a34a0;n=6;}else if(kind==2){src=0x6a3498;n=8;}else if(kind==3){src=0x6a34a8;n=16;}else{src=0x6a34b8;n=9;}
 for(u32 k=0;k<n;++k)p[k]=G(u8,src+k);
 }}
 ext_633654();
}
PCREG(549c50,describe);
