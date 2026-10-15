// batch32130.cpp - cascade h2 (Sonnet): three tier H (float / SSE) functions.
#include "ff.h"

extern "C" void THISCALL ext_5d92e0(u8 *self, u32 a);                  // thiscall ret 4

static inline u8 *engTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }

// 0x4def50, register ABI (ecx = out, edx = b) with a stack argument a, ret 4: quaternion product out = f(b, a) with the exe's exact operation order (SSE singles), see the code.
static void FASTCALL fn4def50(float *out, float *b, float *a) {
  float x1, x0;
  x1 = b[3] * a[0];
  x0 = b[0] * a[3];
  x1 = x1 + x0;
  x0 = a[2] * b[1];
  x1 = x1 + x0;
  x0 = a[1] * b[2];
  x1 = x1 - x0;
  out[0] = x1;
  x1 = b[3] * a[1];
  x0 = a[2] * b[0];
  x1 = x1 - x0;
  x0 = b[1] * a[3];
  x1 = x1 + x0;
  x0 = b[2] * a[0];
  x1 = x1 + x0;
  out[1] = x1;
  x1 = b[3] * a[2];
  x0 = a[1] * b[0];
  x1 = x1 + x0;
  x0 = b[1] * a[0];
  x1 = x1 - x0;
  x0 = b[2] * a[3];
  x1 = x1 + x0;
  out[2] = x1;
  x0 = b[0] * a[0];
  x1 = b[3] * a[3];
  x1 = x1 - x0;
  x0 = a[1] * b[1];
  x1 = x1 - x0;
  x0 = a[2] * b[2];
  x1 = x1 - x0;
  out[3] = x1;
}
PCREG(4def50, fn4def50);

// 0x449100, thiscall(T, ignored, E, X) ret 0x10: byte [this+0x14] bit 0 clear -> nothing; t = [[[0x70039c]+0x1aa3]+0x18]; slot 0x88 of t with ([[this+8]+0x6c], &buf[18 dwords]); with b9 = buf[9], b7 = buf[7], b14 = buf[14],
// b6 = buf[6], b10 = buf[10]: buf[15..17] = {b9, b7, b14}; slot 0xa0 of T with (E, X, b10, b6, b14); slot 0xa4 of T with (E, X, buf[15], buf[16], buf[17]).
static void THISCALL fn449100(u8 *self, void *T, u32 ign, u32 E, u32 X) {
  float buf[18];
  if (!(self[0x14] & 1)) return;
  u8 *t = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
  vcall<void>(t, 0x88, *(u32 *)(*(u8 **)(self + 8) + 0x6c), (u32)buf);
  float b9 = buf[9], b7 = buf[7], b14 = buf[14], b6 = buf[6], b10 = buf[10];
  buf[15] = b9;
  buf[16] = b7;
  buf[17] = b14;
  vcall<void>(T, 0xa0, E, X, b10, b6, b14);
  vcall<void>(T, 0xa4, E, X, buf[15], buf[16], buf[17]);
}
PCREG(449100, fn449100);

// 0x5d9210, thiscall no args: 0x5d92e0(this, [this+0x44]); slot 0x254 of [this+0x44]; o = engine table slot 0x58 with [this+0x54], o != 0 -> 0x5d92e0(this, o); then k = true when the object g = unaligned [[0x70039c]+0x190f]
// is set and byte [g+0x81] != 0, otherwise a flag byte filled by slot 0x90 of the engine table's slot-0x134 object called with (0x67d9dc, &flag); [this+0x58] = k ? 0.125 (0x67da0c) : 0; [this+0x5c] = 0; [this+0x64] = 1.0f; [this+0x60] = 1.0 (0x678858) - 2*[this+0x58].
static void THISCALL fn5d9210(u8 *self) {
  ext_5d92e0(self, *(u32 *)(self + 0x44));
  vcall<void>(*(void **)(self + 0x44), 0x254);
  u8 *o = vcall<u8 *>(engTable(), 0x58, *(u32 *)(self + 0x54));
  if (o) ext_5d92e0(self, (u32)o);
  u8 *eng = G(u8 *, 0x70039c);
  u32 g = rd32(eng + 0x190f);
  bool k;
  if (g && *(u8 *)(g + 0x81) != 0) {
    k = true;
  } else {
    void *f = vcall<void *>(*(u8 **)(eng + 0x9b), 0x134);
    u8 flag = 0;
    vcall<void>(f, 0x90, 0x67d9dcu, (u32)&flag);
    k = flag != 0;
  }
  float x1 = k ? G(float, 0x67da0c) : 0.0f;
  *(float *)(self + 0x58) = x1;
  x1 = x1 + x1;
  *(u32 *)(self + 0x5c) = 0;
  *(u32 *)(self + 0x64) = 0x3f800000;
  *(float *)(self + 0x60) = G(float, 0x678858) - x1;
}
PCREG(5d9210, fn5d9210);
