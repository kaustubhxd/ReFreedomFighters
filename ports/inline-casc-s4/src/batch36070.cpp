// batch36070.cpp - cascade s4 batch 36070: 0x438b10, 0x42b1e0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }

static bool same_cstr(const u8 *x, const u8 *y) {
  for (;;) {
    if (*x != *y) return false;
    if (*x == 0) return true;
    x++;
    y++;
  }
}

// 0x438b10, thiscall(name) ret 4 returns eax (this = s): name == 0 or s[0x19] == 0 -> 0. Iterate l = s[0x19] (slot 0x4c(&it); e = slot 0x5c(&it) while it[0]): e and e[4] and the strings name / *(char **)(e + 4) are equal -> return e. Otherwise 0.
static u32 THISCALL fn438b10(u8 *s, const u8 *name) {
  if (!name) return 0;
  u8 *l = *(u8 **)(s + 0x19);
  if (!l) return 0;
  u32 it[3];
  (*(v1_t **)l)[0x4c / 4](l, (u32)it);
  l = *(u8 **)(s + 0x19);
  u8 *e = (u8 *)(*(v1r_t **)l)[0x5c / 4](l, (u32)it);
  if (it[0] == 0) return 0;
  for (;;) {
    if (e && rd(e + 4)) {
      if (same_cstr(name, *(const u8 **)(e + 4))) return (u32)e;
    }
    l = *(u8 **)(s + 0x19);
    e = (u8 *)(*(v1r_t **)l)[0x5c / 4](l, (u32)it);
    if (it[0] == 0) return 0;
  }
}
PCREG(438b10, fn438b10);

// 0x42b1e0, fastcall(first = ecx, last = edx, p, pend, unused) ret 0xc returns eax: naive byte search (std::search): [first, last) for the pattern [p, pend); first == last or empty pattern -> first. Returns the match start, or last.
static u8 *FASTCALL fn42b1e0(u8 *first, u8 *last, u8 *p, u8 *pend, u32 unused) {
  (void)unused;
  if (first == last) return first;
  if (p == pend) return first;
  if (p + 1 == pend) {
    u8 al = *p;
    do {
      if (*first == al) break;
      first++;
    } while (first != last);
    return first;
  }
  u8 bl = *p;
  u8 *ecx = first;
  for (;;) {
    for (;;) {
      if (*ecx == bl) break;
      ecx++;
      if (ecx == last) return last;
    }
    u8 *cand1 = ecx + 1;
    u8 *edx = cand1;
    if (edx == last) return last;
    u8 *esi = p + 1;
    bool matched = false;
    if (*edx == *esi) {
      for (;;) {
        esi++;
        if (esi == pend) {
          matched = true;
          break;
        }
        edx++;
        if (edx == last) return last;
        if (*edx != *esi) break;
      }
    }
    if (matched) return ecx;
    ecx = cand1;
    if (ecx == last) return ecx;
  }
}
PCREG(42b1e0, fn42b1e0);
