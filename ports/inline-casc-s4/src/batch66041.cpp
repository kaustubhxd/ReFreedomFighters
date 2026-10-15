// batch66041.cpp - cascade s4 batch 66041: 0x55fe40 (tier F row).
#include "ff.h"

typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4
extern "C" void THISCALL ext_5002f0(void *self, u32 f);  // ret 4

static u8 *gobj() { return *(u8 **)(G(u8 *, 0x7003b8) + 0x2c21); }

// Typed record check: tag r[4] of 0 or 2 is fine; anything else prints through the log object (0xd5, 0x69c8e0: 0x69c6b0, 0x69c938) and calls the assert hook (int3 when none), skipping the assignment.
static void bind(u8 *r, u32 value) {
  u32 t = r[4];
  if (t == 0 || t == 2) {
    wr(r, value);
    r[4] = 2;
    return;
  }
  u8 *db = G(u8 *, 0x700390);
  u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x69c8e0u, 0xd5u);
  void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
  ((void (*)(u8 *, u32, u32))fn)(lo, 0x69c6b0u, 0x69c938u);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x55fe40, stdcall(p) ret 4: bind(0x5003d0(p[8], 0), g[0x4c]); g = [0x7003b8][0x2c21]; bind(0x5003d0(p[8], 1), g[0x50]); flag = g[0x58] || g[0x59]; 0x5002f0(0x5003d0(p[8], 2), flag).
static void STDCALL fn55fe40(u8 *p) {
  u8 *g = gobj();
  u8 *r = ext_5003d0(*(u8 **)(p + 8), 0);
  bind(r, rd(g + 0x4c));
  g = gobj();
  r = ext_5003d0(*(u8 **)(p + 8), 1);
  bind(r, rd(g + 0x50));
  g = gobj();
  u32 flag = (g[0x58] || g[0x59]) ? 1 : 0;
  r = ext_5003d0(*(u8 **)(p + 8), 2);
  ext_5002f0(r, flag);
}
PCREG(55fe40, fn55fe40);
