// batch66074.cpp - cascade s4 batch 66074: 0x5edcb0 (tier F row).
#include "ff.h"

extern "C" void FASTCALL ext_5edc80(u32 *first, u32 *last, u32 unused);   // reverse(first, last), ret 4 (one unused stack argument)

static void rev(u32 *a, u32 *b) {
  u32 *d = b;
  for (;;) {
    d--;
    if (a == d) break;
    u32 t = *a;
    *a = *d;
    a++;
    *d = t;
    if (a == d) break;
  }
}

// 0x5edcb0, fastcall(first, mid, last, x, y) ret 0xc, returns the new position of the old first element: a rotate of the dword range [first, last) around mid built from reversals.
// first == mid -> last; last == mid -> first. reverse(first, mid); reverse(mid, last); then swap the outer elements pairwise (first up, last down) until one side reaches mid; the rest is reversed by 0x5edc80 and
// the result is first when the first side is left over, else the last cursor.
extern "C" u32 *FASTCALL fn5edcb0(u32 *first, u32 *mid, u32 *last, u32 x, u32 y) {
  u32 *esi = first;
  u32 *edi = last;
  if (esi == mid) return last;
  if (edi == mid) return esi;
  rev(esi, mid);
  rev(mid, edi);
  for (;;) {
    if (mid == edi) {
      if (esi != mid) {
        ext_5edc80(esi, mid, (u32)last);
        return esi;
      }
      ext_5edc80(mid, edi, (u32)last);
      return edi;
    }
    u32 c = *esi;
    edi--;
    *esi = *edi;
    esi++;
    *edi = c;
    if (esi != mid) continue;
    ext_5edc80(mid, edi, (u32)last);
    return edi;
  }
}
PCREG(5edcb0, fn5edcb0);
