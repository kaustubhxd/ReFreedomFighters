// batch35007.cpp - cascade s5 batch 35007: 0x486e90 (GUESS clamp a stream advance against its end and a limit, then commit it).
#include "ff.h"

typedef s32(THISCALL *g0_t)(void *);
typedef s32(THISCALL *g1_t)(void *, void *);
typedef void(THISCALL *v1_t)(void *, s32);
typedef void(THISCALL *v2_t)(void *, void *, s32);
typedef void(THISCALL *v2i_t)(void *, s32, s32);

// 0x486e90, thiscall(b, limit) ret 8, signed arithmetic. eng = [this+8]; want = eng slot 0x560(b); end = b slot 0x364(), cur = b slot 0x35c();
// n = min(cur + want, end) - cur, then n = limit when limit != 0 and limit < n. eng slot 0x564(b, want - n); b slot 0x360(cur + n); b slot 0x358(1); b slot 0x2d0(0, 0).
static void THISCALL fn486e90(u8 *self, u8 *b, s32 limit) {
  void *eng = *(void **)(self + 8);
  s32 want = (*(g1_t **)eng)[0x560 / 4](eng, b);
  s32 end = (*(g0_t **)b)[0x364 / 4](b);
  s32 cur = (*(g0_t **)b)[0x35c / 4](b);
  s32 n = cur + want;
  if (end < n) n = end;
  n -= cur;
  if (limit != 0 && limit < n) n = limit;
  eng = *(void **)(self + 8);
  (*(v2_t **)eng)[0x564 / 4](eng, b, want - n);
  (*(v1_t **)b)[0x360 / 4](b, cur + n);
  (*(v1_t **)b)[0x358 / 4](b, 1);
  (*(v2i_t **)b)[0x2d0 / 4](b, 0, 0);
}
PCREG(486e90, fn486e90);
