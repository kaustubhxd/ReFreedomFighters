// batch51000.cpp - u4 (Sonnet) batch 51000: tier H float/SSE functions
#include "ff.h"

extern "C" void THISCALL ext_4e0d00(float *v, float s);   // vscalar in place (ret 4)

// x87 normalise in place as the exe does (len = fsqrt(x*x+y*y+z*z) in x87, inv = 1/len, components stored as float(c * inv)); returns float(len)
static inline float norm3_x87(float *v) {
  long double x = v[0];
  long double y = v[1];
  long double z = v[2];
  long double len = fsqrt_x87(x * x + y * y + z * z);
  long double inv = (long double)1.0f / len;
  v[0] = (float)((long double)v[0] * inv);
  v[1] = (float)((long double)v[1] * inv);
  v[2] = (float)((long double)v[2] * inv);
  return (float)len;
}

// 0x5c88c0, thiscall(v, flag) ret 8, returns bool: normalises v (if any component != 0), clamps v.z / v.x against limits at this+0x54/0x60 (flag) and this+0x50,
// then scales by the length and clamps the old v.y magnitude (double compare) against this+0x58/0x64 (flag), v.y = +-this[0x58], rescale by this[0x5c] / len
static bool THISCALL fn5c88c0(u8 *self, float *v, u8 flag) {
  bool changed = false;
  if (v[0] != 0.0f || v[1] != 0.0f || v[2] != 0.0f) norm3_x87(v);
  float oldy = v[1];
  float len;
  v[1] = 0.0f;
  if (v[0] != 0.0f || v[2] != 0.0f) len = norm3_x87(v);
  else len = 0.0f;
  float lim = flag ? *(float *)(self + 0x60) : *(float *)(self + 0x54);
  if (lim > v[2]) {
    *(u32 *)(v + 2) = *(u32 *)(self + 0x54);
    u32 b = *(u32 *)(self + 0x50);
    if (0.0f > v[0]) b ^= G(u32, 0x67af40);
    *(u32 *)v = b;
    changed = true;
  }
  ext_4e0d00(v, len);
  float lim2 = flag ? *(float *)(self + 0x64) : *(float *)(self + 0x58);
  __m128d a = _mm_and_pd(_mm_cvtps_pd(_mm_set_ss(oldy)), _mm_loadu_pd((const double *)0x67cd50));
  if (_mm_cvtsd_f64(a) > (double)lim2) {
    u32 t = *(u32 *)(self + 0x58);
    if (0.0f > oldy) t ^= G(u32, 0x67af40);
    float k = *(float *)(self + 0x5c) / len;
    ext_4e0d00(v, k);
    *(u32 *)(v + 1) = t;
    return true;
  }
  v[1] = oldy;
  return changed;
}
PCREG(5c88c0, fn5c88c0);

extern "C" void THISCALL ext_4362e0(void *self);                       // plain thiscall
extern "C" void THISCALL ext_4297a0(void *self, float *a, float *b);  // thiscall ret 8

