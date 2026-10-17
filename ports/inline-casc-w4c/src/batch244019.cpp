// batch244019.cpp - Sonnet-w4c: hand ports of two colour-distance routines (GUESS names; the lifter rejects their ebp operands).
#include "ff.h"

extern "C" u32 FASTCALL ext_6383a0(u32 flag, s32 *out, s32 *v1, s32 *v2);   // fastcall: ecx = flag, edx = out, 2 stack args, ret 8

// Shared prefix of 0x63a390 / 0x63a460: v1 = a0 | (a0 >> 5) per component (y component shifted by 6 when flag == 0), v2 likewise for a1 (y always >> 6);
// 0x6383a0(flag, buf, v1, v2) fills buf (22 ints).
static void w4c_prefix(u32 flag, const s32 *a0, const s32 *a1, s32 *buf) {
  s32 v1[3], v2[3];
  v1[0] = (a0[0] >> 5) | a0[0];
  v2[0] = (a1[0] >> 5) | a1[0];
  v1[1] = ((flag == 0) ? (a0[1] >> 6) : (a0[1] >> 5)) | a0[1];
  v2[1] = (a1[1] >> 6) | a1[1];
  v1[2] = (a0[2] >> 5) | a0[2];
  v2[2] = (a1[2] >> 5) | a1[2];
  ext_6383a0(flag, buf, v1, v2);
}

// 0x63a390: fastcall(flag, idx, a0, a1, rows, sel, limit) ret 0x14. sum over up to 16 rows of (rows[idx + 4*i] - buf[idx + sel[i]*4])^2; stops once sum > limit (signed); returns sum.
static inline s32 w4c_sq(s32 d) { return (s32)((u32)d * (u32)d); }
static u32 FASTCALL fn63a390(u32 flag, u32 idx, s32 *a0, s32 *a1, s32 *rows, u32 *sel, s32 limit) {
  s32 buf[22];
  w4c_prefix(flag, a0, a1, buf);
  s32 *row = rows + idx;
  s32 sum = 0;
  for (s32 i = 0; i < 16;) {
    s32 d = (s32)((u32)*row - (u32)buf[idx + sel[i] * 4]);
    sum = (s32)((u32)sum + (u32)w4c_sq(d));
    if (sum > limit) break;
    i++;
    row += 4;
  }
  return (u32)sum;
}
PCREG(63a390, fn63a390);

// 0x63a460: fastcall(flag, idx, a0, a1, rows, limit) ret 0x10. rows are 16 bytes: when the word at +0xc is 0 the term is (row[idx] - buf[12 + idx])^2, otherwise the signed minimum of
// the four squares against buf[idx], buf[4 + idx], buf[8 + idx], buf[12 + idx] (and 0x7fffffff); sum > limit (signed) stops.
static u32 FASTCALL fn63a460(u32 flag, u32 idx, s32 *a0, s32 *a1, s32 *rows, s32 limit) {
  s32 buf[22];
  w4c_prefix(flag, a0, a1, buf);
  s32 *row = rows;
  s32 sum = 0;
  for (s32 i = 0; i < 16;) {
    s32 term;
    s32 v = row[idx];
    if (row[3] == 0) {
      term = w4c_sq((s32)((u32)v - (u32)buf[12 + idx]));
    } else {
      s32 m = 0x7fffffff;
      s32 s0 = w4c_sq((s32)((u32)v - (u32)buf[idx]));
      if (s0 < m) m = s0;
      s32 s1 = w4c_sq((s32)((u32)v - (u32)buf[4 + idx]));
      s32 e = (s1 >= m) ? m : s1;
      s32 s2 = w4c_sq((s32)((u32)v - (u32)buf[8 + idx]));
      s32 f = (s2 >= e) ? e : s2;
      s32 s3 = w4c_sq((s32)((u32)v - (u32)buf[12 + idx]));
      term = (s3 >= f) ? f : s3;
    }
    sum = (s32)((u32)sum + (u32)term);
    if (sum > limit) break;
    i++;
    row += 4;
  }
  return (u32)sum;
}
PCREG(63a460, fn63a460);
