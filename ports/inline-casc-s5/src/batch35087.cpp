// batch35087.cpp - cascade s5 batch 35087: 0x6052f0 (GUESS copy a looked-up name into an owned buffer of at least 12 bytes).
#include "ff.h"

extern "C" const u8 *THISCALL ext_5fa090(u32 self, u32 idx);   // thiscall, ret 4, returns a C string
extern "C" u8 *ext_41e290(u32 n);                              // cdecl alloc
typedef void(THISCALL *v1p_t)(void *, void *);

static u32 slen1(const u8 *p) {
  const u8 *q = p;
  while (*q++) {}
  return (u32)(q - p);   // length + 1
}

// 0x6052f0, thiscall(a, b) ret 8. idx = value a slot 0x5c writes through the pointer it is given (the argument slot itself); the name s = 0x5fa090(b, idx); n = strlen(s) + 1, at least 12 (a second
// lookup recomputes the length when it is 12 or more); word [this+0x10] = n; [this+0xc] = 0x41e290(n & 0xffff); the string (looked up once more) is copied into it including the NUL.
static void THISCALL fn6052f0(u8 *self, u8 *a, u32 b) {
  u32 idx;
  (*(v1p_t **)a)[0x5c / 4](a, &idx);
  u32 n = slen1(ext_5fa090(b, idx));
  if (n < 0xc) n = 0xc;
  else n = slen1(ext_5fa090(b, idx));
  *(u16 *)(self + 0x10) = (u16)n;
  u8 *buf = ext_41e290((u16)n);
  *(u8 **)(self + 0xc) = buf;
  const u8 *src = ext_5fa090(b, idx);
  u8 c;
  do {
    c = *src++;
    *buf++ = c;
  } while (c);
}
PCREG(6052f0, fn6052f0);
