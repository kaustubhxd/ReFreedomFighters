// batch35028.cpp - cascade s5 batch 35028: 0x656820 (GUESS find a node in a chain by name).
#include "ff.h"

extern "C" u32 FASTCALL ext_4cc850(u8 *a, u8 *name);   // fastcall (ecx, edx), plain ret
typedef int(*stricmp_t)(const char *, const char *);
typedef u32(THISCALL *g1_t)(void *, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x656820, thiscall(node, name) ret 8, returns the matching node or 0. For each node (starting at the argument): b = this slot 0xc(node); when (word b[4] & 0x7ff) != 0: a null name
// matches at once; _stricmp(name, "...") (IAT 0x676414, string at 0x678d04) == 0 matches; otherwise o = (unaligned dword [engine+0x1aa3]) slot 0x80(word b[4]); when o is non-null
// 0x4cc850(o + 0x20, name) == 0 matches. No match: node = b[8], 0 at the end of the chain.
static u32 THISCALL fn656820(u8 *self, u8 *node, u8 *name) {
  while (node) {
    u8 *b = (u8 *)(*(g1_t **)self)[0xc / 4](self, (u32)node);
    if (*(u16 *)(b + 4) & 0x7ff) {
      if (!name) return (u32)node;
      if (G(stricmp_t, 0x676414)((const char *)name, (const char *)0x678d04) == 0) return (u32)node;
      u8 *eng = G(u8 *, 0x70039c);
      u8 *tab = (u8 *)rd32u(eng + 0x1aa3);
      u8 *o = (u8 *)(*(g1_t **)tab)[0x80 / 4](tab, *(u16 *)(b + 4));
      if (o && ext_4cc850(o + 0x20, name) == 0) return (u32)node;
    }
    node = *(u8 **)(b + 8);
  }
  return 0;
}
PCREG(656820, fn656820);
