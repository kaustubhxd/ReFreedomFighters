// batch294.cpp - unclaimed area 67, GUESS name for 0x439380 (body from the PC bytes). SEH frame and cookie not reproduced.
#include "ff.h"

extern "C" u32 STDCALL ext_439230(u32 base);   // table record whose base equals the argument, or 0 (ret 4), original code
extern "C" u32 THISCALL ext_4cc1d0(u8 *s);     // MYSTR::c_str, original code
extern "C" void THISCALL ext_4cbec0(u8 *s);    // MYSTR::~MYSTR, original code

typedef u32 (THISCALL *F0)(u8 *self);
typedef u32 (THISCALL *F1)(u8 *self, u32 a);
typedef u8 *(THISCALL *F2)(u8 *self, u8 *out, u32 id);
static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }
static inline u8 rdb(u32 p, u32 off) { return *(u8 *)(unsigned long)(p + off); }
static inline u8 *P(u32 p) { return (u8 *)(unsigned long)p; }

// The owner behind the tagged handle at [this+0xc]: tag 3 -> h-4, tag 1 -> [h+8]-4 (null stays 0), anything else 0.
static u32 handleOwner(u32 self) {
  u32 h = rdw(self, 0xc);
  if (h == 0)
    return 0;
  u32 t = rdw(h, 0);
  if (t == 3)
    return h ? h - 4 : 0;
  if (t == 1) {
    u32 v = rdw(h, 8);
    return v ? v - 4 : 0;
  }
  return 0;
}

// 0x439380, thiscall, ret 4. See docs/20-unclaimed-67.md, batch 294.
static u32 THISCALL guessEntryName(u8 *selfP, u32 a) {
  u32 self = (u32)(unsigned long)selfP;
  u32 m = rdw(self, 0x15);
  if (m == 0)
    return 0;
  if ((int)a >= (int)((F0)rdw(rdw(m, 0), 0x14))(P(m)))
    return 0;
  u32 idx = ((F1)rdw(rdw(m, 0), 0x30))(P(rdw(self, 0x15)), a);
  if (rdw(0x6e48c0, 0) == 0)
    return 0;
  u32 i = 0, start = 0, rem;
  for (;;) {
    u32 cnt = rdw(0x6e48c4, i * 16);
    rem = idx - start;
    if ((int)rem < (int)cnt)
      break;
    start += cnt;
    i++;
    if (rdw(0x6e48c0, i * 16) == 0)
      return 0;
  }
  u32 base = rdw(0x6e48c0, i * 16);
  u32 entry = base + rem * 12;
  if (entry == 0)
    return 0;
  for (u32 n = rdw(rdw(rdw(handleOwner(self), 0x11), 0x1344), idx * 10 + 4); n != 0; n = rdw(n, 5)) {
    u32 it = rdw(n, 0);
    if (rdw(it, 0) != 0)
      continue;
    if ((it ? it - 4 : 0) == self) {
      if (rdb(n, 4) == 0)
        return 0;
      break;
    }
  }
  (void)rdw(handleOwner(self), 0x11);   // loaded into ECX before the call; 0x439230 does not use it
  if (rdw(ext_439230(0x6e41d0), 8) != base)
    return rdw(entry, 8);
  u32 id = rdw(entry, 4);
  for (u32 q = 0x6e4928; rdw(q, 0) != 0; q += 8)
    if (id == rdw(q, 4)) {
      id = rdw(q, 0);
      break;
    }
  u32 g = rdw(0x70039c, 0);
  if (rdb(g, 0x6e) != 0 && id == 0xb8)
    id = 0x138;
  u8 buf[0x80];
  u8 *s = ((F2)rdw(rdw(g, 0), 0xdc))(P(g), buf, id);
  u32 r = ext_4cc1d0(s);
  ext_4cbec0(buf);
  return r;
}
PCREG(439380, guessEntryName);
