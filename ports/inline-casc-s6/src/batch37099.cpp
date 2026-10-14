// batch37099.cpp - cascade s6 batch 37099: 0x553e30.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u32 self, u32 idx);        // ret 4
extern "C" u8 *THISCALL ext_5002f0(u8 *node, u32 v);          // ret 4
extern "C" u32 THISCALL ext_4db9a0(u8 *self, u32 key);        // ret 4, bool in al
typedef u32 (*hook_t)();
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd2_t)(void *, u32);
typedef void (*cd3_t)(void *, u32, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

static void logMiss() {
  u8 *lg = *(u8 **)0x700390;
  void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x6a57fc, 0x3ce);
  (*(cd2_t **)L)[0x2c / 4](L, 0x6a5bc0);
}

// 0x553e30, stdcall(a) ret 4: script op. Resolves the object whose id is the first argument (a+4 stack, node 0); it must answer slot 0x1e0 (0x100001), otherwise error 0x3ce is
// logged and 0 is stored in the result node (a+8). Otherwise it walks the object's chain of child records (+8, advanced with slot 0x50 and an out pointer) for one whose
// type 0x2007f9 is set and whose linked record's flag bit 10 is set; its handle (+0x54, via table slot 0x4c) is the result. With no such record the result node is set to an
// empty int (after a type check against 0 / 1 that logs error 0x104 and calls the assert hook).
static void STDCALL fn553e30(u8 *a) {
  u8 *idn = ext_5003d0(*(u32 *)(a + 4), 0);
  u8 *esi = (u8 *)vcall<u32>(tabObj(), 0x58, D32(idn, 0));
  if (!esi || !(u8)vcall<u32>(esi, 0x1e0, 0x100001u)) {
    logMiss();
    ext_5002f0(ext_5003d0(*(u32 *)(a + 8), 0), 0);
    return;
  }
  u8 *cur = *(u8 **)(esi + 8);
  while (cur) {
    if ((u8)ext_4db9a0(cur, 0x2007f9) && D32(cur, 0x50)) {
      u8 *x = *(u8 **)(cur + 0x50);
      u32 v = D32(*(u8 **)(*(u8 **)(x + 0x54) + 8), 0x3c);
      if (((~(v >> 10)) & 1) == 0) {
        u32 h = vcall<u32>(tabObj(), 0x4c, D32(cur, 0x54));
        ext_5002f0(ext_5003d0(*(u32 *)(a + 8), 0), h);
        return;
      }
    }
    vcall<void>(esi, 0x50, (u32)&cur);
  }
  u8 *n = ext_5003d0(*(u32 *)(a + 8), 0);
  if (n[4] != 0 && n[4] != 1) {
    u8 *lg = *(u8 **)0x700390;
    void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x69c8e0, 0x104);
    (*(cd3_t **)L)[0x2c / 4](L, 0x69c6b0, 0x69c938);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  n[4] = 1;
  D32(n, 0) = 0;
}
PCREG(553e30, fn553e30);
