// batch240001.cpp - Sonnet-w4a: small MSVC CRT helpers and unwind funclets (hand ports).
#include "ff.h"

extern "C" u32 ext_634e7e(u32 p);                 // import thunk (cdecl, 1 arg)
extern "C" u32 ext_634e78(u32 cell, u32 p);       // import thunk (cdecl, 2 args)
extern "C" u32 ext_634e8a(u32 a, u32 b, u32 c);   // _controlfp_s thunk (cdecl)
extern "C" u32 ext_634879(u32 code);              // fatal handler (does not return)
extern "C" u32 ext_634cb5();
extern "C" u32 ext_633ed4(u32 p);
extern "C" u32 ext_4690b0(u32 a, u32 b);

static inline u32 w4a_ror(u32 v, u32 n) { n &= 31; return n ? (v >> n) | (v << (32 - n)) : v; }

// 0x633170: cdecl(a, rec): rec->fn(rec->arg, a); rec at +0x24 holds the function, +0x28 its first argument
static u32 fn_633170(u32 a, u8 *rec) {
  typedef u32 (*fp)(u32, u32);
  fp f = *(fp *)(rec + 0x24);
  return f(*(u32 *)(rec + 0x28), a);
}
PCREG(633170, fn_633170);

// 0x6344f2: cdecl(v): EncodePointer-like cookie rotate: ror(v, 0x20 - (cookie & 0x1f)) ^ cookie
static u32 fn_6344f2(u32 v) {
  u32 c = G(u32, 0x6f5630);
  return w4a_ror(v, 0x20 - (c & 0x1f)) ^ c;
}
PCREG(6344f2, fn_6344f2);

// 0x633ed4: cdecl(p): returns p when the lookup succeeded (result 0), else 0
static u32 fn_633ed4(u32 p) {
  u32 c = G(u32, 0x6f5630);
  u32 x = w4a_ror(c ^ G(u32, 0x725498), c & 0x1f);
  u32 r = (x == 0xffffffffu) ? ext_634e7e(p) : ext_634e78(0x725498, p);
  return r == 0 ? p : 0;
}
PCREG(633ed4, fn_633ed4);

// 0x633f0f: cdecl(p): 0 when 633ed4(p) is non-zero, else -1
static u32 fn_633f0f(u32 p) {
  u32 r = ext_633ed4(p);
  return r != 0 ? 0u : 0xffffffffu;
}
PCREG(633f0f, fn_633f0f);

// 0x633e8f: cdecl(a): if the flag helper is non-zero and the low byte of a is 0, swap 0 into [0x725494] and return its old value
static u32 fn_633e8f(u32 a) {
  u32 r = ext_634cb5();
  if (r && (a & 0xff) == 0) {
    r = G(u32, 0x725494);
    G(u32, 0x725494) = 0;
  }
  return r;
}
PCREG(633e8f, fn_633e8f);

// 0x634823: no args: if _controlfp_s(0, 0x10000, 0x30000) is non-zero, call the fatal handler 634879(7)
static u32 fn_634823() {
  u32 r = ext_634e8a(0, 0x10000, 0x30000);
  if (r == 0) return r;
  return ext_634879(7);
}
PCREG(634823, fn_634823);

// 0x6665c0 / 0x666790: funclets (parent frame): ext_4690b0([ebp+8], [[[ebp-0x10]+0x10]+0x14])
#define W4A_FUNCLET_4690B0(addr)                                       \
  static u32 fn_##addr() {                                             \
    u8 *pebp = *(u8 **)__builtin_frame_address(0);                     \
    u8 *p = *(u8 **)(pebp - 0x10);                                     \
    u32 b = *(u32 *)(*(u8 **)(p + 0x10) + 0x14);                       \
    return ext_4690b0(*(u32 *)(pebp + 8), b);                          \
  }                                                                    \
  PCREG(addr, fn_##addr);
W4A_FUNCLET_4690B0(6665c0)
W4A_FUNCLET_4690B0(666790)
