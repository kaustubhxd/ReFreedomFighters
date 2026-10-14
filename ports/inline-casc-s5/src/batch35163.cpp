// batch35163.cpp - cascade s5 batch 35163: 0x4d68e0 (GUESS pack the local date and time into DOS words).
#include "ff.h"

typedef u32 (*time32_t)(u32 *);
typedef u32 *(*localtime32_t)(u32 *);

// 0x4d68e0, stdcall(date, tim) ret 8, no return value. t = _time32(&t) (IAT 0x676438); tm = _localtime32(&t) (IAT 0x67643c). date non-null: *date = mday | (mon + 1) << 5 | (year + 0x30) * 0x200 (16-bit steps,
// each stored in turn). When the word *tim is non-zero (the word, not the pointer, is tested): *tim = (int)sec / 2 | min << 5 | hour << 11.
static void STDCALL fn4d68e0(u16 *date, u16 *tim) {
  u32 t;
  G(time32_t, 0x676438)(&t);
  u32 *tm = G(localtime32_t, 0x67643c)(&t);
  if (date) {
    u16 d = (u16)tm[3];
    *date = d;
    u16 x = (u16)((u16)((u16)tm[4] + 1) << 5) | d;
    *date = x;
    *date = (u16)((u32)(u16)((u16)tm[5] + 0x30) * 0x200) | x;
  }
  if (*tim) {
    u16 s = (u16)((s32)tm[0] / 2);
    *tim = s;
    u16 x = (u16)((u16)tm[1] << 5) | s;
    *tim = x;
    *tim = (u16)((u16)tm[2] << 11) | x;
  }
}
PCREG(4d68e0, fn4d68e0);
