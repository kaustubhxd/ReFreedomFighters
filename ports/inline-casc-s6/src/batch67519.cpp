// batch67519.cpp - cascade s6 batch 67519: 0x56cfd0.
#include "ff.h"

extern "C" void THISCALL ext_563d20(u8 *self, u32 a, u8 *p, u32 n);   // ret 0xc
extern "C" void THISCALL ext_563d40(u8 *self, u32 a, u8 *p, u32 n);   // ret 0xc
extern "C" void THISCALL ext_56d750(u8 *self);                        // plain ret
extern "C" void THISCALL ext_56d840(u8 *self);                        // plain ret
extern "C" u32 THISCALL ext_562d90(u8 *self, u32 key);                // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x56cfd0, thiscall(key) ret 4, returns bool: key handler. Refuses (0) while slot 0xd8 says so. The focused object is found through three slot hops (0x84, 0x2c4, 0x2f0). When it is the
// primary one (+0x180): key 0x102 / 0x103 with the flag byte +0x1b5 set run 0x563d20 / 0x563d40 on the 0xb bytes at +0x1b6 (marking the key handled), and 0x56d750 always runs. When it is the
// table object of +0x184: 0x103 / 0x102 run 0x563d40 / 0x563d20 on the 3 bytes at +0x1be (handled) and 0x56d840 runs. Handled keys return 1, others fall through to 0x562d90.
static u32 THISCALL fn56cfd0(u8 *self, u32 key) {
  if ((u8)vcall<u32>(self, 0xd8)) return 0;
  bool handled = false;
  void *o = (void *)vcall<u32>(self, 0x84);
  void *p = (void *)vcall<u32>(o, 0x2c4);
  u32 q = vcall<u32>(p, 0x2f0);
  if (q == D32(self, 0x180)) {
    if (key == 0x102) {
      if (self[0x1b5]) {
        ext_563d20(self, 1, self + 0x1b6, 0xb);
        handled = true;
      }
    } else if (key == 0x103) {
      if (self[0x1b5]) {
        ext_563d40(self, 1, self + 0x1b6, 0xb);
        handled = true;
      }
    }
    ext_56d750(self);
  } else {
    u32 t = vcall<u32>(*(void **)(*(u8 **)0x70039c + 0x9b), 0x58, D32(self, 0x184));
    if (q == t) {
      if (key == 0x103) {
        ext_563d40(self, 0, self + 0x1be, 3);
        handled = true;
      } else if (key == 0x102) {
        ext_563d20(self, 0, self + 0x1be, 3);
        handled = true;
      }
      ext_56d840(self);
    }
  }
  if (handled) return 1;
  return ext_562d90(self, key);
}
PCREG(56cfd0, fn56cfd0);
