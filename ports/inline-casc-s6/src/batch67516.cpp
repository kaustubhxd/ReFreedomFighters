// batch67516.cpp - cascade s6 batch 67516: 0x502670.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u32 self, u32 idx);   // ret 4
typedef u32 (*hook_t)();
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd3_t)(void *, u32, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// Reads a script value: type 3 (int) is the dword itself, type 4 (object) is that object's slot 0x34 result, anything else logs error 0x111, calls the assert hook and gives 0.
static u32 scriptValue(u8 *n) {
  u8 t = n[4];
  if (t == 3) return D32(n, 0);
  if (t == 4) return vcall<u32>(*(void **)n, 0x34);
  u8 *lg = *(u8 **)0x700390;
  void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x69c8e0, 0x111);
  (*(cd3_t **)L)[0x2c / 4](L, 0x69c6b0, 0x69c9b0);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return 0;
}

// 0x502670, thiscall(a) ret 4: script op forwarding a record. Arguments 2 and 3 are raw dwords, argument 4 and argument 1 are script values (int or object); argument 1 is
// looked up as a registered name id (table slot 0x114, 16-bit) and slot 0x12c of the object at +0xc receives (argument 0's dword, that id, &{arg2, arg3, arg4 value}).
static void THISCALL fn502670(u8 *self, u8 *a) {
  u32 args = *(u32 *)(a + 4);
  u32 trip[3];
  trip[0] = D32(ext_5003d0(args, 2), 0);
  trip[1] = D32(ext_5003d0(args, 3), 0);
  trip[2] = scriptValue(ext_5003d0(args, 4));
  u32 v1 = scriptValue(ext_5003d0(args, 1));
  u32 id = (u16)vcall<u32>(*(void **)(*(u8 **)0x70039c + 0x9b), 0x114, v1, 0u, 0x69ca10u, 0x284u);
  u32 x = D32(ext_5003d0(args, 0), 0);
  vcall<void>(*(void **)(self + 0xc), 0x12c, x, id, (u32)trip);
}
PCREG(502670, fn502670);
