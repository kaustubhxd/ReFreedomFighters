// batch36079.cpp - cascade s4 batch 36079: 0x5fd170 (tier F row).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void *(*memmove_t)(void *, const void *, u32);
typedef void (*free_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_5f3b00(void *self);            // plain ret
extern "C" void THISCALL ext_5fb660(void *self);            // plain ret
extern "C" void THISCALL ext_5fd2a0(void *self, u32 a);     // ret 4
extern "C" void ext_634273(void *p, u32 line);              // cdecl

// 0x5fd170, thiscall() plain ret (this = b): while b[0x20] (count) != 0: edi = last element of the dword array b[0x18];
// find the first index of that value; memmove the tail down when it is not the last index (size (count - i) * 4); count--;
// L = [0x724270]; L->slot 0x24(edi); 0x5fd2a0(b[4], edi); edi != 0 -> 0x5f3b00(edi), 0x634273(edi, 0xad2). Finally 0x5fb660(b[4]).
static void THISCALL fn5fd170(u8 *b) {
  if (rd(b + 0x20)) {
    do {
      u32 cnt = rd(b + 0x20);
      u32 *arr = *(u32 **)(b + 0x18);
      u32 v = arr[cnt - 1];
      u32 i = 0;
      while (i < cnt && arr[i] != v) i++;
      if (i < cnt) {
        if (i < cnt - 1) G(memmove_t, 0x676278)(arr + i, arr + i + 1, (cnt - i) << 2);
        wr(b + 0x20, rd(b + 0x20) - 1);
        u8 *L = G(u8 *, 0x724270);
        (*(v1_t **)L)[0x24 / 4](L, v);
        ext_5fd2a0(*(u8 **)(b + 4), v);
        if (v) {
          ext_5f3b00((void *)v);
          ext_634273((void *)v, 0xad2);
        }
      }
    } while (rd(b + 0x20));
  }
  ext_5fb660(*(u8 **)(b + 4));
}
PCREG(5fd170, fn5fd170);
