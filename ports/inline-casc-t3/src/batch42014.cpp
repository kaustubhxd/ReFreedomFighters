// batch42014.cpp - Sonnet t3: tier H, float return (st0).
#include "ff.h"

typedef void *(THISCALL *iter_next_t)(void *, void *);
typedef void(THISCALL *iter_init_t)(void *, void *);

// 0x4af0d0, thiscall, no args, returns float on st0: it = [this+0x18] (0 -> 0.0); it.slot 0x4c(&cursor); loop over nodes n = it.slot 0x64(&cursor) until 0:
// for nodes with [n+0x48] != -1: b = [n+0x74]; len = float(sqrt(double(bx^2 + by^2 + bz^2))) with b+0x70/+0x74/+0x78; the first len > 0 is returned. Result 0.0 when no node qualifies.
static float THISCALL fn4af0d0(u8 *self) {
  void *it = *(void **)(self + 0x18);
  if (!it) return 0.0f;
  u32 cursor[2];
  (*(iter_init_t **)it)[0x4c / 4](it, cursor);
  u8 *n = (u8 *)(*(iter_next_t **)it)[0x64 / 4](it, cursor);
  while (n) {
    if (*(s32 *)(n + 0x48) != -1) {
      u8 *b = *(u8 **)(n + 0x74);
      float y = *(float *)(b + 0x74), x = *(float *)(b + 0x70), z = *(float *)(b + 0x78);
      float len = (float)crt::sqrt((double)((x * x + y * y) + z * z));
      if (len > 0.0f) return len;
    }
    it = *(void **)(self + 0x18);
    n = (u8 *)(*(iter_next_t **)it)[0x64 / 4](it, cursor);
  }
  return 0.0f;
}
PCREG(4af0d0, fn4af0d0);
