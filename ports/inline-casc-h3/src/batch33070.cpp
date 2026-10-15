// batch33070.cpp - h3 (Sonnet) batch 33070: tier C wrappers, two register-argument (fastcall) functions
#include "ff.h"

extern "C" void THISCALL ext_46a4f0(u8 *self);
extern "C" void THISCALL ext_49d2c0(u8 *self);
extern "C" void THISCALL ext_4cc630(u8 *self, u32 a);               // ret 4
extern "C" u32 THISCALL ext_566f10(u8 *self);
extern "C" void THISCALL ext_5672c0(u8 *self, u32 a);               // ret 4
extern "C" void __attribute__((cdecl)) ext_45c510(u8 *p);
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *p, u32 n);
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);

#define SYS (*(u8 **)0x70039c)
#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))

// 0x46a810: thiscall(a) ret 4: c=[this+0x94]; vtable 0x688308; c && c->slot 0(1); 0x46a4f0(this); a&1: (a&4 ? cdecl 0x4690b0(this,0x98) : cdecl 0x45c510(this)); returns this
static u8 *THISCALL fn46a810(u8 *self, u32 a) {
  u8 *c = *(u8 **)(self + 0x94);
  *(u32 *)self = 0x688308;
  if (c) vcall<u32>(c, 0, 1u);
  ext_46a4f0(self);
  if (a & 1) {
    if (!(a & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, 0x98);
  }
  return self;
}
PCREG(46a810, fn46a810);

// 0x48fa70: thiscall: release the 0x20 objects at this+0x48 (slot 0(1), cleared); [this+0xc8]: 0x49d2c0, delete(p,0x29), cleared; [this+0xad0]=[this+0xad8]=0
static void THISCALL fn48fa70(u8 *self) {
  u32 *q = (u32 *)(self + 0x48);
  for (int i = 0; i != 0x20; i++, q++) {
    u8 *p = (u8 *)*q;
    if (p) {
      vcall<u32>(p, 0, 1u);
      *q = 0;
    }
  }
  u8 *esi = *(u8 **)(self + 0xc8);
  if (esi) {
    ext_49d2c0(esi);
    ext_634273(esi, 0x29);
    *(u32 *)(self + 0xc8) = 0;
  }
  *(u32 *)(self + 0xad0) = 0;
  *(u32 *)(self + 0xad8) = 0;
}
PCREG(48fa70, fn48fa70);

// 0x4cbee0: thiscall(a) ret 4: string assign: this != a: free the heap buffer [this] unless it is the inline one (this+4); 0x4cc630(this, a ? [a] : "")
static u8 *THISCALL fn4cbee0(u8 *self, u8 *a) {
  if (self == a) return self;
  u8 *c = *(u8 **)self;
  if (c != self + 4) ext_634273(c, 1);
  if (a) {
    ext_4cc630(self, *(u32 *)a);
    return self;
  }
  ext_4cc630(self, 0x677b5a);
  return self;
}
PCREG(4cbee0, fn4cbee0);

// 0x537200: thiscall: id=[this+0x51ad]; r=table->slot 0x58(id): r ? table->slot 0x58(id) again : (g=[sysobj+0x190f] ? (table vtable read first; x=g->slot 0xb4(0); table'->vtable[0x58](x)) : 0)
static u32 THISCALL fn537200(u8 *self) {
  u32 id = *(u32 *)(self + 0x51ad);
  u32 r = vcall<u32>(SYS_TABLE, 0x58, id);
  if (r) return vcall<u32>(SYS_TABLE, 0x58, *(u32 *)(self + 0x51ad));
  u8 *g = *(u8 **)(SYS + 0x190f);
  if (!g) return 0;
  u8 *vt = *(u8 **)SYS_TABLE;
  u32 x = vcall<u32>(g, 0xb4, 0u);
  return ((u32(THISCALL *)(u8 *, u32)) * (u32 *)(vt + 0x58))(SYS_TABLE, x);
}
PCREG(537200, fn537200);

// 0x566fd0: thiscall: c=[this+0x94]; (c && byte [c+0x103f]) ? [this+0x188] from 0 to 3: 0x5672c0(this, 0x566f10(this)) : once; then s=[this+0x94] read before table->slot 0x4c([this+0x44]); dword [s+0x132b3]=result
static void THISCALL fn566fd0(u8 *self) {
  u8 *c = *(u8 **)(self + 0x94);
  if (c && c[0x103f]) {
    *(u32 *)(self + 0x188) = 0;
    do {
      u32 y = ext_566f10(self);
      ext_5672c0(self, y);
      (*(s32 *)(self + 0x188))++;
    } while (*(s32 *)(self + 0x188) < 4);
  } else {
    *(u32 *)(self + 0x188) = 0;
    u32 y = ext_566f10(self);
    ext_5672c0(self, y);
  }
  u8 *s = *(u8 **)(self + 0x94);
  u32 z = vcall<u32>(SYS_TABLE, 0x4c, *(u32 *)(self + 0x44));
  *(u32 *)(s + 0x132b3) = z;
}
PCREG(566fd0, fn566fd0);

// 0x5f0db0: fastcall(a=ecx, b=edx): r=table->slot 0x58(a); vtable of r read first; w=(u16)table->slot 0x114(str,0,str,0x33,&local=b); r->vtable[0x130](r, w)
static void __attribute__((fastcall)) fn5f0db0(u32 a, u32 b) {
  u32 local = b;
  u8 *r = vcall<u8 *>(SYS_TABLE, 0x58, a);
  u8 *vt = *(u8 **)r;
  u32 x = vcall<u32>(SYS_TABLE, 0x114, 0x6a6ffcu, 0u, 0x6b82f4u, 0x33u, (u32)&local);
  ((u32(THISCALL *)(u8 *, u32, u32)) * (u32 *)(vt + 0x130))(r, (u32)r, (u32)(u16)x);
}
PCREG(5f0db0, fn5f0db0);

// 0x61a6b0: fastcall(a=ecx, b=edx): for i < [b] (re-read): ent=[b+8]+8i; g=[0x724a00] (re-read); ent->vtable(g)[0x11c](g, 5, 0, a, ent[1], ent[0]-2) with this=ent
static void __attribute__((fastcall)) fn61a6b0(u32 a, u8 *b) {
  u32 local = a;
  if (*(u32 *)b == 0) return;
  u32 i = 0;
  do {
    u8 *ent = *(u8 **)(b + 8) + i * 8;
    u8 *g = G(u8 *, 0x724a00);
    u8 *vt = *(u8 **)g;
    u32 e0 = *(u32 *)ent - 2;
    u32 e1 = *(u32 *)(ent + 4);
    ((u32(THISCALL *)(u8 *, u8 *, u32, u32, u32, u32, u32)) * (u32 *)(vt + 0x11c))(ent, g, 5, 0, local, e1, e0);
    i++;
  } while (i < *(u32 *)b);
}
PCREG(61a6b0, fn61a6b0);

// 0x46d700: thiscall(a) ret 4: id=[this+0x60]; id && o=table->slot 0x58(id) && o->slot 0x300(): p=slot 0x2f8(0); (u8)a ? p->slot 0xbc() : p->slot 0xb8(); else 0
static u32 THISCALL fn46d700(u8 *self, u32 a) {
  u32 id = *(u32 *)(self + 0x60);
  if (!id) return 0;
  u8 *o = vcall<u8 *>(SYS_TABLE, 0x58, id);
  if (vcall<u32>(o, 0x300) == 0) return 0;
  u8 *p = vcall<u8 *>(self, 0x2f8, 0u);
  if ((u8)a) return vcall<u32>(p, 0xbc);
  return vcall<u32>(p, 0xb8);
}
PCREG(46d700, fn46d700);
