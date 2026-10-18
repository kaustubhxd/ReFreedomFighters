#include "ff.h"

extern "C" void *ext_634d22(void *dst, const void *src, u32 n);
extern "C" void *ext_41e290(u32 size);

static inline u32 R32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 RW(const u8 *p) { u16 v; __builtin_memcpy(&v, p, 2); return v; }
static inline void WW(u8 *p, u32 v) { u16 w = (u16)v; __builtin_memcpy(p, &w, 2); }
static inline void cp8(u8 *d, const u8 *s) { __builtin_memcpy(d, s, 8); }
static inline void cp4(u8 *d, const u8 *s) { __builtin_memcpy(d, s, 4); }

// allocation size of count * unit: -1 on 32 bit overflow (mul; seto; neg; or)
static inline u32 asz(u32 count, u32 unit) {
  u64 pr = (u64)count * unit;
  return (pr >> 32) ? 0xffffffffu : (u32)pr;
}
static void log_line(u32 line, u32 file) {
  u8 *L = G(u8 *, 0x700390);
  typedef u32(THISCALL * V2)(void *, u32, u32);
  u8 *M = (u8 *)(*(V2 *)(*(u8 **)L + 0x20))(L, file, line);
  (void)M;
}
static u8 *logger(u32 line) {
  u8 *L = G(u8 *, 0x700390);
  typedef u32(THISCALL * V2)(void *, u32, u32);
  return (u8 *)(*(V2 *)(*(u8 **)L + 0x20))(L, 0x6a1438, line);
}
static void log_d3(u8 *M, u32 fmt, const u8 *f0) {
  u32 vtp = *(u32 *)M, fn = *(u32 *)(vtp + 0x2c), rc = vtp, ra = fn;
  double d0, d1, d2;
  float a, b, c;
  __builtin_memcpy(&a, f0, 4);
  __builtin_memcpy(&b, f0 + 4, 4);
  __builtin_memcpy(&c, f0 + 8, 4);
  d0 = a; d1 = b; d2 = c;
  u32 w[6];
  __builtin_memcpy(w, &d0, 8);
  __builtin_memcpy(w + 2, &d1, 8);
  __builtin_memcpy(w + 4, &d2, 8);
  asm volatile("pushl 20(%[w])\n\tpushl 16(%[w])\n\tpushl 12(%[w])\n\tpushl 8(%[w])\n\tpushl 4(%[w])\n\tpushl (%[w])\n\t"
               "pushl %[f]\n\tpushl %[o]\n\tcall *%%eax\n\taddl $32, %%esp"
               : "+a"(ra), "+c"(rc)
               : [w] "r"(w), [f] "r"(fmt), [o] "r"(M)
               : "edx", "memory", "cc");
}
static void log_d1(u8 *M, u32 fmt, u32 a) {
  u32 vtp = *(u32 *)M, fn = *(u32 *)(vtp + 0x2c), rc = vtp, ra = fn;
  asm volatile("pushl %[a]\n\tpushl %[f]\n\tpushl %[o]\n\tcall *%%eax\n\taddl $12, %%esp"
               : "+a"(ra), "+c"(rc)
               : [a] "r"(a), [f] "r"(fmt), [o] "r"(M)
               : "edx", "memory", "cc");
}

