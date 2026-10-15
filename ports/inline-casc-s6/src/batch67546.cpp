// batch67546.cpp - cascade s6 batch 67546: 0x596ef0.
#include "ff.h"

extern "C" void THISCALL ext_597050(u8 *self, u32 a, u32 entry, u32 z);   // ret 0xc
extern "C" int THISCALL ext_597680(u8 *self, int start, int dir);         // ret 8
extern "C" u32 THISCALL ext_597a70(u8 *self, u32 entry);                  // ret 4, bool in al
extern "C" void THISCALL ext_597e00(u8 *self, u32 entry);                 // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(int *)((u8 *)(p) + (o)))

// 0x596ef0, thiscall(a, flag) ret 8, return value unused: dispatches the action `a` to the entries of two lists. With a primary list (count this[0x2e6] > 0, entries from +0xe6) it runs 0x597050(a,
// entry, 0) on every entry, and with `flag` additionally 0x597e00(entry) for entries accepted by 0x597a70 (or, when sys[0x1b5d] != 1, found in the secondary list at +0x1dae / count +0x1fae).
// Without a primary list it works on the secondary list's current index (+0x1fb2): the next valid entry (0x597680) receives the action, is made current, and with `flag` is removed (swap with the last
// entry); otherwise the index advances (wrapping to 0 at the end). Action 5 acts on the found entry and always advances.
static void THISCALL fn596ef0(u8 *self, u32 a, u32 flag) {
  int cnt = S32(self, 0x2e6);
  if (cnt != 0) {
    for (int i = 0; i < cnt;) {
      u32 entry = D32(self, 0xe6 + 4 * i);
      ext_597050(self, a, entry, 0);
      if ((u8)flag) {
        u32 e = D32(self, 0xe6 + 4 * i);
        if (D32(*(u8 **)0x70039c, 0x1b5d) == 1) {
          if ((u8)ext_597a70(self, e)) ext_597e00(self, D32(self, 0xe6 + 4 * i));
        } else {
          int n = S32(self, 0x1fae);
          for (int k = 0; k < n; k++) {
            if (D32(self, 0x1dae + 4 * k) == e) {
              ext_597e00(self, D32(self, 0xe6 + 4 * i));
              break;
            }
          }
        }
      }
      i++;
      cnt = S32(self, 0x2e6);
    }
    return;
  }
  if (S32(self, 0x1fae) == 0) return;
  int r = ext_597680(self, (int)D32(self, 0x1fb2), 1);
  if (a == 5) {
    if (r == -1) return;
    ext_597050(self, 5, D32(self, 0x1dae + 4 * r), 0);
    D32(self, 0x1fb2)++;
  } else {
    if (r != -1) {
      ext_597050(self, a, D32(self, 0x1dae + 4 * r), 0);
      D32(self, 0x1fb2) = (u32)r;
    }
    if ((u8)flag) {
      D32(self, 0x1fae)--;
      D32(self, 0x1dae + 4 * D32(self, 0x1fb2)) = D32(self, 0x1dae + 4 * D32(self, 0x1fae));
      D32(self, 0x1dae + 4 * D32(self, 0x1fae)) = 0;
    } else {
      D32(self, 0x1fb2)++;
    }
  }
  if (D32(self, 0x1fb2) == D32(self, 0x1fae)) D32(self, 0x1fb2) = 0;
}
PCREG(596ef0, fn596ef0);