// 0x429bc0, thiscall plain, /GS: joystick poll. ext_4362e0(this); if byte [this+0xc] && byte [this+0xb1] and device d = unaligned [this+0x71]:
// d->slot 0x64 (stdcall(d)) < 0: [this+0xb1] = 0, on 0x8007001e / 0x8007000c retry d->slot 0x1c (reacquire) until it succeeds ([0xb1] = 1) or fails with another code ([0xb1] = 1) or d is null;
// otherwise d->slot 0x24(0x110, &state) == 0: floats [this+0xd] = lX / K, [this+0x15] = lY / K (K float 0x679548), ext_4297a0(this, this+0xd, this+0x15), [0x11] = lZ / K,
// [0x19] = lRz / K, ext_4297a0(this, this+0x11, this+0x19); if byte [[0x7003a0]+0x74] & 1 swap [0x11] and [0x19]; buttons: for i < [this+0x61]: float [this+0x1d+4i] = (button i != 0);
// if the flag: [this+0x45] = [this+0x49], [this+0x49] = [this+0x41], [this+0x41] = ([this+0x45] != G(float, 0x6785d0)) as float
static void THISCALL fn429bc0(u8 *self) {
  typedef s32(STDCALL * Slot1)(void *);
  typedef s32(STDCALL * SlotState)(void *, u32, void *);
  s32 state[0x110 / 4];
  ext_4362e0(self);
  if (!self[0xc] || !self[0xb1]) return;
  u8 *d = *(u8 **)(self + 0x71);
  if (!d) return;
  s32 r = (*(Slot1 *)(*(u8 **)d + 0x64))(d);
  if (r < 0) {
    self[0xb1] = 0;
    if (r != (s32)0x8007001e && r != (s32)0x8007000c) return;
    for (;;) {
      d = *(u8 **)(self + 0x71);
      if (!d) break;
      r = (*(Slot1 *)(*(u8 **)d + 0x1c))(d);
      if (r == 0) break;
      self[0xb1] = 0;
      if (r == (s32)0x8007001e || r == (s32)0x8007000c) continue;
      break;
    }
    self[0xb1] = 1;
    return;
  }
  d = *(u8 **)(self + 0x71);
  if ((*(SlotState *)(*(u8 **)d + 0x24))(d, 0x110, state) != 0) return;
  float k = G(float, 0x679548);
  float *p0d = (float *)(self + 0xd);
  float *p15 = (float *)(self + 0x15);
  *p0d = (float)state[0] / k;
  *p15 = (float)state[1] / k;
  ext_4297a0(self, p0d, p15);
  float *p11 = (float *)(self + 0x11);
  float *p19 = (float *)(self + 0x19);
  *p11 = (float)state[2] / k;
  *p19 = (float)state[5] / k;
  ext_4297a0(self, p11, p19);
  u8 *g = G(u8 *, 0x7003a0);
  bool flag = g[0x74] & 1;
  if (flag) {
    u32 t = *(u32 *)p11;
    *(u32 *)p11 = *(u32 *)p19;
    *(u32 *)p19 = t;
  }
  const u8 *btn = (const u8 *)state + 0x30;
  for (s32 i = 0; i < *(s32 *)(self + 0x61); i++) {   // the bound is re-read: the loop's own stores reach [this+0x61] at i = 17
    float f = (float)(s32)(btn[i] != 0);
    *(u32 *)(self + 0x1d + 4 * i) = fbits(f);
  }
  g = G(u8 *, 0x7003a0);
  if (g[0x74] & 1) {
    float c = bitsf(*(u32 *)(self + 0x45)) != G(float, 0x6785d0) ? 1.0f : 0.0f;
    *(u32 *)(self + 0x45) = *(u32 *)(self + 0x49);
    *(u32 *)(self + 0x49) = *(u32 *)(self + 0x41);
    *(u32 *)(self + 0x41) = fbits(c);
  }
}
PCREG(429bc0, fn429bc0);

extern "C" void THISCALL ext_44b610(void *o);   // plain thiscall
extern "C" void ext_44b740(void *o);            // cdecl, one arg

