#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
static u32 read638(u8 *p){void *table=(void *)U(G(void *,0x70039c),0x9b);u32 v=U(p,0);return table&&U(table,0x62e7)==3?__builtin_bswap32(v):v;}
static u8 *THISCALL load638f20(u8 *s,u8 *p) {
 if(read638(p)!=U(s,4))((void(*)())G(u32,0x7003b0))();
 U(s,28)=read638(p+4);u32 packed=read638(p+8);vcall<void>(s,0x74,(s32)packed>>16);vcall<void>(s,0x78,packed&65535);
 vcall<void>(s,0x5c,read638(p+12));vcall<void>(s,0x4c,read638(p+16));vcall<void>(s,0x2c,read638(p+20));vcall<void>(s,0x24,read638(p+24));
 p+=28;U(s,24)=(u32)p;while(*p++){}
 s32 width=vcall<s32>(s,0x1c),height=vcall<s32>(s,0x20);
 u32 i=0;
 if(vcall<u32>(s,0x34))do {
  u32 size=read638(p);p+=4;vcall<void>(s,0x58,p,size,width,height,i,0);p+=size;
  if(width>1)width>>=1;if(height>1)height>>=1;i++;
 }while(i<vcall<u32>(s,0x34));
 return p;
}
PCREG(638f20,load638f20);
