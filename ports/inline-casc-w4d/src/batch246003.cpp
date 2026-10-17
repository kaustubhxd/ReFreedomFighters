// batch246003.cpp - Sonnet-w4d, tier 6/7 hand ports (run 3).
#include "ff.h"
extern "C" void ext_620cb0_w4(u32, u32, u32, u32) __asm__("ext_620cb0");
typedef u32(*W4Cb)(u32, u32, u32, u32 *);

// 0x61dba0: cdecl(A, B, C, D, E) -> status. edi = *C; slot = (B == A[0x8c]) ? &A[0x46] pair (A+0x118, +0x11c) : (A[0x124], +4).
// *slot0 = edi; *C = 0; r = B->fn[0xc](B, edi, D, &out); *slot1 = out; dispatch on r+4 (0 or 3 -> E ? (*E = edi, 0) : 2; 2 -> E ? (*E = edi, 0) : 6;
// 4 -> *slot0 = out, 4; r == 42 -> (A[0x50] ? 0x620cb0(A, B, edi, out)), *C = out, 0; anything else (also r+4 > 0x2e) -> *slot0 = out, 0x17).
extern "C" u32 GUESS_61dba0(u8 *A, u32 B, u32 *C, u32 D, u32 *E) {
  u32 edi = *C;
  u32 *s0, *s1;
  if (B == *(u32 *)(A + 0x8c)) {
    s0 = (u32 *)(A + 0x118);
    s1 = (u32 *)(A + 0x11c);
  } else {
    s0 = (u32 *)*(u32 *)(A + 0x124);
    s1 = s0 + 1;
  }
  *s0 = edi;
  *C = 0;
  u32 out = (u32)A;  // the exe reuses its own first-argument slot as the out variable (pre-call value is never read)
  u32 fn = *(u32 *)(B + 0xc);
  u32 r = ((u32(*)(u32, u32, u32, u32 *))fn)(B, edi, D, &out) + 4;
  *s1 = out;
  if (r > 0x2e) {
    *s0 = out;
    return 0x17;
  }
  switch (r) {
    case 0:
    case 3:
      if (E) { *E = edi; return 0; }
      return 2;
    case 2:
      if (E) { *E = edi; return 0; }
      return 6;
    case 4:
      *s0 = out;
      return 4;
    case 46:
      if (*(u32 *)(A + 0x50)) ext_620cb0_w4((u32)A, B, edi, out);
      *C = out;
      return 0;
    default:
      *s0 = out;
      return 0x17;
  }
}
PCREG(61dba0, GUESS_61dba0);

// 0x62b2f0: cdecl(tokType, enc, p, end, out) -> int. Scans bytes p..end by encoding-class table enc[0x4c + byte]:
// class 0,1,8 stop (*out = p, 0); 5/6/7 multi-byte (2/3/4) via enc callbacks [0x164/0x168/0x16c](enc, p): short input -> -2, callback true -> (*out = p, 0);
// 12,13 consume one byte and, if the class == tokType, either end (-27) or look at the next byte (*out = p; class-9 in the second table -> 0x1b, else 0);
// anything else is skipped; end of input -> -1.
typedef u32(*W4Cb2)(u32, const u8 *);
extern "C" s32 GUESS_62b2f0(u32 tokType, u8 *enc, const u8 *p, const u8 *end, const u8 **out) {
  if (p == end) return -1;
  s32 len = (s32)(end - p);
  for (;;) {
    u32 cls = enc[p[0] + 0x4c];
    if (cls > 0xd) {
      p++; len--;
    } else {
      switch (cls) {
        case 0: case 1: case 8:
          *out = p;
          return 0;
        case 5: case 6: case 7: {
          s32 n = (s32)cls - 3;
          if (len < n) return -2;
          u32 off = cls == 5 ? 0x164 : cls == 6 ? 0x168 : 0x16c;
          if (((W4Cb2)*(u32 *)(enc + off))((u32)enc, p) != 0) {
            *out = p;
            return 0;
          }
          p += n; len -= n;
          break;
        }
        case 12: case 13:
          p++; len--;
          if (cls == tokType) {
            if (p == end) return -27;
            *out = p;
            u32 c2 = enc[p[0] + 0x4c] - 9;
            if (c2 > 0x15) return 0;
            static const u8 t2[22] = {0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0};
            return t2[c2] == 0 ? 0x1b : 0;
          }
          break;
        default:
          p++; len--;
          break;
      }
    }
    if (p == end) return -1;
  }
}
PCREG(62b2f0, GUESS_62b2f0);
