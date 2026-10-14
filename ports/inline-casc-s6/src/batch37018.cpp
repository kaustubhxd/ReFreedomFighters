// batch37018.cpp - cascade s6 batch 37018: 0x509e50.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u32 self, u32 idx);   // ret 4
typedef u32(*hook_t)();
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v4_t)(void *, u32, u32, u32, u32);
typedef void(*cd3_t)(void *, u32, u32);

static void logfail(u32 line, u32 msg) {
  u8 *lg = *(u8 **)0x700390;
  void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x69c8e0, line);
  (*(cd3_t **)L)[0x2c / 4](L, 0x69c6b0, msg);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x509e50, thiscall(a) ret 4: reads a name from node 0 of a+4 (type 3: the dword; type 4: slot 0x34 of the object; else logs error 0x111 and uses 0),
// turns it into a 16-bit id through slot 0x114 of the object table, checks that nodes 1 and 2 have type 0 or 1 (else logs error 0x104), and for every item the list at
// [[this+0xc]+0x18] yields (slot 0x4c starts, slot 0x5c iterates) calls slot 0x12c of [this+0xc] with (item, id, &node 1 value).
static void THISCALL fn509e50(u8 *self, u8 *a) {
  u8 *n0 = ext_5003d0(*(u32 *)(a + 4), 0);
  u32 name;
  u8 ty = n0[4];
  if (ty == 3) {
    name = *(u32 *)n0;
  } else if (ty == 4) {
    void *o = *(void **)n0;
    name = (*(v0_t **)o)[0x34 / 4](o);
  } else {
    logfail(0x111, 0x69c9b0);
    name = 0;
  }
  void *t = *(void **)(*(u8 **)0x70039c + 0x9b);
  u32 id = (u16)(*(v4_t **)t)[0x114 / 4](t, name, 0, 0x69d214, 0x102);
  u8 *n1 = ext_5003d0(*(u32 *)(a + 4), 1);
  if (n1[4] > 1) logfail(0x104, 0x69c938);
  u32 var8 = *(u32 *)n1;
  u8 *n2 = ext_5003d0(*(u32 *)(a + 4), 2);
  if (n2[4] > 1) logfail(0x104, 0x69c938);
  u32 var4 = *(u32 *)n2;
  (void)var4;
  void *lst = *(void **)(*(u8 **)(self + 0xc) + 0x18);
  if (lst) {
    u32 var14;
    (*(v1_t **)lst)[0x4c / 4](lst, (u32)&var14);
    lst = *(void **)(*(u8 **)(self + 0xc) + 0x18);
    u32 item = (*(v1_t **)lst)[0x5c / 4](lst, (u32)&var14);
    while (var14 != 0) {
      void *m = *(void **)(self + 0xc);
      (*(v3_t **)m)[0x12c / 4](m, item, id, (u32)&var8);
      lst = *(void **)(*(u8 **)(self + 0xc) + 0x18);
      item = (*(v1_t **)lst)[0x5c / 4](lst, (u32)&var14);
    }
  }
}
PCREG(509e50, fn509e50);
