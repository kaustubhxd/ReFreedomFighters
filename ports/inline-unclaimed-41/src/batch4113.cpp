// batch4113.cpp - unclaimed-41 batch 13 (slice 13): 0x507f10 (name not in the map; GUESS).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *table, u32 index);   // array accessor, original code

// Record check (the PC's blocks at 0x507f2d, 0x507f84 and 0x507fdb): if the flag byte at rec+4 is neither 0 nor 2, call the
// logger: L = [0x700390]; o = L.vt[+0x20](0x69c8e0, 0x104); then (o's vtable)[+0x2c] with ecx = that vtable and three stack
// arguments (o, 0x69c6b0, 0x69c938), caller-cleaned; then the hook at 0x7003b0 (no arguments; the exe traps if it is zero).
static void errorPath(u8 *rec) {
  typedef u8 *(THISCALL * l20_t)(u8 *, u32, u32);
  u8 flag = rec[4];
  if (flag == 0 || flag == 2)
    return;
  u8 *l = G(u8 *, 0x700390);
  u8 *o = (*(l20_t *)(*(u32 *)l + 0x20))(l, 0x69c8e0u, 0x104u);   // the PC pushes 0x104 then 0x69c8e0: 0x69c8e0 is arg 1
  u8 *vt = *(u8 **)o;
  // vt[+0x2c] with ecx = vt and three stack arguments (o, 0x69c6b0, 0x69c938), pushed in the PC order; the PC pops them itself
  // (`add esp, 12`), so this is a caller-cleanup call, written as inline asm (the target is an input register).
  u32 fn2c = *(u32 *)(vt + 0x2c);   // vt is the vtable pointer itself: the slot is at vt + 0x2c
  u8 *tmp = vt;
  asm volatile("pushl $0x69c938\n\tpushl $0x69c6b0\n\tpushl %[ob]\n\tcall *%[fn]\n\taddl $12, %%esp"
               : "+c"(tmp)
               : [ob] "r"(o), [fn] "r"(fn2c)
               : "eax", "edx", "memory", "cc");
  void (*hook)(void) = (void (*)(void))G(u32, 0x7003b0);
  hook();
}

// 0x507f10 (GUESS name): thiscall, one stack argument x (ret 4). With s = [x+4]:
//   R2 = acc(s,2); check(R2); f2 = R2.f0.  R1 = acc(s,1); check(R1); f1 = R1.f0.  R0 = acc(s,0); check(R0); f0 = R0.f0.
//   vec = (f0, f1, f2); o = [this+0x18]; o.vt[+0x60c](&vec)   (one argument; the callee pops it)
static void THISCALL fn507f10(u8 *self, u8 *x) {
  u8 *s = *(u8 **)(x + 4);
  u8 *r2 = ext_5003d0(s, 2);
  errorPath(r2);
  float f2 = *(float *)r2;
  u8 *r1 = ext_5003d0(s, 1);
  errorPath(r1);
  float f1 = *(float *)r1;
  u8 *r0 = ext_5003d0(s, 0);
  errorPath(r0);
  float f0 = *(float *)r0;
  float vec[3] = {f0, f1, f2};
  u8 *o = *(u8 **)(self + 0x18);
  typedef void(THISCALL * v1_t)(u8 *, u32);
  (*(v1_t *)(*(u32 *)o + 0x60c))(o, (u32)vec);
}
PCREG(507f10, fn507f10);
