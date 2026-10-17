// batch506.cpp - unclaimed-05 batch 6 (claim 6; this is the molotov first item of the slice-4 list).
// Names from the GC name map (naming only, never committed); GUESS where marked.
#include "ff.h"

// Original callees (thiscall, one stack argument, ret 4).
extern "C" void THISCALL ext_4dbe30(u8 *self, u32 one);
extern "C" void THISCALL ext_4dc440(u8 *self, u32 one);

// Virtual slots used by the body (thiscall; the callee pops its own arguments, as in the original).
typedef u8 *(THISCALL *VLookup)(u8 *self, const char *name, u32 flag);       // slot +0x25c: (name, 0)
typedef u32(THISCALL *VGet4c)(u8 *self, u8 *arg);                             // slot +0x4c: (esi)
typedef void(THISCALL *V288)(u8 *self, u8 *a, u32 b, u32 c);                 // slot +0x288: (esi, 0, 1)
typedef void(THISCALL *V1arg)(u8 *self, u32 a);                               // slot +0x224 (1), +0x24 (0)
typedef u8 *(THISCALL *VLog20)(u8 *self, const char *file, u32 line);        // slot +0x20 of the log object

// Assertion-call helper: the original calls [vt+0x2c] with ecx = vt and two stack words, caller pops 8.
// All operands are registers so that the pushes do not shift an esp-relative operand.
static void assertCall(u8 *vt_as_ecx, u32 fn, u8 *a1, u32 a2) {
  asm volatile("pushl %[a2]\n\tpushl %[a1]\n\tcalll *%[f]\n\taddl $8, %%esp"
               : "+c"(vt_as_ecx)
               : [a2] "r"(a2), [a1] "r"(a1), [f] "r"(fn)
               : "eax", "edx", "memory", "cc");
}

// Log helper: the object at 0x700390 gives the assert object (slot +0x20 with (file, line)), then the assert object's
// own vtable slot +0x2c gets the second call.
static void assertLog(const char *file, u32 line, u32 a2) {
  u8 *log = G(u8 *, 0x700390);
  u8 *p = ((VLog20)*(u32 *)(*(u8 **)log + 0x20))(log, file, line);
  u8 *pvt = *(u8 **)p;
  assertCall(pvt, *(u32 *)(pvt + 0x2c), p, a2);
}

// 0x584480, CExplodeMolotov::Init() (high): looks up two named objects through this+0x44 (slot +0x25c). The first
// object gets the engine sequence (0x4c, 0x288, 0x224, 0x4dbe30 and 0x4dc440 on its +8 object, 0x24) and is stored
// in this+0x362 (from 0x4c). A null lookup logs an assertion instead. Ends with the second lookup (assert on null).
static void THISCALL molotovInit(u8 *self) {
  u8 *lk = *(u8 **)(self + 0x44);
  u8 *o = ((VLookup)*(u32 *)(*(u8 **)lk + 0x25c))(lk, (const char *)0x688bd0, 0);
  if (o == 0) {
    assertLog((const char *)0x6ab6d4, 0x2a1, 0x6ab75c);
  } else {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *en = *(u8 **)(eng + 0x9b);
    *(u32 *)(self + 0x362) = ((VGet4c)*(u32 *)(*(u8 **)en + 0x4c))(en, o);

    eng = G(u8 *, 0x70039c);
    en = *(u8 **)(eng + 0x9b);
    u8 *ex = *(u8 **)(en + 0xadc);
    ((V288)*(u32 *)(*(u8 **)ex + 0x288))(ex, o, 0, 1);

    ((V1arg)*(u32 *)(*(u8 **)o + 0x224))(o, 1);
    ext_4dbe30(*(u8 **)(o + 8), 1);
    ext_4dc440(*(u8 **)(o + 8), 1);
    ((V1arg)*(u32 *)(*(u8 **)o + 0x24))(o, 0);
  }

  lk = *(u8 **)(self + 0x44);
  o = ((VLookup)*(u32 *)(*(u8 **)lk + 0x25c))(lk, (const char *)0x690aec, 0);
  if (o == 0) assertLog((const char *)0x6ab6d4, 0x2ad, 0x6ab79c);
}
PCREG(584480, molotovInit);
