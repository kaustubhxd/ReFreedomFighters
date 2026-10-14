// batch32127.cpp - cascade h2 (): four tier H (float / SSE) functions.
#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);                                  // /GS check
extern "C" void THISCALL ext_4db500(u8 *self, float *out);                        // thiscall ret 4
extern "C" void FASTCALL ext_43e920(void *out, const void *a, const void *b);     // x87 vector subtract
extern "C" u32 THISCALL ext_5c88c0(u8 *self, float *a, u32 b);                    // thiscall ret 8, bool in AL
extern "C" void THISCALL ext_65c530(u8 *self, u8 *a);                             // thiscall (stack argument)
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);                              // thiscall ret 4
typedef u32 (*hook_t)();
typedef u32 (*cd3_t)(u32, u32, u32);

static inline u8 *engTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }

// 0x5c8750, thiscall(p) ret 4, returns AL = (0x5c88c0(...) == 0) (/GS frame): v = p[0..2]; slot 0x8c of [this+0x44] with &v; o = engine table slot 0x58 with [this+0x74]; 0x4db500([o+8], &w) fills w[3];
// u = v - w (0x43e920); r = 0x5c88c0(this, &u, 1); returns r == 0 (EAX kept across the /GS check).
static u32 THISCALL fn5c8750(u8 *self, float *p) {
  float v[3], w[3], u[3];
  v[0] = p[0]; v[1] = p[1]; v[2] = p[2];
  vcall<void>(*(void **)(self + 0x44), 0x8c, (u32)v);
  u8 *o = vcall<u8 *>(engTable(), 0x58, *(u32 *)(self + 0x74));
  ext_4db500(*(u8 **)(o + 8), w);
  ext_43e920(u, v, w);
  u32 r = ext_5c88c0(self, u, 1);
  u32 res = ((u8)r) == 0;
  ext_633654(0);
  return res;
}
PCREG(5c8750, fn5c8750);

// 0x65c690, thiscall(p) ret 4: m = [[p+0xc]+0xc]; o = unaligned [this+0x10051]; k = [m+0x6c] (1 -> 0); 0x65c530(this, m); the float constant [0x6f6318] == 0 or flag 0x80000 of [m+0x48] -> slot 0x1d8 of o with 0;
// s = [m+0x68]; a = [m+0x74]*s (a == 0 -> s); b = [m+0x70]*s; slot 0x154 of o with (b, a, k).
static void THISCALL fn65c690(u8 *self, u8 *p) {
  u8 *m = *(u8 **)(*(u8 **)(p + 0xc) + 0xc);
  u32 o = rd32(self + 0x10051);
  u32 k = *(u32 *)(m + 0x6c);
  if (k == 1) k = 0;
  ext_65c530(self, m);
  if (G(float, 0x6f6318) == 0.0f || (*(u32 *)(m + 0x48) & 0x80000)) vcall<void>((void *)o, 0x1d8, 0u);
  float s = *(float *)(m + 0x68);
  float a = *(float *)(m + 0x74) * s;
  float b = *(float *)(m + 0x70) * s;
  if (a == 0.0f) a = s;
  vcall<void>((void *)o, 0x154, b, a, k);
}
PCREG(65c690, fn65c690);

// 0x4dff10, thiscall no args, returns the vector length (x87 float): x == 0 and y == 0 (ordered) -> 0 untouched; l = (float)sqrt(x*x + y*y) (CRT import); l == 0 -> 0; else inv = 1.0 (0x678858) / l, x *= inv, y *= inv; returns l.
extern "C" double VECTORCALL ext_634d7c(double);
static float THISCALL fn4dff10(float *self) {
  float x = self[0];
  float y = self[1];
  if (x == 0.0f && y == 0.0f) return 0.0f;
  float sq = y * y;
  float xx = x * x;
  sq = sq + xx;
  float l = (float)ext_634d7c((double)sq);
  if (l == 0.0f) return 0.0f;
  float inv = G(float, 0x678858) / l;
  self[0] = x * inv;
  self[1] = y * inv;
  return l;
}
PCREG(4dff10, fn4dff10);

// 0x50ac10, stdcall(p) ret 4: f = float (st0) of engine slot 0x1c4 with (0x69d350, 0xb4); q = 0x5003d0([p+8], 0); byte [q+4] neither 0 nor 2 -> logs through [0x700390] (slot 0x20 with (0x69c8e0, 0x104),
// then its cdecl slot 0x2c with (o, 0x69c6b0, 0x69c938)) and calls the assert hook (int3 when null); then byte [q+4] = 2 and [q] = f in every case.
static void STDCALL fn50ac10(u8 *p) {
  float f = vcall<float>(G(void *, 0x70039c), 0x1c4, 0x69d350u, 0xb4u);
  u8 *q = (u8 *)ext_5003d0(*(u8 **)(p + 8), 0);
  u8 kind = q[4];
  if (kind != 0 && kind != 2) {
    void *g = G(void *, 0x700390);
    u8 *o = vcall<u8 *>(g, 0x20, 0x69c8e0u, 0x104u);
    (*(cd3_t *)(*(u8 **)o + 0x2c))((u32)o, 0x69c6b0, 0x69c938);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  q[4] = 2;
  *(float *)q = f;
}
PCREG(50ac10, fn50ac10);
