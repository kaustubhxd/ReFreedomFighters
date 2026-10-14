// batch35132.cpp - cascade s5 batch 35132: 0x48fed0 (GUESS register an object in a bounded list unless it is flagged, or hand it to a shared owner).
#include "ff.h"

extern "C" void THISCALL ext_4d96d0(u8 *self, u32 a);   // thiscall, ret 4
extern "C" void THISCALL ext_4dc630(u8 *self, u32 a, u32 b);   // thiscall, ret 8
typedef u8(THISCALL *b0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u8 *);
typedef u32(THISCALL *g1_t)(void *, u8 *);
typedef void(THISCALL *v0_t)(void *);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x48fed0, thiscall(a) ret 4. tab = [engine+0x9b]. tab slot 0x178() true: the unaligned dword X = [tab+0x5d35], when non-zero X slot 0x14(a), then 0x4d96d0(a, 0). Otherwise nothing when byte [this+0xd0] is zero or [a+0x3c] has any of 0x20200000;
// else a full list ([this+0xcc] == 0x32) first calls this slot 4(); 0x4dc630(a, 0x23000000, 0); r = tab slot 0x50(a); [this + 4 * [this+0xcc] + 4] = r; [this+0xcc]++.
static void THISCALL fn48fed0(u8 *self, u8 *a) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  if ((*(b0_t **)tab)[0x178 / 4](tab)) {
    eng = G(u8 *, 0x70039c);
    tab = *(u8 **)(eng + 0x9b);
    u8 *X = (u8 *)rd32u(tab + 0x5d35);
    if (X) (*(v1_t **)X)[0x14 / 4](X, a);
    ext_4d96d0(a, 0);
    return;
  }
  if (self[0xd0] == 0) return;
  if (*(u32 *)(a + 0x3c) & 0x20200000) return;
  if (*(u32 *)(self + 0xcc) == 0x32) (*(v0_t **)self)[4 / 4](self);
  ext_4dc630(a, 0x23000000, 0);
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u32 r = (*(g1_t **)tab)[0x50 / 4](tab, a);
  u32 idx = *(u32 *)(self + 0xcc);
  *(u32 *)(self + idx * 4 + 4) = r;
  *(u32 *)(self + 0xcc) += 1;
}
PCREG(48fed0, fn48fed0);
