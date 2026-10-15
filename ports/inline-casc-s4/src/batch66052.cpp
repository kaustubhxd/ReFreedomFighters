// batch66052.cpp - cascade s4 batch 66052: 0x4cf850 (tier F row).
#include "ff.h"

typedef u32(THISCALL *v0r_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef void(*qsort_t)(void *, u32, u32, void *);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *ext_41e290(u32 n);                  // cdecl
extern "C" void ext_634273(void *p, u32 flag);     // cdecl

// 0x4cf850, thiscall() plain ret (this = t): n = t->slot 5 (0x14)(); arr = alloc(n * 4, saturating to 0xffffffff on overflow); iterate t (slot 0x4c(&it), e = slot 0x5c(&it) while it[0]) storing the elements in arr; qsort(arr, count, 4, 0x4cc600).
// t[0xc] |= 0x80000000. Walk the chain t[4] (next at +4, nodes read before the call): t->slot 0x1f (0x7c)(node); t[0x14] = 0; t[4] = 0. For each stored element: t->slot 0x23 (0x8c)(e); free(e, 1). Finally free(arr, 4).
static void THISCALL fn4cf850(u8 *t) {
  u32 n = (*(v0r_t **)t)[0x14 / 4](t);
  u64 bytes = (u64)n * 4;
  u32 size = bytes > 0xffffffffull ? 0xffffffffu : (u32)bytes;
  u32 *arr = (u32 *)ext_41e290(size);
  u32 it[4];
  u32 cnt = 0;
  (*(v1_t **)t)[0x4c / 4](t, (u32)it);
  u32 e = (*(v1r_t **)t)[0x5c / 4](t, (u32)it);
  if (it[0] != 0) {
    do {
      arr[cnt] = e;
      cnt++;
      e = (*(v1r_t **)t)[0x5c / 4](t, (u32)it);
    } while (it[0] != 0);
  }
  G(qsort_t, 0x676450)(arr, cnt, 4, (void *)0x4cc600);
  wr(t + 0xc, rd(t + 0xc) | 0x80000000u);
  u32 head = rd(t + 4);
  while (head) {
    u32 next = rd((u8 *)head + 4);
    (*(v1_t **)t)[0x7c / 4](t, head);
    head = next;
  }
  wr(t + 0x14, 0);
  wr(t + 4, 0);
  for (u32 i = 0; i < cnt; i++) {
    (*(v1_t **)t)[0x8c / 4](t, arr[i]);
    ext_634273((void *)arr[i], 1);
  }
  ext_634273(arr, 4);
}
PCREG(4cf850, fn4cf850);
