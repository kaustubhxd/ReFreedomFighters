// batch52010.cpp - cascade tier H, batch 52010: 0x611820 (switch a render overlay on or off through the device object).
#include "ff.h"

extern "C" s32 VECTORCALL ext_633910(float f);                              // CRT float-to-int helper
extern "C" void FASTCALL ext_60feb0(u32 a, u32 b, u32 c, u32 d);            // ret 8: (ecx, edx, stack c, d)
extern "C" float THISCALL ext_60d840(void *self);                           // float in st0
extern "C" float THISCALL ext_60d8e0(void *self);                           // float in st0
extern "C" void THISCALL ext_609a70(void *m);                               // identity matrix
extern "C" void FASTCALL ext_633654(u32 cookie);                            // /GS check

static u32 rd32(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// A device-style call: slot `off` of the object's vtable, stdcall, with the object itself as the first argument.
template <class... A>
static inline void com(u8 *obj, u32 off, A... a) {
  typedef void(STDCALL * fn)(void *, A...);
  (*(fn *)(*(u8 **)obj + off))(obj, a...);
}

// 0x611820, thiscall(on, v, f, w) ret 0x10, /GS. X = [[0x70039c] + 0x1aa3 (unaligned)] + 0x14. this[0x115f] bit 0 clear: nothing.
// on != 0 and t = (v < 0x800 ? v : v - 0x800) != 0: this->slot0x2a0(v, w, 1); device [0x724a00]: slot 0xfc (0, 0x18, 2), (0, 0xb, 0x30000), slot 0xc8 (0x3c, (int(f * 0x68af18) << 24) | 0xffffff);
//   ext_60feb0(0, 5, 0, 3); s = X->slot4(v, 0); (a = ext_60d840(s), b = ext_60d8e0(s)) when s, else 0, 0; M = identity with M[0] = 0.5, M[5] = -0.5, M[10] = 0.5, M[12] = a + 0x67a6ac, M[13] = 0x67a6ac - b;
//   D = [this + 0x1377] (unaligned): D->slot0x94(0x10, M).
// else: D->slot0xfc(0, 0x18, 2) and D->slot0xfc(0, 0xb, 0).
static void THISCALL fn611820(u8 *self, u8 on, u32 v, float f, u32 w) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *X = *(u8 **)((u8 *)rd32(sys + 0x1aa3) + 0x14);
  if (!(self[0x115f] & 1)) {
    ext_633654(0);
    return;
  }
  if (on) {
    u32 t = v < 0x800 ? v : v - 0x800;
    if (t) {
      vcall<void>(self, 0x2a0, v, w, 1u);
      u8 *dev = G(u8 *, 0x724a00);
      com(dev, 0xfc, 0u, 0x18u, 2u);
      com(dev, 0xfc, 0u, 0xbu, 0x30000u);
      float x = f * G(float, 0x68af18);
      u32 col = ((u32)ext_633910(x) << 24) | 0xffffff;
      com(dev, 0xc8, 0x3cu, col);
      ext_60feb0(0, 5, 0, 3);
      u8 *s = vcall<u8 *>(X, 4, v, 0u);
      float a = 0, b = 0;
      if (s) {
        a = ext_60d840(s);
        b = ext_60d8e0(s);
      }
      u32 M[16];
      ext_609a70(M);
      float k = G(float, 0x67a6ac);
      float y1 = a + k;
      float y2 = k - b;
      u8 *D = (u8 *)rd32(self + 0x1377);
      M[0] = 0x3f000000;
      M[5] = 0xbf000000;
      M[10] = 0x3f000000;
      M[12] = fbits(y1);
      M[13] = fbits(y2);
      com(D, 0x94, 0x10u, (u32)M);
      ext_633654(0);
      return;
    }
  }
  u8 *D = (u8 *)rd32(self + 0x1377);
  com(D, 0xfc, 0u, 0x18u, 2u);
  com(D, 0xfc, 0u, 0xbu, 0u);
  ext_633654(0);
}
PCREG(611820, fn611820);
