// batch1017.cpp - area 81, batch 1017: ZMatPosAnim::Load(lg) at 0x4a55e0, thiscall, one stack argument, ret 4. SEH frame and cookie check not reproduced.
// Stand-ins (GUESS): 0x4e5e60 (thiscall on lg, returns a word), 0x4e5e80 (thiscall on lg, returns a float in st0), 0x4e5e40 (thiscall on lg, returns a
// word), 0x4e6180 (thiscall on lg, one argument), 0x4cc1d0 (thiscall on the object from M+0x1d8), 0x4cbec0 (thiscall on a local object).
// Type tests read the first byte of lg's vtable slot 0. Print branch: the debug channel's slot 0x2c (cdecl: channel, format, value).
// Return: the eax of the last call (M's slot 0x21c, or M+0xc when that is not taken, or this's slot 0x58 on the print branch).
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" u32 THISCALL ext_4e5e60(void *self);          // GUESS (stood in)
extern "C" float THISCALL ext_4e5e80(void *self);        // GUESS (stood in)
extern "C" u32 THISCALL ext_4e5e40(void *self);          // GUESS (stood in)
extern "C" void THISCALL ext_4e6180(void *self, u32 a);  // GUESS (stood in)
extern "C" u32 THISCALL ext_4cc1d0(void *self);          // GUESS (stood in)
extern "C" void THISCALL ext_4cbec0(void *self);         // GUESS (stood in)

typedef void(__attribute__((cdecl)) * print_fn)(u32, u32, u32);

// 0x4a55e0 ZMatPosAnim::Load(lg).
static u32 THISCALL matPosAnimLoad(u8 *self, u32 lgArg) {
  u8 *lg = (u8 *)lgArg;
  u8 *M = (u8 *)D(self, 0x44);
  if (vcall<u32>(M, 0x4c, 0x4b455953u) == 0) {
    u8 *chan = (u8 *)vcall<u32>((void *)*(u32 *)0x700390, 0x20, 0x68fe94u, 0x4eu);
    u8 l90[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    u32 Q = vcall<u32>(M, 0x1d8, (u32)l90, 1u);
    u32 V = ext_4cc1d0((void *)Q);
    print_fn fn = (print_fn)D(*(u8 **)chan, 0x2c);
    fn((u32)chan, 0x68fec4u, V);
    ext_4cbec0(l90);
    return vcall<u32>(self, 0x58);
  }
  if (*(u32 *)lg != 0) {
    bool c1 = ext_4e5e60(lg) != 0;
    *(u8 *)(self + 0xc4) = c1;
    u8 b0 = *(u8 *)(*(u8 **)lg);
    bool skipStore = b0 != 0xff && (b0 & 0x3f) == 2;
    if (!skipStore) {
      *(u8 *)(self + 0x92) = c1;
      *(u8 *)(self + 0xc4) = ext_4e5e60(lg) != 0;
    }
    float f = ext_4e5e80(lg);
    ext_4e6180(lg, (u32)(self + 0x5f));
    *(float *)(self + 0xc7) = f;
    *(u8 *)(self + 0x8f) = ext_4e5e60(lg) != 0;
    *(u8 *)(self + 0x91) = ext_4e5e60(lg) != 0;
    *(u8 *)(self + 0xc5) = ext_4e5e60(lg) != 0;
    *(u8 *)(self + 0xc6) = ext_4e5e60(lg) != 0;
    *(u16 *)(self + 0x5d) = (u16)ext_4e5e40(lg);
    b0 = *(u8 *)(*(u8 **)lg);
    if (b0 != 0xff && (b0 & 0x3f) == 3) {
      *(u8 *)(self + 0x90) = ext_4e5e60(lg) != 0;
      *(u8 *)(self + 0xcb) = ext_4e5e60(lg) != 0;
      D(self, 0xcc) = ext_4e5e60(lg);
      D(self, 0xd0) = ext_4e5e60(lg);
    }
    b0 = *(u8 *)(*(u8 **)lg);
    if (b0 != 0xff && (b0 & 0x3f) == 2)
      *(float *)(self + 0xc0) = ext_4e5e80(lg);
    b0 = *(u8 *)(*(u8 **)lg);
    if (b0 != 0xff && (b0 & 0x3f) == 3) {
      *(u8 *)(self + 0xd4) = 0;
      if (ext_4e5e60(lg))
        *(u8 *)(self + 0xd4) = 1;
    }
  }
  u8 *K = (u8 *)D(M, 0xc);
  if (D(K, 0x23) != 0x400003u)
    *(float *)(self + 0xc0) = -1.0f;
  K = (u8 *)D(M, 0xc);
  u32 last = (u32)K;
  if (D(K, 0x23) & 0x800000u)
    last = vcall<u32>(M, 0x21c);
  return last;
}
PCREG(4a55e0, matPosAnimLoad);
