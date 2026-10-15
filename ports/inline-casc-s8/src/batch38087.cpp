// batch38087.cpp - cascade s8 batch 38087: 0x6113d0 (render-state cache: apply a mode word to the device, only sending states that changed).
#include "ff.h"

typedef u32(STDCALL *s3_t)(void *, u32, u32);
typedef u32(STDCALL *s4_t)(void *, u32, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define DEV G(u8 *, 0x724a00)
#define GL(addr) G(u32, addr)
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword

// register-convention exe helpers (the real code runs in both versions)
static inline void rc1(u32 f, u32 c) { __asm__ volatile("call *%[f]" : : "c"(c), [f] "r"(f) : "eax", "edx", "memory", "cc"); }
static inline void rc2(u32 f, u32 c, u32 d) { __asm__ volatile("call *%[f]" : : "c"(c), "d"(d), [f] "r"(f) : "eax", "memory", "cc"); }
static inline void rc0(u32 f) { __asm__ volatile("call *%[f]" : : [f] "r"(f) : "eax", "ecx", "edx", "memory", "cc"); }
// ecx, edx and two stack arguments (first, second) popped by the callee (ret 8)
static inline void rc2s(u32 f, u32 c, u32 d, u32 a1, u32 a2) {
  __asm__ volatile("pushl %[a2]\n\tpushl %[a1]\n\tcall *%[f]" : : "c"(c), "d"(d), [a1] "r"(a1), [a2] "r"(a2), [f] "r"(f) : "eax", "memory", "cc");
}
static void set_rs(u32 state, u32 value) { u8 *d = DEV; SLOT(d, 0xc8, s3_t)(d, state, value); }

// 0x6113d0, thiscall(mode, b, c) ret 0xc. this+0x1e = disabled flag; this+0x141e / 0x1422 / 0x1426 = cached (mode, b, c); this+0x115f / 0x1163 / 0x1377 = device state.
static u32 THISCALL fn6113d0(u8 *self, u32 a, u32 b, u32 c) {
  if (self[0x1e]) return 0;
  if (UN32(self, 0x141e) == a && UN32(self, 0x1426) == c && UN32(self, 0x1422) == b) return 0;
  u32 flag = UN32(self, 0x115f);
  UN32(self, 0x141e) = a;
  UN32(self, 0x1426) = c;
  UN32(self, 0x1422) = b;
  if (flag == 0) {
    if (UN32(self, 0x1163) != 1) return 0;
    u8 *o = (u8 *)UN32(self, 0x1377);
    return SLOT(o, 0xc8, s3_t)(o, 0x3c, b);
  }
  if ((a & 0x402607) != 0) {
    if (GL(0x724934) != 1) {
      GL(0x724934) = 1;
      set_rs(0x1b, 1);
    }
    u32 x = a & 0x2000;
    if (x) {
      rc2(0x60fdd0, 1, 3);
      rc2s(0x60ff30, 0, 7, 2, 0);
      rc2s(0x60feb0, 0, 1, 2, 0);
      UN32(self, 0x141e) = 0xffffffff;
    } else {
      u32 edx = ((a & 0x400) == 0 && (a & 2)) ? 2 : 6;
      rc2(0x60fdd0, 5, edx);
    }
    if (c) {
      rc1(0x60fdb0, 1);
      rc2(0x60fd70, 5, c);
    } else {
      rc1(0x60fdb0, 0);
    }
    if (a & 2) rc0(0x60fe20);
    else if (x) rc0(0x60fe80);
    else rc0(0x60fe50);
  } else {
    if (GL(0x724934) != 0) {
      GL(0x724934) = 0;
      set_rs(0x1b, 0);
    }
    if (GL(0x724938) != 0) {
      GL(0x724938) = 0;
      set_rs(0xf, 0);
    }
    u32 v = GL(0x724954);
    if (GL(0x724950) != v) {
      GL(0x724950) = v;
      set_rs(0x22, v);
    }
  }
  if (a & 0x40000) {
    if (GL(0x72493c) != 0) {
      GL(0x72493c) = 0;
      set_rs(0xe, 0);
    }
  } else if (GL(0x72493c) != 1) {
    GL(0x72493c) = 1;
    set_rs(0xe, 1);
  }
  if (a & 0x20000) {
    if (GL(0x724968) != 8) {
      GL(0x724968) = 8;
      set_rs(0x17, 8);
    }
  } else if (GL(0x724968) != 4) {
    GL(0x724968) = 4;
    set_rs(0x17, 4);
  }
  if (a & 0x80000) {
    if (GL(0x72494c) != 0) {
      GL(0x72494c) = 0;
      set_rs(0x16, 1);
    }
  } else if (GL(0x72494c) != 1) {
    GL(0x72494c) = 1;
    set_rs(0x16, 2);
  }
  if (a & 0x100000) {
    if (GL(0x724940) == 0 && GL(0x724930) != 0) {
      GL(0x724930) = 0;
      set_rs(0x1c, 0);
    }
  } else if (GL(0x724940) == 0 && GL(0x724930) != 1) {
    GL(0x724930) = 1;
    set_rs(0x1c, 1);
  }
  u8 *d = DEV;
  SLOT(d, 0xfc, s4_t)(d, 0, 0xd, ((a >> 14) & 1) * 2 | 1);
  d = DEV;
  SLOT(d, 0xfc, s4_t)(d, 0, 0xe, ((a >> 15) & 1) * 2 | 1);
  return 0;
}
PCREG(6113d0, fn6113d0);
