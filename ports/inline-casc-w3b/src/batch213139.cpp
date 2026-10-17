#include "ff.h"

typedef u32(THISCALL *V1)(void *, u32);

extern "C" double VECTORCALL ext_634d7c(double x);  // sqrt
extern "C" u32 THISCALL ext_477740(void *self, u32 a, u32 flag);

static inline u32 rd32(const u8 *p) { return *(const u32 *)p; }
static inline float rdf(const u8 *p) { return *(const float *)p; }
static inline void wrf(u8 *p, float v) { *(float *)p = v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }
// entity address from a handle: 0 for a null handle, else [[eng+0x9b]+0x44] + handle
static inline u8 *ent(u32 h) {
  if (h == 0) return 0;
  u8 *eng = G(u8 *, 0x70039c);
  return (u8 *)(rd32((u8 *)rd32(eng + 0x9b) + 0x44) + h);
}
static inline float speed(u8 *e) {
  float y = rdf(e + 0x74);
  float x = rdf(e + 0x70);
  float z = rdf(e + 0x78);
  x = x * x;
  y = y * y;
  z = z * z;
  x = x + y;
  x = x + z;
  return (float)ext_634d7c((double)x);
}

// 0x47b8d0: thiscall(a, flag) ret 8 returning bool. Switches the active entry to a (no-op returning 1 when it already is and flag == 0; 0 when [this + a*4 + 0x49a] is 0), recomputes
// the speed statistics of the tracked entities (slots 3, 4, 5 through this slot 0x5a8: lengths of their velocity vectors into this+0x712 / 0x716 / 0x71a, the larger of the last two
// against the first into this+0x71e), the mean speed of slot 8 and slot 12 (this+0x75d / 0x761 / 0x765) and re-runs 0x477740(this[0x650], 1) while preserving this+0x755.
extern "C" u32 THISCALL fn_47b8d0(u8 *self, u32 a, u32 flag) {
  if (rd32(self + 0x4ae) == a && (u8)flag == 0) return 1;
  if (rd32(self + a * 4 + 0x49a) == 0) return 0;
  *(u32 *)(self + 0x4ae) = a;
  *(u32 *)(self + 0x712) = 0;
  *(u32 *)(self + 0x716) = 0;
  *(u32 *)(self + 0x71a) = 0;
  *(u32 *)(self + 0x71e) = 0;
  u8 *P = (u8 *)(*(V1 *)(vt(self) + 0x5a8))(self, 3);
  if (P != 0) wrf(self + 0x712, speed(ent(rd32(P))));
  P = (u8 *)(*(V1 *)(vt(self) + 0x5a8))(self, 4);
  if (P != 0) wrf(self + 0x716, speed(ent(rd32(P))));
  P = (u8 *)(*(V1 *)(vt(self) + 0x5a8))(self, 5);
  if (P != 0) wrf(self + 0x71a, speed(ent(rd32(P))));
  float m = rdf(self + 0x71a);
  float b = rdf(self + 0x716);
  m = (m > b) ? m : b;
  float x1 = rdf(self + 0x712);
  if (!(m > x1)) m = x1;
  wrf(self + 0x71e, m);
  *(u32 *)(self + 0x75d) = 0x41200000;
  *(u32 *)(self + 0x761) = 0x42c80000;
  P = (u8 *)(*(V1 *)(vt(self) + 0x5a8))(self, 8);
  if (P != 0) {
    u32 h = rd32(P);
    float len = speed(ent(h));
    wrf(self + 0x761, len);
    u8 *E = ent(h);
    float q = (float)(int)rd32(E + 0x6c);
    int dur = (int)rd32(E + 0x64) - (int)rd32(E + 0x60);
    dur = dur + 1;
    q = q * len;
    q = q / (float)dur;
    wrf(self + 0x75d, q);
  }
  *(u32 *)(self + 0x765) = rd32(self + 0x75d);
  P = (u8 *)(*(V1 *)(vt(self) + 0x5a8))(self, 0xc);
  if (P != 0) {
    u32 h = rd32(P);
    float len = speed(ent(h));
    u8 *E = ent(h);
    float q = (float)(int)rd32(E + 0x6c);
    int dur = (int)rd32(E + 0x64) - (int)rd32(E + 0x60);
    dur = dur + 1;
    q = q * len;
    q = q / (float)dur;
    wrf(self + 0x765, q);
  }
  u32 cur = rd32(self + 0x650);
  if (cur != 0) {
    u32 save = rd32(self + 0x755);
    ext_477740(self, cur, 1);
    *(u32 *)(self + 0x755) = save;
  }
  return 1;
}
PCREG(47b8d0, fn_47b8d0);
