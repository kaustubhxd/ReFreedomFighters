#include "ff.h"

typedef void(THISCALL *V1)(void *, u32);
typedef void(THISCALL *V2)(void *, u32, u32);
typedef void(THISCALL *VF)(void *, float);

extern "C" u32 THISCALL ext_515b70(void *self, void *stream);
extern "C" void THISCALL ext_528c80(void *sub, void *stream);
extern "C" void THISCALL ext_5274f0(void *sub, void *stream);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }
// stream slots: 0x3c / 0x44 / 0x64 dword kinds, 0x4c float, 0x60 byte, 0x68 vec3 pointer, 0x10 raw bytes (pointer, count)
static inline void sE(u8 *s, u32 v) { (*(V1 *)(vt(s) + 0x3c))(s, v); }
static inline void sD(u8 *s, u32 v) { (*(V1 *)(vt(s) + 0x44))(s, v); }
static inline void sW(u8 *s, u32 v) { (*(V1 *)(vt(s) + 0x64))(s, v); }
static inline void sF(u8 *s, float v) { (*(VF *)(vt(s) + 0x4c))(s, v); }
static inline void sB(u8 *s, u32 v) { (*(V1 *)(vt(s) + 0x60))(s, v); }
static inline void sV(u8 *s, const u8 *p) { (*(V1 *)(vt(s) + 0x68))(s, (u32)p); }
static inline void sR(u8 *s, const u8 *p) { (*(V2 *)(vt(s) + 0x10))(s, (u32)p, 4); }

// 0x5213f0: thiscall(stream) ret 4, returns al. Gate 0x515b70(this, stream) must return nonzero (else its value is returned); then serialises the fields of this in a fixed order
// (vec3 +0x2d8 +0x2e4, float +0x2f0, raw 4 bytes +0x2f4, float +0x2f8, byte +0x2fc, helper 0x528c80(this+0x2fd, stream), float +0x25cd, dwords +0x25d1..+0x25e1, vec3 +0x25e5 +0x25f1
// +0x25fd, bytes +0x2609..0x260b, dwords +0x260c +0x2610 +0x2614 (slot 0x44), float +0x2618, dword +0x2620 (slot 0x44), vec3 +0x2624 +0x2630, helper 0x5274f0(this+0x263c, stream), floats
// +0x268d +0x2691, dword +0x26e6, byte +0x2706, dword +0x26ea, helper 0x5274f0(this+0x2695, stream)). Returns 1.
extern "C" u32 THISCALL fn_5213f0(u8 *self, u8 *S) {
  u32 r = ext_515b70(self, S);
  if ((u8)r == 0) return r;
  sV(S, self + 0x2d8);
  sV(S, self + 0x2e4);
  sF(S, rdf(self + 0x2f0));
  sR(S, self + 0x2f4);
  sF(S, rdf(self + 0x2f8));
  sB(S, self[0x2fc]);
  ext_528c80(self + 0x2fd, S);
  sF(S, rdf(self + 0x25cd));
  sW(S, rd32u(self + 0x25d1));
  sE(S, rd32u(self + 0x25d5));
  sE(S, rd32u(self + 0x25d9));
  sW(S, rd32u(self + 0x25dd));
  sW(S, rd32u(self + 0x25e1));
  sV(S, self + 0x25e5);
  sV(S, self + 0x25f1);
  sV(S, self + 0x25fd);
  sB(S, self[0x2609]);
  sB(S, self[0x260a]);
  sB(S, self[0x260b]);
  sE(S, rd32u(self + 0x260c));
  sE(S, rd32u(self + 0x2610));
  sD(S, rd32u(self + 0x2614));
  sF(S, rdf(self + 0x2618));
  sD(S, rd32u(self + 0x2620));
  sV(S, self + 0x2624);
  sV(S, self + 0x2630);
  ext_5274f0(self + 0x263c, S);
  sF(S, rdf(self + 0x268d));
  sF(S, rdf(self + 0x2691));
  sE(S, rd32u(self + 0x26e6));
  sB(S, self[0x2706]);
  sE(S, rd32u(self + 0x26ea));
  ext_5274f0(self + 0x2695, S);
  return 1;
}
PCREG(5213f0, fn_5213f0);
