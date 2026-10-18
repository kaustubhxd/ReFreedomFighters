#include "ff.h"

typedef u32(THISCALL *S3)(void *, u32, u32, u32);
typedef u32(THISCALL *S1)(void *, u32);
extern "C" void *ext_634d22(void *dst, const void *src, u32 n);
extern "C" s32 STDCALL ext_62f5d0(void *rec, u32 mode);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static inline void log_line(u32 line) {
  void *L = G(void *, 0x700390);
  typedef u32(THISCALL * LogNew)(void *, u32, u32);
  u8 *M = (u8 *)(*(LogNew *)(*(u8 **)L + 0x20))(L, 0x696924, line);
  u32 ra = *(u32 *)(*(u8 **)M + 0x2c), rc = *(u32 *)M;
  u32 fmt = line == 0x46d ? 0x696998 : 0x696aa0;
  asm volatile(
      "pushl %[f]\n\t"
      "pushl %[m]\n\t"
      "call *%%eax\n\t"
      "addl $8, %%esp"
      : "+a"(ra), "+c"(rc)
      : [f] "r"(fmt), [m] "r"(M)
      : "edx", "memory", "cc");
}

// 0x4d7350: thiscall(this, s, dst, len) ret 0xc: reads len bytes of a compressed stream: this->[0x15] (an object) is the byte source with slots 0x10 (seek),
// 0x14 (read) and 0xc (tell), this->[0x11] its handle; s->[8] is the stream mode (0: plain passthrough read, 8: inflate through 0x62f5d0 with the record s->[0x26] and
// the 0x400 byte window at s+0x2e, other: log and return len - record length); returns the number of bytes not delivered
u32 THISCALL fn_4d7350(u8 *self, u8 *s, u32 dst, u32 len) {
  u8 *X = *(u8 **)(self + 0x15);
  u32 handle = rd32u(self + 0x11);
  (*(S3 *)(*(u8 **)X + 0x10))(X, handle, rd32u(s + 0x1e), 0);
  u32 mode = *(u16 *)(s + 8);
  if (mode == 0) {
    X = *(u8 **)(self + 0x15);
    (*(S3 *)(*(u8 **)X + 0x10))(X, handle, rd32u(s + 0x1e), 0);
    return (*(S3 *)(*(u8 **)X + 0x14))(X, dst, len, handle);
  }
  u8 *rec = *(u8 **)(s + 0x26);
  if (mode != 8) {
    log_line(0x46d);
    return len - rd32u(rec + 0x10);
  }
  u32 state = rd32u(s + 0x42e);
  if (state != 0) return state == 1 ? 0 : 0xffffffffu;
  wr32u(rec + 0xc, dst);
  rec = *(u8 **)(s + 0x26);
  wr32u(rec + 0x10, len);
  rec = *(u8 **)(s + 0x26);
  if (rd32u(rec + 0x10) != 0) {
    for (;;) {
      if (rd32u(s + 0x42e) != 0) break;
      rec = *(u8 **)(s + 0x26);
      u8 *win = s + 0x2e;
      u32 keep = rd32u(rec + 4);
      u32 off = 0x400 - keep;
      ext_634d22(win, win + off, keep);
      u32 avail = rd32u(s + 0x12) - rd32u(s + 0x1e);
      u32 n = avail < off ? avail : off;
      if (n != 0) {
        X = *(u8 **)(self + 0x15);
        u32 got = (*(S3 *)(*(u8 **)X + 0x14))(X, (u32)win, n, handle);
        wr32u(*(u8 **)(s + 0x26) + 4, got);
      }
      rec = *(u8 **)(s + 0x26);
      wr32u(rec, (u32)win);
      s32 r = ext_62f5d0(*(void **)(s + 0x26), 3);
      wr32u(s + 0x42e, (u32)r);
      u32 idx = (u32)r + 3;
      if (idx <= 4) {
        if (idx == 0) log_line(0x453);
        else if (idx == 1) log_line(0x456);
        else if (idx == 2) log_line(0x459);
      } else {
        log_line(0x45f);
      }
      rec = *(u8 **)(s + 0x26);
      if (rd32u(rec + 0x10) == 0) break;
    }
  }
  X = *(u8 **)(self + 0x15);
  u32 pos = (*(S1 *)(*(u8 **)X + 0xc))(X, handle);
  wr32u(s + 0x1e, pos);
  rec = *(u8 **)(s + 0x26);
  return len - rd32u(rec + 0x10);
}
PCREG(4d7350, fn_4d7350);
