// batch66053.cpp - cascade s4 batch 66053: 0x5ffc10 (tier F row).
#include "ff.h"

typedef s32(*cmp_t)(const char *, const char *);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }

extern "C" const char *THISCALL ext_5ffb00(void *ctxobj, u32 idx);   // ret 4

static void assert_hook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x5ffc10, thiscall(name) ret 4, returns an entry value or -1 (this = t, packed layout: count u16 +4, u16 index array pointer +6, dword value array pointer +0xa, context pointer +0xe):
// for i < count: idx = (u16) t[6][i]; c = t[0xe]. c[0xa8] != 0 and c[0xa0] <= idx: j = (u16)(idx - c[0xa0]); j < c[0xa8] -> s = c[0xac][j] + c[0xb0]; else log (0x137, 0x6b9420: 0x6b9474) + assert hook and s keeps its previous value.
// Otherwise c[0x9c] set -> s = 0x5ffb00(c[0x9c], idx); else assert hook (s unchanged). _stricmp(s, name) == 0 -> return t[0xa][i]. Initially s = name. End -> -1.
static u32 THISCALL fn5ffc10(u8 *t, const char *name) {
  u32 i = 0;
  if (!(0 < *(u16 *)(t + 4))) return 0xffffffffu;
  const char *s = name;
  const char *sd = name;
  do {
    u32 idx = ((u16 *)rd(t + 6))[i];
    u8 *c = *(u8 **)(t + 0xe);
    if (rd(c + 0xa8) == 0 || rd(c + 0xa0) > idx) {
      u8 *cx = *(u8 **)(c + 0x9c);
      if (cx) {
        s = ext_5ffb00(cx, idx);
      } else {
        assert_hook();
      }
    } else {
      u32 j = (u16)(idx - rd(c + 0xa0));
      if (j < rd(c + 0xa8)) {
        sd = (const char *)(rd(*(u8 **)(c + 0xac) + j * 4) + rd(c + 0xb0));
        s = sd;
      } else {
        u8 *db = G(u8 *, 0x700390);
        u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x6b9420u, 0x137u);
        void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
        ((void (*)(u8 *, u32, u32))fn)(lo, 0x69c6b0u, 0x6b9474u);
        assert_hook();
        s = sd;
      }
    }
    if (G(cmp_t, 0x676414)(s, name) == 0) return rd(*(u8 **)(t + 0xa) + i * 4);
    i++;
  } while ((s32)i < *(u16 *)(t + 4));
  return 0xffffffffu;
}
PCREG(5ffc10, fn5ffc10);
