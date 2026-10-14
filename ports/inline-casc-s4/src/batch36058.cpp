// batch36058.cpp - cascade s4 batch 36058: 0x4f3290 (tier F row).
#include "ff.h"

typedef void(THISCALL *v5_t)(void *, u32, u32, u32, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void STDCALL ext_4f2240(u32 a, u32 b);              // ret 8
extern "C" void THISCALL ext_4f9680(void *self, u32 a);        // ret 4 (tail target)

// 0x4f3290, thiscall(a) ret 4 (this = s): s[0x64] == a -> return. s[0x6a] (byte): 0x4f2240(0xfe, s[0x64]), s[0x68] = 0xfe. old = tab->slot 0x4c(s[0x64]); new = tab->slot 0x4c(a);
// s->slot 0x2dc(0x40, new, 0, s[0x64]); s->slot 0x2dc(0x20, old, 0, a); s[0x64] = a; s->slot 0x2dc(0x100000, old, new, 0); then tail 0x4f9680(0x700e24, 0).
static void THISCALL fn4f3290(u8 *s, u32 a) {
  if (rd(s + 0x64) == a) return;
  if (s[0x6a]) {
    ext_4f2240(0xfe, rd(s + 0x64));
    s[0x68] = 0xfe;
  }
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 old = (*(v1r_t **)tab)[0x4c / 4](tab, rd(s + 0x64));
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 nw = (*(v1r_t **)tab)[0x4c / 4](tab, a);
  (*(v5_t **)s)[0x2dc / 4](s, 0x40, nw, 0, rd(s + 0x64));
  (*(v5_t **)s)[0x2dc / 4](s, 0x20, old, 0, a);
  wr(s + 0x64, a);
  void **vt = *(void ***)s;
  ((v5_t)vt[0x2dc / 4])(s, 0x100000, old, nw, 0);
  ext_4f9680((void *)0x700e24, 0);
}
PCREG(4f3290, fn4f3290);
