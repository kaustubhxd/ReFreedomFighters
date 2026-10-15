// batch989.cpp - residue-11 (core todo), batch 989: ZFFHeroIf::BeamToRef(OpaqueCallParameters_t&), 0x55ee30, thiscall, ret 4.
// id cell = 0x5003d0(p->[4], 0) (stood in); X = render manager vslot 0x58(*id). X null: the debug channel (0x700390 vslot 0x20(0x6a6148,
// 0x15d)) prints through a cdecl vslot 0x30(channel, 0x69d10c, [W+4]) with W = [this+0x18] vslot 0x20(). Otherwise: X vslot 0x80(&v34, &v10);
// when X vslot 0x1e0(0x2000e1) is set: 0x55f900(this, X, &v34, &v10) (stood in); 0x4e09b0(&v34) (exe); [this+0x18] vslot 0x370(&v34, &v10).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 a);                             // stood in by the checker
extern "C" void THISCALL ext_55f900(void *self, void *x, u32 *v34, u32 *v10);      // stood in by the checker
extern "C" void THISCALL ext_4e09b0(void *vec);                                    // exe

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x55ee30 ZFFHeroIf::BeamToRef(OpaqueCallParameters_t&).
static void THISCALL beamToRef(u8 *t, u8 *p) {
  u32 *cell = (u32 *)ext_5003d0((void *)D(p, 4), 0);
  void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
  u8 *x = (u8 *)vcall<u32>(rm, 0x58, *cell);
  if (!x) {
    u8 *ch = (u8 *)vcall<u32>(*(void **)0x700390, 0x20, 0x6a6148u, 0x15du);
    u8 *w = (u8 *)vcall<u32>((void *)D(t, 0x18), 0x20);
    u32 fn = *(u32 *)(*(u32 *)ch + 0x30);
    ((u32(*)(void *, u32, u32))fn)(ch, 0x69d10cu, D(w, 4));
    return;
  }
  u32 v34[0x10];
  u32 v10[4];
  vcall<void>(x, 0x80, (u32)v34, (u32)v10);
  if ((u8)vcall<u32>(x, 0x1e0, 0x2000e1u))
    ext_55f900(t, x, v34, v10);
  ext_4e09b0(v34);
  vcall<void>((void *)D(t, 0x18), 0x370, (u32)v34, (u32)v10);
}
PCREG(55ee30, beamToRef);