// 0x4b46c0, thiscall plain: tf = (float)(s32)((sys[0x40] - [this+0x50]) * 25) * F(0x6785e4), sys = [0x70039c]; o = ((sys+0x9b)->slot 0x60)([this+0x8d]) (thiscall, 1 arg):
// (1) (float)[this+0x68] >= tf and o: [o+0x84] = [this+0x58] * tf; (2) n = [this+0x64] != 0 and tf >= (float)n and o: [o+0x84] = C1 - min'(C1, (tf - n) * [this+0x5c]) (C1 float 0x678858);
// then tf >= (float)([this+0x6c] + n): o2 = lookup, if o2 ext_44b610(o2) and ext_44b740(o2); [this+0x8d] = 0; this->slot 0xa0(); this->slot 0x68(0x10, 0);
// (3) [this+0x70] != 0, m = [this+0x60] * F(0x685270), tf >= m and (float)[this+0x70] + m > tf and o: [o+0x60] = c - [o+0x64], [o+0x64] = c with c = cvttss2si((tf - m) * (float)[this+0x74]);
// (4) [this+0x8d] != 0 and (no object or 0 >= [o+0x70]): this->slot 0xa0(); this->slot 0x68(0x10, 0)
static void THISCALL fn4b46c0(u8 *self) {
  auto get = [&]() -> u8 * {
    u8 *sys = G(u8 *, 0x70039c);
    void *tbl = *(void **)(sys + 0x9b);
    return vcall<u8 *>(tbl, 0x60, *(u32 *)(self + 0x8d));
  };
  u8 *sys = G(u8 *, 0x70039c);
  s32 d = (s32)(*(u32 *)(sys + 0x40) - *(u32 *)(self + 0x50));
  float tf = (float)(s32)((u32)d * 25u) * G(float, 0x6785e4);
  float a = (float)*(s32 *)(self + 0x68);
  if (a >= tf) {
    u8 *o = get();
    if (o) *(float *)(o + 0x84) = *(float *)(self + 0x58) * tf;
  }
  s32 n = *(s32 *)(self + 0x64);
  if (n != 0 && tf >= (float)n) {
    u8 *o = get();
    if (o) {
      float t = (tf - (float)n) * *(float *)(self + 0x5c);
      float c1 = G(float, 0x678858);
      float m = c1 < t ? c1 : t;
      *(float *)(o + 0x84) = c1 - m;
      float y = (float)(s32)(*(u32 *)(self + 0x6c) + (u32)n);
      if (tf >= y) {
        u8 *o2 = get();
        if (o2) {
          ext_44b610(o2);
          ext_44b740(o2);
        }
        *(u32 *)(self + 0x8d) = 0;
        vcall<void>(self, 0xa0);
        vcall<void>(self, 0x68, 0x10u, 0u);
      }
    }
  }
  s32 e = *(s32 *)(self + 0x70);
  if (e != 0) {
    float m = *(float *)(self + 0x60) * G(float, 0x685270);
    if (tf >= m && (float)e + m > tf) {
      u8 *o = get();
      if (o) {
        float t = (tf - *(float *)(self + 0x60) * G(float, 0x685270)) * (float)*(s32 *)(self + 0x74);
        s32 c = _mm_cvttss_si32(_mm_set_ss(t));
        *(u32 *)(o + 0x60) = (u32)c - *(u32 *)(o + 0x64);
        *(u32 *)(o + 0x64) = (u32)c;
      }
    }
  }
  if (*(u32 *)(self + 0x8d) != 0) {
    u8 *o = get();
    if (!o || 0.0f >= *(float *)(o + 0x70)) {
      vcall<void>(self, 0xa0);
      vcall<void>(self, 0x68, 0x10u, 0u);
    }
  }
}
PCREG(4b46c0, fn4b46c0);

extern "C" void THISCALL ext_4dc630(void *o, u32 a, u32 b);   // thiscall ret 8

static inline u32 flags491(u8 *x) {
  u8 *s = *(u8 **)(x + 0x54);
  return s ? *(u32 *)(*(u8 **)(s + 0xc) + 0x23) : 0x200002;
}

