// batch220019.cpp - Codex-x3a manual MMX-lane port of 0x61ad80.
#include "ff.h"

// `punpcklbw mm, zero` expands the four bytes of a dword into four independent
// 16-bit lanes. The original subsequently shifts/subtracts each lane; modelling
// those operations in u64 avoids introducing MMX state into the C++ port.
static inline u64 lane_expand(u32 v) {
  return (u64)(v & 0xffu) |
         ((u64)((v >> 8) & 0xffu) << 16) |
         ((u64)((v >> 16) & 0xffu) << 32) |
         ((u64)((v >> 24) & 0xffu) << 48);
}

static inline u64 lane_shl(u64 v, unsigned bits) {
  u64 out = 0;
  for (unsigned lane = 0; lane != 4; ++lane) {
    u32 word = (u32)(v >> (lane * 16)) & 0xffffu;
    out |= (u64)((word << bits) & 0xffffu) << (lane * 16);
  }
  return out;
}

static inline u64 lane_sub(u64 left, u64 right) {
  u64 out = 0;
  for (unsigned lane = 0; lane != 4; ++lane) {
    u32 a = (u32)(left >> (lane * 16)) & 0xffffu;
    u32 b = (u32)(right >> (lane * 16)) & 0xffffu;
    out |= (u64)((a - b) & 0xffffu) << (lane * 16);
  }
  return out;
}

static inline u32 read32(const void *p) {
  u32 v;
  __builtin_memcpy(&v, p, sizeof v);
  return v;
}

static inline u64 read64(const void *p) {
  u64 v;
  __builtin_memcpy(&v, p, sizeof v);
  return v;
}

static inline void write64(void *p, u64 v) { __builtin_memcpy(p, &v, sizeof v); }

// 0x61ad80: stdcall(src, count, flags), ret 12. `count` is required to be
// nonzero: the machine routine's decrement-and-branch loops wrap at zero.
extern "C" void STDCALL lifted_61ad80(u8 *src, u32 count, u32 flags) {
  const u32 n_iter = (count + 3) >> 2;
  u8 *table1 = (u8 *)0x812840u;

  if (flags & 0x2000u) {
    u8 *record = src;
    u8 *out = table1;
    for (u32 i = 0; i < n_iter; ++i, record += 0x90, out += 0x20) {
      write64(out + 0x00, lane_shl(lane_expand(read32(record + 0x18)), 5));  // m0_61ad80
      write64(out + 0x08, lane_shl(lane_expand(read32(record + 0x3c)), 5));
      write64(out + 0x10, lane_shl(lane_expand(read32(record + 0x60)), 5));
      write64(out + 0x18, lane_shl(lane_expand(read32(record + 0x84)), 5));
    }

    const u64 base = read64((const void *)0x6efd14u);
    u8 *d2 = (u8 *)0x812940u;
    u8 *p = src;
    for (u32 i = 0; i < count; ++i, p += 0x24, d2 += 8) {  // m1_61ad80
      const u32 byte3 = read32(p + 0x18) >> 24;
      const u32 repeated = byte3 * 0x010101u;
      write64(d2, lane_sub(base, lane_shl(lane_expand(repeated), 5)));  // m2_61ad80
    }
  } else {
    u8 *record = src;
    u8 *out = table1;
    for (u32 i = 0; i < n_iter; ++i, record += 0x90, out += 0x20) {
      write64(out + 0x00, lane_shl(lane_expand(read32(record + 0x18)), 4));  // m3_61ad80
      write64(out + 0x08, lane_shl(lane_expand(read32(record + 0x3c)), 4));
      write64(out + 0x10, lane_shl(lane_expand(read32(record + 0x60)), 4));
      write64(out + 0x18, lane_shl(lane_expand(read32(record + 0x84)), 4));
    }

    u8 *zero = (u8 *)0x812940u;
    for (u32 i = 0; i < n_iter; ++i, zero += 0x20) {
      write64(zero + 0x00, 0);
      write64(zero + 0x08, 0);
      write64(zero + 0x10, 0);
      write64(zero + 0x18, 0);  // m4_61ad80
    }
  }
}
PCREG(61ad80, lifted_61ad80);