// 0x531270: thiscall(src, mode, unused) ret 0xc -> bytes consumed. Reads the packed model record at src into this
// (mode 1 allocates every array first, other modes fill the arrays already present).
extern "C" u32 THISCALL fn_531270(u8 *self, u8 *src, u32 mode, u32 unused);
extern "C" u32 THISCALL fn_531270(u8 *self, u8 *src, u32 mode, u32 unused) {
  u8 *p = src + 4;
  W32(self + 0x48, R32(src));
  WW(self + 0x2a, RW(p));
  u32 c52 = RW(p + 2);
  WW(self + 0x52, c52);
  p += 4;
  if (mode == 1) W32(self + 0x54, (u32)ext_41e290(asz(c52, 0x16)));
  ext_634d22((void *)R32(self + 0x54), p, RW(self + 0x52) * 0x16);
  p += RW(self + 0x52) * 0x16;
  u32 c58 = RW(p);
  p += 2;
  WW(self + 0x58, c58);
  if (mode == 1) W32(self + 0x5a, (u32)ext_41e290(asz(c58, 0xc)));
  ext_634d22((void *)R32(self + 0x5a), p, RW(self + 0x58) * 12);
  p += RW(self + 0x58) * 12;
  u32 c70 = RW(p);
  p += 2;
  WW(self + 0x70, c70);
  if (mode == 1) W32(self + 0x72, (u32)ext_41e290(asz(RW(self + 0x2a) * c70, 4)));
  ext_634d22((void *)R32(self + 0x72), p, (RW(self + 0x70) * RW(self + 0x2a)) << 2);
  p += (RW(self + 0x70) * RW(self + 0x2a)) * 4;
  u32 c5e = RW(p);
  p += 2;
  WW(self + 0x5e, c5e);
  if (mode == 1) W32(self + 0x60, (u32)ext_41e290(asz(c5e, 4)));
  ext_634d22((void *)R32(self + 0x60), p, RW(self + 0x5e) << 2);
  p += RW(self + 0x5e) * 4;
  u32 c64 = RW(p);
  p += 2;
  WW(self + 0x64, c64);
  if (mode == 1) W32(self + 0x66, (u32)ext_41e290(asz(c64, 10)));
  ext_634d22((void *)R32(self + 0x66), p, RW(self + 0x64) * 10);
  p += RW(self + 0x64) * 10;
  u32 c86 = RW(p);
  p += 2;
  WW(self + 0x86, c86);
  if (mode == 1) W32(self + 0x88, (u32)ext_41e290(asz(c86, 12)));
  ext_634d22((void *)R32(self + 0x88), p, RW(self + 0x86) * 12);
  p += RW(self + 0x86) * 12;
  if (self[4]) {
    if (mode == 1) W32(self + 0x8c, (u32)ext_41e290(asz(c86, 4)));
    ext_634d22((void *)R32(self + 0x8c), p, RW(self + 0x86) << 2);
    p += RW(self + 0x86) * 4;
    if (self[5]) {
      if (mode == 1) W32(self + 0x90, (u32)ext_41e290(asz(c86, 0x18)));
      ext_634d22((void *)R32(self + 0x90), p, RW(self + 0x86) * 24);
      p += RW(self + 0x86) * 24;
    }
  }
  u32 c6a = RW(p);
  p += 2;
  WW(self + 0x6a, c6a);
  if (mode == 1) W32(self + 0x6c, (u32)ext_41e290(asz(c6a, 4)));
  ext_634d22((void *)R32(self + 0x6c), p, RW(self + 0x6a) << 2);
  p += RW(self + 0x6a) * 4;
  u32 c76 = RW(p);
  p += 2;
  WW(self + 0x76, c76);
  if (mode == 1) {
    W32(self + 0x78, (u32)ext_41e290(asz(c76, 10)));
    W32(self + 0x7c, (u32)ext_41e290(c76));
  }
  ext_634d22((void *)R32(self + 0x78), p, RW(self + 0x76) * 10);
  p += RW(self + 0x76) * 10;
  ext_634d22((void *)R32(self + 0x7c), p, RW(self + 0x76));
  p += RW(self + 0x76);
  u32 c80 = RW(p);
  p += 2;
  WW(self + 0x80, c80);
  if (mode == 1) W32(self + 0x82, (u32)ext_41e290(c80));
  ext_634d22((void *)R32(self + 0x82), p, RW(self + 0x80));
  p += RW(self + 0x80);
  cp8(self + 0x2c, p);
  cp4(self + 0x34, p + 8);
  cp8(self + 0x3c, p + 0xc);
  cp4(self + 0x44, p + 0x14);
  cp8(self + 6, p + 0x18);
  cp4(self + 0xe, p + 0x20);
  cp8(self + 0x12, p + 0x24);
  cp4(self + 0x1a, p + 0x2c);
  cp8(self + 0x1e, p + 0x30);
  cp4(self + 0x26, p + 0x38);
  cp4(self + 0x38, p + 0x3c);
  cp4(self + 0x4c, p + 0x40);
  p += 0x44;
  if (G(u8, 0x701b5d)) {
    u8 *M = logger(0x9ac);
    u8 t[12];
    __builtin_memcpy(t, self + 6, 4);
    __builtin_memcpy(t + 4, self + 0xa, 4);
    __builtin_memcpy(t + 8, self + 0xe, 4);
    log_d3(M, 0x6a1508, t);
    M = logger(0x9ad);
    __builtin_memcpy(t, self + 0x12, 4);
    __builtin_memcpy(t + 4, self + 0x16, 4);
    __builtin_memcpy(t + 8, self + 0x1a, 4);
    log_d3(M, 0x6a1520, t);
    M = logger(0x9ae);
    log_d1(M, 0x6a1538, R32(self + 0x38));
  }
  return (u32)(p - src);
}
PCREG(531270, fn_531270);
