// batch1029.cpp - area 81, batch 1029: 0x5f2c60, thiscall(this; A, B), ret 8, returns this. Appends the range [A, B) to the string object (begin, end,
// capacity end at +0, +4, +8). Fast path when the size plus n fits (memmove of n-1 bytes to end+1, the first byte at end, a NUL at end+n). Otherwise a
// new block of max(S, n) + 1 + S bytes from 0x6014a0 (thiscall, one argument; GUESS, stood in), S old bytes copied, the range appended by memmove, a NUL,
// and the old block released through 0x54f870 (thiscall, two arguments; GUESS, stood in). memmove is the IAT slot 0x676278 (cdecl; the harness installs
// it as a Python handler, the port calls it through the same slot).
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

typedef void *(__attribute__((cdecl)) * memmove_fn)(void *, const void *, u32);

extern "C" u32 THISCALL ext_6014a0(void *self, u32 n);            // GUESS (stood in)
extern "C" void THISCALL ext_54f870(void *self, u32 p, u32 cap); // GUESS (stood in)

static void copyVolatile(u8 *dst, const u8 *src, u32 n) {
  volatile u8 *d = dst;
  for (u32 i = 0; i < n; ++i)
    d[i] = src[i];
}

// 0x5f2c60 (thiscall: this; A, B).
static u8 *THISCALL stringAppendRange(u8 *self, u32 Aarg, u32 Barg) {
  u8 *A = (u8 *)Aarg;
  if (Aarg == Barg)
    return self;
  u32 n = Barg - Aarg;
  u32 begin = D(self, 0);
  u32 end = D(self, 4);
  u32 capEnd = D(self, 8);
  u32 S = end - begin;
  u32 C = capEnd - begin;
  memmove_fn mm = (memmove_fn)(*(u32 *)0x676278);
  if (S + n <= C - 1) {
    mm((void *)(end + 1), A + 1, n - 1);
    D(self, 4) = end + n;
    *(u8 *)(end + n) = 0;
    *(u8 *)end = A[0];
  } else {
    u32 mx = (S < n) ? n : S;
    u32 newcap = mx + 1 + S;
    u8 *p = 0;
    if (newcap != 0)
      p = (u8 *)(u64)ext_6014a0(self, newcap);
    if ((int)S > 0)
      copyVolatile(p, (u8 *)begin, S);
    u8 *dstEnd = p + S;
    mm(dstEnd, A, n);
    u32 newEnd = (u32)(u64)dstEnd + n;
    *(u8 *)newEnd = 0;
    u32 oldBegin = D(self, 0);
    u32 oldCap = D(self, 8) - oldBegin;
    if (oldBegin != 0 && oldCap != 0)
      ext_54f870(self, oldBegin, oldCap);
    D(self, 0) = (u32)(u64)p;
    D(self, 4) = newEnd;
    D(self, 8) = (u32)(u64)p + newcap;
  }
  return self;
}
PCREG(5f2c60, stringAppendRange);
