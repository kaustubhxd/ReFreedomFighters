// batch246006.cpp - Sonnet-w4d, tier 6/7 hand ports (run 6).
#include "ff.h"
#include <emmintrin.h>
#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)
typedef u32(THISCALL *W6T2)(u32, u32, u32);
typedef u32(THISCALL *W6T1)(u32, u32);
typedef u32(THISCALL *W6T3)(u32, u32, u32, u32);
typedef u32(*W6C3)(u32, u32, u32);
extern "C" u32 THISCALL ext_59dce0_w6(u32, u32) __asm__("ext_59dce0");
extern "C" u32 THISCALL ext_4cbec0_w6(u32) __asm__("ext_4cbec0");
static inline u32 w6ld(u32 a) { u32 v; __builtin_memcpy(&v, (void *)a, 4); return v; }
static inline void w6st(u32 a, u32 v) { __builtin_memcpy((void *)a, &v, 4); }

// 0x58b780: thiscall(obj) ret 4 (SEH 0x66b77b, state 0 only in the found path after obj vslot 0x1d8). The table at this+0xa1a
// (count at the unaligned this+0xa16, 0x30-byte entries) is searched for obj in the first dword. Found: logs through G[0x700390]
// vslot 0x20(0x6ac6d0, 0x577) -> vslot 0x2c cdecl(logger, 0x6aca24, text of obj vslot 0x1d8(&tmp, 1)); tmp destroyed (0x4cbec0).
// Not found: appends an entry {obj, const 0x6ad240[0..3], 0, 0, float (this[0x417]&0x400 ? [0x678858] : 0), 4 uninitialised dwords},
// count++, then (this[0xee3]) obj vslot 0x128(word this[0x7ea], &int(cvttss2si of the float), 0) and 0x59dce0(obj; this[0x64f]).
// The 4 uninitialised stack dwords of the entry are written as 0xcccccccc (the harness fills the stack below the arguments with 0xcc).
extern "C" void THISCALL GUESS_58b780(u32 self, u32 obj) {
  SEH_ENTER(0x66b77b);
  u32 count = w6ld(self + 0xa16);
  u32 edx = self + 0xa1a;
  u32 end = self + count * 0x30 + 0xa1a;
  bool found = false;
  if (edx != end) {
    do {
      if (*(u32 *)edx == obj) { found = true; break; }
      edx += 0x30;
    } while (edx != end);
  }
  if (found) {
    u32 lg = *(u32 *)0x700390;
    u32 edi = ((W6T2)*(u32 *)(*(u32 *)lg + 0x20))(lg, 0x6ac6d0, 0x577);
    u8 S[0x90] __attribute__((aligned(4)));
    u32 w = ((W6T2)*(u32 *)(*(u32 *)obj + 0x1d8))(obj, (u32)S, 1);
    reg.state = 0;
    u32 txt = *(u32 *)w;
    ((W6C3)*(u32 *)(*(u32 *)edi + 0x2c))(edi, 0x6aca24, txt);
    ext_4cbec0_w6((u32)S);
  } else {
    u32 flag = w6ld(self + 0x417) & 0x400;
    float f = 0.0f;
    if (flag) f = *(float *)0x678858;
    s32 iv = _mm_cvttss_si32(_mm_set_ss(f));
    u32 e[12];
    e[0] = obj;
    e[1] = *(u32 *)0x6ad240;
    e[2] = *(u32 *)0x6ad244;
    e[3] = *(u32 *)0x6ad248;
    e[4] = *(u32 *)0x6ad24c;
    e[5] = 0;
    e[6] = 0;
    e[7] = fbits(f);
    e[8] = e[9] = e[10] = e[11] = 0xccccccccu;
    u32 dst = self + count * 0x30 + 0xa1a;
    for (int i = 0; i < 12; i++) w6st(dst + 4 * i, e[i]);
    w6st(self + 0xa16, w6ld(self + 0xa16) + 1);
    if (*(u8 *)(self + 0xee3) != 0) {
      u32 iloc = (u32)iv;
      ((W6T3)*(u32 *)(*(u32 *)obj + 0x128))(obj, *(u16 *)(self + 0x7ea), (u32)&iloc, 0);
    }
    ext_59dce0_w6(obj, w6ld(self + 0x64f));
  }
  SEH_LEAVE();
}
PCREG(58b780, GUESS_58b780);

// ---------------------------------------------------------------- 0x4e18e0
extern "C" u32 THISCALL ext_4e1590_w6(u32) __asm__("ext_4e1590");
extern "C" u32 THISCALL GUESS_4e18e0(u32 self, u32 A, u32 B, u32 C, u32 a4, u32 a5);
static inline void w6log(u32 line) {
  u32 lg = *(u32 *)0x700390;
  u32 x = ((W6T2)*(u32 *)(*(u32 *)lg + 0x20))(lg, 0x697114, line);
  ((u32(*)(u32, u32))*(u32 *)(*(u32 *)x + 0x2c))(x, 0x697138);
}

