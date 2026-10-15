// batch66033.cpp - cascade s4 batch 66033: 0x425f80 (tier F row).
#include "ff.h"
#include <stdarg.h>

typedef void *(*iob_t)(u32);
typedef s32(*fflush_t)(void *);
typedef u32(STDCALL *sendmsg_t)(u32, u32, u32, void *);

extern "C" s32 ext_42abee(char *buf, const char *fmt, va_list ap);   // cdecl vsprintf-like
extern "C" void ext_42ab62(const char *s);                          // cdecl print

static u32 slen(const char *s) {
  u32 n = 0;
  while (s[n]) n++;
  return n;
}

// 0x425f80, cdecl(obj, fmt, ...) returns nothing: obj[0x12] set -> return. obj[0x12] = 1; formats into a 0x400-byte stack buffer with 0x42abee; makes sure the text ends with '\n' (appends the 2 bytes at 0x676c04 when it does not, or when it is empty);
// 0x42ab62(buf); fflush(__acrt_iob_func(1)); obj[0x24] (window) != 0 -> SendMessageA(window, 0x4a, 0, &{0, strlen + 1, buf}). obj[0x12] = 0.
extern "C" void fn425f80(u8 *obj, const char *fmt, ...) {
  char buf[0x400];
  if (obj[0x12]) return;
  obj[0x12] = 1;
  va_list ap;
  va_start(ap, fmt);
  ext_42abee(buf, fmt, ap);
  va_end(ap);
  u32 len = slen(buf);
  if (len == 0 || buf[len - 1] != 0xa) *(u16 *)(buf + len) = G(u16, 0x676c04);
  ext_42ab62(buf);
  G(fflush_t, 0x6763c4)(G(iob_t, 0x6763c8)(1));
  u32 wnd = *(u32 *)(obj + 0x24);
  if (wnd) {
    u32 cds[3];
    cds[0] = 0;
    cds[1] = slen(buf) + 1;
    cds[2] = (u32)buf;
    G(sendmsg_t, 0x67621c)(wnd, 0x4a, 0, cds);
  }
  obj[0x12] = 0;
}
PCREG(425f80, fn425f80);
