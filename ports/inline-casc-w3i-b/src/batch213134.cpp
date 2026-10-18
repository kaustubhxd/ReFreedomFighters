#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V4)(void *, u32, u32, u32, u32);

extern "C" long long STDCALL ext_634340(long long a, long long b);  // _allmul
extern "C" long long STDCALL ext_634290(long long a, long long b);  // _alldiv
extern "C" long long STDCALL ext_634380(long long a, long long b);  // _allrem
extern "C" long long VECTORCALL ext_63392e(float x);                 // _ftol2_sse
extern "C" double VECTORCALL ext_633c60(u32 lo, u32 hi);             // _ltod3
extern "C" void THISCALL ext_4690b0(void *p);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline double u32d(u32 v) { return (double)(int)v + ((int)v < 0 ? 4294967296.0 : 0.0); }

// 0x4a4ba0: thiscall(), void. Asks the helper object H = [[[0x70039c]+0x1aa3]+0x18] (slot 0xd4(id, &o1, &o2, &o3)) for three counters of the object's timeline; when it reports
// nothing it calls this slot 0x58. Otherwise (o3 != 1) the elapsed fixed-point time S = (clock - this[0x56]) * (int64)this_f[0x5a] + (o1 << 10) is compared (signed 64 bit) against
// ((o3 - 1) * o2 + o1) << 10: if it passed (and this[0x63] is clear) the object is finished (slot 0x210 / 0x20 / 0x28 / this slot 0x68 by the flags this[0x60..0x62]); else the position
// ((S - o1) / o2) % ((o3 - 1) << 10) is converted to a float, scaled and stored in this[0x4a], and H slot 0xd8 is told.
extern "C" void THISCALL fn_4a4ba0(u8 *self) {
  int o1, o2, o3;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *X = (u8 *)rd32u(self + 0x44);
  u32 id = rd32u((u8 *)rd32u(X + 8) + 0x6c);
  u8 *H = (u8 *)rd32u((u8 *)rd32u(eng + 0x1aa3) + 0x18);
  u8 ok = (u8)(*(V4 *)(vt(H) + 0xd4))(H, id, (u32)&o1, (u32)&o2, (u32)&o3);
  if (!ok) {
    (*(V0 *)(vt(self) + 0x58))(self);
    return;
  }
  if (o3 == 1) return;
  u32 m1 = (u32)o3 - 1;
  u32 ebx = m1 * (u32)o2 + (u32)o1;
  long long ft = ext_63392e(rdf(self + 0x5a));
  int clock = (self[0x65] != 0) ? (int)rd32u(G(u8 *, 0x70039c) + 0x30) : (int)rd32u(G(u8 *, 0x70039c) + 0x40);
  int diff = (int)((u32)clock - rd32u(self + 0x56));
  long long prod = ext_634340((long long)diff, ft);
  unsigned long long S = (unsigned long long)prod + ((unsigned long long)(u32)o1 << 10);
  bool finished = false;
  if (self[0x63] == 0) {
    unsigned long long Xv = (unsigned long long)ebx << 10;
    finished = (long long)S > (long long)Xv;
  }
  if (finished) {
    ext_4690b0((void *)rd32u((u8 *)rd32u(self + 0x44) + 8));
    if (self[0x60] != 0) {
      if (self[0x61] != 0) {
        u8 *Xo = (u8 *)rd32u(self + 0x44);
        u8 *W = (u8 *)(*(V0 *)(vt(Xo) + 0x20))(Xo);
        if (rd32u(W + 0x4c) == 1) {
          Xo = (u8 *)rd32u(self + 0x44);
          W = (u8 *)(*(V0 *)(vt(Xo) + 0x20))(Xo);
          if (W == 0) return;
          (*(V1 *)(vt(W) + 0x210))(W, 1);
          return;
        }
      }
      u8 *Xo = (u8 *)rd32u(self + 0x44);
      if (self[0x60] == 0) return;
      if (Xo == 0) return;
      (*(V1 *)(vt(Xo) + 0x210))(Xo, 1);
      return;
    }
    if (self[0x62] != 0) {
      u8 *Xo = (u8 *)rd32u(self + 0x44);
      (*(V0 *)(vt(Xo) + 0x28))(Xo);
      return;
    }
    (*(V2 *)(vt(self) + 0x68))(self, 0x10, 0);
    return;
  }
  long long num = (long long)(S - (unsigned long long)(u32)o1);
  long long q = ext_634290(num, (long long)(unsigned long long)(u32)o2);
  long long r = ext_634380(q, (long long)(unsigned long long)(m1 << 10));
  double d = ext_633c60((u32)r, (u32)((unsigned long long)r >> 32));
  float f = (float)d;
  f = f * G(float, 0x6785e4);
  f = f * (float)u32d((u32)o2);
  f = f + (float)u32d((u32)o1);
  __builtin_memcpy(self + 0x4a, &f, 4);
  u8 *H2 = (u8 *)rd32u((u8 *)rd32u(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
  u8 *Xo = (u8 *)rd32u(self + 0x44);
  u32 fb;
  __builtin_memcpy(&fb, &f, 4);
  (*(V2 *)(vt(H2) + 0xd8))(H2, rd32u(Xo + 8), fb);
}
PCREG(4a4ba0, fn_4a4ba0);