// 0x4e18e0: thiscall(A, B, C, -, flag) ret 0x14 -> start pointer this[0xc]. Bytecode walker over the stream at this[0xc] (this[8] =
// cursor) until a 0xff byte; op = byte & 0x3f. op 8: relocate [p+1] (flag ? only when negative : always): index&0x7fffffff, 0 -> keep,
// > B -> log (line 0xb6) and zero, else A[idx-1]; op 9: same for the (size/4-1) dwords after the size dword (log line 0xce); op 10:
// [p+1] = C[[p+1]] when C and the index are non-zero; op 12 (size > 4): recurse on the nested stream at p+5 with a local object.
// Advance: ops 1 -> 9 bytes, 2,3,8,10,11 -> 5, 4,5 -> 1 + strlen + 1 (incl. NUL), 7,9,12 -> 1 + dword, others 1.
extern "C" u32 THISCALL GUESS_4e18e0(u32 self, u32 A, u32 B, u32 C, u32 a4, u32 a5) {
  (void)a4;
  u32 p = w6ld(self + 0xc);
  bool flag = (u8)a5 != 0;
  for (;;) {
    w6st(self + 8, p);
    u8 b = *(u8 *)p;
    if (b == 0xff) break;
    u32 op = b & 0x3f;
    switch (op) {
      case 12:
        if ((s32)w6ld(p + 1) > 4) {
          u32 loc[4];
          loc[0] = 0x6970f4;
          loc[1] = (w6ld(p + 1) & 0xffffff) - 4;
          loc[2] = p + 5;
          loc[3] = p + 5;
          GUESS_4e18e0((u32)loc, A, B, C, 0, 0);
        }
        break;
      case 10:
        if (C != 0) {
          u32 idx = w6ld(p + 1);
          if (idx != 0) w6st(p + 1, *(u32 *)(C + idx * 4));
        }
        break;
      case 8: {
        u32 v = w6ld(p + 1);
        if (flag && (s32)v >= 0) break;
        v &= 0x7fffffff;
        if (v == 0) break;
        if (v > B) {
          w6log(0xb6);
          w6st(p + 1, 0);
        } else {
          w6st(p + 1, *(u32 *)(A + v * 4 - 4));
        }
        break;
      }
      case 9: {
        u32 n = ext_4e1590_w6(self);
        u32 edi = (n >> 2) - 1;
        u32 q = p + 5;
        if (edi != 0) {
          do {
            u32 v = w6ld(q);
            if (!(flag && (s32)v >= 0)) {
              v &= 0x7fffffff;
              if (v != 0) {
                if (v > B) {
                  w6log(0xce);
                  w6st(q, 0);
                } else {
                  w6st(q, *(u32 *)(A + v * 4 - 4));
                }
              }
            }
            q += 4;
            edi--;
          } while (edi != 0);
        }
        break;
      }
      default:
        break;
    }
    u32 ecx;
    switch (*(u8 *)p == 0xff ? 0 : (*(u8 *)p & 0x3f)) {
      case 1: ecx = 8; break;
      case 2: case 3: case 8: case 10: case 11: ecx = 4; break;
      case 4: case 5: {
        const u8 *s = (const u8 *)(p + 1);
        u32 l = 0;
        while (s[l]) l++;
        ecx = l + 1;
        break;
      }
      case 7: case 9: case 12: ecx = w6ld(p + 1); break;
      default: ecx = 0; break;
    }
    p = p + ecx + 1;
  }
  w6st(self + 8, w6ld(self + 0xc));
  return w6ld(self + 0xc);
}
PCREG(4e18e0, GUESS_4e18e0);

// ---------------------------------------------------------------- 0x43a440
extern "C" u32 THISCALL ext_43ac30_w6(u32) __asm__("ext_43ac30");
extern "C" u32 THISCALL ext_435eb0_w6(u32, u32) __asm__("ext_435eb0");
extern "C" u32 THISCALL ext_439230_w6(u32, u32) __asm__("ext_439230");
static inline u32 w6cvt(float x) { return (u32)_mm_cvttss_si32(_mm_set_ss(x)); }
static inline float w6negf(float x) { return bitsf(fbits(x) ^ 0x80000000u); }
static inline float w6cnt(u32 g) { return (float)(s32)w6ld(g + 0x9e3); }

