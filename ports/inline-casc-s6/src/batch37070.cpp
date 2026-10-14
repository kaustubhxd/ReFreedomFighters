// batch37070.cpp - cascade s6 batch 37070: 0x552290.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u32 self, u32 idx);                       // value node by index, ret 4
extern "C" u8 *THISCALL ext_5002f0(u8 *node, u32 v);                         // stores an int value into a node, ret 4
extern "C" u32 THISCALL ext_5857f0(u32 self, u32 a, u32 b, u32 c, u32 flag); // ret 0x10
typedef u32 (*hook_t)();
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd3_t)(void *, u32, u32);

static void logfail(u32 line, u32 msg) {
  u8 *lg = *(u8 **)0x700390;
  void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x69c8e0, line);
  (*(cd3_t **)L)[0x2c / 4](L, 0x69c6b0, msg);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

static inline u32 world() { return *(u32 *)(*(u8 **)0x7003b8 + 0x2c1d); }

// 0x552290, stdcall(a) ret 4: a+4 / a+8 are two argument stacks (nodes of type 0 or 1 hold a value dword at +0 and a type byte at +4). Without the object at world+0x2c1d it pushes
// the int 0 on the result stack (a+8). Otherwise it reads nodes 3, 2, 1, 0 of the argument stack, checks that nodes 2, 1 and 0 have type 0 or 1 (logging error 0x104 if not),
// calls 0x5857f0 on the object with (node0, node1, node2, node3 != 0) and pushes its result on the result stack.
static void STDCALL fn552290(u8 *a) {
  if (world() == 0) {
    ext_5002f0(ext_5003d0(*(u32 *)(a + 8), 0), 0);
    return;
  }
  u32 stk = *(u32 *)(a + 4);
  u8 *n3 = ext_5003d0(stk, 3);
  u8 *n2 = ext_5003d0(stk, 2);
  u32 v2 = *(u32 *)n2;
  if (n2[4] > 1) logfail(0x104, 0x69c938);
  u8 *n1 = ext_5003d0(stk, 1);
  if (n1[4] > 1) logfail(0x104, 0x69c938);
  u32 v1 = *(u32 *)n1;
  u8 *n0 = ext_5003d0(stk, 0);
  if (n0[4] > 1) logfail(0x104, 0x69c938);
  u32 r = ext_5857f0(world(), *(u32 *)n0, v1, v2, *(u32 *)n3 != 0);
  ext_5002f0(ext_5003d0(*(u32 *)(a + 8), 0), r);
}
PCREG(552290, fn552290);
