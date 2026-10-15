#include "ff.h"
extern "C" u8* THISCALL ext_4cc1d0(void*);
static u8* end(u8*p){while(*p)++p;return p;}
static void copy(u8*d,const u8*s){do{*d++=*s;}while(*s++);}
static void fixed(u8*d,u32 src,u32 n){for(u32 i=0;i<n;++i)d[i]=G(u8,src+i);}
static u32 THISCALL paths(void*me,u32,u32,u8*name,u32,u32,u32){
 u8 a[260],b[264];copy(a,ext_4cc1d0(G(u8*,0x70039c)+0x123));fixed(end(a),0x678ce8,10);
 vcall<void>(me,0x4c,a);copy(end(a),name);vcall<void>(me,0x4c,a);
 copy(b,a);fixed(end(b),0x67856c,2);fixed(end(b),0x678cf4,13);
 vcall<u32>(me,0x30,b,0);return 0;
}
PCREG(427ac0,paths);
