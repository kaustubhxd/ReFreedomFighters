// batch34059.cpp - cascade tier E, batch 34059: 0x4cec60 (log every id of an iterator), 0x4f2750 (two-step query with a packed argument block), 0x4fbab0 (notify an owner and append a list node).
#include "ff.h"

extern "C" u32 ext_41e290(u32 size);   // cdecl alloc

// 0x4cec60, thiscall, no args: nothing when this is null; it = {}; this->slot0x4c(&it); id = this->slot0x5c(&it); while it[0]: log through the object at 0x700390 (slot 0x20(0x695b7c, 0x5c2), then its slot
// 0x2c with (r, 0x695cec, id), caller-popped, ECX = r's vtable); id = this->slot0x5c(&it).
static void THISCALL fn4cec60(u8 *self) {
  u32 it[3];
  if (!self) return;
  vcall<void>(self, 0x4c, (u32)it);
  u32 id = vcall<u32>(self, 0x5c, (u32)it);
  if (it[0] == 0) return;
  do {
    u8 *lg = G(u8 *, 0x700390);
    u8 *r = vcall<u8 *>(lg, 0x20, 0x695b7cu, 0x5c2u);
    u32 vt = *(u32 *)r;
    u32 slot = ((u32 *)vt)[0x2c / 4];
    asm volatile("push %[id]\n\tpush $0x695cec\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [id] "r"(id), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
    id = vcall<u32>(self, 0x5c, (u32)it);
  } while (it[0] != 0);
}
PCREG(4cec60, fn4cec60);

// 0x4f2750, thiscall(a, b, c, d) ret 0x10, returns EAX: S = {slot-filled, a, b, c}; r1 = this->slot0x2e4(&S) (full EAX kept); when d is zero or a >= 0x10000 (signed) returns r1's EAX; otherwise 1 when
// the low byte of r1 is set, else 1 when this->slot0x2e0(&S, d) is true, else 0.
static u32 THISCALL fn4f2750(u8 *self, s32 a, u32 b, u32 c, u32 d) {
  u32 S[4];
  S[1] = (u32)a;
  S[2] = b;
  S[3] = c;
  u32 r1 = vcall<u32>(self, 0x2e4, (u32)S);
  if (d == 0 || a >= 0x10000) return r1;
  if ((u8)r1) return 1;
  if ((u8)vcall<u32>(self, 0x2e0, (u32)S, d)) return 1;
  return 0;
}
PCREG(4f2750, fn4f2750);

// 0x4fbab0, thiscall(k) ret 4, returns the new node or 0: [this+0x44]'s member [+0x18] gets slot 4(k); node = alloc(0x15) (0 -> return 0); node: byte +0x14 = 0, +0x10 = this, +0 = k, +4 = 0, +8 = [this+0x4c]
// (the old tail), +0xc = 0; the old tail's +0xc = node when it exists (and [this+0x4c] = node), otherwise [this+0x48] = [this+0x4c] = node.
static u8 *THISCALL fn4fbab0(u8 *self, u32 k) {
  u8 *owner = *(u8 **)(self + 0x44);
  vcall<void>(*(u8 **)(owner + 0x18), 4, k);
  u8 *node = (u8 *)ext_41e290(0x15);
  if (!node) return 0;
  node[0x14] = 0;
  *(u8 **)(node + 0x10) = self;
  *(u32 *)node = k;
  *(u32 *)(node + 4) = 0;
  u8 *tail = *(u8 **)(self + 0x4c);
  *(u8 **)(node + 8) = tail;
  *(u32 *)(node + 0xc) = 0;
  if (tail) {
    *(u8 **)(tail + 0xc) = node;
    *(u8 **)(self + 0x4c) = node;
    return node;
  }
  *(u8 **)(self + 0x48) = node;
  *(u8 **)(self + 0x4c) = node;
  return node;
}
PCREG(4fbab0, fn4fbab0);
