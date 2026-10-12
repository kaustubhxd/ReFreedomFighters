#include "ff.h"
// batch933.cpp - unclaimed-80 claim 13 (docs/20-unclaimed-80.md). ZFFActorIf::MakeInactiveOnMap(OpaqueCallParameters_t&)
// (0x55b3f0, map name). Thiscall, one argument (param), ret 4. The cookie check (0x633654) is omitted.
// Exe helpers (original code, stubbed by the spec with logging): 0x5003d0 (thiscall, 1 arg, returns a pointer), 0x59d150 (2 args,
// returns al), 0x59d250 (3 args), 0x589c20 (1 arg, returns an object), 0x596940 (4 args), 0x59d090 (1 arg, returns al).
// t = [[this+0x1c]+0x54]+8. t == 2: p = 5003d0(param+4, 0); 59d250(A, 0, *p, 1). t == 3: as below. Any other t: return.

extern "C" u8 *THISCALL ext_5003d0(u8 *ecx, u32 a);
extern "C" u8 THISCALL ext_59d150(u8 *ecx, u32 a, u32 b);
extern "C" void THISCALL ext_59d250(u8 *ecx, u32 a, u32 b, u32 c);
extern "C" u8 *THISCALL ext_589c20(u8 *ecx, u32 a);
extern "C" void THISCALL ext_596940(u8 *ecx, u32 a, u32 b, u32 c, u32 d);
extern "C" u8 THISCALL ext_59d090(u8 *ecx, u32 a);

static void THISCALL makeInactiveOnMap(u8 *self, u8 *param) {
  u8 *g = G(u8 *, 0x7003b8);
  u8 *obj = *(u8 **)(self + 0x1c);
  u8 *mid = *(u8 **)(obj + 0x54);
  u32 t = *(u32 *)(mid + 8);
  if (t == 2) {
    u8 *p = ext_5003d0(*(u8 **)(param + 4), 0);
    u8 *a = *(u8 **)(g + 0x2c15);
    ext_59d250(a, 0, *(u32 *)p, 1);
    return;
  }
  if (t != 3)
    return;
  u8 *p1 = ext_5003d0(*(u8 **)(param + 4), 0);
  u8 *a = *(u8 **)(g + 0x2c15);
  if (ext_59d150(a, 1, *(u32 *)p1) != 0)
    return;
  u8 *p2 = ext_5003d0(*(u8 **)(param + 4), 0);
  a = *(u8 **)(g + 0x2c15);
  ext_59d250(a, 1, *(u32 *)p2, 1);
  u8 *a3 = *(u8 **)(g + 0x2c15);
  u32 vt = *(u32 *)obj;
  // Uninitialised, as in the exe: the callees write these locals and the exe never clears them first.
  u32 o34[2];
  u32 L[4];
  typedef u32(THISCALL * s2_fn)(u8 *, u32, u32);
  typedef void(THISCALL * s1_fn)(u8 *, u32);
  typedef u8 *(THISCALL * s0_fn)(u8 *);
  typedef void(THISCALL * sx_fn)(u8 *, u32);
  u32 r = ((s2_fn)(*(u32 *)(vt + 0x3a0)))(obj, (u32)o34, (u32)&L[0]);
  ((s1_fn)(*(u32 *)(vt + 0x390)))(obj, r);
  u8 *x = ((s0_fn)(*(u32 *)(vt + 0x20)))(obj);
  ((sx_fn)(*(u32 *)(*(u32 *)x + 0x84)))(x, (u32)&L[0]);
  float fl = *(float *)&L[1] + G(float, 0x680a84);
  *(float *)&L[1] = fl;
  u8 *y = ext_589c20(g, 0);
  ext_596940(y, 0, (u32)&L[0], 1, 0xffffffffu);
  if (ext_59d090(a3, 1) == 0)
    return;
  ext_596940(y, 1, (u32)&L[0], 1, 0xffffffffu);
}
PCREG(55b3f0, makeInactiveOnMap);
