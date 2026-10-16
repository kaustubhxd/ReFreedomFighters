#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" float THISCALL ext_4e5e80(void *rd);
extern "C" u32 THISCALL ext_4e5e60(void *rd);
extern "C" void THISCALL ext_4e6180(void *rd, void *out);
extern "C" void THISCALL ext_4e0a10(void *q);
extern "C" void THISCALL ext_4e0d00(void *q, float a);
extern "C" void FASTCALL ext_4e0be0(void *v, void *q);
extern "C" void THISCALL ext_4db2c0(void *obj, void *a, void *b);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline void wrf(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }

// 0x4a7380: thiscall(unused, reader) ret 8, no defined return value, /GS protected: loads the fields of an object from a record reader (reader->[0] is the cursor,
// a null cursor loads defaults: vectors (0, 500, 0) at +0x11b and (0, -500, 0) at +0x127, scale 1.0f at +0xea / +0xee / +0xf2, +0xfa = 1). Otherwise it reads in this order:
// float +0xb4 (0x4e5e80), flags +0xb8 and +0xb9 (0x4e5e60 != 0), vectors +0x11b and +0x127 (0x4e6180), floats +0xea, +0xee (clamped to at most 1.0f), +0xf2,
// dword +0xfa, dword +0x111, bytes +0x10f and +0x133, then +0x110 when the next record byte has type 3 (byte & 0x3f, not 0xff) and dword +0x117 when it has type 0xb.
// Then +0xd2 takes the vector +0x11b, a set +0x133 builds a quaternion on the stack (0x4e0a10, 0x4e0d00(pi), 0x4e0be0(+0xd2, quaternion)), 0x4db2c0 gets the object
// [[this+0x44]+8] with this+0x90 and this+0x84, six dwords +0xba..+0xce are cleared, +0xf6 takes the engine clock ([0x70039c] + 0x40), +0xfe = 0 and +0x10e = 0.
extern "C" void THISCALL fn_4a7380(u8 *self, u32 unused, u8 *rd) {
  (void)unused;
  wr32u(self + 0x111, 0);
  wr32u(self + 0x117, 0);
  self[0x10f] = 0;
  self[0x133] = 0;
  u8 *v1 = self + 0x11b;
  if (rd32u(rd) == 0) {
    wr32u(self + 0xb4, 0);
    self[0xb8] = 0;
    self[0xb9] = 0;
    wr32u(v1, 0);
    wr32u(v1 + 4, 0x43fa0000);
    wr32u(v1 + 8, 0);
    wr32u(self + 0x127, 0);
    wr32u(self + 0x12b, 0xc3fa0000);
    wr32u(self + 0x12f, 0);
    wr32u(self + 0xea, 0x3f800000);
    wr32u(self + 0xee, 0x3f800000);
    wr32u(self + 0xf2, 0x3f800000);
    wr32u(self + 0xfa, 1);
  } else {
    wrf(self + 0xb4, ext_4e5e80(rd));
    self[0xb8] = ext_4e5e60(rd) != 0;
    self[0xb9] = ext_4e5e60(rd) != 0;
    ext_4e6180(rd, v1);
    ext_4e6180(rd, self + 0x127);
    wrf(self + 0xea, ext_4e5e80(rd));
    wrf(self + 0xee, ext_4e5e80(rd));
    wrf(self + 0xf2, ext_4e5e80(rd));
    u32 e = ext_4e5e60(rd);
    wr32u(self + 0xfa, e);
    if (rdf(self + 0xee) > G(float, 0x678858)) wr32u(self + 0xee, 0x3f800000);
    wr32u(self + 0x111, ext_4e5e60(rd));
    self[0x10f] = ext_4e5e60(rd) != 0;
    self[0x133] = ext_4e5e60(rd) != 0;
    u8 b = **(u8 **)rd;
    if (b != 0xff && (b & 0x3f) == 3) self[0x110] = ext_4e5e60(rd) != 0;
    b = **(u8 **)rd;
    if (b != 0xff && (b & 0x3f) == 0xb) wr32u(self + 0x117, ext_4e5e60(rd));
  }
  wr32u(self + 0xd2, rd32u(v1));
  wr32u(self + 0xd6, rd32u(v1 + 4));
  wr32u(self + 0xda, rd32u(v1 + 8));
  if (self[0x133]) {
    u8 q[12];  // the original's 16-byte slot overlaps its /GS cookie: the helpers only touch 12 bytes
    ext_4e0a10(q);
    ext_4e0d00(q, bitsf(0x40490fdb));
    ext_4e0be0(self + 0xd2, q);
  }
  ext_4db2c0((void *)rd32u((u8 *)rd32u(self + 0x44) + 8), self + 0x90, self + 0x84);
  for (u32 off = 0xba; off <= 0xce; off += 4) wr32u(self + off, 0);
  u8 *clk = G(u8 *, 0x70039c) + 0x40;
  if (self + 0xf6 != clk) wr32u(self + 0xf6, rd32u(clk));
  wr32u(self + 0xfe, 0);
  self[0x10e] = 0;
  ext_633654(G(u32, 0x6f5630));
}
PCREG(4a7380, fn_4a7380);
