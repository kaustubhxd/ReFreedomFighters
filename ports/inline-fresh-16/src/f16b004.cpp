// f16b004.cpp - fresh slice 16, batch 4 (2026-10-12).
// 0x4f1240 ZWINOBJ::SetPos(v): any of v[0..2] != geom(+8) +0x24/+0x28/+0x2c (NaN = not equal) -> ZGEOM::SetPos 0x45fd20(this; v),
//           this+0x90 = 1. Ret 4.
// 0x63ae80 ZDrawArray<ZPrimDrawEntry,...>::Add: walk the free-entry ring from +8 (entry +2 == 0xffff means used, next at +8)
//           until a free one or back at the start; none -> 0x63b3c0(this) (grow; false -> return 0); then +0xc++ and tail
//           0x63b110(entry).
// 0x637dc0 (w, h, mips): this slot 0x74(w), slot 0x78(h); n = 1, or with mips != 0 the mip count of max(w, h); slot 0x5c(n).
// 0x54f200: +0x7c = 0x3f; COM object +4: slot 0x10(obj, 0x6bdf60, 1, 0, 0, this+0x10, 0x70) (stdcall); failure (< 0) ->
//           error report (0x6a4168, 0xff, 0x6a4278).
// 0x5f31c0 SerialInfo_t::savecharptr(s): n = strlen(s)+1; +8 + n > +0xc -> handler at 0x7003b0 (int3 if null; not run);
//           copy s with its 0 to [+8]; +8 += n. Ret 4.
// 0x5667c0 CBriefing::Init: ZVideoSelector::Init 0x562440; s = db slot 0x138(); CCom::SetVal (s slot 0x60, ret 0xc)(0x68c070,
//           db slot 0x4c(+0x44) (ret 4), 0x10) (the pushed 0x10 is SetVal's third argument);
//           [+0x44] slot 0xbc(1).
// 0x63b600 ZDrawBase::Alloc(n): off = ZOffsetAllocPointerSort<1024>::Alloc 0x63b510(+0x60; (n + 15) & ~15); off == -1 ->
//           error report (0x6c265c, 0xe4, 0x6c26b0), return 0; else +0x64 + off. Ret 4.
#include "ff.h"
#include "f16log.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_45fd20[], ext_63b3c0[], ext_63b110[], ext_562440[], ext_63b510[];

extern "C" void THISCALL f16_4f1240(u8 *self, const float *v) {
  u8 *g = AT(u8 *, self, 8);
  if (v[0] != AT(float, g, 0x24) || v[1] != AT(float, g, 0x28) || v[2] != AT(float, g, 0x2c)) {
    ((void(THISCALL *)(void *, const float *))(void *)ext_45fd20)(self, v);
    AT(u8, self, 0x90) = 1;
  }
}

extern "C" u32 THISCALL f16_63ae80(u8 *self) {
  typedef u32(THISCALL * Take)(void *);
  u8 *start = AT(u8 *, self, 8);
  if (start) {
    u8 *e = start;
    do {
      if (AT(u16, e, 2) != 0xffff) {
        AT(u32, self, 0xc)++;
        return ((Take)(void *)ext_63b110)(e);
      }
      e = AT(u8 *, e, 8);
      AT(u8 *, self, 8) = e;
    } while (e != start && e);
  }
  if (!((bool(THISCALL *)(void *))(void *)ext_63b3c0)(self)) return 0;
  AT(u32, self, 0xc)++;
  return ((Take)(void *)ext_63b110)(AT(void *, self, 8));
}

extern "C" void THISCALL f16_637dc0(void *self, u32 w, u32 h, u32 mips) {
  vcall<void>(self, 0x74, w);
  vcall<void>(self, 0x78, h);
  u32 n = 1;
  if ((u8)mips) {
    s32 a = (s32)(w >> 1), b = (s32)(h >> 1);
    while (a || b) {
      n++;
      a >>= 1;
      b >>= 1;
    }
  }
  vcall<void>(self, 0x5c, n);
}

extern "C" void THISCALL f16_54f200(u8 *self) {
  void *o = AT(void *, self, 4);
  AT(u32, self, 0x7c) = 0x3f;
  if (!o) return;
  typedef s32(STDCALL * Co)(void *, u32, u32, u32, u32, void *, u32);
  s32 r = (*(Co *)(*(u8 **)o + 0x10))(o, 0x6bdf60u, 1, 0, 0, self + 0x10, 0x70);
  if (r < 0) f16_report(0x6a4168u, 0xff, 0x6a4278u);
}

extern "C" void THISCALL f16_5f31c0(u8 *self, const char *s) {
  u32 n = 0;
  while (s[n]) n++;
  n += 1;
  if (AT(u32, self, 8) + n > AT(u32, self, 0xc)) {
    typedef void (*Hfn)();
    Hfn h = G(Hfn, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  char *d = AT(char *, self, 8);
  char c;
  do {
    c = *s++;
    *d++ = c;
  } while (c);
  AT(u32, self, 8) += n;
}

extern "C" void THISCALL f16_5667c0(u8 *self) {
  ((void(THISCALL *)(void *))(void *)ext_562440)(self);
  void *s = vcall<void *>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x138);
  u32 r = vcall<u32>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x4c, AT(u32, self, 0x44));
  vcall<void>(s, 0x60, 0x68c070u, r, 0x10u);
  vcall<void>(AT(void *, self, 0x44), 0xbc, 1u);
}

extern "C" u32 THISCALL f16_63b600(u8 *self, u32 n) {
  s32 off = ((s32(THISCALL *)(void *, u32))(void *)ext_63b510)(AT(void *, self, 0x60), (n + 15) & 0xfffffff0u);
  if (off == -1) {
    f16_report(0x6c265cu, 0xe4, 0x6c26b0u);
    return 0;
  }
  return AT(u32, self, 0x64) + (u32)off;
}

PCREG(4f1240, f16_4f1240);
PCREG(63ae80, f16_63ae80);
PCREG(637dc0, f16_637dc0);
PCREG(54f200, f16_54f200);
PCREG(5f31c0, f16_5f31c0);
PCREG(5667c0, f16_5667c0);
PCREG(63b600, f16_63b600);
