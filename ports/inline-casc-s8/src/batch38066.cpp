// batch38066.cpp - cascade s8 batch 38066: 0x555830 (look up / create a cached object for a script argument and record whether it has no [0x48]).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 a);   // ret 4
extern "C" void THISCALL ext_5002f0(u8 *self, u32 a);  // ret 4
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(*log2_t)(void *, u32);
typedef u32(*log3_t)(void *, u32, u32);
typedef u32 (*hook_t)();
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)

static void *log_stream(u32 file, u32 line) {
  u8 *lg = G(u8 *, 0x700390);
  return (void *)SLOT(lg, 0x20, v2_t)(lg, file, line);
}
static void assert_hook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}
// reads the argument slot's bool-ish tag (byte at +4 must be 0 or 1); otherwise logs 0x104 and calls the assert hook
static void check_tag(u8 *p) {
  u8 t = p[4];
  if (t != 0 && t != 1) {
    void *st = log_stream(0x69c8e0, 0x104);
    (*(log3_t **)st)[0x2c / 4](st, 0x69c6b0, 0x69c938);
    assert_hook();
  }
}
static void drop_arg(u8 *arg) {
  u8 *r = ext_5003d0(*(u8 **)(arg + 8), 0);
  ext_5002f0(r, 0);
}
static void log2(u32 line, u32 msg) {
  void *st = log_stream(0x6a57fc, line);
  (*(log2_t **)st)[0x2c / 4](st, msg);
}

// 0x555830, thiscall(arg) ret 4. this = cache (+0x14 count, +0x18 array of object pointers); arg+4 / arg+8 = argument cells.
static void THISCALL fn555830(u8 *self, u8 *arg) {
  u8 *r = ext_5003d0(*(u8 **)(arg + 4), 0);
  check_tag(r);
  u8 *tbl = *(u8 **)(ENG + 0x9b);
  u8 *key = (u8 *)SLOT(tbl, 0x58, v1_t)(tbl, *(u32 *)r);
  if (!key) {
    drop_arg(arg);
    log2(0x468, 0x6a5c90);
    return;
  }
  u8 *found = 0;
  u32 cnt = *(u32 *)(self + 0x14);
  for (u32 i = 0; i < cnt; i++) {
    u8 *o = *(u8 **)(self + 0x18 + 4 * i);
    if (o && *(u8 **)(o + 0x30) == key) { found = o; break; }
  }
  if (!found) {
    found = (u8 *)SLOT(key, 0x100, v1_t)(key, 0x6a5cac);
    if (!found) {
      log2(0x475, 0x6a5cb8);
      drop_arg(arg);
      return;
    }
    *(u8 **)(self + 0x18 + 4 * *(u32 *)(self + 0x14)) = found;
    (*(u32 *)(self + 0x14))++;
  }
  u8 *S = *(u8 **)(arg + 8);
  u8 *slot;
  if (*(u32 *)(S + 8) > 0) {
    u32 idx = *(u32 *)(S + 4);
    u8 *A = *(u8 **)S;
    if (!(idx < *(u32 *)(A + 8))) assert_hook();
    slot = *(u8 **)A + idx * 8;
  } else {
    assert_hook();
    u8 *A = *(u8 **)S;
    if (!(*(u32 *)(A + 8) > 0)) assert_hook();
    slot = *(u8 **)A;
  }
  u32 flag = *(u32 *)(found + 0x48) == 0;
  check_tag(slot);
  *(u32 *)slot = flag;
  slot[4] = 1;
}
PCREG(555830, fn555830);
