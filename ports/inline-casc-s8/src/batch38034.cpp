// batch38034.cpp - cascade s8 batch 38034: 0x5a9e20 (select an entry by name).
#include "ff.h"

extern "C" u32 *THISCALL ext_5a8360(u8 *self, u32 key);   // ret 4
extern "C" void THISCALL ext_5ebd80(u8 *self, u32 v);     // ret 4
typedef int (*stricmp_t)(const char *, const char *);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(*log3_t)(void *, u32, u32);
#define imp_stricmp G(stricmp_t, 0x676414)
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))

// 0x5a9e20, thiscall(name) ret 4. A name equal (pointer compare) to the one stored at the unaligned dword this+0x685 does nothing; otherwise it is stored and looked up: null maps to key 0x6aff24, a
// case-insensitive match against the sixteen known names (in the order below) maps to its key, and the key goes through 0x5a8360(this, key). A found entry's first dword is handed to
// 0x5ebd80 (this[0x430]); a failed lookup or a name without a match logs line 0xd94 with the name (logger slot 0x30).
static void THISCALL fn5a9e20(u8 *self, const char *name) {
  if ((u32)name == *(u32 *)(self + 0x685)) return;
  *(u32 *)(self + 0x685) = (u32)name;
  u32 key = 0;
  bool have = false;
  if (!name) {
    key = 0x6aff24;
    have = true;
  } else {
    static const u32 tab[16][2] = {{0x6ad858, 0x6affd4}, {0x690aec, 0x6b0014}, {0x6ad894, 0x6afff4}, {0x6ad870, 0x6affc8}, {0x6ad8b4, 0x6b0008}, {0x6ad8a8, 0x6b0048},
                                   {0x6b0090, 0x6b009c}, {0x690af4, 0x6b0058}, {0x6b00a8, 0x6affc8}, {0x6ad838, 0x6affe0}, {0x6ad84c, 0x6b002c}, {0x6ad884, 0x6b0038},
                                   {0x6b00b4, 0x6b0000}, {0x6ac9a0, 0x6affe8}, {0x6ad8a0, 0x6b0064}, {0x6acb04, 0x6b0020}};
    for (int i = 0; i < 16; i++) {
      if (imp_stricmp(name, (const char *)tab[i][0]) == 0) {
        key = tab[i][1];
        have = true;
        break;
      }
    }
  }
  if (have) {
    u32 *e = ext_5a8360(self, key);
    if (e) {
      ext_5ebd80(*(u8 **)(self + 0x430), *e);
      return;
    }
  }
  u8 *lg = G(u8 *, 0x700390);
  void *st = (void *)SLOT(lg, 0x20, v2_t)(lg, 0x6af69c, 0xd94);
  (*(log3_t **)st)[0x30 / 4](st, 0x6b00c8, (u32)name);
}
PCREG(5a9e20, fn5a9e20);
