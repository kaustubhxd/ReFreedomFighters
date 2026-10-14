// batch34047.cpp - cascade tier E, batch 34047: 0x4f2240 (notify matching children of a node list), 0x529d00 (read a record from a stream), 0x546040 (write an array of 0x34-byte records
// to a stream).
#include "ff.h"

extern "C" bool THISCALL ext_4db9a0(void *node, u32 mask);   // thiscall ret 4, bool in al
extern "C" void THISCALL ext_529d70(void *self, void *s);    // thiscall ret 4

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x4f2240, stdcall(a, o) ret 8 (ECX unused): nothing when o is null or o->slot0x1e0(0x100033) is false. Otherwise walks the node chain starting at [o+8] (next through o->slot0x50(&node), stack pointer): for
// every node accepted by 0x4db9a0(node, 0x20002c) whose child [node+0x54] has byte +0x21 == 8, calls that child's slot 0x250(low byte of a).
static void STDCALL fn4f2240(u32 a, u8 *o) {
  if (!o) return;
  if (!vcall<bool>(o, 0x1e0, 0x100033u)) return;
  u32 node = *(u32 *)(o + 8);
  if (!node) return;
  u8 bl = (u8)a;
  do {
    if (ext_4db9a0((void *)node, 0x20002c)) {
      u8 *ch = *(u8 **)(node + 0x54);
      if (ch[0x21] == 8) vcall<void>(ch, 0x250, (u32)bl);
    }
    vcall<void>(o, 0x50, (u32)&node);
  } while (node);
}
PCREG(4f2240, fn4f2240);

// 0x529d00, thiscall(s) ret 4, returns true: s slot 0x6c(this+4); s slot 0x40(&id) (stack pointer); [this+0x18] = engine table slot 0x58(id); s slot 0x6c(this+0x1c); s slot 0x50(this+0x28),
// s slot 0x50(this+0x2c); 0x529d70(this+0x30, s).
static bool THISCALL fn529d00(u8 *self, u8 *s) {
  vcall<void>(s, 0x6c, (u32)(self + 4));
  u32 id;
  vcall<void>(s, 0x40, (u32)&id);
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0x18) = vcall<u32>(tbl, 0x58, id);
  vcall<void>(s, 0x6c, (u32)(self + 0x1c));
  vcall<void>(s, 0x50, (u32)(self + 0x28));
  vcall<void>(s, 0x50, (u32)(self + 0x2c));
  ext_529d70(self + 0x30, s);
  return true;
}
PCREG(529d00, fn529d00);

// 0x546040, thiscall(s) ret 4, returns true: for each of the [this+0x28] (signed) records of 0x34 bytes starting at the unaligned pointer [this+0xf]: s slot 0x6c(rec+0xc), s slot 0x6c(rec),
// s slot 0x6c(rec+0x18), s slot 0x6c(rec+0x24).
static bool THISCALL fn546040(u8 *self, u8 *s) {
  s32 n = *(s32 *)(self + 0x28);
  u8 *rec = (u8 *)rd32u(self + 0xf);
  s32 i = 0;
  if (n > 0) {
    do {
      vcall<void>(s, 0x6c, (u32)(rec + 0xc));
      vcall<void>(s, 0x6c, (u32)rec);
      vcall<void>(s, 0x6c, (u32)(rec + 0x18));
      vcall<void>(s, 0x6c, (u32)(rec + 0x24));
      rec += 0x34;
      i++;
    } while (i < n);
  }
  return true;
}
PCREG(546040, fn546040);
