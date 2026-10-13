// f16b011.cpp - fresh slice 16, batch 11 (2026-10-12).
// 0x500880 VisibleEventTranslator_t::handleEventTranslation(factory, id, val) (stdcall): o = factory slot 0x18(id); none -> 0;
//           e = 0x5003d0(o slot 0x4c(); 0) (the pushed 0 is 0x5003d0's argument: slot 0x4c takes none); byte e+4 <= 1 ->
//           e[0] = val, e+4 = 1; else error report (0x69c8e0, 0xc4; 0x69c6b0, 0x69c938) and the handler at 0x7003b0 (int3 if
//           null; not run). Returns o. Ret 0xc.
// 0x494540 ZEngineDataBase::ScratchedDisk: s = db slot 0x134() ([0x7003ac], a CSharedCom); s SetVal slot 0x40(0x68dfd4,
//           db slot 0xb0(), 0xc) (ret 0xc; the pushed 0xc is SetVal's type); db slot 0xa8(); slot 0xa0(0x68dfe4);
//           ControlSceneChange slot 0x18c(true).
// 0x5a3e40 CMPGameController deleting destructor: 0x5a3dc0(this); flag bit 0: bit 2 -> ZOctreeFuskeBaseKlasse::lort
//           0x4690b0(this, 0x137) (cdecl), else the handler at 0x7003b0 (int3 if null; not run). Returns this. Ret 4. SEH not
//           reproduced.
// 0x65ca80 ZShadowListBuild::NewSetBegin(geom): +0x41c + 8 > +0x420 -> error report (0x6c4828, 0x17e; 0x6c4854 through slot 0x30),
//           false; else [+0x408]+8 += 1, +0x40c = p = +0x41c, p[0] = geom, p[1] = 0, +0x41c += 8, +0x404 = +0x41c, true. Ret 4.
// 0x61a900 ZRObjectInstanceStripGC::UpdateLight(dst, src, n) (stdcall, MMX): per 36-byte vertex: copies src 0..0x18 and
//           0x1c..0x24; dst+0x18 = packuswb of ((q[0x812840+8i] & [0x6efd1c]) | (q[0x812940+8i] & [0x6efd24])) >> 5 (signed
//           16-bit lanes). n == 0 would run 2^32 times; not generated. Ret 0xc.
#include "ff.h"
#include "f16log.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_5003d0[], ext_5a3dc0[], ext_4690b0[];

extern "C" void *STDCALL f16_500880(void *fac, u32 id, u32 val) {
  void *o = vcall<void *>(fac, 0x18, id);
  if (!o) return 0;
  void *arr = vcall<void *>(o, 0x4c);
  u8 *e = ((u8 * (THISCALL *)(void *, u32))(void *)ext_5003d0)(arr, 0);
  if (AT(u8, e, 4) <= 1) {
    AT(u32, e, 0) = val;
    AT(u8, e, 4) = 1;
    return o;
  }
  f16_report2(0x69c8e0u, 0xc4, 0x69c6b0u, 0x69c938u);
  typedef void (*Hfn)();
  Hfn h = G(Hfn, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return o;
}

extern "C" void THISCALL f16_494540(void *self) {
  void *s = vcall<void *>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x134);
  u32 v = vcall<u32>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0xb0);
  vcall<void>(s, 0x40, 0x68dfd4u, v, 0xcu);
  vcall<void>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0xa8);
  vcall<void>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0xa0, 0x68dfe4u);
  vcall<void>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x18c, 1u);
}

extern "C" void *THISCALL f16_5a3e40(void *self, u32 flags) {
  ((void(THISCALL *)(void *))(void *)ext_5a3dc0)(self);
  if (flags & 1) {
    if (flags & 4) {
      ((void (*)(void *, u32))(void *)ext_4690b0)(self, 0x137);
    } else {
      typedef void (*Hfn)();
      Hfn h = G(Hfn, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
    }
  }
  return self;
}

extern "C" bool THISCALL f16_65ca80(u8 *self, u32 geom) {
  if (AT(u32, self, 0x41c) + 8 > AT(u32, self, 0x420)) {
    void *o = G(void *, 0x700390);
    void *t = vcall<void *>(o, 0x20, 0x6c4828u, 0x17eu);
    typedef void (*Rep)(void *, u32);
    (*(Rep *)(*(u8 **)t + 0x30))(t, 0x6c4854u);
    return false;
  }
  AT(u32, AT(u8 *, self, 0x408), 8)++;
  u32 *p = AT(u32 *, self, 0x41c);
  AT(u32 *, self, 0x40c) = p;
  p[0] = geom;
  AT(u32 *, self, 0x40c)[1] = 0;
  AT(u32, self, 0x41c) += 8;
  AT(u32, self, 0x404) = AT(u32, self, 0x41c);
  return true;
}

extern "C" void STDCALL f16_61a900(u8 *dst, const u8 *src, u32 n) {
  const u64 *a = (const u64 *)0x812840, *b = (const u64 *)0x812940;
  u64 m1 = G(u64, 0x6efd1c), m2 = G(u64, 0x6efd24);
  do {
    u64 q = (*a & m1) | (*b & m2);
    u32 packed = 0;
    for (int k = 0; k < 4; ++k) {
      s32 w = (s16)(u16)(q >> (16 * k));
      w >>= 5;
      u32 v = w < 0 ? 0 : (w > 255 ? 255 : (u32)w);
      packed |= v << (8 * k);
    }
    u64 s0 = AT(u64, src, 0), s1 = AT(u64, src, 8), s2 = AT(u64, src, 0x10), s3 = AT(u64, src, 0x1c);
    AT(u64, dst, 0) = s0;
    AT(u64, dst, 8) = s1;
    AT(u64, dst, 0x10) = s2;
    AT(u32, dst, 0x18) = packed;
    AT(u64, dst, 0x1c) = s3;
    ++a;
    ++b;
    src += 0x24;
    dst += 0x24;
  } while (--n);
}

PCREG(500880, f16_500880);
PCREG(494540, f16_494540);
PCREG(5a3e40, f16_5a3e40);
PCREG(65ca80, f16_65ca80);
PCREG(61a900, f16_61a900);
