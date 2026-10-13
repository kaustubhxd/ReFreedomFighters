// batch4120.cpp - unclaimed-41 batch 20 (slice 13): 0x46ffd0 ZItem::PlaySound(unsigned int) (vtable; the /GS cookie check is not reproduced).
#include "ff.h"

extern "C" void THISCALL ext_43ec00(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);   // five stack args, callee pops (stub, GUESS)

typedef u32(THISCALL * r0_t)(u8 *);
typedef u32(THISCALL * r1_t)(u8 *, u32);
typedef void(THISCALL * v2_t)(u8 *, u32, u32);

// 0x46ffd0: thiscall, one stack argument (the sound id, ret 4). sound == 0 returns at once (eax = 0).
//   t = this.vt[+0x2f4]()                       site A: no stack argument
//   b = t ? t2.vt[+0x20]() with t2 = this.vt[+0x2f4]() (site B, no stack argument) : this
//   this.vt[+0x2c8](&loc34, &loc10); b.vt[+0x94](&loc34, &loc10)
//   r = this.vt[+0x2f4](0)                      site C: pushes one zero argument and does not pop it (the PC leaves the dword on the stack)
//   s = rm.+0x9b.vt[+0x4c](r)
//   ext_43ec00(b, &loc34, &loc10, sound, 0, s)  five stack arguments, ecx = b
static void THISCALL fn46ffd0(u8 *self, u32 sound) {
  if (sound == 0)
    return;
  u8 *vt = *(u8 **)self;
  u32 t = ((r0_t)(*(u32 *)(vt + 0x2f4)))(self);                    // site A
  u8 *b;
  if (t != 0) {
    u8 *p = (u8 *)((r0_t)(*(u32 *)(*(u8 **)self + 0x2f4)))(self);  // site B
    b = (u8 *)((r0_t)(*(u32 *)(*(u8 **)p + 0x20)))(p);
  } else {
    b = self;
  }

  u32 loc34[3];
  u32 loc10[3];
  ((v2_t)(*(u32 *)(*(u8 **)self + 0x2c8)))(self, (u32)loc34, (u32)loc10);
  ((v2_t)(*(u32 *)(*(u8 **)b + 0x94)))(b, (u32)loc34, (u32)loc10);

  // site C: one pushed argument (0), not popped by the caller
  u32 fnc = *(u32 *)(*(u8 **)self + 0x2f4);
  u32 r;
  u8 *tmp = self;
  asm volatile("movl %[fn], %%edx\n\tpushl $0\n\tcall *%%edx" : "=a"(r), "+c"(tmp) : [fn] "m"(fnc) : "edx", "memory", "cc");

  u8 *rm = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(rm + 0x9b);
  u32 s = ((r1_t)(*(u32 *)(*(u8 **)o + 0x4c)))(o, r);
  ext_43ec00(b, (u32)loc34, (u32)loc10, sound, 0u, s);
}
PCREG(46ffd0, fn46ffd0);
