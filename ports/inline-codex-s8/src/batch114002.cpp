#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
static u32 resolve58(u32 p) {
 if(!p)return 0;
 u8 *m=G(u8 *,0x70038c);
 if(vcall<u32>(m,0x20,p))return 0;
 m=G(u8 *,0x70038c);
 if(U(m,8) && U(m,12)<=p && p<U(m,16))return ((u32(THISCALL *)(u32))U(m,8))(p);
 if(!U(p,-4))vcall<void>(m,0xac,p);
 return U(p,-4);
}
static void THISCALL save58a3b0(u8 *s,void *st) {
 vcall<void>(st,0x3c,U(s,0xbe5));
 for(u32 i=0;i<U(s,0xbe5);i++)vcall<void>(st,0x3c,resolve58(U(s,0xbe9+i*4)));
 vcall<void>(st,0x3c,U(s,0xc69));
 for(u32 i=0;i<U(s,0xc69);i++) {
  u8 *p=s+0xc6d+i*9;
  vcall<void>(st,0x3c,resolve58(U(p,0)));vcall<void>(st,0x3c,U(p,4));vcall<void>(st,0x60,(u32)p[8]);
 }
 vcall<void>(st,0x3c,U(s,0xd8d));
 for(u32 i=0;i<U(s,0xd8d);i++) {
  u8 *p=s+0xd91+i*0xf4;
  vcall<void>(st,0x64,U(p,0x34));vcall<void>(st,0x3c,U(p,0));
  for(u32 j=0;j<U(p,0);j++)vcall<void>(st,0x64,U(p,4+j*4));
  vcall<void>(st,0x3c,U(p,0x38));
  for(u32 j=0;j<U(p,0x38);j++){u32 a=U(p,0x3c+j*4);vcall<void>(st,0x64,a?U(a,0):0);}
 }
 for(u32 i=0;i<4;i++)vcall<void>(st,0x64,U(s,0x2c3d+i*4));
 vcall<void>(st,0x3c,U(s,0x2c55));
 for(u32 i=0;i<U(s,0x2c55);i++)vcall<void>(st,0x64,U(s,0x2c59+i*4));
}
PCREG(58a3b0,save58a3b0);
