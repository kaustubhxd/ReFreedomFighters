// batch37016.cpp - cascade s6 batch 37016: 0x497470.
#include "ff.h"

extern "C" u8 *ext_41e290(u32 n);                          // alloc, cdecl
extern "C" void ext_634d10(u8 *p, u32 v, u32 n);           // memset thunk, cdecl
extern "C" void THISCALL ext_496380(u8 *self, u8 *buf);    // ret 4
typedef void(THISCALL *s1_t)(void *, void *);

// 0x497470, thiscall(a) ret 4: sibling of 0x498cc0. Builds a bit set with one bit per 0x70-byte entry of [[this+0x14]+4] (count = [this[0x14]+0xc] / 0x70, all set,
// padding bits of the last byte clear), hands it to 0x496380, then walks the entries: for every set bit it clears the bit (at byte i>>3, as the original does) and,
// when the entry lacks flag 0x4000000, follows its +0x50 chain, notifies a (slot 4) with the chain end and clears the bits of every entry the chain end's +0x54
// object lists (slot 0x50 iterates).
static void THISCALL fn497470(u8 *self, u8 *a) {
  u32 n = *(u32 *)(*(u8 **)(self + 0x14) + 0xc);
  u32 cnt = n / 0x70;
  u32 nbytes = (cnt + 7) >> 3;
  u8 *buf = ext_41e290(nbytes);
  ext_634d10(buf, 0xff, nbytes);
  if (cnt & 7) buf[nbytes - 1] = (u8)((1 << (cnt & 7)) - 1);
  ext_496380(self, buf);
  u32 base = *(u32 *)(*(u8 **)(self + 0x14) + 4);
  if (!nbytes) return;
  u32 off = 0;
  for (u32 i = 0; i != nbytes; i++, off += 0x380) {
    u32 v = buf[i];
    if (v) {
      u8 *e = (u8 *)(*(u32 *)(*(u8 **)(self + 0x14) + 4) + off);
      for (u32 bit = 1; bit <= 0x80; bit <<= 1, e += 0x70) {
        if (!(v & bit)) continue;
        buf[i >> 3] &= (u8)~bit;
        if (*(u32 *)(e + 0x3c) & 0x4000000) continue;
        u8 *c = e;
        while (*(u8 **)(c + 0x50)) c = *(u8 **)(c + 0x50);
        (*(s1_t **)a)[1](a, c);
        u8 *q = *(u8 **)(c + 0x54);
        u32 tag = q ? *(u32 *)(*(u8 **)(q + 0xc) + 0x23) : 0x200002;
        if (tag & 0x100000) {
          u32 f = *(u32 *)(q + 8);
          if (f) {
            do {
              s32 idx = (s32)(f - base) / 0x70;
              u32 uidx = (u32)idx;
              buf[uidx >> 3] &= (u8) ~(1u << (uidx & 7));
              u32 var = f;
              void *qq = *(void **)(c + 0x54);
              (*(s1_t **)qq)[0x50 / 4](qq, &var);
              f = var;
            } while (f);
          }
        }
        v = buf[i];
      }
    }
  }
}
PCREG(497470, fn497470);
