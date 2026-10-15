#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define P(p,o) (*(u8 **)((u8 *)(p)+(o)))
typedef u32(THISCALL *v0)(u8 *);
typedef u32(THISCALL *v1)(u8 *,u32);
typedef u32(THISCALL *v2)(u8 *,u32,u32);
typedef void (*logfn)(u32,u32,...);
typedef void (*assertfn)();
#define SLOT(p,o,T) ((T)U(P(p,0),o))
static u8 *table() { return P(G(u8 *,0x70039c),0x9b); }
static u32 read32(u8 *st) { u32 x; SLOT(st,0x18,v2)(st,(u32)&x,4); return x; }
static void seek(u8 *st,u32 x) { SLOT(st,0xc,v1)(st,x); }
static void assertion() { G(assertfn,0x7003b0)(); }
static void THISCALL fn497fe0(u8 *s,u8 *st) {
  u8 *classes=P(P(s,0x14),4);
  seek(st,13);
  u32 cls=read32(st);
  while(cls!=0xffffffff) {
    u8 *factory=P(classes,cls*0x70+0x54);
    seek(st,16);
    u32 id=read32(st);
    while(id!=0xffffffff) {
      u8 *item=0;
      if(id==0x80000000) {
        u32 kind=read32(st);
        if(kind==1) {
          u32 arg=read32(st), engineid=read32(st);
          U(table(),0x10)=engineid;
          item=(u8 *)SLOT(factory,0x110,v2)(factory,arg,0);
        } else if(kind==0) {
          u32 flags=read32(st),engineid=read32(st),name;
          U(table(),0x10)=engineid;
          SLOT(st,0x60,v1)(st,(u32)&name);
          item=(u8 *)SLOT(factory,(flags&2)?0x10c:0x108,v2)(factory,name,0xffffffff);
        } else assertion();
      } else {
        item=P(table(),0x5d29);
        while(item && U(item,0x20)!=id) item=P(item,0x28);
      }
      seek(st,17);
      SLOT(st,0x34,v1)(st,0x45564e54);
      u8 *t=table(); SLOT(t,0x74,v0)(t);
      if(!(SLOT(item,0x28,v1)(item,(u32)st)&0xff)) assertion();
      u32 load=read32(st);
      if(load) {
        if(!U(item,0x1c)) U(item,4)|=0x40;
        if(!(SLOT(item,0x20,v1)(item,(u32)st)&0xff)) assertion();
        if(item[4]&0x40) {
          u8 *logger=G(u8 *,0x700390);
          u32 l=SLOT(logger,0x20,v2)(logger,0x68e36c,0x688);
          SLOT((u8 *)l,0x2c,logfn)(l,0x68e428,U(P(item,0x40),0));
          assertion();
        }
        U(item,4)|=0x80;
      }
      t=table(); SLOT(t,0x78,v0)(t);
      seek(st,16);
      id=read32(st);
    }
    seek(st,13);
    cls=read32(st);
  }
}
PCREG(497fe0,fn497fe0);
