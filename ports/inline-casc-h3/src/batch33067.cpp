// batch33067.cpp - h3 (Sonnet) batch 33067: tier C wrappers
#include "ff.h"

extern "C" void THISCALL ext_4c5770(u8 *self, u32 a);              // ret 4
extern "C" void THISCALL ext_4ccf60(u8 *self);
extern "C" void THISCALL ext_4cbec0(u8 *self);
extern "C" void THISCALL ext_43ea20(u8 *self);                      // tail to 0x45c3e0
extern "C" void __attribute__((cdecl)) ext_45c510(u8 *p);
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *p, u32 n);

#define SYS (*(u8 **)0x70039c)
#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))
typedef u32 (*hook_t)();

// 0x4a90b0: stdcall(a) ret 4 (stack cookie): if (u8)a->slot 0x1e0(0x200011): a->slot 0x21c(&{0.015f x3})
static void STDCALL fn4a90b0(u8 *a) {
  u32 v[3] = {0x3c75c28f, 0x3c75c28f, 0x3c75c28f};
  if ((u8)vcall<u32>(a, 0x1e0, 0x200011u)) vcall<u32>(a, 0x21c, (u32)v);
}
PCREG(4a90b0, fn4a90b0);

// 0x4c5620: thiscall: p=table->slot 0x138(); local=0; p->slot 0x88(str,&local); [this+0x53]=table->slot 0x58(local); 0x4c5770(this, (u8)[this+0x52])
static void THISCALL fn4c5620(u8 *self) {
  u8 *p = vcall<u8 *>(SYS_TABLE, 0x138);
  u32 local = 0;
  vcall<u32>(p, 0x88, 0x68a9e0u, (u32)&local);
  u32 r = vcall<u32>(SYS_TABLE, 0x58, local);
  *(u32 *)(self + 0x53) = r;
  ext_4c5770(self, self[0x52]);
}
PCREG(4c5620, fn4c5620);

// 0x4daa20: thiscall(a) ret 4: (u8)a: [this+0x54] null -> assert hook; tail [this+0x54]->slot 0xb4(1); else [this+0x54] ? tail slot 0xb4(0)
static u32 THISCALL fn4daa20(u8 *self, u32 a) {
  if ((u8)a) {
    if (*(u32 *)(self + 0x54) == 0) {
      hook_t h = G(hook_t, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
    }
    return vcall<u32>(*(u8 **)(self + 0x54), 0xb4, 1u);
  }
  u8 *o = *(u8 **)(self + 0x54);
  if (!o) return 0;
  return vcall<u32>(o, 0xb4, 0u);
}
PCREG(4daa20, fn4daa20);

// 0x4f86c0: thiscall(a) ret 4: 0x4ccf60(this+0x10f); 0x4cbec0(this+0x8f); 0x43ea20(this); a&1: (a&4 ? cdecl 0x4690b0(this,0x1df) : cdecl 0x45c510(this)); returns this
static u8 *THISCALL fn4f86c0(u8 *self, u32 a) {
  ext_4ccf60(self + 0x10f);
  ext_4cbec0(self + 0x8f);
  ext_43ea20(self);
  if (a & 1) {
    if (!(a & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, 0x1df);
  }
  return self;
}
PCREG(4f86c0, fn4f86c0);

// 0x526ff0: thiscall(a) ret 4 bool: [a]=[this+4]; [this+0x19]==2 -> 1; slots 0x30,0x28,0x24; [a]=[this+4]; returns byte [this+0x18]
static u32 THISCALL fn526ff0(u8 *self, u32 *a) {
  *a = *(u32 *)(self + 4);
  if (*(u32 *)(self + 0x19) == 2) return 1;
  vcall<u32>(self, 0x30);
  vcall<u32>(self, 0x28);
  vcall<u32>(self, 0x24);
  *a = *(u32 *)(self + 4);
  return self[0x18];
}
PCREG(526ff0, fn526ff0);

// 0x549150: thiscall(a) ret 4 bool: [this+4]&=~0x40; if [this+4]&4: a->slot 0x3c([this+0x4c]), [0x50], [0x54], [0x58]; returns 1
static u32 THISCALL fn549150(u8 *self, u8 *a) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  if (*(u32 *)(self + 4) & 4) {
    vcall<u32>(a, 0x3c, *(u32 *)(self + 0x4c));
    vcall<u32>(a, 0x3c, *(u32 *)(self + 0x50));
    vcall<u32>(a, 0x3c, *(u32 *)(self + 0x54));
    vcall<u32>(a, 0x3c, *(u32 *)(self + 0x58));
  }
  return 1;
}
PCREG(549150, fn549150);

// 0x5769c0: thiscall: vtable of c=[this+0x44] read first; w=(u16)table->slot 0x114(s,0,s,0x10d,this+0x206); c'->vtable[0x12c]([this+0x215], w); r=slot 0x84(); r->slot 0x2f8([this+0x215])
static u32 THISCALL fn5769c0(u8 *self) {
  u8 *vtc = *(u8 **)(*(u8 **)(self + 0x44));
  u32 x = vcall<u32>(SYS_TABLE, 0x114, 0x6a77a0u, 0u, 0x6a945cu, 0x10du, (u32)(self + 0x206));
  u8 *c2 = *(u8 **)(self + 0x44);
  ((u32(THISCALL *)(u8 *, u32, u32)) * (u32 *)(vtc + 0x12c))(c2, *(u32 *)(self + 0x215), (u32)(u16)x);
  u8 *r = vcall<u8 *>(self, 0x84);
  return vcall<u32>(r, 0x2f8, *(u32 *)(self + 0x215));
}
PCREG(5769c0, fn5769c0);

// 0x5e90f0: thiscall: p=table->slot 0x138(); local=0; p->slot 0x88(str,&local); p2=table->slot 0x138(); p2->slot 0x5c(str, this, 2)
static void THISCALL fn5e90f0(u8 *self) {
  u8 *p = vcall<u8 *>(SYS_TABLE, 0x138);
  u32 local = 0;
  vcall<u32>(p, 0x88, 0x6acf30u, (u32)&local);
  u8 *p2 = vcall<u8 *>(SYS_TABLE, 0x138);
  vcall<u32>(p2, 0x5c, 0x6acf30u, (u32)self, 2u);
}
PCREG(5e90f0, fn5e90f0);
