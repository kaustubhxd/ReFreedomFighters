// batch2405.cpp - decomp area 24, batch 2405: GUESS introsort over 53-byte records keyed by a float at +0
// (0x4ade70). Median-of-three pivot (the middle, the last and the first key), partition by the exe helper 0x4ae320
// (the pivot passed by value as 14 stack dwords, ret 0x38), recursion on the right part and a loop on the left,
// heap-sort fallback 0x4ae0b0 when the depth budget is used up. Ranges under 17 records (901 bytes) are left for the
// caller's insertion pass.
#include "ff.h"

extern "C" u8 *FASTCALL ext_4ae320(u8 *first, u8 *last, u32 p0, u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6,
                                   u32 p7, u32 p8, u32 p9, u32 p10, u32 p11, u32 p12, u32 p13);  // partition
extern "C" void FASTCALL ext_4ae0b0(u8 *first, u8 *last, u32 lastDup, u32 zero);  // heap-sort fallback

static const u32 kRec = 53;     // record size (0x35)
static const s32 kSmall = 0x385;  // 17 records

// 0x4ade70 introSort(first, last, unused, depth), fastcall, ret 8. last is one past the end.
static void FASTCALL introSort(u8 *first, u8 *last, u32 unused, u32 depth) {
  (void)unused;
  if ((s32)((u32)last - (u32)first) < kSmall)
    return;
  u8 *lo = first;
  u8 *hi = last;
  u32 d = depth;
  for (;;) {
    if (d == 0) {
      ext_4ae0b0(lo, hi, (u32)hi, 0);
      return;
    }
    u32 count = ((u32)hi - (u32)lo) / kRec;
    u8 *midp = lo + kRec * (count / 2);
    u8 *lastp = hi - kRec;
    float a = *(float *)lo;
    float b = *(float *)midp;
    float c = *(float *)lastp;
    u8 *pv;
    if (b > a)
      pv = (c > b) ? midp : (c > a) ? lastp : lo;
    else
      pv = (c > a) ? lo : (c > b) ? lastp : midp;
    u32 pb[14] = {0};
    for (u32 k = 0; k < kRec; ++k)
      ((u8 *)pb)[k] = pv[k];
    --d;
    u8 *split = ext_4ae320(lo, hi, pb[0], pb[1], pb[2], pb[3], pb[4], pb[5], pb[6], pb[7], pb[8], pb[9], pb[10],
                           pb[11], pb[12], pb[13]);
    introSort(split, hi, 0, d);
    hi = split;
    if ((s32)((u32)hi - (u32)lo) < kSmall)
      return;
  }
}
PCREG(4ade70, introSort);
