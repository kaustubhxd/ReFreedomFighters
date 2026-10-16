#include "ff.h"

extern "C" u32 THISCALL ext_5320b0(void *self, u32 a, u32 b, u32 c, u32 e);
extern "C" u32 THISCALL ext_52e320(void *self, u32 p);
extern "C" u32 THISCALL ext_531070(void *self, u32 p);
extern "C" u32 THISCALL ext_530a40(void *self);
extern "C" u32 THISCALL ext_531e70(void *self, u32 a0, u32 a1, u32 a2, u32 a3, float f, u32 w, u32 c, u32 q, u32 p, u32 rec, u32 e, u32 uq0, u32 flag, u32 x);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u16 rd16u(const u8 *p) { u16 v; __builtin_memcpy(&v, p, 2); return v; }

// 0x531c40: thiscall(A, B, C, D, E) ret 0x14: D == 10 forwards to 0x5320b0(A, B, C, E). Otherwise rec = this->[0x98] + (u16)A * 0x15 supplies three words (+4, +6, +8) copied
// into a stack triple; p = this->[0x78] + 10 * (word read through rec[0] from table this->[0x5a] (stride 12, when B == this->[0x38] - 1) or this->[0x54] (stride 0x16));
// the object C (a record: u16 at +0x16, byte at +0x20 == 3 picks 0x52e320 over 0x531070 to fetch a word from the table at 0x6e9004 + 6 * D, D == 11 uses C->[0x16] itself)
// must give nonzero values and C->[0x16] != 0, else 0; q is the same lookup for the C->[0x16] index (also replacing the triple by C's words +0x18, +0x1a, +0x1c);
// 0x530a40(C) == 0 returns 0xffff. Then (u8)p[0], (u8)q[0], bytes p[1], p[2], q[1], q[2] build a weight by D (0..5; other D calls the assert hook [0x7003b0] first) and
// 0x531e70 is called with 14 values (the float is 0x678858, or 0x67da0c for D 4 and 5; its flag dword keeps the upper bytes of q) whose result is returned.
extern "C" u32 THISCALL fn_531c40(u8 *self, u32 A, u32 B, u32 C, u32 D, u32 E) {
  u8 *cp = (u8 *)C;
  if (D == 10) return ext_5320b0(self, A, B, C, E);
  u8 *rec = (u8 *)rd32u(self + 0x98) + (u16)A * 0x15;
  u16 w[3];
  w[0] = rd16u(rec + 4);
  w[1] = rd16u(rec + 6);
  w[2] = rd16u(rec + 8);
  u32 last = rd32u(self + 0x38) - 1;
  u32 x = B == last ? rd16u((u8 *)rd32u(self + 0x5a) + rd16u(rec) * 12) : rd16u((u8 *)rd32u(self + 0x54) + rd16u(rec) * 0x16);
  u8 *p = (u8 *)rd32u(self + 0x78) + x * 10;
  u32 ax;
  if (D == 0xb) {
    ax = rd16u(cp + 0x16);
  } else if (cp[0x20] == 3) {
    ax = (u16)ext_52e320(cp, D * 6 + 0x6e9004);
  } else {
    ax = (u16)ext_531070(cp, D * 6 + 0x6e9004);
  }
  if ((u16)ax == 0) return 0;
  u32 v = rd16u(cp + 0x16);
  u8 *pc16 = cp + 0x16;
  if ((u16)v == 0) return 0;
  u32 y = B == last ? rd16u((u8 *)rd32u(self + 0x5a) + (u16)v * 12) : rd16u((u8 *)rd32u(self + 0x54) + (u16)v * 0x16);
  u8 *q = (u8 *)rd32u(self + 0x78) + y * 10;
  w[0] = rd16u(pc16 + 2);
  w[1] = rd16u(pc16 + 4);
  w[2] = rd16u(pc16 + 6);
  u32 c = (u16)ext_530a40(cp);
  if (c == 0) return 0xffff;
  float f = G(float, 0x678858);
  u32 flag = (u32)(u32)q & ~0xffu;
  flag |= 1;
  u32 q0 = q[0], p0 = p[0];
  u32 ecx, eax;
  switch (D) {
    case 0: ecx = p[1] * p0; eax = p0; break;
    case 1: flag &= ~0xffu; ecx = q[1] * q0; eax = p0; break;
    case 2: ecx = 0; eax = p0; break;
    case 3: flag &= ~0xffu; ecx = 0; eax = p0; break;
    case 4: f = G(float, 0x67da0c); ecx = (p[2] + p[1]) * p0; eax = p0; break;
    case 5: f = G(float, 0x67da0c); ecx = (q[2] + q[1]) * q0; flag &= ~0xffu; eax = p0; break;
    default: {
      typedef u32 (*Hook)();
      Hook h = G(Hook, 0x7003b0);
      if (!h) __builtin_trap();
      h();
      f = G(float, 0x678858);
      ecx = p0;
      eax = p0;
      break;
    }
  }
  return ext_531e70(self, (u32)(u32)pc16, A, E, D, f, (u32)(u32)w, c, (u32)(u32)q, (u32)(u32)p, (u32)(u32)rec, eax, q0, flag, ecx);
}
PCREG(531c40, fn_531c40);
