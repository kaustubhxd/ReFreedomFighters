// f16b006.cpp - fresh slice 16, batch 6 (2026-10-12).
// 0x5f3e40 Process_t::collectOpaqueObjectInfo(buf): 0x5f3eb0(this; +0x28, buf), 0x5f3eb0(this; +0x34, buf) (ret 8); each of
//           the +0x54 objects in array [+0x4c]: slot 0x3c(buf); then 0x5fe610([+0x96]; this, buf) (ret 8). Ret 4. The loop's
//           index bound check (handler 0x7003b0 / int3) can never fire (index < count by the loop test) and is left out.
// 0x640240 ZDrawBase::ShouldFlush: +4 == 0 -> true; free = ring distance of +0x268 / +0x26c in dwords (0x2000 ring);
//           free > 0x1555 -> error report (0x6c265c, 0x27e; 0x6c26d4, free), true; else false.
// 0x436080 ZSysInput::InitDevices: devices at +4 (count +0xc), +0x10 (count +0x1c), +0x20 (count +0x60): slot 4(0) on each.
// 0x4b1500 CCutSequenceProxy::LoadInit(rd): +0x48 = db RegisterZMsg slot 0x114(0x691f40, 0, 0x691edc, 0xe8d); +0x4a = the same
//           with 0x691f98 / 0xe8e (ret 0x10); +0x4c = DBREAD::operator unsigned int 0x4e5e60(rd). Ret 4.
// 0x5bf780: o = [[0x70039c]+0x9b]+8 slot 0x44(ECX as passed) (the push ecx is its argument: the epilogue's pops only
//           balance if the callee pops it); o != 0 -> CLogicOperatorEvaluatorTriggerFunctions ctor 0x5bf5c0(o). Returns o.
//           SEH frame not reproduced.
// 0x608e80: ZRender::Close 0x64f910, 0x60d610; +0x13ed -> COM [+0x1377] slot 0x138([0x724a54]); [+0x13e7] slot 0(1);
//           Release (slot 8, stdcall) on [0x724ad8] (if set), [+0x1377], [0x724b38].
// 0x45b880 ZBloodSplatters::ClassFrameUpdate: +0x6508 = (float)pow([0x680148], [0x70039c]+0x48 * [0x67885c]); tail
//           ZProjectMarks::UpdateActiveMarks 0x45c180.
#include "ff.h"
#include "f16log.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_5f3eb0[], ext_5fe610[], ext_4e5e60[], ext_5bf5c0[], ext_64f910[], ext_60d610[], ext_634db2[], ext_45c180[];

extern "C" void THISCALL f16_5f3e40(u8 *self, void *buf) {
  typedef void(THISCALL * F2)(void *, void *, void *);
  ((F2)(void *)ext_5f3eb0)(self, self + 0x28, buf);
  ((F2)(void *)ext_5f3eb0)(self, self + 0x34, buf);
  for (u32 i = 0; i < AT(u32, self, 0x54); ++i) vcall<void>(AT(void **, self, 0x4c)[i], 0x3c, buf);
  ((F2)(void *)ext_5fe610)(AT(void *, self, 0x96), self, buf);
}

extern "C" bool THISCALL f16_640240(u8 *self) {
  if (AT(u8, self, 4) == 0) return true;
  u32 a = AT(u32, self, 0x26c), b = AT(u32, self, 0x268);
  u32 n = b < a ? 0x2000u - (u32)((s32)(a - b) >> 2) : (u32)((s32)(b - a) >> 2);
  if (n > 0x1555) {
    f16_report2(0x6c265cu, 0x27e, 0x6c26d4u, n);
    return true;
  }
  return false;
}

extern "C" void THISCALL f16_436080(u8 *self) {
  for (u32 i = 0; i < AT(u32, self, 0xc); ++i) vcall<void>(((void **)(self + 4))[i], 4, 0u);
  for (u32 i = 0; i < AT(u32, self, 0x1c); ++i) vcall<void>(((void **)(self + 0x10))[i], 4, 0u);
  for (u32 i = 0; i < AT(u32, self, 0x60); ++i) vcall<void>(((void **)(self + 0x20))[i], 4, 0u);
}

extern "C" void THISCALL f16_4b1500(u8 *self, void *rd) {
  AT(u16, self, 0x48) = vcall<u16>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x114, 0x691f40u, 0u, 0x691edcu, 0xe8du);
  AT(u16, self, 0x4a) = vcall<u16>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x114, 0x691f98u, 0u, 0x691edcu, 0xe8eu);
  AT(u32, self, 0x4c) = ((u32(THISCALL *)(void *))(void *)ext_4e5e60)(rd);
}

extern "C" void *THISCALL f16_5bf780(void *self) {
  void *a = AT(void *, AT(u8 *, G(u8 *, 0x70039c), 0x9b), 8);
  void *o = vcall<void *>(a, 0x44, self);
  if (o) ((void(THISCALL *)(void *))(void *)ext_5bf5c0)(o);
  return o;
}

extern "C" void THISCALL f16_608e80(u8 *self) {
  typedef u32(STDCALL * C1)(void *);
  typedef u32(STDCALL * C2)(void *, u32);
  ((void(THISCALL *)(void *))(void *)ext_64f910)(self);
  ((void(THISCALL *)(void *))(void *)ext_60d610)(self);
  if (AT(u8, self, 0x13ed)) {
    void *o = AT(void *, self, 0x1377);
    (*(C2 *)(*(u8 **)o + 0x138))(o, G(u32, 0x724a54));
  }
  void *x = AT(void *, self, 0x13e7);
  if (x) vcall<void>(x, 0, 1u);
  void *y = G(void *, 0x724ad8);
  if (y) (*(C1 *)(*(u8 **)y + 8))(y);
  void *o = AT(void *, self, 0x1377);
  (*(C1 *)(*(u8 **)o + 8))(o);
  void *z = G(void *, 0x724b38);
  (*(C1 *)(*(u8 **)z + 8))(z);
}

extern "C" void THISCALL f16_45b880(u8 *self) {
  typedef double(VECTORCALL * Pow)(double, double);
  float t = AT(float, G(u8 *, 0x70039c), 0x48) * G(float, 0x67885c);
  double r = ((Pow)(void *)ext_634db2)(G(double, 0x680148), (double)t);
  AT(float, self, 0x6508) = (float)r;
  ((void(THISCALL *)(void *))(void *)ext_45c180)(self);
}

PCREG(5f3e40, f16_5f3e40);
PCREG(640240, f16_640240);
PCREG(436080, f16_436080);
PCREG(4b1500, f16_4b1500);
PCREG(5bf780, f16_5bf780);
PCREG(608e80, f16_608e80);
PCREG(45b880, f16_45b880);
