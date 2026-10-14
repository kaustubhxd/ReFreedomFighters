// batch37020.cpp - cascade s6 batch 37020: 0x619e70.
#include "ff.h"

extern "C" void THISCALL ext_441730(u8 *c);                  // plain ret, ecx = 0x6bdea0
extern "C" void THISCALL ext_440530(u8 *c);                  // plain ret, ecx = 0x6bdea0
extern "C" void THISCALL ext_610f20(u8 *dev, u32 a);         // ret 4
extern "C" void THISCALL ext_610e20(u8 *dev, u32 a);         // ret 4
extern "C" void THISCALL ext_6107e0(u8 *dev, u32 a);         // ret 4
extern "C" void THISCALL ext_610070(u8 *dev, u32 a);         // ret 4
extern "C" void THISCALL ext_611710(u8 *dev, u32 a);         // ret 4
extern "C" void FASTCALL ext_61a6b0(u32 a, u32 *b);          // plain ret
typedef void(THISCALL *t3_t)(void *, u32, u32, u32);
typedef void(THISCALL *t0_t)(void *);
typedef void(STDCALL *s2_t)(void *, u32);
typedef void(STDCALL *s3_t)(void *, u32, u32);
typedef void(STDCALL *s4_t)(void *, u32, u32, u32);
#define GV(a) G(u32, a)
#define DEV G(u8 *, 0x724a00)
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x619e70, thiscall(p, dev) ret 8: draws one batch with renderer dev. Applies the state of this+4's object to dev (slot 0x29c), sets the shader/texture state
// from p (0x610f20/0x610e20/0x6107e0 for plain materials, 0x610070 + slot 0x28c otherwise), caches the global device state (words at 0x724948 / 0x7249f8 /
// 0x724970+0x7249b0 / 0x7249f0+0x7249f4, each only re-sent through the device at [0x724a00] when it changes), releases the objects at dev+0x13fa / dev+0x140a
// when marked and finally runs 0x61a6b0.
static void THISCALL fn619e70(u8 *self, u8 *p, u8 *dev) {
  u8 *z = *(u8 **)(self + 4);
  if (!U32(z, 0x28) || !U32(z, 0x14)) return;
  ext_441730((u8 *)0x6bdea0);
  u8 *y = *(u8 **)(*(u8 **)(*(u8 **)(self + 4) + 4) + 8);
  (*(t3_t **)dev)[0x29c / 4](dev, U32(y, 0x20), U32(y, 0x38), U32(y, 0x44));
  u8 *q = *(u8 **)(p + 0x14);
  if (!(p[5] & 4) && !(q[5] & 4)) {
    u32 esi = U32(p, 0x24), edi = U32(p, 0x28);
    ext_610f20(dev, U32(p, 0x20));
    ext_610e20(dev, esi);
    ext_6107e0(dev, edi);
  } else {
    u32 esi = U32(q, 8) + 8;
    if (U32(q, 0xc)) esi = U32(q, 0xc);
    if (U32(p, 0xc)) esi = U32(p, 0xc);
    ext_610070(dev, 0);
    (*(t3_t **)dev)[0x28c / 4](dev, esi, esi + 0x24, 0);
  }
  if (dev[0x115f] & 2) {
    if (GV(0x724948) != 1) {
      void *d = DEV;
      GV(0x724948) = 1;
      (*(s3_t **)d)[0xc8 / 4](d, 0x89, 1);
    }
    ext_611710(dev, U32(self, 8));
  }
  u8 *esi = *(u8 **)(dev + 0x13fa);
  u8 *edi = *(u8 **)(dev + 0x140a);
  if (GV(0x7249f8) != 0x152) {
    void *d = DEV;
    GV(0x7249f8) = 0x152;
    (*(s2_t **)d)[0x130 / 4](d, 0x152);
  }
  if (U32(esi, 0x30)) {
    (*(t0_t **)esi)[2](esi);
    U32(esi, 0x30) = 0;
  }
  u32 edx = U32(esi, 0x2c);
  if (GV(0x724970) != edx || GV(0x7249b0) != 0x24) {
    void *d = DEV;
    GV(0x724970) = edx;
    GV(0x7249b0) = 0x24;
    (*(s4_t **)d)[0x14c / 4](d, 0, edx, 0x24);
  }
  u32 ecx = U32(z, 0x28);
  if (U32(edi, 0x18)) {
    (*(t0_t **)edi)[2](edi);
    U32(edi, 0x18) = 0;
  }
  u32 e2 = U32(edi, 0x14);
  if (GV(0x7249f0) != e2 || GV(0x7249f4) != ecx) {
    void *d = DEV;
    GV(0x7249f0) = e2;
    GV(0x7249f4) = ecx;
    (*(s3_t **)d)[0x154 / 4](d, e2, ecx);
  }
  ext_61a6b0(U32(z, 0x24), (u32 *)(z + 0xc));
  ext_440530((u8 *)0x6bdea0);
}
PCREG(619e70, fn619e70);