// 0x43a440: thiscall(), void. Writes a 0-/0x7f-/signed-byte record for the audio/controller slot into the byte buffer this[0x131c]
// at the offset taken from the table entry of 0x6e49c0 (0x439230(0x6e49c0) -> [entry]). If [0x7003a0] is null: returns. Calls 0x43ac30(this).
// G = [0x70039c]. G[0x6d]==0: (tail jump to 0x43a5e0) the record comes from G's byte flags at 0x13fc/0x1401/0x1406 (>= 0x80 -> 0x7f)
// and the float this[0x132c] - G[0x9ef] split into +5/+6 bytes (divided by (float)G[0x9e3]), this[0x132c] = G[0x9ef], using the table
// at 0x6e48b8 directly (key = 0x6e49c0, 16-byte entries). Otherwise the record comes from the object returned by
// [0x7003a0]->0x435eb0(0) (bytes at +0xc/+0xd/+0xe, floats at +8 (-> +5/+6), +4 (-> +7/+8) and +0 (-> +9/+0xa)).
extern "C" void THISCALL GUESS_43a440(u32 self) {
  if (*(u32 *)0x7003a0 == 0) return;
  ext_43ac30_w6(self);
  u32 g = *(u32 *)0x70039c;
  if (*(u8 *)(g + 0x6d) == 0) {
    u32 key = *(u32 *)0x6e48c0;
    u32 idx = 0;
    u32 ent = 0;
    if (key != 0) {
      for (;;) {
        if (key == 0x6e49c0) { ent = idx * 16 + 0x6e48b8; break; }
        idx++;
        key = *(u32 *)(idx * 16 + 0x6e48c0);
        if (key == 0) break;
      }
    }
    u32 off = *(u32 *)ent;  // faults on the null entry exactly like the exe
    g = *(u32 *)0x70039c;
    u8 *b = (u8 *)(off + *(u32 *)(self + 0x131c));
    b[0] = *(u8 *)(g + 0x13fc) >= 0x80 ? 0x7f : 0;
    b = (u8 *)(off + *(u32 *)(self + 0x131c));
    b[1] = *(u8 *)(g + 0x1401) >= 0x80 ? 0x7f : 0;
    b = (u8 *)(off + *(u32 *)(self + 0x131c));
    b[2] = *(u8 *)(g + 0x1406) >= 0x80 ? 0x7f : 0;
    b = (u8 *)(off + *(u32 *)(self + 0x131c));
    b[5] = 0;
    b = (u8 *)(off + *(u32 *)(self + 0x131c));
    b[6] = 0;
    float x = *(float *)(self + 0x132c) - bitsf(w6ld(g + 0x9ef));
    if (x > *(float *)0x678858) {
      float q = x / w6cnt(g);
      b = (u8 *)(off + *(u32 *)(self + 0x131c));
      b[6] = (u8)w6cvt(q);
      w6st(self + 0x132c, w6ld(*(u32 *)0x70039c + 0x9ef));
      return;
    }
    if (*(float *)0x67af2c > x) {
      float q = x / w6cnt(g);
      b = (u8 *)(off + *(u32 *)(self + 0x131c));
      b[5] = (u8)w6cvt(w6negf(q));
      g = *(u32 *)0x70039c;
    }
    w6st(self + 0x132c, w6ld(g + 0x9ef));
    return;
  }
  u32 rec = ext_435eb0_w6(*(u32 *)0x7003a0, 0);
  if (rec == 0) return;
  u32 ent = ext_439230_w6(self, 0x6e49c0);
  u32 off = *(u32 *)ent;
  u8 *b = (u8 *)(off + *(u32 *)(self + 0x131c));
  b[0] = *(u8 *)(rec + 0xc) ? 0x7f : 0;
  b = (u8 *)(off + *(u32 *)(self + 0x131c));
  b[1] = *(u8 *)(rec + 0xd) ? 0x7f : 0;
  b = (u8 *)(off + *(u32 *)(self + 0x131c));
  b[2] = *(u8 *)(rec + 0xe) ? 0x7f : 0;
  b = (u8 *)(off + *(u32 *)(self + 0x131c));
  b[5] = 0;
  b = (u8 *)(off + *(u32 *)(self + 0x131c));
  b[6] = 0;
  float f8 = *(float *)(rec + 8);
  g = *(u32 *)0x70039c;
  if (f8 > 0.0f) {
    float q = f8 / w6cnt(g);
    b = (u8 *)(off + *(u32 *)(self + 0x131c));
    b[5] = (u8)w6cvt(q);
  } else if (0.0f > f8) {
    float q = f8 / w6cnt(g);
    b = (u8 *)(off + *(u32 *)(self + 0x131c));
    b[6] = (u8)w6cvt(w6negf(q));
  }
  float f4 = *(float *)(rec + 4);
  b = (u8 *)(off + *(u32 *)(self + 0x131c));
  b[7] = f4 > *(float *)0x679540 ? (u8)w6cvt(f4) : 0;
  b = (u8 *)(off + *(u32 *)(self + 0x131c));
  b[8] = *(float *)0x67af28 > f4 ? (u8)w6cvt(f4) : 0;
  float f0 = *(float *)rec;
  b = (u8 *)(off + *(u32 *)(self + 0x131c));
  b[9] = f0 > *(float *)0x679540 ? (u8)w6cvt(f0) : 0;
  b = (u8 *)(off + *(u32 *)(self + 0x131c));
  b[10] = *(float *)0x67af28 > f0 ? (u8)w6cvt(f0) : 0;
}
PCREG(43a440, GUESS_43a440);

