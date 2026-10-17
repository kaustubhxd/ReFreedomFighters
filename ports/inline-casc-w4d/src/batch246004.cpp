// batch246004.cpp - Sonnet-w4d, tier 6/7 hand ports (run 4).
#include "ff.h"
#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)
typedef u32(THISCALL *W4T1)(u32, u32);
static inline u32 w4v1(u32 o, u32 slot, u32 a) { return ((W4T1)*(u32 *)(*(u32 *)o + slot))(o, a); }
extern "C" u32 THISCALL ext_4ccba0_w4(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccf60_w4(u32) __asm__("ext_4ccf60");

// 0x53aae0: thiscall(obj) ret 4 -> al = 1 (SEH 0x66c60b, state 0 after the iterator ctor). Fills an iterator It from obj vslot 0x70(&It),
// walks it (vslot 0x4c reset, 0x5c next(&flag) -> key); each key is resolved with the registry [[0x70039c]+0x9b] vslot 0x58; a non-null
// result that is not already in the list this[4] (vslots 0x4c/0x64, element[4] == result) gets a node from this[4] vslot 4(0):
// node[0] = (result vslot 0x1e0(0x2007d0) & 0xff) ? 1 : 2, node[1] = result, node[2] = G[0x40] (unless aliased), node[3] = node[4] = 0,
// appended to the chain this[0xe] (next at +0xc, prev at +0x10).
extern "C" u32 THISCALL GUESS_53aae0(u32 self, u32 obj) {
  SEH_ENTER(0x66c60b);
  u8 It[0x40] __attribute__((aligned(4)));
  u32 F, H;
  u32 itp = (u32)It;
  ext_4ccba0_w4(itp);
  reg.state = 0;
  w4v1(obj, 0x70, itp);
  w4v1(itp, 0x4c, (u32)&F);
  u32 r = w4v1(itp, 0x5c, (u32)&F);
  if (F != 0) {
    for (;;) {
      u32 rg;
      __builtin_memcpy(&rg, (u8 *)*(u32 *)0x70039c + 0x9b, 4);
      u32 ebx = w4v1(rg, 0x58, r);
      if (ebx != 0) {
        bool found = false;
        u32 lst = *(u32 *)(self + 4);
        if (lst != 0) {
          w4v1(lst, 0x4c, (u32)&H);
          u32 e = w4v1(*(u32 *)(self + 4), 0x64, (u32)&H);
          while (e != 0) {
            if (*(u32 *)(e + 4) == ebx) { found = true; break; }
            e = w4v1(*(u32 *)(self + 4), 0x64, (u32)&H);
          }
        }
        if (!found) {
          u32 p = w4v1(*(u32 *)(self + 4), 4, 0);
          u32 *node = (u32 *)(p - 4);
          u32 al = ((W4T1)*(u32 *)(*(u32 *)ebx + 0x1e0))(ebx, 0x2007d0) & 0xff;
          node[1] = ebx;
          node[0] = al ? 1 : 2;
          u32 *dst = node + 2;
          u32 *src = (u32 *)(*(u32 *)0x70039c + 0x40);
          if (dst != src) *dst = *src;
          node[4] = 0;
          node[3] = 0;
          u32 head;
          __builtin_memcpy(&head, (u8 *)self + 0xe, 4);
          if (head == 0) {
            u32 nv = (u32)node;
            __builtin_memcpy((u8 *)self + 0xe, &nv, 4);
          } else {
            u32 *t = (u32 *)head;
            while (t[3] != 0) t = (u32 *)t[3];
            t[3] = (u32)node;
            node[4] = (u32)t;
          }
        }
      }
      r = w4v1(itp, 0x5c, (u32)&F);
      if (F == 0) break;
    }
  }
  ext_4ccf60_w4(itp);
  SEH_LEAVE();
  return 1;
}
PCREG(53aae0, GUESS_53aae0);
