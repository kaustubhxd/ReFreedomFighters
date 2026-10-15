// batch67526.cpp - cascade s6 batch 67526: 0x440940.
#include "ff.h"

extern "C" u32 THISCALL ext_4daa00(u8 *e);                                  // plain ret, bool in al
extern "C" void THISCALL ext_4daf90(u8 *e, u32 *v);                         // ret 4
extern "C" void THISCALL ext_4db7c0(u8 *e, u32 *v);                         // ret 4
extern "C" void FASTCALL ext_4e2c60(u8 *e, u32 *v);                         // plain ret
extern "C" void FASTCALL ext_4419f0(u32 *v, u8 *e);                         // plain ret
extern "C" void FASTCALL ext_441940(u32 *v, u8 *p);                         // plain ret
extern "C" void FASTCALL ext_43e8e0(u32 *dst, u32 *a, u32 *b);              // ret 4
extern "C" void FASTCALL ext_43e920(u32 *dst, u32 *a, u32 *b);              // ret 4
extern "C" void FASTCALL ext_4e08d0(u32 *acc, u32 *v);                      // plain ret
extern "C" void FASTCALL ext_4e0900(u32 *acc, u32 *v);                      // plain ret
extern "C" void FASTCALL ext_4e0d00(u32 *v, u32 unusedEdx, u32 scale);                     // ret 4 (float scale as bits)

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x440940, thiscall(out, b, flag) ret 0xc: builds the bounding volume of the children chained from +0x50 (next at +0x60). Accumulators start at -/+ 1e38 per axis; every child that
// 0x4daa00 does not reject (and, with the flag byte set, is not flagged 0xc00 at +0x3c) delivers a centre and an extent vector (slot 0x2bc of its sub-object when the sub-object's
// type bit 0x100000 is set, else 0x4daf90 / 0x4db7c0), which are transformed (0x4e2c60, 0x4419f0, 0x441940) and combined (0x43e8e0 / 0x43e920) before the accumulators are widened
// (0x4e08d0 / 0x4e0900). The result is written to `out` (0x43e8e0 of the accumulators, scaled by 0.5 with 0x4e0d00) and to `b` (0x43e920).
static void THISCALL fn440940(u8 *self, u32 *out, u32 *b, u32 flag) {
  u32 A[3] = {0xfe967699u, 0xfe967699u, 0xfe967699u};
  u32 B[3] = {0x7e967699u, 0x7e967699u, 0x7e967699u};
  u32 v10[3], v28[3], v40[3], v4c[3];
  u8 *esi = *(u8 **)(self + 0x50);
  while (esi) {
    bool skip = false;
    if ((u8)ext_4daa00(esi)) skip = true;
    else if ((u8)flag && (D32(esi, 0x3c) & 0xc00)) skip = true;
    if (!skip) {
      u8 *sub = *(u8 **)(esi + 0x54);
      u32 t = sub ? D32(*(u8 **)(sub + 0xc), 0x23) : 0x200002u;
      if (t & 0x100000) {
        vcall<void>(sub, 0x2bc, (u32)v10, (u32)v28, flag);
      } else {
        ext_4daf90(esi, v10);
        ext_4db7c0(esi, v28);
      }
      ext_4e2c60(esi, v28);
      ext_4419f0(v10, esi);
      ext_441940(v10, (u8 *)(esi + 0x24));
      ext_43e8e0(v40, v10, v28);
      ext_43e920(v4c, v10, v28);
      ext_4e08d0(A, v40);
      ext_4e0900(B, v4c);
    }
    esi = *(u8 **)(esi + 0x60);
  }
  ext_43e8e0(out, A, B);
  ext_4e0d00(out, 0, 0x3f000000u);
  ext_43e920(b, A, out);
}
PCREG(440940, fn440940);
