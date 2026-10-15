#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define B(p,o) (*((u8 *)(p)+(o)))
extern "C" void THISCALL ext_64c2d0(void *);
extern "C" void THISCALL ext_64c240(void *,void *);
extern "C" void THISCALL ext_6491b0(void *,void *);
extern "C" void THISCALL ext_63f030(void *,void *);
extern "C" void THISCALL ext_64b3c0(void *,void *);
struct Iter64 {u32 *p;u32 i;u8 *node;};
static void step64(Iter64 &it) {
 if(++it.i==U(it.node,0)) {it.node=(u8 *)U(it.node,8);if(it.node){it.i=0;it.p=(u32 *)(it.node+16);}else it.p=0;}
 else it.p++;
}
static void THISCALL cleanup64de70(u8 *s) {
 u32 stamp=U(G(u8 *,0x70039c),0x3c);
 ext_64c2d0(s);
 u8 *map=(u8 *)U(U(s,0x10051),16);
 Iter64 it;
 vcall<void>(s+0x10171,12,&it);
 while(it.p) {
  u8 *p=(u8 *)*it.p;
  if(U(p,16)!=stamp){vcall<void>(s+0x10171,16,&it);ext_64c240(s,p);}
  else {step64(it);u8 mask=(u8)(1u<<(map[B(p,0x15)]&31));if(B(p,0x14)!=mask){B(p,0x14)=mask;ext_6491b0(s,p);}}
 }
 vcall<void>(s+0x10185,12,&it);
 while(it.p) {
  u8 *p=(u8 *)*it.p;
  if(U(p,16)!=stamp && !*(u16 *)((u8 *)U(p,8)+0x3e)) {
   vcall<void>(s+0x10185,16,&it);B(p,5)&=0xfe;
   U(p,0)=U(G(u8 *,0x70039c),0x3c);
   u8 *ring=(u8 *)U(s,0x1005d)+0x268;
   U(p,0)=U(G(u8 *,0x70039c),0x3c);
   u32 cursor=U(ring,0);u16 index=(u16)(((s32)(cursor-(u32)ring-8))>>2);
   U(cursor,0)=(u32)p;U(ring,0)+=4;if(U(ring,0)==(u32)ring+0x8008)U(ring,0)=(u32)ring+8;
   *(u16 *)(p+6)=index;u8 *data=(u8 *)U(p,8);if(--B(data,0x3c)==0)ext_63f030((void *)U(s,0x1005d),data);
  } else step64(it);
 }
 vcall<void>(s+0x101ad,12,&it);
 while(it.p) {
  u8 *p=(u8 *)*it.p;
  if(B(p,4)!=6) {if(U(p,16)!=stamp)vcall<void>(s+0x101ad,16,&it);else step64(it);}
  else if((s8)B(p,5)>=0){vcall<void>(s+0x101ad,16,&it);ext_64b3c0(s,p);}
  else {step64(it);B(p,5)&=0x7f;u32 idx=(*(u16 *)((u8 *)U(U(U(p,8),16),8)+6))&0xfff;u8 *head=(u8 *)U(U(s,0x10071),idx*4);U(p,24)=U(head,16);U(head,16)=(u32)p;}
 }
 vcall<void>(s,0x24);U(s,0x181c5)=0;
}
PCREG(64de70,cleanup64de70);
