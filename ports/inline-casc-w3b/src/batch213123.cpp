#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V3)(void *, u32, u32, u32);
typedef u32(THISCALL *V5)(void *, u32, u32, u32, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" u32 THISCALL ext_564fd0(void *self, u32 code);
extern "C" void THISCALL ext_56b930(void *self, u32 a, u32 b);
extern "C" u32 THISCALL ext_5b1000(void *self, u32 a);
extern "C" u32 THISCALL ext_48aad0(void *pair);
extern "C" void THISCALL ext_5ae710(void *self, u32 a);
extern "C" void THISCALL ext_59cb60(void *self, void *buf);
extern "C" u32 THISCALL ext_561be0(void *self);
extern "C" void THISCALL ext_563500(void *self);
extern "C" void THISCALL ext_562bc0(void *self);
extern "C" void THISCALL ext_565100(void *self, u32 a);
extern "C" void THISCALL ext_563d20(void *self, u32 a, void *p, u32 c);
extern "C" void THISCALL ext_563d40(void *self, u32 a, void *p, u32 c);
extern "C" void THISCALL ext_56b460(void *self, u32 a);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x56c1a0: menu command dispatch, thiscall(int code) ret 4, /GS, always returns al = 0. Codes 1, 2, 3, 10, 101, 102 (jump table 0x56c438 + index bytes 0x56c450) are handled
// unless 0x564fd0(code) ran and self.slot 0xd8() reports true; every other code does nothing.
extern "C" u32 THISCALL fn_56c1a0(u8 *self, u32 code) {
  u8 buf[8];
  ext_564fd0(self, code);
  if ((u8)(*(V0 *)(vt(self) + 0xd8))(self)) goto done;
  if (code - 1 > 0x65) goto done;
  switch (code) {
  case 1: {
    u8 *E = G(u8 *, 0x70039c);
    u8 *T = (u8 *)rd32u(E + 0x9b);
    u8 *Y = (u8 *)(*(V0 *)(vt(T) + 0x134))(T);
    (*(V3 *)(vt(Y) + 0x5c))(Y, 0x6a777c, 0, 2);
    u8 *B = (u8 *)rd32u(self + 0x94);
    u8 *P = B + 0x57;
    ext_56b930((void *)rd32u(self + 0xcea), (u32)P, rd32u(self + 0xce2));
    if ((u8)ext_5b1000(B + 0x50f, 0x6a7924)) {
      u8 *E2 = G(u8 *, 0x70039c);
      u8 *T2 = (u8 *)rd32u(E2 + 0x9b);
      u32 pair[2];
      pair[0] = (*(V0 *)(vt(T2) + 0x138))(T2);
      pair[1] = 0x6a7b0c;
      u32 ebx = ext_48aad0(pair);
      u32 m = rd32u(P + 0x3ba);
      if (m == 3 || m == 2) {
        u8 *O44 = (u8 *)rd32u(self + 0x44);
        u8 *vo = vt(O44);
        u8 *E3 = G(u8 *, 0x70039c);
        u8 *T3 = (u8 *)rd32u(E3 + 0x9b);
        u32 ax = (*(V5 *)(vt(T3) + 0x114))(T3, 0x6a7b48, 0, 0x6a7b20, 0xa2, 0);
        (*(V2 *)(vo + 0x12c))(O44, ebx, (u16)ax);
      }
      (*(V1 *)(vt(self) + 0xd0))(self, ebx);
      goto done;
    }
    ext_5ae710(P, 0);
    {
      const u8 *src = P + 0x35a + 0x48;
      u8 *dst = buf;
      u8 c;
      do {
        c = *src++;
        *dst++ = c;
      } while (c != 0);
    }
    {
      u32 cl = buf[2];
      u32 al;
      if (cl == 0x31) {
        al = buf[3];
      } else {
        if (cl == 0x38) {
          if (buf[3] != 0x52) cl = 0x39;
          buf[2] = (u8)cl;
        }
        al = 0x52;
      }
      if ((u8)cl == 0x36) al = 0x41;
      buf[4] = 0;
      buf[3] = (u8)al;
    }
    ext_59cb60((void *)rd32u(self + 0x94), buf);
    if ((u8)ext_561be0(self)) {
      ext_563500(self);
      ext_562bc0(self);
      goto done;
    }
    {
      u8 *E4 = G(u8 *, 0x70039c);
      u8 *T4 = (u8 *)rd32u(E4 + 0x9b);
      u32 pair2[2];
      pair2[0] = (*(V0 *)(vt(T4) + 0x138))(T4);
      u8 *vs = vt(self);
      pair2[1] = 0x6a7b5c;
      u32 r = ext_48aad0(pair2);
      (*(V1 *)(vs + 0xd0))(self, r);
    }
    goto done;
  }
  case 2: {
    u8 *B = (u8 *)rd32u(self + 0x94);
    ext_56b930((void *)rd32u(self + 0xcea), (u32)(B + 0x57), rd32u(self + 0xce2));
    ext_565100(self, 0x14);
    goto done;
  }
  case 3: {
    u8 *B = (u8 *)rd32u(self + 0x94);
    u32 v = rd32u(self + 0xce2);
    wr32u(B + 0xdd, v);
    ext_565100(self, 0x17);
    u8 *O = (u8 *)rd32u(self + 0xc7e);
    (*(V1 *)(vt(O) + 0xbc))(O, 1);
    goto done;
  }
  case 10:
  case 102: {
    u8 *p = self + 0xce2;
    ext_563d40(self, 0, p, rd32u(self + 0xce6));
    ext_56b460(self, rd32u(p));
    goto done;
  }
  case 101: {
    u8 *p = self + 0xce2;
    ext_563d20(self, 0, p, rd32u(self + 0xce6));
    ext_56b460(self, rd32u(p));
    goto done;
  }
  default:
    break;
  }
done:
  ext_633654(G(u32, 0x6f5630));
  return 0;
}
PCREG(56c1a0, fn_56c1a0);
