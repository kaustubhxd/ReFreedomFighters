#include "ff.h"

typedef void(THISCALL *V1)(void *, u32);
typedef void(THISCALL *VF)(void *, float);

extern "C" u32 THISCALL ext_4fb2f0(void *self, void *stream);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }
// stream slots: 0x44 u32, 0x3c u32 (second kind), 0x4c float, 0x60 byte, 0x68 vec3 pointer, 0x70 3x3 matrix pointer
static inline void sD(u8 *s, u32 v) { (*(V1 *)(vt(s) + 0x44))(s, v); }
static inline void sE(u8 *s, u32 v) { (*(V1 *)(vt(s) + 0x3c))(s, v); }
static inline void sF(u8 *s, float v) { (*(VF *)(vt(s) + 0x4c))(s, v); }
static inline void sB(u8 *s, u32 v) { (*(V1 *)(vt(s) + 0x60))(s, v); }
static inline void sV(u8 *s, const u8 *p) { (*(V1 *)(vt(s) + 0x68))(s, (u32)p); }
static inline void sM(u8 *s, const u8 *p) { (*(V1 *)(vt(s) + 0x70))(s, (u32)p); }

// 0x5ca270: thiscall(stream) ret 4, returns al. Gate 0x4fb2f0(this, stream) must return nonzero (else its value is returned); then serialises the fields of this in a fixed order
// to the stream's slots: u32 +0x64 +0x68, floats +0x2f6 +0x2fa, vec3 +0x2fe, bytes +0x30a +0x30b, vec3 +0x30c +0x318 +0x324, floats +0x330..+0x340, matrix +0x344, u32 +0x368 (slot 0x3c),
// matrix +0x36c, vec3 +0x390 +0x39c +0x3a8, matrix +0x3b4, vec3 +0x3d8, matrix +0x3e4, vec3 +0x408, matrix +0x414, vec3 +0x438 +0x444, byte +0x450. Returns 1.
extern "C" u32 THISCALL fn_5ca270(u8 *self, u8 *S) {
  u32 r = ext_4fb2f0(self, S);
  if ((u8)r == 0) return r;
  sD(S, rd32u(self + 0x64));
  sD(S, rd32u(self + 0x68));
  sF(S, rdf(self + 0x2f6));
  sF(S, rdf(self + 0x2fa));
  sV(S, self + 0x2fe);
  sB(S, self[0x30a]);
  sB(S, self[0x30b]);
  sV(S, self + 0x30c);
  sV(S, self + 0x318);
  sV(S, self + 0x324);
  sF(S, rdf(self + 0x330));
  sF(S, rdf(self + 0x334));
  sF(S, rdf(self + 0x338));
  sF(S, rdf(self + 0x33c));
  sF(S, rdf(self + 0x340));
  sM(S, self + 0x344);
  sE(S, rd32u(self + 0x368));
  sM(S, self + 0x36c);
  sV(S, self + 0x390);
  sV(S, self + 0x39c);
  sV(S, self + 0x3a8);
  sM(S, self + 0x3b4);
  sV(S, self + 0x3d8);
  sM(S, self + 0x3e4);
  sV(S, self + 0x408);
  sM(S, self + 0x414);
  sV(S, self + 0x438);
  sV(S, self + 0x444);
  sB(S, self[0x450]);
  return 1;
}
PCREG(5ca270, fn_5ca270);
