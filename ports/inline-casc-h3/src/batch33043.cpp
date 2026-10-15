// batch33043.cpp - h3 (Sonnet) batch 33043: tier B loops, list walkers, ctors
#include "ff.h"

extern "C" u32 THISCALL ext_49c980(u8 *self, u32 a, u32 b);                  // ret 8
extern "C" u32 THISCALL ext_59d370(u8 *self);                                // bool in al
extern "C" u8 *THISCALL ext_43ff00(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e);   // ret 0x14
extern "C" u32 THISCALL ext_63b340(u8 *self);
extern "C" u32 THISCALL ext_63b3c0(u8 *self);
extern "C" u32 THISCALL ext_63b0c0(u8 *self);
extern "C" u32 THISCALL ext_648750(u8 *self);
extern "C" void *__attribute__((cdecl)) ext_634d10(void *p, int v, u32 n);   // memset
extern "C" u8 *THISCALL ext_64d030(u8 *self, u32 a, u32 b, u32 c, u32 d);    // ret 0x10
extern "C" void __attribute__((fastcall)) ext_4de420(u8 *dst, u8 *src);      // ecx=dst, edx=src
extern "C" void THISCALL ext_4ee210(u8 *self, u32 a, u32 b, u32 c);          // ret 0xc

// 0x49c770: thiscall(a) ret 4: count = lo16+hi16 of 0x49c980([this+0x39],[a+0x68]); flag each; flag a
static void THISCALL fn49c770(u8 *self, u8 *a) {
  u32 r = ext_49c980(self, *(u32 *)(self + 0x39), *(u32 *)(a + 0x68));
  u32 count = (r >> 16) + (r & 0xffff);
  if (count) {
    u32 i = 0;
    do {
      u8 *p = ((u8 **)*(u8 **)(self + 0x39))[i];
      i++;
      *(u32 *)(p + 0x3c) |= 0x1000000;
    } while (i < count);
  }
  *(u32 *)(a + 0x3c) |= 0x1000000;
}
PCREG(49c770, fn49c770);

// 0x58a320: thiscall: compact array [this+0x3c..] of n=[this+0x38] entries, dropping entries where 0x59d370 is true
static void THISCALL fn58a320(u8 *self) {
  u32 *edi = (u32 *)(self + 0x3c);
  while (edi != (u32 *)(self + (*(u32 *)(self + 0x38) + 0xf) * 4)) {
    if ((u8)ext_59d370((u8 *)*edi)) {
      *edi = *(u32 *)(self + *(u32 *)(self + 0x38) * 4 + 0x38);
      (*(u32 *)(self + 0x38))--;
    } else {
      edi++;
    }
  }
}
PCREG(58a320, fn58a320);

// 0x4f9e10: thiscall(a,b,c,d,e) ret 0x14: r = 0x43ff00(...); copy seven fields this->r; return r
static u8 *THISCALL fn4f9e10(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e) {
  u8 *r = ext_43ff00(self, a, b, c, d, e);
  *(u32 *)(r + 0x8f) = *(u32 *)(self + 0x8f);
  *(u32 *)(r + 0x93) = *(u32 *)(self + 0x93);
  *(u32 *)(r + 0x97) = *(u32 *)(self + 0x97);
  *(u32 *)(r + 0x9b) = *(u32 *)(self + 0x9b);
  *(u32 *)(r + 0xa7) = *(u32 *)(self + 0xa7);
  *(u32 *)(r + 0xab) = *(u32 *)(self + 0xab);
  *(u32 *)(r + 0xaf) = *(u32 *)(self + 0xaf);
  return r;
}
PCREG(4f9e10, fn4f9e10);

// 0x63ae30: thiscall: skip list nodes (next at +8) whose word [+2]==0xffff; then tail-call 0x63b0c0
static u32 THISCALL fn63ae30(u8 *self) {
  u8 *head = *(u8 **)(self + 8);
  if (head) {
    for (;;) {
      u8 *n = *(u8 **)(self + 8);
      if (*(u16 *)(n + 2) != 0xffff) {
        (*(u32 *)(self + 0xc))++;
        return ext_63b0c0(n);
      }
      u8 *nx = *(u8 **)(n + 8);
      *(u8 **)(self + 8) = nx;
      if (head == nx) break;
      if (!nx) break;
    }
  }
  if (!(u8)ext_63b340(self)) return 0;
  (*(u32 *)(self + 0xc))++;
  return ext_63b0c0(*(u8 **)(self + 8));
}
PCREG(63ae30, fn63ae30);

