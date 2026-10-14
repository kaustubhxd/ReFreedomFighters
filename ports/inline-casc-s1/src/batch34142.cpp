// batch34142.cpp - cascade tier E, batch 34142: 0x5f5490 (copy records into a vector), 0x5f9010 (push a ref-counted record).
#include "ff.h"

extern "C" void ext_42ab62(u32 a);   // cdecl
typedef void (*hook_t)();

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x5f5490, thiscall(src, count) ret 8: for count times (none when zero): when [this+8] >= [this+4] the error print ext_42ab62(0x6b89b4) and the assert hook [0x7003b0] (int3 when null) run and carry on;
// slot = [this] + 8 * [this+8]; [this+8]++; when src != slot: a kind-4 old record at slot has [slot]->slot0x28() called first; then [slot] = (src kind 4 ? [src]->slot0x24() : [src]) and the kind byte is copied.
static void THISCALL fn5f5490(u8 *self, u8 *src, u32 count) {
  if (!count) return;
  do {
    if (*(u32 *)(self + 8) >= *(u32 *)(self + 4)) {
      ext_42ab62(0x6b89b4);
      hook_t h = G(hook_t, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
    }
    u32 size = *(u32 *)(self + 8);
    u8 *slot = *(u8 **)self + size * 8;
    *(u32 *)(self + 8) = size + 1;
    if (src != slot) {
      if (slot[4] == 4) vcall<void>(*(u8 **)slot, 0x28);
      u32 v;
      if (src[4] == 4) v = vcall<u32>(*(u8 **)src, 0x24);
      else v = *(u32 *)src;
      *(u32 *)slot = v;
      slot[4] = src[4];
    }
  } while (--count);
}
PCREG(5f5490, fn5f5490);

// 0x5f9010, thiscall plain: s = (embedded object at this+0xaca)->slot0(0x67a14c, 0); s->slot0x30(unaligned [this+0x1a]); the vector {[+0x34] data, [+0x38] cap, [+0x3c] size}: when size >= cap the error print and the assert hook run and carry on;
// slot = data + 8 * size; size++; kind = slot[4]: 0 or 4 -> (4: [slot]->slot0x28() first) [slot] = s->slot0x24(), slot[4] = 4; any other kind is left alone. Finally returns s->slot0x28() (tail call).
static u32 THISCALL fn5f9010(u8 *self) {
  u8 *emb = self + 0xaca;
  u8 *s = vcall<u8 *>(emb, 0x0, 0x67a14cu, 0u);
  vcall<void>(s, 0x30, rd32(self + 0x1a));
  if (*(u32 *)(self + 0x3c) >= *(u32 *)(self + 0x38)) {
    ext_42ab62(0x6b89b4);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u32 size = *(u32 *)(self + 0x3c);
  u8 *slot = *(u8 **)(self + 0x34) + size * 8;
  *(u32 *)(self + 0x3c) = size + 1;
  u8 k = slot[4];
  if (k == 0 || k == 4) {
    if (k == 4) vcall<void>(*(u8 **)slot, 0x28);
    *(u32 *)slot = vcall<u32>(s, 0x24);
    slot[4] = 4;
  }
  return vcall<u32>(s, 0x28);
}
PCREG(5f9010, fn5f9010);
