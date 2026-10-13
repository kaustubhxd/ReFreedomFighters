// f16b020.cpp - fresh slice 16, batch 20 (2026-10-12).
// 0x497880 ZGeomBuffer::InitResourceGeoms(h): +0x48 = +0x4c = 0; a = [h+0x20]: n = [h+a]; +0x40 = new(n * 12, saturating to
//           0xffffffff), +0x48 = n, memcpy(+0x40, h+a+4, n*12). b = [h+0x24]: same with n * 8 into +0x44 / +0x4c.
// 0x5b9380 CFriendlyControl::CFriendlyControl(): 0x469870(this); +4 |= 0x20; +0x44 = 0; vtable 0x6b2754; word +0x60 / +0x62 =
//           RegisterZMsg (db slot 0x114)(0x694c6c, 0, 0x6b27e4, 0x12 / 0x13); +0x58 = +0x5c = 0. SEH not reproduced.
// 0x490940 ZEngineDataBase::GetPrimsData(buf, size): MYSTR tmp = CalcCacheFileName(this; &tmp, 0x68d848); [0x700394]
//           slot 0x60(c_str(&tmp), buf, size, 0, 0); this slot 0x90(2, 0, 0.42f bits 0x3ed70a3d) (float result dropped);
//           ~MYSTR. SEH and stack cookie not reproduced.
// 0x49b5c0 ctor(list): CMemPool::CMemPool(this+4); +0x35 = 0; vtable 0x68ed14; list: list slot 0x4c(&it); r = list slot
//           0x5c(&it); while it[0]: o = db slot 0x58(r); o -> q = [o+8], [q+0x68] = q; r = list slot 0x5c(&it). Returns
//           this. SEH not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_41e290[], ext_634d22[], ext_469870[], ext_48c4b0[], ext_4cc1d0[], ext_4cbec0[], ext_4e6b30[];

typedef void *(*NewFn)(u32);
typedef void *(*CpyFn)(void *, const void *, u32);

static inline u32 satmul(u32 n, u32 k) {
  unsigned long long v = (unsigned long long)n * k;
  return (v >> 32) ? 0xffffffffu : (u32)v;
}

extern "C" void THISCALL f16_497880(u8 *self, u8 *h) {
  AT(u32, self, 0x48) = 0;
  AT(u32, self, 0x4c) = 0;
  u32 a = AT(u32, h, 0x20), b = AT(u32, h, 0x24);
  if (a) {
    u32 n = AT(u32, h, a);
    void *p = ((NewFn)(void *)ext_41e290)(satmul(n, 12));
    AT(void *, self, 0x40) = p;
    AT(u32, self, 0x48) = n;
    ((CpyFn)(void *)ext_634d22)(p, h + a + 4, n * 12);
  }
  if (b) {
    u32 n = AT(u32, h, b);
    void *p = ((NewFn)(void *)ext_41e290)(satmul(n, 8));
    AT(void *, self, 0x44) = p;
    AT(u32, self, 0x4c) = n;
    ((CpyFn)(void *)ext_634d22)(p, h + b + 4, n * 8);
  }
}

extern "C" void *THISCALL f16_5b9380(u8 *self) {
  ((void(THISCALL *)(void *))(void *)ext_469870)(self);
  AT(u32, self, 4) |= 0x20;
  AT(u32, self, 0x44) = 0;
  AT(u32, self, 0) = 0x6b2754u;
  AT(u16, self, 0x60) = (u16)vcall<u32>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x114, 0x694c6cu, 0u, 0x6b27e4u, 0x12u);
  AT(u16, self, 0x62) = (u16)vcall<u32>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x114, 0x694c6cu, 0u, 0x6b27e4u, 0x13u);
  AT(u32, self, 0x58) = 0;
  AT(u32, self, 0x5c) = 0;
  return self;
}

struct MYSTRbuf {
  u8 b[0x80];
};

extern "C" void THISCALL f16_490940(void *self, u32 buf, u32 size) {
  volatile MYSTRbuf tmp;
  ((void(THISCALL *)(void *, volatile void *, u32))(void *)ext_48c4b0)(self, &tmp, 0x68d848u);
  u32 s = ((u32(THISCALL *)(volatile void *))(void *)ext_4cc1d0)(&tmp);
  vcall<u32>(G(void *, 0x700394), 0x60, s, buf, size, 0u, 0u);
  (void)vcall<float>(self, 0x90, 2u, 0u, 0x3ed70a3du);
  ((void(THISCALL *)(volatile void *))(void *)ext_4cbec0)(&tmp);
}

extern "C" void *THISCALL f16_49b5c0(u8 *self, void *list) {
  ((void(THISCALL *)(void *))(void *)ext_4e6b30)(self + 4);
  AT(u32, self, 0x35) = 0;
  AT(u32, self, 0) = 0x68ed14u;
  if (list) {
    volatile u32 it[4];
    vcall<void>(list, 0x4c, (u32 *)it);
    u32 r = vcall<u32>(list, 0x5c, (u32 *)it);
    while (it[0]) {
      u8 *o = vcall<u8 *>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x58, r);
      if (o) {
        u8 *q = AT(u8 *, o, 8);
        AT(u8 *, q, 0x68) = q;
      }
      r = vcall<u32>(list, 0x5c, (u32 *)it);
    }
  }
  return self;
}

PCREG(497880, f16_497880);
PCREG(5b9380, f16_5b9380);
PCREG(490940, f16_490940);
PCREG(49b5c0, f16_49b5c0);
