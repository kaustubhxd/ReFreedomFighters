// batch600.cpp - area 49 (unclaimed-49), batch 600: ZParticleController::CreateParticle (0x4561c0, 711 bytes).
// thiscall, 4 stack args (id, pos, vel, time), ret 0x10. The controller holds a per-id table (8-byte entries at
// +id*8+0x15 = template handle, +id*8+0x19 = particle slot number) and a particle pool (pointer at +0x81d; 0x94c
// bytes per particle; a free-list of particle indices at +0x25300 with the count at +0x25400).
// The template object (render manager slot 0x58 of the handle +0x15) supplies the emitter fields.
// Every GUESS is marked GUESS. The exe's odd float tests are kept literal (see the comments).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef long double(THISCALL *vRand)(void *self, const char *file, u32 line);
typedef u32(THISCALL *vU1)(void *self, u32 a);
extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);   // PSVECSubtract: out = a - b (b on stack)
extern "C" void FASTCALL ext_4e0d00(float *v, float s);                             // vscalar (s on stack)

static const u32 kPool = 0x81d;

// 0x4561c0 CreateParticle(id, pos, vel, time)
static void THISCALL createParticle(u8 *self, u32 id, const float *pos, const float *vel, u32 time) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *rm = *(u8 **)(sys + 0x9b);
  u8 *tmpl = (u8 *)((vU1)VT(rm, 0x58))(rm, *(u32 *)(self + id * 8 + 0x15));
  u32 slot = *(u32 *)(self + id * 8 + 0x19);
  u8 *pool = *(u8 **)(self + kPool);
  u8 *p = 0;
  if (slot) {
    u8 *cand = pool - 0x94c + slot * 0x94c;
    if (cand && *(u32 *)(cand + 4) != 0x40) {
      p = cand;   // reuse the particle that is not in state 0x40
      goto tail;
    }
  }
  {
    u32 *cnt = (u32 *)(pool + 0x25400);
    if (*cnt == 0)
      return;
    (*cnt)--;
    u32 fi = *(u32 *)(pool + 0x25300 + *cnt * 4);   // free-list entry for the new count
    p = pool + fi * 0x94c;
    *(u32 *)(p + 4) = 0;
    *(u32 *)(p + 0) = *(u32 *)(self + id * 8 + 0x19);
    *(u32 *)(self + id * 8 + 0x19) = fi + 1;       // new slot number (1-based)
    *(u32 *)(p + 0x910) = (u32)(p + 0xc);
    *(u32 *)(p + 0x90c) = 0;
    *(u32 *)(p + 0x914) = 0;
    *(u32 *)(p + 0x918) = *(u32 *)(tmpl + 0x28);
    *(u32 *)(p + 0x91c) = *(u32 *)(tmpl + 0x30);
    *(u32 *)(p + 0x920) = *(u32 *)(tmpl + 0x34);
    *(u32 *)(p + 0x924) = *(u32 *)(tmpl + 0x38);
    *(u32 *)(p + 0x928) = *(u32 *)(tmpl + 0x3c);
    *(u32 *)(p + 0x92c) = *(u32 *)(tmpl + 0x40);
    *(u32 *)(p + 0x930) = *(u32 *)(tmpl + 0x44);
    *(u32 *)(p + 0x934) = *(u32 *)(tmpl + 0x24);
    *(u32 *)(p + 0x938) = *(u32 *)(tmpl + 0xe1);
    *(u32 *)(p + 0x93c) = *(u32 *)(tmpl + 0xe5);
    *(u32 *)(p + 0x940) = *(u32 *)(tmpl + 0xe9);
    *(u32 *)(p + 0x944) = *(u32 *)(tmpl + 0xdd);
    *(u32 *)(p + 0x948) = (u32)(tmpl + 0x5d);
  }
tail: {
    u32 cnt = *(u32 *)(p + 4);
    *(u32 *)(p + 8) = 0;
    u8 *st = p + (cnt * 9 + 3) * 4;               // state block pointer (GUESS: the particle's sub-record)
    *(u32 *)(p + 4) = cnt + 1;
    u8 par = (u8)((cnt + 1) & 1);
    float T24 = *(float *)(tmpl + 0x24);
    float T28 = *(float *)(tmpl + 0x28);
    float T2c = *(float *)(tmpl + 0x2c);
    long double rv = ((vRand)VT(sys, 0x1c0))(sys, (const char *)0x682d18, 0x235);
    float r = (float)rv;
    float v1 = (1.0f - r * T2c) * T28;
    // exe: ucomiss v1, 0; lahf; test ah,0x44; jp  -> the jp is parity of (ZF|PF), so the store of T28 happens only
    // when v1 == 0 and ordered (ZF=1, PF=0). Otherwise v stays v1.
    float v = v1;
    if (v1 == 0.0f)
      v = T28;
    float ang = 0.0f;
    if (tmpl[0x48]) {
      long double x = ((vRand)VT(sys, 0x1c0))(sys, (const char *)0x682d18, 0x237);
      ang = (float)((x + x) * 3.1415927410125732L);
    }
    int off = (int)(v * -1024.0f);
    u32 t = time - (u32)off;
    u32 *sb = (u32 *)st;
    float *ss = (float *)st;
    float *out = (float *)(st + 0xc);
    float *tv = (float *)(tmpl + 0xe1);
    (void)sb;
    ext_43e920(out, tv, vel);                   // out = T+0xe1 - vel
    ext_4e0d00(out, 1.0f / T24);                // out *= 1 / T24
    ext_43e920(ss, pos, out);                   // st = pos - out
    ss[6] = (float)(int)time * 0.0009765625f;   // +0x18 (time / 1024 as float)
    ss[7] = (float)(int)t * 0.0009765625f;      // +0x1c
    ss[8] = ang;                                // +0x20
    u32 bits = *(u32 *)(st + 0x1c);
    bits = (bits & 0xfffffffeu) | (u32)par;
    *(u32 *)(st + 0x1c) = bits;
  }
}
PCREG(4561c0, createParticle);
