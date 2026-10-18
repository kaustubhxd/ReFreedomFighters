// batch252019.cpp - Sonnet-w4f hand ports of 0x6388e0 and 0x638a30 (identical except the fill callee 0x637e10 / 0x6380e0).
#include "ff.h"
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 THISCALL ext_4d06a0_thiscall2(u32, u32) __asm__("ext_4d06a0");
extern "C" u32 THISCALL ext_639df0_thiscall3(u32, u32, u32) __asm__("ext_639df0");
extern "C" u32 THISCALL ext_637e10_thiscall3(u32, u32, u32) __asm__("ext_637e10");
extern "C" u32 THISCALL ext_6380e0_thiscall3(u32, u32, u32) __asm__("ext_6380e0");
extern "C" void FASTCALL ext_633654(u32 cookie);

// thiscall(this, a, b) ret 8, void. a = copy descriptor, b = texture index.
#define CONVERT_BODY(FILL)                                                                          \
  u8 F[0x400] __attribute__((aligned(4)));                                                          \
  u32 D = (u32)(F + 0x300 - 0x64), E = (u32)(F + 0x300 - 0x34);                                     \
  u32 rec = ((u32(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)ecx_in + 0x38)))(ecx_in, b);             \
  u32 w = (G(u32, rec + 4) + 3) & 0xfffffffcu;                                                      \
  u32 h = (G(u32, rec + 8) + 3) & 0xfffffffcu;                                                      \
  u32 prod = h * w;                                                                                 \
  u64 prod4 = (u64)prod * 4;                                                                        \
  u32 buf = ext_41e290_cdecl1(prod4 > 0xffffffffull ? 0xffffffffu : (u32)prod4);                    \
  FILL(ecx_in, buf, b);                                                                             \
  G(u32, D) = 0xff0000; G(u32, D + 4) = 0xff00; G(u32, D + 8) = 0xff; G(u32, D + 12) = 0xff000000; \
  ext_4d06a0_thiscall2(D, D);                                                                       \
  G(u32, E) = G(u32, a + 0x14); G(u32, E + 4) = G(u32, a + 0x18);                                   \
  G(u32, E + 8) = G(u32, a + 0x1c); G(u32, E + 12) = G(u32, a + 0x20);                              \
  ext_4d06a0_thiscall2(D, E);                                                                       \
  u32 p = buf + (G(u32, a + 4) * w + G(u32, a)) * 4;                                                \
  u32 q = G(u32, a + 0x2c);                                                                         \
  s32 j = 0;                                                                                        \
  if ((s32)G(u32, a + 0xc) > 0) {                                                                   \
    do {                                                                                            \
      if ((s32)G(u32, a + 8) > 0) {                                                                 \
        u32 src = p; s32 i = 0;                                                                     \
        do {                                                                                        \
          u32 v = ext_639df0_thiscall3(D, G(u32, src), G(u8, a + 0x28));                            \
          if (G(u32, a + 0x24) == 0x10) G(u16, q + i * 2) = (u16)v;                                 \
          else G(u32, q + 4 * i) = v;                                                               \
          i++; src += 4;                                                                            \
        } while (i < (s32)G(u32, a + 8));                                                           \
      }                                                                                             \
      q += G(u32, a + 0x10); p += w * 4; j++;                                                       \
    } while (j < (s32)G(u32, a + 0xc));                                                             \
  }                                                                                                 \
  ext_634273_cdecl2(buf, 4);                                                                        \
  ext_633654(G(u32, 0x6f5630));

extern "C" void THISCALL lifted_6388e0(u32 ecx_in, u32 a, u32 b) { CONVERT_BODY(ext_637e10_thiscall3) }
PCREG(6388e0, lifted_6388e0);
extern "C" void THISCALL lifted_638a30(u32 ecx_in, u32 a, u32 b) { CONVERT_BODY(ext_6380e0_thiscall3) }
PCREG(638a30, lifted_638a30);
