// batch35156.cpp - cascade s5 batch 35156: 0x555f20 (GUESS apply a configured resource word and store a presence flag into a record).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u32 self, u32 a);   // thiscall, ret 4
extern "C" void THISCALL ext_5002f0(u32 self, u32 a);  // thiscall, ret 4
typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef u32(THISCALL *g6_t)(void *, u32, u32, u32, u32, u32 *, u32);
typedef void(THISCALL *v1_t)(void *, u32);

// 0x555f20, stdcall(a) ret 4. s = [0x5003d0(a[4], 0)]; v = [0x5003d0(a[4], 1)] (kept in a local); tab = engine[+0x9b]; p = tab slot 0x58(s) (never checked); w = low word of
// tab slot 0x114(0x6a5874, 0, 0x6a57fc, 0x19a, &v, 0) (v is an output dword); p slot 0x128(w); then 0x5002f0(0x5003d0(a[8], 0), v != 0).
static void STDCALL fn555f20(u8 *a) {
  u32 s = *(u32 *)ext_5003d0(*(u32 *)(a + 4), 0);
  u32 v = *(u32 *)ext_5003d0(*(u32 *)(a + 4), 1);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *p = (*(e1_t **)tab)[0x58 / 4](tab, s);
  u32 f = (*(u32 **)p)[0x128 / 4];
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u32 w = (*(g6_t **)tab)[0x114 / 4](tab, 0x6a5874, 0, 0x6a57fc, 0x19a, &v, 0);
  ((v1_t)f)(p, w & 0xffff);
  u32 rec = ext_5003d0(*(u32 *)(a + 8), 0);
  ext_5002f0(rec, v != 0);
}
PCREG(555f20, fn555f20);
