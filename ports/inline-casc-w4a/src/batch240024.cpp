// batch240024.cpp - Sonnet-w4a: 0x5f4390 (object state dump through the global text stream, hand port).
#include "ff.h"

extern "C" u32 THISCALL ext_600800_t(u32 self) __asm__("ext_600800");
extern "C" u32 THISCALL ext_600810_t(u32 self) __asm__("ext_600810");

typedef u32 (*pf_t)(u32 self, u32 fmt, ...);   // cdecl printf-like stream slot 0xc
static inline u32 stream() { return G(u32, 0x724270); }   // 0x5fa630: returns the global stream object
static inline pf_t pf_of(u32 s) { return *(pf_t *)(*(u8 **)s + 0xc); }
#define P(...) do { u32 s_ = stream(); pf_of(s_)(s_, __VA_ARGS__); } while (0)

// 0x5f4390: thiscall(): prints the state of a record (flags, ids, a float, names, counters) through the stream's printf slot
static void THISCALL fn_5f4390(u8 *self) {
  P(0x6b8bb4u);
  P(0x6b8bdcu);
  if ((*(u16 *)(self + 0xac) & 0x8800) != 0) { P(0x6b8becu); } else { P(0x6b8c14u); }
  P(0x6b8c34u, (u32) * (u16 *)(self + 0xaa));
  if ((*(u16 *)(self + 0xac) & 0x4000) != 0) { P(0x6b8c54u); }
  P(0x6b8c78u, G(u32, 0x6efbe4 + 4 * (*(u16 *)(self + 0xac) & 0xf)));
  {
    u32 s1 = stream();
    u32 s2 = stream();
    pf_t pf2 = pf_of(s2);
    ((u32(THISCALL *)(u32))(*(u32 *)(*(u8 **)s1 + 4)))(s1);
    double d2;
    asm volatile("fstpl %0" : "=m"(d2));    // the exe stores st0 of an EMPTY x87 stack here (stack underflow: the indefinite NaN on hardware); same instruction, same result
    pf2(s2, 0x6b8c98u, (double)*(float *)(self + 0xa), d2);
  }
  P(0x6b8cd4u);
  {
    u32 s = stream();
    u32 r = ext_600800_t(*(u32 *)(self + 0x96));
    pf_of(s)(s, 0x6b8ce8u, r);
  }
  {
    u32 s1 = stream();
    u32 s3 = stream();
    u32 r = ((u32(THISCALL *)(u32, u32))(*(u32 *)(*(u8 **)s3 + 0x1c)))(s3, *(u32 *)(self + 0x24));
    pf_of(s1)(s1, 0x6b8d08u, r);
  }
  P(0x6b8d44u, *(u32 *)(self + 0x20) == 0 ? 0x6b8d30u : 0x6b8d28u);
  if (*(u32 *)(self + 0x20) != 0) { P(0x6b8d64u, *(u32 *)(self + 0x20)); }
  P(0x6b8d84u, (u32)(s32) * (s16 *)(self + 8));
  P(0x6b8da4u);
  P(0x6b8db0u, 0xad2u);
  {
    u32 s = stream();
    u32 r = ext_600810_t((u32)(self + 0x9a));
    pf_of(s)(s, 0x6b8dd0u, r);
  }
  P(0x6b8df0u);
  P(0x6b8dfcu, *(u32 *)(self + 0x3c), *(u32 *)(self + 0x38));
  P(0x6b8e28u, *(u32 *)(self + 0x48), *(u32 *)(self + 0x44));
  P(0x6b8e54u, *(u32 *)(self + 0x60), *(u32 *)(self + 0x5c));
}
PCREG(5f4390, fn_5f4390);
