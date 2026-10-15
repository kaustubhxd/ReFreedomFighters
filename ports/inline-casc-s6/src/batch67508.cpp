// batch67508.cpp - cascade s6 batch 67508: 0x5591b0.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u32 self, u32 idx);   // ret 4
extern "C" void THISCALL ext_58b780(u8 *obj, u32 arg);   // ret 4
extern "C" void THISCALL ext_594460(u8 *obj, u32 arg);   // ret 4
typedef u32 (*hook_t)();
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd3_t)(void *, u32, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

static void typeCheck(u8 *n) {
  if (n[4] != 0 && n[4] != 1) {
    u8 *lg = *(u8 **)0x700390;
    void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x69c8e0, 0x104);
    (*(cd3_t **)L)[0x2c / 4](L, 0x69c6b0, 0x69c938);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
}

// 0x5591b0, thiscall(a) ret 4: script op taking an object id and an int (both type-checked 0 / 1). When the id resolves to an object, a second lookup is made and the object is kept only
// if it answers slot 0x1e0 with the value stored at +0x23 of the table's slot-0x154 record for the name at 0x6a6088; the (re)resolved object (or null) is then passed with this+0x1c to
// 0x58b780 when the int is non-zero and to 0x594460 otherwise.
static void THISCALL fn5591b0(u8 *self, u8 *a) {
  u32 args = *(u32 *)(a + 4);
  u8 *n0 = ext_5003d0(args, 0);
  typeCheck(n0);
  u32 id = D32(n0, 0);
  u8 *n1 = ext_5003d0(args, 1);
  typeCheck(n1);
  u32 flag = D32(n1, 0);
  u8 *h = 0;
  if (vcall<u32>(tabObj(), 0x58, id)) {
    u8 *obj = (u8 *)vcall<u32>(tabObj(), 0x58, id);
    u8 *k = (u8 *)vcall<u32>(tabObj(), 0x154, 0x6a6088u, 0u);
    if ((u8)vcall<u32>(obj, 0x1e0, D32(k, 0x23))) h = (u8 *)vcall<u32>(tabObj(), 0x58, id);
  }
  if (flag) ext_58b780(h, D32(self, 0x1c));
  else ext_594460(h, D32(self, 0x1c));
}
PCREG(5591b0, fn5591b0);
