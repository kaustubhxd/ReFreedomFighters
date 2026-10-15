// XML context serialization: optional value, name/value attributes, enabled names.
#include "ff.h"
extern "C" int ext_6206e0(u8 *pool);
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define P(p,o) (*(u8 **)((u8 *)(p)+(o)))
static bool room(u8 *s) {
  return U(s,0x238)!=U(s,0x234) || ext_6206e0(s+0x22c)!=0;
}
static void emit(u8 *s,u8 ch) { *P(s,0x238)=ch; ++U(s,0x238); }
static u32 fn61f7f0(u8 *s) {
  bool separated=false;
  u8 *v=P(s,0x1e0);
  if(v) {
    if(!room(s)) return 0;
    emit(s,'=');
    int n=(int)U(v,0x14);
    if(s[0x268]) --n;
    for(int i=0;i<n;++i) {
      if(!room(s)) return 0;
      emit(s,P(P(s,0x1e0),0x10)[i]);
    }
    separated=true;
  }
  u8 **a=(u8 **)P(s,0x194), **end=a+U(s,0x198);
  for(;a!=end;++a) {
    u8 *item=*a;
    if(!item || !P(item,4)) continue;
    if(separated) {
      if(!room(s)) return 0;
      emit(s,12);
    }
    u8 *name=P(item,0);
    for(;*name;++name) {
      if(!room(s)) return 0;
      emit(s,*name);
    }
    if(!room(s)) return 0;
    emit(s,'=');
    int n=(int)U(P(item,4),0x14);
    if(s[0x268]) --n;
    for(int i=0;i<n;++i) {
      if(!room(s)) return 0;
      emit(s,P(P(item,4),0x10)[i]);
    }
    separated=true;
  }
  a=(u8 **)P(s,0x158); end=a+U(s,0x15c);
  for(;a!=end;++a) {
    u8 *item=*a;
    if(!item || !item[0x1c]) continue;
    if(separated) {
      if(!room(s)) return 0;
      emit(s,12);
    }
    u8 *name=P(item,0);
    for(;*name;++name) {
      if(!room(s)) return 0;
      emit(s,*name);
    }
    separated=true;
  }
  if(!room(s)) return 0;
  emit(s,0);
  return U(s,0x23c);
}
PCREG(61f7f0,fn61f7f0);