// 0x491ee0, thiscall plain, /GS: collects objects from the pointer array [this+4 ..] (count [this+0xcc], re-read each pass) into a local array of 128 (no bound check):
// skip an element with bit mask 0xc00 in [e+0x3c]; flags(e) = [[[e+0x54]+0xc]+0x23] or 0x200002 without [e+0x54]; bit 0x800000: take e if [e+0x68] != 0;
// else bit 0x100000: walk the chain c = [s+8] (s = [e+0x54]), c = next through s->slot 0x2a0(&c): for c with [c+0x68] != 0 and no 0xc00: ensure bits 0x3000000 (ext_4dc630(c, 0x3000000, 0)),
// take c if flags(c) has 0x800000. Then profiler pairs (engine floats [+0x9c7] and [+0x9c3] both != 0: r = slot 0x1c8(0x67a7f8, 0x259) in edx:eax; slot 0x178(eax, edx, 0x68e16c))
// around this->slot 0x10(array, count); the second pair uses line 0x260 and slot 0x17c.
static void THISCALL fn491ee0(u8 *self) {
  u8 *arr[128];
  u32 n = 0;
  if (*(u32 *)(self + 0xcc) != 0) {
    u8 **p = (u8 **)(self + 4);
    u32 i = 0;
    do {
      u8 *e = *p;
      if (!(*(u32 *)(e + 0x3c) & 0xc00)) {
        u32 fl = flags491(e);
        if (fl & 0x800000) {
          if (*(u32 *)(e + 0x68) != 0) arr[n++] = e;
        } else if (fl & 0x100000) {
          u8 *s = *(u8 **)(e + 0x54);
          u8 *cur = *(u8 **)(s + 8);
          if (cur) {
            do {
              if (*(u32 *)(cur + 0x68) != 0) {
                u32 f = *(u32 *)(cur + 0x3c);
                if (!(f & 0xc00)) {
                  if ((f & 0x3000000) != 0x3000000) ext_4dc630(cur, 0x3000000, 0);
                  if (flags491(cur) & 0x800000) arr[n++] = cur;
                }
              }
              vcall<void>(s, 0x2a0, (u32)&cur);
            } while (cur);
          }
        }
      }
      p++;
      i++;
    } while (i != *(u32 *)(self + 0xcc));
  }
  u8 *eng = G(u8 *, 0x70039c);
  if (*(float *)(eng + 0x9c7) != 0.0f && *(float *)(eng + 0x9c3) != 0.0f) {
    u64 t = vcall<u64>(eng, 0x1c8, 0x67a7f8u, 0x259u);
    u8 *eng2 = G(u8 *, 0x70039c);
    vcall<void>(eng2, 0x178, (u32)t, (u32)(t >> 32), 0x68e16cu);
  }
  vcall<void>(self, 0x10, (u32)arr, n);
  eng = G(u8 *, 0x70039c);
  if (*(float *)(eng + 0x9c7) != 0.0f && *(float *)(eng + 0x9c3) != 0.0f) {
    u64 t = vcall<u64>(eng, 0x1c8, 0x67a7f8u, 0x260u);
    u8 *eng2 = G(u8 *, 0x70039c);
    vcall<void>(eng2, 0x17c, (u32)t, (u32)(t >> 32), 0x68e16cu);
  }
}
PCREG(491ee0, fn491ee0);

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 idx);   // thiscall ret 4: returns a pointer to a typed value cell (float at +0, type byte at +4)

// type check macro the exe expands: cell type byte must be 0 or 2, else log (0x700390 slot 0x20(0x69c8e0, 0x104) -> o; o->slot 0x2c(o, 0x69c6b0, 0x69c938), cdecl) and call the assert hook [0x7003b0]
static inline void chk_type(u8 *cell) {
  u8 t = cell[4];
  if (t != 0 && t != 2) {
    typedef void (*Log)(void *, u32, u32);
    void *o = vcall<void *>(G(void *, 0x700390), 0x20, 0x69c8e0u, 0x104u);
    (*(Log *)(*(u8 **)o + 0x2c))(o, 0x69c6b0, 0x69c938);
    typedef void (*Hook)();
    Hook h = G(Hook, 0x7003b0);
    if (h) h();
    else __builtin_debugtrap();
  }
}

// 0x5010f0, thiscall(a) ret 4, /GS: v[3] = floats of three value cells ext_5003d0([a+4], 0 / 1 / 2) (each type-checked); x = float returned (st0) by [this+0xc]->slot 0x198(v);
// cell = ext_5003d0([a+8], 0), type-checked; cell type byte = 2, cell float = x
static void THISCALL fn5010f0(u8 *self, u8 *a) {
  float v[3];
  for (u32 i = 0; i < 3; i++) {
    u8 *cell = ext_5003d0(*(void **)(a + 4), i);
    chk_type(cell);
    v[i] = *(float *)cell;
  }
  float x = vcall<float>(*(void **)(self + 0xc), 0x198, (u32)v);
  u8 *out = ext_5003d0(*(void **)(a + 8), 0);
  chk_type(out);
  out[4] = 2;
  *(float *)out = x;
}
PCREG(5010f0, fn5010f0);