// 0x648480: same with 0x63b3c0 and tail 0x648750
static u32 THISCALL fn648480(u8 *self) {
  u8 *head = *(u8 **)(self + 8);
  if (head) {
    for (;;) {
      u8 *n = *(u8 **)(self + 8);
      if (*(u16 *)(n + 2) != 0xffff) {
        (*(u32 *)(self + 0xc))++;
        return ext_648750(n);
      }
      u8 *nx = *(u8 **)(n + 8);
      *(u8 **)(self + 8) = nx;
      if (head == nx) break;
      if (!nx) break;
    }
  }
  if (!(u8)ext_63b3c0(self)) return 0;
  (*(u32 *)(self + 0xc))++;
  return ext_648750(*(u8 **)(self + 8));
}
PCREG(648480, fn648480);

// 0x54cc50: thiscall(a) ret 4: init with memset of 0x4028 bytes at this+0x7f
static u8 *THISCALL fn54cc50(u8 *self, u32 a) {
  *(u32 *)(self + 8) = a;
  *(u32 *)self = 0x6a3234;
  *(u8 *)(self + 0x7a) = 0;
  *(u16 *)(self + 0x7c) = 0;
  *(u32 *)(self + 0x71) = 0;
  *(u32 *)(self + 0x61) = 0;
  *(u32 *)(self + 0x5d) = 0;
  *(u32 *)(self + 0x6d) = 0;
  *(u32 *)(self + 0x69) = 0;
  *(u32 *)(self + 0x75) = 1;
  ext_634d10(self + 0x7f, 0, 0x4028);
  *(u32 *)(self + 0x29) = 0;
  *(u32 *)(self + 0xc) = 1;
  *(u32 *)(self + 0x39) = 1;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x20) = 0;
  *(u32 *)(self + 0x3d) = 0;
  *(u32 *)(self + 0x18) = 7;
  return self;
}
PCREG(54cc50, fn54cc50);

// 0x65f460: thiscall(a,b,c,d) ret 0x10
static void THISCALL fn65f460(u8 *self, u32 a, u8 *b, u32 *c, u32 d) {
  u8 *esi = ext_64d030(*(u8 **)(self + 0xc), *(u32 *)(self + 4), a, 1, 1);
  u8 *edi = *(u8 **)(esi + 0xc);
  if (edi) {
    *(u32 *)(edi + 0x24) = c[0];
    *(u32 *)(edi + 0x28) = c[1];
    *(u32 *)(edi + 0x2c) = c[2];
    ext_4de420(*(u8 **)(esi + 0xc), b);
  }
  u8 al = (u8)d;
  if (al != 0xff) esi[0x16] = al;
}
PCREG(65f460, fn65f460);

// 0x4f9860: ctor(a,b,c) ret 0xc
static u8 *THISCALL fn4f9860(u8 *self, u32 a, u32 b, u32 c) {
  ext_4ee210(self, a, b, c);
  *(u32 *)(self + 0x68) = 0;
  *(u32 *)(self + 0x70) = 0;
  *(u32 *)(self + 0x74) = 0;
  *(u32 *)(self + 0x6c) = 0;
  *(u32 *)(self + 0x60) = 0;
  *(u32 *)(self + 0x64) = 0;
  *(u32 *)(self + 0x8b) = 0;
  *(u8 *)(self + 0x88) = 1;
  *(u32 *)self = 0x69ba58;
  *(u32 *)(self + 0xa7) = 0;
  *(u32 *)(self + 0xaf) = 0;
  *(u32 *)(self + 0x9f) = 0;
  *(u32 *)(self + 0xa3) = 0;
  *(u32 *)(self + 0x8f) = 1;
  *(u32 *)(self + 0x93) = 0;
  *(u32 *)(self + 0x97) = 0;
  *(u32 *)(self + 0x9b) = 0;
  *(u32 *)(self + 0xab) = 0;
  *(u8 *)(self + 0xb3) = 0;
  return self;
}
PCREG(4f9860, fn4f9860);
