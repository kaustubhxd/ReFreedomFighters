#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
extern "C" s32 ext_410de0(void *,u32);
extern "C" void *ext_634df4(u32,u32);
extern "C" u32 ext_405ca0(void *,void *);
extern "C" void ext_4010c0(void *);
typedef u32 (*Factory401)(void *,void *);
static s32 load401510(u8 *s,void *st) {
 u8 *b=(u8 *)U(s,0x1c);if(!b)return -129;
 U(b,0x1c)=ext_410de0(st,8)+1;
 for(s32 i=0;i<(s32)U(b,0x1c);i++) {void *p=ext_634df4(1,0x34);U(b,0x924+i*4)=(u32)p;if(ext_405ca0(st,p))goto fail;}
 {
 const u32 counts[]={0x10,0x14,0x18,0xc};const u32 dests[]={0x424,0x624,0x824,0x224};const u32 tables[]={0x6f1dc0,0x6f1dc4,0x6f1dcc,0x6f1dd8};const s32 bounds[]={1,2,3,1};
 for(u32 group=0;group<4;group++) {
  U(b,counts[group])=ext_410de0(st,6)+1;
  for(s32 i=0;i<(s32)U(b,counts[group]);i++) {
   s32 type=ext_410de0(st,16);U(b,dests[group]-0x100+i*4)=type;
   if(type<0||type>=bounds[group])goto fail;
   u32 p=((Factory401)U(G(u32,tables[group]+type*4),4))(s,st);U(b,dests[group]+i*4)=p;if(!p)goto fail;
  }
 }
 }
 U(b,8)=ext_410de0(st,6)+1;
 for(s32 i=0;i<(s32)U(b,8);i++) {
  u8 *p=(u8 *)ext_634df4(1,16);U(b,0x24+i*4)=(u32)p;
  U(p,0)=ext_410de0(st,1);U(p,4)=ext_410de0(st,16);U(p,8)=ext_410de0(st,16);U(p,12)=ext_410de0(st,8);
  if((s32)U(p,4)>=1||(s32)U(p,8)>=1||(s32)U(p,12)>=(s32)U(b,12))goto fail;
 }
 if(ext_410de0(st,1)==1)return 0;
fail:ext_4010c0(s);return -133;
}
PCREG(401510,load401510);
