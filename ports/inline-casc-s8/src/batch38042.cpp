// batch38042.cpp - cascade s8 batch 38042: 0x500cb0 (script call: move one object relative to another).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 a);   // ret 4
extern "C" void THISCALL ext_5002f0(u8 *self, u32 a);  // ret 4
extern "C" u32 THISCALL ext_4db9a0(u8 *node, u32 flags);   // ret 4
extern "C" void THISCALL ext_4daf90(u8 *node, void *out);  // ret 4
extern "C" void THISCALL ext_4db670(u8 *node, void *out);  // ret 4
extern "C" void THISCALL ext_4db1f0(u8 *node, void *out);  // ret 4
typedef u32 (*hook_t)();
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(*log2_t)(void *, u32);
typedef u32(*log3_t)(void *, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)

static void *log_stream(u32 file, u32 line) {
  u8 *lg = G(u8 *, 0x700390);
  return (void *)SLOT(lg, 0x20, v2_t)(lg, file, line);
}
static void call_hook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x500cb0, stdcall(req) ret 4. Two object ids are read from req[4] (0x5003d0 with 0 and 1; a type byte other than 0 / 1 logs error 0x104 and calls the assert hook but carries on) and resolved through
// the engine table's slot 0x54; req[8] is primed with 0x5003d0 / 0x5002f0. A missing first or second object logs 0x2da / 0x2df and returns; a first object that fails 0x4db9a0(0x2000e1) logs 0x2e6.
// Then the second object's position (0x4daf90 / 0x4db670) is moved by the first object's 0x4db1f0 and handed to slot 0x180 of the first object's +0x54 (with -10.0f); its byte result goes to req[8] through
// 0x5003d0 / 0x5002f0.
static void STDCALL fn500cb0(u8 *req) {
  u8 *a = ext_5003d0(*(u8 **)(req + 4), 0);
  if (a[4] != 0 && a[4] != 1) {
    void *st = log_stream(0x69c8e0, 0x104);
    (*(log3_t **)st)[0x2c / 4](st, 0x69c6b0, 0x69c938);
    call_hook();
  }
  u8 *t = *(u8 **)(ENG + 0x9b);
  u8 *x = (u8 *)SLOT(t, 0x54, v1_t)(t, *(u32 *)a);
  u8 *b = ext_5003d0(*(u8 **)(req + 4), 1);
  if (b[4] != 0 && b[4] != 1) {
    void *st = log_stream(0x69c8e0, 0x104);
    (*(log3_t **)st)[0x2c / 4](st, 0x69c6b0, 0x69c938);
    call_hook();
  }
  t = *(u8 **)(ENG + 0x9b);
  u8 *y = (u8 *)SLOT(t, 0x54, v1_t)(t, *(u32 *)b);
  u8 *o = ext_5003d0(*(u8 **)(req + 8), 0);
  ext_5002f0(o, 0);
  if (!x) {
    void *st = log_stream(0x69ca10, 0x2da);
    (*(log2_t **)st)[0x2c / 4](st, 0x69cb78);
    return;
  }
  if (!y) {
    void *st = log_stream(0x69ca10, 0x2df);
    (*(log2_t **)st)[0x2c / 4](st, 0x69cbe0);
    return;
  }
  if (!(u8)ext_4db9a0(x, 0x2000e1)) {
    void *st = log_stream(0x69ca10, 0x2e6);
    (*(log2_t **)st)[0x2c / 4](st, 0x69cc40);
  }
  u8 pos[0xc];
  ext_4daf90(y, pos);
  ext_4db670(y, pos);
  ext_4db1f0(x, pos);
  u8 *obj = *(u8 **)(x + 0x54);
  u8 r = (u8)SLOT(obj, 0x180, v2_t)(obj, (u32)pos, 0xc1200000);
  o = ext_5003d0(*(u8 **)(req + 8), 0);
  ext_5002f0(o, r);
}
PCREG(500cb0, fn500cb0);
