// batch35151.cpp - cascade s5 batch 35151: 0x478b70 (GUESS read the cached value when the target object is in an allowed state).
#include "ff.h"

typedef u8(THISCALL *b1_t)(void *, u32);
typedef u8 *(THISCALL *o0_t)(void *);
typedef u32(THISCALL *g0_t)(void *);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x478b70, thiscall(o, unused) ret 8. Returns 0 when (byte +0x726 != 0 and dword +0x64c == 10), or byte +0x753 != 0, or o is null, or o slot 0x1e0(0x1007d2) is false, or the byte at +0x26a
// (0x466cd0 returns [ecx]) is non-zero, or byte +0x726 is zero. Otherwise k = o->slot 0x350() slot 0x330(); when k == 2 or (k - 4) <= 2 (unsigned) returns the unaligned dword at +0x74f, else 0.
static u32 THISCALL fn478b70(u8 *self, u8 *o, u32 unused) {
  if (self[0x726] && *(u32 *)(self + 0x64c) == 10) return 0;
  if (self[0x753]) return 0;
  if (!o) return 0;
  if (!(*(b1_t **)o)[0x1e0 / 4](o, 0x1007d2)) return 0;
  if (self[0x26a]) return 0;
  if (!self[0x726]) return 0;
  u8 *p = (*(o0_t **)o)[0x350 / 4](o);
  u32 k = (*(g0_t **)p)[0x330 / 4](p);
  if (k == 2 || k - 4 <= 2) return rd32u(self + 0x74f);
  return 0;
}
PCREG(478b70, fn478b70);
