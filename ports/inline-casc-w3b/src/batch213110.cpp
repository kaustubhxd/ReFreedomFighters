#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef void(THISCALL *VF)(void *, float);
typedef void(THISCALL *V1)(void *, u32);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// config key lookup C.slot 0xa4(key, 0) -> al
static inline bool has(u8 *C, u32 key) { return (u8)(*(V2 *)(vt(C) + 0xa4))(C, key, 0) != 0; }

// float key: R = C.slot 0x94(buf, key); R[0].slot 0x84(R[4], &f) fills f; this[0x44].slot(f)
static inline void cfg_float(u8 *C, u8 *self, u32 key, u32 slot) {
  u32 buf[3];
  float f = 0.0f;
  u8 *R = (u8 *)(*(V2 *)(vt(C) + 0x94))(C, (u32)buf, key);
  u8 *Ro = (u8 *)rd32u(R);
  (*(V2 *)(vt(Ro) + 0x84))(Ro, rd32u(R + 4), (u32)&f);
  u8 *O = (u8 *)rd32u(self + 0x44);
  (*(VF *)(vt(O) + slot))(O, f);
}

// 0x4fb040: thiscall(), void. Resets the object (this slot 0x84(), this[0x5c] = 0, this[0x44]->[0x30] = 0, u16 this[0x5a] = 0) and loads the optional config values from the
// config object C = [[0x70039c]+0x9b] slot 0x138(): float keys 0x6922bc -> this[0x44] slot 0x214, 0x6922c8 -> slot 0x218, 0x69c208 -> slot 0x220, a colour triple under 0x69c218
// (C.slot 0x94 then R[0].slot 0x9c(R[4], 4) -> three dwords packed (a << 16) + (b << 8) + c, passed to slot 0x21c) and the float key 0x69c228 -> slot 0x224 (default 0x4286cccd = 67.4f).
extern "C" void THISCALL fn_4fb040(u8 *self) {
  u8 *selfvt = vt(self);
  wr32u(self + 0x5c, 0);
  (*(V0 *)(selfvt + 0x84))(self);
  u8 *O44 = (u8 *)rd32u(self + 0x44);
  wr32u(O44 + 0x30, 0);
  self[0x5a] = 0;
  self[0x5b] = 0;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *T = (u8 *)rd32u(eng + 0x9b);
  u8 *C = (u8 *)(*(V0 *)(vt(T) + 0x138))(T);
  if (has(C, 0x6922bc)) cfg_float(C, self, 0x6922bc, 0x214);
  if (has(C, 0x6922c8)) cfg_float(C, self, 0x6922c8, 0x218);
  if (has(C, 0x69c208)) cfg_float(C, self, 0x69c208, 0x220);
  if (has(C, 0x69c218)) {
    u32 buf[3];
    u8 *R = (u8 *)(*(V2 *)(vt(C) + 0x94))(C, (u32)buf, 0x69c218);
    u8 *Ro = (u8 *)rd32u(R);
    u8 *Q = (u8 *)(*(V2 *)(vt(Ro) + 0x9c))(Ro, rd32u(R + 4), 4);
    u8 *O = (u8 *)rd32u(self + 0x44);
    u32 packed = rd32u(Q);
    packed <<= 8;
    packed += rd32u(Q + 4);
    packed <<= 8;
    packed += rd32u(Q + 8);
    (*(V1 *)(vt(O) + 0x21c))(O, packed);
  }
  if (has(C, 0x69c228)) {
    cfg_float(C, self, 0x69c228, 0x224);
  } else {
    u8 *O = (u8 *)rd32u(self + 0x44);
    float dflt;
    u32 bits = 0x4286cccd;
    __builtin_memcpy(&dflt, &bits, 4);
    (*(VF *)(vt(O) + 0x224))(O, dflt);
  }
}
PCREG(4fb040, fn_4fb040);
