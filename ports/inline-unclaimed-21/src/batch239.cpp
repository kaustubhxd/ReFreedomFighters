// batch239.cpp - gap band 0x641000-0x661000 (parked item, now ported). 0x645ec0 (name GUESS): thiscall(X, B) (ret 8).
// SEH frame and stack cookie not reproduced (the fs:[0] save and the cookie check are not observable here).
// id = rm->child->vt[0x50](X), child = [[0x70039c] + 0x9b]. n = [this+0x69]; entries of 56 bytes at this+0x6d.
// If an entry i has [i+4] == B and [i] == id: found. Then o = [rm+0x190f]; r = o->vt[0x20](X); 0x63d7d0(r); n = n - 1,
// [this+0x69] = n; the last entry (n) is copied over entry i (56 bytes).
// Not found: if X != 0: t = 0x4da2f0(X, &local, 1); esi = 0x4cc1d0(t); bl = 1. Else esi = 0x6c2a28.
// Then D = [0x700390]: p = D->vt[0x20](D, 0x6c2904, 0x30a) (callee pops 8); P->vt[0x2c](P, 0x6c2a30, esi) (caller pops 12);
// if bl: 0x4cbec0(&local).
#include "ff.h"

extern "C" u8 *THISCALL ext_4da2f0(u8 *self, u8 *p1, u32 p2);   // original, thiscall, two stack words, ret 8 (stubbed)
extern "C" u32 THISCALL ext_4cc1d0(u8 *self);                    // original, thiscall, no stack words (stubbed)
extern "C" void THISCALL ext_63d7d0(u8 *self);                   // original, thiscall, no stack words (stubbed)
extern "C" void THISCALL ext_4cbec0(u8 *self);                   // original dtor of a stack block (stubbed; no-op)

typedef u32(THISCALL *SlotOne)(u8 *, u32);                  // one stack word, eax result
typedef u32(THISCALL *SlotTwo)(u8 *, u32, u32);             // vtable 0x20 of the error object: two stack words, callee pops
typedef u32(THISCALL *SlotNone)(u8 *);

static u32 vslot20(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

// The exe's call site loads ECX from [P] (the vtable value), then calls [ecx + 0x2c]: ECX is the vtable, not P.
// Three stack words, the CALLER pops them (add esp, 12 after the call).
struct VCall3 { u32 a, b, c, ecx, target; };
static void vcall_callerpops3(u32 ecxv, u32 a, u32 b, u32 c) {
  VCall3 v = {a, b, c, ecxv, *(u32 *)(ecxv + 0x2c)};
  __asm__ volatile("pushl 8(%0)\n\tpushl 4(%0)\n\tpushl (%0)\n\tmovl 12(%0), %%ecx\n\tcalll *16(%0)\n\taddl $12, %%esp"
                   : : "r"(&v) : "eax", "ecx", "edx", "memory", "cc");
}

static void THISCALL search_645ec0(u8 *self, u32 X, u32 B) {
  u8 *rm = G(u8 *, 0x70039c);
  u8 *child = *(u8 **)(rm + 0x9b);
  u32 id = ((SlotOne)vslot20(child, 0x50))(child, X);
  u32 esi = 0;
  bool bl = false;
  u32 n = *(u32 *)(self + 0x69);
  bool found = false;
  u8 *ent = self + 0x6d;
  for (u32 i = 0; i != n; ++i, ent += 56) {
    if (*(u32 *)(ent + 4) == B && *(u32 *)ent == id) {
      esi = i;
      found = true;
      break;
    }
  }
  if (found) {
    u8 *o = *(u8 **)(rm + 0x190f);
    u8 *r = (u8 *)(u32)((SlotOne)vslot20(o, 0x20))(o, X);
    ext_63d7d0(r);
    u32 last = --*(u32 *)(self + 0x69);
    u8 *base = self + 0x69 + 4;
    for (u32 k = 0; k < 56; ++k) base[esi * 56 + k] = base[last * 56 + k];
    return;
  }
  if (X != 0) {
    u8 local90[0x20];
    u8 *t = ext_4da2f0((u8 *)X, local90, 1);
    bl = true;
    esi = ext_4cc1d0(t);
  } else {
    esi = 0x6c2a28u;
  }
  u8 *D = G(u8 *, 0x700390);
  u8 *P = (u8 *)(u32)((SlotTwo)vslot20(D, 0x20))(D, 0x6c2904u, 0x30au);
  vcall_callerpops3(*(u32 *)P, (u32)P, 0x6c2a30u, esi);
  if (bl) {
    u8 local[0x20];
    ext_4cbec0(local);
  }
}
PCREG(645ec0, search_645ec0);
