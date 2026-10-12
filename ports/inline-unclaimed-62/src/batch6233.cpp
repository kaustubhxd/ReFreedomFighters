// batch6233 - unclaimed-62 claim 26 (short exe leaves): three small functions.
//   0x54dbd0  thiscall, one argument (ret 4): c = this+0x8031; if c != 0 and arg != 0 returns arg + c, else 0
//   0x54a240  no arguments (ret 0): e = [0x70039c]; returns [e+0x190f]'s +0x133 dword when [e+0x190f] is non-null, else the dword at e+0x9db
//   0x5646b0  thiscall, returns al: 1 if this+0x85 byte, or this+0xc9a dword != 0xa, or this+0x18a byte is non-zero, else 0
#include "ff.h"

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static u32 THISCALL fn54dbd0(u8 *self, u32 a) {
  u32 c = rd32u(self + 0x8031);
  if (c == 0) return 0;
  if (a == 0) return 0;
  return a + c;
}

static u32 fn54a240(void) {
  u8 *e = G(u8 *, 0x70039c);
  u8 *c = rdp(e + 0x190f);
  if (c == 0) return rd32u(e + 0x9db);
  return rd32u(c + 0x133);
}

static u8 THISCALL fn5646b0(u8 *self) {
  if (self[0x85] != 0) return 1;
  if (rd32u(self + 0xc9a) != 0xa) return 1;
  if (self[0x18a] != 0) return 1;
  return 0;
}

PCREG(54dbd0, fn54dbd0);
PCREG(54a240, fn54a240);
PCREG(5646b0, fn5646b0);
