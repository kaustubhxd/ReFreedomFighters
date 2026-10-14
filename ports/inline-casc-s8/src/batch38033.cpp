// batch38033.cpp - cascade s8 batch 38033: 0x602e00 (convert a parsed value by the target mode).
#include "ff.h"

extern "C" void THISCALL ext_50d7b0(u8 *x, u32 *v);   // ret 4
extern "C" void THISCALL ext_602cd0(u8 *x, u32 *v);   // ret 4
extern "C" u32 THISCALL ext_5fb8b0(u8 *str, u32 pat);  // ret 4
typedef int (*strncmp_t)(const char *, const char *, u32);
typedef u32 (*hook_t)();
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(*log3_t)(void *, u32, u32);
#define imp_cmp G(strncmp_t, 0x676408)
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))

static void log_err(u32 line) {
  u8 *lg = G(u8 *, 0x700390);
  void *st = (void *)SLOT(lg, 0x20, v2_t)(lg, 0x6b98c8, line);
  (*(log3_t **)st)[0x2c / 4](st, 0x69c6b0, 0x69c7f0);
}
static void call_hook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x602e00, thiscall(x, y) ret 8; this[0x10] selects the mode. Mode 2: x gets the value 0 (0x50d7b0). Mode 3: this[4..8] is a text; when it is not exactly the 3 characters at 0x6b8788 it is
// tested with 0x5fb8b0 against 0x6b869c (true -> 0x602cd0(x, 0)) and 0x6b8774 (true -> error 0x10e); otherwise (or in the remaining case) x gets 0. Mode 4: needs this[0x1c] (error 0x11c); y is
// the maker object (null -> error 0x117 and this[0x1c] is used); its slot 0 builds a value from this[4]; x (tag byte at x[4]: 0 or 4 accepted) releases its old value through slot 0x28 and
// stores the new one with tag 4. Any other mode logs error 0x120. Every error calls the assert hook (int3 when it is null).
static void THISCALL fn602e00(u8 *self, u8 *x, u8 *y) {
  u32 mode = *(u32 *)(self + 0x10);
  if (mode == 2) {
    u32 local = 0;
    ext_50d7b0(x, &local);
    return;
  }
  if (mode == 3) {
    u8 *edi = self + 4;
    s32 len = *(s32 *)(self + 8) - *(s32 *)(self + 4);
    u32 n = len > 3 ? 3 : (u32)len;
    int r = imp_cmp(*(const char **)edi, (const char *)0x6b8788, n);
    bool toTests = !(r == 0 && len >= 3 && !(len > 3));
    if (toTests) {
      if (ext_5fb8b0(edi, 0x6b869c) == 0) {
        u32 local = 0;
        ext_602cd0(x, &local);
        return;
      }
      if (ext_5fb8b0(edi, 0x6b8774) != 0) {
        log_err(0x10e);
        call_hook();
        return;
      }
    }
    u32 local = 0;
    ext_50d7b0(x, &local);
    return;
  }
  if (mode == 4) {
    if (*(u32 *)(self + 0x1c) == 0) {
      log_err(0x11c);
      call_hook();
      return;
    }
    u8 *obj = y;
    if (!obj) {
      log_err(0x117);
      call_hook();
      obj = *(u8 **)(self + 0x1c);
    }
    u32 r = SLOT(obj, 0, v2_t)(obj, *(u32 *)(self + 4), 0);
    u8 tag = x[4];
    if (tag == 0 || tag == 4) {
      if (tag == 4) {
        u8 *old = *(u8 **)x;
        SLOT(old, 0x28, v0_t)(old);
      }
      *(u32 *)x = r;
      x[4] = 4;
    }
    return;
  }
  log_err(0x120);
  call_hook();
}
PCREG(602e00, fn602e00);
