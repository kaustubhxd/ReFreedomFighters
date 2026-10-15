// batch35197.cpp - cascade s5 batch 35197 (tier H): 0x51db60 (GUESS spawn a randomly placed effect: fade value, look-up of an effect object, random direction).
#include "ff.h"

extern "C" u8 THISCALL ext_51c470(u8 *self);                         // al, plain ret
extern "C" void THISCALL ext_517030(u8 *self, u32 a, u32 b);         // ret 8
extern "C" void THISCALL ext_4e0d00(float *v, float s);              // v *= s, ret 4
extern "C" void FASTCALL ext_441940(float *a, float *b);             // plain ret (a += b)
extern "C" void THISCALL ext_516f40(u8 *self, float *v);             // ret 4
extern "C" void THISCALL ext_5168b0(u8 *self);                       // plain ret
extern "C" double VECTORCALL ext_634d70(double);                     // cos
extern "C" double VECTORCALL ext_634d76(double);                     // sin
typedef float(THISCALL *rnd_t)(void *, u32, u32);
typedef u8 *(THISCALL *o1_t)(void *, u32);
typedef u32(THISCALL *g1_t)(void *, u32);
typedef void(THISCALL *p1_t)(void *, float *);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { return bitsf(rd32u(p)); }
static inline void wrf(u8 *p, float f) { wr32u(p, fbits(f)); }

// 0x51db60, thiscall, no args, no return value (stack cookie not reproduced). When byte [[0x7003b8]+0xab8] is set returns. r = engine slot 0x1c0(0x69f8b8, 0x478) (an x87 float); when K1 (0x67a284) > r and 0x51c470(this): f = (float [+0x597] - [0x680a90]) / KC (0x67d164),
// x = f clamped to [0, 1.0 (0x678858)] (NaN kept), [+0x4c1] = 1.0 - x; tab slot 0x58([+0x56a]); id = ([[engine+0x1aa3]+0x1c]) slot 0x74(this+0x562); rec = ([[engine+0x1aa3]+0x18]) slot 0xf8(id); non-null: o = tab slot 0x160(byte rec[2]); non-null: 0x517030(this+0x4ad, [o+0x44], 0x677b5a).
// Then when !(float [+0x597] >= [0x68af28]): P = {[+0x54e], [+0x552] + [0x684cf0], [+0x556]}; r2 = engine slot 0x1c0(0x69f8b8, 0x49b); a = double(r2 * [0x680a60] * [0x67da18]); V = {(float)cos a, 0, (float)sin a}, W = V; W *= 200.0f (0x4e0d00); P += W (0x441940);
// this slot 0x8c(P); this slot 0x90(V); [+0x4da], [+0x4de], [+0x4e2] = P; 0x516f40(this+0x4ad, V); 0x5168b0(this+0x4ad).
static void THISCALL fn51db60(u8 *self) {
  u8 *g = G(u8 *, 0x7003b8);
  if (g[0xab8]) return;
  u8 *eng = G(u8 *, 0x70039c);
  float r = (*(rnd_t **)eng)[0x1c0 / 4](eng, 0x69f8b8, 0x478);
  if (G(float, 0x67a284) > r) {
    if (ext_51c470(self)) {
      float f = rdf(self + 0x597) - G(float, 0x680a90);
      f = f / G(float, 0x67d164);
      float x = (0.0f > f) ? 0.0f : ((G(float, 0x678858) < f) ? G(float, 0x678858) : f);
      u32 key = rd32u(self + 0x56a);
      wrf(self + 0x4c1, G(float, 0x678858) - x);
      eng = G(u8 *, 0x70039c);
      u8 *tab = *(u8 **)(eng + 0x9b);
      (*(g1_t **)tab)[0x58 / 4](tab, key);
      eng = G(u8 *, 0x70039c);
      u8 *E = (u8 *)rd32u(eng + 0x1aa3);
      u8 *F = *(u8 **)(E + 0x1c);
      u32 id = (*(g1_t **)F)[0x74 / 4](F, (u32)(self + 0x562));
      E = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x1aa3);
      u8 *Gg = *(u8 **)(E + 0x18);
      u8 *rec = (*(o1_t **)Gg)[0xf8 / 4](Gg, id);
      if (rec) {
        u8 dl = rec[2];
        eng = G(u8 *, 0x70039c);
        tab = *(u8 **)(eng + 0x9b);
        u8 *o = (*(o1_t **)tab)[0x160 / 4](tab, dl);
        if (o) ext_517030(self + 0x4ad, *(u32 *)(o + 0x44), 0x677b5a);
      }
    }
  }
  if (!(rdf(self + 0x597) >= G(float, 0x68af28))) {
    float P[3], V[3], W[3];
    float p1 = rdf(self + 0x552) + G(float, 0x684cf0);
    P[0] = rdf(self + 0x54e);
    P[2] = rdf(self + 0x556);
    P[1] = p1;
    eng = G(u8 *, 0x70039c);
    float r2 = (*(rnd_t **)eng)[0x1c0 / 4](eng, 0x69f8b8, 0x49b);
    float t = r2 * G(float, 0x680a60);
    t = t * G(float, 0x67da18);
    double a = (double)t;
    float c = (float)ext_634d70(a);
    W[1] = 0;
    W[0] = c;
    float s = (float)ext_634d76(a);
    V[1] = 0;
    W[2] = s;
    V[0] = c;
    V[2] = s;
    ext_4e0d00(W, bitsf(0x43480000));
    ext_441940(P, W);
    (*(p1_t **)self)[0x8c / 4](self, P);
    (*(p1_t **)self)[0x90 / 4](self, V);
    wrf(self + 0x4da, P[0]);
    wrf(self + 0x4de, P[1]);
    wrf(self + 0x4e2, P[2]);
    ext_516f40(self + 0x4ad, V);
    ext_5168b0(self + 0x4ad);
  }
}
PCREG(51db60, fn51db60);
