// batch37087.cpp - cascade s6 batch 37087: 0x4fc500.
#include "ff.h"

extern "C" void THISCALL ext_4fd800(u8 *self, u32 id);   // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define W16(p, o) (*(u16 *)((u8 *)(p) + (o)))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }
static inline u8 *byId(u32 id) { return (u8 *)vcall<u32>(tabObj(), 0x58, id); }

// 0x4fc500, thiscall(), returns an object or 0: picks the id this entity should be bound to (from the embedded selector at +0x98 when it has one, else from the first id in the
// list at [+0x84]+0x48 that resolves, dropping unresolved ids with 0x4fd800; with no list the object of +0x78 is positioned first) and rebinds: the previously bound object
// (+0x74) is told to detach (slot 0x128), the new one is attached through the owner at +0x44 (slot 0x12c) and +0x74 is updated. Returns the resolved object when its type data
// (+0xc) has flag 0x400000 set at +0x23, otherwise 0.
static u8 *THISCALL fn4fc500(u8 *self) {
  u32 esi = 0;
  u8 *sub = self + 0x98;
  if (vcall<u32>(sub, 0x14)) {
    esi = vcall<u32>(sub, 0x30, 0u);
  } else {
    if (!D32(self, 0x84)) {
      u8 *o = byId(D32(self, 0x78));
      u32 h = vcall<u32>(tabObj(), 0x4c, D32(self, 0x44), 0u);
      vcall<void>(o, 0x128, (u32)W16(self, 0x80), h);
      if (!D32(self, 0x84)) return 0;
    }
    u8 *l = *(u8 **)(*(u8 **)(self + 0x84) + 0x48);
    if (l) {
      esi = D32(l, 0);
      while (!byId(esi)) {
        ext_4fd800(*(u8 **)(self + 0x84), esi);
        u8 *n = *(u8 **)(*(u8 **)(self + 0x84) + 0x48);
        if (!n) return 0;
        esi = D32(n, 0);
      }
    }
  }
  u8 *edi = byId(esi);
  u32 edx = D32(self, 0x74);
  if (esi == edx) {
    D32(self, 0x144) = 0;
  } else {
    if (edx) {
      u8 *o = byId(edx);
      if (o) vcall<void>(o, 0x128, (u32)W16(self, 0x64), 0u, 0u);
    }
    if (edi) {
      vcall<void>(*(void **)(self + 0x44), 0x12c, esi, (u32)W16(self, 0x62), (u32)self);
      D32(self, 0x74) = esi;
    } else {
      esi = 0;
      D32(self, 0x74) = 0;
    }
  }
  if (edi && (D32(*(u8 **)(edi + 0xc), 0x23) & 0x400000)) return edi;
  return 0;
}
PCREG(4fc500, fn4fc500);