extern "C" void THISCALL ext_461d60(void *self);   // plain thiscall

// 0x466040, thiscall plain, /GS: walks the chain c = [this->slot 0x20()+8], c = next via o->slot 0x50(&c) (o = this->slot 0x20() each pass), ext_4dc630(c, 0, 0x2001d) for each;
// ext_461d60(this); if engine [+0x1a9f] object x: [this+0x147] = x->slot 0x5c(0x685ffc), [this+0x14f] = x->slot 0x5c(0x686004) (x re-read), [this+0x14b] = [this+0x147];
// z = table(engine+0x9b)[0xadc]->slot 0x25c(0x685f44, 0); if null: z = same object->slot 0x294(0x685f44, 0x67f610, 0, 1), five z->slot 0x10c(name, int) calls, z->slot 0x154(),
// ext_4dc630([z+8], 0x800000, 0), z->slot 0x124(1, 0, 0, 0); [[0x7003b8]+0x4ac] = z; z->slot 0x218(this); this->slot 0x358(); r = this->slot 0x3a0(&buf); this->slot 0x398(r);
// [this+0x143] = 2; [this+0x1ca] = buf[1] + F(0x684cf0); this->slot 0x3d4()
static void THISCALL fn466040(u8 *self) {
  float buf[3];
  u8 *o = vcall<u8 *>(self, 0x20);
  u8 *cur = *(u8 **)(o + 8);
  while (cur) {
    ext_4dc630(cur, 0, 0x2001d);
    u8 *o2 = vcall<u8 *>(self, 0x20);
    vcall<void>(o2, 0x50, (u32)&cur);
  }
  ext_461d60(self);
  u8 *sys = G(u8 *, 0x70039c);
  u8 *x = *(u8 **)(sys + 0x1a9f);
  if (x) {
    u32 a = vcall<u32>(x, 0x5c, 0x685ffcu);
    *(u32 *)(self + 0x147) = a;
    sys = G(u8 *, 0x70039c);
    x = *(u8 **)(sys + 0x1a9f);
    u32 b = vcall<u32>(x, 0x5c, 0x686004u);
    *(u32 *)(self + 0x14f) = b;
    *(u32 *)(self + 0x14b) = *(u32 *)(self + 0x147);
    sys = G(u8 *, 0x70039c);
  }
  u8 *y = *(u8 **)(*(u8 **)(sys + 0x9b) + 0xadc);
  u8 *z = vcall<u8 *>(y, 0x25c, 0x685f44u, 0u);
  if (!z) {
    sys = G(u8 *, 0x70039c);
    y = *(u8 **)(*(u8 **)(sys + 0x9b) + 0xadc);
    z = vcall<u8 *>(y, 0x294, 0x685f44u, 0x67f610u, 0u, 1u);
    vcall<void>(z, 0x10c, 0x68600cu, 0xffffffffu);
    vcall<void>(z, 0x10c, 0x686020u, 0xffffffffu);
    vcall<void>(z, 0x10c, 0x686034u, 0x270fu);
    vcall<void>(z, 0x10c, 0x68604cu, 0xffffffffu);
    vcall<void>(z, 0x10c, 0x686060u, 0xffffffffu);
    vcall<void>(z, 0x154);
    ext_4dc630(*(u8 **)(z + 8), 0x800000, 0);
    vcall<void>(z, 0x124, 1u, 0u, 0u, 0u);
  }
  *(u8 **)(G(u8 *, 0x7003b8) + 0x4ac) = z;
  vcall<void>(z, 0x218, (u32)self);
  vcall<void>(self, 0x358);
  u32 r = vcall<u32>(self, 0x3a0, (u32)buf);
  vcall<void>(self, 0x398, r);
  float f = buf[1] + G(float, 0x684cf0);
  self[0x143] = 2;
  *(u32 *)(self + 0x1ca) = fbits(f);
  vcall<void>(self, 0x3d4);
}
PCREG(466040, fn466040);