// ---------------------------------------------------------------- 0x55a170
extern "C" u32 THISCALL ext_5003d0_w6(u32, u32) __asm__("ext_5003d0");
extern "C" u32 FASTCALL ext_43e920_w6(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 THISCALL ext_4e0d00_w6(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 FASTCALL ext_441940_w6(u32, u32) __asm__("ext_441940");
extern "C" double VECTORCALL ext_634d7c_w6(double) __asm__("ext_634d7c");
typedef u32(THISCALL *W6T2b)(u32, u32, u32);
static inline float w6ldf(u8 *a) { float f; __builtin_memcpy(&f, a, 4); return f; }
static inline void w6stf(u8 *a, float f) { __builtin_memcpy(a, &f, 4); }

// Reports through logger [0x700390] (vslot 0x20(0x69c8e0, 0x104) -> X, X vslot 0x2c cdecl(X, 0x69c6b0, 0x69c938)) and then the
// fatal pointer [0x7003b0] (int3 when null).
static inline void w6fatal() {
  u32 lg = *(u32 *)0x700390;
  u32 x = ((W6T2b)*(u32 *)(*(u32 *)lg + 0x20))(lg, 0x69c8e0, 0x104);
  ((u32(*)(u32, u32, u32))*(u32 *)(*(u32 *)x + 0x2c))(x, 0x69c6b0, 0x69c938);
  u32 f = *(u32 *)0x7003b0;
  if (f) ((void (*)())f)();
  else asm volatile("int3");
}
static inline void w6setslot(u32 ent, float v) {
  u8 t = *(u8 *)(ent + 4);
  if (t != 0 && t != 2) w6fatal();
  *(u8 *)(ent + 4) = 2;
  w6stf((u8 *)ent, v);
}

// 0x55a170: thiscall(src) ret 4, void. Reads 3 floats of src[4] (0x5003d0(i)) into a vector A, asks this[0x1c] vslot 0x57c(out, tmp) to fill
// the 3-float tmp, 0x43e920(res, tmp, A) -> res; len = sqrt(res.x^2 + 0 + res.z^2) (CRT 0x634d7c); if 0 < len < 750.0: res *= 1/len,
// res *= (750.0 - len) (0x4e0d00 twice), tmp += res (0x441940), tmp.y += 35.0. Writes tmp.x/y/z into the three entries of src[8]
// (0x5003d0(0..2): type byte must be 0 or 2, else logged + fatal; set to 2, float at +0). Mirrors the exe frame (F+k = esp+k).
extern "C" void THISCALL GUESS_55a170(u32 self, u32 src) {
  u8 F[0x60] __attribute__((aligned(8)));
  u32 e;
  e = ext_5003d0_w6(*(u32 *)(src + 4), 0); w6stf(F + 0x04, *(float *)e);
  e = ext_5003d0_w6(*(u32 *)(src + 4), 1); w6stf(F + 0x08, *(float *)e);
  e = ext_5003d0_w6(*(u32 *)(src + 4), 2); w6stf(F + 0x0c, *(float *)e);
  u32 obj = *(u32 *)(self + 0x1c);
  ((W6T2b)*(u32 *)(*(u32 *)obj + 0x57c))(obj, (u32)(F + 0x28), (u32)(F + 0x10));
  ext_43e920_w6((u32)(F + 0x1c), (u32)(F + 0x10), (u32)(F + 0x04));
  float x = w6ldf(F + 0x1c);
  x = x * x;
  w6stf(F + 0x20, 0.0f);
  x = x + 0.0f;
  float z = w6ldf(F + 0x24);
  z = z * z;
  x = x + z;
  float len = (float)ext_634d7c_w6((double)x);
  w6stf(F + 0x00, len);
  if (len > 0.0f && *(float *)0x6a60b0 > len) {
    float inv = *(float *)0x678858 / len;
    ext_4e0d00_w6((u32)(F + 0x1c), fbits(inv));
    float d = *(float *)0x6a60b0 - w6ldf(F + 0x00);
    ext_4e0d00_w6((u32)(F + 0x1c), fbits(d));
    ext_441940_w6((u32)(F + 0x10), (u32)(F + 0x1c));
    float y = w6ldf(F + 0x14) + *(float *)0x6a60a4;
    w6stf(F + 0x14, y);
  }
  w6stf(F + 0x00, w6ldf(F + 0x10));
  w6setslot(ext_5003d0_w6(*(u32 *)(src + 8), 0), w6ldf(F + 0x00));
  w6stf(F + 0x00, w6ldf(F + 0x14));
  w6setslot(ext_5003d0_w6(*(u32 *)(src + 8), 1), w6ldf(F + 0x00));
  w6stf(F + 0x00, w6ldf(F + 0x18));
  w6setslot(ext_5003d0_w6(*(u32 *)(src + 8), 2), w6ldf(F + 0x00));
}
PCREG(55a170, GUESS_55a170);

// ---------------------------------------------------------------- 0x55cc30
extern "C" u32 FASTCALL ext_43e960_w6(u32, u32) __asm__("ext_43e960");
extern "C" u32 THISCALL ext_4e0d80_w6(u32, u32) __asm__("ext_4e0d80");
extern "C" u32 THISCALL ext_5002f0_w6(u32, u32) __asm__("ext_5002f0");
typedef u32(THISCALL *W6V0)(u32);
typedef u32(THISCALL *W6V3)(u32, u32, u32, u32);
typedef u32(THISCALL *W6V6)(u32, u32, u32, u32, u32, u32, u32);

// 0x55cc30: thiscall(src) ret 4, void (esp-based frame mirrored by F: F+k = esp+k of the exe after its prologue). entry = src[4]->0x5003d0(0);
// esi = *entry. esi < 0: logs (logger [0x700390] vslot 0x20(0x6a5eb0, 0x4a0) -> X; Y = W->vslot 0x20() with W = this[0x1c]; text Y[4] or
// 0x67c8e8; X vslot 0x2c cdecl(X, 0x6a5fb8, text)), W->vslot 0x354(0, 0) and 0x5002f0(src[8]->0x5003d0(0), 0). Otherwise: W vslot
// 0x57c(F+0x24, F+0x18), copy 12 bytes F+0x18 -> F+0xc, W vslot 0x620(F+0x18, 1, 1), W vslot 0x578(F+0x24, F+0x18), 0x43e960(F+0xc, F+0x18),
// len = sqrt(y^2 + x^2 + z^2); len > 16.0 (0x6a60a0): 0x4e0d80(F+0xc, 16.0f); P = W[0x1c]: P[8..10] += trunc(vec * 0.5) (signed
// byte arithmetic via cvttss2si), W vslot 0x354(0, 0), P[8..10] restored to the saved bytes, W vslot 0x5ac(1, 0), this vslot 0x50
// (G[0x9b][0x44] + esi, 0, 0.0, -1.0, 0.0, 1.0) and 0x5002f0(src[8]->0x5003d0(0), result).
extern "C" void THISCALL GUESS_55cc30(u32 self, u32 src) {
  u8 F[0x60] __attribute__((aligned(8)));
  u32 e = ext_5003d0_w6(*(u32 *)(src + 4), 0);
  s32 esi = *(s32 *)e;
  u32 res;
  if (esi < 0) {
    u32 lg = *(u32 *)0x700390;
    u32 x = ((W6T2b)*(u32 *)(*(u32 *)lg + 0x20))(lg, 0x6a5eb0, 0x4a0);
    u32 w = *(u32 *)(self + 0x1c);
    u32 y = ((W6V0)*(u32 *)(*(u32 *)w + 0x20))(w);
    u32 txt = *(u32 *)(y + 4);
    if (txt == 0) txt = 0x67c8e8;
    ((u32(*)(u32, u32, u32))*(u32 *)(*(u32 *)x + 0x2c))(x, 0x6a5fb8, txt);
    w = *(u32 *)(self + 0x1c);
    ((W6T2b)*(u32 *)(*(u32 *)w + 0x354))(w, 0, 0);
    res = 0;
  } else {
    u32 w = *(u32 *)(self + 0x1c);
    ((W6T2b)*(u32 *)(*(u32 *)w + 0x57c))(w, (u32)(F + 0x24), (u32)(F + 0x18));
    w = *(u32 *)(self + 0x1c);
    __builtin_memcpy(F + 0x0c, F + 0x18, 12);
    ((W6T3)*(u32 *)(*(u32 *)w + 0x620))(w, (u32)(F + 0x18), 1, 1);
    w = *(u32 *)(self + 0x1c);
    ((W6T2b)*(u32 *)(*(u32 *)w + 0x578))(w, (u32)(F + 0x24), (u32)(F + 0x18));
    ext_43e960_w6((u32)(F + 0x0c), (u32)(F + 0x18));
    float x = w6ldf(F + 0x0c), y = w6ldf(F + 0x10), z = w6ldf(F + 0x14);
    float s = y * y;
    x = x * x;
    s = s + x;
    z = z * z;
    s = s + z;
    float len = (float)ext_634d7c_w6((double)s);
    if (len > *(float *)0x6a60a0) ext_4e0d80_w6((u32)(F + 0x0c), fbits(16.0f));
    float half = *(float *)0x67a6ac;
    w = *(u32 *)(self + 0x1c);
    u8 *P = (u8 *)*(u32 *)(w + 0x1c);
    u8 c2 = P[0xa], bl = P[8], bh = P[9];
    float v = w6ldf(F + 0x0c) * half;
    v = v + (float)(s32)(s8)bl;
    P[8] = (u8)w6cvt(v);
    P = (u8 *)*(u32 *)(*(u32 *)(self + 0x1c) + 0x1c);
    v = w6ldf(F + 0x10) * half;
    v = v + (float)(s32)(s8)P[9];
    P[9] = (u8)w6cvt(v);
    P = (u8 *)*(u32 *)(*(u32 *)(self + 0x1c) + 0x1c);
    v = w6ldf(F + 0x14) * half;
    v = v + (float)(s32)(s8)P[0xa];
    P[0xa] = (u8)w6cvt(v);
    w = *(u32 *)(self + 0x1c);
    ((W6T2b)*(u32 *)(*(u32 *)w + 0x354))(w, 0, 0);
    P = (u8 *)*(u32 *)(*(u32 *)(self + 0x1c) + 0x1c);
    P[8] = bl;
    P = (u8 *)*(u32 *)(*(u32 *)(self + 0x1c) + 0x1c);
    P[9] = bh;
    P = (u8 *)*(u32 *)(*(u32 *)(self + 0x1c) + 0x1c);
    P[0xa] = c2;
    w = *(u32 *)(self + 0x1c);
    ((W6T2b)*(u32 *)(*(u32 *)w + 0x5ac))(w, 1, 0);
    u32 g = *(u32 *)0x70039c;
    u32 q = w6ld(g + 0x9b);
    u32 a = *(u32 *)(q + 0x44) + (u32)esi;
    res = ((W6V6)*(u32 *)(*(u32 *)self + 0x50))(self, a, 0, 0, 0xbf800000u, 0, 0x3f800000u);
  }
  u32 ent = ext_5003d0_w6(*(u32 *)(src + 8), 0);
  ext_5002f0_w6(ent, res);
}
PCREG(55cc30, GUESS_55cc30);

// ---------------------------------------------------------------- 0x615c30
extern "C" u32 THISCALL ext_64c7e0_w6(u32, u32) __asm__("ext_64c7e0");
extern "C" u32 THISCALL ext_65c530_w6(u32, u32) __asm__("ext_65c530");
typedef u32(STDCALL *W6S3)(u32, u32, u32);
typedef u32(STDCALL *W6S4)(u32, u32, u32, u32);
static inline void w6rs(u32 d, u32 state, u32 val) { ((W6S3)*(u32 *)(*(u32 *)d + 0xc8))(d, state, val); }
static inline void w6tss(u32 d, u32 stage, u32 type, u32 val) { ((W6S4)*(u32 *)(*(u32 *)d + 0xfc))(d, stage, type, val); }

// 0x615c30: thiscall(list, count, q, -, idx) ret 0x14, void. Does nothing if the actor table this[0x10071] has no entry for (word q[0x5a] & 0xfff).
// Otherwise Q = this[0x182a5]; synchronises the cached render states in .data (0x724934 =1, 0x724968 =4, 0x72493c =0, 0x724928 =1,
// 0x72492c =4, 0x724930 =0 when 0x724940 == 0, 0x724950 = 0x724958) through D = [0x724a00] vslot 0xc8 (stdcall(D, state, value);
// states 0x1b 0x17 0xe 0x13 0x14 0x1c 0x22) and vslot 0xfc (stdcall(D, 0, 0xd/0xe, 3)); sets Q[0x1e] = 1; for each of the count actors
// list[i] with a table entry: actor = table[word & 0xfff] (0x64c7e0), V = actor[0x20][0xc][0xc]; on a new V: 0x65c530(this, V),
// Q[0x27] = V, Q vslot 0x2a4(1, Q[0x140e + idx*4]), Q[0x27] = 0, Q vslot 0x154(V[0x70]*V[0x68], V[0x74]*V[0x68], V[0x6c]); then walks the
// child chain actor[0x1c] (next at +0x1c): when child[8][0x10][8] has word +2 == 0 and flag 0x800 at +0x20 -> this vslot 0x80(child, 0).
// Finally Q vslot 0x2a4(0, 0), Q[0x1e] = 0, Q[0x141e] = 0xffffffff.
extern "C" void THISCALL GUESS_615c30(u32 self, u32 list, u32 count, u32 q, u32 a4, u32 idx) {
  (void)a4;
  u32 tbl = w6ld(self + 0x10071);
  if (*(u32 *)(tbl + (*(u16 *)(q + 0x5a) & 0xfff) * 4) == 0) return;
  u32 Q = w6ld(self + 0x182a5);
  u32 d;
  if (*(u32 *)0x724934 != 1) { d = *(u32 *)0x724a00; *(u32 *)0x724934 = 1; w6rs(d, 0x1b, 1); }
  if (*(u32 *)0x724968 != 4) { d = *(u32 *)0x724a00; *(u32 *)0x724968 = 4; w6rs(d, 0x17, 4); }
  if (*(u32 *)0x72493c != 0) { d = *(u32 *)0x724a00; *(u32 *)0x72493c = 0; w6rs(d, 0xe, 0); }
  if (*(u32 *)0x724928 != 1) { d = *(u32 *)0x724a00; *(u32 *)0x724928 = 1; w6rs(d, 0x13, 1); }
  if (*(u32 *)0x72492c != 4) { d = *(u32 *)0x724a00; *(u32 *)0x72492c = 4; w6rs(d, 0x14, 4); }
  d = *(u32 *)0x724a00; w6tss(d, 0, 0xd, 3);
  d = *(u32 *)0x724a00; w6tss(d, 0, 0xe, 3);
  if (*(u32 *)0x724940 == 0 && *(u32 *)0x724930 != 0) { d = *(u32 *)0x724a00; *(u32 *)0x724930 = 0; w6rs(d, 0x1c, 0); }
  u32 edx = *(u32 *)0x724958;
  if (*(u32 *)0x724950 != edx) { d = *(u32 *)0x724a00; *(u32 *)0x724950 = edx; w6rs(d, 0x22, edx); }
  *(u8 *)(Q + 0x1e) = 1;
  u32 prev = 0;
  if (count != 0) {
    u32 i = 0;
    do {
      u32 o = *(u32 *)(list + i * 4);
      u32 word = *(u16 *)(o + 0x5a);
      u32 tb = w6ld(self + 0x10071);
      if (*(u32 *)(tb + (word & 0xfff) * 4) != 0) {
        u32 actor = ext_64c7e0_w6(self, word);
        u32 v = *(u32 *)(*(u32 *)(*(u32 *)(actor + 0x20) + 0xc) + 0xc);
        if (prev != v) {
          prev = v;
          ext_65c530_w6(self, v);
          w6st(Q + 0x27, v);
          ((W6T2b)*(u32 *)(*(u32 *)Q + 0x2a4))(Q, 1, *(u32 *)(Q + 0x140e + idx * 4));
          w6st(Q + 0x27, 0);
          float f1 = bitsf(*(u32 *)(v + 0x70)) * bitsf(*(u32 *)(v + 0x68));
          float f2 = bitsf(*(u32 *)(v + 0x74)) * bitsf(*(u32 *)(v + 0x68));
          ((W6V3)*(u32 *)(*(u32 *)Q + 0x154))(Q, fbits(f1), fbits(f2), *(u32 *)(v + 0x6c));
        }
        u32 ch = *(u32 *)(actor + 0x1c);
        while (ch != 0) {
          u32 x = *(u32 *)(*(u32 *)(*(u32 *)(ch + 8) + 0x10) + 8);
          if (*(u16 *)(x + 2) == 0 && (*(u32 *)(x + 0x20) & 0x800)) ((W6T2b)*(u32 *)(*(u32 *)self + 0x80))(self, ch, 0);
          ch = *(u32 *)(ch + 0x1c);
        }
      }
      i++;
    } while (i < count);
  }
  ((W6T2b)*(u32 *)(*(u32 *)Q + 0x2a4))(Q, 0, 0);
  *(u8 *)(Q + 0x1e) = 0;
  w6st(Q + 0x141e, 0xffffffffu);
}
PCREG(615c30, GUESS_615c30);

// ---------------------------------------------------------------- 0x49dca0
extern "C" u32 THISCALL ext_49d6c0_w6(u32) __asm__("ext_49d6c0");
extern "C" u32 THISCALL ext_48fcb0_w6(u32, u32, u32) __asm__("ext_48fcb0");
extern "C" u32 THISCALL ext_48f7e0_w6(u32, u32) __asm__("ext_48f7e0");
typedef u64(THISCALL *W6U64)(u32, u32, u32);
typedef u32(THISCALL *W6L)(u32, u32, u32, u32);
typedef u32(THISCALL *W6B)(u32);
// Debug log through G vslot 0x1c8(0x67a7f8, line) -> (eax:edx) then G vslot slot(eax, edx, text), only when both G[0x9c7] and G[0x9c3]
// are != 0.0 (ucomiss + lahf + test ah,0x44 + jnp skips only on ordered-equal; NaN counts as non-zero).
static inline void w6dbg(u32 g, u32 line, u32 slot, u32 text) {
  if (!(bitsf(w6ld(g + 0x9c7)) == 0.0f) && !(bitsf(w6ld(g + 0x9c3)) == 0.0f)) {
    u64 r = ((W6U64)*(u32 *)(*(u32 *)g + 0x1c8))(g, 0x67a7f8, line);
    ((W6L)*(u32 *)(*(u32 *)g + slot))(g, (u32)r, (u32)(r >> 32), text);
  }
}

// 0x49dca0: thiscall(), void. ext 0x49d6c0(this); this[0x28] = 1; G = [0x70039c]; G[0x38] = G[0x40]; R = G[0x9b] (unaligned): flagB = R vslot 0xb8(),
// cur = R vslot 4(). For each of the this[0x10] ids in this[4]: item = [0x70038c] vslot 0xcc(id); needs item[0x18] & 0x10; ebx = item[0x30] or
// R vslot 0x58(item[0x1c]). Branch A (item[0x1c] != 0 and (!flagB or item[0x14] & 0x100)), if cur is null or == item: name = ebx[4] or "" (0x67c8e8),
// debug line 0x259 (slot 0x178, name), 0x48fcb0(0x6ffa84, ebx, item); text = name; Branch B (otherwise; flagB needs item[0x14] & 0x100): if cur is
// null or == item: ebx = item vslot 0x14(), debug 0x259 (slot 0x178, ebx), 0x48f7e0(0x6ffa84, item), text = item vslot 0x14(). Then debug line 0x260
// (slot 0x17c, text). Finally this[0x28] = 0.
extern "C" void THISCALL GUESS_49dca0(u32 self) {
  ext_49d6c0_w6(self);
  *(u8 *)(self + 0x28) = 1;
  u32 g = *(u32 *)0x70039c;
  if (g + 0x38 != g + 0x40) {
    *(u32 *)(g + 0x38) = *(u32 *)(g + 0x40);
    g = *(u32 *)0x70039c;
  }
  u32 R = w6ld(g + 0x9b);
  u8 flagB = (u8)((W6B)*(u32 *)(*(u32 *)R + 0xb8))(R);
  g = *(u32 *)0x70039c;
  R = w6ld(g + 0x9b);
  u32 cur = ((W6B)*(u32 *)(*(u32 *)R + 4))(R);
  if (*(u32 *)(self + 0x10) == 0) goto done;
  {
    u32 i = 0;
    do {
      u32 id = *(u32 *)(*(u32 *)(self + 4) + i * 4);
      i++;
      u32 M = *(u32 *)0x70038c;
      u32 item = ((W6T1)*(u32 *)(*(u32 *)M + 0xcc))(M, id);
      if (item != 0 && (*(u8 *)(item + 0x18) & 0x10)) {
        u32 ebx = *(u32 *)(item + 0x30);
        if (ebx == 0) {
          g = *(u32 *)0x70039c;
          R = w6ld(g + 0x9b);
          ebx = ((W6T1)*(u32 *)(*(u32 *)R + 0x58))(R, *(u32 *)(item + 0x1c));
        }
        u32 text;
        bool branchA;
        if (flagB && !(*(u32 *)(item + 0x14) & 0x100)) branchA = false;
        else branchA = *(u32 *)(item + 0x1c) != 0;
        if (branchA) {
          if (cur != 0 && cur != item) goto next;
          u32 name = *(u32 *)(ebx + 4);
          if (name == 0) name = 0x67c8e8;
          g = *(u32 *)0x70039c;
          w6dbg(g, 0x259, 0x178, name);
          ext_48fcb0_w6(0x6ffa84, ebx, item);
          text = *(u32 *)(ebx + 4);
          if (text == 0) text = 0x67c8e8;
        } else {
          if (flagB && !(*(u32 *)(item + 0x14) & 0x100)) goto next;
          if (cur != 0 && cur != item) goto next;
          u32 t = ((W6B)*(u32 *)(*(u32 *)item + 0x14))(item);
          g = *(u32 *)0x70039c;
          w6dbg(g, 0x259, 0x178, t);
          ext_48f7e0_w6(0x6ffa84, item);
          text = ((W6B)*(u32 *)(*(u32 *)item + 0x14))(item);
        }
        g = *(u32 *)0x70039c;
        w6dbg(g, 0x260, 0x17c, text);
      }
    next:;
    } while (i != *(u32 *)(self + 0x10));
  }
done:
  *(u8 *)(self + 0x28) = 0;
}
PCREG(49dca0, GUESS_49dca0);

// ---------------------------------------------------------------- 0x4d96d0
extern "C" u32 FASTCALL ext_43e8e0_w6(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 THISCALL ext_4db460_w6(u32, u32, u32) __asm__("ext_4db460");
extern "C" u32 THISCALL ext_4dd060_w6(u32, u32) __asm__("ext_4dd060");

// 0x4d96d0: thiscall(node) ret 4, void (esp-based frame, F+k = esp+k after the exe's prologue; the loop keeps the frame). Loop: this = ecx, node = esi.
// node != 0: stops if node[0x3c] & 0x40000 or node[0x54] vslot 0x60() is true or 0x4db460(node, F+0x20, F+0x5c) is false. If this[0x4c] == 0.0: F+0x14 =
// 0x43e920(F+0x20, F+0x5c), F+4 = 0x43e8e0(F+0x20, F+0x5c); else an existing box this[0x30..0x4c] is grown with the new corner points (F+4/F+0x14 = from
// this+0x30/+0x40, F+0x44 = 0x43e920 and F+0x38 = 0x43e8e0 of F+0x20/F+0x5c), componentwise max/min via comiss, stopping when nothing changed. Then
// F+0x50 = 0x43e8e0(F+4, F+0x14) * 0.5 (0x4e0d00) -> this[0x30..0x38], this[0x3c] |= 0x100000, F+0x2c = 0x43e920(F+4, F+0x50), 0x4dd060(this, F+0x2c),
// this[0x4c] = sqrt(|F+0x2c|^2) + 1.0, this[0x54] gets this[0x40..0x48] at +0x18 and this[0x30..0x38] at +0x24. Then (also when node == 0): stops if
// G[0x9b] vslot 0x70() is true, this[0x3c] & 0x40000 or this[0x50] is 0; otherwise repeats with this = this[0x50], node = this.
extern "C" void THISCALL GUESS_4d96d0(u32 self, u32 node) {
  u8 F[0x70] __attribute__((aligned(8)));
  u32 edi = self, esi = node;
  for (;;) {
    u8 bl = 0;
    w6st((u32)(F + 0x10), edi);
    if (esi != 0) {
      if (*(u32 *)(esi + 0x3c) & 0x40000) return;
      u32 c = *(u32 *)(esi + 0x54);
      if (c != 0 && ((u8)((W6B)*(u32 *)(*(u32 *)c + 0x60))(c))) return;
      if (!((u8)ext_4db460_w6(esi, (u32)(F + 0x20), (u32)(F + 0x5c)))) return;
      float v4c = bitsf(*(u32 *)(edi + 0x4c));
      if (v4c == 0.0f) {
        ext_43e920_w6((u32)(F + 0x14), (u32)(F + 0x20), (u32)(F + 0x5c));
        ext_43e8e0_w6((u32)(F + 0x04), (u32)(F + 0x20), (u32)(F + 0x5c));
        bl = 1;
      } else {
        u32 e40 = edi + 0x40;
        ext_43e8e0_w6((u32)(F + 0x04), edi + 0x30, e40);
        ext_43e920_w6((u32)(F + 0x14), edi + 0x30, e40);
        ext_43e920_w6((u32)(F + 0x44), (u32)(F + 0x5c), (u32)(F + 0x20));
        ext_43e8e0_w6((u32)(F + 0x38), (u32)(F + 0x20), (u32)(F + 0x5c));
        if (w6ldf(F + 0x38) > w6ldf(F + 0x04)) { w6stf(F + 0x04, w6ldf(F + 0x38)); bl = 1; }
        if (w6ldf(F + 0x3c) > w6ldf(F + 0x08)) { w6stf(F + 0x08, w6ldf(F + 0x3c)); bl = 1; }
        if (w6ldf(F + 0x40) > w6ldf(F + 0x0c)) { w6stf(F + 0x0c, w6ldf(F + 0x40)); bl = 1; }
        if (w6ldf(F + 0x14) > w6ldf(F + 0x44)) { w6stf(F + 0x14, w6ldf(F + 0x44)); bl = 1; }
        if (w6ldf(F + 0x18) > w6ldf(F + 0x48)) { w6stf(F + 0x18, w6ldf(F + 0x48)); bl = 1; }
        if (w6ldf(F + 0x1c) > w6ldf(F + 0x4c)) { w6stf(F + 0x1c, w6ldf(F + 0x4c)); bl = 1; }
        else if (!bl) return;
        edi = w6ld((u32)(F + 0x10));
      }
      ext_43e8e0_w6((u32)(F + 0x50), (u32)(F + 0x04), (u32)(F + 0x14));
      ext_4e0d00_w6((u32)(F + 0x50), fbits(0.5f));
      *(float *)(edi + 0x30) = w6ldf(F + 0x50);
      *(float *)(edi + 0x34) = w6ldf(F + 0x54);
      *(float *)(edi + 0x38) = w6ldf(F + 0x58);
      *(u32 *)(edi + 0x3c) |= 0x100000;
      ext_43e920_w6((u32)(F + 0x2c), (u32)(F + 0x04), (u32)(F + 0x50));
      ext_4dd060_w6(edi, (u32)(F + 0x2c));
      float y = w6ldf(F + 0x30);
      float x = w6ldf(F + 0x2c);
      y = y * y;
      x = x * x;
      x = x + y;
      float z = w6ldf(F + 0x34);
      z = z * z;
      x = x + z;
      float len = (float)ext_634d7c_w6((double)x);
      *(u32 *)(edi + 0x3c) |= 0x100000;
      u32 p = *(u32 *)(edi + 0x54);
      *(float *)(edi + 0x4c) = len + *(float *)0x678858;
      *(u32 *)(p + 0x18) = *(u32 *)(edi + 0x40);
      *(u32 *)(p + 0x1c) = *(u32 *)(edi + 0x44);
      *(u32 *)(p + 0x20) = *(u32 *)(edi + 0x48);
      p = *(u32 *)(edi + 0x54);
      *(u32 *)(p + 0x24) = *(u32 *)(edi + 0x30);
      *(u32 *)(p + 0x28) = *(u32 *)(edi + 0x34);
      *(u32 *)(p + 0x2c) = *(u32 *)(edi + 0x38);
      if (!bl) return;
    }
    u32 g = *(u32 *)0x70039c;
    u32 R = w6ld(g + 0x9b);
    if ((u8)((W6B)*(u32 *)(*(u32 *)R + 0x70))(R)) return;
    if (*(u32 *)(edi + 0x3c) & 0x40000) return;
    u32 par = *(u32 *)(edi + 0x50);
    if (par == 0) return;
    esi = edi;
    edi = par;
  }
}
PCREG(4d96d0, GUESS_4d96d0);
