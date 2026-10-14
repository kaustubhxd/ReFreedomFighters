// batch885.cpp - area 50 (residue-09 file row): 0x4395d0 [42 instr, no stack args, void; ZInputActions::HandleDebugOptions (name
// from the map)]. The entry loads ECX from the engine global, so the entry ECX is never read. The call through vt+0x184 at
// 0x439663 runs with ECX left over from the vt+0xf0 call at 0x439656 (the exe does not reload ECX). ECX from previous call modelled as
// input: the port captures ECX after the vt+0xf0 call and passes it to vt+0x184 as an explicit this (inline asm). The callee is
// cdecl at the stack level (the exe pops the four words itself with add esp,0x10); only ECX carries the leftover value.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))
#define F32(p, o) (*(float *)((u8 *)(p) + (o)))

// vt+0xf0 call: THISCALL on obj with no arguments; returns eax, and leaves the register ECX (after the call) in *ecx_io.
static inline u32 call_f0(void *&ecx_io, void *fn) {
  u32 eax, t1;
  asm volatile("call *%[f]" : "=&a"(eax), "=&d"(t1), "+c"(ecx_io) : [f] "r"(fn) : "memory", "cc");
  return eax;
}

// vt+0x184 call with an explicit this in ECX and four cdecl stack words (args[0] is the lowest).
static inline void call_184(void *ecx_val, void *fn, const u32 *args) {
  u32 t0, t1;
  asm volatile(
      "pushl 12(%[p])\n\t"
      "pushl 8(%[p])\n\t"
      "pushl 4(%[p])\n\t"
      "pushl 0(%[p])\n\t"
      "call *%[f]\n\t"
      "addl $16, %%esp"
      : "+c"(ecx_val), "=&a"(t0), "=&d"(t1)
      : [p] "r"(args), [f] "r"(fn)
      : "memory", "cc");
}

// 0x4395d0 (ZInputActions::HandleDebugOptions).
static void THISCALL HandleDebugOptions(void) {
  u8 *g = G(u8 *, 0x70039c);
  if (1.0f > F32(g, 0x9c7)) return;
  u8 *O = (u8 *)FP(g, 0x1907);
  bool flag = vcall<bool>(O, 0x38, (void *)0x67a6c0u, 0u);
  if (flag) {
    u8 *g2 = G(u8 *, 0x70039c);
    U8(g2, 0x1b3e) = (U8(g2, 0x1b3e) == 0) ? 1 : 0;
  }
  u8 *g3 = G(u8 *, 0x70039c);
  const char *str = (U8(g3, 0x1b3e) != 0) ? (const char *)0x67a88c : (const char *)0x67a8a0;
  u8 *res = (u8 *)vcall<void *>(g3, 0x190);
  u8 *g4 = G(u8 *, 0x70039c);
  void *o2 = FP(g4, 0x190f);
  void *fn_f0 = *(void **)(*(u8 **)o2 + 0xf0);
  void *ecx_after = o2;
  u32 r = call_f0(ecx_after, fn_f0);            // ECX after this call is the leftover (modelled input)
  void *fn_184 = *(void **)(*(u8 **)res + 0x184);
  u32 args[4] = {(u32)res, 0u, r - 3u, (u32)str};
  call_184(ecx_after, fn_184, args);
}
PCREG(4395d0, HandleDebugOptions);
