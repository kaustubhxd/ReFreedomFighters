// u69_09.cpp - area 69, group 9 (unclaimed-69 thread).
#include "ff.h"

static inline u8 *sys() { return G(u8 *, 0x70039c); }

// 0x4f14d0, ZCHAROBJ::SetTextId(const char* id, const char* text) (GC map high). thiscall, two stack args (ret 8). When the
// text is non-null and not empty, the engine's actions object (engine+0xae4) resolves (id, text) through slot 0 and its result
// replaces the text. The text is then passed to slot 0x284 of this.
static void THISCALL charObjSetTextId(u8 *self, const char *id, const char *text) {
  const char *t = text;
  if (text && text[0] != '\0') {
    u8 *engine = *(u8 **)(sys() + 0x9b);
    void *acts = *(void **)(engine + 0xae4);
    t = vcall<const char *>(acts, 0, id, text);
  }
  vcall<void>(self, 0x284, t);
}
PCREG(4f14d0, charObjSetTextId);
