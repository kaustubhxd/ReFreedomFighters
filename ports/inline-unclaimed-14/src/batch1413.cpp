// batch1413.cpp - unclaimed-14 batch 13 (slice 13, heavy list): ZFFActor::CloseCombatAttack(unsigned int, unsigned int).
#include "ff.h"

// Original code run as is (pure helpers that touch only the global chain): vector math with x87 (43e920), the 0x5eb770
// helper that calls global+0x9b's vtable +0x58, and 0x5eb7a0 (switch on its argument, hook at 0x7003b0).
extern "C" void FASTCALL ext_43e920(u8 *ecx, u8 *edx, u8 *stackarg);   // ecx = out, edx = b, 1 stack argument (a), ret 4
extern "C" void THISCALL ext_5eb770(u8 *self, u32 a);                    // ret 4
extern "C" void THISCALL ext_5eb7a0(u8 *self, u32 b);                    // ret 4

// 0x59e7d0, ZFFActor::CloseCombatAttack(unsigned int, unsigned int) (high): thiscall, two stack arguments (ret 8). Returns
// al = 0 on the early exits (eax keeps the caller's high bits; the spec compares al only).
//  T = (global+0x9b)->vtable[+0x58](a). If T is null: M = global700390->vtable[+0x20](0x6d7, 0x6ae6a0),
//      Y = this->vtable[+0x20](), then M->vtable[+0x2c] with this = [Y+4], args (M, 0x6aeaf8, [Y+4] or 0x67c8e8). return 0.
//  Argument order: each call pushes its constants in the reverse order of the C++ parameters (the last pushed is argument 1).
//  Else: exits 0 unless [this+0x7ae] and [this+0x7b2] are nonzero; calls this->vtable[+0x80](&p40, &p1c) and
//  T->vtable[+0x84](&p10); 43e920(&p50, &p1c, &p10) makes p50 = p1c - p10; exits 0 when |p50|^2 >= 28900 or the dot
//  product p40.p50 is below 0.5. Exits 0 when this->vtable[+0x3f0]() is nonzero. The counter at [this+0x7aa]: if it is
//  <= 2 it is incremented; otherwise it is reset, the global's vtable[+0x1c0](0x6f1, 0x6ae6a0) is called, and when 0.8 >
//  the float popped from the x87 stack (fstp) this->vtable[+0x6e8](0, 0, 0x12). Then Z = this->vtable[+0x3ec](0x11),
//  5eb770(Z, a), 5eb7a0(Z, b), and the result is this->vtable[+0x3d8](Z).
static u32 THISCALL closeCombatAttack(u8 *self, u32 a, u32 b) {
  u8 *g = G(u8 *, 0x70039c);
  u8 *bobj = *(u8 **)(g + 0x9b);
  typedef u32(THISCALL * f58_t)(u8 *, u32);
  u8 *t = (u8 *)(*(f58_t *)(*(u32 *)bobj + 0x58))(bobj, a);
  if (t == 0) {
    typedef u32(THISCALL * f20a_t)(u8 *, u32, u32);
    u8 *l = G(u8 *, 0x700390);
    u8 *m = (u8 *)(*(f20a_t *)(*(u32 *)l + 0x20))(l, 0x6ae6a0, 0x6d7);   // pushed 0x6d7 then 0x6ae6a0: 0x6ae6a0 is arg 1
    typedef u32(THISCALL * f20_t)(u8 *);
    u8 *y = (u8 *)(*(f20_t *)(*(u32 *)self + 0x20))(self);
    u32 ecx = *(u32 *)(y + 4);
    u32 edx = 0x67c8e8;
    if (ecx != 0)
      edx = ecx;
    // M->vtable[+0x2c] with this = [Y+4] and three stack arguments (m, 0x6aeaf8, edx), pushed in that PC order. The PC
    // pops them itself (`add esp, 0xc` after the call), so this is a caller-cleanup call, written as inline asm.
    u32 fn = *(u32 *)(*(u32 *)m + 0x2c);
    asm volatile("pushl %[e]\n\tpushl %[k]\n\tpushl %[mm]\n\tcall *%[fn]\n\taddl $12, %%esp"
                 :
                 : "c"(ecx), [e] "r"(edx), [k] "i"(0x6aeaf8), [mm] "r"(m), [fn] "S"(fn)   // esi: preserved by the callee
                 : "eax", "edx", "memory", "cc");
    return 0;
  }
  if (*(u32 *)(self + 0x7ae) == 0 || *(u32 *)(self + 0x7b2) == 0)
    return 0;
  // frame: fr[0x50 + off] is the PC's [ebp+off]
  u8 fr[0x50] = {};
  u8 *p50 = fr + 0x00;   // [ebp-0x50]: vector 1 (out of 43e920)
  u8 *p40 = fr + 0x10;   // [ebp-0x40]: vector 2
  u8 *p1c = fr + 0x34;   // [ebp-0x1c]
  u8 *p10 = fr + 0x40;   // [ebp-0x10]
  *(u32 *)p1c = 0;
  *(u32 *)(fr + 0x38) = 0;   // [ebp-0x18]
  *(u32 *)(fr + 0x3c) = 0;   // [ebp-0x14]
  *(u32 *)(fr + 0x40) = 0;   // [ebp-0x10]
  *(u32 *)(fr + 0x44) = 0;   // [ebp-0xc]
  *(u32 *)(fr + 0x48) = 0;   // [ebp-0x8]
  typedef void(THISCALL * f80_t)(u8 *, u8 *, u8 *);
  (*(f80_t *)(*(u32 *)self + 0x80))(self, p40, p1c);
  typedef void(THISCALL * f84_t)(u8 *, u8 *);
  (*(f84_t *)(*(u32 *)t + 0x84))(t, p10);
  ext_43e920(p50, p1c, p10);
  float x = *(float *)p50, y = *(float *)(p50 + 4), z = *(float *)(p50 + 8);
  float len2 = (x * x + y * y) + z * z;
  if (len2 >= G(float, 0x6aef84))
    return 0;
  float v0 = *(float *)p40, v1 = *(float *)(p40 + 4), v2 = *(float *)(p40 + 8);
  float dot = (v0 * x + v1 * y) + v2 * z;
  if (G(float, 0x67a6ac) > dot)
    return 0;
  typedef u32(THISCALL * f0_t)(u8 *);
  if ((*(f0_t *)(*(u32 *)self + 0x3f0))(self) != 0)
    return 0;
  u32 cnt = *(u32 *)(self + 0x7aa);
  if (cnt <= 2) {
    *(u32 *)(self + 0x7aa) = cnt + 1;
  } else {
    *(u32 *)(self + 0x7aa) = 0;
    typedef u32(THISCALL * f2_t)(u8 *, u32, u32);
    (*(f2_t *)(*(u32 *)g + 0x1c0))(g, 0x6ae6a0, 0x6f1);   // pushed 0x6f1 then 0x6ae6a0: 0x6ae6a0 is arg 1
    float tv;
    asm volatile("fstps %0" : "=m"(tv));   // pops st0, as the PC's `fstp dword [ebp-0x44]`
    if (G(float, 0x67c1a8) > tv) {
      typedef void(THISCALL * f6e8_t)(u8 *, u32, u32, u32);
      (*(f6e8_t *)(*(u32 *)self + 0x6e8))(self, 0x12, 0, 0);   // pushed 0, 0, 0x12: 0x12 is arg 1
    }
  }
  typedef u8 *(THISCALL * f3ec_t)(u8 *, u32);
  u8 *zobj = (*(f3ec_t *)(*(u32 *)self + 0x3ec))(self, 0x11);
  ext_5eb770(zobj, a);
  ext_5eb7a0(zobj, b);
  typedef u32(THISCALL * f3d8_t)(u8 *, u8 *);
  return (*(f3d8_t *)(*(u32 *)self + 0x3d8))(self, zobj);
}
PCREG(59e7d0, closeCombatAttack);
