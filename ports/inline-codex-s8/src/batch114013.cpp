#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
static void assert657(){((void(*)())G(u32,0x7003b0))();}
static void THISCALL extract657060(void *s,u32 id,u32 kind,u8 *dst,u32 n) {
 u8 *record=vcall<u8 *>(s,12,id);if(*(u16 *)(record+2))return;
 if(kind==16) {
  if(U(record,0x40)<n)assert657();u16 *src=vcall<u16 *>(s,12,U(record,0x3c));
  for(u32 i=0;i<n;i++)((u16 *)dst)[i]=src[i];return;
 }
 u8 *src=vcall<u8 *>(s,12,U(record,0x14));
 if((u32)(*(u16 *)(record+14)*U(record,0x50))<n)assert657();
 if(kind==2){for(u32 i=0;i<n;i++)U(dst,i*4)=U(src,i*36+24);return;}
 u32 off=kind==1?0:kind==4?12:28,stride=(kind==1||kind==4)?12:8;
 for(u32 i=0;i<n;i++)for(u32 j=0;j<3;j++)U(dst,i*stride+j*4)=U(src,i*36+off+j*4);
}
PCREG(657060,extract657060);
