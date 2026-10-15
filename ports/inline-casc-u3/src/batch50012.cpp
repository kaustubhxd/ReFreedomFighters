// batch50012.cpp - cascade u3, tier H, batch 50012: 0x4bbe50 (timed value ramp with random re-targeting).
#include "ff.h"

static u32 rd32(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static float rdf(const u8 *p) { return bitsf(rd32(p)); }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static void wf(u8 *p, float f) { u32 v = fbits(f); p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// engine random float through [sys] slot 0x1c0(file 0x693c40, line) -> st0
static float engine_rand(u32 line) {
  u8 *sys = G(u8 *, 0x70039c);
  return vcall<float>(sys, 0x1c0, 0x693c40, line);
}

// 0x4bbe50, thiscall() void (unaligned: byte [+0x78], floats [+0x74], [+0x79]): returns unless dword [sys+0x1a9f] and byte [this+0x78] are set. dt = (float)(sys[0x40] - (int)([+0x74] * 1024.0)) * 1/1024;
// dt <= 0.08 (0x693d20) -> return. [+0x74] = (float)sys[0x40] / 1024. When [+0x70] >= (float)[+0x68] * dt: mode [+0x48] 0: v = ([+0x4c] - A) / [+0x70] * ((float)[+0x64] * dt) + A, mode 1:
// v = A - ([+0x50] - ([+0x4c] - A)) / [+0x70] * ((float)[+0x64] * dt) (A = unaligned float [+0x79]); modes 0 / 1 store clamp(v, 0, 1.0) at [[[+0x44]+0x18]+0x84]; [+0x68]++ in every mode.
// Then (float)[+0x64] * dt >= [+0x54]: [+0x64] = 0; r1 = rand(0x443): [+0x58] < r1 -> [+0x64]++ and return; else [+0x68] = 1, r2 = rand(0x446),
// [+0x70] = (float)(int)((r2 * ([+0x60] - [+0x5c]) + [+0x5c]) / dt) * dt, A = dword [[[+0x44]+0x18]+0x84]; mode 0 -> mode = 1, mode 1 -> mode = 0; [+0x64]++.
static void THISCALL fn4bbe50(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  if (rd32(sys + 0x1a9f) == 0) return;
  if (self[0x78] == 0) return;
  s32 ms = *(s32 *)(sys + 0x40);
  s32 base = _mm_cvttss_si32(_mm_set_ss(rdf(self + 0x74) * 1024.0f));
  float dt = (float)(ms - base) * G(float, 0x6785e4);
  if (G(float, 0x693d20) >= dt) return;
  float T = rdf(self + 0x70);
  wf(self + 0x74, (float)ms * G(float, 0x6785e4));
  float lim = (float)*(s32 *)(self + 0x68) * dt;
  if (!(T < lim)) {
    s32 mode = *(s32 *)(self + 0x48);
    if (mode == 0 || mode == 1) {
      float A = rdf(self + 0x79);
      float v;
      if (mode == 0) {
        v = rdf(self + 0x4c) - A;
        float k = (float)*(s32 *)(self + 0x64) * dt;
        v = v / T;
        v = v * k;
        v = v + A;
      } else {
        float x = rdf(self + 0x4c) - A;
        float y = rdf(self + 0x50) - x;
        float k = (float)*(s32 *)(self + 0x64) * dt;
        y = y / T;
        y = y * k;
        v = A - y;
      }
      float o;
      if (0.0f > v) o = 0.0f;
      else o = (G(float, 0x678858) < v) ? G(float, 0x678858) : v;
      u8 *tgt = *(u8 **)(*(u8 **)(self + 0x44) + 0x18);
      *(float *)(tgt + 0x84) = o;
    }
    (*(s32 *)(self + 0x68))++;
  }
  float e = (float)*(s32 *)(self + 0x64) * dt;
  if (!(e < rdf(self + 0x54))) {
    *(s32 *)(self + 0x64) = 0;
    float r1 = engine_rand(0x443);
    if (!(rdf(self + 0x58) < r1)) {
      float lo = rdf(self + 0x5c);
      *(s32 *)(self + 0x68) = 1;
      float r2 = engine_rand(0x446);
      float w = rdf(self + 0x60) - lo;
      float m = r2 * w + lo;
      m = m / dt;
      s32 q = _mm_cvttss_si32(_mm_set_ss(m));
      wf(self + 0x70, (float)q * dt);
      u8 *tgt = *(u8 **)(*(u8 **)(self + 0x44) + 0x18);
      wr32(self + 0x79, rd32(tgt + 0x84));
      s32 mode = *(s32 *)(self + 0x48);
      if (mode == 1) {
        (*(s32 *)(self + 0x64))++;
        *(s32 *)(self + 0x48) = 0;
        return;
      }
      if (mode == 0) *(s32 *)(self + 0x48) = 1;
    }
  }
  (*(s32 *)(self + 0x64))++;
}
PCREG(4bbe50, fn4bbe50);
