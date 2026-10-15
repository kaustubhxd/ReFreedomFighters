// batch67511.cpp - cascade s6 batch 67511: 0x4ac310.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline u8 *eng() { return *(u8 **)0x70039c; }
static inline void *tabObj() { return *(void **)(eng() + 0x9b); }

// 0x4ac310, thiscall(), plain ret: applies two registered names (strings at 0x690ad0 and 0x690adc, a null-terminated list) to this object. The engine is first notified (slot 0x14);
// for each name the table's slot-0x138 object resolves it to an id (slot 0x88 with an out id), the id to a table object which this object is told about (own slot 0x8c). Every
// key yielded by the embedded iterator at +0x11a (slot 0x4c starts, 0x5c yields with an out count) that resolves to an object answering 0x1007d8 gets slot 0x324 (0x3e7). A missing id or
// object ends everything early; otherwise, when the engine's byte +0x9b7 was set on entry, the engine is notified again at the end (slot 0x10).
static void THISCALL fn4ac310(u8 *self) {
  u8 saved = eng()[0x9b7];
  vcall<void>(eng(), 0x14);
  const u32 names[3] = {0x690ad0, 0x690adc, 0};
  for (int i = 0; names[i]; i++) {
    void *L = (void *)vcall<u32>(tabObj(), 0x138);
    u32 id = 0;
    vcall<void>(L, 0x88, names[i], (u32)&id);
    if (!id) return;
    u8 *obj = (u8 *)vcall<u32>(tabObj(), 0x58, id);
    if (!obj) return;
    vcall<void>(self, 0x8c, (u32)obj);
    u8 *it = self + 0x11a;
    u32 cnt;
    vcall<void>(it, 0x4c, (u32)&cnt);
    u32 key = vcall<u32>(it, 0x5c, (u32)&cnt);
    if (cnt) {
      do {
        u8 *o = (u8 *)vcall<u32>(tabObj(), 0x58, key);
        if (o && (u8)vcall<u32>(o, 0x1e0, 0x1007d8u)) vcall<void>(o, 0x324, 0x3e7u);
        key = vcall<u32>(it, 0x5c, (u32)&cnt);
      } while (cnt);
    }
  }
  if (saved) vcall<void>(eng(), 0x10);
}
PCREG(4ac310, fn4ac310);
