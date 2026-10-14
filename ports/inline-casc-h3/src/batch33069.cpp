// batch33069.cpp - h3 () batch 33069: tier C wrappers
#include "ff.h"

extern "C" void THISCALL ext_43f8c0(u8 *self, u32 a);               // ret 4
extern "C" void THISCALL ext_43de70(u8 *self);
extern "C" void __attribute__((cdecl)) ext_45c510(u8 *p);
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *p, u32 n);
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);

#define SYS (*(u8 **)0x70039c)
#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))
typedef u32 (*hook_t)();

// 0x657860: thiscall(a,b,n) ret 0xc: r1=slot 0xc(a); r2=slot 0xc([r1+0x14]); n times: slot 0x128(b++ , r2+0x18+0x24*i) (vtable re-read each time)
static void THISCALL fn657860(u8 *self, u32 a, u32 *b, u32 n) {
  u8 *r1 = vcall<u8 *>(self, 0xc, a);
  u8 *r2 = vcall<u8 *>(self, 0xc, *(u32 *)(r1 + 0x14));
  if (n == 0) return;
  u8 *dst = r2 + 0x18;
  do {
    vcall<u32>(self, 0x128, (u32)b, (u32)dst);
    dst += 0x24;
    b++;
    n--;
  } while (n != 0);
}
PCREG(657860, fn657860);

// 0x46cd60: thiscall(a) ret 4: 0x43f8c0(this,a); (u8)a->slot 0x1e0(0x1007d1): copy [0x60],[0x64]; (u8)a->slot 0x1e0(0x1007d2): copy [0xb6]
static void THISCALL fn46cd60(u8 *self, u8 *a) {
  ext_43f8c0(self, (u32)a);
  if ((u8)vcall<u32>(a, 0x1e0, 0x1007d1u)) {
    *(u32 *)(self + 0x60) = *(u32 *)(a + 0x60);
    *(u32 *)(self + 0x64) = *(u32 *)(a + 0x64);
  }
  if ((u8)vcall<u32>(a, 0x1e0, 0x1007d2u)) *(u32 *)(self + 0xb6) = *(u32 *)(a + 0xb6);
}
PCREG(46cd60, fn46cd60);

// 0x4b07f0: thiscall(a) ret 4 bool: [this+4]&=~0x40; assert hook (always; int3 when null); slot 0x98(0); a->slot 0x48(this+0x48); a->slot 0x40(this+0xde); return 1
static u32 THISCALL fn4b07f0(u8 *self, u8 *a) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  vcall<u32>(self, 0x98, 0u);
  vcall<u32>(a, 0x48, (u32)(self + 0x48));
  vcall<u32>(a, 0x40, (u32)(self + 0xde));
  return 1;
}
PCREG(4b07f0, fn4b07f0);

// 0x4d60e0: thiscall (stack cookie): cdecl import[0x67642c](buf, [this+0xd], 0x104); buf[0x104]=0; delete([this+0xd],1); [this+0xd]=0; this->slot 0x34(buf, [this+9])
typedef u32 (__attribute__((cdecl)) *imp3c_t)(u8 *, u32, u32);
static void THISCALL fn4d60e0(u8 *self) {
  u8 buf[0x108];
  (*(imp3c_t *)0x67642c)(buf, *(u32 *)(self + 0xd), 0x104);
  buf[0x104] = 0;
  ext_634273(*(void **)(self + 0xd), 1);
  *(u32 *)(self + 0xd) = 0;
  vcall<u32>(self, 0x34, (u32)buf, *(u32 *)(self + 9));
}
PCREG(4d60e0, fn4d60e0);

// 0x4f9c00: thiscall: if [this+0x70] != 0x20: p=slot 0x2c4(); x=table->slot 0x58([this+0x60]); slot 0x310(table, 0, x) (two pushed-ecx junk dwords: the table pointer and the zeroed slot); p->slot 0x2dc(1)
static void THISCALL fn4f9c00(u8 *self) {
  if (*(u32 *)(self + 0x70) == 0x20) return;
  u8 *p = vcall<u8 *>(self, 0x2c4);
  u8 *tab = SYS_TABLE;
  u32 x = vcall<u32>(tab, 0x58, *(u32 *)(self + 0x60));
  vcall<u32>(self, 0x310, (u32)tab, 0u, x);
  vcall<u32>(p, 0x2dc, 1u);
}
PCREG(4f9c00, fn4f9c00);

// 0x575d00: thiscall: five entries at this+0x240 (stride 0x24): flag=(this->slot 0x84()->slot 0x2f0() != [entry-0x1c]); [entry] ? [entry]->slot 0xbc((this & ~0xff)|flag) (the pushed local keeps the upper bytes of ecx)
static void THISCALL fn575d00(u8 *self) {
  u8 *q = self + 0x240;
  for (int i = 5; i != 0; i--, q += 0x24) {
    u8 *p = vcall<u8 *>(self, 0x84);
    u32 v = vcall<u32>(p, 0x2f0);
    u32 flag = v != *(u32 *)(q - 0x1c);
    u8 *c = *(u8 **)q;
    if (c) vcall<u32>(c, 0xbc, ((u32)self & 0xffffff00u) | flag);
  }
}
PCREG(575d00, fn575d00);

// 0x5fa220: thiscall(a) ret 4: v=[this+4]: array [v], count [v+8]; returns index of a, else assert hook and -1
static u32 THISCALL fn5fa220(u8 *self, u32 a) {
  u8 *v = *(u8 **)(self + 4);
  u32 n = *(u32 *)(v + 8);
  if (n) {
    u32 *arr = *(u32 **)v;
    u32 i = 0;
    do {
      if (a == *arr) return i;
      i++;
      arr++;
    } while (i < n);
  }
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return 0xffffffffu;
}
PCREG(5fa220, fn5fa220);

// 0x452fa0: thiscall(a) ret 4: c=[this+0x52]; vtable 0x681b24; c && c->slot 0(1); 0x43de70(this); a&1: (a&4 ? cdecl 0x4690b0(this,0x62) : cdecl 0x45c510(this)); returns this
static u8 *THISCALL fn452fa0(u8 *self, u32 a) {
  u8 *c = *(u8 **)(self + 0x52);
  *(u32 *)self = 0x681b24;
  if (c) vcall<u32>(c, 0, 1u);
  ext_43de70(self);
  if (a & 1) {
    if (!(a & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, 0x62);
  }
  return self;
}
PCREG(452fa0, fn452fa0);
