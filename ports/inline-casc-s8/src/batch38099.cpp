#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define P(p,o) (*(u8 **)((u8 *)(p)+(o)))
typedef u32(THISCALL *v1)(u8 *,u32);
typedef u32(THISCALL *v2)(u8 *,u32,u32);
typedef void (*logfn)(u32,u32,...);
#define SLOT(p,o,T) ((T)U(P(p,0),o))
extern "C" u8 THISCALL ext_437d60(u8 *p);
static u8 *owner(u8 *s) {
  u8 *p=P(s,0xc);
  if(!p) return 0;
  if(U(p,0)==3) return p-4;
  if(U(p,0)==1) return P(p,8) ? P(p,8)-4 : 0;
  return 0;
}
static void log_type(u32 line) {
  u8 *l=G(u8 *,0x700390);
  u32 x=SLOT(l,0x20,v2)(l,0x67a850,line);
  SLOT((u8 *)x,0x2c,logfn)(x,0x67ad10);
}
static void log_missing(u8 *s,u8 *n,u32 line) {
  u8 *l=G(u8 *,0x700390);
  u32 x=SLOT(l,0x20,v2)(l,0x67a850,line);
  SLOT((u8 *)x,0x2c,logfn)(x,0x67acd4,U(s,8),U(n,0));
}
static u8 THISCALL fn438380(u8 *s) {
  u8 *list=P(s,0x3e);
  if(!list) return 1;
  u32 it[3];
  SLOT(list,0x4c,v1)(list,(u32)it);
  list=P(s,0x3e);
  u8 *n=(u8 *)SLOT(list,0x64,v1)(list,(u32)it);
  while(n) {
    u8 *o=owner(s);
    u8 *x=(u8 *)SLOT(o,0x10,v1)(o,U(n,0));
    if(!x) {
      o=P(owner(s),0x11);
      x=(u8 *)SLOT(o,0x58,v1)(o,U(n,0));
      if(!x) log_missing(s,n,n[8] ? 0xf42 : 0xf69);
    }
    if(n[8]) {
      if(U(x,0)==0) {
        if(!ext_437d60(x-4)) return 0;
      } else log_type(0xf4c);
      if(U(x,0)==0 && (u32)(x-4)!=0 && !(x[-4+0x32]&0x10)) return 0;
    } else {
      if(x && U(x,0)==0) {
        if(ext_437d60(x-4)) return 0;
      } else log_type(0xf73);
    }
    list=P(s,0x3e);
    n=(u8 *)SLOT(list,0x64,v1)(list,(u32)it);
  }
  return 1;
}
PCREG(438380,fn438380);
