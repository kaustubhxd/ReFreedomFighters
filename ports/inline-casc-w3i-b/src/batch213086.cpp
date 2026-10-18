#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);

extern "C" u32 THISCALL ext_600820(void *self, void *s);
extern "C" u32 THISCALL ext_5f4940(void *self, u32 a);
extern "C" u32 THISCALL ext_5f9450(void *self, void *s, u32 q, void *p);
extern "C" u32 THISCALL ext_600810(void *self);
extern "C" u32 THISCALL ext_600860(void *self, void *s, void *obj, u32 q);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u32 rd16u(const u8 *p) { u16 v; __builtin_memcpy(&v, p, 2); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x5f92c0: thiscall(stream, q) ret 8, no defined return value: serializes the object into the stream object (slots: 0x38 float, 0x2c dword, 0x28 / 0x24 word writers, 0x48 pair):
// 1.9f (0x3ff33333), 0x600820(this[0x96], stream), this[0x64], this slot 0x28(), words [0xaa] [0xac], this slot 0x28(), words [0xb2] [0xb4], word [8] via slot 0x28, float [0xa], dword [0xe],
// 0x5f4940(this, [0x16]) (or 0 when [0x16] is zero), dword [0x24], three nested 0x5f9450(this, stream, q, this+0x28 / 0x34 / 0x40), the child count [0x54], each child (array [0x4c]) slot 0xc(stream, q)
// (assert hook for an out of range first index) and, when [0x20] is zero, 0x600810(this+0x9a) as dword, the pair ([0x9e], [0xa2] - [0x9e]) via slot 0x48 and 0x600860(this[0x96], stream, this, q).
extern "C" void THISCALL fn_5f92c0(u8 *self, u8 *S, u32 q) {
  float f19 = bitsf(0x3ff33333);
  (void)f19;
  V1 w38 = *(V1 *)(vt(S) + 0x38);
  w38(S, 0x3ff33333);
  ext_600820((void *)rd32u(self + 0x96), S);
  (*(V1 *)(vt(S) + 0x2c))(S, rd32u(self + 0x64));
  {
    u8 *sv = vt(S);
    u32 r = (*(V0 *)(vt(self) + 0x28))(self);
    (*(V1 *)(sv + 0x2c))(S, r);
  }
  (*(V1 *)(vt(S) + 0x24))(S, rd16u(self + 0xaa));
  (*(V1 *)(vt(S) + 0x24))(S, rd16u(self + 0xac));
  {
    u8 *sv = vt(S);
    u32 r = (*(V0 *)(vt(self) + 0x28))(self);
    (*(V1 *)(sv + 0x2c))(S, r);
  }
  (*(V1 *)(vt(S) + 0x24))(S, rd16u(self + 0xb2));
  (*(V1 *)(vt(S) + 0x24))(S, rd16u(self + 0xb4));
  (*(V1 *)(vt(S) + 0x28))(S, rd16u(self + 8));
  (*(V1 *)(vt(S) + 0x38))(S, rd32u(self + 0xa));
  (*(V1 *)(vt(S) + 0x2c))(S, rd32u(self + 0xe));
  u32 p16 = rd32u(self + 0x16);
  if (p16) {
    u8 *sv = vt(S);
    u32 r = ext_5f4940(self, p16);
    (*(V1 *)(sv + 0x2c))(S, r);
  } else {
    (*(V1 *)(vt(S) + 0x2c))(S, 0);
  }
  (*(V1 *)(vt(S) + 0x2c))(S, rd32u(self + 0x24));
  ext_5f9450(self, S, q, self + 0x28);
  ext_5f9450(self, S, q, self + 0x34);
  ext_5f9450(self, S, q, self + 0x40);
  (*(V1 *)(vt(S) + 0x2c))(S, rd32u(self + 0x54));
  u32 i = 0;
  if (rd32u(self + 0x54) > i) {
    if (!(i < rd32u(self + 0x54))) {
      typedef u32 (*Hook)();
      Hook h = G(Hook, 0x7003b0);
      if (!h) __builtin_trap();
      h();
    }
    do {
      u8 *child = (u8 *)((u32 *)rd32u(self + 0x4c))[i];
      (*(V2 *)(vt(child) + 0xc))(child, (u32)S, q);
      i++;
    } while (i < rd32u(self + 0x54));
  }
  if (rd32u(self + 0x20) == 0) {
    u8 *sv = vt(S);
    u32 r = ext_600810(self + 0x9a);
    (*(V1 *)(sv + 0x2c))(S, r);
    u32 a = rd32u(self + 0x9e), b = rd32u(self + 0xa2);
    (*(V2 *)(vt(S) + 0x48))(S, a, b - a);
    ext_600860((void *)rd32u(self + 0x96), S, self, q);
  }
}
PCREG(5f92c0, fn_5f92c0);
