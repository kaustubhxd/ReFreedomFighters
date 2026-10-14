// batch37028.cpp - cascade s6 batch 37028: 0x556e80.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u32 self, u32 idx);   // ret 4
extern "C" void THISCALL ext_591820(u8 *self, u32 id);   // ret 4
typedef u32 (*hook_t)();
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v5_t)(void *, u32, u32, u32, u32, u32);
typedef void(*cdl_t)(void *, ...);

static void *logger(u32 file, u32 line) {
  u8 *lg = *(u8 **)0x700390;
  return (void *)(*(v2_t **)lg)[0x20 / 4](lg, file, line);
}
static void assertHook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}
static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

// 0x556e80, stdcall(a) ret 4: command that resolves node 0 of a+4 (type 0/1 checked, error 0x104) to an object through the table, node 2 to a name (type 3 dword,
// type 4 slot 0x34, else error 0x111 and 0). When the object exists and answers slot 0x1e0(0x2003e8): node 1 must be 0 (error 0x2d1), the name is turned into a 16-bit
// id through table slot 0x114 and handed to 0x591820 on the object; otherwise error 0x2cd.
static void STDCALL fn556e80(u8 *a) {
  u8 *n0 = ext_5003d0(*(u32 *)(a + 4), 0);
  if (n0[4] > 1) {
    void *L = logger(0x69c8e0, 0x104);
    (*(cdl_t **)L)[0x2c / 4](L, 0x69c6b0, 0x69c938);
    assertHook();
  }
  void *t = tabObj();
  u8 *obj = (u8 *)(*(v1_t **)t)[0x58 / 4](t, *(u32 *)n0);
  u8 *n2 = ext_5003d0(*(u32 *)(a + 4), 2);
  u32 name;
  u8 ty = n2[4];
  if (ty == 3) {
    name = *(u32 *)n2;
  } else if (ty == 4) {
    void *o = *(void **)n2;
    name = (*(v0_t **)o)[0x34 / 4](o);
  } else {
    void *L = logger(0x69c8e0, 0x111);
    (*(cdl_t **)L)[0x2c / 4](L, 0x69c6b0, 0x69c9b0);
    assertHook();
    name = 0;
  }
  u32 var8 = *(u32 *)ext_5003d0(*(u32 *)(a + 4), 3);
  u32 var4 = *(u32 *)ext_5003d0(*(u32 *)(a + 4), 4);
  (void)var4;
  if (obj && (u8)(*(v1_t **)obj)[0x1e0 / 4](obj, 0x2003e8)) {
    u8 *n1 = ext_5003d0(*(u32 *)(a + 4), 1);
    if (*(u32 *)n1 != 0) {
      void *L = logger(0x6a57fc, 0x2d1);
      (*(cdl_t **)L)[0x2c / 4](L, 0x6a590c);
    }
    t = tabObj();
    u32 id = (u16)(*(v5_t **)t)[0x114 / 4](t, name, 0, 0x6a57fc, 0x2d4, (u32)&var8);
    ext_591820(obj, id);
    return;
  }
  void *L = logger(0x6a57fc, 0x2cd);
  (*(cdl_t **)L)[0x2c / 4](L, 0x6a58c0);
}
PCREG(556e80, fn556e80);
