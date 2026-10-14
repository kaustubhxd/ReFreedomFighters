// batch38078.cpp - cascade s8 batch 38078: 0x4d6e80 (zip reader: walk the central directory entries and hand each file name to the matching archive).
#include "ff.h"

extern "C" u8 THISCALL ext_4d6520(u8 *self, char *name, u8 *out, u32 z);   // ret 0xc
extern "C" u8 THISCALL ext_4d7170(u8 *a, u8 *b);                            // ret 4
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32 (*log2_t)(void *, u32);
typedef u32 (*log5_t)(void *, u32, u32, u32, u32);
typedef u32 (*hook_t)();
typedef int (*strnicmp_t)(const char *, const char *, u32);
#define imp_strnicmp G(strnicmp_t, 0x67640c)
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword
#define W16(p, off) (*(u16 *)((u8 *)(p) + (off)))

static void *log_stream(u32 line) {
  u8 *lg = G(u8 *, 0x700390);
  return (void *)SLOT(lg, 0x20, v2_t)(lg, 0x696924, line);
}
static void assert_hook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}
static u32 tell(u8 *self, u8 *arg) { u8 *f = (u8 *)UN32(self, 0x15); return SLOT(f, 0xc, v1_t)(f, UN32(arg, 0x11)); }
static u32 eof(u8 *self, u8 *arg) { u8 *f = (u8 *)UN32(self, 0x15); return SLOT(f, 0x1c, v1_t)(f, UN32(arg, 0x11)); }
static void rd(u8 *self, u8 *arg, void *buf, u32 n) { u8 *f = (u8 *)UN32(self, 0x15); SLOT(f, 0x14, v3_t)(f, (u32)buf, n, UN32(arg, 0x11)); }
static void seek(u8 *self, u8 *arg, u32 pos) { u8 *f = (u8 *)UN32(self, 0x15); SLOT(f, 0x10, v3_t)(f, UN32(arg, 0x11), pos, 0); }
static void name_mismatch(u32 line, char *name, u32 a, u32 b) {
  void *st = log_stream(line);
  (*(log5_t **)st)[0x2c / 4](st, 0x696b30, (u32)name, a, b);
}

// 0x4d6e80, thiscall(arg) ret 4, void. this+0x15 = file object (slots 0xc tell, 0x10 seek, 0x14 read, 0x1c eof), arg+0x11 = handle, arg+0x2e = start position of the directory; entries start with a signature dword.
static void THISCALL fn4d6e80(u8 *self, u8 *arg) {
  char name[0x10004], extra[0x10004];
  u8 done = 0;
  u32 sig;
  u8 e[0x2a];
  u8 obj[0x1c];
  seek(self, arg, UN32(arg, 0x2e));
  if (eof(self, arg)) return;
  for (;;) {
    if (done) return;
    tell(self, arg);
    rd(self, arg, &sig, 4);
    tell(self, arg);
    if (sig == 0x2014b50) {
      rd(self, arg, e, 0x2a);
      u16 nl = W16(e, 0x18);
      if (nl) {
        rd(self, arg, name, nl);
        name[nl] = 0;
        u32 pos = tell(self, arg);
        if (ext_4d6520(self, name, obj, 0)) {
          if (ext_4d7170(obj, e + 2)) {
            if (imp_strnicmp((const char *)0x696b24, name, 5) != 0) name_mismatch(0x58a, name, UN32(self, 0xd), UN32(arg, 0xd));
            SLOT(self, 0x54, v1_t)(self, (u32)name);
          } else {
            if (ext_4d7170(e + 2, obj) && imp_strnicmp((const char *)0x696b24, name, 5) != 0) name_mismatch(0x591, name, UN32(arg, 0xd), UN32(self, 0xd));
            SLOT(arg, 0x54, v1_t)(arg, (u32)name);
          }
        }
        seek(self, arg, pos);
      }
      if (W16(e, 0x1a)) rd(self, arg, extra, W16(e, 0x1a));
      if (W16(e, 0x1c)) rd(self, arg, extra, W16(e, 0x1c));
    } else if (sig == 0x6054b50 || sig == 0x52756e65) {
      done = 1;
    } else {
      void *st = log_stream(0x5a6);
      (*(log2_t **)st)[0x2c / 4](st, 0x6969dc);
      assert_hook();
    }
    if (eof(self, arg)) return;
  }
}
PCREG(4d6e80, fn4d6e80);
