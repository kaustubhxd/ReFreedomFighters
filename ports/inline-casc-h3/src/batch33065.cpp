// batch33065.cpp - h3 () batch 33065: tier C wrappers
#include "ff.h"

extern "C" void THISCALL ext_6060a0(u8 *self, u32 a, u32 b);         // ret 8
extern "C" u32 THISCALL ext_466290(u8 *self, u32 a, u32 b);          // ret 8
extern "C" u32 THISCALL ext_466f60(u8 *self, u32 a);                 // ret 4
extern "C" u32 THISCALL ext_4db9a0(u8 *self, u32 a);                 // ret 4, bool in al
extern "C" void THISCALL ext_511a00(u8 *self);
extern "C" void THISCALL ext_512070(u8 *self);
extern "C" void __attribute__((cdecl)) ext_45c510(u8 *p);
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *p, u32 n);
extern "C" void *__attribute__((cdecl)) ext_41e290(u32 n);
extern "C" void THISCALL ext_5e9300(u8 *self, u32 a);                // ret 4
extern "C" u32 THISCALL ext_4748b0(u8 *self, u32 a);                 // ret 4

#define SYS (*(u8 **)0x70039c)
#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))
typedef u32 (*hook_t)();
typedef u32 (__attribute__((cdecl)) *log3_t)(u8 *, u32, u32);

// 0x5f95a0: thiscall(a) ret 4: a->slot 0x2c([this]); a->slot 0x40(this+4); 0x6060a0(this+0x10, a, 0); 0x6060a0(this+0x2c, a, 0)
static void THISCALL fn5f95a0(u8 *self, u8 *a) {
  vcall<u32>(a, 0x2c, *(u32 *)self);
  vcall<u32>(a, 0x40, (u32)(self + 4));
  ext_6060a0(self + 0x10, (u32)a, 0);
  ext_6060a0(self + 0x2c, (u32)a, 0);
}
PCREG(5f95a0, fn5f95a0);

// 0x467060: thiscall(a,b,c) ret 0xc: r = c ? 0x466290(a,0) : 0x466f60(a); o=table->slot 0x60(r); o: [o+0x60]=b-[o+0x64]; [o+0x64]=b; returns r
static u32 THISCALL fn467060(u8 *self, u32 a, u32 b, u8 c) {
  u32 r = c ? ext_466290(self, a, 0) : ext_466f60(self, a);
  u8 *o = vcall<u8 *>(SYS_TABLE, 0x60, r);
  if (o) {
    *(u32 *)(o + 0x60) = b - *(u32 *)(o + 0x64);
    *(u32 *)(o + 0x64) = b;
  }
  return r;
}
PCREG(467060, fn467060);

// 0x4fa180: stdcall(a,b) ret 8: if (u8)0x4db9a0(b, 0x20002c): s=[b+0x54]; s->slot 0xbc(([s+0x21]&(u8)a) ? 0 : 1); if (signed byte [s+0x21] < 0) s->slot 0xbc(0)
static void STDCALL fn4fa180(u32 a, u8 *b) {
  if (!(u8)ext_4db9a0(b, 0x20002c)) return;
  u8 *s = *(u8 **)(b + 0x54);
  u32 arg = (s[0x21] & (u8)a) ? 0 : 1;
  vcall<u32>(s, 0xbc, arg);
  if ((s8)s[0x21] < 0) vcall<u32>(s, 0xbc, 0u);
}
PCREG(4fa180, fn4fa180);

// 0x506040: thiscall: kind byte [this+4]: 3 -> return [this]; 4 -> tail [[this]] vtable slot 0x34(); else log-style + assert hook, return 0
static u32 THISCALL fn506040(u8 *self) {
  u8 k = self[4];
  if (k == 3) return *(u32 *)self;
  if (k == 4) return vcall<u32>(*(u8 **)self, 0x34);
  u8 *g = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(g, 0x20, 0x69c8e0u, 0x111u);
  (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x69c6b0, 0x69c9b0);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return 0;
}
PCREG(506040, fn506040);

// 0x520360: thiscall(a) ret 4: 0x511a00(this+0x2fd); 0x512070(this); a&1: (a&4 ? cdecl 0x4690b0(this,0x270d) : cdecl 0x45c510(this)); returns this
static u8 *THISCALL fn520360(u8 *self, u32 a) {
  ext_511a00(self + 0x2fd);
  ext_512070(self);
  if (a & 1) {
    if (!(a & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, 0x270d);
  }
  return self;
}
PCREG(520360, fn520360);

// 0x54cda0: thiscall: n=[this+0x805d]; [this+0x803d]=new(n*4 sat); for i<n (signed): [[this+0x803d]+4i]=slot 0x40()
static void THISCALL fn54cda0(u8 *self) {
  u32 n = *(u32 *)(self + 0x805d);
  u64 sz = (u64)n * 4;
  void *p = ext_41e290(sz > 0xffffffffull ? 0xffffffffu : (u32)sz);
  *(void **)(self + 0x803d) = p;
  if (*(int *)(self + 0x805d) <= 0) return;
  int i = 0;
  do {
    u32 v = vcall<u32>(self, 0x40);
    ((u32 *)*(u8 **)(self + 0x803d))[i] = v;
    i++;
  } while (i < *(int *)(self + 0x805d));
}
PCREG(54cda0, fn54cda0);

// 0x593ee0: thiscall(a) ret 4: if byte [this+0x9e7]: p=table->slot 0x138(); local=0; p->slot 0x88(str, &local); 0x5e9300(local, a); then 0x4748b0(this,a)
static u32 THISCALL fn593ee0(u8 *self, u32 a) {
  if (self[0x9e7]) {
    u8 *p = vcall<u8 *>(SYS_TABLE, 0x138);
    u32 local = 0;
    vcall<u32>(p, 0x88, 0x6acf30u, (u32)&local);
    ext_5e9300((u8 *)local, a);
  }
  return ext_4748b0(self, a);
}
PCREG(593ee0, fn593ee0);

// 0x4382e0: thiscall: if [this+0x1208]==0x200 assert hook (int3 when null); first free 9-byte slot (dwords at +0 and +5 zero) of 0x200 at this+8: count++ and return it, else 0
static u8 *THISCALL fn4382e0(u8 *self) {
  if (*(u32 *)(self + 0x1208) == 0x200) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u8 *p = self + 8;
  for (int i = 0; i < 0x200; i++, p += 9) {
    if (*(u32 *)p == 0 && *(u32 *)(p + 5) == 0) {
      (*(u32 *)(self + 0x1208))++;
      return self + 8 + i * 8 + i;
    }
  }
  return 0;
}
PCREG(4382e0, fn4382e0);
