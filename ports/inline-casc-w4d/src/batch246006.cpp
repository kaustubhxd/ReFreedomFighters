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
        ext_43e920_w6((u32)(F + 0x44), (u32)(F + 0x20), (u32)(F + 0x5c));
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

// ---------------------------------------------------------------- 0x65a0e0
extern "C" u32 THISCALL ext_4dad20_w6(u32) __asm__("ext_4dad20");
extern "C" u32 THISCALL ext_4dd0c0_w6(u32) __asm__("ext_4dd0c0");
extern "C" u32 THISCALL ext_658d30_w6(u32) __asm__("ext_658d30");
typedef u32(THISCALL *W6T4)(u32, u32, u32, u32, u32);

// 0x65a0e0: thiscall(), void (own 16-byte aligned frame of 0x1b38 bytes via __chkstk, /GS cookie not reproduced). Debug line 0x259 (G vslot 0x178, text 0x6c459c)
// when both G[0x9c7] and G[0x9c3] are != 0.0. Then iterates the set at this+0x1f0 (object with vtable at its start; vslot 0xc(&it) starts the
// iterator {cur, idx, node}; vslot 0x10(&it) removes the current element): item = *cur; if !(item[5] & 1) remove it; else the iterator
// advances inline (idx+1 == node[0] -> node = node[8], cur = node+0x10, idx = 0 or cur = 0; else cur += 4), this vslot 0x80(item), and for
// child = item[0x38] with flag 0x1000000: if child[0x68]: 0x4dad20(child) when child[0x58], 0x4dd0c0(child) when flag 0x2000000; then, unless
// 0x658d30(item) is true: r = this vslot 0xe8(F, item); every entry item[0x40][i*8] (i < byte item[0x3d]) with e[0x18]: ok |= e[0x18] vslot 8(e, this, F, r);
// when no entry returned true the child's 0x1000000 flag is cleared. Finally debug line 0x260 (slot 0x17c).
extern "C" void THISCALL GUESS_65a0e0(u32 self) {
  u8 Fbuf[0x1b10] __attribute__((aligned(16)));
  u32 it[3];
  w6dbg(*(u32 *)0x70039c, 0x259, 0x178, 0x6c459c);
  u32 obj = self + 0x1f0;
  ((W6T1)*(u32 *)(*(u32 *)obj + 0xc))(obj, (u32)it);
  while (it[0] != 0) {
    u32 item = *(u32 *)it[0];
    if (!(*(u8 *)(item + 5) & 1)) {
      ((W6T1)*(u32 *)(*(u32 *)obj + 0x10))(obj, (u32)it);
      continue;
    }
    u32 cur = it[0];
    it[1] = it[1] + 1;
    if (it[1] == *(u32 *)it[2]) {
      u32 nx = *(u32 *)(it[2] + 8);
      it[2] = nx;
      if (nx != 0) { it[1] = 0; it[0] = nx + 0x10; }
      else it[0] = 0;
    } else {
      it[0] = cur + 4;
    }
    ((W6T1)*(u32 *)(*(u32 *)self + 0x80))(self, item);
    u32 child = *(u32 *)(item + 0x38);
    if (child != 0 && (*(u32 *)(child + 0x3c) & 0x1000000)) {
      if (*(u32 *)(child + 0x68) != 0) {
        if (*(u8 *)(child + 0x58) != 0) ext_4dad20_w6(child);
        if (*(u32 *)(child + 0x3c) & 0x2000000) ext_4dd0c0_w6(child);
      }
      if (ext_658d30_w6(item) == 0) {
        u32 r = ((W6T2b)*(u32 *)(*(u32 *)self + 0xe8))(self, (u32)Fbuf, item);
        u32 arr = *(u32 *)(item + 0x40);
        u8 cl = 0;
        if (*(u8 *)(item + 0x3d) != 0) {
          u32 i = 0;
          do {
            u32 e = *(u32 *)(arr + i * 8);
            if (e != 0) {
              u32 c = *(u32 *)(e + 0x18);
              if (c != 0) {
                u8 al = (u8)((W6T4)*(u32 *)(*(u32 *)c + 8))(c, e, self, (u32)Fbuf, r);
                if (al) cl = 1;
              }
            }
            i++;
          } while (i < *(u8 *)(item + 0x3d));
        }
        if (cl) continue;
        *(u32 *)(*(u32 *)(item + 0x38) + 0x3c) &= 0xfeffffffu;
      }
    }
  }
  w6dbg(*(u32 *)0x70039c, 0x260, 0x17c, 0x6c459c);
}
PCREG(65a0e0, GUESS_65a0e0);

// ---------------------------------------------------------------- 0x43a130
extern "C" u32 THISCALL ext_435e90_w6(u32, u32) __asm__("ext_435e90");
typedef float(THISCALL *W6F1)(u32, u32);
typedef u32(THISCALL *W6B1)(u32, u32);

// 0x43a130: thiscall(obj, key) ret 8, void (x87 results of the vslots: float in st0). Returns if [0x7003a0] is null. Finds `key` (B) among the
// keys at 0x6e48c0 (16-byte entries at 0x6e48b8, offset at +0, length at +0xc; a missing key dereferences null like the exe), clears
// buf[off .. off+len) with buf = this[0x131c], then P = [0x7003a0]->0x435e90(obj). When P and P vslot 0x14(2): five stick/trigger pairs from P
// vslots 0x2c(0), 0x28(0), 0x2c(1), 0x28(1): f > 0.000122 -> buf[off + 1/3/5/7] = trunc(f * [0x67af20]), else f < -0.000122 ->
// buf[off + 0/2/4/6] = trunc(f * [0x67af30]); then for i in 0..15 buf[off + 8 + i] = trunc(max(min(obj vslot 0x30(i) * [0x67af20] (x87 fmul,
// precision control matters), [0x67af20]), [0x67af34])); the loop calls P (not obj) vslot 0x30.
extern "C" void THISCALL GUESS_43a130(u32 self, u32 obj, u32 key) {
  u32 dev = *(u32 *)0x7003a0;
  if (dev == 0) return;
  u32 ent = 0;
  u32 k = *(u32 *)0x6e48c0;
  u32 idx = 0;
  bool found = false;
  if (k != 0) {
    for (;;) {
      if (key == k) { found = true; ent = idx * 16 + 0x6e48b8; break; }
      idx++;
      k = *(u32 *)(idx * 16 + 0x6e48c0);
      if (k == 0) break;
    }
  }
  if (!found) ent = 0;
  u32 len = *(u32 *)(ent + 0xc);
  s32 off = *(s32 *)ent;
  s32 end = off + (s32)len;
  u8 *buf;
  if (off < end) {
    s32 c = off;
    do {
      buf = (u8 *)*(u32 *)(self + 0x131c);
      buf[c] = 0;
      c++;
    } while (c < (s32)(*(u32 *)(ent + 0xc) + (u32)off));
    dev = *(u32 *)0x7003a0;
  }
  u32 p = ext_435e90_w6(dev, obj);
  if (p == 0) return;
  if (!(u8)((W6B1)*(u32 *)(*(u32 *)p + 0x14))(p, 2)) return;
  const float thr = *(float *)0x679540, nthr = *(float *)0x67af28, sc = *(float *)0x67af20, nsc = *(float *)0x67af30;
  struct Pair { u32 slot; u32 arg; int hi; int lo; };
  static const Pair pr[4] = {{0x2c, 0, 1, 0}, {0x28, 0, 3, 2}, {0x2c, 1, 5, 4}, {0x28, 1, 7, 6}};
  for (int q = 0; q < 4; q++) {
    float f = ((W6F1)*(u32 *)(*(u32 *)p + pr[q].slot))(p, pr[q].arg);
    if (f > thr) {
      s32 v = _mm_cvttss_si32(_mm_set_ss(f * sc));
      buf = (u8 *)*(u32 *)(self + 0x131c);
      buf[off + pr[q].hi] = (u8)v;
    } else if (nthr > f) {
      s32 v = _mm_cvttss_si32(_mm_set_ss(f * nsc));
      buf = (u8 *)*(u32 *)(self + 0x131c);
      buf[off + pr[q].lo] = (u8)v;
    }
  }
  for (int i = 0; i < 0x10; i++) {
    float r = ((W6F1)*(u32 *)(*(u32 *)p + 0x30))(p, (u32)i);
    long double t = (long double)r * (long double)sc;
    float f = (float)t;
    __m128 m = _mm_min_ss(_mm_set_ss(f), _mm_set_ss(sc));
    float x = _mm_cvtss_f32(m);
    if (!(x > *(float *)0x67af34)) x = *(float *)0x67af34;
    s32 v = _mm_cvttss_si32(_mm_set_ss(x));
    buf = (u8 *)*(u32 *)(self + 0x131c);
    buf[i + off + 8] = (u8)v;
  }
}
PCREG(43a130, GUESS_43a130);

// ---------------------------------------------------------------- 0x6097d0
extern "C" double VECTORCALL ext_634dac_w6(double) __asm__("ext_634dac");
typedef float(THISCALL *W6F0)(u32);
typedef s32(THISCALL *W6I0)(u32);

// 0x6097d0: thiscall(out, S, rect, flag) ret 0x10, void. Builds the 4x4 projection matrix `out` for a viewport: w, h = (unsigned) rect[2]-rect[0], rect[3]-rect[1]
// (0 -> 1.0); aspect = this vslot 0xd8() / vslot 0xdc(); near = max(0x679544, S[0x64]); far = S[0x68]; ratio q = aspect / (w / h);
// R1 = S vslot 0x248() (x87 st0); r1q = R1 * q (x87 fmul, stored as float); invR2 = 1 / this vslot 0xe8() (x87 fld1 / fdivrp, stored as float).
// S[0x48] & 1 clear: x4 = near * (float)tan(S[0x5c] * 0.5), x3 = x4 * invAspect * r1q / invR2; set: x4 = 1/(2*S[0x3c]), x3 = 1/(2*S[0x40]*invAspect)*invAspect*r1q,
// far *= 2. Then out[0] = 2near / (x4 + x4), out[5] = 2near / (x3 + x3), out[8] = 0/(2x4) , out[9] = 0/(2x3), out[0xb] = 1, zero elsewhere;
// flag != 0: out[0xa] = 1, out[0xe] = -near; else out[0xa] = far / (far - near), out[0xe] = -far * near / (far - near).
extern "C" void THISCALL GUESS_6097d0(u32 self, u32 out, u32 S, u32 rect, u32 flag) {
  u32 dw = *(u32 *)(rect + 8) - *(u32 *)rect;
  float w = (float)((double)(s32)dw + *(double *)(0x680aa0 + (dw >> 31) * 8));
  u32 dh = *(u32 *)(rect + 0xc) - *(u32 *)(rect + 4);
  float h = (float)((double)(s32)dh + *(double *)(0x680aa0 + (dh >> 31) * 8));
  float one = *(float *)0x678858;
  float fh = h, fw = w;
  if (h == 0.0f) fh = one;
  if (w == 0.0f) fw = one;
  s32 ia = ((W6I0)*(u32 *)(*(u32 *)self + 0xd8))(self);
  s32 ib = ((W6I0)*(u32 *)(*(u32 *)self + 0xdc))(self);
  float aspect = (float)ia / (float)ib;
  float nearv = _mm_cvtss_f32(_mm_max_ss(_mm_set_ss(*(float *)0x679544), _mm_set_ss(bitsf(*(u32 *)(S + 0x64)))));
  float farv = bitsf(*(u32 *)(S + 0x68));
  float r1 = ((W6F0)*(u32 *)(*(u32 *)S + 0x248))(S);
  float ratio = fw / fh;
  float q = aspect / ratio;
  float invA = one / aspect;
  float r1q = (float)((long double)r1 * (long double)q);
  float r2 = ((W6F0)*(u32 *)(*(u32 *)self + 0xe8))(self);
  float invR2 = (float)((long double)1 / (long double)r2);
  float x4, x3;
  if (!(*(u8 *)(S + 0x48) & 1)) {
    float a = bitsf(*(u32 *)(S + 0x5c)) * *(float *)0x67a6ac;
    float t = (float)ext_634dac_w6((double)a);
    x4 = t * nearv;
    x3 = x4 * invA;
    x3 = x3 * r1q;
    x3 = x3 / invR2;
  } else {
    float s3c = bitsf(*(u32 *)(S + 0x3c));
    s3c = s3c + s3c;
    x3 = one;
    x4 = one;
    x4 = x4 / s3c;
    float m = bitsf(*(u32 *)(S + 0x40)) * invA;
    m = m + m;
    x3 = x3 / m;
    x3 = x3 * invA;
    farv = farv + farv;
    x3 = x3 * r1q;
  }
  float nx4 = bitsf(fbits(x4) ^ 0x80000000u);
  float d4 = x4 - nx4;
  float near2 = nearv + nearv;
  float nx3 = bitsf(fbits(x3) ^ 0x80000000u);
  float z4 = x4 + nx4;
  u32 *o = (u32 *)out;
  o[1] = 0; o[2] = 0; o[3] = 0; o[4] = 0; o[6] = 0; o[7] = 0;
  o[0xb] = 0x3f800000; o[0xc] = 0; o[0xd] = 0; o[0xf] = 0;
  o[8] = fbits(z4 / d4);
  o[0] = fbits(near2 / d4);
  float d3 = x3 - nx3;
  float z3 = nx3 + x3;
  o[5] = fbits(near2 / d3);
  o[9] = fbits(z3 / d3);
  if (flag & 0xff) {
    o[0xa] = 0x3f800000;
    o[0xe] = fbits(nearv * *(float *)0x67af2c);
  } else {
    float f2 = farv;
    float f3 = farv;
    float nf = farv * *(float *)0x67af2c;
    float dd = f2 - nearv;
    nf = nf * nearv;
    o[0xa] = fbits(f3 / dd);
    o[0xe] = fbits(nf / dd);
  }
}
PCREG(6097d0, GUESS_6097d0);

// ---------------------------------------------------------------- 0x653cc0
typedef u32(THISCALL *W6A4)(u32, u32, u32, u32, u32);
typedef u32(THISCALL *W6A5)(u32, u32, u32, u32, u32, u32);
typedef u32(THISCALL *W6A7)(u32, u32, u32, u32, u32, u32, u32, u32);

// 0x653cc0: thiscall(text, width, lines) ret 0xc, void (/GS cookie not reproduced). Draws `lines` rows of `width` characters of `text` with a bitmap font through this
// vslot 0x25c (quad of 4 vertices of 0x24 bytes + index array {0,1,2,3}) after setting up the state (vslots 0x114(vslot 0xf0() - 1), 0x134(0, 0, w, h) with
// w, h = (float) vslot 0xd8() / 0xdc(), 0x150(0,0,0,0), 0x14c(-0.5,0.5,-0.5,0.5,0.5,1.5,0), 0x15c(0)). cw = vslot 0xf4() * [0x680a60] / w, ch = vslot 0xf8() *
// [0x680a60] / h (x87 mul + div, one rounding at the fstp); y = 1.0 - ch, rows continue while lines != 0: a row with y > 1.0 is skipped, otherwise x = -1.0 and each
// character c (not 0, '\n', ' ') draws a quad at (x, y, x + cw, y + ch) with uv from the table at 0x7f5c10 + c*8 (+4) (+ [0x6bd568] / [0x6bd56c]); x += cw per character,
// y -= ch per row, text += width. Finally vslot 0x15c(1).
extern "C" void THISCALL GUESS_653cc0(u32 self, u32 text, u32 width, u32 lines) {
  if (text == 0) return;
  u32 vt = *(u32 *)self;
  u32 n0 = ((W6B)*(u32 *)(vt + 0xf0))(self);
  ((W6T1)*(u32 *)(vt + 0x114))(self, n0 - 1);
  s32 ia = ((W6I0)*(u32 *)(*(u32 *)self + 0xd8))(self);
  float fa = (float)ia;
  s32 ib = ((W6I0)*(u32 *)(*(u32 *)self + 0xdc))(self);
  float fb = (float)ib;
  ((W6A4)*(u32 *)(*(u32 *)self + 0x134))(self, 0, 0, fbits(fa), fbits(fb));
  ((W6A4)*(u32 *)(*(u32 *)self + 0x150))(self, 0, 0, 0, 0);
  ((W6A7)*(u32 *)(*(u32 *)self + 0x14c))(self, 0xbf000000u, 0x3f000000u, 0xbf000000u, 0x3f000000u, 0x3f000000u, 0x3fc00000u, 0);
  ((W6T1)*(u32 *)(*(u32 *)self + 0x15c))(self, 0);
  u32 idx[2] = {0x10000, 0x30002};
  float r1 = ((W6F0)*(u32 *)(*(u32 *)self + 0xf4))(self);
  float cw = (float)(((long double)r1 * (long double)*(float *)0x680a60) / (long double)fa);
  float r2 = ((W6F0)*(u32 *)(*(u32 *)self + 0xf8))(self);
  float ch = (float)(((long double)r2 * (long double)*(float *)0x680a60) / (long double)fb);
  float one = *(float *)0x678858;
  float y = one - ch;
  s32 cnt = (s32)lines;
  if (cnt > 0) {
    s32 B = (s32)width;
    do {
      if (!(y > one) && B > 0) {
        float x = *(float *)0x67af2c;
        const u8 *p = (const u8 *)text;
        s32 nn = B;
        do {
          u8 c = *p;
          if (c != 0 && c != 0xa && c != 0x20) {
            float V[36];
            s32 ci = (s32)(s8)c;
            float v = *(float *)(0x7f5c14 + ci * 8);
            float u = *(float *)(0x7f5c10 + ci * 8);
            float x1 = x + cw;
            float vv = v + *(float *)0x6bd56c;
            float u2 = u + *(float *)0x6bd568;
            float yp = y + ch;
            u32 *W = (u32 *)V;
            W[0] = fbits(x);  W[1] = fbits(y);  W[2] = 0x3f800000; W[6] = 0xffffffffu; W[7] = fbits(u);  W[8] = fbits(vv);
            W[9] = fbits(x1); W[10] = fbits(y); W[11] = 0x3f800000; W[15] = 0xffffffffu; W[16] = fbits(u2); W[17] = fbits(vv);
            W[18] = fbits(x); W[19] = fbits(yp); W[20] = 0x3f800000; W[24] = 0xffffffffu; W[25] = fbits(u);  W[26] = fbits(v);
            W[27] = fbits(x1); W[28] = fbits(yp); W[29] = 0x3f800000; W[33] = 0xffffffffu; W[34] = fbits(u2); W[35] = fbits(v);
            ((W6A5)*(u32 *)(*(u32 *)self + 0x25c))(self, 0, (u32)V, 4, (u32)idx, 4);
          }
          x = x + cw;
          p++;
          nn--;
        } while (nn != 0);
      }
      y = y - ch;
      text += width;
      cnt--;
    } while (cnt != 0);
  }
  ((W6T1)*(u32 *)(*(u32 *)self + 0x15c))(self, 1);
}
PCREG(653cc0, GUESS_653cc0);

// ---------------------------------------------------------------- 0x5f4170
extern "C" u32 ext_5fa630_w6() __asm__("ext_5fa630");
extern "C" u32 THISCALL ext_600800_w6(u32) __asm__("ext_600800");
typedef u32(*W6C5)(u32, u32, double, u32, u32);
typedef u32(*W6C4)(u32, u32, double, u32);
typedef u32(*W6C2)(u32, u32);
typedef u32(*W6C3b)(u32, u32, u32);

// 0x5f4170: thiscall(), void. Dumps the pending record ring of `this` through the logger ([0x700390] vslot 0x20(0x6b8a64, line) -> stream S, S vslot 0x2c cdecl
// (S, fmt, args...)): lines 0x52 and 0x55 plain, 0x53 prints Y vslot 0x1c(this[0x24]) with Y = 0x5fa630(), 0x54 prints 0x600800 of the object this[0x96] (unaligned).
// Then walks the ring (records of 20 bytes at this+0xbe, count at the unaligned this[0xba], head at the unaligned this[0xb6]) from the head until the head is reached
// again or a record has kind 0: kind 1: Y vslot 0xc(Y, 0x6b8b04, (double)rec[4], O vslot 8(word rec[0xc]), rec[8]) with O = [0x724278][0x3c]; kind 2:
// Y vslot 0xc(Y, 0x6b8ae0, (double)rec[4], H vslot 0(rec[0xc]), H vslot 0(rec[0x10])) (r1 = H(rec[0x10]), r2 = H(rec[0xc]) passed as (r2, r1)); kind 3:
// Y vslot 0xc(Y, 0x6b8b2c, (double)rec[4], rec[0xc]); other kinds call the fatal pointer [0x7003b0] (int3 when null).
extern "C" void THISCALL GUESS_5f4170(u32 self) {
  u32 lg = *(u32 *)0x700390;
  u32 s = ((W6T2b)*(u32 *)(*(u32 *)lg + 0x20))(lg, 0x6b8a64, 0x52);
  ((W6C2)*(u32 *)(*(u32 *)s + 0x2c))(s, 0x6b8a90);
  lg = *(u32 *)0x700390;
  s = ((W6T2b)*(u32 *)(*(u32 *)lg + 0x20))(lg, 0x6b8a64, 0x53);
  u32 y = ext_5fa630_w6();
  u32 r = ((W6T1)*(u32 *)(*(u32 *)y + 0x1c))(y, *(u32 *)(self + 0x24));
  ((W6C3b)*(u32 *)(*(u32 *)s + 0x2c))(s, 0x6b8ac0, r);
  lg = *(u32 *)0x700390;
  s = ((W6T2b)*(u32 *)(*(u32 *)lg + 0x20))(lg, 0x6b8a64, 0x54);
  u32 h = ext_600800_w6(w6ld(self + 0x96));
  ((W6C3b)*(u32 *)(*(u32 *)s + 0x2c))(s, 0x6b8ad4, h);
  lg = *(u32 *)0x700390;
  s = ((W6T2b)*(u32 *)(*(u32 *)lg + 0x20))(lg, 0x6b8a64, 0x55);
  ((W6C2)*(u32 *)(*(u32 *)s + 0x2c))(s, 0x6b8a90);
  u32 node = w6ld(self + 0xb6);
  if (*(u32 *)node == 0) {
    node = self + 0xbe;
    if (*(u32 *)(self + 0xbe) == 0) return;
  }
  for (;;) {
    u32 kind = *(u32 *)node;
    if (kind == 1) {
      u32 o = *(u32 *)(*(u32 *)0x724278 + 0x3c);
      u32 yy = ext_5fa630_w6();
      u32 rr = ((W6T1)*(u32 *)(*(u32 *)o + 8))(o, (u32)*(u16 *)(node + 0xc));
      ((W6C5)*(u32 *)(*(u32 *)yy + 0xc))(yy, 0x6b8b04, (double)bitsf(*(u32 *)(node + 4)), rr, *(u32 *)(node + 8));
    } else if (kind == 2) {
      u32 yy = ext_5fa630_w6();
      u32 ho = w6ld(self + 0x96);
      u32 r1 = ((W6T1)*(u32 *)(*(u32 *)ho))(ho, *(u32 *)(node + 0x10));
      u32 r2 = ((W6T1)*(u32 *)(*(u32 *)ho))(ho, *(u32 *)(node + 0xc));
      ((W6C5)*(u32 *)(*(u32 *)yy + 0xc))(yy, 0x6b8ae0, (double)bitsf(*(u32 *)(node + 4)), r2, r1);
    } else if (kind == 3) {
      u32 yy = ext_5fa630_w6();
      ((W6C4)*(u32 *)(*(u32 *)yy + 0xc))(yy, 0x6b8b2c, (double)bitsf(*(u32 *)(node + 4)), *(u32 *)(node + 0xc));
    } else {
      u32 f = *(u32 *)0x7003b0;
      if (f) ((void (*)())f)();
      else asm volatile("int3");
    }
    u32 nx = node + 0x14;
    u32 endp = self + w6ld(self + 0xba) * 20 + 0xbe;
    u32 cand = (nx != endp) ? nx : self + 0xbe;
    node = cand;
    if (node == w6ld(self + 0xb6)) return;
    if (*(u32 *)node == 0) return;
  }
}
PCREG(5f4170, GUESS_5f4170);

// ---------------------------------------------------------------- 0x480640
extern "C" s32 VECTORCALL ext_633910_w6(float f) __asm__("ext_633910");
extern "C" u32 FASTCALL ext_441940_w6b(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_43e960_w6b(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_4e0be0_w6(u32, u32) __asm__("ext_4e0be0");
typedef u32(THISCALL *W6A8)(u32, u32, u32, u32, u32, u32, u32, u32, u32);

// 0x480640: thiscall(A, B, C, D) ret 0x10 -> (x << 24) | 0xffffff. Frame mirrored by F (L(k) = ebp + k). Local vectors: v40 = (0, 0, min(B[8], A[0x68])) filled by A vslot
// 0x274(&v40, D); V34 = (0, this[0x1c] * 0.1, 0), step = (0, 0, 2pi / (float)N) with N = this[0x18]; P = A vslot 0x84(), Q = this vslot 0x84(). N == 0: x = C.
// Otherwise R = 0x43e920(Q, P); trace = G[0x1aa3][0x1c] vslot 0x34(&hit, 0, &P, &R, 1, 2, 0, 1) (8 args, bool): true or hit[+0x10] == this[8] -> x = 0;
// else for each of the N steps: R = V34, A vslot 0x88(&R), 0x441940(R, Q), 0x43e960(R, P), trace again with (1, 1, 1, 0) arguments: a hit whose [+0x10] != this[8]
// counts as blocked; V34 = 0x4e0be0(V34, step). Finally x = int((1 - blocked / (float)N) * (float)C) through the exe's float-to-int helper 0x633910.
extern "C" u32 THISCALL GUESS_480640(u32 self, u32 A, u32 B, u32 C, u32 D) {
  u8 F[0xf0] __attribute__((aligned(8)));
#define L(k) ((u32)(F + 0xe8 + (k)))
  float b8 = bitsf(*(u32 *)(B + 8));
  float a68 = bitsf(*(u32 *)(A + 0x68));
  w6st(L(-0x40), 0); w6st(L(-0x3c), 0);
  float mn = b8;
  if (b8 > a68) mn = a68;
  w6stf((u8 *)L(-0x38), mn);
  ((W6T2b)*(u32 *)(*(u32 *)A + 0x274))(A, L(-0x40), D);
  float f1 = bitsf(*(u32 *)(self + 0x1c)) * *(float *)0x67a284;
  w6stf((u8 *)L(-0x30), f1);
  u32 N = *(u32 *)(self + 0x18);
  float fN = (float)((double)(s32)N + *(double *)(0x680aa0 + (N >> 31) * 8));
  float step = *(float *)0x68aef8 / fN;
  w6st(L(-0x1c), 0); w6st(L(-0x18), 0); w6st(L(-0x14), 0);
  w6st(L(-0x28), 0); w6st(L(-0x24), 0); w6st(L(-0x20), 0);
  w6st(L(-0x34), 0); w6st(L(-0x2c), 0); w6st(L(-0x4c), 0); w6st(L(-0x48), 0);
  w6stf((u8 *)L(-0x44), step);
  ((W6T1)*(u32 *)(*(u32 *)A + 0x84))(A, L(-0x1c));
  ((W6T1)*(u32 *)(*(u32 *)self + 0x84))(self, L(-0x28));
  u32 x;
  if (*(u32 *)(self + 0x18) == 0) {
    x = C;
  } else {
    ext_43e920_w6(L(-0x10), L(-0x28), L(-0x1c));
    u32 g = *(u32 *)0x70039c;
    w6st(L(-0x94), 0x3f800000);
    u32 o1 = *(u32 *)(w6ld(g + 0x1aa3) + 0x1c);
    u8 al = (u8)((W6A8)*(u32 *)(*(u32 *)o1 + 0x34))(o1, L(-0x94), 0, L(-0x1c), L(-0x10), 1, 2, 0, 1);
    if (al || *(u32 *)L(-0x84) == *(u32 *)(self + 8)) {
      x = 0;
    } else {
      u32 blocked = 0;
      u32 i = 0;
      do {
        u32 *R = (u32 *)L(-0x10);
        R[0] = *(u32 *)L(-0x34); R[1] = *(u32 *)L(-0x30); R[2] = *(u32 *)L(-0x2c);
        ((W6T1)*(u32 *)(*(u32 *)A + 0x88))(A, L(-0x10));
        ext_441940_w6b(L(-0x10), L(-0x28));
        ext_43e960_w6b(L(-0x10), L(-0x1c));
        g = *(u32 *)0x70039c;
        w6st(L(-0xdc), 0x3f800000);
        o1 = *(u32 *)(w6ld(g + 0x1aa3) + 0x1c);
        u8 al2 = (u8)((W6A8)*(u32 *)(*(u32 *)o1 + 0x34))(o1, L(-0xdc), 0, L(-0x1c), L(-0x10), 1, 1, 1, 0);
        if (al2 && *(u32 *)L(-0xcc) != *(u32 *)(self + 8)) blocked++;
        ext_4e0be0_w6(L(-0x34), L(-0x4c));
        i++;
      } while (i != *(u32 *)(self + 0x18));
      u32 N2 = *(u32 *)(self + 0x18);
      float h = (float)((double)(s32)blocked + *(double *)(0x680aa0 + (blocked >> 31) * 8));
      float n = (float)((double)(s32)N2 + *(double *)(0x680aa0 + (N2 >> 31) * 8));
      float q = h / n;
      float t = *(float *)0x678858 - q;
      float cf = (float)((double)(s32)C + *(double *)(0x680aa0 + (C >> 31) * 8));
      t = t * cf;
      x = (u32)ext_633910_w6(t);
    }
  }
#undef L
  return (x << 24) | 0xffffffu;
}
PCREG(480640, GUESS_480640);

// ---------------------------------------------------------------- 0x439c20
extern "C" u32 THISCALL ext_4cbeb0_w6(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4ccbe0_w6(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4382e0_w6(u32) __asm__("ext_4382e0");
extern "C" u32 THISCALL ext_437b00_w6(u32, u32) __asm__("ext_437b00");
extern "C" u32 ext_41e290_w6(u32) __asm__("ext_41e290");
typedef char *(*W6strchr)(const char *, int);

// owner lookup shared by the three blocks: x = this[8]; kind [x] == 3 -> r = x - 4; kind 1 -> y = x[8], r = y ? y - 4 : 0; else r = 0; result = *(u32 *)(r + 0x11)
// (r == 0 dereferences address 0x11 like the exe).
static inline u32 w6owner(u32 self) {
  u32 x = *(u32 *)(self + 8);
  u32 r = 0;
  if (x != 0) {
    u32 k = *(u32 *)x;
    if (k == 3) r = x - 4;
    else if (k == 1) {
      u32 y = *(u32 *)(x + 8);
      r = y ? y - 4 : 0;
    }
  }
  return w6ld(r + 0x11);
}

// 0x439c20: thiscall(str) ret 4, void (SEH 0x665bbd; state 0 after the temp string ctor, 1 around the allocation of this[0xd]). Copies str into a temp string (ctor 0x4cbeb0)
// and splits it at '>' (strchr through the IAT 0x676254, cdecl): every segment (the '>' replaced by NUL) is looked up with owner vslot 0x64(segment) (index; -1 logs
// through [0x700390] vslot 0x20(0x67a850, 0xc8a) and its vslot 0x2c(0x67ac40, segment)); a valid index below owner[0x1210] gets, creating this[0xd] (0x41e290(0x1c),
// 0x4ccbe0(2, 4)) when needed, its slot written ([this[0xd] vslot 4(0)][-4] = index, [0] = 0) and a new node (0x4382e0(ent[0])) linked in front of the list at
// owner[0x1344] + index * 10: node[5] = ent[4], ent[4] = node, node[0] = this. A non-empty remainder after the last '>' goes to 0x437b00(this, rest). The temp string is destroyed (0x4cbec0).
extern "C" void THISCALL GUESS_439c20(u32 self, u32 str) {
  if (str == 0) return;
  SEH_ENTER(0x665bbd);
  u8 Tb[0x84] __attribute__((aligned(4)));
  u32 T = (u32)Tb;
  ext_4cbeb0_w6(T);
  reg.state = 0;
  u32 ebx = *(u32 *)T;
  {
    const u8 *s = (const u8 *)str;
    u8 *d = (u8 *)ebx;
    u8 cl;
    do { cl = *s++; *d++ = cl; } while (cl);
  }
  char *hit = (*(W6strchr *)0x676254)((const char *)ebx, 0x3e);
  if (hit != 0) {
    for (;;) {
      *hit = 0;
      u32 q = w6owner(self);
      s32 idx = (s32)((W6T1)*(u32 *)(*(u32 *)q + 0x64))(q, ebx);
      if (idx == -1) {
        u32 lg = *(u32 *)0x700390;
        u32 x = ((W6T2b)*(u32 *)(*(u32 *)lg + 0x20))(lg, 0x67a850, 0xc8a);
        ((u32(*)(u32, u32, u32))*(u32 *)(*(u32 *)x + 0x2c))(x, 0x67ac40, ebx);
      } else if (!(*(s32 *)(w6owner(self) + 0x1210) <= idx)) {
        if (w6ld(self + 0xd) == 0) {
          u32 raw = ext_41e290_w6(0x1c);
          reg.state = 1;
          u32 obj = raw ? ext_4ccbe0_w6(raw, 2, 4) : 0;
          reg.state = 0;
          w6st(self + 0xd, obj);
        }
        u32 lst = w6ld(self + 0xd);
        u32 p = ((W6T1)*(u32 *)(*(u32 *)lst + 4))(lst, 0);
        *(u32 *)(p - 4) = (u32)idx;
        *(u8 *)p = 0;
        u32 base = *(u32 *)(w6owner(self) + 0x1344);
        u32 ent = base + (u32)idx * 10;
        u32 node = ext_4382e0_w6(*(u32 *)ent);
        w6st(node + 5, *(u32 *)(ent + 4));
        *(u32 *)(ent + 4) = node;
        *(u32 *)node = self;
      }
      ebx = (u32)hit + 1;
      hit = (*(W6strchr *)0x676254)((const char *)ebx, 0x3e);
      if (hit == 0) break;
    }
  }
  if (*(u8 *)ebx != 0) ext_437b00_w6(self, ebx);
  ext_4cbec0_w6(T);
  SEH_LEAVE();
}
PCREG(439c20, GUESS_439c20);

// ---------------------------------------------------------------- 0x652420
// 0x652420: thiscall(A, planes, np, verts, nv, extra) ret 0x18, void. Clips a triangle strip: for each vertex i (16-byte stride, x y z at +0/4/8) a bit mask of the
// planes (16 bytes: nx ny nz w) whose signed distance is > 0 (one bit per plane); state s = ((old & 3) << 1) | (mask == 0). s == 7: when old >= 7 a new vertex buffer
// from A vslot 4(0) gets the previous buffer's vertices 1 and 2 and verts[i]; when old < 7 and i is even a buffer gets verts[i-2], verts[i-1], verts[i] (strip start),
// else (odd i) s = 3 and the generic step runs: for i >= 2 and (mask(i-2) & mask(i-1) & mask(i)) == 0 this vslot 0x258(A, planes, np, &tri, &tri, extra) with the triangle
// {verts[i-2], verts[(i odd) ? i : i-1], verts[(i odd) ? i-1 : i]}.
extern "C" void THISCALL GUESS_652420(u32 self, u32 A, u32 planes, u32 np, u32 verts, u32 nv, u32 extra) {
  u32 st = 0, prev = 0, prevprev = 0, buf = 0;
  if ((s32)nv <= 0) return;
  s32 i = 0;
  do {
    u32 mask = 0;
    if ((s32)np > 0) {
      float vx = bitsf(*(u32 *)(verts + i * 16)), vy = bitsf(*(u32 *)(verts + i * 16 + 4)), vz = bitsf(*(u32 *)(verts + i * 16 + 8));
      for (s32 k = 0; k < (s32)np; k++) {
        u32 p = planes + (u32)k * 16;
        float f = bitsf(*(u32 *)p) * vx;
        float f2 = bitsf(*(u32 *)(p + 4)) * vy;
        f = f + f2;
        float f3 = vz * bitsf(*(u32 *)(p + 8));
        f = f + f3;
        f = f + bitsf(*(u32 *)(p + 12));
        mask |= (u32)(f > 0.0f) << (k & 31);
      }
    }
    u32 old = st;
    u32 s = ((old & 3) << 1) | (mask == 0 ? 1u : 0u);
    bool handled = false;
    if (s == 7) {
      if (old >= s) {
        u32 nb = ((W6T1)*(u32 *)(*(u32 *)A + 4))(A, 0);
        u32 *o = (u32 *)buf, *n = (u32 *)nb;
        n[0] = o[3]; n[1] = o[4]; n[2] = o[5]; n[3] = o[6]; n[4] = o[7]; n[5] = o[8];
        buf = nb;
        u32 *vi = (u32 *)(verts + i * 16);
        n[6] = vi[0]; n[7] = vi[1]; n[8] = vi[2];
        handled = true;
      } else if (!(i & 1)) {
        u32 nb = ((W6T1)*(u32 *)(*(u32 *)A + 4))(A, 0);
        u32 *n = (u32 *)nb;
        u32 *v2 = (u32 *)(verts + (i - 2) * 16), *v1 = (u32 *)(verts + (i - 1) * 16), *vi = (u32 *)(verts + i * 16);
        n[0] = v2[0]; n[1] = v2[1]; n[2] = v2[2];
        n[3] = v1[0]; n[4] = v1[1]; n[5] = v1[2];
        buf = nb;
        n[6] = vi[0]; n[7] = vi[1]; n[8] = vi[2];
        handled = true;
      } else {
        s = 3;
      }
    }
    if (!handled && i >= 2 && (prevprev & (mask & prev)) == 0) {
      u32 tri[9];
      s32 a1 = (i & 1) ? i : i - 1, a2 = (i & 1) ? i - 1 : i;
      u32 *v0 = (u32 *)(verts + (i - 2) * 16), *va = (u32 *)(verts + a1 * 16), *vb = (u32 *)(verts + a2 * 16);
      tri[0] = v0[0]; tri[1] = v0[1]; tri[2] = v0[2];
      tri[3] = va[0]; tri[4] = va[1]; tri[5] = va[2];
      tri[6] = vb[0]; tri[7] = vb[1]; tri[8] = vb[2];
      ((W6V6)*(u32 *)(*(u32 *)self + 0x258))(self, A, planes, np, (u32)tri, (u32)tri, extra);
    }
    prevprev = prev;
    prev = mask;
    st = s;
    i++;
  } while (i < (s32)nv);
}
PCREG(652420, GUESS_652420);

// ---------------------------------------------------------------- 0x61bfe0
extern "C" void ext_62c9b0_w6(u32) __asm__("ext_62c9b0");
extern "C" u32 ext_6204f0_w6(u32, u32) __asm__("ext_6204f0");
extern "C" u32 ext_61f2c0_w6(u32, u32) __asm__("ext_61f2c0");
extern "C" u32 ext_626ac0_w6(u32, u32, u32) __asm__("ext_626ac0");
extern "C" u32 ext_626a80_w6(u32, u32, u32) __asm__("ext_626a80");
extern "C" u32 ext_626a70_w6() __asm__("ext_626a70");
extern "C" u32 ext_626a60_w6() __asm__("ext_626a60");
extern "C" u32 ext_620e70_w6(u32, u32) __asm__("ext_620e70");
extern "C" void ext_61c3d0_w6(u32) __asm__("ext_61c3d0");
typedef u32 (*W6Alloc)(u32);

// 0x61bfe0: cdecl(a0, allocs, a2) -> object (0 on failure). allocs = {alloc fn, [4], [8]} or null (then {[0x6762f0], [0x6762f4], [0x6762ec]}). Allocates the 0x274-byte
// object with alloc(0x274), keeps the triple at +0xc, initialises ~100 fields (zeros, +0x74 = self, +0x110 = 0x620b30, +0x214 = 0x10, +0x268 = 0x21, +0x22c.. record with
// the triple pointer), allocates +0x220 (0x100 bytes) and +0x2c (0x400 bytes), +0xe4 = a0 ? 0x6204f0(self+0x22c, a0) : 0, then 0x61f2c0(self+0x158, self); success
// needs +0x220, +0x2c and (a0 -> +0xe4) set: +0x30 = +0x2c + 0x400; a2 == 0: 0x626a80(self+0x90, self+0x8c, 0), +0xe0 = 0x626a60(); else 0x626ac0 (same args),
// +0xe8 = 1, +0xe0 = 0x626a70(), +0x268 = *a2 (byte), then 0x620e70(self, 0x6be290) must be non-zero; any failure calls 0x61c3d0(self) and returns 0.
extern "C" u32 GUESS_61bfe0(u32 a0, u32 al, u32 a2) {
  u32 edi, ebx, esi;
#define F32(o) (*(volatile u32 *)(edi + (o)))
  if (al != 0) {
    edi = ((W6Alloc)*(u32 *)al)(0x274);
    ebx = edi + 0xc;
    *(u32 *)ebx = *(u32 *)al;
    *(u32 *)(ebx + 4) = *(u32 *)(al + 4);
    *(u32 *)(ebx + 8) = *(u32 *)(al + 8);
  } else {
    esi = *(u32 *)0x6762f0;
    edi = ((W6Alloc)esi)(0x274);
    ebx = edi + 0xc;
    *(u32 *)(ebx + 4) = *(u32 *)0x6762f4;
    u32 t = *(u32 *)0x6762ec;
    *(u32 *)ebx = esi;
    *(u32 *)(ebx + 8) = t;
  }
  if (edi == 0) return 0;
  F32(0x110) = 0x620b30;
  ext_62c9b0_w6(edi + 0x100);
  F32(0) = 0; F32(4) = 0;
  for (u32 o = 0x34; o <= 0x70; o += 4) F32(o) = 0;
  F32(0x74) = edi;
  F32(0x78) = 0; F32(0x7c) = 0; F32(0x80) = 0; F32(0x84) = 0; F32(0x88) = 0;
  F32(8) = 0; F32(0x18) = 0; F32(0x1c) = 0; F32(0x24) = 0; F32(0x28) = 0; F32(0x20) = 0;
  F32(0x14c) = 0; F32(0x150) = 0;
  F32(0x130) = 0; F32(0x134) = 0; F32(0x138) = 0; F32(0x13c) = 0; F32(0x140) = 0; F32(0x144) = 0; F32(0x148) = 0;
  F32(0x224) = 0; F32(0x228) = 0;
  F32(0x114) = 0; F32(0x118) = 0; F32(0x11c) = 0; F32(0x120) = 0; F32(0x124) = 0; F32(0x12c) = 0;
  F32(0x204) = 0; F32(0x208) = 0; F32(0x210) = 0; F32(0x20c) = 0; F32(0x214) = 0x10;
  F32(0x220) = ((W6Alloc)*(u32 *)ebx)(0x100);
  F32(0x218) = 0;
  F32(0x2c) = ((W6Alloc)*(u32 *)ebx)(0x400);
  F32(0x260) = 0; F32(0x25c) = 0; F32(0x264) = 0;
  F32(0xf0) = 0; F32(0xfc) = 0; F32(0xf4) = 0; F32(0xf8) = 0;
  *(volatile u8 *)(edi + 0x268) = 0x21;
  F32(0x270) = 0; F32(0x26c) = 0; F32(0xe8) = 0; F32(0xec) = 0;
  u32 rec = edi + 0x22c;
  *(u32 *)rec = 0; *(u32 *)(rec + 4) = 0; *(u32 *)(rec + 0x10) = 0; *(u32 *)(rec + 0xc) = 0; *(u32 *)(rec + 8) = 0; *(u32 *)(rec + 0x14) = ebx;
  F32(0x244) = 0; F32(0x248) = 0; F32(0x254) = 0; F32(0x250) = 0; F32(0x24c) = 0;
  F32(0x258) = ebx;
  esi = a0;
  F32(0xe4) = esi ? ext_6204f0_w6(rec, esi) : 0;
  F32(0x200) = 0;
  bool ok = ext_61f2c0_w6(edi + 0x158, edi) != 0 && F32(0x220) != 0 && F32(0x2c) != 0 && !(esi && F32(0xe4) == 0);
  if (ok) {
    F32(0x30) = F32(0x2c) + 0x400;
    if (a2 == 0) {
      ext_626a80_w6(edi + 0x90, edi + 0x8c, 0);
      F32(0xe0) = ext_626a60_w6();
      return edi;
    }
    ext_626ac0_w6(edi + 0x90, edi + 0x8c, 0);
    F32(0xe8) = 1;
    F32(0xe0) = ext_626a70_w6();
    *(volatile u8 *)(edi + 0x268) = *(u8 *)a2;
    if (ext_620e70_w6(edi, 0x6be290) != 0) return edi;
  }
  ext_61c3d0_w6(edi);
  return 0;
#undef F32
}
PCREG(61bfe0, GUESS_61bfe0);

// ---------------------------------------------------------------- 0x4d6c60
typedef u32(THISCALL *W6R4)(u32, u32, u32, u32);

static inline void w6fatal2() {
  u32 f = *(u32 *)0x7003b0;
  if (f) ((void (*)())f)();
  else asm volatile("int3");
}
static inline void w6read(u32 F, u32 dst, u32 n, u32 h) {
  if (((W6R4)*(u32 *)(*(u32 *)F + 0x14))(F, dst, n, h) != n) w6fatal2();
}

// 0x4d6c60: thiscall(), void (two 0x10004-byte stack buffers from __chkstk, /GS cookie not reproduced). Reads the central directory entries of an archive file object
// F = this[0x15] with handle h = this[0x11]: seeks (F vslot 0x10(h, this[0x3c] ? this[0x40] : this[0x2e], 0)), then while F vslot 0x1c(h) is 0: sig = read 4 bytes
// (F vslot 0x14(&dst, n, h); a short read calls the fatal pointer [0x7003b0]); 0x02014b50 = entry: pos = F vslot 0xc(h), read 0x2a header bytes, name (word +0x18)
// into buffer 1 (NUL appended); if name length != 0 and pos is not in the list this[0x66][0..this[0x62]) the entry's bytes +2..+0x1c are copied to a 26-byte record and
// flagged; then the extra field (word +0x1a) and the comment (word +0x1c) are read into buffer 2; a flagged entry calls this[0x6a] vslot 4(buffer1, &rec,
// dword(+0x26) + name length + 0x1e); 0x06054b50 or 0x52756e65 ends; any other signature logs through [0x700390] vslot 0x24(0x6969c0).
extern "C" void THISCALL GUESS_4d6c60(u32 self) {
  u8 B1[0x10004] __attribute__((aligned(16)));
  u8 B2[0x10004] __attribute__((aligned(16)));
  u32 F = w6ld(self + 0x15);
  u32 h = w6ld(self + 0x11);
  u32 pos0 = (*(u32 *)(self + 0x3c) == 0) ? w6ld(self + 0x2e) : w6ld(self + 0x40);
  ((W6T3)*(u32 *)(*(u32 *)F + 0x10))(F, h, pos0, 0);
  F = w6ld(self + 0x15);
  if (((W6T1)*(u32 *)(*(u32 *)F + 0x1c))(F, w6ld(self + 0x11)) != 0) return;
  for (;;) {
    u8 bl = 0;
    u8 hdr2[0x2a];
    u32 sig = 0;
    F = w6ld(self + 0x15);
    h = w6ld(self + 0x11);
    if (((W6R4)*(u32 *)(*(u32 *)F + 0x14))(F, (u32)&sig, 4, h) != 4) w6fatal2();
    if (sig == 0x2014b50) {
      F = w6ld(self + 0x15);
      u32 esi = ((W6T1)*(u32 *)(*(u32 *)F + 0xc))(F, w6ld(self + 0x11));
      F = w6ld(self + 0x15);
      if (((W6R4)*(u32 *)(*(u32 *)F + 0x14))(F, (u32)hdr2, 0x2a, w6ld(self + 0x11)) != 0x2a) w6fatal2();
      u16 nameLen = *(u16 *)(hdr2 + 0x18);
      u16 extraLen, commentLen;
      u8 rec[26];
      if (nameLen != 0) {
        F = w6ld(self + 0x15);
        if (((W6R4)*(u32 *)(*(u32 *)F + 0x14))(F, (u32)B1, nameLen, w6ld(self + 0x11)) != nameLen) w6fatal2();
        B1[nameLen] = 0;
        u32 cnt = w6ld(self + 0x62);
        bool found = false;
        if (cnt != 0) {
          u32 arr = w6ld(self + 0x66);
          for (u32 i = 0; i < cnt; i++) {
            if (esi == *(u32 *)(arr + i * 4)) { found = true; break; }
          }
        }
        if (!found) {
          __builtin_memcpy(rec, hdr2 + 2, 26);
          bl = 1;
        }
      }
      extraLen = *(u16 *)(hdr2 + 0x1a);
      if (extraLen != 0) {
        F = w6ld(self + 0x15);
        if (((W6R4)*(u32 *)(*(u32 *)F + 0x14))(F, (u32)B2, extraLen, w6ld(self + 0x11)) != extraLen) w6fatal2();
      }
      commentLen = *(u16 *)(hdr2 + 0x1c);
      if (commentLen != 0) {
        F = w6ld(self + 0x15);
        if (((W6R4)*(u32 *)(*(u32 *)F + 0x14))(F, (u32)B2, commentLen, w6ld(self + 0x11)) != commentLen) w6fatal2();
      }
      if (bl) {
        u32 off;
        __builtin_memcpy(&off, hdr2 + 0x26, 4);
        u32 M = w6ld(self + 0x6a);
        ((W6T3)*(u32 *)(*(u32 *)M + 4))(M, (u32)B1, (u32)rec, off + nameLen + 0x1e);
      }
    } else if (sig == 0x6054b50 || sig == 0x52756e65) {
      return;
    } else {
      u32 lg = *(u32 *)0x700390;
      ((u32(*)(u32, u32))*(u32 *)(*(u32 *)lg + 0x24))(lg, 0x6969c0);
    }
    F = w6ld(self + 0x15);
    if (((W6T1)*(u32 *)(*(u32 *)F + 0x1c))(F, w6ld(self + 0x11)) != 0) return;
  }
}
PCREG(4d6c60, GUESS_4d6c60);

// ---------------------------------------------------------------- 0x55a3e0
extern "C" u32 THISCALL ext_4db7c0_w6(u32, u32) __asm__("ext_4db7c0");

// 0x55a3e0: thiscall(src) ret 4, void (/GS cookie not reproduced). e = src[4]->0x5003d0(0) (type byte must be 0 or 1, else the logger + fatal pointer as in 0x55a170);
// obj = G[0x9b] vslot 0x58(*e); V = (0, 0, 0); this[0x1c] vslot 0x84(&V); obj vslot 0x8c(&V); U = obj[8]->0x4db7c0() (3 floats). If U.z > U.x: V.x = V.x > 0 ? U.x : -U.x;
// else V.z = V.z > 0 ? U.z : -U.z; obj vslot 0x84(&V); V.y += [0x685270]; writes V.x, V.y, V.z into the entries 0..2 of src[8] (type byte 0 or 2, else fatal; set to 2).
extern "C" void THISCALL GUESS_55a3e0(u32 self, u32 src) {
  float V[3] = {0, 0, 0}, U[3];
  u32 e = ext_5003d0_w6(*(u32 *)(src + 4), 0);
  u8 dl = *(u8 *)(e + 4);
  if (dl != 0 && dl != 1) w6fatal();
  u32 g = *(u32 *)0x70039c;
  u32 R = w6ld(g + 0x9b);
  u32 obj = ((W6T1)*(u32 *)(*(u32 *)R + 0x58))(R, *(u32 *)e);
  V[0] = 0; V[1] = 0; V[2] = 0;
  u32 W = *(u32 *)(self + 0x1c);
  ((W6T1)*(u32 *)(*(u32 *)W + 0x84))(W, (u32)V);
  ((W6T1)*(u32 *)(*(u32 *)obj + 0x8c))(obj, (u32)V);
  ext_4db7c0_w6(*(u32 *)(obj + 8), (u32)U);
  if (U[2] > U[0]) {
    if (V[0] > 0.0f) V[0] = U[0];
    else V[0] = bitsf(fbits(U[0]) ^ 0x80000000u);
  } else {
    if (V[2] > 0.0f) V[2] = U[2];
    else V[2] = bitsf(fbits(U[2]) ^ 0x80000000u);
  }
  ((W6T1)*(u32 *)(*(u32 *)obj + 0x84))(obj, (u32)V);
  V[1] = V[1] + *(float *)0x685270;
  float vx = V[0];
  w6setslot(ext_5003d0_w6(*(u32 *)(src + 8), 0), vx);
  float vy = V[1];
  w6setslot(ext_5003d0_w6(*(u32 *)(src + 8), 1), vy);
  float vz = V[2];
  w6setslot(ext_5003d0_w6(*(u32 *)(src + 8), 2), vz);
}
PCREG(55a3e0, GUESS_55a3e0);

// ---------------------------------------------------------------- 0x49bbc0
extern "C" u32 FASTCALL ext_4419f0_w6(u32, u32) __asm__("ext_4419f0");

// 0x49bbc0: fastcall(A, B, r, s, it) ret 0xc -> bool. Iterates the triangles of `it` (vslot 0x4c(&state) reset, vslot 0x64(&state) next node; a node holds three vertices
// as floats at +4/+0x10/+0x1c) skipping triangles with two identical vertices (ordered-equal compares); each remaining triangle's vertices are transformed by 0x4419f0(v, A)
// and 0x441940(v, B); a vertex with d = x^2 + y^2 + z^2 (summed y, x, z order) satisfying z > sqrt(d) * s and r*r > d makes the function return 1; no hit -> 0.
extern "C" u32 FASTCALL GUESS_49bbc0(u32 A, u32 B, float r, float s, u32 itobj) {
  float r2 = r * r;
  if (itobj == 0) return 0;
  u32 it[4] = {0, 0, 0, 0};
  ((W6T1)*(u32 *)(*(u32 *)itobj + 0x4c))(itobj, (u32)it);
  u32 node = ((W6T1)*(u32 *)(*(u32 *)itobj + 0x64))(itobj, (u32)it);
  while (node != 0) {
    float *p = (float *)node;
    bool eq01 = p[1] == p[4] && p[2] == p[5] && p[3] == p[6];
    bool eq12 = p[4] == p[7] && p[5] == p[8] && p[6] == p[9];
    bool eq20 = p[7] == p[1] && p[8] == p[2] && p[9] == p[3];
    if (!(eq01 || eq12 || eq20)) {
      float T[9];
      for (int i = 0; i < 9; i++) T[i] = p[1 + i];
      ext_4419f0_w6((u32)&T[0], A);
      ext_4419f0_w6((u32)&T[3], A);
      ext_4419f0_w6((u32)&T[6], A);
      ext_441940_w6b((u32)&T[0], B);
      ext_441940_w6b((u32)&T[3], B);
      ext_441940_w6b((u32)&T[6], B);
      for (int v = 0; v < 3; v++) {
        float x = T[3 * v], y = T[3 * v + 1], z = T[3 * v + 2];
        float d = y * y;
        float xx = x * x;
        d = d + xx;
        float zz = z * z;
        d = d + zz;
        float len = (float)ext_634d7c_w6((double)d);
        len = len * s;
        bool c1 = z > len;
        bool c2 = r2 > d;
        if (c1 && c2) return 1;
      }
    }
    node = ((W6T1)*(u32 *)(*(u32 *)itobj + 0x64))(itobj, (u32)it);
  }
  return 0;
}
PCREG(49bbc0, GUESS_49bbc0);

// ---------------------------------------------------------------- 0x5544f0
extern "C" u32 THISCALL ext_5520c0_w6(u32, u32, u32, u32) __asm__("ext_5520c0");

// 0x5544f0: thiscall(src) ret 4, void (ebx saved around the body). e0, e1 = src[4]->0x5003d0(0 / 1) (type byte must be 0 or 1, else logger + fatal pointer as in 0x55a170);
// a = *e0, b = *e1; 0x5520c0(this, a, 0, &V) fills V (3 floats); obj = G[0x9b] vslot 0x58(a); G[0x9b] vslot 0x114(0x6a5884, 0, 0x6a57fc, 0x18c, b, 0) -> id (16 bit);
// obj vslot 0x128(id). Then entry 0 of src[4] is copied into entry 0 of src[8] when they differ: a destination of type 4 is released (value vslot 0x28), a source of type 4 is
// cloned (value vslot 0x24, result stored), else the raw value; the type byte is copied. Entries 1..3 of src[8] (type 0 or 2, else fatal; set to 2) receive V.x, V.y, V.z.
extern "C" void THISCALL GUESS_5544f0(u32 self, u32 src) {
  float V[4] = {0, 0, 0, 0};
  u32 e0 = ext_5003d0_w6(*(u32 *)(src + 4), 0);
  u8 dl = *(u8 *)(e0 + 4);
  if (dl != 0 && dl != 1) w6fatal();
  u32 a = *(u32 *)e0;
  u32 e1 = ext_5003d0_w6(*(u32 *)(src + 4), 1);
  u8 cl = *(u8 *)(e1 + 4);
  if (cl != 0 && cl != 1) w6fatal();
  u32 b = *(u32 *)e1;
  ext_5520c0_w6(self, a, 0, (u32)V);
  u32 g = *(u32 *)0x70039c;
  u32 R = w6ld(g + 0x9b);
  u32 obj = ((W6T1)*(u32 *)(*(u32 *)R + 0x58))(R, a);
  g = *(u32 *)0x70039c;
  R = w6ld(g + 0x9b);
  u32 id = ((W6V6)*(u32 *)(*(u32 *)R + 0x114))(R, 0x6a5884, 0, 0x6a57fc, 0x18c, b, 0) & 0xffff;
  ((W6T1)*(u32 *)(*(u32 *)obj + 0x128))(obj, id);
  u32 de = ext_5003d0_w6(*(u32 *)(src + 4), 0);
  u32 se = ext_5003d0_w6(*(u32 *)(src + 8), 0);
  if (de != se) {
    if (*(u8 *)(se + 4) == 4) {
      u32 c = *(u32 *)se;
      ((W6B)*(u32 *)(*(u32 *)c + 0x28))(c);
    }
    u32 val;
    if (*(u8 *)(de + 4) == 4) {
      u32 c = *(u32 *)de;
      val = ((W6B)*(u32 *)(*(u32 *)c + 0x24))(c);
    } else {
      val = *(u32 *)de;
    }
    *(u32 *)se = val;
    *(u8 *)(se + 4) = *(u8 *)(de + 4);
  }
  float vx = V[0];
  w6setslot(ext_5003d0_w6(*(u32 *)(src + 8), 1), vx);
  float vy = V[1];
  w6setslot(ext_5003d0_w6(*(u32 *)(src + 8), 2), vy);
  float vz = V[2];
  w6setslot(ext_5003d0_w6(*(u32 *)(src + 8), 3), vz);
}
PCREG(5544f0, GUESS_5544f0);

// ---------------------------------------------------------------- 0x6183a0
extern "C" u32 FASTCALL ext_4de440_w6(u32, u32, u32) __asm__("ext_4de440");
extern "C" u32 FASTCALL ext_441970_w6(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 THISCALL ext_610070_w6(u32, u32) __asm__("ext_610070");
extern "C" u32 THISCALL ext_6107e0_w6(u32, u32) __asm__("ext_6107e0");
extern "C" u32 FASTCALL ext_61a660_w6(u32, u32) __asm__("ext_61a660");
typedef u32(STDCALL *W6S2)(u32, u32);

// 0x6183a0: thiscall(A, S, R) ret 8, void (/GS cookie not reproduced). Z = S[8][0x10][8]; returns when Z[0x20] & 0x800000. Debug line 0x259 (G vslot 0x178, text 0x6bdef0). R vslot
// 0x29c(Z[0x20], Z[0x38], Z[0x44]); C = S[0x14], p = S[0x28]; pose = S[0xc] ?: C[0xc] ?: C[8] + 8; D = C[0x20]. Both S[5] and C[5] without bit 4: V1 = 0x4de440(pose, D+0x10),
// V2 = 0x441970(pose+0x24, D+0x10), V2 = 0x441940(V2, D+0x34), 0x610070(R, 0), R vslot 0x28c(&V1, &V2, 0); otherwise 0x610070(R, 0), R vslot 0x28c(pose, pose+0x24, 0). Then 0x6107e0(R, p);
// cached D3D state through dev = [0x724a00] (vslot 0xc8 / 0x130 / 0x14c / 0x154 stdcall with the device first): state 0x89 = 0 when R[0x115f] & 2 and [0x724948]; 0x152 via vslot 0x130
// when [0x7249f8] != 0x152; R[0x13fa] object: release (vslot 8) when [+0x30], vslot 0x14c(0, [+0x2c], 0x24) on cache miss of [0x724970] / [0x7249b0]; R[0x140a] object: release when
// [+0x18], vslot 0x154([+0x14], A[4][0x28]) on a miss of [0x7249f0] / [0x7249f4]; finally 0x61a660(A[4][0x24], A[4] + 0xc) and debug line 0x260 (slot 0x17c).
extern "C" void THISCALL GUESS_6183a0(u32 A, u32 S, u32 R) {
  u32 Z = *(u32 *)(*(u32 *)(*(u32 *)(S + 8) + 0x10) + 8);
  if (*(u32 *)(Z + 0x20) & 0x800000) return;
  w6dbg(*(u32 *)0x70039c, 0x259, 0x178, 0x6bdef0);
  ((W6T3)*(u32 *)(*(u32 *)R + 0x29c))(R, *(u32 *)(Z + 0x20), *(u32 *)(Z + 0x38), *(u32 *)(Z + 0x44));
  u32 C = *(u32 *)(S + 0x14);
  u32 p = *(u32 *)(S + 0x28);
  u32 pose = *(u32 *)(C + 8) + 8;
  if (*(u32 *)(C + 0xc) != 0) pose = *(u32 *)(C + 0xc);
  if (*(u32 *)(S + 0xc) != 0) pose = *(u32 *)(S + 0xc);
  u32 D = *(u32 *)(C + 0x20);
  if ((*(u8 *)(S + 5) & 4) || (*(u8 *)(C + 5) & 4)) {
    ext_610070_w6(R, 0);
    ((W6T3)*(u32 *)(*(u32 *)R + 0x28c))(R, pose, pose + 0x24, 0);
  } else {
    u32 V1[4] = {0, 0, 0, 0}, V2[4] = {0, 0, 0, 0};
    u32 m = D + 0x10;
    ext_4de440_w6((u32)V1, pose, m);
    ext_441970_w6((u32)V2, pose + 0x24, m);
    ext_441940_w6b((u32)V2, D + 0x34);
    ext_610070_w6(R, 0);
    ((W6T3)*(u32 *)(*(u32 *)R + 0x28c))(R, (u32)V1, (u32)V2, 0);
  }
  ext_6107e0_w6(R, p);
  if ((*(u8 *)(R + 0x115f) & 2) && *(u32 *)0x724948 != 0) {
    u32 d = *(u32 *)0x724a00;
    *(u32 *)0x724948 = 0;
    w6rs(d, 0x89, 0);
  }
  u32 A4 = *(u32 *)(A + 4);
  u32 o1 = w6ld(R + 0x13fa);
  u32 o2 = w6ld(R + 0x140a);
  if (*(u32 *)0x7249f8 != 0x152) {
    u32 d = *(u32 *)0x724a00;
    *(u32 *)0x7249f8 = 0x152;
    ((W6S2)*(u32 *)(*(u32 *)d + 0x130))(d, 0x152);
  }
  if (*(u32 *)(o1 + 0x30) != 0) {
    ((W6B)*(u32 *)(*(u32 *)o1 + 8))(o1);
    *(u32 *)(o1 + 0x30) = 0;
  }
  u32 e = *(u32 *)(o1 + 0x2c);
  if (*(u32 *)0x724970 != e || *(u32 *)0x7249b0 != 0x24) {
    u32 d = *(u32 *)0x724a00;
    *(u32 *)0x724970 = e;
    *(u32 *)0x7249b0 = 0x24;
    ((W6S4)*(u32 *)(*(u32 *)d + 0x14c))(d, 0, e, 0x24);
  }
  u32 b28 = *(u32 *)(A4 + 0x28);
  if (*(u32 *)(o2 + 0x18) != 0) {
    ((W6B)*(u32 *)(*(u32 *)o2 + 8))(o2);
    *(u32 *)(o2 + 0x18) = 0;
  }
  u32 s14 = *(u32 *)(o2 + 0x14);
  if (*(u32 *)0x7249f0 != s14 || *(u32 *)0x7249f4 != b28) {
    u32 d = *(u32 *)0x724a00;
    *(u32 *)0x7249f0 = s14;
    *(u32 *)0x7249f4 = b28;
    ((W6S3)*(u32 *)(*(u32 *)d + 0x154))(d, s14, b28);
  }
  ext_61a660_w6(*(u32 *)(A4 + 0x24), A4 + 0xc);
  w6dbg(*(u32 *)0x70039c, 0x260, 0x17c, 0x6bdef0);
}
PCREG(6183a0, GUESS_6183a0);

// ---------------------------------------------------------------- 0x60c100
extern "C" u32 FASTCALL ext_60ff30_w6(u32, u32, u32, u32) __asm__("ext_60ff30");
extern "C" u32 FASTCALL ext_60feb0_w6(u32, u32, u32, u32) __asm__("ext_60feb0");

// 0x60c100: thiscall(-) ret 4 (the stack argument is unused), void (/GS cookie not reproduced). dev = unaligned this[0x1377]: dev vslot 0x94 (stdcall(dev, state, &identity 4x4)) for
// states 3, 2, 0x100, 0x10; 0x60ff30 and 0x60feb0 (fastcall, 2 stack args) for stage 0 and, when [0x724a08] > 1, stage 1; cached render states via [0x724a00] vslot 0xc8:
// 0x13 = 5, 0x14 = 6, 0x1b = 1, 0xe = 0 (each only on a cache miss of [0x724928] / [0x72492c] / [0x724934] / [0x72493c]), 0x17 = 8 always, texture slot 0xf4(0, [0x724ad8]) on a
// miss of [0x724848]; then a full-screen quad: w, h = this vslot 0xd8() / 0xdc(); u/v offsets from this[0x60] / this[0x64] and 32/w, 32/h; this vslot 0x25c(0, &verts, 4, &idx, 4)
// with idx {0,1,2,3} and 4 vertices (x y z u v defined); finally state 0x17 = 4.
extern "C" void THISCALL GUESS_60c100(u32 self, u32 unused) {
  (void)unused;
  float M[16];
  for (int i = 0; i < 16; i++) M[i] = 0.0f;
  M[0] = M[5] = M[10] = M[15] = 1.0f;
  u32 dev = w6ld(self + 0x1377);
  ((W6S3)*(u32 *)(*(u32 *)dev + 0x94))(dev, 3, (u32)M);
  dev = w6ld(self + 0x1377);
  ((W6S3)*(u32 *)(*(u32 *)dev + 0x94))(dev, 2, (u32)M);
  dev = w6ld(self + 0x1377);
  ((W6S3)*(u32 *)(*(u32 *)dev + 0x94))(dev, 0x100, (u32)M);
  dev = w6ld(self + 0x1377);
  ((W6S3)*(u32 *)(*(u32 *)dev + 0x94))(dev, 0x10, (u32)M);
  ext_60ff30_w6(0, 2, 2, 1);
  if (*(u32 *)0x724a08 > 1) ext_60ff30_w6(1, 1, 2, 1);
  ext_60feb0_w6(0, 2, 2, 1);
  if (*(u32 *)0x724a08 > 1) ext_60feb0_w6(1, 1, 2, 1);
  u32 d;
  if (*(u32 *)0x724928 != 5) { d = *(u32 *)0x724a00; *(u32 *)0x724928 = 5; w6rs(d, 0x13, 5); }
  if (*(u32 *)0x72492c != 6) { d = *(u32 *)0x724a00; *(u32 *)0x72492c = 6; w6rs(d, 0x14, 6); }
  if (*(u32 *)0x724934 != 1) { d = *(u32 *)0x724a00; *(u32 *)0x724934 = 1; w6rs(d, 0x1b, 1); }
  if (*(u32 *)0x72493c != 0) { d = *(u32 *)0x724a00; *(u32 *)0x72493c = 0; w6rs(d, 0xe, 0); }
  d = *(u32 *)0x724a00;
  w6rs(d, 0x17, 8);
  u32 tex = *(u32 *)0x724ad8;
  if (*(u32 *)0x724848 != tex) {
    d = *(u32 *)0x724a00;
    *(u32 *)0x724848 = tex;
    ((W6S3)*(u32 *)(*(u32 *)d + 0xf4))(d, 0, tex);
  }
  u32 idx[2] = {0x10000, 0x30002};
  float K1 = *(float *)0x6b7f68;
  s32 iw = ((W6I0)*(u32 *)(*(u32 *)self + 0xd8))(self);
  float invW = K1 / (float)iw;
  s32 ih = ((W6I0)*(u32 *)(*(u32 *)self + 0xdc))(self);
  float hK = K1 / (float)ih;
  float half = *(float *)0x67a6ac;
  float a4 = bitsf(*(u32 *)(self + 0x60));
  a4 = a4 + a4;
  float a5 = bitsf(*(u32 *)(self + 0x64));
  float x2 = invW * half;
  a5 = a5 + a5;
  float x1 = hK * half;
  float x4 = a4 - x2;
  float c2 = x2 + 0.0f;
  a5 = a5 + x1;
  float c7 = 0.0f - x1;
  float x0 = x4 + invW;
  float n5 = bitsf(fbits(a5) ^ 0x80000000u);
  float c1 = c2 + *(float *)0x678858;
  float d7 = c7 + *(float *)0x678858;
  float d5 = n5 + hK;
  u32 V[36];
  for (int i = 0; i < 36; i++) V[i] = 0;
  u32 *W = V;
  W[0] = fbits(x4); W[1] = fbits(n5); W[2] = 0; W[7] = fbits(c2); W[8] = fbits(c7);
  W[9] = fbits(x0); W[10] = fbits(n5); W[11] = 0; W[16] = fbits(c1); W[17] = fbits(c7);
  W[18] = fbits(x4); W[19] = fbits(d5); W[20] = 0; W[25] = fbits(c2); W[26] = fbits(d7);
  W[27] = fbits(x0); W[28] = fbits(d5); W[29] = 0; W[34] = fbits(c1); W[35] = fbits(d7);
  ((W6A5)*(u32 *)(*(u32 *)self + 0x25c))(self, 0, (u32)V, 4, (u32)idx, 4);
  d = *(u32 *)0x724a00;
  w6rs(d, 0x17, 4);
}
PCREG(60c100, GUESS_60c100);

// ---------------------------------------------------------------- 0x63d4a0
extern "C" u32 THISCALL ext_6493f0_w6(u32) __asm__("ext_6493f0");
extern "C" u32 THISCALL ext_64b0b0_w6(u32) __asm__("ext_64b0b0");
extern "C" u32 THISCALL ext_65ca30_w6(u32, u32, u32) __asm__("ext_65ca30");
extern "C" u32 THISCALL ext_65d070_w6(u32, u32, u32) __asm__("ext_65d070");
extern "C" u32 THISCALL ext_65cc70_w6(u32) __asm__("ext_65cc70");
extern "C" u32 THISCALL ext_65c9d0_w6(u32) __asm__("ext_65c9d0");
extern "C" u32 THISCALL ext_65ca60_w6(u32, u32) __asm__("ext_65ca60");
extern "C" u32 THISCALL ext_65c9f0_w6(u32) __asm__("ext_65c9f0");
extern "C" u32 THISCALL ext_65ca20_w6(u32) __asm__("ext_65ca20");
extern "C" u32 THISCALL ext_65c9e0_w6(u32) __asm__("ext_65c9e0");
extern "C" u32 THISCALL ext_65ca00_w6(u32, u32) __asm__("ext_65ca00");

// 0x63d4a0: thiscall(arr, n) ret 8, void (own frame of 0x1468 bytes via __chkstk: the container objects O1 / O2 and the 0x1000-byte buffer are local arrays; /GS cookie not reproduced).
// 0x6493f0 on every arr[i]; then, while any arr[i] vslot 0x28(pass) returns true (pass 0, 1, ...): in pass 0, when G[0x8f] != 0 and e = G[0x9b][0x5d35] != 0 (unaligned): debug
// 0x259 (slot 0x178, text 0x6c27f0), O1 = 0x65ca30(buf, 0x1000), the iterator of the set at this+0x204 (its vslot 0xc(&tmp) -> {cur, idx, node}; items cur -> 0x65d070(O1, e, item[0x38])
// with the inline {count@0, next@8, items@0x10} advance), 0x65cc70(O1), 0x65c9d0(O1), this vslot 0xd0(), O2 = 0x65ca60(buf), count = 0x65c9f0(O2): for each record R (0x65ca20) with R[8] > 0
// items (0x65c9e0, 0x65ca00(item[4])): this vslot 0xd8(R[0], item[0], 0x65ca00 result, item[4]); this vslot 0xd4(); debug 0x260 (slot 0x17c). Finally 0x64b0b0 on every arr[i].
extern "C" void THISCALL GUESS_63d4a0(u32 self, u32 arr, u32 n) {
  u8 O1[0x470] __attribute__((aligned(16)));
  u8 BUF[0x1010] __attribute__((aligned(16)));
  u8 O2[0x40] __attribute__((aligned(16)));
  u32 tmp[4];
  for (u32 i = 0; i < n; i++) ext_6493f0_w6(((u32 *)arr)[i]);
  u32 c = 0;
  u8 flag;
  do {
    flag = 0;
    if (n) {
      u8 bl = flag;
      for (u32 i = 0; i < n; i++) {
        u32 o = ((u32 *)arr)[i];
        bl |= (u8)((W6T1)*(u32 *)(*(u32 *)o + 0x28))(o, c);
      }
      flag = bl;
    }
    u32 e = c;
    c++;
    if (e == 0) {
      u32 g = *(u32 *)0x70039c;
      if (w6ld(g + 0x8f) != 0) {
        u32 e2 = w6ld(w6ld(g + 0x9b) + 0x5d35);
        if (e2 != 0) {
          w6dbg(g, 0x259, 0x178, 0x6c27f0);
          ext_65ca30_w6((u32)O1, (u32)BUF, 0x1000);
          u32 obj204 = self + 0x204;
          u32 P = ((W6T1)*(u32 *)(*(u32 *)obj204 + 0xc))(obj204, (u32)tmp);
          u32 edi = *(u32 *)P, ebx = *(u32 *)(P + 4), esi = *(u32 *)(P + 8);
          if (edi != 0) {
            do {
              u32 it = *(u32 *)edi;
              ext_65d070_w6((u32)O1, e2, *(u32 *)(it + 0x38));
              ebx++;
              if (ebx != *(u32 *)esi) {
                edi += 4;
              } else {
                esi = *(u32 *)(esi + 8);
                if (esi == 0) break;
                ebx = 0;
                edi = esi + 0x10;
              }
            } while (edi != 0);
          }
          ext_65cc70_w6((u32)O1);
          ext_65c9d0_w6((u32)O1);
          ((W6B)*(u32 *)(*(u32 *)self + 0xd0))(self);
          ext_65ca60_w6((u32)O2, (u32)BUF);
          s32 cnt = (s32)ext_65c9f0_w6((u32)O2);
          if (cnt > 0) {
            do {
              u32 R = ext_65ca20_w6((u32)O2);
              u32 id = *(u32 *)R;
              s32 k = 0;
              if ((s32)*(u32 *)(R + 8) > 0) {
                do {
                  u32 item = ext_65c9e0_w6((u32)O2);
                  u32 a = ext_65ca00_w6((u32)O2, *(u32 *)(item + 4));
                  ((W6A4)*(u32 *)(*(u32 *)self + 0xd8))(self, id, *(u32 *)item, a, *(u32 *)(item + 4));
                  k++;
                } while (k < (s32)*(u32 *)(R + 8));
              }
              cnt--;
            } while (cnt != 0);
          }
          ((W6B)*(u32 *)(*(u32 *)self + 0xd4))(self);
          w6dbg(*(u32 *)0x70039c, 0x260, 0x17c, 0x6c27f0);
        }
      }
    }
  } while (flag);
  for (u32 i = 0; i < n; i++) ext_64b0b0_w6(((u32 *)arr)[i]);
}
PCREG(63d4a0, GUESS_63d4a0);

// ---------------------------------------------------------------- 0x6281a0
extern "C" u32 ext_62c640_w6(u32, u32) __asm__("ext_62c640");
extern "C" u32 ext_626ed0_w6(u32, u32, u32, u32) __asm__("ext_626ed0");

static inline u32 w6cls2(u32 enc, u8 dl, u8 cl) {
  if (dl == 0) return *(u8 *)(enc + 0x4c + cl);
  return ext_62c640_w6(dl, cl);
}
static inline bool w6tab(u32 tabaddr, u8 dl, u8 cl) {
  u32 edx = (u32)*(u8 *)(tabaddr + dl);
  u32 bit = 1u << (cl & 0x1f);
  return (*(u32 *)(0x6bf720 + ((u32)(cl >> 5) + edx * 8) * 4) & bit) != 0;
}

// 0x6281a0: cdecl(enc, ptr, end, nextTok) -> token type (an XML processing-instruction / name scanner for 2-byte characters; expat). The three jump-table dispatches are
// driven by the exe's own tables (dword tables at 0x6283d4 / 0x628408 / 0x628444, byte index tables at 0x6283ec / 0x628428 / 0x62845c) and switch on the handler addresses.
// ptr == end -> -1; class = (hi == 0) ? enc[0x4c + lo] : 0x62c640(hi, lo); incomplete multi-byte (-2); default: *nextTok = pos, 0; a PI target is checked with 0x626ed0(enc, start, pos, &tok)
// (tok 11 / 12, error -> 0); "?>" (0x00 0x3e) ends the token: *nextTok = pos + 2, returns tok.
extern "C" s32 GUESS_6281a0(u32 enc, u32 ptr, u32 end, u32 nextTok) {
  u32 start = ptr;
  u32 esi = ptr, edi = end;
  u32 tok = 0;
  if (esi == edi) return -1;
  u8 dl = *(u8 *)esi, cl = *(u8 *)(esi + 1);
  u32 cls = w6cls2(enc, dl, cl);
  bool first = true;
  for (;;) {
    u32 k = cls - 5;
    u32 h;
    if (k > 0x18) { *(u32 *)nextTok = esi; return 0; }
    if (first) h = *(u32 *)(0x6283d4 + 4 * (u32)*(u8 *)(0x6283ec + k));
    else h = *(u32 *)(0x628408 + 4 * (u32)*(u8 *)(0x628428 + k));
    switch (h) {
      case 0x6282a4: if ((s32)(edi - esi) >= 2) goto def; return -2;
      case 0x6282bb: if ((s32)(edi - esi) >= 3) goto def; return -2;
      case 0x6283b3: if ((s32)(edi - esi) >= 4) goto def; return -2;
      case 0x628223:
        esi += 2;
        if (esi == edi) return -1;
        break;
      case 0x6281f7:
        if (!w6tab(0x6bfc20, dl, cl)) goto def;
        esi += 2;
        if (esi == edi) return -1;
        break;
      case 0x628267:
        if (!w6tab(0x6bfd20, dl, cl)) goto def;
        esi += 2;
        if (esi == edi) return -1;
        break;
      case 0x628293:
        esi += 2;
        if (esi == edi) return -1;
        break;
      case 0x628376: {
        if (ext_626ed0_w6(enc, start, esi, (u32)&tok) == 0) goto def;
        esi += 2;
        if (esi == edi) return -1;
        if (*(u8 *)esi != 0) goto def;
        if (*(u8 *)(esi + 1) != 0x3e) goto def;
        goto fin;
      }
      case 0x6282d2: {
        if (ext_626ed0_w6(enc, start, esi, (u32)&tok) == 0) goto def;
        esi += 2;
        if (esi == edi) return -1;
        s32 ecx = (s32)(edi - esi);
        for (;;) {
          u8 d2 = *(u8 *)esi;
          u32 lo = *(u8 *)(esi + 1);
          u32 c2 = (d2 == 0) ? (u32)*(u8 *)(enc + 0x4c + lo) : ext_62c640_w6(d2, lo);
          u32 h3;
          if (c2 > 0xf) h3 = 0x62832d;
          else h3 = *(u32 *)(0x628444 + 4 * (u32)*(u8 *)(0x62845c + c2));
          bool adv2 = false;
          switch (h3) {
            case 0x6283c6: goto def;
            case 0x628324: if (ecx < 2) return -2; adv2 = true; break;
            case 0x628341: if (ecx < 3) return -2; esi += 3; ecx -= 3; if (esi == edi) return -1; continue;
            case 0x62834e: if (ecx < 4) return -2; esi += 4; ecx -= 4; if (esi == edi) return -1; continue;
            case 0x62835b:
              esi += 2; ecx -= 2;
              if (esi == edi) return -1;
              if (*(u8 *)esi == 0 && *(u8 *)(esi + 1) == 0x3e) goto fin;
              continue;
            default: adv2 = true; break;
          }
          if (adv2) {
            esi += 2; ecx -= 2;
            if (esi == edi) return -1;
          }
        }
      }
      default:
      def:
        *(u32 *)nextTok = esi;
        return 0;
    }
    first = false;
    dl = *(u8 *)esi; cl = *(u8 *)(esi + 1);
    cls = w6cls2(enc, dl, cl);
  }
fin:
  *(u32 *)nextTok = esi + 2;
  return (s32)tok;
}
PCREG(6281a0, GUESS_6281a0);

// ---------------------------------------------------------------- 0x62a200
extern "C" u32 ext_628f30_w6(u32, u32, u32, u32) __asm__("ext_628f30");
// 0x62a200: little-endian twin of 0x6281a0 (unit bytes swapped: hi = ptr[1], lo = ptr[0]; target check 0x628f30; tables 0x62a434 / 0x62a44c / 0x62a468 / 0x62a488 / 0x62a4a4 / 0x62a4bc). cdecl(enc, ptr, end, nextTok) -> token type (an XML processing-instruction / name scanner for 2-byte characters; expat). The three jump-table dispatches are
// driven by the exe's own tables (dword tables at 0x62a434 / 0x62a468 / 0x62a4a4, byte index tables at 0x62a44c / 0x62a488 / 0x62a4bc) and switch on the handler addresses.
// ptr == end -> -1; class = (hi == 0) ? enc[0x4c + lo] : 0x62c640(hi, lo); incomplete multi-byte (-2); default: *nextTok = pos, 0; a PI target is checked with 0x626ed0(enc, start, pos, &tok)
// (tok 11 / 12, error -> 0); "?>" (0x00 0x3e) ends the token: *nextTok = pos + 2, returns tok.
extern "C" s32 GUESS_62a200(u32 enc, u32 ptr, u32 end, u32 nextTok) {
  u32 start = ptr;
  u32 esi = ptr, edi = end;
  u32 tok = 0;
  if (esi == edi) return -1;
  u8 dl = *(u8 *)(esi + 1), cl = *(u8 *)esi;
  u32 cls = w6cls2(enc, dl, cl);
  bool first = true;
  for (;;) {
    u32 k = cls - 5;
    u32 h;
    if (k > 0x18) { *(u32 *)nextTok = esi; return 0; }
    if (first) h = *(u32 *)(0x62a434 + 4 * (u32)*(u8 *)(0x62a44c + k));
    else h = *(u32 *)(0x62a468 + 4 * (u32)*(u8 *)(0x62a488 + k));
    switch (h) {
      case 0x62a304: if ((s32)(edi - esi) >= 2) goto def; return -2;
      case 0x62a31b: if ((s32)(edi - esi) >= 3) goto def; return -2;
      case 0x62a413: if ((s32)(edi - esi) >= 4) goto def; return -2;
      case 0x62a283:
        esi += 2;
        if (esi == edi) return -1;
        break;
      case 0x62a257:
        if (!w6tab(0x6bfc20, dl, cl)) goto def;
        esi += 2;
        if (esi == edi) return -1;
        break;
      case 0x62a2c7:
        if (!w6tab(0x6bfd20, dl, cl)) goto def;
        esi += 2;
        if (esi == edi) return -1;
        break;
      case 0x62a2f3:
        esi += 2;
        if (esi == edi) return -1;
        break;
      case 0x62a3d6: {
        if (ext_628f30_w6(enc, start, esi, (u32)&tok) == 0) goto def;
        esi += 2;
        if (esi == edi) return -1;
        if (*(u8 *)(esi + 1) != 0) goto def;
        if (*(u8 *)esi != 0x3e) goto def;
        goto fin;
      }
      case 0x62a332: {
        if (ext_628f30_w6(enc, start, esi, (u32)&tok) == 0) goto def;
        esi += 2;
        if (esi == edi) return -1;
        s32 ecx = (s32)(edi - esi);
        for (;;) {
          u8 d2 = *(u8 *)(esi + 1);
          u32 lo = *(u8 *)esi;
          u32 c2 = (d2 == 0) ? (u32)*(u8 *)(enc + 0x4c + lo) : ext_62c640_w6(d2, lo);
          u32 h3;
          if (c2 > 0xf) h3 = 0x62a38d;
          else h3 = *(u32 *)(0x62a4a4 + 4 * (u32)*(u8 *)(0x62a4bc + c2));
          bool adv2 = false;
          switch (h3) {
            case 0x62a426: goto def;
            case 0x62a384: if (ecx < 2) return -2; adv2 = true; break;
            case 0x62a3a1: if (ecx < 3) return -2; esi += 3; ecx -= 3; if (esi == edi) return -1; continue;
            case 0x62a3ae: if (ecx < 4) return -2; esi += 4; ecx -= 4; if (esi == edi) return -1; continue;
            case 0x62a3bb:
              esi += 2; ecx -= 2;
              if (esi == edi) return -1;
              if (*(u8 *)(esi + 1) == 0 && *(u8 *)esi == 0x3e) goto fin;
              continue;
            default: adv2 = true; break;
          }
          if (adv2) {
            esi += 2; ecx -= 2;
            if (esi == edi) return -1;
          }
        }
      }
      default:
      def:
        *(u32 *)nextTok = esi;
        return 0;
    }
    first = false;
    dl = *(u8 *)(esi + 1); cl = *(u8 *)esi;
    cls = w6cls2(enc, dl, cl);
  }
fin:
  *(u32 *)nextTok = esi + 2;
  return (s32)tok;
}
PCREG(62a200, GUESS_62a200);

// ---------------------------------------------------------------- 0x622650
extern "C" s32 ext_629c10_w6(u32, u32, u32, u32) __asm__("ext_629c10");
extern "C" s32 ext_62a690_w6(u32, u32, u32, u32) __asm__("ext_62a690");

// 0x622650: cdecl(enc, ptr, end, nextTok) -> token type (expat content tokenizer for little-endian 2-byte characters; unit hi = p[1], lo = p[0]). ptr == end -> -4; odd length: the
// end is rounded down (a single byte -> -1). Class of the first unit (enc[0x4c + lo] when hi == 0, else 0x62c640(hi, lo)); the first dispatch is the exe's table 0x622848 (classes
// 0, 1, 8 -> *next = p, 0; 2 -> 0x629c10(enc, p + 2, end, next); 3 -> 0x62a690(...); 4 -> "]]>" handling (-5 when the data ends); 5 / 6 / 7 -> need 2 / 3 / 4 bytes (-2) then
// skip; 9 -> CR: -3 at the end, a following LF is consumed; *next = p + 2, 7; 10 -> LF: *next = p + 2, 7; others skip 2). Then the data loop with the byte table 0x622888
// and dword table 0x622874: stops (*next = p, 6) on classes 0..3, 8..10, on incomplete multi-byte units and at the end; class 4 with "]>" following ends with *next = p + 4, 0.
extern "C" s32 GUESS_622650(u32 enc, u32 ptr, u32 end, u32 nextTok) {
  u32 ecx = ptr, edx = end, start = ptr;
  if (ecx == edx) return -4;
  u32 diff = edx - ecx;
  if (diff & 1) {
    diff &= ~1u;
    if (diff == 0) return -1;
    edx = diff + ecx;
  }
  u32 cls = w6cls2(enc, *(u8 *)(ecx + 1), *(u8 *)ecx);
  if (cls > 10) {
    ecx += 2;
  } else {
    u32 h = *(u32 *)(0x622848 + 4 * cls);
    switch (h) {
      case 0x62283b: *(u32 *)nextTok = ecx; return 0;
      case 0x6226ae: return ext_629c10_w6(enc, ecx + 2, edx, nextTok);
      case 0x6226c4: return ext_62a690_w6(enc, ecx + 2, edx, nextTok);
      case 0x62271e: {
        ecx += 2;
        u32 save = ecx;
        if (ecx == edx) return -5;
        if (*(u8 *)(ecx + 1) != 0 || *(u8 *)ecx != 0x5d) break;
        ecx += 2;
        if (ecx == edx) return -5;
        if (*(u8 *)(ecx + 1) == 0 && *(u8 *)ecx == 0x3e) { *(u32 *)nextTok = ecx; return 0; }
        ecx = save;
        break;
      }
      case 0x622756: if ((s32)(edx - ecx) < 2) return -2; ecx += 2; break;
      case 0x622769: if ((s32)(edx - ecx) < 3) return -2; ecx += 3; break;
      case 0x622777: if ((s32)(edx - ecx) < 4) return -2; ecx += 4; break;
      case 0x6226da: {
        ecx += 2;
        if (ecx == edx) return -3;
        u32 c2 = w6cls2(enc, *(u8 *)(ecx + 1), *(u8 *)ecx);
        if (c2 != 10) ecx = start;
        ecx += 2;
        *(u32 *)nextTok = ecx;
        return 7;
      }
      case 0x62270c:
        ecx += 2;
        *(u32 *)nextTok = ecx;
        return 7;
      default: *(u32 *)nextTok = ecx; return 0;
    }
  }
  while (ecx != edx) {
    u32 c = w6cls2(enc, *(u8 *)(ecx + 1), *(u8 *)ecx);
    u32 step = 2;
    if (c <= 10) {
      u32 h = *(u32 *)(0x622874 + 4 * (u32)*(u8 *)(0x622888 + c));
      if (h == 0x6227c7) { *(u32 *)nextTok = ecx; return 6; }
      else if (h == 0x6227be) { if ((s32)(edx - ecx) < 2) { *(u32 *)nextTok = ecx; return 6; } }
      else if (h == 0x6227d6) { if ((s32)(edx - ecx) < 3) { *(u32 *)nextTok = ecx; return 6; } step = 3; }
      else if (h == 0x6227e6) { if ((s32)(edx - ecx) < 4) { *(u32 *)nextTok = ecx; return 6; } step = 4; }
      else if (h == 0x6227f6) {
        u32 e2 = ecx + 2;
        if (e2 == edx) { *(u32 *)nextTok = ecx; return 6; }
        if (*(u8 *)(ecx + 3) == 0 && *(u8 *)e2 == 0x5d) {
          u32 e4 = ecx + 4;
          if (e4 == edx) { *(u32 *)nextTok = ecx; return 6; }
          if (*(u8 *)(ecx + 5) == 0 && *(u8 *)e4 == 0x3e) { *(u32 *)nextTok = e4; return 0; }
        }
      }
    }
    ecx += step;
  }
  *(u32 *)nextTok = ecx;
  return 6;
}
PCREG(622650, GUESS_622650);

// ---------------------------------------------------------------- 0x624100
extern "C" s32 ext_627bb0_w6(u32, u32, u32, u32) __asm__("ext_627bb0");
extern "C" s32 ext_628630_w6(u32, u32, u32, u32) __asm__("ext_628630");
// 0x624100: cdecl(enc, ptr, end, nextTok) -> token type (expat content tokenizer for little-endian 2-byte characters; unit hi = p[1], lo = p[0]). ptr == end -> -4; odd length: the
// end is rounded down (a single byte -> -1). Class of the first unit (enc[0x4c + lo] when hi == 0, else 0x62c640(hi, lo)); the first dispatch is the exe's table 0x6242f8 (classes
// 0, 1, 8 -> *next = p, 0; 2 -> 0x629c10(enc, p + 2, end, next); 3 -> 0x62a690(...); 4 -> "]]>" handling (-5 when the data ends); 5 / 6 / 7 -> need 2 / 3 / 4 bytes (-2) then
// skip; 9 -> CR: -3 at the end, a following LF is consumed; *next = p + 2, 7; 10 -> LF: *next = p + 2, 7; others skip 2). Then the data loop with the byte table 0x624338
// and dword table 0x624324: stops (*next = p, 6) on classes 0..3, 8..10, on incomplete multi-byte units and at the end; class 4 with "]>" following ends with *next = p + 4, 0.
extern "C" s32 GUESS_624100(u32 enc, u32 ptr, u32 end, u32 nextTok) {
  u32 ecx = ptr, edx = end, start = ptr;
  if (ecx == edx) return -4;
  u32 diff = edx - ecx;
  if (diff & 1) {
    diff &= ~1u;
    if (diff == 0) return -1;
    edx = diff + ecx;
  }
  u32 cls = w6cls2(enc, *(u8 *)ecx, *(u8 *)(ecx + 1));
  if (cls > 10) {
    ecx += 2;
  } else {
    u32 h = *(u32 *)(0x6242f8 + 4 * cls);
    switch (h) {
      case 0x6242eb: *(u32 *)nextTok = ecx; return 0;
      case 0x62415e: return ext_627bb0_w6(enc, ecx + 2, edx, nextTok);
      case 0x624174: return ext_628630_w6(enc, ecx + 2, edx, nextTok);
      case 0x6241ce: {
        ecx += 2;
        u32 save = ecx;
        if (ecx == edx) return -5;
        if (*(u8 *)ecx != 0 || *(u8 *)(ecx + 1) != 0x5d) break;
        ecx += 2;
        if (ecx == edx) return -5;
        if (*(u8 *)ecx == 0 && *(u8 *)(ecx + 1) == 0x3e) { *(u32 *)nextTok = ecx; return 0; }
        ecx = save;
        break;
      }
      case 0x624206: if ((s32)(edx - ecx) < 2) return -2; ecx += 2; break;
      case 0x624219: if ((s32)(edx - ecx) < 3) return -2; ecx += 3; break;
      case 0x624227: if ((s32)(edx - ecx) < 4) return -2; ecx += 4; break;
      case 0x62418a: {
        ecx += 2;
        if (ecx == edx) return -3;
        u32 c2 = w6cls2(enc, *(u8 *)ecx, *(u8 *)(ecx + 1));
        if (c2 != 10) ecx = start;
        ecx += 2;
        *(u32 *)nextTok = ecx;
        return 7;
      }
      case 0x6241bc:
        ecx += 2;
        *(u32 *)nextTok = ecx;
        return 7;
      default: *(u32 *)nextTok = ecx; return 0;
    }
  }
  while (ecx != edx) {
    u32 c = w6cls2(enc, *(u8 *)ecx, *(u8 *)(ecx + 1));
    u32 step = 2;
    if (c <= 10) {
      u32 h = *(u32 *)(0x624324 + 4 * (u32)*(u8 *)(0x624338 + c));
      if (h == 0x624277) { *(u32 *)nextTok = ecx; return 6; }
      else if (h == 0x62426e) { if ((s32)(edx - ecx) < 2) { *(u32 *)nextTok = ecx; return 6; } }
      else if (h == 0x624286) { if ((s32)(edx - ecx) < 3) { *(u32 *)nextTok = ecx; return 6; } step = 3; }
      else if (h == 0x624296) { if ((s32)(edx - ecx) < 4) { *(u32 *)nextTok = ecx; return 6; } step = 4; }
      else if (h == 0x6242a6) {
        u32 e2 = ecx + 2;
        if (e2 == edx) { *(u32 *)nextTok = ecx; return 6; }
        if (*(u8 *)e2 == 0 && *(u8 *)(ecx + 3) == 0x5d) {
          u32 e4 = ecx + 4;
          if (e4 == edx) { *(u32 *)nextTok = ecx; return 6; }
          if (*(u8 *)e4 == 0 && *(u8 *)(ecx + 5) == 0x3e) { *(u32 *)nextTok = e4; return 0; }
        }
      }
    }
    ecx += step;
  }
  *(u32 *)nextTok = ecx;
  return 6;
}
PCREG(624100, GUESS_624100);

// ---------------------------------------------------------------- 0x623be0
extern "C" s32 ext_62b450_w6(u32, u32, u32, u32) __asm__("ext_62b450");
extern "C" s32 ext_62c060_w6(u32, u32, u32, u32) __asm__("ext_62c060");
typedef s32 (*W6Pred)(u32, u32);

// 0x623be0: cdecl(enc, ptr, end, nextTok) -> token type (expat content tokenizer for a 1-byte encoding; class = enc[0x4c + *p]; the multi-byte lead classes 5 / 6 / 7 call the
// encoding's predicates enc[0x164] / [0x168] / [0x16c](enc, p) (cdecl): a non-zero result ends the token with *next = p, 0). Same structure as 0x622650: ptr == end -> -4; table 0x623df0
// for the first unit (classes 0 / 1 / 8 -> *next = p, 0; 2 -> 0x62b450(enc, p + 1, end, next); 3 -> 0x62c060(...); 4 -> "]]>" (-5 at the end); 5 / 6 / 7 -> -2 when short, predicate,
// skip 2 / 3 / 4; 9 -> CR (-3 at the end, a following LF consumed, 7); 10 -> LF (7); others skip 1), then the data loop with byte table 0x623e30 / dword table 0x623e1c (stop:
// *next = p, 6; "]]>" -> *next = p + 2, 0).
extern "C" s32 GUESS_623be0(u32 enc, u32 ptr, u32 end, u32 nextTok) {
  u32 esi = ptr, edi = end, start = ptr;
  if (esi == edi) return -4;
  u32 cls = *(u8 *)(enc + 0x4c + *(u8 *)esi);
  if (cls > 10) {
    esi++;
  } else {
    u32 h = *(u32 *)(0x623df0 + 4 * cls);
    switch (h) {
      case 0x623c16: return ext_62b450_w6(enc, esi + 1, edi, nextTok);
      case 0x623c2c: return ext_62c060_w6(enc, esi + 1, edi, nextTok);
      case 0x623c42: {
        esi++;
        if (esi == edi) return -3;
        if (*(u8 *)(enc + 0x4c + *(u8 *)esi) != 10) esi = start;
        esi++;
        *(u32 *)nextTok = esi;
        return 7;
      }
      case 0x623c6c: *(u32 *)nextTok = esi + 1; return 7;
      case 0x623c7e: {
        esi++;
        u32 save = esi;
        if (esi == edi) return -5;
        if (*(u8 *)esi != 0x5d) break;
        esi++;
        if (esi == edi) return -5;
        if (*(u8 *)esi == 0x3e) { *(u32 *)nextTok = esi; return 0; }
        esi = save;
        break;
      }
      case 0x623ca6:
        if ((s32)(edi - esi) < 2) return -2;
        if (((W6Pred)*(u32 *)(enc + 0x164))(enc, esi) != 0) { *(u32 *)nextTok = esi; return 0; }
        esi += 2;
        break;
      case 0x623cc5:
        if ((s32)(edi - esi) < 3) return -2;
        if (((W6Pred)*(u32 *)(enc + 0x168))(enc, esi) != 0) { *(u32 *)nextTok = esi; return 0; }
        esi += 3;
        break;
      case 0x623ce4:
        if ((s32)(edi - esi) < 4) return -2;
        if (((W6Pred)*(u32 *)(enc + 0x16c))(enc, esi) != 0) { *(u32 *)nextTok = esi; return 0; }
        esi += 4;
        break;
      default: *(u32 *)nextTok = esi; return 0;
    }
  }
  while (esi != edi) {
    u32 c = *(u8 *)(enc + 0x4c + *(u8 *)esi);
    u32 step = 1;
    if (c <= 10) {
      u32 h = *(u32 *)(0x623e1c + 4 * (u32)*(u8 *)(0x623e30 + c));
      if (h == 0x623dcf) { *(u32 *)nextTok = esi; return 6; }
      else if (h == 0x623d41) {
        if ((s32)(edi - esi) < 2) { *(u32 *)nextTok = esi; return 6; }
        if (((W6Pred)*(u32 *)(enc + 0x164))(enc, esi) != 0) { *(u32 *)nextTok = esi; return 6; }
        step = 2;
      } else if (h == 0x623d66) {
        if ((s32)(edi - esi) < 3) { *(u32 *)nextTok = esi; return 6; }
        if (((W6Pred)*(u32 *)(enc + 0x168))(enc, esi) != 0) { *(u32 *)nextTok = esi; return 6; }
        step = 3;
      } else if (h == 0x623d87) {
        if ((s32)(edi - esi) < 4) { *(u32 *)nextTok = esi; return 6; }
        if (((W6Pred)*(u32 *)(enc + 0x16c))(enc, esi) != 0) { *(u32 *)nextTok = esi; return 6; }
        step = 4;
      } else if (h == 0x623da8) {
        u32 e1 = esi + 1;
        if (e1 == edi) { *(u32 *)nextTok = esi; return 6; }
        if (*(u8 *)e1 == 0x5d) {
          u32 e2 = esi + 2;
          if (e2 == edi) { *(u32 *)nextTok = esi; return 6; }
          if (*(u8 *)e2 == 0x3e) { *(u32 *)nextTok = e2; return 0; }
        }
      }
    }
    esi += step;
  }
  *(u32 *)nextTok = esi;
  return 6;
}
PCREG(623be0, GUESS_623be0);

// ---------------------------------------------------------------- 0x62bb10
extern "C" u32 ext_62a870_w6(u32, u32, u32, u32) __asm__("ext_62a870");

// 0x62bb10: cdecl(enc, ptr, end, nextTok) -> token type (expat processing-instruction scanner for a 1-byte encoding; class = enc[0x4c + *p]). ptr == end -> -1. Stage 1 (first byte,
// table 0x62bdc0 / 0x62bdd8): classes 5 / 6 / 7 are multi-byte name-start leads (need 2 / 3 / 4 bytes, else -2; predicate enc[0x158] / [0x15c] / [0x160](enc, p) must be non-zero, else
// default), classes 22 / 24 step 1, everything else default (*next = p, 0). Stage 2 (name characters, table 0x62bdf4 / 0x62be14): leads with predicates enc[0x14c] / [0x150] / [0x154],
// step-1 classes, and the PI-target classes (0x62bc96: 0x62a870(enc, start, p, &tok) must be non-zero, then content scanning; 0x62bd7c: the same, then '>' must follow). Stage 3
// (content, table 0x62be30 / 0x62be48): leads with predicates enc[0x164] / [0x168] / [0x16c] (non-zero -> default), class 15 '?' followed by '>' ends with *next = p + 1, tok.
extern "C" s32 GUESS_62bb10(u32 enc, u32 ptr, u32 end, u32 nextTok) {
  u32 start = ptr;
  u32 esi = ptr, edi = end;
  u32 tok = 0;
  if (esi == edi) return -1;
  u32 cls = *(u8 *)(enc + 0x4c + *(u8 *)esi);
  u32 k = cls - 5;
  if (k > 0x18) goto def;
  {
    u32 h = *(u32 *)(0x62bdc0 + 4 * (u32)*(u8 *)(0x62bdd8 + k));
    u32 step;
    switch (h) {
      case 0x62bb52: step = 1; break;
      case 0x62bb59:
        if ((s32)(edi - esi) < 2) return -2;
        if (((W6Pred)*(u32 *)(enc + 0x158))(enc, esi) == 0) goto def;
        step = 2; break;
      case 0x62bb82:
        if ((s32)(edi - esi) < 3) return -2;
        if (((W6Pred)*(u32 *)(enc + 0x15c))(enc, esi) == 0) goto def;
        step = 3; break;
      case 0x62bbab:
        if ((s32)(edi - esi) < 4) return -2;
        if (((W6Pred)*(u32 *)(enc + 0x160))(enc, esi) == 0) goto def;
        step = 4; break;
      default: goto def;
    }
    esi += step;
    if (esi == edi) return -1;
  }
  for (;;) {
    cls = *(u8 *)(enc + 0x4c + *(u8 *)esi);
    k = cls - 5;
    if (k > 0x18) goto def;
    u32 h = *(u32 *)(0x62bdf4 + 4 * (u32)*(u8 *)(0x62be14 + k));
    u32 step;
    switch (h) {
      case 0x62bc02: step = 1; break;
      case 0x62bc09:
        if ((s32)(edi - esi) < 2) return -2;
        if (((W6Pred)*(u32 *)(enc + 0x14c))(enc, esi) == 0) goto def;
        step = 2; break;
      case 0x62bc32:
        if ((s32)(edi - esi) < 3) return -2;
        if (((W6Pred)*(u32 *)(enc + 0x150))(enc, esi) == 0) goto def;
        step = 3; break;
      case 0x62bc5b:
        if ((s32)(edi - esi) < 4) return -2;
        if (((W6Pred)*(u32 *)(enc + 0x154))(enc, esi) == 0) goto def;
        step = 4; break;
      case 0x62bd7c:
        if (ext_62a870_w6(enc, start, esi, (u32)&tok) == 0) goto def;
        esi++;
        if (esi == edi) return -1;
        if (*(u8 *)esi != 0x3e) goto def;
        *(u32 *)nextTok = esi + 1;
        return (s32)tok;
      case 0x62bc96: {
        if (ext_62a870_w6(enc, start, esi, (u32)&tok) == 0) goto def;
        esi++;
        if (esi == edi) return -1;
        s32 rem = (s32)(edi - esi);
        for (;;) {
          u32 c3 = *(u8 *)(enc + 0x4c + *(u8 *)esi);
          if (c3 > 0xf) {
            esi++; rem--;
          } else {
            u32 h3 = *(u32 *)(0x62be30 + 4 * (u32)*(u8 *)(0x62be48 + c3));
            if (h3 == 0x62bcdf) {
              if (rem < 2) return -2;
              if (((W6Pred)*(u32 *)(enc + 0x164))(enc, esi) != 0) goto def;
              esi += 2; rem -= 2;
            } else if (h3 == 0x62bd05) {
              if (rem < 3) return -2;
              if (((W6Pred)*(u32 *)(enc + 0x168))(enc, esi) != 0) goto def;
              esi += 3; rem -= 3;
            } else if (h3 == 0x62bd27) {
              if (rem < 4) return -2;
              if (((W6Pred)*(u32 *)(enc + 0x16c))(enc, esi) != 0) goto def;
              esi += 4; rem -= 4;
            } else if (h3 == 0x62bd45) {
              esi++; rem--;
              if (esi == end) return -1;
              if (*(u8 *)esi == 0x3e) { *(u32 *)nextTok = esi + 1; return (s32)tok; }
            } else if (h3 == 0x62bd59) {
              esi++; rem--;
            } else {
              goto def;
            }
          }
          if (esi == end) return -1;
        }
      }
      default: goto def;
    }
    esi += step;
    if (esi == edi) return -1;
  }
def:
  *(u32 *)nextTok = esi;
  return 0;
}
PCREG(62bb10, GUESS_62bb10);

// ---------------------------------------------------------------- 0x42bae0
extern "C" u32 THISCALL ext_4d3f80_w6(u32) __asm__("ext_4d3f80");
extern "C" u32 THISCALL ext_430010_w6(u32, u32) __asm__("ext_430010");
extern "C" u32 THISCALL ext_54f870_w6(u32, u32, u32) __asm__("ext_54f870");
extern "C" u32 FASTCALL ext_42b080_w6(u32, u32, u32) __asm__("ext_42b080");
extern "C" void ext_634273_w6(u32, u32) __asm__("ext_634273");

// 0x42bae0: thiscall(), void: destructor (SEH 0x664bfa; states -1 -> 0 -> 1 -> -1 for [0x1b65], 2 -> 3 -> -1 for [0x1b69], 4 -> 5 -> -1 for [0x1b6d], 6 for [0x1b61] and the 22 string members).
// this[0] = 0x6797a0; [0x70038c] vslot 0x38(); this[0x1b37] object: 0x4d3f80, free(p, 0x10f4); this[0x1b55]: free(p, 1); this[0x1b51]: deleting-destructor vslot 0(1);
// this[0x1b65] (list head): if [+4] != 0 the nodes are reset (0x430010([[p]+1]), [[p]+5] = [p], [[p]+1] = 0, [[p]+9] = [p], [p+4] = 0), then 0x54f870(p, [p], 0x25) and free(p, 9);
// this[0x1b69] / [0x1b6d] (vectors of 12-byte elements): 0x42b080([p], [p+4], this), element block released with 0x54f870(p, begin, count * 12) when non-empty, free(p, 0xc);
// this[0x1b61] (vector of dwords): 0x54f870(p, begin, bytes), free(p, 0xc); finally 0x4cbec0 on the 22 embedded strings (offsets 0x1ab7 ... 0xa3). All pointers unaligned.
extern "C" void THISCALL GUESS_42bae0(u32 self) {
  SEH_ENTER(0x664bfa);
  *(u32 *)self = 0x6797a0;
  u32 g = *(u32 *)0x70038c;
  if (g) ((W6B)*(u32 *)(*(u32 *)g + 0x38))(g);
  u32 edi = w6ld(self + 0x1b37);
  if (edi) {
    ext_4d3f80_w6(edi);
    ext_634273_w6(edi, 0x10f4);
  }
  u32 eax = w6ld(self + 0x1b55);
  if (eax) ext_634273_w6(eax, 1);
  u32 ecx = w6ld(self + 0x1b51);
  w6st(self + 0x1b55, 0);
  if (ecx) ((W6T1)*(u32 *)(*(u32 *)ecx))(ecx, 1);
  edi = w6ld(self + 0x1b65);
  w6st(self + 0x1b51, 0);
  if (edi) {
    reg.state = 0;
    if (*(u32 *)(edi + 4) != 0) {
      u32 n = *(u32 *)edi;
      ext_430010_w6(edi, w6ld(n + 1));
      n = *(u32 *)edi;
      w6st(n + 5, n);
      n = *(u32 *)edi;
      w6st(n + 1, 0);
      n = *(u32 *)edi;
      w6st(n + 9, n);
      *(u32 *)(edi + 4) = 0;
    }
    reg.state = 1;
    ext_54f870_w6(edi, *(u32 *)edi, 0x25);
    reg.state = -1;
    ext_634273_w6(edi, 9);
    w6st(self + 0x1b65, 0);
  }
  for (int pass = 0; pass < 2; pass++) {
    u32 off = pass == 0 ? 0x1b69 : 0x1b6d;
    edi = w6ld(self + off);
    if (edi) {
      reg.state = pass == 0 ? 2 : 4;
      ext_42b080_w6(*(u32 *)edi, *(u32 *)(edi + 4), self);
      u32 ebx = *(u32 *)edi;
      s32 diff = (s32)(*(u32 *)(edi + 8) - ebx);
      s32 q = (s32)(((long long)diff * (long long)(s32)0x2aaaaaab) >> 32);
      q = q >> 1;
      s32 cnt = q + (s32)((u32)q >> 31);
      reg.state = pass == 0 ? 3 : 5;
      if (cnt != 0) ext_54f870_w6(edi, ebx, (u32)cnt * 12);
      reg.state = -1;
      ext_634273_w6(edi, 0xc);
      w6st(self + off, 0);
    }
  }
  edi = w6ld(self + 0x1b61);
  if (edi) {
    s32 d = (s32)(*(u32 *)(edi + 8) - *(u32 *)edi) >> 2;
    ecx = *(u32 *)edi;
    reg.state = 6;
    if (d != 0) ext_54f870_w6(edi, ecx, (u32)d << 2);
    ext_634273_w6(edi, 0xc);
    w6st(self + 0x1b61, 0);
  }
  static const u16 offs[22] = {0x1ab7, 0x1a17, 0x1997, 0x1917, 0x923, 0x8a3, 0x823, 0x7a3, 0x723, 0x6a3, 0x623, 0x5a3, 0x523, 0x4a3, 0x423, 0x3a3, 0x323, 0x2a3, 0x223, 0x1a3, 0x123, 0xa3};
  for (int i = 0; i < 22; i++) ext_4cbec0_w6(self + offs[i]);
  SEH_LEAVE();
}
PCREG(42bae0, GUESS_42bae0);

// ---------------------------------------------------------------- 0x43afe0
extern "C" u32 THISCALL ext_43a380_w6(u32) __asm__("ext_43a380");
extern "C" u32 THISCALL ext_43a440_w6(u32) __asm__("ext_43a440");
extern "C" u32 THISCALL ext_43a130_w6(u32, u32, u32) __asm__("ext_43a130");
extern "C" u32 THISCALL ext_43b630_w6(u32, u32, u32) __asm__("ext_43b630");
extern "C" u32 THISCALL ext_4395d0_w6(u32) __asm__("ext_4395d0");

// 0x43afe0: thiscall(), void. Debug line 0x259 (slot 0x178, text 0x67a8b4). The N pointers in this[0x121c..] (count this[0x1218]) get byte [+0x32] = ((b & 0x10) << 1) | (b & 0x9f);
// N = 0; if [0x7003a0][0xc] != 0: 0x43a380(this); if [0x7003a0][0x1c] != 0: 0x43a440(this); 0x43a130(i, key) for (0, 0x6e4a50) (1, 0x6e4b80) (2, 0x6e4cb0) (3, 0x6e4de0).
// For each of this[0x1210] entries i (10-byte records at this[0x1344], values from the byte array this[0x131c]): flag = value != 0; when the record's flag byte (+8) differs it is
// updated, +9 = value and every object of the record's list (head at +4, next at +5, object = node[0], base = object - 4) with object[0] == 0 gets base[0x31] = value,
// base[0x42] += / -= 1 (by node[4] == flag) and is appended to the pointer array once; objects of type 2 call 0x43b630(object, i, flag); when only the value (+9) differs the
// objects with type 0 get base[0x2d] = value. Then every array entry is rewritten: [+0x19] == [+0x42]: unless bits 0x30 / [+0x10] == 0, [+0x32] = ([+0x32] & 0xbf) | 0x10 and the
// dword at +0x25 is copied to +0x29; otherwise with both bits 0x30 and [+0x10] set [+0x32] &= 0xaf and +0x1d is copied to +0x21; the source dword is then refreshed from
// [0x70039c] + 0x1c. 0x4395d0(this); debug line 0x260 (slot 0x17c).
extern "C" void THISCALL GUESS_43afe0(u32 self) {
  w6dbg(*(u32 *)0x70039c, 0x259, 0x178, 0x67a8b4);
  u32 n = *(u32 *)(self + 0x1218);
  if (n != 0) {
    u32 i = 0;
    do {
      u32 p = *(u32 *)(self + 0x121c + i * 4);
      u8 b = *(u8 *)(p + 0x32);
      u8 c = (u8)((b & 0x10) + (b & 0x10));
      *(u8 *)(p + 0x32) = (u8)(c | (b & 0x9f));
      i++;
    } while (i != *(u32 *)(self + 0x1218));
  }
  *(u32 *)(self + 0x1218) = 0;
  u32 g = *(u32 *)0x7003a0;
  if (*(u32 *)(g + 0xc) != 0) {
    ext_43a380_w6(self);
    g = *(u32 *)0x7003a0;
  }
  if (*(u32 *)(g + 0x1c) != 0) ext_43a440_w6(self);
  ext_43a130_w6(self, 0, 0x6e4a50);
  ext_43a130_w6(self, 1, 0x6e4b80);
  ext_43a130_w6(self, 2, 0x6e4cb0);
  ext_43a130_w6(self, 3, 0x6e4de0);
  u32 M = *(u32 *)(self + 0x1210);
  if (M != 0) {
    u32 i = 0, j = 0;
    u32 edxg = 0;   // the exe passes the stale upper bits of edx to 0x43b630; the callee only uses the low byte
    do {
      u8 bl = *(u8 *)(*(u32 *)(self + 0x131c) + i);
      u8 dl = (bl != 0) ? 1 : 0;
      (void)edxg;
      u32 tab = *(u32 *)(self + 0x1344);
      if (*(u8 *)(tab + j + 8) != dl) {
        *(u8 *)(tab + j + 8) = dl;
        tab = *(u32 *)(self + 0x1344);
        *(u8 *)(tab + j + 9) = bl;
        tab = *(u32 *)(self + 0x1344);
        u32 node = w6ld(tab + j + 4);
        while (node != 0) {
          u32 O = *(u32 *)node;
          if (*(u32 *)O == 0) {
            u32 base = O - 4;
            *(u8 *)(base + 0x31) = bl;
            if (*(u8 *)(node + 4) == dl) (*(u32 *)(base + 0x42))++;
            else (*(u32 *)(base + 0x42))--;
            u32 cnt = *(u32 *)(self + 0x1218);
            u32 k = 0;
            if (cnt != 0) {
              for (k = 0; k < cnt; k++) {
                if (*(u32 *)(self + 0x121c + k * 4) == base) break;
              }
            }
            if (k == cnt) {
              *(u32 *)(self + 0x121c + cnt * 4) = base;
              (*(u32 *)(self + 0x1218))++;
            }
          }
          if (*(u32 *)O == 2) ext_43b630_w6(O, i, dl);
          node = w6ld(node + 5);
        }
        bl = bl;
      }
      tab = *(u32 *)(self + 0x1344);
      if (*(u8 *)(tab + j + 9) != bl) {
        u32 node = w6ld(tab + j + 4);
        while (node != 0) {
          u32 c = *(u32 *)node;
          if (*(u32 *)c == 0) *(u8 *)(c + 0x2d) = bl;
          node = w6ld(node + 5);
        }
      }
      i++;
      j += 10;
    } while (i != *(u32 *)(self + 0x1210));
  }
  n = *(u32 *)(self + 0x1218);
  if (n != 0) {
    u32 i = 0;
    do {
      u32 p = *(u32 *)(self + 0x121c + i * 4);
      u32 src = 0, dst = 0;
      bool go = false;
      if (w6ld(p + 0x19) == *(u32 *)(p + 0x42)) {
        u8 al = *(u8 *)(p + 0x32);
        if (!(al & 0x30) && *(u8 *)(p + 0x10) != 0) {
          al = (u8)((al & 0xbf) | 0x10);
          *(u8 *)(p + 0x32) = al;
          src = p + 0x25;
          dst = p + 0x29;
          go = true;
        }
      } else {
        u8 dl = *(u8 *)(p + 0x32);
        if ((dl & 0x30) == 0x30 && *(u8 *)(p + 0x10) != 0) {
          dl &= 0xaf;
          *(u8 *)(p + 0x32) = dl;
          src = p + 0x1d;
          dst = p + 0x21;
          go = true;
        }
      }
      if (go) {
        if (dst != src) w6st(dst, w6ld(src));
        u32 gg = *(u32 *)0x70039c + 0x1c;
        if (src != gg) w6st(src, w6ld(gg));
      }
      i++;
    } while (i != *(u32 *)(self + 0x1218));
  }
  ext_4395d0_w6(self);
  w6dbg(*(u32 *)0x70039c, 0x260, 0x17c, 0x67a8b4);
}
PCREG(43afe0, GUESS_43afe0);

// ---------------------------------------------------------------- 0x4dd0c0
extern "C" u32 THISCALL ext_4dc630_w6(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4dafb0_w6(u32) __asm__("ext_4dafb0");
extern "C" u32 THISCALL ext_4db2f0_w6(u32, u32) __asm__("ext_4db2f0");
extern "C" u32 THISCALL ext_4de7a0_w6(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4db600_w6(u32, u32, u32) __asm__("ext_4db600");
extern "C" u32 THISCALL ext_4db1f0_w6(u32, u32) __asm__("ext_4db1f0");
extern "C" u32 FASTCALL ext_441a60_w6(u32, u32) __asm__("ext_441a60");
extern "C" u32 THISCALL ext_4db270_w6(u32, u32) __asm__("ext_4db270");
extern "C" u32 FASTCALL ext_43e960_w6c(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_4dac50_w6(u32, u32) __asm__("ext_4dac50");
extern "C" u32 FASTCALL ext_4dba00_w6(u32, u32, u32) __asm__("ext_4dba00");
extern "C" u32 FASTCALL ext_4db070_w6(u32, u32, u32, u32) __asm__("ext_4db070");
typedef u32(THISCALL *W6A11)(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
typedef u32(*W6C5b)(u32, u32, u32, u32, u32);

// 0x4dd0c0: thiscall(), void (own frame via __chkstk: candidate pointer array A1 (0x1000 bytes), scratch A2 (0x200 bytes); /GS cookie not reproduced). H = G[0x9b][0x5d35] (unaligned); H == 0
// or this[0x3c] & 0x200000: only 0x4dc630(this, 0, 0x2000000). Otherwise R = H vslot 0xc(&out); edi = a world object: this[0x3c] & 0x40040000 == 0 -> 0x4db2f0(this[0x54][8], 0); else
// base = (flag 0x40000000 ? 0x4dafb0(this) : this), word id = [base + 0x5c]: id != 0 and G[0x9b][8] vslot 0x5c(id) -> record with byte [+0x1c] != 0 gives edi = [record], else edi =
// G[0x9b][0xadc]. M (3 vectors) = 0x4de7a0(), V = this[0x30..0x38]; 0x4db600(this, &M, &V); node = edi[8]: when node[0x50]: 0x4db1f0(node[0x50], &V), 0x43e960(&V, node + 0x24), 0x441a60(&V,
// node) and the same 0x4db270 / 0x441a60 pair for each of the three vectors of M (each guarded by node[0x50]). K = G[0x1aa3][0x1c] vslot 0x3c(A1, A2, edi, 1, &M, &V, this + 0x40, -1, 1, 1, 1)
// (11 stack args); for each candidate c = A1[i] without flag 0x400: kind = c[0x54] ? c[0x54][0xc][0x23] (0x80000d skips) : 0x200002; kind & 0x800000: c[0x68] != 0, 0x4dac50(c, A2) and
// 0x4dba00(this, r, A2) true -> R[n++] = c; else with c[0x3c] & 0x40000 and kind & 0x100000 and (c[0x54] vslot 0x2a8() & 0x10000): n = 0x4db070(n, R, this, c). n > 12: logger
// [0x700390] vslot 0x20(0x696e24, 0xd0d) then its vslot 0x30(0x697050, name or "", n, 12), n = 12. H vslot 0(n, this); 0x4dc630(this, 0, 0x2000000).
extern "C" void THISCALL GUESS_4dd0c0(u32 self) {
  u8 A1[0x1010] __attribute__((aligned(16)));
  u8 A2[0x210] __attribute__((aligned(16)));
  float V[4] = {0, 0, 0, 0};
  float M[10];
  for (int q = 0; q < 10; q++) M[q] = 0.0f;
  u32 outv = 0;
  u32 g = *(u32 *)0x70039c;
  u32 H = w6ld(*(u32 *)(g + 0x9b) + 0x5d35);
  if (H == 0 || (*(u32 *)(self + 0x3c) & 0x200000)) {
    ext_4dc630_w6(self, 0, 0x2000000);
    return;
  }
  u32 R = ((W6T1)*(u32 *)(*(u32 *)H + 0xc))(H, (u32)&outv);
  u32 flags = *(u32 *)(self + 0x3c);
  u32 edi;
  if (!(flags & 0x40040000)) {
    u32 t = *(u32 *)(self + 0x54);
    edi = ext_4db2f0_w6(*(u32 *)(t + 8), 0);
  } else {
    u32 base;
    if (flags & 0x40000000) base = ext_4dafb0_w6(self);
    else base = self;
    u32 id = *(u16 *)(base + 0x5c);
    bool found = false;
    edi = 0;
    if (id != 0) {
      u32 gg = *(u32 *)0x70039c;
      u32 o8 = *(u32 *)(w6ld(gg + 0x9b) + 8);
      u32 rec = ((W6T1)*(u32 *)(*(u32 *)o8 + 0x5c))(o8, id);
      if (rec != 0 && *(u8 *)(rec + 0x1c) != 0) { edi = *(u32 *)rec; found = true; }
    }
    if (!found) {
      u32 gg = *(u32 *)0x70039c;
      edi = w6ld(w6ld(gg + 0x9b) + 0xadc);
    }
  }
  ext_4de7a0_w6((u32)(M));
  V[0] = bitsf(*(u32 *)(self + 0x30));
  V[1] = bitsf(*(u32 *)(self + 0x34));
  V[2] = bitsf(*(u32 *)(self + 0x38));
  ext_4db600_w6(self, (u32)M, (u32)V);
  u32 node = *(u32 *)(edi + 8);
  u32 w3 = (u32)&M[0], w2 = (u32)&M[3], w1 = (u32)&M[6];
  if (*(u32 *)(node + 0x50) != 0) {
    ext_4db1f0_w6(*(u32 *)(node + 0x50), (u32)V);
    ext_43e960_w6c((u32)V, node + 0x24);
    ext_441a60_w6((u32)V, node);
    if (*(u32 *)(node + 0x50) != 0) { ext_4db270_w6(*(u32 *)(node + 0x50), w1); ext_441a60_w6(w1, node); }
    if (*(u32 *)(node + 0x50) != 0) { ext_4db270_w6(*(u32 *)(node + 0x50), w2); ext_441a60_w6(w2, node); }
    if (*(u32 *)(node + 0x50) != 0) { ext_4db270_w6(*(u32 *)(node + 0x50), w3); ext_441a60_w6(w3, node); }
  }
  g = *(u32 *)0x70039c;
  u32 q = *(u32 *)(w6ld(g + 0x1aa3) + 0x1c);
  u32 K = ((W6A11)*(u32 *)(*(u32 *)q + 0x3c))(q, (u32)A1, (u32)A2, edi, 1, (u32)M, (u32)V, self + 0x40, 0xffffffffu, 1, 1, 1);
  u32 n = 0;
  if (K != 0) {
    u32 i = 0;
    do {
      u32 c = ((u32 *)A1)[i];
      u32 cf = *(u32 *)(c + 0x3c);
      if (!(cf & 0x400)) {
        u32 ecx = *(u32 *)(c + 0x54);
        u32 kind;
        bool skip = false;
        if (ecx != 0) {
          kind = w6ld(*(u32 *)(ecx + 0xc) + 0x23);
          if (kind == 0x80000d) skip = true;
        } else {
          kind = 0x200002;
        }
        if (!skip) {
          if (kind & 0x800000) {
            if (*(u32 *)(c + 0x68) != 0) {
              u32 r4 = ext_4dac50_w6(c, (u32)A2);
              if ((u8)ext_4dba00_w6(self, r4, (u32)A2) != 0) {
                ((u32 *)R)[n] = c;
                n++;
              }
            }
          } else if ((cf & 0x40000) && (kind & 0x100000)) {
            u32 o = *(u32 *)(c + 0x54);
            u32 e = ((W6B)*(u32 *)(*(u32 *)o + 0x2a8))(o);
            if (e & 0x10000) n = ext_4db070_w6(n, R, self, c);
          }
        }
      }
      i++;
    } while (i < K);
    if (n > 0xc) {
      u32 lg = *(u32 *)0x700390;
      u32 x = ((W6T2b)*(u32 *)(*(u32 *)lg + 0x20))(lg, 0x696e24, 0xd0d);
      u32 t = *(u32 *)(self + 0x54);
      u32 txt = 0x67c8e8;
      if (t != 0) {
        u32 s4 = *(u32 *)(t + 4);
        if (s4 != 0) txt = s4;
      }
      ((W6C5b)*(u32 *)(*(u32 *)x + 0x30))(x, 0x697050, txt, n, 0xc);
      n = 0xc;
    }
  }
  ((W6T2b)*(u32 *)(*(u32 *)H))(H, n, self);
  ext_4dc630_w6(self, 0, 0x2000000);
}
PCREG(4dd0c0, GUESS_4dd0c0);

// ---------------------------------------------------------------- 0x60c4a0
extern "C" u32 THISCALL ext_60ee10_w7(u32, u32, u32) __asm__("ext_60ee10");
extern "C" u32 THISCALL ext_60ed80_w7(u32, u32, u32) __asm__("ext_60ed80");
typedef u32(STDCALL *W7S1)(u32);
typedef u32(STDCALL *W7S6)(u32, u32, u32, u32, u32, u32);

// 0x60c4a0: thiscall(u32 mode, vertex records (9 dwords each), u32 n, u16 *indices, u32 count), ret 0x14, void. mode > 4: nothing. Else the exe's own jump table
// at 0x60c758 picks (primitive type s4, primitive count ebx): 2 -> (cnt >> 1), 3 -> cnt - 1, 4 -> cnt / 3, 5 -> cnt - 2, 6 -> cnt - 2. Render-state cache against the globals
// 0x724970/0x7249b0 (device vslot 0x14c(0, self[0x13f2][0], 0x24)), 0x7249f0/0x7249f4 (vslot 0x154(self[0x13f6][0], 0)) and 0x7249f8 (vslot 0x130(0x152)). The vertex
// buffer object A = self[0x13f2] is locked by 0x60ee10(&n, &voff); n > 0 copies n 36-byte records to the returned pointer; then A is unlocked (vslot 0x30) when A[0x10] and A[0].
// The index buffer object B = self[0x13f6] is locked by 0x60ed80(&count, &ioff) (ioff replaces the old local, count the pointer); count > 0 copies indices adding the low word
// of voff; B unlocked (vslot 0x30 when B[0xc] and B[0]); the final call is self[0x1377] vslot 0x11c(s4, voff, n, ioff, primcount).
extern "C" void THISCALL GUESS_60c4a0(u32 self, u32 mode, u32 src, u32 n, u32 idx, u32 cnt) {
  if (mode > 4) return;
  u32 h = *(u32 *)(0x60c758 + mode * 4);
  u32 s4, pc;
  switch (h) {
    case 0x60c4c1: s4 = 5; pc = cnt - 2; break;
    case 0x60c4d0: s4 = 6; pc = cnt - 2; break;
    case 0x60c4df: s4 = 4; pc = (u32)(((u64)cnt * 0xaaaaaaabULL) >> 32) >> 1; break;
    case 0x60c4f4: s4 = 3; pc = cnt - 1; break;
    case 0x60c503: s4 = 2; pc = cnt >> 1; break;
    default: return;
  }
  u32 A = w6ld(self + 0x13f2);
  u32 e = *(u32 *)A;
  u32 d;
  if (*(u32 *)0x724970 != e || *(u32 *)0x7249b0 != 0x24) {
    d = *(u32 *)0x724a00;
    *(u32 *)0x724970 = e;
    *(u32 *)0x7249b0 = 0x24;
    ((W6S4)*(u32 *)(*(u32 *)d + 0x14c))(d, 0, e, 0x24);
  }
  u32 B = w6ld(self + 0x13f6);
  e = *(u32 *)B;
  if (*(u32 *)0x7249f0 != e || *(u32 *)0x7249f4 != 0) {
    d = *(u32 *)0x724a00;
    *(u32 *)0x7249f0 = e;
    *(u32 *)0x7249f4 = 0;
    ((W6S3)*(u32 *)(*(u32 *)d + 0x154))(d, e, 0);
  }
  if (*(u32 *)0x7249f8 != 0x152) {
    d = *(u32 *)0x724a00;
    *(u32 *)0x7249f8 = 0x152;
    ((W6S2)*(u32 *)(*(u32 *)d + 0x130))(d, 0x152);
  }
  u32 voff;
  u32 dst = ext_60ee10_w7(A, (u32)&n, (u32)&voff);
  if (n != 0) {
    for (u32 i = 0; i < n; i++)
      for (int q = 0; q < 9; q++) w6st(dst + i * 36 + q * 4, w6ld(src + i * 36 + q * 4));
  }
  A = w6ld(self + 0x13f2);
  if (*(u8 *)(A + 0x10) != 0) {
    u32 o = *(u32 *)A;
    if (o != 0) {
      ((W7S1)*(u32 *)(*(u32 *)o + 0x30))(o);
      *(u8 *)(A + 0x10) = 0;
    }
  }
  u32 ioff;
  u32 ip = ext_60ed80_w7(B = w6ld(self + 0x13f6), (u32)&cnt, (u32)&ioff);
  if (cnt != 0) {
    for (u32 i = 0; i < cnt; i++) *(u16 *)(ip + i * 2) = (u16)(*(u16 *)(idx + i * 2) + (u16)voff);
  }
  B = w6ld(self + 0x13f6);
  if (*(u8 *)(B + 0xc) != 0) {
    u32 o = *(u32 *)B;
    if (o != 0) {
      ((W7S1)*(u32 *)(*(u32 *)o + 0x30))(o);
      *(u8 *)(B + 0xc) = 0;
    }
  }
  u32 obj = w6ld(self + 0x1377);
  ((W7S6)*(u32 *)(*(u32 *)obj + 0x11c))(obj, s4, voff, n, ioff, pc);
}
PCREG(60c4a0, GUESS_60c4a0);

// ---------------------------------------------------------------- 0x5460b0
extern "C" double VECTORCALL ext_634d70_d7(double) __asm__("ext_634d70");
extern "C" double VECTORCALL ext_634d76_d7(double) __asm__("ext_634d76");
extern "C" double VECTORCALL ext_634dac_d7(double) __asm__("ext_634dac");
extern "C" void FASTCALL ext_446ee0_w7(u32, u32, u32) __asm__("ext_446ee0");
static inline float w7rf(u32 p) { float v; __builtin_memcpy(&v, (void *)p, 4); return v; }
static inline void w7wf(u32 p, float v) { __builtin_memcpy((void *)p, &v, 4); }
// normalize the float triple at p in place with the x87 stack (precision from the control word), when any component is not equal to 0 (NaN counts as not equal)
static void w7norm(u32 p) {
  if (w7rf(p) != 0.0f || w7rf(p + 4) != 0.0f || w7rf(p + 8) != 0.0f) {
    long double x = w7rf(p), y = w7rf(p + 4), z = w7rf(p + 8);
    long double s = x * x;
    s += y * y;
    s += z * z;
    long double len = fsqrt_x87(s);
    long double inv = 1.0L / len;
    w7wf(p, (float)(x * inv));
    w7wf(p + 4, (float)(y * inv));
    w7wf(p + 8, (float)(z * inv));
  }
}

// 0x5460b0: fastcall(V = ECX, float *O1 = EDX, float *O2, f0, f1, f2, f3) ret 0x14, void. a = (f0 + f1) * [0x67a6ac] * [0x67da04] (single float math), b = (f2 + f3) * same: V[0] = (float)sin(a),
// V[2] = (float)cos(a), V[1] = (float)(tan(b) * (double)V[2]); V normalized (x87) unless all three are equal to 0. W = V + 0x18 = (V[2], 0, V[0] xor [0x67af40]) normalized the same
// way; U = V + 0xc = 0x446ee0(V, W) (cross product), normalized the same way. *O1 = (float)([0x678610] / tan((f1 - f0) * k * k)), *O2 = (float)([0x678610] / tan((f3 - f2) * k * k)).
extern "C" void FASTCALL GUESS_5460b0(u32 V, u32 o1, u32 o2, float f0, float f1, float f2, float f3) {
  float k1 = *(float *)0x67a6ac, k2 = *(float *)0x67da04;
  float a = (f0 + f1) * k1 * k2;
  double da = (double)a;
  float sv = (float)ext_634d76_d7(da);
  w7wf(V, sv);
  float cv = (float)ext_634d70_d7(da);
  w7wf(V + 8, cv);
  float b = (f2 + f3) * k1 * k2;
  double tb = ext_634dac_d7((double)b);
  float mid = (float)(tb * (double)cv);
  w7wf(V + 4, mid);
  w7norm(V);
  u32 W = V + 0x18;
  w6st(W, w6ld(V + 8));
  w7wf(W + 8, bitsf(*(u32 *)V ^ *(u32 *)0x67af40));
  w7wf(W + 4, 0.0f);
  w7norm(W);
  ext_446ee0_w7(V + 0xc, V, W);
  w7norm(V + 0xc);
  float c1 = (f1 - f0) * k1 * k2;
  double r1 = *(double *)0x678610 / ext_634dac_d7((double)c1);
  w7wf(o1, (float)r1);
  float c2 = (f3 - f2) * k1 * k2;
  double r2 = *(double *)0x678610 / ext_634dac_d7((double)c2);
  w7wf(o2, (float)r2);
}
PCREG(5460b0, GUESS_5460b0);

// ---------------------------------------------------------------- 0x55c1a0
extern "C" float FASTCALL ext_4e0830_w7(u32, u32) __asm__("ext_4e0830");
static inline void w7fatal(u32 line, u32 msg) {
  u32 lg = *(u32 *)0x700390;
  u32 x = ((W6T2b)*(u32 *)(*(u32 *)lg + 0x20))(lg, 0x69c8e0, line);
  ((u32(*)(u32, u32, u32))*(u32 *)(*(u32 *)x + 0x2c))(x, 0x69c6b0, msg);
  u32 f = *(u32 *)0x7003b0;
  if (f) ((void (*)())f)();
  else asm volatile("int3");
}

// 0x55c1a0: thiscall(src) ret 4, void (/GS cookie not reproduced). Arguments through 0x5003d0(src[4], i): i = 0 kind 3 -> edi = dword, kind 4 -> edi = (*entry) vslot 0x34(),
// otherwise logged (line 0x111, text 0x69c9b0) + fatal pointer, edi = 0; i = 1 (kind 0 or 2, else logged line 0x104 / 0x69c938 + fatal) float R; i = 2 and i = 3 (kind 0 or 1, else
// the same log) dwords E2 and E3. h = G[0x9b] vslot 0x114(edi, 0, 0x6a5eb0, 0x2fb) & 0xffff; W = this[0x1c], list = W[0x913] (unaligned); null -> end. P = {0,0,0};
// W vslot 0x84(&P); for (it = list vslot 0x84(&P, R, &cursor (-1), -1); it; it = list vslot 0x84(&P, R, &cursor, -1)): when it[0x54][4] == W[0x54][4] and it != W:
// Q = {0,0,0}; it vslot 0x84(&Q); d = 0x4e0830(&P, &Q) (x87, stored as float); unless d > R * R: it vslot 0x128(h, {E2, E3}, 0).
extern "C" void THISCALL GUESS_55c1a0(u32 self, u32 src) {
  u32 e = ext_5003d0_w6(*(u32 *)(src + 4), 0);
  u32 edi;
  u8 k = *(u8 *)(e + 4);
  if (k == 3) edi = *(u32 *)e;
  else if (k == 4) {
    u32 o = *(u32 *)e;
    edi = ((W6B)*(u32 *)(*(u32 *)o + 0x34))(o);
  } else {
    w7fatal(0x111, 0x69c9b0);
    edi = 0;
  }
  e = ext_5003d0_w6(*(u32 *)(src + 4), 1);
  k = *(u8 *)(e + 4);
  if (k != 0 && k != 2) w7fatal(0x104, 0x69c938);
  u32 rb = *(u32 *)e;
  e = ext_5003d0_w6(*(u32 *)(src + 4), 2);
  k = *(u8 *)(e + 4);
  if (k != 0 && k != 1) w7fatal(0x104, 0x69c938);
  u32 e2 = *(u32 *)e;
  e = ext_5003d0_w6(*(u32 *)(src + 4), 3);
  k = *(u8 *)(e + 4);
  if (k != 0 && k != 1) w7fatal(0x104, 0x69c938);
  u32 e3 = *(u32 *)e;
  float r = bitsf(rb);
  float lim = r * r;
  u32 gg = *(u32 *)0x70039c;
  u32 h9 = w6ld(gg + 0x9b);
  u32 h = ((W6T4)*(u32 *)(*(u32 *)h9 + 0x114))(h9, edi, 0, 0x6a5eb0, 0x2fb) & 0xffff;
  u32 pair[2] = {e2, e3};
  u32 W = *(u32 *)(self + 0x1c);
  u32 list = w6ld(W + 0x913);
  if (list == 0) return;
  u32 P[3] = {0, 0, 0};
  ((W6T1)*(u32 *)(*(u32 *)W + 0x84))(W, (u32)P);
  u32 cur = 0xffffffff;
  u32 it = ((W6T4)*(u32 *)(*(u32 *)list + 0x84))(list, (u32)P, rb, (u32)&cur, 0xffffffff);
  while (it != 0) {
    if (*(u32 *)(*(u32 *)(it + 0x54) + 4) == *(u32 *)(*(u32 *)(*(u32 *)(self + 0x1c) + 0x54) + 4) && it != *(u32 *)(self + 0x1c)) {
      u32 Q[3] = {0, 0, 0};
      ((W6T1)*(u32 *)(*(u32 *)it + 0x84))(it, (u32)Q);
      float d = ext_4e0830_w7((u32)P, (u32)Q);
      if (!(d > lim)) ((W6T3)*(u32 *)(*(u32 *)it + 0x128))(it, h, (u32)pair, 0);
    }
    it = ((W6T4)*(u32 *)(*(u32 *)list + 0x84))(list, (u32)P, rb, (u32)&cur, 0xffffffff);
  }
}
PCREG(55c1a0, GUESS_55c1a0);

// ---------------------------------------------------------------- 0x559a10
// 0x559a10: thiscall(src) ret 4, void (/GS cookie not reproduced). P = three floats of the entries 0x5003d0(src[4], 0..2) (copied without a kind check), S = entry 3. L = 3 floats filled by
// W = this[0x1c] vslot 0x84(&L); D = 0x43e920(P, L) (P - L) normalized (x87) unless all three are equal to 0, D *= S (0x4e0d00), P += D (0x43e960). Ray query: K = G[0x1aa3][0x1c]
// vslot 0x30(&R, 0, {P.x, P.y + [0x67cd40], P.z}, {0, -500.0, 0}, 1, 1, 1, 0) with R[0] = 1.0; when al is set P = (R[1], R[2], R[3]). Then P.x, P.y, P.z are stored (type byte 2) into the entries
// 0x5003d0(src[8], 0..2); a type byte other than 0 or 2 is logged (line 0xd5, text 0x69c938) + fatal pointer instead and that entry is not written.
extern "C" void THISCALL GUESS_559a10(u32 self, u32 src) {
  u32 vb[3], sc, e;
  e = ext_5003d0_w6(*(u32 *)(src + 4), 0); vb[0] = *(u32 *)e;
  e = ext_5003d0_w6(*(u32 *)(src + 4), 1); vb[1] = *(u32 *)e;
  e = ext_5003d0_w6(*(u32 *)(src + 4), 2); vb[2] = *(u32 *)e;
  e = ext_5003d0_w6(*(u32 *)(src + 4), 3); sc = *(u32 *)e;
  u32 W = *(u32 *)(self + 0x1c);
  u32 L[3] = {0, 0, 0};
  ((W6T1)*(u32 *)(*(u32 *)W + 0x84))(W, (u32)L);
  u32 D[3];
  ext_43e920_w6((u32)D, (u32)vb, (u32)L);
  w7norm((u32)D);
  ext_4e0d00_w6((u32)D, sc);
  ext_43e960_w6c((u32)vb, (u32)D);
  u32 R[4] = {0x3f800000, 0, 0, 0};
  float ty = bitsf(vb[1]) + *(float *)0x67cd40;
  u32 A34[3] = {vb[0], fbits(ty), vb[2]};
  u32 A28[3] = {0, 0xc3fa0000, 0};
  u32 gg = *(u32 *)0x70039c;
  u32 ob = w6ld(gg + 0x1aa3);
  u32 K = *(u32 *)(ob + 0x1c);
  u8 hit = (u8)((W6A8)*(u32 *)(*(u32 *)K + 0x30))(K, (u32)R, 0, (u32)A34, (u32)A28, 1, 1, 1, 0);
  if (hit) { vb[0] = R[1]; vb[1] = R[2]; vb[2] = R[3]; }
  for (int i = 0; i < 3; i++) {
    e = ext_5003d0_w6(*(u32 *)(src + 8), i);
    u8 k = *(u8 *)(e + 4);
    if (k == 0 || k == 2) {
      *(u32 *)e = vb[i];
      *(u8 *)(e + 4) = 2;
    } else {
      w7fatal(0xd5, 0x69c938);
    }
  }
}
PCREG(559a10, GUESS_559a10);

// ---------------------------------------------------------------- 0x553a30
extern "C" float FASTCALL ext_4e0870_w7(u32, u32) __asm__("ext_4e0870");
static inline u32 w7ent(u32 src4, u32 i) {
  u32 e = ext_5003d0_w6(src4, i);
  u8 k = *(u8 *)(e + 4);
  if (k != 0 && k != 2) w7fatal(0x104, 0x69c938);
  return e;
}

// 0x553a30: stdcall(src) ret 4, void (/GS cookie not reproduced). Reads the float entries 0x5003d0(src[4], i) in the order 2, 1, 0, 5, 4, 3 (each type byte must be 0 or 2, else logged
// (line 0x104, text 0x69c938) + fatal pointer, execution continues): A = (e0, e1, e2), B = (e3, e4, e5), d = 0x4e0870(&A, &B) (distance, x87 return stored as float); the entry
// 0x5003d0(src[8], 0) gets the same type check, then its type byte is set to 2 and d is stored (also after a failed check).
extern "C" void STDCALL GUESS_553a30(u32 src) {
  u32 A[3], B[3];
  u32 s4 = *(u32 *)(src + 4);
  u32 e;
  e = w7ent(s4, 2); A[2] = *(u32 *)e;
  e = w7ent(s4, 1); A[1] = *(u32 *)e;
  e = w7ent(s4, 0); A[0] = *(u32 *)e;
  e = w7ent(s4, 5); B[2] = *(u32 *)e;
  e = w7ent(s4, 4); B[1] = *(u32 *)e;
  e = w7ent(s4, 3); B[0] = *(u32 *)e;
  float d = ext_4e0870_w7((u32)A, (u32)B);
  e = w7ent(*(u32 *)(src + 8), 0);
  *(u8 *)(e + 4) = 2;
  *(u32 *)e = fbits(d);
}
PCREG(553a30, GUESS_553a30);

// ---------------------------------------------------------------- 0x556780
extern "C" u32 THISCALL ext_4db7c0_w7(u32, u32) __asm__("ext_4db7c0");
static inline u32 w7ent01(u32 src4, u32 i) {
  u32 e = ext_5003d0_w6(src4, i);
  u8 k = *(u8 *)(e + 4);
  if (k != 0 && k != 1) w7fatal(0x104, 0x69c938);
  return e;
}
static inline double w7absd(float f) {
  double d = (double)f;
  u64 b;
  __builtin_memcpy(&b, &d, 8);
  b &= *(u64 *)0x67cd50;
  __builtin_memcpy(&d, &b, 8);
  return d;
}

// 0x556780: thiscall(src) ret 4, void (/GS cookie not reproduced). Entry 0 (0x5003d0(src[4], 0)): kind 3 -> esi = dword, kind 4 -> esi = (*entry) vslot 0x34(), otherwise logged (line 0x111,
// text 0x69c9b0) + fatal pointer, esi = 0. Entries 1 and 2 (kind 0 or 1, else logged line 0x104 / 0x69c938 + fatal): ID = dword 1, V = dword 2. ID == 0 ends. h = G[0x9b] vslot 0x114(esi, 0,
// 0x6a57fc, 0x502) & 0xffff; N = G[0x9b] vslot 0x58(ID); when this[0x10] == 0: this[0x10] = G[0x9b][0xadc] vslot 0x25c(0x685f44, 0), 0 ends. 0x4db7c0(N[8], &E) fills the extent E (3 floats);
// C = this[0x10][0x18] (0 ends) vslot 0x4c(&it); item = C vslot 0x5c(&it) (re-read each time); while it[0] != 0: M = G[0x9b] vslot 0x58(item); when bit 0x400 of M vslot 0x20()[8][0x3c] is
// clear: M vslot 0x84(&D), N vslot 0x8c(&D) and when E.x > |D.x| and E.y > |D.y| and E.z > |D.z| (doubles; NaN fails) M vslot 0x128(h, &V, 0).
extern "C" void THISCALL GUESS_556780(u32 self, u32 src) {
  u32 s4 = *(u32 *)(src + 4);
  u32 e = ext_5003d0_w6(s4, 0);
  u32 esi;
  u8 k = *(u8 *)(e + 4);
  if (k == 3) esi = *(u32 *)e;
  else if (k == 4) {
    u32 o = *(u32 *)e;
    esi = ((W6B)*(u32 *)(*(u32 *)o + 0x34))(o);
  } else {
    w7fatal(0x111, 0x69c9b0);
    esi = 0;
  }
  e = w7ent01(*(u32 *)(src + 4), 1);
  u32 id = *(u32 *)e;
  e = w7ent01(*(u32 *)(src + 4), 2);
  u32 vv = *(u32 *)e;
  if (id == 0) return;
  u32 H = w6ld(*(u32 *)0x70039c + 0x9b);
  u32 h = ((W6T4)*(u32 *)(*(u32 *)H + 0x114))(H, esi, 0, 0x6a57fc, 0x502) & 0xffff;
  H = w6ld(*(u32 *)0x70039c + 0x9b);
  u32 N = ((W6T1)*(u32 *)(*(u32 *)H + 0x58))(H, id);
  if (*(u32 *)(self + 0x10) == 0) {
    u32 S = w6ld(w6ld(*(u32 *)0x70039c + 0x9b) + 0xadc);
    u32 r = ((W6T2b)*(u32 *)(*(u32 *)S + 0x25c))(S, 0x685f44, 0);
    *(u32 *)(self + 0x10) = r;
    if (r == 0) return;
  }
  float E[3];
  ext_4db7c0_w7(*(u32 *)(N + 8), (u32)E);
  u32 C = *(u32 *)(*(u32 *)(self + 0x10) + 0x18);
  if (C == 0) return;
  u32 it[3];
  ((W6T1)*(u32 *)(*(u32 *)C + 0x4c))(C, (u32)it);
  C = *(u32 *)(*(u32 *)(self + 0x10) + 0x18);
  u32 item = ((W6T1)*(u32 *)(*(u32 *)C + 0x5c))(C, (u32)it);
  if (it[0] == 0) return;
  do {
    u32 H3 = w6ld(*(u32 *)0x70039c + 0x9b);
    u32 M = ((W6T1)*(u32 *)(*(u32 *)H3 + 0x58))(H3, item);
    u32 o2 = ((W6B)*(u32 *)(*(u32 *)M + 0x20))(M);
    u32 fl = *(u32 *)(*(u32 *)(o2 + 8) + 0x3c);
    if (!((fl >> 10) & 1)) {
      float D[3] = {0, 0, 0};
      ((W6T1)*(u32 *)(*(u32 *)M + 0x84))(M, (u32)D);
      ((W6T1)*(u32 *)(*(u32 *)N + 0x8c))(N, (u32)D);
      if ((double)E[0] > w7absd(D[0]) && (double)E[1] > w7absd(D[1]) && (double)E[2] > w7absd(D[2]))
        ((W6T3)*(u32 *)(*(u32 *)M + 0x128))(M, h, (u32)&vv, 0);
    }
    C = *(u32 *)(*(u32 *)(self + 0x10) + 0x18);
    item = ((W6T1)*(u32 *)(*(u32 *)C + 0x5c))(C, (u32)it);
  } while (it[0] != 0);
}
PCREG(556780, GUESS_556780);

// ---------------------------------------------------------------- 0x491b70
typedef float(THISCALL *W8F3)(u32, u32, u32, u32);
static inline void w8prog(u32 self, u32 n, u32 T) {
  float ratio = (float)(s32)n / (float)(s32)T;
  ((W8F3)*(u32 *)(*(u32 *)self + 0x90))(self, 5, 0, fbits(ratio));
}

// 0x491b70: thiscall(list L) ret 4, void. T = L vslot 0x14() * 2 + this[0x5d2d]; counter n = 0; progress call = this vslot 0x90(5, 0, (float)n / (float)T) (x87 result dropped).
// S = G[0x9b][0xadc] vslot 0x154(). Pass A: L vslot 0x4c(&it); for item = L vslot 0x5c(&it) while it[0] != 0: progress(n++), X = G[0x9b] vslot 0x54(item); X and X[0x54] non-null
// -> X[0x54] vslot 0x154(); item = L vslot 0x5c(&it). Pass B over the node list this[0x5d29] (next = node[0x28]): n++; nodes with byte [0x14] & 1: progress(n), obj = node[0x30], non-null:
// when node[0x14] & 0x200 or bit 0x400 of obj[8][0x3c] is clear: when byte node[4] & 1 is clear node vslot 8(), node[4] |= 4 (skipping the rest unless bit 1 is now set), then node vslot 0x4c(),
// node[4] |= 0x100, node vslot 0x54(node[0x30]); then obj vslot 0x1e8(). Pass C: same over nodes with [0x14] & 2 with slot 0xc and node[4] |= 8, no 0x1e8 call. S2 vslot 0x158(). Pass D: L
// again; for each item: progress(n++), M = G[0x9b] vslot 0x54(item); M non-null: 0x4dc630(M, 0x800000, 0) and M[0x54] non-null -> M[0x54] vslot 0x158().
extern "C" void THISCALL GUESS_491b70(u32 self, u32 L) {
  u32 cnt = ((W6B)*(u32 *)(*(u32 *)L + 0x14))(L);
  u32 T = cnt * 2 + w6ld(self + 0x5d2d);
  u32 n = 0;
  u32 S = w6ld(w6ld(*(u32 *)0x70039c + 0x9b) + 0xadc);
  ((W6B)*(u32 *)(*(u32 *)S + 0x154))(S);
  u32 it[3];
  ((W6T1)*(u32 *)(*(u32 *)L + 0x4c))(L, (u32)it);
  u32 item = ((W6T1)*(u32 *)(*(u32 *)L + 0x5c))(L, (u32)it);
  if (it[0] != 0) {
    do {
      w8prog(self, n, T);
      u32 H = w6ld(*(u32 *)0x70039c + 0x9b);
      n++;
      u32 X = ((W6T1)*(u32 *)(*(u32 *)H + 0x54))(H, item);
      if (X != 0) {
        u32 Y = *(u32 *)(X + 0x54);
        if (Y != 0) ((W6B)*(u32 *)(*(u32 *)Y + 0x154))(Y);
      }
      item = ((W6T1)*(u32 *)(*(u32 *)L + 0x5c))(L, (u32)it);
    } while (it[0] != 0);
  }
  u32 node = w6ld(self + 0x5d29);
  while (node != 0) {
    u32 next = *(u32 *)(node + 0x28);
    n++;
    if (*(u8 *)(node + 0x14) & 1) {
      w8prog(self, n, T);
      u32 obj = *(u32 *)(node + 0x30);
      if (obj != 0) {
        bool doit = (*(u32 *)(node + 0x14) & 0x200) || !((*(u32 *)(*(u32 *)(obj + 8) + 0x3c) >> 10) & 1);
        if (doit) {
          bool go = true;
          if (!(*(u8 *)(node + 4) & 1)) {
            ((W6B)*(u32 *)(*(u32 *)node + 8))(node);
            *(u32 *)(node + 4) |= 4;
            if (!(*(u8 *)(node + 4) & 1)) go = false;
          }
          if (go) {
            ((W6B)*(u32 *)(*(u32 *)node + 0x4c))(node);
            u32 v = *(u32 *)(node + 0x30);
            *(u32 *)(node + 4) |= 0x100;
            ((W6T1)*(u32 *)(*(u32 *)node + 0x54))(node, v);
          }
        }
        ((W6B)*(u32 *)(*(u32 *)obj + 0x1e8))(obj);
      }
    }
    node = next;
  }
  node = w6ld(self + 0x5d29);
  while (node != 0) {
    u32 next = *(u32 *)(node + 0x28);
    n++;
    if (*(u8 *)(node + 0x14) & 2) {
      w8prog(self, n, T);
      u32 obj = *(u32 *)(node + 0x30);
      if (obj != 0) {
        bool doit = (*(u32 *)(node + 0x14) & 0x200) || !((*(u32 *)(*(u32 *)(obj + 8) + 0x3c) >> 10) & 1);
        if (doit) {
          bool go = true;
          if (!(*(u8 *)(node + 4) & 1)) {
            ((W6B)*(u32 *)(*(u32 *)node + 0xc))(node);
            *(u32 *)(node + 4) |= 8;
            if (!(*(u8 *)(node + 4) & 1)) go = false;
          }
          if (go) {
            ((W6B)*(u32 *)(*(u32 *)node + 0x4c))(node);
            u32 v = *(u32 *)(node + 0x30);
            *(u32 *)(node + 4) |= 0x100;
            ((W6T1)*(u32 *)(*(u32 *)node + 0x54))(node, v);
          }
        }
      }
    }
    node = next;
  }
  u32 S2 = w6ld(w6ld(*(u32 *)0x70039c + 0x9b) + 0xadc);
  ((W6B)*(u32 *)(*(u32 *)S2 + 0x158))(S2);
  ((W6T1)*(u32 *)(*(u32 *)L + 0x4c))(L, (u32)it);
  item = ((W6T1)*(u32 *)(*(u32 *)L + 0x5c))(L, (u32)it);
  if (it[0] != 0) {
    do {
      w8prog(self, n, T);
      u32 H = w6ld(*(u32 *)0x70039c + 0x9b);
      n++;
      u32 M = ((W6T1)*(u32 *)(*(u32 *)H + 0x54))(H, item);
      if (M != 0) {
        ext_4dc630_w6(M, 0x800000, 0);
        u32 Y = *(u32 *)(M + 0x54);
        if (Y != 0) ((W6B)*(u32 *)(*(u32 *)Y + 0x158))(Y);
      }
      item = ((W6T1)*(u32 *)(*(u32 *)L + 0x5c))(L, (u32)it);
    } while (it[0] != 0);
  }
}
PCREG(491b70, GUESS_491b70);

// ---------------------------------------------------------------- 0x554f20
extern "C" void FASTCALL ext_451890_w8(u32, u32, float) __asm__("ext_451890");
typedef u32(THISCALL *W8T2)(u32, u32, u32);

// 0x554f20: stdcall(src) ret 4, void (/GS cookie not reproduced). ID = dword of entry 0x5003d0(src[4], 0) (kind 0 or 1, else logged line 0x104 / 0x69c938 + fatal). O = G[0x9b]
// vslot 0x58(ID); a chain of vslot 0x20() calls (O, then O again and its result, then O again giving B) must be non-null at O, O's first result and the second-level result;
// then B vslot 0x80(&M, &V) (M = 9 floats, V = 3 floats) and V += M[6..8] * 0xc289947b (as float), V += M[0..2] * 0xc1971893 (0x451890, real exe code). Any null
// link instead gives V = 0 and M = identity (0x4de7a0). V.x/y/z and M[6], M[7], M[8] are stored into the entries 0x5003d0(src[8], 0..5) (kind 0 or 2, else the same log; the
// type byte is set to 2 in every case).
extern "C" void STDCALL GUESS_554f20(u32 src) {
  u32 M[9], V[3];
  u32 e = w7ent01(*(u32 *)(src + 4), 0);
  u32 id = *(u32 *)e;
  u32 H = w6ld(*(u32 *)0x70039c + 0x9b);
  u32 O = ((W6T1)*(u32 *)(*(u32 *)H + 0x58))(H, id);
  bool ok = false;
  if (O != 0) {
    u32 a = ((W6B)*(u32 *)(*(u32 *)O + 0x20))(O);
    if (a != 0) {
      u32 a2 = ((W6B)*(u32 *)(*(u32 *)O + 0x20))(O);
      u32 b = ((W6B)*(u32 *)(*(u32 *)a2 + 0x20))(a2);
      if (b != 0) {
        u32 a4 = ((W6B)*(u32 *)(*(u32 *)O + 0x20))(O);
        u32 B = ((W6B)*(u32 *)(*(u32 *)a4 + 0x20))(a4);
        ((W8T2)*(u32 *)(*(u32 *)B + 0x80))(B, (u32)M, (u32)V);
        ext_451890_w8((u32)V, (u32)&M[6], bitsf(0xc289947b));
        ext_451890_w8((u32)V, (u32)M, bitsf(0xc1971893));
        ok = true;
      }
    }
  }
  if (!ok) {
    V[0] = V[1] = V[2] = 0;
    ext_4de7a0_w6((u32)M);
  }
  u32 vals[6] = {V[0], V[1], V[2], M[6], M[7], M[8]};
  for (int i = 0; i < 6; i++) {
    e = w7ent(*(u32 *)(src + 8), i);
    *(u8 *)(e + 4) = 2;
    *(u32 *)e = vals[i];
  }
}
PCREG(554f20, GUESS_554f20);

// ---------------------------------------------------------------- 0x60bba0
// 0x60bba0: thiscall(), void (own frame via __chkstk with 128 vertices of 36 bytes and 128 index words; /GS cookie not reproduced; vertex bytes the exe never writes are left undefined).
// Only when G[0x1aa3][0x7a] is set (G = [0x70039c]). s = G[0x34] (c1 = [0x678858] when it is <= 0), v = (int)(c1 / s + [0x67a6ac]) is stored as a byte into the ring buffer
// this[0x1205 + this[0x1285]], the index this[0x1285] advances and wraps at 0x80. Then this vslot 0xd8() / 0xdc() (ints, as floats w, h) -> vslot 0x134(0, 0, w, h); vslot
// 0x14c(-1, 1, -1, 1, 1, 10, 0); vslot 0x28c(0, 0, 0); dev = this[0x1377], this[0x14f2] = 0, dev vslot 0xc8(0x2f, 0); texture stage setters 0x60ff30 / 0x60feb0 (fastcall(0, 1, 2, 0), and
// (1, 1, 2, 1) when [0x724a08] > 1); cached render states 0x13 = 5, 0x14 = 6, 0x1b = 1, 0xe = 0, 0x17 = 8 (device [0x724a00] vslot 0xc8) on a cache miss. Index words i = i; four line
// pieces i = 0..3 (x 0.75 -> 1.0, y = ((double)i + [0x680aa0]) as float * [0x67a288]^2 - c1, color 0xff3f3f4f) and one at y = -0.85 (color 0xff7f7f9f) are drawn with this vslot 0x25c(3, verts, 2,
// idx, 2); finally 128 vertices (x from [0x684ce4] in steps of [0x6bd564], y from the ring bytes starting at this[0x1285] as byte * [0x67a288] / [0x67cd40] - c1, z 1.0, color 0xff7f3f3f)
// are drawn with vslot 0x25c(3, verts, 0x80, idx, 0x80).
extern "C" void THISCALL GUESS_60bba0(u32 self) {
  u8 Vb[0x1200] __attribute__((aligned(16)));
  u16 Ib[128];
  u32 G = *(u32 *)0x70039c;
  u32 K = w6ld(G + 0x1aa3);
  if (*(u8 *)(K + 0x7a) == 0) return;
  float g34 = bitsf(*(u32 *)(G + 0x34));
  float c1 = *(float *)0x678858;
  float s = (g34 <= 0.0f) ? c1 : g34;
  float rr = c1 / s + *(float *)0x67a6ac;
  s32 v = _mm_cvttss_si32(_mm_set_ss(rr));
  u32 ri = w6ld(self + 0x1285);
  *(u8 *)(self + ri + 0x1205) = (u8)v;
  w6st(self + 0x1285, w6ld(self + 0x1285) + 1);
  if (w6ld(self + 0x1285) == 0x80) w6st(self + 0x1285, 0);
  s32 wi = ((W6I0)*(u32 *)(*(u32 *)self + 0xd8))(self);
  float f1 = (float)wi;
  s32 hi = ((W6I0)*(u32 *)(*(u32 *)self + 0xdc))(self);
  float f2 = (float)hi;
  ((W6T4)*(u32 *)(*(u32 *)self + 0x134))(self, 0, 0, fbits(f1), fbits(f2));
  ((W6A7)*(u32 *)(*(u32 *)self + 0x14c))(self, 0xbf800000, 0x3f800000, 0xbf800000, 0x3f800000, 0x3f800000, 0x41200000, 0);
  ((W6T3)*(u32 *)(*(u32 *)self + 0x28c))(self, 0, 0, 0);
  u32 dev = w6ld(self + 0x1377);
  w6st(self + 0x14f2, 0);
  ((W6S3)*(u32 *)(*(u32 *)dev + 0xc8))(dev, 0x2f, 0);
  ext_60ff30_w6(0, 1, 2, 0);
  ext_60feb0_w6(0, 1, 2, 0);
  if (*(u32 *)0x724a08 > 1) {
    ext_60ff30_w6(1, 1, 2, 1);
    ext_60feb0_w6(1, 1, 2, 1);
  }
  u32 d;
  if (*(u32 *)0x724928 != 5) { d = *(u32 *)0x724a00; *(u32 *)0x724928 = 5; w6rs(d, 0x13, 5); }
  if (*(u32 *)0x72492c != 6) { d = *(u32 *)0x724a00; *(u32 *)0x72492c = 6; w6rs(d, 0x14, 6); }
  if (*(u32 *)0x724934 != 1) { d = *(u32 *)0x724a00; *(u32 *)0x724934 = 1; w6rs(d, 0x1b, 1); }
  if (*(u32 *)0x72493c != 0) { d = *(u32 *)0x724a00; *(u32 *)0x72493c = 0; w6rs(d, 0xe, 0); }
  if (*(u32 *)0x724968 != 8) { d = *(u32 *)0x724a00; *(u32 *)0x724968 = 8; w6rs(d, 0x17, 8); }
  for (u32 i = 0; i < 128; i++) Ib[i] = (u16)i;
  float s2 = *(float *)0x67a288;
  u32 vb = (u32)Vb;
  w6st(vb + 0, 0x3f400000);
  w6st(vb + 8, 0x3f800000);
  w6st(vb + 0x24, 0x3f800000);
  w6st(vb + 0x2c, 0x3f800000);
  w6st(vb + 0x18, 0xff3f3f4f);
  w6st(vb + 0x3c, 0xff3f3f4f);
  for (u32 i = 0; i < 4; i++) {
    double dd = (double)(s32)i + *(double *)(0x680aa0 + (i >> 31) * 8);
    float y = (float)dd;
    y = y * s2;
    y = y * s2;
    y = y - *(float *)0x678858;
    w6st(vb + 4, fbits(y));
    w6st(vb + 0x28, fbits(y));
    ((W6A5)*(u32 *)(*(u32 *)self + 0x25c))(self, 3, vb, 2, (u32)Ib, 2);
  }
  w6st(vb + 4, 0xbf59999a);
  w6st(vb + 0x28, 0xbf59999a);
  w6st(vb + 0x18, 0xff7f7f9f);
  w6st(vb + 0x3c, 0xff7f7f9f);
  ((W6A5)*(u32 *)(*(u32 *)self + 0x25c))(self, 3, vb, 2, (u32)Ib, 2);
  u32 e = w6ld(self + 0x1285);
  float x = *(float *)0x684ce4;
  float step = *(float *)0x6bd564;
  for (u32 i = 0; i < 128; i++) {
    u32 nx = e + 1;
    w6st(vb + 36 * i, fbits(x));
    u8 b = *(u8 *)(self + e + 0x1205);
    x = x + step;
    w6st(vb + 36 * i + 8, 0x3f800000);
    w6st(vb + 36 * i + 0x18, 0xff7f3f3f);
    float y = ((float)b * s2) / *(float *)0x67cd40;
    y = y - *(float *)0x678858;
    w6st(vb + 36 * i + 4, fbits(y));
    e = (nx != 0x80) ? nx : 0;
  }
  ((W6A5)*(u32 *)(*(u32 *)self + 0x25c))(self, 3, vb, 0x80, (u32)Ib, 0x80);
}
PCREG(60bba0, GUESS_60bba0);

// ---------------------------------------------------------------- 0x60d1a0
extern "C" u32 THISCALL ext_60bfc0_w9(u32, u32, u32) __asm__("ext_60bfc0");

// 0x60d1a0: thiscall(P, n, B, color) ret 0x10, void. Debug line 0x259 (slot 0x178, text 0x6bd508) and, at the end, line 0x260 (slot 0x17c); halved color c = (color >> 1) & 0x7f7f7f7f.
// Vertex buffer object A = this[0x13f2] locked by 0x60ee10(&cnt = n * 4, &voff) -> dst. n quads of 4 vertices (9 dwords each: x y z, 0, 0, 1.0, color, t, 0 and the second pair with
// the 9th dword 1.0 for vertices 2 and 3): B != 0: P is an array of 0x18-byte records (a b c s t u) and B points to 12 fixed floats, vertex j position = (B[3j] * s + a, B[3j+1] * s + b,
// B[3j+2] * s + c), t/u texture floats (t for vertices 0 and 3, u for 1 and 2); B == 0: P is an array of 0x38-byte records (12 position floats then t and u). Then A is unlocked
// (vslot 0x30 when byte A[0x10] and A[0]), the stream/vertex-format caches 0x724970 / 0x7249b0 (dev vslot 0x14c) and 0x7249f8 (dev vslot 0x130) are refreshed and 0x60bfc0(n, voff) draws.
extern "C" void THISCALL GUESS_60d1a0(u32 self, u32 P, u32 n, u32 B, u32 color) {
  u32 edi = (color >> 1) & 0x7f7f7f7f;
  w6dbg(*(u32 *)0x70039c, 0x259, 0x178, 0x6bd508);
  u32 cnt = n * 4;
  u32 voff = 0;
  u32 A = w6ld(self + 0x13f2);
  u32 dst = ext_60ee10_w7(A, (u32)&cnt, (u32)&voff);
  if (B != 0) {
    if (n != 0) {
      u32 ecx = P + 0xc;
      u32 e = dst;
      for (u32 k = n; k != 0; k--) {
        float s = bitsf(*(u32 *)ecx), t = bitsf(*(u32 *)(ecx + 4)), u = bitsf(*(u32 *)(ecx + 8));
        float a = bitsf(*(u32 *)(ecx - 0xc)), b = bitsf(*(u32 *)(ecx - 8)), c = bitsf(*(u32 *)(ecx - 4));
        float tt[4] = {t, u, u, t};
        for (int j = 0; j < 4; j++) {
          u32 vb = e + j * 36;
          w6st(vb + 0, fbits(bitsf(*(u32 *)(B + 12 * j)) * s + a));
          w6st(vb + 4, fbits(bitsf(*(u32 *)(B + 12 * j + 4)) * s + b));
          w6st(vb + 8, fbits(bitsf(*(u32 *)(B + 12 * j + 8)) * s + c));
          w6st(vb + 0xc, 0);
          w6st(vb + 0x10, 0);
          w6st(vb + 0x14, 0x3f800000);
          w6st(vb + 0x18, edi);
          w6st(vb + 0x1c, fbits(tt[j]));
          w6st(vb + 0x20, (j == 0 || j == 1) ? 0 : 0x3f800000);
        }
        ecx += 0x18;
        e += 0x90;
      }
    }
  } else if (n != 0) {
    u32 e = dst;
    u32 R = P;
    for (u32 k = n; k != 0; k--) {
      u32 t = *(u32 *)(R + 0x30), u = *(u32 *)(R + 0x34);
      u32 tt[4] = {t, u, u, t};
      for (int j = 0; j < 4; j++) {
        u32 vb = e + j * 36;
        w6st(vb + 0, *(u32 *)(R + 12 * j));
        w6st(vb + 4, *(u32 *)(R + 12 * j + 4));
        w6st(vb + 8, *(u32 *)(R + 12 * j + 8));
        w6st(vb + 0xc, 0);
        w6st(vb + 0x10, 0);
        w6st(vb + 0x14, 0x3f800000);
        w6st(vb + 0x18, edi);
        w6st(vb + 0x1c, tt[j]);
        w6st(vb + 0x20, (j == 0 || j == 1) ? 0 : 0x3f800000);
      }
      R += 0x38;
      e += 0x90;
    }
  }
  A = w6ld(self + 0x13f2);
  if (*(u8 *)(A + 0x10) != 0) {
    u32 o = *(u32 *)A;
    if (o != 0) {
      ((W7S1)*(u32 *)(*(u32 *)o + 0x30))(o);
      *(u8 *)(A + 0x10) = 0;
    }
  }
  u32 ed = *(u32 *)w6ld(self + 0x13f2);
  if (*(u32 *)0x724970 != ed || *(u32 *)0x7249b0 != 0x24) {
    u32 d = *(u32 *)0x724a00;
    *(u32 *)0x724970 = ed;
    *(u32 *)0x7249b0 = 0x24;
    ((W6S4)*(u32 *)(*(u32 *)d + 0x14c))(d, 0, ed, 0x24);
  }
  if (*(u32 *)0x7249f8 != 0x152) {
    u32 d = *(u32 *)0x724a00;
    *(u32 *)0x7249f8 = 0x152;
    ((W6S2)*(u32 *)(*(u32 *)d + 0x130))(d, 0x152);
  }
  ext_60bfc0_w9(self, n, voff);
  w6dbg(*(u32 *)0x70039c, 0x260, 0x17c, 0x6bd508);
}
PCREG(60d1a0, GUESS_60d1a0);

// ---------------------------------------------------------------- 0x61b1e0
extern "C" u32 THISCALL ext_65bc00_wa(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_65bc00");
extern "C" u32 FASTCALL ext_616e00_wa(u32, u32, u32, u32) __asm__("ext_616e00");

// 0x61b1e0: thiscall(A, B, p1, p2) ret 0x10, returns al. this[0xc] == 0 or this[4][0x14] == 0: 0. Debug line 0x259 (slot 0x178, text 0x6bde70) and at the end line 0x260 (slot 0x17c).
// X = A[0xc], Y = A[0x10][8]; Ob / Oe = unaligned dwords at B[0xb9a4] + 0x13fa / 0x13fe, whose [0x30] is created by their vslot 4(0, 0) when zero. src = G[0x1aa3][0x20] + Y[0x14],
// nv = word Y[0xe], dstp = Oe[0x30] + this[0xc] * 4, mode = Y[0x50]. mode == 1: 0x65bc00(this, dstp, src, n, p1, p2, Y[0x20]) in chunks of 32 vertices (36 bytes each), result 0.
// Otherwise result 1: t = 0 unless X[0x48] != 0, then (X[0x48] - (float)unsigned(Y[0x48])) / (float)unsigned(Y[0x4c]) (double table add for negative ints [0x680aa0]); i0 = (int)t,
// i1 = min_unsigned(i0 + 1, mode - 1), f = t - (float)i0; the frames src + i0 * nv * 36 and src + i1 * nv * 36 are blended in chunks of 32 vertices into the static buffer 0x724ff8
// (dst = (v1 - v0) * f + v0 for the floats at 0, 4, 8, 0xc, 0x10, 0x14, 0x1c, 0x20; the color at 0x18 via 0x616e00(&dst[6], v0 + 0x18, &v1[6], f), exe code), then
// 0x65bc00(this, dstp, 0x724ff8, n, p1, p2, Y[0x20]); the frame pointers advance by n * 36 per chunk.
extern "C" u8 THISCALL GUESS_61b1e0(u32 self, u32 A, u32 B, u32 p1, u32 p2) {
  if (*(u32 *)(self + 0xc) == 0) return 0;
  if (*(u32 *)(*(u32 *)(self + 4) + 0x14) == 0) return 0;
  w6dbg(*(u32 *)0x70039c, 0x259, 0x178, 0x6bde70);
  u32 X = *(u32 *)(A + 0xc);
  u32 Y = *(u32 *)(*(u32 *)(A + 0x10) + 8);
  u32 C = *(u32 *)(B + 0xb9a4);
  u32 Ob = w6ld(C + 0x13fa), Oe = w6ld(C + 0x13fe);
  if (*(u32 *)(Ob + 0x30) == 0) *(u32 *)(Ob + 0x30) = ((W6T2b)*(u32 *)(*(u32 *)Ob + 4))(Ob, 0, 0);
  if (*(u32 *)(Oe + 0x30) == 0) *(u32 *)(Oe + 0x30) = ((W6T2b)*(u32 *)(*(u32 *)Oe + 4))(Oe, 0, 0);
  u32 K = w6ld(*(u32 *)0x70039c + 0x1aa3);
  u32 mode = *(u32 *)(Y + 0x50);
  u32 src = *(u32 *)(K + 0x20) + *(u32 *)(Y + 0x14);
  u32 nv = *(u16 *)(Y + 0xe);
  u32 dstp = *(u32 *)(Oe + 0x30) + *(u32 *)(self + 0xc) * 4;
  u8 ret = 0;
  if (mode == 1) {
    u32 e = nv, b = src;
    if (e != 0) {
      do {
        u32 n = e > 0x20 ? 0x20 : e;
        ext_65bc00_wa(self, dstp, b, n, p1, p2, *(u32 *)(Y + 0x20));
        b += n * 36;
        e -= n;
      } while (e != 0);
    }
  } else {
    ret = 1;
    float t = 0.0f;
    float xf = bitsf(*(u32 *)(X + 0x48));
    if (!(xf == 0.0f)) {
      u32 ya = *(u32 *)(Y + 0x48);
      float a = (float)((double)(s32)ya + *(double *)(0x680aa0 + (ya >> 31) * 8));
      t = xf - a;
      u32 yb = *(u32 *)(Y + 0x4c);
      float b = (float)((double)(s32)yb + *(double *)(0x680aa0 + (yb >> 31) * 8));
      t = t / b;
    }
    s32 i0 = _mm_cvttss_si32(_mm_set_ss(t));
    u32 i1 = (u32)i0 + 1;
    u32 lim = mode - 1;
    if (!(i1 <= lim)) i1 = lim;
    float f = t - (float)i0;
    u32 s0 = src + ((u32)i0 * nv) * 36;
    u32 s1 = src + (i1 * nv) * 36;
    u32 e = nv;
    if (e != 0) {
      do {
        u32 n, rem;
        if (e > 0x20) { n = 0x20; rem = e - 0x20; }
        else { n = e; rem = 0; }
        for (u32 k = 0; k < n; k++) {
          u32 v0 = s0 + 36 * k, v1 = s1 + 36 * k, D = 0x724ff8 + 36 * k;
          static const u32 offs[6] = {0, 4, 8, 0xc, 0x10, 0x14};
          for (int q = 0; q < 6; q++) {
            float a0 = bitsf(*(u32 *)(v0 + offs[q])), a1 = bitsf(*(u32 *)(v1 + offs[q]));
            *(u32 *)(D + offs[q]) = fbits((a1 - a0) * f + a0);
          }
          ext_616e00_wa(D + 0x18, v0 + 0x18, v1 + 0x18, fbits(f));
          {
            float a0 = bitsf(*(u32 *)(v0 + 0x1c)), a1 = bitsf(*(u32 *)(v1 + 0x1c));
            *(u32 *)(D + 0x1c) = fbits((a1 - a0) * f + a0);
            a0 = bitsf(*(u32 *)(v0 + 0x20)); a1 = bitsf(*(u32 *)(v1 + 0x20));
            *(u32 *)(D + 0x20) = fbits((a1 - a0) * f + a0);
          }
        }
        ext_65bc00_wa(self, dstp, 0x724ff8, n, p1, p2, *(u32 *)(Y + 0x20));
        s0 += n * 36;
        s1 += n * 36;
        e = rem;
      } while (e != 0);
    }
  }
  w6dbg(*(u32 *)0x70039c, 0x260, 0x17c, 0x6bde70);
  return ret;
}
PCREG(61b1e0, GUESS_61b1e0);

// ---------------------------------------------------------------- 0x6218c0
extern "C" u32 ext_620180_wb(u32, u32, u32, u32) __asm__("ext_620180");
extern "C" u32 ext_6206e0_wb(u32) __asm__("ext_6206e0");
extern "C" u32 ext_61fd60_wb(u32, u32, u32) __asm__("ext_61fd60");
extern "C" s32 ext_626e10_wb(s32, u32) __asm__("ext_626e10");
typedef s32 (*WBTok)(u32, u32, u32, u32);
typedef s32 (*WBVs2)(u32, u32);
extern "C" u32 GUESS_6218c0(u32 parser, u32 enc, u32 start, u32 end);
// append one byte to the growable buffer object buf ([+8] limit, [+0xc] cursor): grows with 0x6206e0 when full, false when that fails
static bool w9put(u32 buf, u8 c) {
  if (*(u32 *)(buf + 8) == *(u32 *)(buf + 0xc)) {
    if (!ext_6206e0_wb(buf)) return false;
  }
  *(u8 *)*(u32 *)(buf + 0xc) = c;
  *(u32 *)(buf + 0xc) += 1;
  return true;
}
static inline u32 w9fail(u32 parser, u32 enc, u32 where, u32 code) {
  if (enc == *(u32 *)(parser + 0x8c)) *(u32 *)(parser + 0x118) = where;
  return code;
}

// 0x6218c0: cdecl(parser, enc, start, end) returns an error / status code (recursive). buf1 = parser + 0x1a8. Loops over the tokens returned by enc vslot 0x14(enc, ptr, end, &next); the
// handler is chosen through the exe's own byte table 0x621be0[token + 4] and dword table 0x621bbc. Token -4 returns 0; -3 appends '\n' (next = enc[0x44] + ptr); -1: [0x118] = ptr and
// returns 4 (when enc == parser[0x8c]); 0: [0x118] = next, returns 4; 6 and 9: 0x620180(buf1, enc, ptr, next) (0 returns 1); 7: appends '\n'; 10: r = enc vslot 0x2c(enc, ptr), 0x626e10(r, bytes)
// gives n bytes that are appended (r < 0 or n == 0: [0x118] = ptr, returns 0xe); 28: entity reference: parser[0x270] == 0 and enc == parser[0x8c] -> [0x118] = ptr, returns 2; else the name is
// collected into buf2 = parser + 0x22c with 0x620180(buf2, enc, ptr + enc[0x44], next - enc[0x44]) and a terminating 0 byte, looked up with 0x61fd60(parser + 0x1c8, name, 0); missing: 0xb, flag
// byte [+0x1c] set: 0xc, [+0xc] set: 0xa; otherwise the entity text is parsed recursively with parser[0xe0] as the encoding (result != 0 returns it). Other tokens: [0x118] = ptr, returns 0x17.
extern "C" u32 GUESS_6218c0(u32 parser, u32 enc, u32 start, u32 end) {
  u32 next = 0;
  u32 edi = start;
  u32 buf1 = parser + 0x1a8;
  s32 tok = ((WBTok)*(u32 *)(enc + 0x14))(enc, edi, end, (u32)&next);
  u32 ev = (u32)tok + 4;
  for (;;) {
    if (ev > 0x20) break;
    u32 h = *(u32 *)(0x621bbc + *(u8 *)(0x621be0 + ev) * 4);
    switch (h) {
      case 0x621b74: return 0;
      case 0x621ad1: goto dflt;
      case 0x621a25:
        next = *(u32 *)(enc + 0x44) + edi;
        if (!w9put(buf1, 0xa)) return 1;
        break;
      case 0x621b7d: return w9fail(parser, enc, edi, 4);
      case 0x621b9a: return w9fail(parser, enc, next, 4);
      case 0x621a00:
        if (!ext_620180_wb(buf1, enc, edi, next)) return 1;
        break;
      case 0x621a30:
        if (!w9put(buf1, 0xa)) return 1;
        break;
      case 0x621a50: {
        s32 r = ((WBVs2)*(u32 *)(enc + 0x2c))(enc, edi);
        if (r < 0) return w9fail(parser, enc, edi, 0xe);
        u8 loc[8];
        s32 n = ext_626e10_wb(r, (u32)loc);
        if (n == 0) return w9fail(parser, enc, edi, 0xe);
        for (s32 i = 0; i < n; i++)
          if (!w9put(buf1, loc[i])) return 1;
        break;
      }
      case 0x62190e: {
        if (*(u32 *)(parser + 0x270) == 0 && enc == *(u32 *)(parser + 0x8c)) return w9fail(parser, enc, edi, 2);
        u32 buf2 = parser + 0x22c;
        u32 off = *(u32 *)(enc + 0x44);
        if (!ext_620180_wb(buf2, enc, off + edi, next - off)) return 1;
        if (*(u32 *)(parser + 0x238) == *(u32 *)(buf2 + 8)) {
          if (!ext_6206e0_wb(buf2)) return 1;
        }
        *(u8 *)*(u32 *)(buf2 + 0xc) = 0;
        *(u32 *)(buf2 + 0xc) += 1;
        u32 nm = *(u32 *)(buf2 + 0x10);
        if (nm == 0) return 1;
        u32 ent = ext_61fd60_wb(parser + 0x1c8, nm, 0);
        *(u32 *)(parser + 0x238) = *(u32 *)(parser + 0x23c);
        if (ent == 0) return w9fail(parser, enc, edi, 0xb);
        if (*(u8 *)(ent + 0x1c) != 0) return w9fail(parser, enc, edi, 0xc);
        if (*(u32 *)(ent + 0xc) != 0) return w9fail(parser, enc, edi, 0xa);
        *(u8 *)(ent + 0x1c) = 1;
        u32 rr = GUESS_6218c0(parser, *(u32 *)(parser + 0xe0), *(u32 *)(ent + 4), *(u32 *)(ent + 8) + *(u32 *)(ent + 4));
        *(u8 *)(ent + 0x1c) = 0;
        if (rr != 0) return rr;
        break;
      }
      default: goto dflt;
    }
    edi = next;
    tok = ((WBTok)*(u32 *)(enc + 0x14))(enc, edi, end, (u32)&next);
    ev = (u32)tok + 4;
  }
dflt:
  return w9fail(parser, enc, edi, 0x17);
}
PCREG(6218c0, GUESS_6218c0);

// ---------------------------------------------------------------- 0x62c270
extern "C" u32 ext_628ee0_wc(s32) __asm__("ext_628ee0");
typedef u32 (*WBConv)(u32, u32, u32, u32, u32);
// the next character as ASCII through enc[0x3c] (utf8 converter into a one byte buffer): -1 when nothing was produced
static inline s32 w10ch(u32 enc, u32 ptr, u32 end) {
  u32 from = ptr;
  s8 c = 0;
  u32 to = (u32)&c;
  ((WBConv)*(u32 *)(enc + 0x3c))(enc, (u32)&from, end, (u32)&to, (u32)&c + 1);
  if (to == (u32)&c) return -1;
  return (s32)c;
}
static inline bool w10sp(s32 c) { return c == 9 || c == 10 || c == 13 || c == 32; }

// 0x62c270: cdecl(enc, ptr, end, namePtr, nameEnd, valPtr, nextTok) returns 1 / 0 (the xmltok pseudo attribute scanner for the XML declaration). ptr == end: *namePtr = 0, returns 1.
// The first character must be white space (9, 10, 13, 32), else *nextTok = ptr, 0; white space is skipped (ptr += enc[0x44]); end of input there: *namePtr = 0, 1; *namePtr = ptr; the
// name runs until '=' or white space (isSpace 0x628ee0) or a failed conversion (-1: *nextTok = ptr, 0); *nameEnd = ptr there; after white space the next char must be '='; an empty name
// returns 0; white space is skipped after '='; the quote (0x22 or 0x27) opens the value: *valPtr = ptr after it, the value consists of [a-zA-Z0-9.-_] up to the same quote
// (any other character, -1 included: *nextTok = ptr, 0), finally *nextTok = ptr after the closing quote and returns 1.
extern "C" u32 GUESS_62c270(u32 enc, u32 ptr, u32 end, u32 namePtr, u32 nameEnd, u32 valPtr, u32 nextTok) {
  u32 esi = ptr;

  if (esi == end) { *(u32 *)namePtr = 0; return 1; }
  s32 c = w10ch(enc, esi, end);
  if (!w10sp(c)) { *(u32 *)nextTok = esi; return 0; }
  do {
    esi += *(u32 *)(enc + 0x44);
    c = w10ch(enc, esi, end);
  } while (w10sp(c));
  if (esi == end) { *(u32 *)namePtr = 0; return 1; }
  *(u32 *)namePtr = esi;
  for (;;) {
    c = w10ch(enc, esi, end);
    if (c == -1) { *(u32 *)nextTok = esi; return 0; }
    if (c == 0x3d) { *(u32 *)nameEnd = esi; break; }
    if (ext_628ee0_wc(c) != 0) {
      *(u32 *)nameEnd = esi;
      do {
        esi += *(u32 *)(enc + 0x44);
        c = w10ch(enc, esi, end);
      } while (w10sp(c));
      if (c != 0x3d) { *(u32 *)nextTok = esi; return 0; }
      break;
    }
    esi += *(u32 *)(enc + 0x44);
  }
  if (esi == *(u32 *)namePtr) { *(u32 *)nextTok = esi; return 0; }
  esi += *(u32 *)(enc + 0x44);
  c = w10ch(enc, esi, end);
  while (w10sp(c)) {
    esi += *(u32 *)(enc + 0x44);
    c = w10ch(enc, esi, end);
  }
  if (c != 0x22 && c != 0x27) { *(u32 *)nextTok = esi; return 0; }

  esi += *(u32 *)(enc + 0x44);
  *(u32 *)valPtr = esi;
  s32 open = (s32)(s8)c;
  for (;;) {
    c = w10ch(enc, esi, end);
    if (c == open) {
      *(u32 *)nextTok = esi + *(u32 *)(enc + 0x44);
      return 1;
    }
    if (!((c >= 0x61 && c <= 0x7a) || (c >= 0x41 && c <= 0x5a) || (c >= 0x30 && c <= 0x39) || c == 0x2e || c == 0x2d || c == 0x5f)) {
      *(u32 *)nextTok = esi;
      return 0;
    }
    esi += *(u32 *)(enc + 0x44);
  }

}
PCREG(62c270, GUESS_62c270);

// ---------------------------------------------------------------- 0x62a8e0
extern "C" s32 ext_62c060_wd(u32, u32, u32, u32) __asm__("ext_62c060");
typedef s32 (*WDPred)(u32, u32);
// handler address of an exe jump table: dword table dtab, byte index table btab (or direct dword table when btab == 0)
static inline u32 w11h(u32 dtab, u32 btab, u32 i) { return *(u32 *)(dtab + (btab ? *(u8 *)(btab + i) : i) * 4); }

// 0x62a8e0: cdecl(enc, ptr, end, nextTok) returns -1 (input ends), -2 (partial multi byte character), 0 (error, *nextTok = ptr), 1 (tag end '>': *nextTok = ptr + 1), 3 ("/>": *nextTok = ptr + 1) or the result
// of 0x62c060 (character reference scanner); the xmltok attribute scanner of an element start tag. The byte types come from enc[0x4c + byte]; the five dispatch tables are the exe's own
// (read at run time): name characters (types 22, 24 .. 27) advance, multi byte leads (5, 6, 7) check the length and call enc[0x14c / 0x150 / 0x154] (name start, [0x158 / 0x15c / 0x160] name
// character, [0x164 / 0x168 / 0x16c] value character, non zero = invalid); one colon is allowed in a name; white space after the name and an '=' (type 14), quote (12 / 13) begins the value,
// '&' calls 0x62c060, '<' and bad bytes fail; after the closing quote white space, '/>' or '>' or the next name start follow.
extern "C" s32 GUESS_62a8e0(u32 enc, u32 ptr, u32 end, u32 nextTok) {
  u32 esi = ptr, ebx = end;
  u32 colon = 0, q = 0, outp = 0;
  u32 eax, t;
#define W11BT(p) ((u32) * (u8 *)(enc + 0x4c + *(u8 *)(p)))
  if (esi == ebx) return -1;
top:
  eax = W11BT(esi) - 5;
  if (eax > 0x18) goto err;
  switch (w11h(0x62ac14, 0x62ac38, eax)) {
    case 0x62a928:
      if ((s32)(ebx - esi) < 2) return -2;
      if (!((WDPred)*(u32 *)(enc + 0x14c))(enc, esi)) goto err;
      esi += 2;
      goto abad;
    case 0x62a952:
      if ((s32)(ebx - esi) < 3) return -2;
      if (!((WDPred)*(u32 *)(enc + 0x150))(enc, esi)) goto err;
      esi += 3;
      goto abad;
    case 0x62a978:
      if ((s32)(ebx - esi) < 4) return -2;
      if (!((WDPred)*(u32 *)(enc + 0x154))(enc, esi)) goto err;
      esi += 4;
      goto abad;
    case 0x62a9c3: goto skips;
    case 0x62a922:
      esi++;
      goto abad;
    case 0x62a990:
      if (colon) goto err;
      esi++;
      colon = 1;
      if (esi == ebx) return -1;
      eax = W11BT(esi) - 5;
      if (eax > 0x18) goto err;
      switch (w11h(0x62ac54, 0x62ac6c, eax)) {
        case 0x62ab61:
          if ((s32)(ebx - esi) < 2) return -2;
          if (!((WDPred)*(u32 *)(enc + 0x158))(enc, esi)) goto err;
          esi += 2;
          goto abad;
        case 0x62ab75:
          if ((s32)(ebx - esi) < 3) return -2;
          if (!((WDPred)*(u32 *)(enc + 0x15c))(enc, esi)) goto err;
          esi += 3;
          goto abad;
        case 0x62ab89:
          if ((s32)(ebx - esi) < 4) return -2;
          if (!((WDPred)*(u32 *)(enc + 0x160))(enc, esi)) goto err;
          esi += 4;
          goto abad;
        case 0x62a922:
          esi++;
          goto abad;
        default: goto err;
      }
    case 0x62a9f6:
      goto eq;
    default: goto err;
  }
skips:
  esi++;
  if (esi == ebx) return -1;
  t = W11BT(esi);
  if (t == 0xe) goto eq;
  if (t < 9) goto err;
  if (t <= 0xa) goto skips;
  if (t == 0x15) goto skips;
  goto err;
eq:
  colon = 0;
eqloop:
  esi++;
  if (esi == ebx) return -1;
  t = W11BT(esi);
  q = t;
  if (t == 0xc || t == 0xd) goto valstart;
  if (t < 9) goto err;
  if (t <= 0xa) goto eqloop;
  if (t == 0x15) goto eqloop;
  goto err;
valstart:
  esi++;
valnext:
  outp = esi;
valloop:
  if (esi == ebx) return -1;
  t = W11BT(esi);
  if (t == q) goto closeq;
  if (t > 8) goto valstart;
  switch (w11h(0x62ac88, 0, t)) {
    case 0x62aae5: {
      s32 r = ext_62c060_wd(enc, esi + 1, ebx, (u32)&outp);
      if (r <= 0) {
        if (r != 0) return r;
        *(u32 *)nextTok = outp;
        return 0;
      }
      esi = outp;
      goto valloop;
    }
    case 0x62aa3b: goto valstart;
    case 0x62aa64:
      if ((s32)(ebx - esi) < 2) return -2;
      if (((WDPred)*(u32 *)(enc + 0x164))(enc, esi)) goto err;
      esi += 2;
      goto valnext;
    case 0x62aa8e:
      if ((s32)(ebx - esi) < 3) return -2;
      if (((WDPred)*(u32 *)(enc + 0x168))(enc, esi)) goto err;
      esi += 3;
      goto valnext;
    case 0x62aab8:
      if ((s32)(ebx - esi) < 4) return -2;
      if (((WDPred)*(u32 *)(enc + 0x16c))(enc, esi)) goto err;
      esi += 4;
      goto valnext;
    default: goto err;
  }
closeq:
  esi++;
  if (esi == ebx) return -1;
  eax = W11BT(esi) - 9;
  if (eax > 0xc) goto err;
  switch (w11h(0x62acac, 0x62acbc, eax)) {
    case 0x62ab37: goto ws;
    case 0x62ac00:
      *(u32 *)nextTok = esi + 1;
      return 1;
    case 0x62abde: goto sol;
    default: goto err;
  }
ws:
  esi++;
  if (esi == ebx) return -1;
  eax = W11BT(esi) - 5;
  if (eax > 0x18) goto err;
  switch (w11h(0x62accc, 0x62acf0, eax)) {
    case 0x62ab61:
      if ((s32)(ebx - esi) < 2) return -2;
      if (!((WDPred)*(u32 *)(enc + 0x158))(enc, esi)) goto err;
      esi += 2;
      goto abad;
    case 0x62ab75:
      if ((s32)(ebx - esi) < 3) return -2;
      if (!((WDPred)*(u32 *)(enc + 0x15c))(enc, esi)) goto err;
      esi += 3;
      goto abad;
    case 0x62ab89:
      if ((s32)(ebx - esi) < 4) return -2;
      if (!((WDPred)*(u32 *)(enc + 0x160))(enc, esi)) goto err;
      esi += 4;
      goto abad;
    case 0x62ab37: goto ws;
    case 0x62ac00:
      *(u32 *)nextTok = esi + 1;
      return 1;
    case 0x62abde: goto sol;
    case 0x62ab5e:
      esi++;
      goto abad;
    default: goto err;
  }
sol:
  esi++;
  if (esi == ebx) return -1;
  if (*(u8 *)esi != 0x3e) goto err;
  *(u32 *)nextTok = esi + 1;
  return 3;
abad:
  if (esi != ebx) goto top;
  return -1;
err:
  *(u32 *)nextTok = esi;
  return 0;
#undef W11BT
}
PCREG(62a8e0, GUESS_62a8e0);

// ---------------------------------------------------------------- 0x556030
extern "C" void FASTCALL ext_4e0be0_we(u32, u32) __asm__("ext_4e0be0");

// 0x556030: stdcall(src) ret 4, void (/GS cookie not reproduced). Reads the float entries 0x5003d0(src[4], i) in the order 2, 1, 0, 5, 4, 3 (each type byte must be 0 or 2, else logged (line 0x104,
// text 0x69c938) + fatal pointer, execution continues): A = (e0, e1, e2), B = (e3, e4, e5) scaled by 0x3c8efa35 (4e0d00) and A rotated by the euler angles B (0x4e0be0, real exe code).
// Then A.x, A.y, A.z are written into the entries 0x5003d0(src[8], 0 / 1 / 2) (same type check, the type byte becomes 2 in every case).
extern "C" void STDCALL GUESS_556030(u32 src) {
  u32 A[3], B[3];
  u32 s4 = *(u32 *)(src + 4);
  u32 e;
  e = w7ent(s4, 2); A[2] = *(u32 *)e;
  e = w7ent(s4, 1); A[1] = *(u32 *)e;
  e = w7ent(s4, 0); A[0] = *(u32 *)e;
  e = w7ent(s4, 5); B[2] = *(u32 *)e;
  e = w7ent(s4, 4); B[1] = *(u32 *)e;
  e = w7ent(s4, 3); B[0] = *(u32 *)e;
  ext_4e0d00_w6((u32)B, 0x3c8efa35);
  ext_4e0be0_we((u32)A, (u32)B);
  u32 o8 = *(u32 *)(src + 8);
  for (int i = 0; i < 3; i++) {
    e = w7ent(o8, i);
    *(u8 *)(e + 4) = 2;
    *(u32 *)e = A[i];
  }
}
PCREG(556030, GUESS_556030);

// ---------------------------------------------------------------- 0x5563d0
// 0x5563d0: thiscall(src) ret 4, void (/GS cookie not reproduced). Entries 0x5003d0(src[4], i): 0 -> edi (kind 3 dword, kind 4 object vslot 0x34(), else logged line 0x111 / text 0x69c9b0 + fatal and 0),
// 1, 2, 3 and 5 (kind 0 or 1, else logged line 0x104 / 0x69c938 + fatal): V1, V2, ID and KEY dwords, 4 (kind 0 or 2): float R. lim = R * R; h = G[0x9b] vslot 0x114(edi, 0, 0x6a57fc, 0x48a) & 0xffff;
// when this[0x10] is 0 it is set from G[0x9b][0xadc] vslot 0x25c(0x685f44, 0) (0 ends); L = this[0x10] vslot 0x100(0x6a5cf0) (0 ends); P = {0,0,0}; N = G[0x9b] vslot 0x58(ID) vslot 0x84(&P); then
// for it = L vslot 0x84(&P, R, &cursor (-1), -1) while non-null: when it[0x54][4] == KEY: Q = {0,0,0}, it vslot 0x84(&Q), d = 0x4e0830(&P, &Q) (real exe code) and unless d > lim (NaN passes)
// it vslot 0x128(h, {V2, V1}, 0).
extern "C" void THISCALL GUESS_5563d0(u32 self, u32 src) {
  u32 s4 = *(u32 *)(src + 4);
  u32 e = ext_5003d0_w6(s4, 0);
  u32 edi;
  u8 k = *(u8 *)(e + 4);
  if (k == 3) edi = *(u32 *)e;
  else if (k == 4) {
    u32 o = *(u32 *)e;
    edi = ((W6B)*(u32 *)(*(u32 *)o + 0x34))(o);
  } else {
    w7fatal(0x111, 0x69c9b0);
    edi = 0;
  }
  e = w7ent01(s4, 1); u32 v1 = *(u32 *)e;
  e = w7ent01(s4, 2); u32 v2 = *(u32 *)e;
  e = w7ent01(s4, 3); u32 id = *(u32 *)e;
  e = w7ent(s4, 4); u32 rb = *(u32 *)e;
  e = w7ent01(s4, 5); u32 key = *(u32 *)e;
  float r = bitsf(rb);
  float lim = r * r;
  u32 H = w6ld(*(u32 *)0x70039c + 0x9b);
  u32 h = ((W6T4)*(u32 *)(*(u32 *)H + 0x114))(H, edi, 0, 0x6a57fc, 0x48a) & 0xffff;
  u32 pair[2] = {v2, v1};
  if (*(u32 *)(self + 0x10) == 0) {
    u32 S = w6ld(w6ld(*(u32 *)0x70039c + 0x9b) + 0xadc);
    *(u32 *)(self + 0x10) = ((W6T2b)*(u32 *)(*(u32 *)S + 0x25c))(S, 0x685f44, 0);
  }
  u32 C = *(u32 *)(self + 0x10);
  if (C == 0) return;
  u32 L = ((W6T1)*(u32 *)(*(u32 *)C + 0x100))(C, 0x6a5cf0);
  if (L == 0) return;
  u32 P[3] = {0, 0, 0};
  u32 H2 = w6ld(*(u32 *)0x70039c + 0x9b);
  u32 N = ((W6T1)*(u32 *)(*(u32 *)H2 + 0x58))(H2, id);
  ((W6T1)*(u32 *)(*(u32 *)N + 0x84))(N, (u32)P);
  u32 cur = 0xffffffff;
  u32 it = ((W6T4)*(u32 *)(*(u32 *)L + 0x84))(L, (u32)P, rb, (u32)&cur, 0xffffffff);
  while (it != 0) {
    if (*(u32 *)(*(u32 *)(it + 0x54) + 4) == key) {
      u32 Q[3] = {0, 0, 0};
      ((W6T1)*(u32 *)(*(u32 *)it + 0x84))(it, (u32)Q);
      float d = ext_4e0830_w7((u32)P, (u32)Q);
      if (!(d > lim)) ((W6T3)*(u32 *)(*(u32 *)it + 0x128))(it, h, (u32)pair, 0);
    }
    it = ((W6T4)*(u32 *)(*(u32 *)L + 0x84))(L, (u32)P, rb, (u32)&cur, 0xffffffff);
  }
}
PCREG(5563d0, GUESS_5563d0);

// ---------------------------------------------------------------- 0x627bb0
extern "C" s32 ext_626f60_wf(u32, u32, u32, u32) __asm__("ext_626f60");
extern "C" s32 ext_627420_wf(u32, u32, u32, u32) __asm__("ext_627420");
extern "C" s32 ext_627520_wf(u32, u32, u32, u32) __asm__("ext_627520");
extern "C" s32 ext_6277b0_wf(u32, u32, u32, u32) __asm__("ext_6277b0");
extern "C" s32 ext_6281a0_wf(u32, u32, u32, u32) __asm__("ext_6281a0");
extern "C" u32 ext_62c640_wf(u32, u32) __asm__("ext_62c640");
// byte type of the big endian UTF-16 character at p: enc[0x4c + low byte] when the high byte is 0, else the exe's unicode_byte_type (0x62c640)
static inline u32 w12bt(u32 enc, u32 p) {
  u32 hi = *(u8 *)p, lo = *(u8 *)(p + 1);
  return hi == 0 ? (u32) * (u8 *)(enc + 0x4c + lo) : ext_62c640_wf(hi, lo);
}
// naming bitmap test (page index table ptab, bitmaps 0x6bf720)
static inline bool w12bm(u32 ptab, u32 hi, u32 lo) {
  u32 idx = (lo >> 5) + *(u8 *)(ptab + hi) * 8;
  return (*(u32 *)(0x6bf720 + idx * 4) >> (lo & 0x1f)) & 1;
}

// 0x627bb0: cdecl(enc, ptr, end, nextTok) returns -1 (input ends), -2 (partial character), 0 (error, *nextTok = ptr), 2 (start tag without attributes, *nextTok = ptr + 2), 4 ("/>"), or the result of
// a scanner: the big endian UTF-16 scanLt (the text after '<'): '?' -> 0x6281a0, '!' then '[' -> 0x627420 / '-' -> 0x627520 (else error), '/' -> 0x6277b0, a name start (types 22, 24 or a two byte
// character found in the name start bitmap) begins a tag name (type table 0x627f10: name characters, one colon (types 23, 25 .. 27, two byte characters in the name character bitmap), white space
// -> 0x626f60 on the first attribute name start, '>' returns 2, '/' needs '>' and returns 4). Characters cost 2 bytes; the dispatch tables are the exe's own (read at run time).
extern "C" s32 GUESS_627bb0(u32 enc, u32 ptr, u32 end, u32 nextTok) {
  u32 edx = ptr, edi = end, colon = 0, eax, t;
  if (edx == edi) return -1;
  t = w12bt(enc, edx);
  eax = t - 5;
  if (eax > 0x18) goto err;
  switch (w11h(0x627ed0, 0x627ef4, eax)) {
    case 0x627d22: goto p2;
    case 0x627d37: goto p3;
    case 0x627d4c: goto p4;
    case 0x627e98: return ext_6281a0_wf(enc, edx + 2, edi, nextTok);
    case 0x627e38: goto excl;
    case 0x627eae: return ext_6277b0_wf(enc, edx + 2, edi, nextTok);
    case 0x627c35: goto nmstart;
    case 0x627c06:
      if (!w12bm(0x6bfc20, *(u8 *)edx, *(u8 *)(edx + 1))) goto err;
      goto nmstart;
    default: goto err;
  }
nmstart:
  edx += 2;
  colon = 0;
  if (edx == edi) return -1;
nameloop:
  t = w12bt(enc, edx);
  eax = t - 5;
  if (eax > 0x18) goto err;
  switch (w11h(0x627f10, 0x627f38, eax)) {
    case 0x627d22: goto p2;
    case 0x627d37: goto p3;
    case 0x627d4c: goto p4;
    case 0x627d61: goto ws;
    case 0x627dfa: goto gt;
    case 0x627e0c: goto sol;
    case 0x627d0f: goto advance;
    case 0x627c90:
      if (colon) goto err;
      edx += 2;
      colon = 1;
      if (edx == edi) return -1;
      t = w12bt(enc, edx);
      eax = t - 5;
      if (eax > 0x18) goto err;
      switch (w11h(0x627f54, 0x627f6c, eax)) {
        case 0x627d22: goto p2;
        case 0x627d37: goto p3;
        case 0x627d4c: goto p4;
        case 0x627d0f: goto advance;
        case 0x627ce3:
          if (!w12bm(0x6bfc20, *(u8 *)edx, *(u8 *)(edx + 1))) goto err;
          goto advance;
        default: goto err;
      }
    case 0x627c84:
      if (!w12bm(0x6bfd20, *(u8 *)edx, *(u8 *)(edx + 1))) goto err;
      goto advance;
    default: goto err;
  }
advance:
  edx += 2;
  if (edx != edi) goto nameloop;
  return -1;
ws:
  edx += 2;
  if (edx == edi) return -1;
wsloop:
  t = w12bt(enc, edx);
  eax = t - 5;
  if (eax > 0x18) goto err;
  switch (w11h(0x627f88, 0x627fac, eax)) {
    case 0x627d22: goto p2;
    case 0x627d37: goto p3;
    case 0x627d4c: goto p4;
    case 0x627da5:
      edx += 2;
      if (edx != edi) goto wsloop;
      return -1;
    case 0x627dfa: goto gt;
    case 0x627e0c: goto sol;
    case 0x627de1: return ext_626f60_wf(enc, edx + 2, edi, nextTok);
    case 0x627db4:
      if (!w12bm(0x6bfc20, *(u8 *)edx, *(u8 *)(edx + 1))) goto err;
      return ext_626f60_wf(enc, edx + 2, edi, nextTok);
    default: goto err;
  }
gt:
  *(u32 *)nextTok = edx + 2;
  return 2;
sol:
  edx += 2;
  if (edx == edi) return -1;
  if (*(u8 *)edx != 0) goto err;
  if (*(u8 *)(edx + 1) != 0x3e) goto err;
  *(u32 *)nextTok = edx + 2;
  return 4;
excl:
  edx += 2;
  if (edx == edi) return -1;
  t = w12bt(enc, edx);
  if (t == 0x14) return ext_627420_wf(enc, edx + 2, edi, nextTok);
  if (t == 0x1b) return ext_627520_wf(enc, edx + 2, edi, nextTok);
  goto err;
p2:
  if ((s32)(edi - edx) >= 2) goto err;
  return -2;
p3:
  if ((s32)(edi - edx) >= 3) goto err;
  return -2;
p4:
  if ((s32)(edi - edx) >= 4) goto err;
  return -2;
err:
  *(u32 *)nextTok = edx;
  return 0;
}
PCREG(627bb0, GUESS_627bb0);

// ---------------------------------------------------------------- 0x629c10
extern "C" s32 ext_628fc0_wg(u32, u32, u32, u32) __asm__("ext_628fc0");
extern "C" s32 ext_629480_wg(u32, u32, u32, u32) __asm__("ext_629480");
extern "C" s32 ext_629580_wg(u32, u32, u32, u32) __asm__("ext_629580");
extern "C" s32 ext_629810_wg(u32, u32, u32, u32) __asm__("ext_629810");
extern "C" s32 ext_62a200_wg(u32, u32, u32, u32) __asm__("ext_62a200");
extern "C" u32 ext_62c640_wg(u32, u32) __asm__("ext_62c640");
// byte type of the little endian UTF-16 character at p: enc[0x4c + low byte] when the high byte is 0, else the exe's unicode_byte_type (0x62c640)
static inline u32 w13bt(u32 enc, u32 p) {
  u32 hi = *(u8 *)(p + 1), lo = *(u8 *)p;
  return hi == 0 ? (u32) * (u8 *)(enc + 0x4c + lo) : ext_62c640_wg(hi, lo);
}
// naming bitmap test (page index table ptab, bitmaps 0x6bf720)
static inline bool w13bm(u32 ptab, u32 hi, u32 lo) {
  u32 idx = (lo >> 5) + *(u8 *)(ptab + hi) * 8;
  return (*(u32 *)(0x6bf720 + idx * 4) >> (lo & 0x1f)) & 1;
}

// 0x629c10: cdecl(enc, ptr, end, nextTok) returns -1 (input ends), -2 (partial character), 0 (error, *nextTok = ptr), 2 (start tag without attributes, *nextTok = ptr + 2), 4 ("/>"), or the result of
// a scanner: the little endian UTF-16 scanLt (the text after '<'): '?' -> 0x6281a0, '!' then '[' -> 0x627420 / '-' -> 0x627520 (else error), '/' -> 0x6277b0, a name start (types 22, 24 or a two byte
// character found in the name start bitmap) begins a tag name (type table 0x629f70: name characters, one colon (types 23, 25 .. 27, two byte characters in the name character bitmap), white space
// -> 0x626f60 on the first attribute name start, '>' returns 2, '/' needs '>' and returns 4). Characters cost 2 bytes; the dispatch tables are the exe's own (read at run time).
extern "C" s32 GUESS_629c10(u32 enc, u32 ptr, u32 end, u32 nextTok) {
  u32 edx = ptr, edi = end, colon = 0, eax, t;
  if (edx == edi) return -1;
  t = w13bt(enc, edx);
  eax = t - 5;
  if (eax > 0x18) goto err;
  switch (w11h(0x629f30, 0x629f54, eax)) {
    case 0x629d82: goto p2;
    case 0x629d97: goto p3;
    case 0x629dac: goto p4;
    case 0x629ef8: return ext_62a200_wg(enc, edx + 2, edi, nextTok);
    case 0x629e98: goto excl;
    case 0x629f0e: return ext_629810_wg(enc, edx + 2, edi, nextTok);
    case 0x629c95: goto nmstart;
    case 0x629c66:
      if (!w13bm(0x6bfc20, *(u8 *)(edx + 1), *(u8 *)edx)) goto err;
      goto nmstart;
    default: goto err;
  }
nmstart:
  edx += 2;
  colon = 0;
  if (edx == edi) return -1;
nameloop:
  t = w13bt(enc, edx);
  eax = t - 5;
  if (eax > 0x18) goto err;
  switch (w11h(0x629f70, 0x629f98, eax)) {
    case 0x629d82: goto p2;
    case 0x629d97: goto p3;
    case 0x629dac: goto p4;
    case 0x629dc1: goto ws;
    case 0x629e5a: goto gt;
    case 0x629e6c: goto sol;
    case 0x629d6f: goto advance;
    case 0x629cf0:
      if (colon) goto err;
      edx += 2;
      colon = 1;
      if (edx == edi) return -1;
      t = w13bt(enc, edx);
      eax = t - 5;
      if (eax > 0x18) goto err;
      switch (w11h(0x629fb4, 0x629fcc, eax)) {
        case 0x629d82: goto p2;
        case 0x629d97: goto p3;
        case 0x629dac: goto p4;
        case 0x629d6f: goto advance;
        case 0x629d43:
          if (!w13bm(0x6bfc20, *(u8 *)(edx + 1), *(u8 *)edx)) goto err;
          goto advance;
        default: goto err;
      }
    case 0x629ce4:
      if (!w13bm(0x6bfd20, *(u8 *)(edx + 1), *(u8 *)edx)) goto err;
      goto advance;
    default: goto err;
  }
advance:
  edx += 2;
  if (edx != edi) goto nameloop;
  return -1;
ws:
  edx += 2;
  if (edx == edi) return -1;
wsloop:
  t = w13bt(enc, edx);
  eax = t - 5;
  if (eax > 0x18) goto err;
  switch (w11h(0x629fe8, 0x62a00c, eax)) {
    case 0x629d82: goto p2;
    case 0x629d97: goto p3;
    case 0x629dac: goto p4;
    case 0x629e05:
      edx += 2;
      if (edx != edi) goto wsloop;
      return -1;
    case 0x629e5a: goto gt;
    case 0x629e6c: goto sol;
    case 0x629e41: return ext_628fc0_wg(enc, edx + 2, edi, nextTok);
    case 0x629e14:
      if (!w13bm(0x6bfc20, *(u8 *)(edx + 1), *(u8 *)edx)) goto err;
      return ext_628fc0_wg(enc, edx + 2, edi, nextTok);
    default: goto err;
  }
gt:
  *(u32 *)nextTok = edx + 2;
  return 2;
sol:
  edx += 2;
  if (edx == edi) return -1;
  if (*(u8 *)(edx + 1) != 0) goto err;
  if (*(u8 *)edx != 0x3e) goto err;
  *(u32 *)nextTok = edx + 2;
  return 4;
excl:
  edx += 2;
  if (edx == edi) return -1;
  t = w13bt(enc, edx);
  if (t == 0x14) return ext_629480_wg(enc, edx + 2, edi, nextTok);
  if (t == 0x1b) return ext_629580_wg(enc, edx + 2, edi, nextTok);
  goto err;
p2:
  if ((s32)(edi - edx) >= 2) goto err;
  return -2;
p3:
  if ((s32)(edi - edx) >= 3) goto err;
  return -2;
p4:
  if ((s32)(edi - edx) >= 4) goto err;
  return -2;
err:
  *(u32 *)nextTok = edx;
  return 0;
}
PCREG(629c10, GUESS_629c10);

// ---------------------------------------------------------------- 0x626f60
extern "C" s32 ext_628630_wh(u32, u32, u32, u32) __asm__("ext_628630");
// byte type inside attribute values: like w12bt but the high byte switch is the exe's own inlined copy (tables 0x627364 / 0x627374)
static inline u32 w14vt(u32 enc, u32 p) {
  u32 hi = *(u8 *)p, lo = *(u8 *)(p + 1);
  if (hi == 0) return (u32) * (u8 *)(enc + 0x4c + lo);
  u32 x = hi - 0xd8;
  if (x > 0x27) return 0x1d;
  switch (w11h(0x627364, 0x627374, x)) {
    case 0x627109: return 7;
    case 0x627110: return 8;
    case 0x627117: return lo >= 0xfe ? 0 : 0x1d;
    default: return 0x1d;
  }
}

// 0x626f60: cdecl(enc, ptr, end, nextTok): the big endian UTF-16 attribute scanner (scanAtts) of an element start tag; returns -1 (input ends), -2 (partial character), 0 (error, *nextTok = ptr),
// 1 ('>' after a value: *nextTok = ptr + 2), 3 ("/>": *nextTok = ptr + 2) or the result of 0x628630 (character reference scanner, negative returned, 0 -> *nextTok = outp). Names: name characters
// (types 22, 24 .. 27 and two byte characters in the name character bitmap) advance, one colon (after it name starts: types 22, 24, bitmap 0x6bfc20), white space then '=' (type 14), quote (12 / 13),
// the value runs to the same quote ('<', bad types fail, '&' calls 0x628630, 6 / 7 type leads need 3 / 4 bytes), after the closing quote white space, '>' or "/>" or the next name start. The dispatch
// tables are the exe's own (read at run time).
extern "C" s32 GUESS_626f60(u32 enc, u32 ptr, u32 end, u32 nextTok) {
  u32 edi = ptr, esi = end, colon = 0, eax, t, q = 0, outp = 0;
  if (edi == esi) return -1;
top:
  t = w12bt(enc, edi);
  eax = t - 5;
  if (eax > 0x18) goto err;
  switch (w11h(0x6272f0, 0x627314, eax)) {
    case 0x6272a9: goto p2;
    case 0x6272c0: goto p3;
    case 0x6272d7: goto p4;
    case 0x627030: goto skips;
    case 0x627078: goto eq;
    case 0x62723f: goto advance;
    case 0x626fcf:
      if (colon) goto err;
      edi += 2;
      colon = 1;
      if (edi == esi) return -1;
      t = w12bt(enc, edi);
      eax = t - 5;
      if (eax > 0x18) goto err;
      switch (w11h(0x627330, 0x627348, eax)) {
        case 0x6272a9: goto p2;
        case 0x6272c0: goto p3;
        case 0x6272d7: goto p4;
        case 0x62723f: goto advance;
        case 0x62701e:
          if (!w12bm(0x6bfc20, *(u8 *)edi, *(u8 *)(edi + 1))) goto err;
          goto advance;
        default: goto err;
      }
    case 0x626fbd:
      if (!w12bm(0x6bfd20, *(u8 *)edi, *(u8 *)(edi + 1))) goto err;
      goto advance;
    default: goto err;
  }
advance:
  edi += 2;
  if (edi != esi) goto top;
  return -1;
skips:
  edi += 2;
  if (edi == esi) return -1;
  t = w12bt(enc, edi);
  if (t == 0xe) goto eq;
  if ((s32)t < 9) goto err;
  if ((s32)t <= 0xa) goto skips;
  if (t == 0x15) goto skips;
  goto err;
eq:
  colon = 0;
eqloop:
  edi += 2;
  if (edi == esi) return -1;
  q = w12bt(enc, edi);
  if (q == 0xc || q == 0xd) goto valadv;
  if ((s32)q < 9) goto err;
  if ((s32)q <= 0xa) goto eqloop;
  if (q == 0x15) goto eqloop;
  goto err;
valadv:
  edi += 2;
valset:
  outp = edi;
valloop:
  if (edi == esi) return -1;
  t = w14vt(enc, edi);
  if (t == q) goto closeq;
  if (t > 8) goto valadv;
  switch (w11h(0x62739c, 0, t)) {
    case 0x62716f: {
      s32 r = ext_628630_wh(enc, edi + 2, esi, (u32)&outp);
      if (r <= 0) {
        if (r != 0) return r;
        *(u32 *)nextTok = outp;
        return 0;
      }
      edi = outp;
      goto valloop;
    }
    case 0x6270cf: goto valadv;
    case 0x627136:
      if ((s32)(esi - edi) < 2) return -2;
      goto valadv;
    case 0x627145:
      if ((s32)(esi - edi) < 3) return -2;
      edi += 3;
      goto valset;
    case 0x62715a:
      if ((s32)(esi - edi) < 4) return -2;
      edi += 4;
      goto valset;
    default: goto err;
  }
closeq:
  edi += 2;
  if (edi == esi) return -1;
  t = w12bt(enc, edi);
  eax = t - 9;
  if (eax > 0xc) goto err;
  switch (w11h(0x6273c0, 0x6273d0, eax)) {
    case 0x6271d6: goto ws;
    case 0x627295:
      *(u32 *)nextTok = edi + 2;
      return 1;
    case 0x627267: goto sol;
    default: goto err;
  }
ws:
  edi += 2;
  if (edi == esi) return -1;
  t = w12bt(enc, edi);
  eax = t - 5;
  if (eax > 0x18) goto err;
  switch (w11h(0x6273e0, 0x627404, eax)) {
    case 0x6272a9: goto p2;
    case 0x6272c0: goto p3;
    case 0x6272d7: goto p4;
    case 0x6271d6: goto ws;
    case 0x627295:
      *(u32 *)nextTok = edi + 2;
      return 1;
    case 0x627267: goto sol;
    case 0x62723f: goto advance;
    case 0x627212:
      if (!w12bm(0x6bfc20, *(u8 *)edi, *(u8 *)(edi + 1))) goto err;
      goto advance;
    default: goto err;
  }
sol:
  edi += 2;
  if (edi == esi) return -1;
  if (*(u8 *)edi != 0) goto err;
  if (*(u8 *)(edi + 1) != 0x3e) goto err;
  *(u32 *)nextTok = edi + 2;
  return 3;
p2:
  if ((s32)(esi - edi) >= 2) goto err;
  return -2;
p3:
  if ((s32)(esi - edi) >= 3) goto err;
  return -2;
p4:
  if ((s32)(esi - edi) >= 4) goto err;
  return -2;
err:
  *(u32 *)nextTok = edi;
  return 0;
}
PCREG(626f60, GUESS_626f60);

// ---------------------------------------------------------------- 0x49be80
extern "C" void FASTCALL ext_4419f0_wi(u32, u32) __asm__("ext_4419f0");
extern "C" double VECTORCALL ext_634d7c_wi(double) __asm__("ext_634d7c");
static inline bool w15eq(const u32 *a, const u32 *b) {
  return bitsf(a[0]) == bitsf(b[0]) && bitsf(a[1]) == bitsf(b[1]) && bitsf(a[2]) == bitsf(b[2]);
}

// 0x49be80: fastcall(A = ECX, B = EDX, float r, float k, float s, list L) ret 0x10, returns AL. f8sq = r * r. Scale pair from s: when 1.0 > s (constant [0x678858], strict): q = (float)(C / (double)s)
// (C = double [0x678610]), t = (float)sqrt((double)q) (CRT 0x634d7c), R1 = q / t, F = (float)(C / (double)t); otherwise t = (float)sqrt((double)s), R1 = (float)(C / (double)t), F = s / t. L null: 0.
// Iterates L (vslot 0x4c(&it) then item = vslot 0x64(&it) until null): item floats at +4 .. +0x24 are three vertices V0 (+4), V1 (+0x10), V2 (+0x1c); an item with two equal vertices (V0 == V1, V1 == V2 or V2 == V0,
// all components compared as floats) is skipped. Vertices are transformed in place by 0x4419f0(P, A) (3x3 matrix, x87 real exe code) and 0x441940(P, B) (+ B). For each transformed vertex P with
// m = (P.y * P.y + P.x * P.x) + P.z * P.z: hit when r * r > m and (double)P.z > sqrt((double)((P.y * F)^2 + P.z^2)) * (double)k and (double)P.z > sqrt((double)((P.x * R1)^2 + P.z^2)) * (double)k;
// any hit returns 1; no hit in any item returns 0.
extern "C" u8 FASTCALL GUESS_49be80(u32 A, u32 B, float r, float k, float s, u32 L) {
  float f8sq = r * r;
  float c1 = *(float *)0x678858;
  double C = *(double *)0x678610;
  float R1, F;
  if (c1 > s) {
    float q = (float)(C / (double)s);
    float t = (float)ext_634d7c_wi((double)q);
    R1 = q / t;
    F = (float)(C / (double)t);
  } else {
    float t = (float)ext_634d7c_wi((double)s);
    R1 = (float)(C / (double)t);
    F = s / t;
  }
  if (L == 0) return 0;
  u32 st[4];
  ((W6T1)*(u32 *)(*(u32 *)L + 0x4c))(L, (u32)st);
  u32 item = ((W6T1)*(u32 *)(*(u32 *)L + 0x64))(L, (u32)st);
  while (item != 0) {
    u32 T[9];
    for (int i = 0; i < 9; i++) T[i] = *(u32 *)(item + 4 + 4 * i);
    if (!(w15eq(&T[0], &T[3]) || w15eq(&T[3], &T[6]) || w15eq(&T[6], &T[0]))) {
      ext_4419f0_wi((u32)&T[0], A);
      ext_4419f0_wi((u32)&T[3], A);
      ext_4419f0_wi((u32)&T[6], A);
      ext_441940_w6((u32)&T[0], B);
      ext_441940_w6((u32)&T[3], B);
      ext_441940_w6((u32)&T[6], B);
      for (int v = 0; v < 3; v++) {
        float px = bitsf(T[3 * v]), py = bitsf(T[3 * v + 1]), pz = bitsf(T[3 * v + 2]);
        float m = (py * py + px * px) + pz * pz;
        bool in = f8sq > m;
        float pzz = pz * pz;
        float ya = py * F;
        float xa = px * R1;
        float ya2 = ya * ya;
        ya2 = ya2 + pzz;
        double sa = ext_634d7c_wi((double)ya2) * (double)k;
        bool a1 = (double)pz > sa;
        float xa2 = xa * xa;
        xa2 = xa2 + pzz;
        double sb = ext_634d7c_wi((double)xa2) * (double)k;
        bool a2 = (double)pz > sb;
        if (in && (a1 && a2)) return 1;
      }
    }
    item = ((W6T1)*(u32 *)(*(u32 *)L + 0x64))(L, (u32)st);
  }
  return 0;
}
PCREG(49be80, GUESS_49be80);

// ---------------------------------------------------------------- 0x62b450
extern "C" s32 ext_62a8e0_wj(u32, u32, u32, u32) __asm__("ext_62a8e0");
extern "C" s32 ext_62ad10_wj(u32, u32, u32, u32) __asm__("ext_62ad10");
extern "C" s32 ext_62add0_wj(u32, u32, u32, u32) __asm__("ext_62add0");
extern "C" s32 ext_62b040_wj(u32, u32, u32, u32) __asm__("ext_62b040");
extern "C" s32 ext_62bb10_wj(u32, u32, u32, u32) __asm__("ext_62bb10");

// 0x62b450: cdecl(enc, ptr, end, nextTok): the single byte scanLt (the text after '<'); returns -1 (input ends), -2 (partial character), 0 (error, *nextTok = ptr), 2 (start tag without attributes:
// *nextTok = ptr + 1), 4 ("/>": *nextTok = ptr + 1) or a scanner result: '?' (type 15) -> 0x62bb10, '!' then '[' (type 0x14) -> 0x62ad10 / '-' (0x1b) -> 0x62add0 (else error), '/' (17) -> 0x62b040,
// a name start (types 22, 24 or a lead byte 5 / 6 / 7 accepted by enc[0x158 / 0x15c / 0x160]) begins the tag name; name loop (tables 0x62b844 / 0x62b86c: lead bytes via enc[0x14c / 0x150 / 0x154],
// one colon, after it name starts via 0x158 / 0x15c / 0x160), white space then a name start calls 0x62a8e0 (attributes), '>' -> 2, '/' needs '>' -> 4. The remaining length drives the partial
// character checks inside the name loop. The dispatch tables are the exe's own (read at run time).
extern "C" s32 GUESS_62b450(u32 enc, u32 ptr, u32 end, u32 nextTok) {
  u32 esi = ptr, rem = 0, colon = 0, eax, t, adv;
#define W16BT(p) ((u32) * (u8 *)(enc + 0x4c + *(u8 *)(p)))
  if (esi == end) return -1;
  t = W16BT(esi);
  eax = t - 5;
  if (eax > 0x18) goto err;
  switch (w11h(0x62b804, 0x62b828, eax)) {
    case 0x62b48c: adv = 1; goto nmstart;
    case 0x62b493:
      if ((s32)(end - esi) < 2) return -2;
      if (!((WDPred)*(u32 *)(enc + 0x158))(enc, esi)) goto err;
      adv = 2;
      goto nmstart;
    case 0x62b4bc:
      if ((s32)(end - esi) < 3) return -2;
      if (!((WDPred)*(u32 *)(enc + 0x15c))(enc, esi)) goto err;
      adv = 3;
      goto nmstart;
    case 0x62b4e5:
      if ((s32)(end - esi) < 4) return -2;
      if (!((WDPred)*(u32 *)(enc + 0x160))(enc, esi)) goto err;
      adv = 4;
      goto nmstart;
    case 0x62b7ca: return ext_62bb10_wj(enc, esi + 1, end, nextTok);
    case 0x62b782: goto excl;
    case 0x62b7e0: return ext_62b040_wj(enc, esi + 1, end, nextTok);
    default: goto err;
  }
nmstart:
  esi += adv;
  colon = 0;
  if (esi == end) return -1;
  rem = end - esi;
nameloop:
  t = W16BT(esi);
  eax = t - 5;
  if (eax > 0x18) goto err;
  switch (w11h(0x62b844, 0x62b86c, eax)) {
    case 0x62b542:
      if ((s32)rem < 2) return -2;
      if (!((WDPred)*(u32 *)(enc + 0x14c))(enc, esi)) goto err;
      esi += 2;
      rem -= 2;
      goto aftername;
    case 0x62b56b:
      if ((s32)rem < 3) return -2;
      if (!((WDPred)*(u32 *)(enc + 0x150))(enc, esi)) goto err;
      esi += 3;
      rem -= 3;
      goto aftername;
    case 0x62b594:
      if ((s32)rem < 4) return -2;
      if (!((WDPred)*(u32 *)(enc + 0x154))(enc, esi)) goto err;
      esi += 4;
      rem -= 4;
      goto aftername;
    case 0x62b646: goto ws;
    case 0x62b74d: goto gt;
    case 0x62b75f: goto sol;
    case 0x62b5e2:
      esi++;
      rem--;
      goto aftername;
    case 0x62b5a5:
      if (colon) goto err;
      esi++;
      colon = 1;
      rem--;
      if (esi == end) return -1;
      t = W16BT(esi);
      eax = t - 5;
      if (eax > 0x18) goto err;
      switch (w11h(0x62b888, 0x62b8a0, eax)) {
        case 0x62b5e6:
          if ((s32)rem < 2) return -2;
          if (!((WDPred)*(u32 *)(enc + 0x158))(enc, esi)) goto err;
          esi += 2;
          rem -= 2;
          goto aftername;
        case 0x62b5fa:
          if ((s32)rem < 3) return -2;
          if (!((WDPred)*(u32 *)(enc + 0x15c))(enc, esi)) goto err;
          esi += 3;
          rem -= 3;
          goto aftername;
        case 0x62b60e:
          if ((s32)rem < 4) return -2;
          if (!((WDPred)*(u32 *)(enc + 0x160))(enc, esi)) goto err;
          esi += 4;
          rem -= 4;
          goto aftername;
        case 0x62b5e2:
          esi++;
          rem--;
          goto aftername;
        default: goto err;
      }
    default: goto err;
  }
aftername:
  if (esi != end) goto nameloop;
  return -1;
ws:
  esi++;
  if (esi == end) return -1;
wsloop:
  t = W16BT(esi);
  eax = t - 5;
  if (eax > 0x18) goto err;
  switch (w11h(0x62b8bc, 0x62b8e0, eax)) {
    case 0x62b69b:
      if ((s32)(end - esi) < 2) return -2;
      if (!((WDPred)*(u32 *)(enc + 0x158))(enc, esi)) goto err;
      return ext_62a8e0_wj(enc, esi + 2, end, nextTok);
    case 0x62b6d3:
      if ((s32)(end - esi) < 3) return -2;
      if (!((WDPred)*(u32 *)(enc + 0x15c))(enc, esi)) goto err;
      return ext_62a8e0_wj(enc, esi + 3, end, nextTok);
    case 0x62b70b:
      if ((s32)(end - esi) < 4) return -2;
      if (!((WDPred)*(u32 *)(enc + 0x160))(enc, esi)) goto err;
      return ext_62a8e0_wj(enc, esi + 4, end, nextTok);
    case 0x62b674:
      esi++;
      if (esi != end) goto wsloop;
      return -1;
    case 0x62b681: return ext_62a8e0_wj(enc, esi + 1, end, nextTok);
    case 0x62b74d: goto gt;
    case 0x62b762: goto sol;
    default: goto err;
  }
gt:
  *(u32 *)nextTok = esi + 1;
  return 2;
sol:
  esi++;
  if (esi == end) return -1;
  if (*(u8 *)esi != 0x3e) goto err;
  *(u32 *)nextTok = esi + 1;
  return 4;
excl:
  esi++;
  if (esi == end) return -1;
  t = W16BT(esi);
  if ((t & 0xff) == 0x14) return ext_62ad10_wj(enc, esi + 1, end, nextTok);
  if ((t & 0xff) == 0x1b) return ext_62add0_wj(enc, esi + 1, end, nextTok);
  goto err;
err:
  *(u32 *)nextTok = esi;
  return 0;
#undef W16BT
}
PCREG(62b450, GUESS_62b450);

// ---------------------------------------------------------------- 0x61c790
typedef u32 (*WK3)(u32, u32, u32);
extern "C" u32 GUESS_61c790(u32 parser, u32 enc, u32 isCdata, u32 ptr, u32 end, u32 buf);

// 0x61c790: cdecl(parser, enc, isCdata, ptr, end, buf): appends a normalized attribute value to buf ([+8] limit, [+0xc] cursor, [+0x10] start); returns 0 (done / end token), 1 (out of memory),
// 4 (input ends: parser[0x118] = ptr or next when enc == parser[0x8c]), 0xb, 0xc, 0xf, 0x10 (entity errors), 0xe (bad character), 0x17 (unexpected token) or a nested result. Tokens come from
// enc[0x10](enc, ptr, end, &next), dispatched through the exe's own tables (0x61cb18 / 0x61cb3c, token + 4): -4 returns 0; -3 and 7 / 39 white space (-3 sets next = enc[0x44] + ptr first):
// appends 0x20, except when !isCdata and buf is empty or already ends with 0x20; -1: [0x118] = ptr, 4; 0: [0x118] = next, 4; 6: 0x620180(buf, enc, ptr, next) (0 returns 1); 9 (entity or
// character reference): al = enc[0x30](enc, ptr + m, next - m) appended when non-zero, else the name is collected into buf2 = parser + 0x244 with 0x620180 and a 0 byte, looked up with
// 0x61fd60(parser + 0x158, name, 0): missing -> ignored when parser[0x1c0] == 0 else 0xb; busy flag [+0x1c] -> 0xc; [+0x18] -> 0xf; no text [+4] -> 0x10; otherwise the text is processed
// recursively with enc = parser[0xe0]; 10: r = enc[0x2c](enc, ptr) (negative -> 0xe), 0x20 is squeezed when !isCdata, 0x626e10(r, bytes) gives n bytes appended (0 -> 0xe); any other token: 0x17.
extern "C" u32 GUESS_61c790(u32 parser, u32 enc, u32 isCdata, u32 ptr, u32 end, u32 buf) {
  u32 next = 0, edi = ptr;
  s32 tok = ((WBTok)*(u32 *)(enc + 0x10))(enc, edi, end, (u32)&next);
  u32 ev = (u32)tok + 4;
  for (;;) {
    if (ev > 0x2b) break;
    u32 h = *(u32 *)(0x61cb18 + *(u8 *)(0x61cb3c + ev) * 4);
    switch (h) {
      case 0x61cad0: return 0;
      case 0x61c881: next = *(u32 *)(enc + 0x44) + edi; goto nl;
      case 0x61c88c: goto nl;
      case 0x61caf9: return w9fail(parser, enc, edi, 4);
      case 0x61cad9: return w9fail(parser, enc, next, 4);
      case 0x61c85c:
        if (!ext_620180_wb(buf, enc, edi, next)) return 1;
        goto cont;
      case 0x61c8cd: {
        u32 m = *(u32 *)(enc + 0x44);
        u8 al = (u8)((WK3) * (u32 *)(enc + 0x30))(enc, m + edi, next - m);
        if (al) {
          if (!w9put(buf, al)) return 1;
          goto cont;
        }
        u32 buf2 = parser + 0x244;
        if (!ext_620180_wb(buf2, enc, m + edi, next - m)) return 1;
        if (*(u32 *)(parser + 0x250) == *(u32 *)(buf2 + 8)) {
          if (!ext_6206e0_wb(buf2)) return 1;
        }
        *(u8 *)*(u32 *)(buf2 + 0xc) = 0;
        *(u32 *)(buf2 + 0xc) += 1;
        u32 nm = *(u32 *)(buf2 + 0x10);
        if (nm == 0) return 1;
        u32 ent = ext_61fd60_wb(parser + 0x158, nm, 0);
        *(u32 *)(parser + 0x250) = *(u32 *)(parser + 0x254);
        if (ent == 0) {
          if (*(u32 *)(parser + 0x1c0) == 0) goto cont;
          return w9fail(parser, enc, edi, 0xb);
        }
        if (*(u8 *)(ent + 0x1c) != 0) return w9fail(parser, enc, edi, 0xc);
        if (*(u32 *)(ent + 0x18) != 0) return w9fail(parser, enc, edi, 0xf);
        u32 start = *(u32 *)(ent + 4);
        if (start == 0) return w9fail(parser, enc, edi, 0x10);
        *(u8 *)(ent + 0x1c) = 1;
        u32 rr = GUESS_61c790(parser, *(u32 *)(parser + 0xe0), isCdata, start, *(u32 *)(ent + 8) + start, buf);
        *(u8 *)(ent + 0x1c) = 0;
        if (rr != 0) return rr;
        goto cont;
      }
      case 0x61c7d0: {
        s32 r = ((WBVs2) * (u32 *)(enc + 0x2c))(enc, edi);
        if (r < 0) return w9fail(parser, enc, edi, 0xe);
        if (isCdata == 0 && r == 0x20) {
          u32 cur = *(u32 *)(buf + 0xc);
          if (cur - *(u32 *)(buf + 0x10) == 0) goto cont;
          if (*(u8 *)(cur - 1) == (u8)r) goto cont;
        }
        u8 loc[8];
        s32 n = ext_626e10_wb(r, (u32)loc);
        if (n == 0) return w9fail(parser, enc, edi, 0xe);
        for (s32 i = 0; i < n; i++)
          if (!w9put(buf, loc[i])) return 1;
        goto cont;
      }
      default: goto dflt;
    }
  nl:
    if (isCdata == 0) {
      u32 cur = *(u32 *)(buf + 0xc);
      if (cur - *(u32 *)(buf + 0x10) == 0) goto cont;
      if (*(u8 *)(cur - 1) == 0x20) goto cont;
    }
    if (!w9put(buf, 0x20)) return 1;
  cont:
    edi = next;
    tok = ((WBTok)*(u32 *)(enc + 0x10))(enc, edi, end, (u32)&next);
    ev = (u32)tok + 4;
  }
dflt:
  return w9fail(parser, enc, edi, 0x17);
}
PCREG(61c790, GUESS_61c790);

// ---------------------------------------------------------------- 0x61a060
extern "C" void FASTCALL ext_4de440_wk(u32, u32, u32) __asm__("ext_4de440");
extern "C" void FASTCALL ext_441970_wk(u32, u32, u32) __asm__("ext_441970");
extern "C" void FASTCALL ext_443ef0_wk(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" void THISCALL ext_610070_wk(u32, u32) __asm__("ext_610070");
extern "C" void THISCALL ext_6107e0_wk(u32, u32) __asm__("ext_6107e0");
extern "C" void FASTCALL ext_61a6b0_wk(u32, u32) __asm__("ext_61a6b0");
typedef u32(THISCALL *WKA9)(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);

// 0x61a060: thiscall(A, R) ret 8, void (/GS cookie not reproduced). Nothing when this[0xc] == 0 or X = this[4] + 0xc has X[8] == 0. Debug line 0x259 (text 0x6bde94, slot 0x178) and at the end line 0x260
// (slot 0x17c; skipped when the frustum test culls... no: the culled path still ends with it, only the early exits above skip it). S = this[4][4][8]; R vslot 0x29c(S[0x20], S[0x38], S[0x44]); T = A[0xc]
// or D[0xc] or D[8] + 8 (D = A[0x14], later non-zero entries win) is the transform. When neither A[5] nor D[5] has bit 4: M (3x3) = 0x4de440(T, D20 + 0x10), v = 0x441970(T + 0x24, D20 + 0x10) +
// (D20 + 0x34) (0x441940), D20 = D[0x20]; with P = S[0x10] + G[0x1aa3][0x20] and when [0x680a60] > P[0x10]: two plane tests with dots of (0x441970(P + 0x10 or 0x20, M) and 0x443ef0(v, ..., -P[0x1c] or
// -P[0x2c])); the second plane test culls (-> end) when its dot is > 0, the first only gates it. Draw setup: 0x610070(R, S[0x54]), R vslot 0x28c(M, v, S[0x58]) (or (T, T + 0x24, S[0x58]) when bit 4);
// 0x6107e0(R, A[0x28]); state 0x89 reset when R[0x115f] & 2 and [0x724948]; caches 0x7249f8, 0x724970 / 0x7249b0 (V = R[0x13fa] released through vslot 8 when [+0x30]) and 0x7249f0 / 0x7249f4
// (Q = R[0x140a], vslot 8 when [+0x18]); 0x61a6b0(this[8], X); then by flags S[0x20]: both 0x1100: R vslot 0x29c(f & 0x80000 | 0x40002, 0, 0), vslot 0x2ac(1, S60, S68, S64, S6c, S70, S74, 0, 0),
// 0x61a6b0, vslot 0x2ac(0 x 9); only 0x1000: vslot 0x29c, vslot 0x2a8(1, S60, S64, 0), 0x61a6b0, vslot 0x2a8(0 x 4); neither: end. Then R vslot 0x2a0(S[4], 0, 1) and 0x29c(0, 0, 0).
extern "C" void THISCALL GUESS_61a060(u32 self, u32 A, u32 R) {
  u32 G = *(u32 *)0x70039c;
  if (*(u32 *)(self + 0xc) == 0) return;
  u32 X = *(u32 *)(self + 4) + 0xc;
  if (*(u32 *)(X + 8) == 0) return;
  w6dbg(G, 0x259, 0x178, 0x6bde94);
  u32 K20 = *(u32 *)(w6ld(*(u32 *)0x70039c + 0x1aa3) + 0x20);
  u32 S = *(u32 *)(*(u32 *)(*(u32 *)(self + 4) + 4) + 8);
  ((W6T3)*(u32 *)(*(u32 *)R + 0x29c))(R, *(u32 *)(S + 0x20), *(u32 *)(S + 0x38), *(u32 *)(S + 0x44));
  u32 f58 = *(u32 *)(S + 0x58);
  u32 f54 = *(u32 *)(S + 0x54);
  u32 D = *(u32 *)(A + 0x14);
  u32 A28 = *(u32 *)(A + 0x28);
  u32 D20 = *(u32 *)(D + 0x20);
  u32 T = *(u32 *)(D + 8) + 8;
  if (*(u32 *)(D + 0xc) != 0) T = *(u32 *)(D + 0xc);
  if (*(u32 *)(A + 0xc) != 0) T = *(u32 *)(A + 0xc);
  u32 M[12];
  if (!(*(u8 *)(A + 5) & 4) && !(*(u8 *)(D + 5) & 4)) {
    ext_4de440_wk((u32)M, T, D20 + 0x10);
    ext_441970_wk((u32)&M[9], T + 0x24, D20 + 0x10);
    ext_441940_w6((u32)&M[9], D20 + 0x34);
    u32 P = *(u32 *)(S + 0x10) + K20;
    if (*(float *)0x680a60 > bitsf(*(u32 *)(P + 0x10))) {
      u32 W6[3], W5[3];
      ext_441970_wk((u32)W6, P + 0x10, (u32)M);
      ext_443ef0_wk((u32)W5, (u32)&M[9], (u32)W6, *(u32 *)(P + 0x1c) ^ *(u32 *)0x67af40);
      float d1 = (bitsf(W5[0]) * bitsf(W6[0]) + bitsf(W5[1]) * bitsf(W6[1])) + bitsf(W5[2]) * bitsf(W6[2]);
      if (d1 > 0.0f) {
        ext_441970_wk((u32)W6, P + 0x20, (u32)M);
        ext_443ef0_wk((u32)W5, (u32)&M[9], (u32)W6, *(u32 *)(P + 0x2c) ^ *(u32 *)0x67af40);
        float d2 = (bitsf(W5[0]) * bitsf(W6[0]) + bitsf(W5[1]) * bitsf(W6[1])) + bitsf(W5[2]) * bitsf(W6[2]);
        if (d2 > 0.0f) goto fin;
      }
    }
    ext_610070_wk(R, f54);
    ((W6T3)*(u32 *)(*(u32 *)R + 0x28c))(R, (u32)M, (u32)&M[9], f58);
  } else {
    ext_610070_wk(R, f54);
    ((W6T3)*(u32 *)(*(u32 *)R + 0x28c))(R, T, T + 0x24, f58);
  }
  ext_6107e0_wk(R, A28);
  if ((*(u8 *)(R + 0x115f) & 2) && *(u32 *)0x724948 != 0) {
    u32 d = *(u32 *)0x724a00;
    *(u32 *)0x724948 = 0;
    w6rs(d, 0x89, 0);
  }
  {
    u32 Q = w6ld(R + 0x140a);
    u32 V = w6ld(R + 0x13fa);
    if (*(u32 *)0x7249f8 != 0x152) {
      u32 d = *(u32 *)0x724a00;
      *(u32 *)0x7249f8 = 0x152;
      ((W6S2)*(u32 *)(*(u32 *)d + 0x130))(d, 0x152);
    }
    if (*(u32 *)(V + 0x30) != 0) {
      ((W6B)*(u32 *)(*(u32 *)V + 8))(V);
      *(u32 *)(V + 0x30) = 0;
    }
    u32 ed = *(u32 *)(V + 0x2c);
    if (*(u32 *)0x724970 != ed || *(u32 *)0x7249b0 != 0x24) {
      u32 d = *(u32 *)0x724a00;
      *(u32 *)0x724970 = ed;
      *(u32 *)0x7249b0 = 0x24;
      ((W6S4)*(u32 *)(*(u32 *)d + 0x14c))(d, 0, ed, 0x24);
    }
    u32 s0c = *(u32 *)(self + 0xc);
    if (*(u32 *)(Q + 0x18) != 0) {
      ((W6B)*(u32 *)(*(u32 *)Q + 8))(Q);
      *(u32 *)(Q + 0x18) = 0;
    }
    u32 qe = *(u32 *)(Q + 0x14);
    if (*(u32 *)0x7249f0 != qe || *(u32 *)0x7249f4 != s0c) {
      *(u32 *)0x7249f4 = s0c;
      u32 d = *(u32 *)0x724a00;
      *(u32 *)0x7249f0 = qe;
      ((W6S3)*(u32 *)(*(u32 *)d + 0x154))(d, qe, s0c);
    }
  }
  ext_61a6b0_wk(*(u32 *)(self + 8), X);
  {
    u32 fl = *(u32 *)(S + 0x20);
    if ((fl & 0x1100) == 0x1100) {
      ((W6T3)*(u32 *)(*(u32 *)R + 0x29c))(R, (fl & 0x80000) | 0x40002, 0, 0);
      ((WKA9)*(u32 *)(*(u32 *)R + 0x2ac))(R, 1, *(u32 *)(S + 0x60), *(u32 *)(S + 0x68), *(u32 *)(S + 0x64), *(u32 *)(S + 0x6c), *(u32 *)(S + 0x70), *(u32 *)(S + 0x74), 0, 0);
      ext_61a6b0_wk(*(u32 *)(self + 8), X);
      ((WKA9)*(u32 *)(*(u32 *)R + 0x2ac))(R, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    } else if (fl & 0x1000) {
      ((W6T3)*(u32 *)(*(u32 *)R + 0x29c))(R, (fl & 0x80000) | 0x40002, 0, 0);
      ((W6T4)*(u32 *)(*(u32 *)R + 0x2a8))(R, 1, *(u32 *)(S + 0x60), *(u32 *)(S + 0x64), 0);
      ext_61a6b0_wk(*(u32 *)(self + 8), X);
      ((W6T4)*(u32 *)(*(u32 *)R + 0x2a8))(R, 0, 0, 0, 0);
    } else {
      goto fin;
    }
  }
  ((W6T3)*(u32 *)(*(u32 *)R + 0x2a0))(R, *(u16 *)(S + 4), 0, 1);
  ((W6T3)*(u32 *)(*(u32 *)R + 0x29c))(R, 0, 0, 0);
fin:
  w6dbg(*(u32 *)0x70039c, 0x260, 0x17c, 0x6bde94);
}
PCREG(61a060, GUESS_61a060);

// ---------------------------------------------------------------- 0x401f20
extern "C" void *ext_634d28_wm(void *, const void *, u32) __asm__("ext_634d28");
extern "C" u32 ext_634dee_wm(u32, u32) __asm__("ext_634dee");

// 0x401f20: cdecl(v, vb) returns 0 or -1: libvorbis vorbis_synthesis_blockin (overlap add of a decoded block into the DSP state). v: [+4] vi (channels at vi[4], codec setup ci = vi[0x1c] with
// blocksizes ci[0] / ci[4]), [+8] pcm channel pointer array, [+0x10] pcm_storage, [+0x14] pcm_current, [+0x18] pcm_returned, [+0x20] eofflag, [+0x24] lW, [+0x28] W, [+0x2c] nW, [+0x30] centerW,
// [+0x38] granulepos (64 bit), [+0x40] sequence (64 bit), [+0x48 .. 0x64] four 64 bit bit counters; vb: [0] pcm array, [+0x1c] W, [+0x2c] eofflag, [+0x30] granulepos, [+0x38] sequence, [+0x58 ..
// 0x64] four bit counters. Steps: when centerW > bs1 / 2 and pcm_returned > 0x2000 the buffers are shifted down (memmove CRT 0x634d28) by min(centerW - bs1 / 2, pcm_returned); lW = W, nW = -1, W = vb.W; the
// counters are added (sign extended); a sequence that does not follow resets granulepos to -1; begin / end window positions from bs[lW] / 4 + bs[W] / 4 and the storage is grown with realloc (CRT
// 0x634dee) to end + bs1 when end > pcm_storage; W other than 0 / 1 returns -1; the window overlaps are added (float add) and copied; pcm_returned = -1 is set to the new center; granulepos is
// advanced / limited against the block's granulepos, centerW = new center, pcm_current = end, eofflag.
extern "C" s32 GUESS_401f20(u32 v, u32 vb) {
  u32 vi = *(u32 *)(v + 4);
  u32 ci = *(u32 *)(vi + 0x1c);
  s32 half = *(s32 *)(ci + 4) / 2;
  s32 centerW = *(s32 *)(v + 0x30);
  s32 edi = 0;
  if (centerW > half && *(s32 *)(v + 0x18) > 0x2000) {
    s32 ret = *(s32 *)(v + 0x18);
    edi = centerW - half;
    if (ret < edi) edi = ret;
    *(s32 *)(v + 0x14) -= edi;
    *(s32 *)(v + 0x30) -= edi;
    *(s32 *)(v + 0x18) -= edi;
    if (edi != 0) {
      for (s32 j = 0; j < *(s32 *)(vi + 4); j++) {
        u32 p = *(u32 *)(*(u32 *)(v + 8) + j * 4);
        ext_634d28_wm((void *)p, (void *)(p + edi * 4), (u32)(*(s32 *)(v + 0x14) << 2));
      }
    }
  }
  *(u32 *)(v + 0x24) = *(u32 *)(v + 0x28);
  *(u32 *)(v + 0x2c) = 0xffffffff;
  *(u32 *)(v + 0x28) = *(u32 *)(vb + 0x1c);
  {
    static const u32 off[4] = {0x48, 0x50, 0x58, 0x60};
    for (int q = 0; q < 4; q++) {
      s32 add = *(s32 *)(vb + 0x58 + 4 * q);
      u64 cur = (u64) * (u32 *)(v + off[q]) | ((u64) * (u32 *)(v + off[q] + 4) << 32);
      cur += (u64)(long long)add;
      *(u32 *)(v + off[q]) = (u32)cur;
      *(u32 *)(v + off[q] + 4) = (u32)(cur >> 32);
    }
  }
  {
    u64 seq = (u64) * (u32 *)(v + 0x40) | ((u64) * (u32 *)(v + 0x44) << 32);
    seq += 1;
    u64 vseq = (u64) * (u32 *)(vb + 0x38) | ((u64) * (u32 *)(vb + 0x3c) << 32);
    if (seq != vseq) {
      *(u32 *)(v + 0x38) = 0xffffffff;
      *(u32 *)(v + 0x3c) = 0xffffffff;
    }
    *(u32 *)(v + 0x40) = *(u32 *)(vb + 0x38);
    *(u32 *)(v + 0x44) = *(u32 *)(vb + 0x3c);
  }
  s32 W = *(s32 *)(v + 0x28), lW = *(s32 *)(v + 0x24);
  s32 bsW = *(s32 *)(ci + W * 4);
  s32 bsl = *(s32 *)(ci + lW * 4);
  s32 newc = bsl / 4 + bsW / 4 + *(s32 *)(v + 0x30);
  s32 beginW = newc - bsW / 2;
  s32 endW = beginW + bsW;
  if (endW > *(s32 *)(v + 0x10)) {
    *(s32 *)(v + 0x10) = *(s32 *)(ci + 4) + endW;
    for (s32 j = 0; j < *(s32 *)(vi + 4); j++) {
      u32 pa = *(u32 *)(v + 8) + j * 4;
      *(u32 *)pa = ext_634dee_wm(*(u32 *)pa, (u32)(*(s32 *)(v + 0x10) << 2));
    }
  }
  s32 start, n;
  if (*(s32 *)(v + 0x28) == 0) {
    start = 0;
    n = *(s32 *)ci / 2;
  } else if (*(s32 *)(v + 0x28) == 1) {
    s32 bl = *(s32 *)(ci + *(s32 *)(v + 0x24) * 4);
    start = *(s32 *)(ci + 4) / 4 - bl / 4;
    n = bl / 2 + start;
  } else {
    return -1;
  }
  for (s32 j = 0; j < *(s32 *)(vi + 4); j++) {
    u32 p = *(u32 *)(v + 8) + 0;
    p = *(u32 *)(*(u32 *)(v + 8) + j * 4) + (u32)(beginW * 4);
    u32 src = *(u32 *)(*(u32 *)vb + j * 4);
    s32 i = start;
    if (i < n) {
      for (; i < n; i++) {
        long double a = *(float *)(src + i * 4);
        *(float *)(p + i * 4) = (float)(a + (long double)*(float *)(p + i * 4));
      }
    }
    for (; i < bsW; i++) *(u32 *)(p + i * 4) = *(u32 *)(src + i * 4);
  }
  if (*(s32 *)(v + 0x18) == -1) *(s32 *)(v + 0x18) = newc;
  {
    u32 glo = *(u32 *)(v + 0x38), ghi = *(u32 *)(v + 0x3c);
    u32 blo = *(u32 *)(vb + 0x30), bhi = *(u32 *)(vb + 0x34);
    if ((glo & ghi) == 0xffffffff) {
      if ((blo & bhi) == 0xffffffff) {
        *(u32 *)(v + 0x38) = 0;
        *(u32 *)(v + 0x3c) = 0;
      } else {
        *(u32 *)(v + 0x38) = blo;
        *(u32 *)(v + 0x3c) = bhi;
      }
    } else {
      s32 d = newc - *(s32 *)(v + 0x30);
      u64 g = ((u64)ghi << 32) | glo;
      g += (u64)(long long)d;
      *(u32 *)(v + 0x38) = (u32)g;
      *(u32 *)(v + 0x3c) = (u32)(g >> 32);
      if ((blo & bhi) != 0xffffffff) {
        glo = *(u32 *)(v + 0x38);
        ghi = *(u32 *)(v + 0x3c);
        if (!(glo == blo && ghi == bhi)) {
          bool setvb;
          if ((s32)ghi < (s32)bhi) setvb = true;
          else if ((s32)ghi > (s32)bhi) setvb = false;
          else setvb = glo <= blo;
          if (!setvb) {
            s32 diff = (s32)(glo - blo);
            if (*(u32 *)(vb + 0x2c) != 0) {
              newc -= diff;
            } else if (*(u32 *)(vb + 0x38) == 1 && *(u32 *)(vb + 0x3c) == 0) {
              s32 nr = *(s32 *)(v + 0x18) + diff;
              *(s32 *)(v + 0x18) = nr;
              if (nr > newc) *(s32 *)(v + 0x18) = newc;
            }
          }
          *(u32 *)(v + 0x38) = blo;
          *(u32 *)(v + 0x3c) = bhi;
        }
      }
    }
  }
  *(s32 *)(v + 0x30) = newc;
  *(s32 *)(v + 0x14) = endW;
  if (*(u32 *)(vb + 0x2c) != 0) *(u32 *)(v + 0x20) = 1;
  return 0;
}
PCREG(401f20, GUESS_401f20);

// 0x659c40: thiscall(this) void. C = this + 0x1c8 is a container with vslots 4 (non-empty?), 0xc (begin: fills a 3-dword
// iterator {cur, idx, node}), 0x10 (skip: advances cur in place). Items are walked as blocks {count, ?, next, ?, items at +0x10}.
// Pass 1: for each item with flag [item+5] & 1: per-item setup via 0x658d30 / 0x658d00, item[0x38][0x54] vslot 0x24c / 0x2c0,
// 0x63eb90 (float stored at +0x271 of the 0x24c result), the global [0x70039c][0x1aa3][0x18] vslot 0xc8, then 0x646430 / 0x645c30 / 0x647870.
// Pass 2: items whose 0x24c result passes 0x646040: global vslots 0xc4 / 0xbc, 0x658d30 / 0x658d80 and (when [obj+0x11] != 1)
// a loop over [obj+0x11]-1 pairs calling 0x4df1e0 / 0x4de480 / 0x4419f0 / 0x441940.
// Pass 3: per item 0x647790 and 6 unaligned dword copies from the [0x54] object, then this vslot 0xc4(item). End: this vslot 0x10.
extern "C" u32 THISCALL ext_658d30_wq(u32) __asm__("ext_658d30");
extern "C" u32 THISCALL ext_658d00_wq(u32) __asm__("ext_658d00");
extern "C" u32 THISCALL ext_658d80_wq(u32) __asm__("ext_658d80");
extern "C" float THISCALL ext_63eb90_wq(u32, u32) __asm__("ext_63eb90");
extern "C" u32 THISCALL ext_646430_wq(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_646430");
extern "C" u32 THISCALL ext_645c30_wq(u32, u32, u32, u32, u32) __asm__("ext_645c30");
extern "C" u32 THISCALL ext_647870_wq(u32, u32, u32, u32) __asm__("ext_647870");
extern "C" u32 THISCALL ext_647790_wq(u32, u32, u32, u32) __asm__("ext_647790");
extern "C" u8 THISCALL ext_646040_wq(u32) __asm__("ext_646040");
extern "C" void FASTCALL ext_4df1e0_wq(u32, u32) __asm__("ext_4df1e0");
extern "C" void FASTCALL ext_4de480_wq(u32, u32) __asm__("ext_4de480");
extern "C" void FASTCALL ext_4419f0_wq(u32, u32) __asm__("ext_4419f0");
extern "C" void FASTCALL ext_441940_wq(u32, u32) __asm__("ext_441940");
typedef u32(THISCALL *Q0)(u32);
typedef void(THISCALL *Q0v)(u32);
typedef u32 *(THISCALL *Q1p)(u32, u32 *);
typedef void(THISCALL *Q1v)(u32, u32 *);
typedef u32(THISCALL *Q1)(u32, u32);
static inline u32 qvt(u32 o, u32 off) { return w6ld(w6ld(o) + off); }
extern "C" void THISCALL GUESS_659c40(u32 self) {
  u32 C = self + 0x1c8;
  if (((Q0)qvt(C, 4))(C) != 0) {
    u32 tmp[3];
    u32 cur, idx, node;
    auto begin = [&]() {
      u32 *r = ((Q1p)qvt(C, 0xc))(C, tmp);
      cur = r[0];
      idx = r[1];
      node = r[2];
    };
    auto advance = [&]() {
      idx++;
      if (idx == w6ld(node)) {
        node = w6ld(node + 8);
        if (node == 0) {
          cur = 0;
        } else {
          idx = 0;
          cur = node + 0x10;
        }
      } else {
        cur += 4;
      }
    };
    u8 loc[0xae0] __attribute__((aligned(4)));
    begin();
    while (cur != 0) {
      u32 item = w6ld(cur);
      if (!(*(u8 *)(item + 5) & 1)) {
        ((Q1v)qvt(C, 0x10))(C, &cur);
        continue;
      }
      u32 b04 = ext_658d30_wq(item);
      u32 t = w6ld(item + 0x38);
      u32 af4 = w6ld(t + 0x54);
      u32 af8 = w6ld(t + 0x6c);
      u32 b0c = ((Q0)qvt(af4, 0x24c))(af4);
      float f = ext_63eb90_wq(self, *(u16 *)(w6ld(item + 0x38) + 0x5a));
      w6st(b0c + 0x271, fbits(f));
      u32 ebx = ((Q0)qvt(af4, 0x2c0))(af4);
      u32 g = w6ld(w6ld(w6ld(0x70039c) + 0x1aa3) + 0x18);
      u32 esi = ((Q1)qvt(g, 0xc8))(g, af8);
      u32 edi = ext_658d00_wq(item);
      ext_646430_wq(b0c, ebx, esi, edi, (u32)loc, af4, b04);
      ext_645c30_wq(b0c, ebx, b04, edi, (u32)loc);
      ext_647870_wq(b0c, b04, af8, af4);
      advance();
    }
    begin();
    while (cur != 0) {
      u32 item = w6ld(cur);
      u32 b04 = ((Q0)qvt(w6ld(w6ld(item + 0x38) + 0x54), 0x24c))(w6ld(w6ld(item + 0x38) + 0x54));
      if (ext_646040_wq(b04) & 0xff) {
        u32 esi = w6ld(w6ld(item + 0x38) + 0x6c);
        u32 g = w6ld(w6ld(w6ld(0x70039c) + 0x1aa3) + 0x18);
        u32 b0c = ((Q1)qvt(g, 0xc4))(g, esi);
        g = w6ld(w6ld(w6ld(0x70039c) + 0x1aa3) + 0x18);
        ((Q1)qvt(g, 0xbc))(g, esi);
        u32 b00 = ext_658d30_wq(item);
        ext_658d80_wq(item);
        if (w6ld(b04 + 0x11) != 1) {
          u32 p = b0c + 0xc;
          u32 ebx = b00;
          u32 k = 1;
          do {
            p += 0x30;
            ebx += 0x30;
            u32 e = w6ld(p) * 0x30 + b00;
            ext_4df1e0_wq(ebx, ebx);
            ext_4de480_wq(ebx, e);
            ext_4419f0_wq(ebx + 0x24, e);
            ext_441940_wq(ebx + 0x24, e + 0x24);
            k++;
          } while (k != w6ld(b04 + 0x11));
        }
      }
      advance();
    }
    begin();
    while (cur != 0) {
      u32 item = w6ld(cur);
      u32 t = w6ld(item + 0x38);
      u32 esi = w6ld(t + 0x54);
      u32 edi = ((Q0)qvt(esi, 0x24c))(esi);
      u32 r658 = ext_658d30_wq(item);
      ext_647790_wq(edi, r658, w6ld(w6ld(item + 0x38) + 0x6c), esi);
      u32 s8 = w6ld(esi + 8);
      w6st(edi + 0x281, w6ld(s8 + 0x30));
      w6st(edi + 0x285, w6ld(s8 + 0x34));
      w6st(edi + 0x289, w6ld(s8 + 0x38));
      s8 = w6ld(esi + 8);
      w6st(edi + 0x275, w6ld(s8 + 0x40));
      w6st(edi + 0x279, w6ld(s8 + 0x44));
      w6st(edi + 0x27d, w6ld(s8 + 0x48));
      ((Q1)qvt(self, 0xc4))(self, item);
      advance();
    }
  }
  ((Q0v)qvt(self, 0x10))(self);
}
PCREG(659c40, GUESS_659c40);

// 0x4d6520: thiscall(path, out, outPtr) ret 0xc, returns al (/GS cookie not reproduced; three 0x10004-byte stack buffers A, B, C). Looks up an archive
// entry by name: A = path with '\\' turned into '/'; pat = strchr(path, '*') (IAT 0x676254). Without pattern, with this[0x6a] != 0 and outPtr == 0: M vslot 8(A, out, &loc)
// (al) answers directly: false -> 0, true -> file F = this[0x15] vslot 0x10(this[0x11], loc, 0), return 1. Otherwise seeks as 0x4d6c60 (this[0x3c] ? this[0x40] : this[0x2e]) and scans the
// central directory (vslots 0x1c eof, 0x14 read, 0xc tell): 0x02014b50 = entry (header 0x2a bytes; name length word +0x18 read into B; skipped when its position is in
// the list this[0x66][0..this[0x62]); with pattern 0x4cc850(B, A) == 0 matches, without pattern strlen(A) == name length and strcmp (IAT 0x676414) == 0 match; a match
// copies header bytes +2..+0x1c (26 bytes) to out and sets the flag); extra (word +0x1a) and comment (word +0x1c) are read into C; a matched entry stores its position
// in *outPtr, seeks to dword(+0x26) + name length + 0x1e and calls M vslot 4(A, out, tell) when M != 0, returns 1. 0x06054b50 / 0x52756e65 end with 0; other signatures log
// through [0x700390] vslot 0x20(0x696924, 0x2b5) / its result vslot 0x2c(0x6969dc) and the fatal pointer. Short reads call the fatal pointer.
typedef int (*W6strcmp)(const char *, const char *);
extern "C" u32 FASTCALL ext_4cc850_wr(u32, u32) __asm__("ext_4cc850");
extern "C" u32 THISCALL GUESS_4d6520(u32 self, u32 path, u32 out, u32 outPtr) {
  u8 A[0x10004] __attribute__((aligned(16)));
  u8 B[0x10004] __attribute__((aligned(16)));
  u8 C[0x10004] __attribute__((aligned(16)));
  u32 n = 0;
  while (*(u8 *)(path + n) != 0) {
    u8 ch = *(u8 *)(path + n);
    A[n] = (ch == 0x5c) ? 0x2f : ch;
    n++;
  }
  A[n] = 0;
  char *pat = (*(W6strchr *)0x676254)((const char *)path, 0x2a);
  u32 M = w6ld(self + 0x6a);
  if (pat == 0 && M != 0 && outPtr == 0) {
    u32 loc = 0xffffffffu;
    u8 ok = (u8)((W6T3)*(u32 *)(*(u32 *)M + 8))(M, (u32)A, out, (u32)&loc);
    if (!ok) return 0;
    u32 F = w6ld(self + 0x15);
    ((W6T3)*(u32 *)(*(u32 *)F + 0x10))(F, w6ld(self + 0x11), loc, 0);
    return 1;
  }
  u32 F = w6ld(self + 0x15);
  u32 pos0 = (*(u32 *)(self + 0x3c) == 0) ? w6ld(self + 0x2e) : w6ld(self + 0x40);
  ((W6T3)*(u32 *)(*(u32 *)F + 0x10))(F, w6ld(self + 0x11), pos0, 0);
  F = w6ld(self + 0x15);
  if (((W6T1)*(u32 *)(*(u32 *)F + 0x1c))(F, w6ld(self + 0x11)) != 0) return 0;
  for (;;) {
    u32 sig = 0;
    F = w6ld(self + 0x15);
    w6read(F, (u32)&sig, 4, w6ld(self + 0x11));
    if (sig == 0x2014b50) {
      u8 hdr[0x2a];
      u8 found = 0;
      F = w6ld(self + 0x15);
      u32 esi = ((W6T1)*(u32 *)(*(u32 *)F + 0xc))(F, w6ld(self + 0x11));
      F = w6ld(self + 0x15);
      w6read(F, (u32)hdr, 0x2a, w6ld(self + 0x11));
      u16 nameLen = *(u16 *)(hdr + 0x18);
      if (nameLen != 0) {
        F = w6ld(self + 0x15);
        w6read(F, (u32)B, nameLen, w6ld(self + 0x11));
        B[nameLen] = 0;
        bool skip = false;
        u32 cnt = w6ld(self + 0x62);
        if (cnt != 0) {
          u32 arr = w6ld(self + 0x66);
          u32 i = 0;
          do {
            if (esi == *(u32 *)(arr + i * 4)) { skip = true; break; }
            i++;
          } while (i < cnt);
        }
        if (!skip) {
          bool copy;
          if (pat != 0) {
            copy = ext_4cc850_wr((u32)B, (u32)A) == 0;
          } else {
            u32 len = 0;
            while (A[len] != 0) len++;
            if (len != nameLen) copy = false;
            else copy = (*(W6strcmp *)0x676414)((const char *)B, (const char *)A) == 0;
          }
          if (copy) {
            __builtin_memcpy((void *)out, hdr + 2, 26);
            found = 1;
          }
        }
      }
      u16 extraLen = *(u16 *)(hdr + 0x1a);
      if (extraLen != 0) {
        F = w6ld(self + 0x15);
        w6read(F, (u32)C, extraLen, w6ld(self + 0x11));
      }
      u16 commentLen = *(u16 *)(hdr + 0x1c);
      if (commentLen != 0) {
        F = w6ld(self + 0x15);
        w6read(F, (u32)C, commentLen, w6ld(self + 0x11));
      }
      if (found) {
        if (outPtr != 0) w6st(outPtr, esi);
        u32 off;
        __builtin_memcpy(&off, hdr + 0x26, 4);
        F = w6ld(self + 0x15);
        ((W6T3)*(u32 *)(*(u32 *)F + 0x10))(F, w6ld(self + 0x11), off + nameLen + 0x1e, 0);
        u32 M2 = w6ld(self + 0x6a);
        if (M2 != 0) {
          F = w6ld(self + 0x15);
          u32 tell = ((W6T1)*(u32 *)(*(u32 *)F + 0xc))(F, w6ld(self + 0x11));
          ((W6T3)*(u32 *)(*(u32 *)M2 + 4))(M2, (u32)A, out, tell);
        }
        return 1;
      }
    } else if (sig == 0x6054b50 || sig == 0x52756e65) {
      return 0;
    } else {
      u32 lg = *(u32 *)0x700390;
      u32 x = ((W6T2b)*(u32 *)(*(u32 *)lg + 0x20))(lg, 0x696924, 0x2b5);
      ((u32(*)(u32, u32))*(u32 *)(*(u32 *)x + 0x2c))(x, 0x6969dc);
      w6fatal2();
    }
    F = w6ld(self + 0x15);
    if (((W6T1)*(u32 *)(*(u32 *)F + 0x1c))(F, w6ld(self + 0x11)) != 0) return 0;
  }
}
PCREG(4d6520, GUESS_4d6520);

// 0x619770: thiscall(A, R) ret 8, void (/GS cookie not reproduced). Sibling of 0x61a060 without the debug lines. Nothing when this[0xc] == 0, X = this[4] + 0xc has X[8] == 0 or S[0x20] & 0x800000
// (S = this[4][4][8]). R vslot 0x29c(S[0x20], S[0x38], S[0x44]); 0x6107e0(R, A[0x28]); T / M / v / frustum tests exactly as in 0x61a060 (draw through 0x610070(R, S[0x54]) and R vslot 0x28c(M, v, S[0x58])
// or (T, T + 0x24, S[0x58])); 0x6107e0(R, A[0x28]) again; 0x61aaf0(0) when R[0x115f] & 2; cache [0x7249f8] against [0x724b30] (device vslot 0x130), V = R[0x13fa] / V2 = R[0x13fe]
// released through vslot 8 when [+0x30] and registered with 0x61ab20(0, V[0x2c], 0x24) / 0x61ab20(1, V2[0x2c], 4); Q = R[0x140a] and 0x7249f0 / 0x7249f4 as in 0x61a060; 0x61a6b0(this[8], X); then the flag
// dependent draw state calls (both 0x1100: vslots 0x29c, 0x2ac, 0x2ac; only 0x1000: 0x29c, 0x2a8, 0x2a8; neither: end) and R vslot 0x2a0(S[4], 0, 1), 0x29c(0, 0, 0).
extern "C" void FASTCALL ext_61aaf0_wk(u32) __asm__("ext_61aaf0");
extern "C" void FASTCALL ext_61ab20_wk(u32, u32, u32) __asm__("ext_61ab20");
extern "C" void THISCALL GUESS_619770(u32 self, u32 A, u32 R) { /*q1*/
  if (*(u32 *)(self + 0xc) == 0) return; /*q2*/
  u32 X = *(u32 *)(self + 4) + 0xc; /*q3*/
  if (*(u32 *)(X + 8) == 0) return; /*q4*/
  u32 K20 = *(u32 *)(w6ld(*(u32 *)0x70039c + 0x1aa3) + 0x20); /*q5*/
  u32 S = *(u32 *)(*(u32 *)(*(u32 *)(self + 4) + 4) + 8); /*q6*/
  if (*(u32 *)(S + 0x20) & 0x800000) return; /*q7*/
  ((W6T3)*(u32 *)(*(u32 *)R + 0x29c))(R, *(u32 *)(S + 0x20), *(u32 *)(S + 0x38), *(u32 *)(S + 0x44)); /*q8*/
  u32 f58 = *(u32 *)(S + 0x58); /*q9*/
  u32 f54 = *(u32 *)(S + 0x54); /*q10*/
  u32 A28 = *(u32 *)(A + 0x28); /*q11*/
  ext_6107e0_wk(R, A28); /*q12*/
  u32 D = *(u32 *)(A + 0x14); /*q13*/
  u32 D20 = *(u32 *)(D + 0x20); /*q14*/
  u32 T = *(u32 *)(D + 8) + 8; /*q15*/
  if (*(u32 *)(D + 0xc) != 0) T = *(u32 *)(D + 0xc); /*q16*/
  if (*(u32 *)(A + 0xc) != 0) T = *(u32 *)(A + 0xc); /*q17*/
  u32 M[12]; /*q18*/
  if (!(*(u8 *)(A + 5) & 4) && !(*(u8 *)(D + 5) & 4)) { /*q19*/
    ext_4de440_wk((u32)M, T, D20 + 0x10); /*q20*/
    ext_441970_wk((u32)&M[9], T + 0x24, D20 + 0x10); /*q21*/
    ext_441940_w6((u32)&M[9], D20 + 0x34); /*q22*/
    u32 P = *(u32 *)(S + 0x10) + K20; /*q23*/
    if (*(float *)0x680a60 > bitsf(*(u32 *)(P + 0x10))) { /*q24*/
      u32 W6[3], W5[3]; /*q25*/
      ext_441970_wk((u32)W6, P + 0x10, (u32)M); /*q26*/
      ext_443ef0_wk((u32)W5, (u32)&M[9], (u32)W6, *(u32 *)(P + 0x1c) ^ *(u32 *)0x67af40); /*q27*/
      float d1 = (bitsf(W5[0]) * bitsf(W6[0]) + bitsf(W5[1]) * bitsf(W6[1])) + bitsf(W5[2]) * bitsf(W6[2]); /*q28*/
      if (d1 > 0.0f) { /*q29*/
        ext_441970_wk((u32)W6, P + 0x20, (u32)M); /*q30*/
        ext_443ef0_wk((u32)W5, (u32)&M[9], (u32)W6, *(u32 *)(P + 0x2c) ^ *(u32 *)0x67af40); /*q31*/
        float d2 = (bitsf(W5[0]) * bitsf(W6[0]) + bitsf(W5[1]) * bitsf(W6[1])) + bitsf(W5[2]) * bitsf(W6[2]); /*q32*/
        if (d2 > 0.0f) return; /*q33*/
      }
    }
    ext_610070_wk(R, f54); /*q34*/
    ((W6T3)*(u32 *)(*(u32 *)R + 0x28c))(R, (u32)M, (u32)&M[9], f58); /*q35*/
  } else { /*q36*/
    ext_610070_wk(R, f54); /*q37*/
    ((W6T3)*(u32 *)(*(u32 *)R + 0x28c))(R, T, T + 0x24, f58); /*q38*/
  }
  ext_6107e0_wk(R, A28); /*q39*/
  if (*(u8 *)(R + 0x115f) & 2) ext_61aaf0_wk(0); /*q40*/
  { /*q41*/
    u32 Q = w6ld(R + 0x140a); /*q42*/
    u32 V = w6ld(R + 0x13fa); /*q43*/
    u32 V2 = w6ld(R + 0x13fe); /*q44*/
    u32 ev = *(u32 *)0x724b30; /*q45*/
    if (*(u32 *)0x7249f8 != ev) { /*q46*/
      u32 d = *(u32 *)0x724a00; /*q47*/
      *(u32 *)0x7249f8 = ev; /*q48*/
      ((W6S2)*(u32 *)(*(u32 *)d + 0x130))(d, ev); /*q49*/
    }
    if (*(u32 *)(V + 0x30) != 0) { /*q50*/
      ((W6B)*(u32 *)(*(u32 *)V + 8))(V); /*q51*/
      *(u32 *)(V + 0x30) = 0; /*q52*/
    }
    ext_61ab20_wk(0, *(u32 *)(V + 0x2c), 0x24); /*q53*/
    if (*(u32 *)(V2 + 0x30) != 0) { /*q54*/
      ((W6B)*(u32 *)(*(u32 *)V2 + 8))(V2); /*q55*/
      *(u32 *)(V2 + 0x30) = 0; /*q56*/
    }
    ext_61ab20_wk(1, *(u32 *)(V2 + 0x2c), 4); /*q57*/
    u32 s0c = *(u32 *)(self + 0xc); /*q58*/
    if (*(u32 *)(Q + 0x18) != 0) { /*q59*/
      ((W6B)*(u32 *)(*(u32 *)Q + 8))(Q); /*q60*/
      *(u32 *)(Q + 0x18) = 0; /*q61*/
    }
    u32 qe = *(u32 *)(Q + 0x14); /*q62*/
    if (*(u32 *)0x7249f0 != qe || *(u32 *)0x7249f4 != s0c) { /*q63*/
      *(u32 *)0x7249f4 = s0c; /*q64*/
      u32 d = *(u32 *)0x724a00; /*q65*/
      *(u32 *)0x7249f0 = qe; /*q66*/
      ((W6S3)*(u32 *)(*(u32 *)d + 0x154))(d, qe, s0c); /*q67*/
    }
  }
  ext_61a6b0_wk(*(u32 *)(self + 8), X); /*q68*/
  { /*q69*/
    u32 fl = *(u32 *)(S + 0x20); /*q70*/
    if ((fl & 0x1100) == 0x1100) { /*q71*/
      ((W6T3)*(u32 *)(*(u32 *)R + 0x29c))(R, (fl & 0x80000) | 0x40002, 0, 0); /*q72*/
      ((WKA9)*(u32 *)(*(u32 *)R + 0x2ac))(R, 1, *(u32 *)(S + 0x60), *(u32 *)(S + 0x68), *(u32 *)(S + 0x64), *(u32 *)(S + 0x6c), *(u32 *)(S + 0x70), *(u32 *)(S + 0x74), 0, 0); /*q73*/
      ext_61a6b0_wk(*(u32 *)(self + 8), X); /*q74*/
      ((WKA9)*(u32 *)(*(u32 *)R + 0x2ac))(R, 0, 0, 0, 0, 0, 0, 0, 0, 0); /*q75*/
    } else if (fl & 0x1000) { /*q76*/
      ((W6T3)*(u32 *)(*(u32 *)R + 0x29c))(R, (fl & 0x80000) | 0x40002, 0, 0); /*q77*/
      ((W6T4)*(u32 *)(*(u32 *)R + 0x2a8))(R, 1, *(u32 *)(S + 0x60), *(u32 *)(S + 0x64), 0); /*q78*/
      ext_61a6b0_wk(*(u32 *)(self + 8), X); /*q79*/
      ((W6T4)*(u32 *)(*(u32 *)R + 0x2a8))(R, 0, 0, 0, 0); /*q80*/
    } else { /*q81*/
      return; /*q82*/
    }
  }
  ((W6T3)*(u32 *)(*(u32 *)R + 0x2a0))(R, *(u16 *)(S + 4), 0, 1); /*q83*/
  ((W6T3)*(u32 *)(*(u32 *)R + 0x29c))(R, 0, 0, 0); /*q84*/
}
PCREG(619770, GUESS_619770);

// 0x6359d0: thiscall(), void (own frame of 0x1b054 bytes via the 0x6336b0 stack probe, /GS cookie not reproduced). Quad / triangle submission for a bounding query.
// Part 1 (when this[0x6f] != 0): O = G[0x1aa3][0x1c] vslot 0x38(L, F, 2, this+0x29, this+0x1d, this+0x4d, 0x400000, 1, 1, 1) -> n (L = 0x800 object pointers, F = 12 floats
// D(0..2) B(3..5) A(6..8) C(9..11) in memory order). For each object e = L[i]: P = e[0x54] vslot 0x244() (12 floats) copied to A = P[0..2], B = P[3..5], C = P[6..8], D = P[9..11];
// 0x4db670(e, &A / &B / &C / &D) (transform by e's matrix chain); triangle (A, B, C) is submitted through 0x6354a0(e, &A, &B, &C) unless A == B, A == C or B == C (float compares,
// NaN is "not equal"), then triangle (C, D, A) through 0x6354a0(e, &C, &D, &A) unless C == D, C == A or D == A.
// Part 2: O vslot 0x84(&cnt, buf, 0x19000, this+0x29, this+0x1d, this+0x4d, this[0x6a], 0); this[0x8f] = 0; for each of cnt records {npts, ?, ?, ?, obj at +0x10, ?, points at +0x18}: when obj[0x54] != 0,
// this[0x70] != 0 and obj[0x54][0x10] has bit 2 at +0x18 the record is skipped; else each point is transformed (0x4419f0(pt, this+0x29), 0x441940(pt, this+0x1d)) and the npts - 2 triangles
// (p_k, p_k+1, p_k+2) of the strip are submitted with 0x6354a0(obj, p0, p1, p2) (reversed p2, p1, p0 for odd k) unless two of the points are equal. npts of 0 or 1 would loop 2^32 times.
extern "C" void THISCALL ext_4db670_wm(u32, u32) __asm__("ext_4db670");
extern "C" void THISCALL ext_6354a0_wm(u32, u32, u32, u32, u32) __asm__("ext_6354a0");
extern "C" void FASTCALL ext_4419f0_wm(u32, u32) __asm__("ext_4419f0");
extern "C" void FASTCALL ext_441940_wm2(u32, u32) __asm__("ext_441940");
typedef u32(THISCALL *WN10)(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
typedef u32(THISCALL *WN8)(u32, u32, u32, u32, u32, u32, u32, u32, u32);
static inline bool wm3eq(u32 a, u32 b) {
  return bitsf(w6ld(a)) == bitsf(w6ld(b)) && bitsf(w6ld(a + 4)) == bitsf(w6ld(b + 4)) && bitsf(w6ld(a + 8)) == bitsf(w6ld(b + 8));
}
extern "C" void THISCALL GUESS_6359d0(u32 self) { /*r1*/
  if (*(u8 *)(self + 0x6f) != 0) { /*r2*/
    u32 L[0x800]; /*r3*/
    u32 F[12]; /*r4*/
    u32 G = *(u32 *)0x70039c; /*r5*/
    u32 O = w6ld(w6ld(G + 0x1aa3) + 0x1c); /*r6*/
    u32 n = ((WN10) * (u32 *)(*(u32 *)O + 0x38))(O, (u32)L, (u32)F, 2, self + 0x29, self + 0x1d, self + 0x4d, 0x400000, 1, 1, 1); /*r7*/
    u32 D = (u32)&F[0], B = (u32)&F[3], A = (u32)&F[6], C = (u32)&F[9]; /*r8*/
    for (u32 i = 0; i != n && n != 0; i++) { /*r9*/
      u32 e = L[i]; /*r10*/
      u32 q = w6ld(e + 0x54); /*r11*/
      u32 P = ((W6B) * (u32 *)(*(u32 *)q + 0x244))(q); /*r12*/
      for (int k = 0; k < 3; k++) { /*r13*/
        F[6 + k] = w6ld(P + 4 * k); /*r14*/
        F[3 + k] = w6ld(P + 12 + 4 * k); /*r15*/
        F[9 + k] = w6ld(P + 24 + 4 * k); /*r16*/
        F[k] = w6ld(P + 36 + 4 * k); /*r17*/
      }
      ext_4db670_wm(e, A); /*r18*/
      ext_4db670_wm(e, B); /*r19*/
      ext_4db670_wm(e, C); /*r20*/
      ext_4db670_wm(e, D); /*r21*/
      if (!wm3eq(A, B)) { /*r22*/
        if (!wm3eq(A, C) && !wm3eq(B, C)) ext_6354a0_wm(self, e, A, B, C); /*r23*/
      }
      if (!wm3eq(C, D) && !wm3eq(C, A) && !wm3eq(D, A)) ext_6354a0_wm(self, e, C, D, A); /*r24*/
    }
  }
  u8 buf[0x19000] __attribute__((aligned(16))); /*r25*/
  u32 cnt = 0; /*r26*/
  { /*r27*/
    u32 G = *(u32 *)0x70039c; /*r28*/
    u32 O = w6ld(w6ld(G + 0x1aa3) + 0x1c); /*r29*/
    ((WN8) * (u32 *)(*(u32 *)O + 0x84))(O, (u32)&cnt, (u32)buf, 0x19000, self + 0x29, self + 0x1d, self + 0x4d, w6ld(self + 0x6a), 0); /*r30*/
  }
  w6st(self + 0x8f, 0); /*r31*/
  u32 rec = (u32)buf; /*r32*/
  u32 idx = 0; /*r33*/
  if (cnt != 0) { /*r34*/
    do { /*r35*/
      u32 npts = w6ld(rec); /*r36*/
      u32 obj = w6ld(rec + 0x10); /*r37*/
      u32 start = rec + 0x18; /*r38*/
      u32 q54 = w6ld(obj + 0x54); /*r39*/
      bool special = false; /*r40*/
      if (q54 != 0 && *(u8 *)(self + 0x70) != 0) { /*r41*/
        u32 q10 = w6ld(q54 + 0x10); /*r42*/
        if (q10 != 0 && (*(u8 *)(q10 + 0x18) & 2)) special = true; /*r43*/
      }
      if (special) { /*r44*/
        rec = start + npts * 12; /*r45*/
      } else {
        u32 pt = start; /*r46*/
        for (u32 c = npts; c != 0; c--) { /*r47*/
          ext_4419f0_wm(pt, self + 0x29); /*r48*/
          ext_441940_wm2(pt, self + 0x1d); /*r49*/
          pt += 12; /*r50*/
        }
        u32 nm2 = npts - 2; /*r51*/
        u32 e = start; /*r52*/
        u32 k = 0; /*r53*/
        if (nm2 != 0) { /*r54*/
          do { /*r55*/
            u32 p0 = e, p1 = e + 12, p2 = e + 24; /*r56*/
            if (!wm3eq(p0, p1) && !wm3eq(p0, p2) && !wm3eq(p1, p2)) { /*r57*/
              if (k & 1) ext_6354a0_wm(self, obj, p2, p1, p0); /*r58*/
              else ext_6354a0_wm(self, obj, p0, p1, p2); /*r59*/
            }
            k++; /*r60*/
            e += 12; /*r61*/
          } while (k != nm2); /*r62*/
        }
        rec = e + 0x18; /*r63*/
      }
      idx++; /*r64*/
    } while (idx != cnt); /*r65*/
  }
}
PCREG(6359d0, GUESS_6359d0);

// 0x61b570: thiscall(a, R, p10, p14) ret 0x10, returns al (/GS-free frame). Nothing (0) when this[0xc] == 0 or this[4][0x14] == 0. Timer helpers 0x441730 / 0x440530 (debug lines 0x259 / 0x260 on the
// texts 0x6bde70 and 0x6bde7c); aM = a[0xc], S2 = a[0x10][8]; W = R[0xb9a4]: fB1 = byte W[0x1295], fB2 = byte W[0x1296], E = W[0x13fa] (its buffer [E+0x30] is created through
// E vslot 4(0, 0) when null); src = G[0x1aa3][0x20] + S2[0x14], dst = [E+0x30] + this[0xc] * 0x24, cnt = word S2[0xe], nfr = S2[0x50]. The draw call is
// 0x65bd20 (fB2) / 0x65bcc0 (fB1) / 0x65bc60 (neither) thiscall(dst, src, n, p10, p14, S2[0x20]). nfr == 1: cnt vertices in chunks of 0x20 are passed straight through; debug line 0x260
// (slot 0x17c, text 0x6bde70) and return 0. Otherwise (returns 1): t = aM[0x48] == 0 ? 0 : (aM[0x48] - float(u32 S2[0x48])) / float(u32 S2[0x4c]) (unsigned int to double via the 0x680aa0
// table, then to float); idx = (int)t; frame A = src + idx * cnt * 0x24, frame B = src + min(idx + 1, nfr - 1) (unsigned) * cnt * 0x24; t -= (float)idx. Per chunk of at most 0x20
// vertices: debug 0x259 (slot 0x178, text 0x6bde84), vertices lerped at 0x724b78 + k * 0x24 (floats at +0 .. +0x14 and +0x1c, +0x20 as (B - A) * t + A, the packed colour at +0x18
// through 0x616e00(out + 0x18, A + 0x18, B + 0x18, t)), debug 0x260 (slot 0x17c, text 0x6bde84), draw call from 0x724b78, pointers advanced by n * 0x24. Final debug 0x260 (text 0x6bde70).
extern "C" void THISCALL ext_441730_wr(u32) __asm__("ext_441730");
extern "C" void THISCALL ext_440530_wr(u32) __asm__("ext_440530");
extern "C" void FASTCALL ext_616e00_wr(u32, u32, u32, u32) __asm__("ext_616e00");
extern "C" void THISCALL ext_65bc60_wr(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_65bc60");
extern "C" void THISCALL ext_65bcc0_wr(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_65bcc0");
extern "C" void THISCALL ext_65bd20_wr(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_65bd20");
static inline void wr_draw(u32 self, u32 dst, u32 src, u32 n, u32 p10, u32 p14, u32 s20, u8 fB1, u8 fB2) {
  if (fB2 != 0) ext_65bd20_wr(self, dst, src, n, p10, p14, s20);
  else if (fB1 != 0) ext_65bcc0_wr(self, dst, src, n, p10, p14, s20);
  else ext_65bc60_wr(self, dst, src, n, p10, p14, s20);
}
static inline void wr_lerp(u32 o, u32 a, u32 b, float t) {
  float av = bitsf(w6ld(a));
  float bv = bitsf(w6ld(b));
  float r = (bv - av) * t + av;
  w6st(o, fbits(r));
}
extern "C" u32 THISCALL GUESS_61b570(u32 self, u32 a, u32 R, u32 p10, u32 p14) { /*s1*/
  if (w6ld(self + 0xc) == 0) return 0; /*s2*/
  if (w6ld(w6ld(self + 4) + 0x14) == 0) return 0; /*s3*/
  ext_441730_wr(0x6bde70); /*s4*/
  u32 aM = w6ld(a + 0xc); /*s5*/
  u32 S2 = w6ld(w6ld(a + 0x10) + 8); /*s6*/
  u32 W = w6ld(R + 0xb9a4); /*s7*/
  u8 fB1 = *(u8 *)(W + 0x1295); /*s8*/
  u32 E = w6ld(W + 0x13fa); /*s9*/
  u8 fB2 = *(u8 *)(W + 0x1296); /*s10*/
  ext_441730_wr(0x6bde7c); /*s11*/
  if (w6ld(E + 0x30) == 0) w6st(E + 0x30, ((W6T2)*(u32 *)(*(u32 *)E + 4))(E, 0, 0)); /*s12*/
  u32 buf = w6ld(E + 0x30); /*s13*/
  ext_440530_wr(0x6bde7c); /*s14*/
  u32 G = *(u32 *)0x70039c; /*s15*/
  u32 src = w6ld(w6ld(G + 0x1aa3) + 0x20) + w6ld(S2 + 0x14); /*s16*/
  u32 dst = buf + w6ld(self + 0xc) * 0x24; /*s17*/
  u32 cnt = *(u16 *)(S2 + 0xe); /*s18*/
  u32 nfr = w6ld(S2 + 0x50); /*s19*/
  if (nfr == 1) { /*s20*/
    u32 rem = cnt; /*s21*/
    if (rem != 0) { /*s22*/
      do { /*s23*/
        u32 n = rem > 0x20 ? 0x20 : rem; /*s24*/
        rem -= n; /*s25*/
        wr_draw(self, dst, src, n, p10, p14, w6ld(S2 + 0x20), fB1, fB2); /*s26*/
        src += n * 0x24; /*s27*/
        dst += n * 0x24; /*s28*/
      } while (rem != 0); /*s29*/
    }
    w6dbg(*(u32 *)0x70039c, 0x260, 0x17c, 0x6bde70); /*s30*/
    return 0; /*s31*/
  }
  float t = 0.0f; /*s32*/
  float a48 = bitsf(w6ld(aM + 0x48)); /*s33*/
  if (!(a48 == 0.0f)) { /*s34*/
    u32 i48 = w6ld(S2 + 0x48); /*s35*/
    u32 i4c = w6ld(S2 + 0x4c); /*s36*/
    double d1 = (double)(s32)i48 + *(double *)(0x680aa0 + (i48 >> 31) * 8); /*s37*/
    t = a48; /*s38*/
    t = t - (float)d1; /*s39*/
    double d2 = (double)(s32)i4c + *(double *)(0x680aa0 + (i4c >> 31) * 8); /*s40*/
    t = t / (float)d2; /*s41*/
  }
  s32 idx = _mm_cvttss_si32(_mm_set_ss(t)); /*s42*/
  u32 e1 = nfr - 1; /*s43*/
  u32 c1 = (u32)idx + 1; /*s44*/
  u32 sel = (c1 <= e1) ? c1 : e1; /*s45*/
  float fi = (float)idx; /*s46*/
  t = t - fi; /*s47*/
  u32 fa = src + (u32)idx * cnt * 0x24; /*s48*/
  u32 fb = src + sel * cnt * 0x24; /*s49*/
  u32 rem = cnt; /*s50*/
  while (rem != 0) { /*s51*/
    u32 n = rem > 0x20 ? 0x20 : rem; /*s52*/
    rem -= n; /*s53*/
    w6dbg(G, 0x259, 0x178, 0x6bde84); /*s54*/
    for (u32 k = 0; k < n; k++) { /*s55*/
      u32 av = fa + k * 0x24, bv = fb + k * 0x24, ov = 0x724b78 + k * 0x24; /*s56*/
      wr_lerp(ov, av, bv, t); /*s57*/
      wr_lerp(ov + 4, av + 4, bv + 4, t); /*s58*/
      wr_lerp(ov + 8, av + 8, bv + 8, t); /*s59*/
      wr_lerp(ov + 0xc, av + 0xc, bv + 0xc, t); /*s60*/
      wr_lerp(ov + 0x10, av + 0x10, bv + 0x10, t); /*s61*/
      wr_lerp(ov + 0x14, av + 0x14, bv + 0x14, t); /*s62*/
      ext_616e00_wr(ov + 0x18, av + 0x18, bv + 0x18, fbits(t)); /*s63*/
      wr_lerp(ov + 0x1c, av + 0x1c, bv + 0x1c, t); /*s64*/
      wr_lerp(ov + 0x20, av + 0x20, bv + 0x20, t); /*s65*/
    }
    w6dbg(G, 0x260, 0x17c, 0x6bde84); /*s66*/
    wr_draw(self, dst, 0x724b78, n, p10, p14, w6ld(S2 + 0x20), fB1, fB2); /*s67*/
    fa += n * 0x24; /*s68*/
    fb += n * 0x24; /*s69*/
    dst += n * 0x24; /*s70*/
  }
  w6dbg(*(u32 *)0x70039c, 0x260, 0x17c, 0x6bde70); /*s71*/
  return 1; /*s72*/
}
PCREG(61b570, GUESS_61b570);

// 0x5f3430: cdecl(), void. o = [0x7003a4]; when non-null tail-jumps to o vslot 0x4c with ecx = o (thiscall, no stack arguments forwarded in the tests).
extern "C" void GUESS_5f3430() {
  u32 o = *(u32 *)0x7003a4; /*u1*/
  if (o != 0) { /*u2*/
    ((W6B)*(u32 *)(*(u32 *)o + 0x4c))(o); /*u3*/
  }
}
PCREG(5f3430, GUESS_5f3430);

// 0x406090: cdecl(book, a, b, n), returns 0 or -1 (libvorbis vorbis_book_decodev_add shape). dim = book[0]; while the running index i < n: entry = 0x405f20(book, b) (-1 returns -1); t = book[3] + dim * entry floats
// (dim * entry wraps in 32 bits); dim > 8: a[i++] += t[j] for j < dim (re-reading book[0] each step); dim in 1..8: the same through an unrolled jump table at 0x4061c0 (dim - 1 above 7, i.e. dim <= 0, adds nothing and
// would never end, so the spec keeps dim >= 1). n <= 0 returns 0 at once. The additions are x87 (float + float in extended precision, stored as float).
extern "C" s32 ext_405f20_wo(u32, u32) __asm__("ext_405f20");
static inline void wo_add(u32 ai, u32 tj) {
  float r = (float)((long double)bitsf(w6ld(tj)) + (long double)bitsf(w6ld(ai)));
  w6st(ai, fbits(r));
}
extern "C" s32 GUESS_406090(u32 book, u32 a, u32 b, s32 n) {
  s32 dim = *(s32 *)book; /*v1*/
  s32 i = 0; /*v2*/
  if (n <= 0) return 0; /*v3*/
  do { /*v4*/
    s32 e = ext_405f20_wo(book, b); /*v5*/
    if (e == -1) return -1; /*v6*/
    u32 t = w6ld(book + 0xc) + (u32)(dim * e) * 4; /*v7*/
    if (dim > 8) { /*v8*/
      for (s32 j = 0; j < *(s32 *)book; j++) { /*v9*/
        wo_add(a + (u32)i * 4, t + (u32)j * 4); /*v10*/
        i++; /*v11*/
      }
    } else { /*v12*/
      u32 cases = (u32)(dim - 1); /*v13*/
      if (cases <= 7) { /*v14*/
        for (u32 j = 0; j <= cases; j++) { /*v15*/
          wo_add(a + (u32)i * 4, t + j * 4); /*v16*/
          i++; /*v17*/
        }
      }
    }
  } while (i < n); /*v18*/
  return 0; /*v19*/
}
PCREG(406090, GUESS_406090);

// 0x40ba60: cdecl(a, fits, py0, py1) returns 0, or cnt - 2 (< 0) when fewer than 2 points (libvorbis floor1 fit_line shape). a = array of fits 0x30-byte records; x0 = a[0], x1 = a[fits-1][4].
// For each record with a nonzero dword at +0x24 the dwords +8 / +0xc / +0x10 / +0x18 are added into x / y / x2 / xy, +0x1c into cnt and +0x20 into n; (+0x14 is summed but never used). *py0 >= 0
// adds the point (x0, *py0): x += x0, y += y0, x2 += x0 * x0, xy += y0 * x0, cnt++, n++; *py1 >= 0 the point (x1, *py1) likewise. cnt < 2 returns cnt - 2. Otherwise (x87, extended
// precision, intermediate results stored as doubles): X2d = double(x2); R = [0x6be018] / (n * X2d - x * x); a = double((X2d * y - xy * x) * R); b = double((n * xy - y * x) * R);
// *py0 = ftol(floor(double((x0 * b + a) + [0x6be020]))) and *py1 likewise with x1 (floor 0x634dca takes the double on the stack, ftol 0x634dfa converts st0), then each clamped to 0x3ff
// from above (y0, y1) and to 0 from below (y0, y1).
static inline s32 wp_floor_ftol(double d) {
  u32 lo, hi;
  __builtin_memcpy(&lo, &d, 4);
  __builtin_memcpy(&hi, (u8 *)&d + 4, 4);
  u32 f1 = 0x634dca, f2 = 0x634dfa;
  s32 r;
  asm volatile(
      "pushl %[hi]\n\t"
      "pushl %[lo]\n\t"
      "call *%[f1]\n\t"
      "addl $8, %%esp\n\t"
      "call *%[f2]\n\t"
      : "=&a"(r)
      : [hi] "r"(hi), [lo] "r"(lo), [f1] "r"(f1), [f2] "r"(f2)
      : "ecx", "edx", "memory", "cc");
  return r;
}
extern "C" s32 GUESS_40ba60(u32 a, s32 fits, u32 py0, u32 py1) {
  s32 x0 = *(s32 *)a; /*w1*/
  s32 x1 = *(s32 *)(a + 48 * (u32)fits - 0x2c); /*w2*/
  s32 x = 0, y = 0, x2 = 0, xy = 0, cnt = 0, nn = 0; /*w3*/
  if (fits > 0) { /*w4*/
    u32 p = a + 8; /*w5*/
    s32 left = fits; /*w6*/
    do { /*w7*/
      if (w6ld(p + 0x1c) != 0) { /*w8*/
        x += (s32)w6ld(p); /*w9*/
        y += (s32)w6ld(p + 4); /*w10*/
        x2 += (s32)w6ld(p + 8); /*w11*/
        xy += (s32)w6ld(p + 0x10); /*w12*/
        cnt += (s32)w6ld(p + 0x14); /*w13*/
        nn += (s32)w6ld(p + 0x18); /*w14*/
      }
      p += 0x30; /*w15*/
      left--; /*w16*/
    } while (left != 0); /*w17*/
  }
  s32 y0 = *(s32 *)py0; /*w18*/
  if (y0 >= 0) { /*w19*/
    y += y0; /*w20*/
    x += x0; /*w21*/
    x2 += x0 * x0; /*w22*/
    xy += y0 * x0; /*w23*/
    cnt++; /*w24*/
    nn++; /*w25*/
  }
  s32 y1 = *(s32 *)py1; /*w26*/
  if (y1 >= 0) { /*w27*/
    x += x1; /*w28*/
    y += y1; /*w29*/
    x2 += x1 * x1; /*w30*/
    xy += y1 * x1; /*w31*/
    cnt++; /*w32*/
    nn++; /*w33*/
  }
  if (cnt < 2) return cnt - 2; /*w34*/
  long double Xl = (long double)x; /*w35*/
  long double Yl = (long double)y; /*w36*/
  double x2d = (double)(long double)x2; /*w37*/
  long double XYl = (long double)xy; /*w38*/
  long double Nl = (long double)nn; /*w39*/
  long double D1 = Nl * (long double)x2d - Xl * Xl; /*w40*/
  long double R = (long double)*(double *)0x6be018 / D1; /*w41*/
  long double A = (long double)x2d * Yl - XYl * Xl; /*w42*/
  double av = (double)(A * R); /*w43*/
  long double B = Nl * XYl - Yl * Xl; /*w44*/
  double bv = (double)(B * R); /*w45*/
  double c2 = *(double *)0x6be020; /*w46*/
  double d0 = (double)(((long double)x0 * (long double)bv + (long double)av) + (long double)c2); /*w47*/
  s32 r0 = wp_floor_ftol(d0); /*w48*/
  *(s32 *)py0 = r0; /*w49*/
  double d1 = (double)(((long double)x1 * (long double)bv + (long double)av) + (long double)c2); /*w50*/
  s32 r1 = wp_floor_ftol(d1); /*w51*/
  *(s32 *)py1 = r1; /*w52*/
  if (*(s32 *)py0 > 0x3ff) *(s32 *)py0 = 0x3ff; /*w53*/
  if (*(s32 *)py1 > 0x3ff) *(s32 *)py1 = 0x3ff; /*w54*/
  if (*(s32 *)py0 < 0) *(s32 *)py0 = 0; /*w55*/
  if (*(s32 *)py1 < 0) *(s32 *)py1 = 0; /*w56*/
  return 0; /*w57*/
}
PCREG(40ba60, GUESS_40ba60);

// 0x40b7b0: cdecl(flr, mdct, x0, x1, a, n, info) returns a[0x1c] (libvorbis floor1 accumulate_fit shape). q0 = 0x40ba30(&flr[x0]) (dB quantiser, hooked); a[0..11] = 0, a[0] = x0, a[1] = x1,
// a[0xa] = q0; x1 = min(x1, n). For i in x0 .. x1: q = 0x40ba30(&flr[i]); q != 0: if mdct[i] + info[0x460] (x87, extended) is >= flr[i] (NaN counts as less) the point goes to the first
// set (xa += i, ya += q, x2a += i*i, y2a += q*q, xya += q*i, an++) else to the second (xb, yb, x2b, y2b, xyb, bn++). Totals: bn += an, the b sums += the a sums. w = 0 when bn < info[0x454] or
// an < info[0x458], else info[0x45c] * bn / an (signed idiv; an = 0 would fault, the spec keeps info[0x458] >= 1). a[2..6] = w * a-sums + totals, a[7] = bn, a[8] = w * an + bn, a[9] = an
// (+1 when bn >= info[0x464]), a[0xb] = -200, or 0x40ba30(&flr[i]) when x1 < n. Returns bn.
extern "C" s32 ext_40ba30_wb(u32) __asm__("ext_40ba30");
extern "C" s32 GUESS_40b7b0(u32 flr, u32 mdct, s32 x0, s32 x1, u32 a, s32 n, u32 info) {
  u32 pfl = flr + (u32)x0 * 4; /*z1*/
  s32 q0 = ext_40ba30_wb(pfl); /*z2*/
  for (int k = 0; k < 12; k++) w6st(a + 4 * k, 0); /*z3*/
  w6st(a, (u32)x0); /*z4*/
  w6st(a + 4, (u32)x1); /*z5*/
  w6st(a + 0x28, (u32)q0); /*z6*/
  s32 x1c = x1 > n ? n : x1; /*z7*/
  u32 xa = 0, ya = 0, x2a = 0, y2a = 0, xya = 0, xb = 0, yb = 0, x2b = 0, y2b = 0, xyb = 0; /*z8*/
  u32 an = 0, bn = 0; /*z9*/
  s32 i = x0; /*z10*/
  if (i < x1c) { /*z11*/
    u32 p = pfl; /*z12*/
    u32 delta = mdct - flr; /*z13*/
    do { /*z14*/
      u32 q = (u32)ext_40ba30_wb(p); /*z15*/
      if (q != 0) { /*z16*/
        long double s = (long double)bitsf(w6ld(p + delta)) + (long double)bitsf(w6ld(info + 0x460)); /*z17*/
        bool lessb = !(s >= (long double)bitsf(w6ld(p))); /*z18*/
        if (!lessb) { /*z19*/
          xa += (u32)i; /*z20*/
          ya += q; /*z21*/
          x2a += (u32)i * (u32)i; /*z22*/
          y2a += q * q; /*z23*/
          xya += q * (u32)i; /*z24*/
          an++; /*z25*/
        } else { /*z26*/
          xb += (u32)i; /*z27*/
          yb += q; /*z28*/
          x2b += (u32)i * (u32)i; /*z29*/
          y2b += q * q; /*z30*/
          xyb += q * (u32)i; /*z31*/
          bn++; /*z32*/
        }
      }
      p += 4; /*z33*/
      i++; /*z34*/
    } while (i < x1c); /*z35*/
  }
  xb += xa; /*z36*/
  yb += ya; /*z37*/
  x2b += x2a; /*z38*/
  y2b += y2a; /*z39*/
  xyb += xya; /*z40*/
  bn += an; /*z41*/
  s32 w; /*z42*/
  if ((s32)bn < (s32)w6ld(info + 0x454)) w = 0; /*z43*/
  else if ((s32)an < (s32)w6ld(info + 0x458)) w = 0; /*z44*/
  else w = (s32)(w6ld(info + 0x45c) * bn) / (s32)an; /*z45*/
  u32 wu = (u32)w; /*z46*/
  w6st(a + 8, wu * xa + xb); /*z47*/
  w6st(a + 0xc, wu * ya + yb); /*z48*/
  w6st(a + 0x10, wu * x2a + x2b); /*z49*/
  w6st(a + 0x14, wu * y2a + y2b); /*z50*/
  w6st(a + 0x18, wu * xya + xyb); /*z51*/
  w6st(a + 0x20, wu * an + bn); /*z52*/
  w6st(a + 0x1c, bn); /*z53*/
  w6st(a + 0x24, an); /*z54*/
  if ((s32)bn >= (s32)w6ld(info + 0x464)) { /*z55*/
    an++; /*z56*/
    w6st(a + 0x24, an); /*z57*/
  }
  w6st(a + 0x2c, 0xffffff38u); /*z58*/
  if (x1c < n) w6st(a + 0x2c, (u32)ext_40ba30_wb(flr + (u32)i * 4)); /*z59*/
  return (s32)w6ld(a + 0x1c); /*z60*/
}
PCREG(40b7b0, GUESS_40b7b0);

// 0x40bc80: cdecl(x0, x1, y0, y1, mask, mdct, info) returns 0 or 1 (libvorbis floor1 inspect_error shape; the spec keeps x1 > x0). Walks the line from (x0, y0) to (x1, y1) with the integer
// Bresenham step (dy / adx, sy = base +- 1, err += ady - |base * adx|); at each x in x0 .. x1 - 1 whose mdct[x] + info[0x460] (x87, extended; NaN skips) is >= mask[x] and whose val =
// 0x40ba30(&mask[x]) is non-zero (the first point is also taken when val is 0): y + info[0x448] < val (NaN counts) or y - info[0x44c] > val returns 1 at once; otherwise e2 += (y - val)^2 and
// count++. count == 0 returns 0; info[0x448]^2 / count > info[0x450] or info[0x44c]^2 / count > info[0x450] returns 0; finally 1 only when (float)(e2 / count) > info[0x450].
extern "C" s32 ext_40ba30_wc(u32) __asm__("ext_40ba30");
extern "C" s32 GUESS_40bc80(s32 x0, s32 x1, s32 y0, s32 y1, u32 mask, u32 mdct, u32 info) {
  s32 dy = y1 - y0; /*y1*/
  s32 adx = x1 - x0; /*y2*/
  s32 ady = dy < 0 ? -dy : dy; /*y3*/
  s32 base = dy / adx; /*y4*/
  s32 sy = (dy >= 0) ? base + 1 : base - 1; /*y5*/
  s32 yy = y0; /*y6*/
  s32 err = 0; /*y7*/
  u32 pm = mask + (u32)x0 * 4; /*y8*/
  s32 val = ext_40ba30_wc(pm); /*y9*/
  s32 count = 0; /*y10*/
  s32 e2 = 0; /*y11*/
  s32 babs = base * adx; /*y12*/
  if (babs < 0) babs = -babs; /*y13*/
  s32 adyp = ady - babs; /*y14*/
  long double atten = (long double)bitsf(w6ld(info + 0x460)); /*y15*/
  long double off1 = (long double)bitsf(w6ld(info + 0x448)); /*y16*/
  long double off2 = (long double)bitsf(w6ld(info + 0x44c)); /*y17*/
  long double mv = (long double)bitsf(w6ld(mdct + (u32)x0 * 4)) + atten; /*y18*/
  if (mv >= (long double)bitsf(w6ld(pm))) { /*y19*/
    long double Y = (long double)y0; /*y20*/
    long double V = (long double)val; /*y21*/
    if (!((Y + off1) >= V)) return 1; /*y22*/
    if ((Y - off2) > V) return 1; /*y23*/
    count = 1; /*y24*/
    e2 = (y0 - val) * (y0 - val); /*y25*/
  }
  s32 i = x0 + 1; /*y26*/
  if (i < x1) { /*y27*/
    u32 p = mask + (u32)i * 4; /*y28*/
    u32 delta = mdct - mask; /*y29*/
    do { /*y30*/
      err += adyp; /*y31*/
      if (err >= adx) { /*y32*/
        err -= adx; /*y33*/
        yy += sy; /*y34*/
      } else { /*y35*/
        yy += base; /*y36*/
      }
      long double m2 = (long double)bitsf(w6ld(p + delta)) + atten; /*y37*/
      if (m2 >= (long double)bitsf(w6ld(p))) { /*y38*/
        val = ext_40ba30_wc(p); /*y39*/
        if (val != 0) { /*y40*/
          long double Y2 = (long double)yy; /*y41*/
          long double V2 = (long double)val; /*y42*/
          if (!((Y2 + off1) >= V2)) return 1; /*y43*/
          if ((Y2 - off2) > V2) return 1; /*y44*/
          e2 += (yy - val) * (yy - val); /*y45*/
          count++; /*y46*/
        }
      }
      i++; /*y47*/
      p += 4; /*y48*/
    } while (i < x1); /*y49*/
  }
  if (count == 0) return 0; /*y50*/
  float fc = (float)count; /*y51*/
  long double limit = (long double)bitsf(w6ld(info + 0x450)); /*y52*/
  if (off1 * off1 / (long double)fc > limit) return 0; /*y53*/
  if (off2 * off2 / (long double)fc > limit) return 0; /*y54*/
  s32 mean = e2 / count; /*y55*/
  return ((long double)mean > limit) ? 1 : 0; /*y56*/
}
PCREG(40bc80, GUESS_40bc80);

// 0x65b550: stdcall(a0 unused, n, base, cnt, flags) ret 0x14, void. Packed SSE lighting accumulation. D0 = 0x812a40 is a global lane table (16-byte aligned, 8 iterations of 4 lanes at most): positions at
// +0 / +0x80 / +0x100, normals +0x180 / +0x200 / +0x280, albedo +0x380 / +0x400 / +0x480, accumulators +0x500 / +0x580 / +0x600 (each 0x80 bytes, stepped by 0x10 per iteration; the number of iterations is
// (n + 3) >> 2 as an unsigned do-while, so n >= 1). For each of cnt records at base + k * 0x240 (type dword at +0x1a0, byte at +0x1a4): types 0..3 jump through the table 0x65bbec (type 0 -> spot
// with a smoothstep cone, 1 -> point light, 2 -> projected (u, v, w) cone with rcpps, 3 -> ambient), other types are skipped; types 0, 1 and 2 are also skipped when flags & 0x2000 and the byte at +0x1a4
// has bit 0 clear; type 3 with flags & 0x2000 only adds the colours (+0xc0 / +0xd0 / +0xe0), with flags & 0x1000000 adds albedo * colour, else hemisphere light. rsqrtps / rcpps run in the emulator exactly as in the original.
#define WQ_LD(a) _mm_load_ps((const float *)(u32)(a))
#define WQ_ST(a, v) _mm_store_ps((float *)(u32)(a), (v))
static inline void wq_acc(u32 D, u32 p, __m128 w) {
  __m128 v = _mm_mul_ps(WQ_LD(D + 0x380), w); /*h1*/
  v = _mm_mul_ps(v, WQ_LD(p + 0xc0)); /*h2*/
  v = _mm_add_ps(v, WQ_LD(D + 0x500)); /*h3*/
  WQ_ST(D + 0x500, v); /*h4*/
  v = _mm_mul_ps(WQ_LD(D + 0x400), w); /*h5*/
  v = _mm_mul_ps(v, WQ_LD(p + 0xd0)); /*h6*/
  v = _mm_add_ps(v, WQ_LD(D + 0x580)); /*h7*/
  WQ_ST(D + 0x580, v); /*h8*/
  v = _mm_mul_ps(WQ_LD(D + 0x480), w); /*h9*/
  v = _mm_mul_ps(v, WQ_LD(p + 0xe0)); /*h10*/
  v = _mm_add_ps(v, WQ_LD(D + 0x600)); /*h11*/
  WQ_ST(D + 0x600, v); /*h12*/
}
extern "C" void STDCALL GUESS_65b550(u32 a0, u32 n, u32 base, u32 cnt, u32 flags) { /*t1*/
  (void)a0; /*t2*/
  const u32 D0 = 0x812a40; /*t3*/
  const __m128 Z = WQ_LD(0x6c46a0), ONE = WQ_LD(0x6c46c0); /*t4*/
  if (cnt == 0) return; /*t5*/
  u32 recb = base + 0x1a4; /*t6*/
  do { /*t7*/
    u32 p = recb - 0x1a4; /*t8*/
    u32 type = w6ld(recb - 4); /*t9*/
    if (type <= 3) { /*t10*/
      u32 iters = (n + 3) >> 2; /*t11*/
      u32 D = D0; /*t12*/
      bool skip = false; /*t13*/
      if (type != 3 && (flags & 0x2000) && !(*(u8 *)recb & 1)) skip = true; /*t14*/
      if (!skip) { /*t15*/
        if (type == 1) { /*t16*/
          do { /*t17*/
            __m128 x0 = _mm_sub_ps(WQ_LD(p), WQ_LD(D)); /*t18*/
            __m128 x1 = _mm_sub_ps(WQ_LD(p + 0x10), WQ_LD(D + 0x80)); /*t19*/
            __m128 x2 = _mm_sub_ps(WQ_LD(p + 0x20), WQ_LD(D + 0x100)); /*t20*/
            __m128 t4 = _mm_mul_ps(x0, WQ_LD(D + 0x180)); /*t21*/
            __m128 t5 = _mm_mul_ps(x1, WQ_LD(D + 0x200)); /*t22*/
            __m128 t6 = _mm_mul_ps(x2, WQ_LD(D + 0x280)); /*t23*/
            t4 = _mm_add_ps(t4, t5); /*t24*/
            t4 = _mm_add_ps(t4, t6); /*t25*/
            t4 = _mm_max_ps(t4, Z); /*t26*/
            x0 = _mm_mul_ps(x0, x0); /*t27*/
            x1 = _mm_mul_ps(x1, x1); /*t28*/
            x2 = _mm_mul_ps(x2, x2); /*t29*/
            x0 = _mm_add_ps(x0, x1); /*t30*/
            x0 = _mm_add_ps(x0, x2); /*t31*/
            __m128 r1 = _mm_rsqrt_ps(x0); /*t32*/
            __m128 r2 = _mm_rcp_ps(r1); /*t33*/
            __m128 at = _mm_sub_ps(WQ_LD(p + 0x160), r2); /*t34*/
            at = _mm_mul_ps(at, WQ_LD(p + 0x170)); /*t35*/
            at = _mm_max_ps(at, Z); /*t36*/
            at = _mm_min_ps(at, ONE); /*t37*/
            at = _mm_mul_ps(at, r1); /*t38*/
            at = _mm_mul_ps(at, t4); /*t39*/
            wq_acc(D, p, at); /*t40*/
            D += 0x10; /*t41*/
          } while (--iters != 0); /*t42*/
        } else if (type == 0) { /*t43*/
          do { /*t44*/
            __m128 x0 = _mm_sub_ps(WQ_LD(p), WQ_LD(D)); /*t45*/
            __m128 x1 = _mm_sub_ps(WQ_LD(p + 0x10), WQ_LD(D + 0x80)); /*t46*/
            __m128 x2 = _mm_sub_ps(WQ_LD(p + 0x20), WQ_LD(D + 0x100)); /*t47*/
            __m128 t4 = _mm_mul_ps(x0, WQ_LD(D + 0x180)); /*t48*/
            __m128 t5 = _mm_mul_ps(x1, WQ_LD(D + 0x200)); /*t49*/
            __m128 t6 = _mm_mul_ps(x2, WQ_LD(D + 0x280)); /*t50*/
            t4 = _mm_add_ps(t4, t5); /*t51*/
            t4 = _mm_add_ps(t4, t6); /*t52*/
            t4 = _mm_max_ps(t4, Z); /*t53*/
            __m128 c0 = x0, c1 = x1, c2 = x2; /*t54*/
            x0 = _mm_mul_ps(x0, x0); /*t55*/
            x1 = _mm_mul_ps(x1, x1); /*t56*/
            x2 = _mm_mul_ps(x2, x2); /*t57*/
            x0 = _mm_add_ps(x0, x1); /*t58*/
            x0 = _mm_add_ps(x0, x2); /*t59*/
            __m128 r1 = _mm_rsqrt_ps(x0); /*t60*/
            __m128 r2 = _mm_rcp_ps(r1); /*t61*/
            __m128 at = _mm_sub_ps(WQ_LD(p + 0x160), r2); /*t62*/
            at = _mm_mul_ps(at, WQ_LD(p + 0x170)); /*t63*/
            at = _mm_max_ps(at, Z); /*t64*/
            at = _mm_min_ps(at, ONE); /*t65*/
            at = _mm_mul_ps(at, r1); /*t66*/
            at = _mm_mul_ps(at, t4); /*t67*/
            c0 = _mm_mul_ps(c0, WQ_LD(p + 0x90)); /*t68*/
            c1 = _mm_mul_ps(c1, WQ_LD(p + 0xa0)); /*t69*/
            c2 = _mm_mul_ps(c2, WQ_LD(p + 0xb0)); /*t70*/
            c0 = _mm_add_ps(c0, c1); /*t71*/
            c0 = _mm_add_ps(c0, c2); /*t72*/
            c0 = _mm_mul_ps(c0, r1); /*t73*/
            c0 = _mm_mul_ps(c0, WQ_LD(0x6c46f0)); /*t74*/
            c0 = _mm_sub_ps(c0, WQ_LD(p + 0x180)); /*t75*/
            c0 = _mm_mul_ps(c0, WQ_LD(p + 0x190)); /*t76*/
            c0 = _mm_max_ps(c0, Z); /*t77*/
            c0 = _mm_min_ps(c0, ONE); /*t78*/
            __m128 s3 = WQ_LD(0x6c46e0); /*t79*/
            __m128 s2 = _mm_mul_ps(c0, WQ_LD(0x6c46d0)); /*t80*/
            s3 = _mm_sub_ps(s3, s2); /*t81*/
            c0 = _mm_mul_ps(c0, c0); /*t82*/
            c0 = _mm_mul_ps(c0, s3); /*t83*/
            at = _mm_mul_ps(at, c0); /*t84*/
            wq_acc(D, p, at); /*t85*/
            D += 0x10; /*t86*/
          } while (--iters != 0); /*t87*/
        } else if (type == 2) { /*t88*/
          do { /*t89*/
            __m128 x0 = _mm_sub_ps(WQ_LD(p), WQ_LD(D)); /*t90*/
            __m128 x1 = _mm_sub_ps(WQ_LD(p + 0x10), WQ_LD(D + 0x80)); /*t91*/
            __m128 x2 = _mm_sub_ps(WQ_LD(p + 0x20), WQ_LD(D + 0x100)); /*t92*/
            __m128 t4 = _mm_mul_ps(x0, WQ_LD(D + 0x180)); /*t93*/
            __m128 t5 = _mm_mul_ps(x1, WQ_LD(D + 0x200)); /*t94*/
            __m128 t6 = _mm_mul_ps(x2, WQ_LD(D + 0x280)); /*t95*/
            t4 = _mm_add_ps(t4, t5); /*t96*/
            t4 = _mm_add_ps(t4, t6); /*t97*/
            t4 = _mm_max_ps(t4, Z); /*t98*/
            __m128 u = _mm_mul_ps(x0, WQ_LD(p + 0x30)); /*t99*/
            __m128 v = _mm_mul_ps(x0, WQ_LD(p + 0x60)); /*t100*/
            __m128 w = _mm_mul_ps(x0, WQ_LD(p + 0x90)); /*t101*/
            __m128 m3 = _mm_mul_ps(x1, WQ_LD(p + 0x40)); /*t102*/
            u = _mm_add_ps(u, m3); /*t103*/
            m3 = _mm_mul_ps(x1, WQ_LD(p + 0x70)); /*t104*/
            v = _mm_add_ps(v, m3); /*t105*/
            m3 = _mm_mul_ps(x1, WQ_LD(p + 0xa0)); /*t106*/
            w = _mm_add_ps(w, m3); /*t107*/
            m3 = _mm_mul_ps(x2, WQ_LD(p + 0x50)); /*t108*/
            u = _mm_add_ps(u, m3); /*t109*/
            m3 = _mm_mul_ps(x2, WQ_LD(p + 0x80)); /*t110*/
            v = _mm_add_ps(v, m3); /*t111*/
            m3 = _mm_mul_ps(x2, WQ_LD(p + 0xb0)); /*t112*/
            w = _mm_add_ps(w, m3); /*t113*/
            __m128 su = _mm_mul_ps(u, u); /*t114*/
            __m128 sv = _mm_mul_ps(v, v); /*t115*/
            __m128 sw = _mm_mul_ps(w, w); /*t116*/
            su = _mm_add_ps(su, sv); /*t117*/
            su = _mm_add_ps(su, sw); /*t118*/
            __m128 r1 = _mm_rsqrt_ps(su); /*t119*/
            __m128 r2 = _mm_rcp_ps(r1); /*t120*/
            __m128 at = _mm_sub_ps(WQ_LD(p + 0x160), r2); /*t121*/
            at = _mm_mul_ps(at, WQ_LD(p + 0x170)); /*t122*/
            at = _mm_max_ps(at, Z); /*t123*/
            at = _mm_min_ps(at, ONE); /*t124*/
            at = _mm_mul_ps(at, r1); /*t125*/
            at = _mm_mul_ps(at, t4); /*t126*/
            __m128 rw = _mm_rcp_ps(w); /*t127*/
            u = _mm_mul_ps(u, WQ_LD(p + 0x120)); /*t128*/
            v = _mm_mul_ps(v, WQ_LD(p + 0x130)); /*t129*/
            u = _mm_mul_ps(u, rw); /*t130*/
            v = _mm_mul_ps(v, rw); /*t131*/
            u = _mm_and_ps(u, WQ_LD(0x6c4700)); /*t132*/
            v = _mm_and_ps(v, WQ_LD(0x6c4700)); /*t133*/
            u = _mm_sub_ps(u, WQ_LD(p + 0x140)); /*t134*/
            v = _mm_sub_ps(v, WQ_LD(p + 0x140)); /*t135*/
            u = _mm_mul_ps(u, WQ_LD(p + 0x150)); /*t136*/
            v = _mm_mul_ps(v, WQ_LD(p + 0x150)); /*t137*/
            u = _mm_max_ps(u, Z); /*t138*/
            v = _mm_max_ps(v, Z); /*t139*/
            u = _mm_min_ps(u, ONE); /*t140*/
            v = _mm_min_ps(v, ONE); /*t141*/
            __m128 q1 = _mm_sub_ps(ONE, u); /*t142*/
            __m128 q2 = _mm_sub_ps(ONE, v); /*t143*/
            q1 = _mm_mul_ps(q1, q2); /*t144*/
            __m128 q3 = WQ_LD(0x6c46e0); /*t145*/
            q2 = _mm_mul_ps(q1, WQ_LD(0x6c46d0)); /*t146*/
            q3 = _mm_sub_ps(q3, q2); /*t147*/
            q1 = _mm_mul_ps(q1, q1); /*t148*/
            q1 = _mm_mul_ps(q1, q3); /*t149*/
            at = _mm_mul_ps(at, q1); /*t150*/
            wq_acc(D, p, at); /*t151*/
            D += 0x10; /*t152*/
          } while (--iters != 0); /*t153*/
        } else { /*t154*/
          if (flags & 0x2000) { /*t155*/
            do { /*t156*/
              __m128 a0v = _mm_add_ps(WQ_LD(D + 0x500), WQ_LD(p + 0xc0)); /*t157*/
              __m128 a1v = _mm_add_ps(WQ_LD(D + 0x580), WQ_LD(p + 0xd0)); /*t158*/
              __m128 a2v = _mm_add_ps(WQ_LD(D + 0x600), WQ_LD(p + 0xe0)); /*t159*/
              WQ_ST(D + 0x500, a0v); /*t160*/
              WQ_ST(D + 0x580, a1v); /*t161*/
              WQ_ST(D + 0x600, a2v); /*t162*/
              D += 0x10; /*t163*/
            } while (--iters != 0); /*t164*/
          } else if (flags & 0x1000000) { /*t165*/
            do { /*t166*/
              __m128 a0v = _mm_mul_ps(WQ_LD(D + 0x380), WQ_LD(p + 0xc0)); /*t167*/
              __m128 a1v = _mm_mul_ps(WQ_LD(D + 0x400), WQ_LD(p + 0xd0)); /*t168*/
              __m128 a2v = _mm_mul_ps(WQ_LD(D + 0x480), WQ_LD(p + 0xe0)); /*t169*/
              a0v = _mm_add_ps(a0v, WQ_LD(D + 0x500)); /*t170*/
              a1v = _mm_add_ps(a1v, WQ_LD(D + 0x580)); /*t171*/
              a2v = _mm_add_ps(a2v, WQ_LD(D + 0x600)); /*t172*/
              WQ_ST(D + 0x500, a0v); /*t173*/
              WQ_ST(D + 0x580, a1v); /*t174*/
              WQ_ST(D + 0x600, a2v); /*t175*/
              D += 0x10; /*t176*/
            } while (--iters != 0); /*t177*/
          } else { /*t178*/
            do { /*t179*/
              __m128 h3 = _mm_mul_ps(WQ_LD(D + 0x180), WQ_LD(p + 0x90)); /*t180*/
              __m128 h4 = _mm_mul_ps(WQ_LD(D + 0x200), WQ_LD(p + 0xa0)); /*t181*/
              __m128 h5 = _mm_mul_ps(WQ_LD(D + 0x280), WQ_LD(p + 0xb0)); /*t182*/
              __m128 h6 = _mm_sub_ps(ONE, h3); /*t183*/
              h6 = _mm_sub_ps(h6, h4); /*t184*/
              h6 = _mm_sub_ps(h6, h5); /*t185*/
              h6 = _mm_mul_ps(h6, WQ_LD(0x6c46b0)); /*t186*/
              h3 = WQ_LD(p + 0xf0); /*t187*/
              h4 = WQ_LD(p + 0x100); /*t188*/
              h5 = WQ_LD(p + 0x110); /*t189*/
              h3 = _mm_mul_ps(h3, h6); /*t190*/
              h4 = _mm_mul_ps(h4, h6); /*t191*/
              h5 = _mm_mul_ps(h5, h6); /*t192*/
              h3 = _mm_add_ps(h3, WQ_LD(p + 0xc0)); /*t193*/
              h4 = _mm_add_ps(h4, WQ_LD(p + 0xd0)); /*t194*/
              h5 = _mm_add_ps(h5, WQ_LD(p + 0xe0)); /*t195*/
              h3 = _mm_mul_ps(h3, WQ_LD(D + 0x380)); /*t196*/
              h4 = _mm_mul_ps(h4, WQ_LD(D + 0x400)); /*t197*/
              h5 = _mm_mul_ps(h5, WQ_LD(D + 0x480)); /*t198*/
              h3 = _mm_add_ps(h3, WQ_LD(D + 0x500)); /*t199*/
              h4 = _mm_add_ps(h4, WQ_LD(D + 0x580)); /*t200*/
              h5 = _mm_add_ps(h5, WQ_LD(D + 0x600)); /*t201*/
              WQ_ST(D + 0x500, h3); /*t202*/
              WQ_ST(D + 0x580, h4); /*t203*/
              WQ_ST(D + 0x600, h5); /*t204*/
              D += 0x10; /*t205*/
            } while (--iters != 0); /*t206*/
          }
        }
      }
    }
    recb += 0x240; /*t207*/
  } while (--cnt != 0); /*t208*/
}
PCREG(65b550, GUESS_65b550);

// 0x432cf0: thiscall(), returns al (/GS cookie not reproduced). Writes the key configuration as XML text. G = [0x70039c]; G[0x6b] != 0 returns 1; O = G + 0x4a3 (path holder, [O] = the path string);
// 0x4cc5f0(O) == 0 (empty path) logs through [0x700390] vslot 0x20(0x679f78, 0x1be) -> X, X vslot 0x2c(X, 0x67a068) and returns 0. Else buf = 0x41e290(0x2710) (cdecl), sprintf (0x42ac56, cdecl varargs) of
// "<Settings>\n<Controls>\n" style tags (formats at 0x67a0f4 "<%s", 0x67a0f8 ">\n", ...), then for each item of this+0x84 (iterator init vslot 0x4c(&it), next vslot 0x64(&it), 0 ends): "<Mapping" + Action=name
// (name = [item], the real 0x4cc1d0) padded with tabs (count = (int)ceil((0x13 - len) * [0x67a288] - [0x679540]) through 0x634da6 when len < 0x13), Activation = T[item[0xa1]] (T = the 9 strings None, Hold, Tap, Release, FastTap,
// DoubleClick, HoldDown, ClickHold, Press), ">\n", then for the 4 dwords at item + 0x80 that are not -1: "Key\t" SCode=this vslot 4(code) padded to 0x14, Device=this vslot 8(code), "/>\n"; item[0xa7] -> String=, item[0xab]
// -> NotAction/String=; "</Mapping>\n" and a newline byte. At the end "</Controls>" and "</Settings>", log 'Saving config file %s' (X vslot 0x2c, line 0x21c), 0x420ae0(path) (thiscall on the path string),
// H = [0x700394] vslot 0x14(path) -> file; non-zero: H vslot 0x38(file, buf, len), vslot 0x1c(file), 0x634273(buf, 1), return 1; zero: log line 0x226 'Unable to write' with G[0x4a3] and return 0.
extern "C" s32 ext_42ac56_wx(u32, u32, ...) __asm__("ext_42ac56");
extern "C" u32 THISCALL ext_4cc1d0_wx(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc5f0_wx(u32) __asm__("ext_4cc5f0");
extern "C" u32 ext_41e290_wx(u32) __asm__("ext_41e290");
extern "C" void THISCALL ext_420ae0_wx(u32) __asm__("ext_420ae0");
extern "C" void ext_634273_wx(u32, u32) __asm__("ext_634273");
extern "C" double ext_634da6_wx(double) __asm__("ext_634da6");
static inline u32 wx_tabs(u32 ebx, u32 pad) {
  float f = (float)(s32)pad * *(float *)0x67a288;
  f = f - *(float *)0x679540;
  double d = (double)f;
  double r = ext_634da6_wx(d);
  s32 cnt = (s32)r;
  if (cnt != 0) {
    for (s32 k = 0; k < cnt; k++) *(u8 *)(ebx + k) = 9;
    ebx += (u32)cnt;
  }
  return ebx;
}
static inline u32 wx_strlen(u32 s) {
  u32 n = 0;
  while (*(u8 *)(s + n) != 0) n++;
  return n;
}
extern "C" u32 THISCALL GUESS_432cf0(u32 self) {
  u32 G = *(u32 *)0x70039c; /*x1*/
  if (*(u8 *)(G + 0x6b) != 0) return 1; /*x2*/
  u32 O = G + 0x4a3; /*x3*/
  if (ext_4cc5f0_wx(O) == 0) { /*x4*/
    u32 lg = *(u32 *)0x700390; /*x5*/
    u32 x = ((W6T2b)*(u32 *)(*(u32 *)lg + 0x20))(lg, 0x679f78, 0x1be); /*x6*/
    ((u32(*)(u32, u32))*(u32 *)(*(u32 *)x + 0x2c))(x, 0x67a068); /*x7*/
    return 0; /*x8*/
  }
  u32 T[9] = {0x677b5c, 0x67a0a0, 0x67a0a8, 0x67a0ac, 0x67a0b4, 0x67a0bc, 0x67a0c8, 0x67a0d4, 0x67a0e0}; /*x9*/
  u32 buf = ext_41e290_wx(0x2710); /*x10*/
  *(u8 *)buf = 0; /*x11*/
  u32 ebx = buf; /*x12*/
  ebx += ext_42ac56_wx(buf, 0x67a0f4, 0x67a0e8); /*x13*/
  ebx += ext_42ac56_wx(ebx, 0x67a0f8); /*x14*/
  ebx += ext_42ac56_wx(ebx, 0x67a0f4, 0x67a0fc); /*x15*/
  ebx += ext_42ac56_wx(ebx, 0x67a0f8); /*x16*/
  u32 so = self + 0x84; /*x17*/
  u32 it[3]; /*x18*/
  u32 item = 0; /*x19*/
  if (so != 0) { /*x20*/
    ((W6T1)*(u32 *)(*(u32 *)so + 0x4c))(so, (u32)it); /*x21*/
    item = ((W6T1)*(u32 *)(*(u32 *)so + 0x64))(so, (u32)it); /*x22*/
  }
  while (item != 0) { /*x23*/
    ebx += ext_42ac56_wx(ebx, 0x67a0f4, 0x67a108); /*x24*/
    ebx += ext_42ac56_wx(ebx, 0x67a118, 0x67a110, ext_4cc1d0_wx(item)); /*x25*/
    s32 padn = 0x13 - (s32)wx_strlen(ext_4cc1d0_wx(item)); /*x26*/
    if (padn > 0) ebx = wx_tabs(ebx, (u32)padn); /*x27*/
    u32 idx = w6ld(item + 0xa1); /*x28*/
    ebx += ext_42ac56_wx(ebx, 0x67a118, 0x67a124, T[idx]); /*x29*/
    ebx += ext_42ac56_wx(ebx, 0x67a0f8); /*x30*/
    u32 cur = item + 0x80; /*x31*/
    for (int k = 4; k != 0; k--, cur += 4) { /*x32*/
      u32 v = w6ld(cur); /*x33*/
      if (v == 0xffffffffu) continue; /*x34*/
      ebx += ext_42ac56_wx(ebx, 0x67a0f4, 0x67a130); /*x35*/
      u32 nm = ((W6T1)*(u32 *)(*(u32 *)self + 4))(self, v); /*x36*/
      ebx += ext_42ac56_wx(ebx, 0x67a118, 0x67a138, nm); /*x37*/
      s32 pad2 = 0x14 - (s32)wx_strlen(nm); /*x38*/
      if (pad2 > 0) ebx = wx_tabs(ebx, (u32)pad2); /*x39*/
      u32 dv = ((W6T1)*(u32 *)(*(u32 *)self + 8))(self, w6ld(cur)); /*x40*/
      ebx += ext_42ac56_wx(ebx, 0x67a118, 0x67a140, dv); /*x41*/
      ebx += ext_42ac56_wx(ebx, 0x67a148); /*x42*/
    }
    if (w6ld(item + 0xa7) != 0) { /*x43*/
      ebx += ext_42ac56_wx(ebx, 0x67a0f4, 0x67a110); /*x44*/
      ebx += ext_42ac56_wx(ebx, 0x67a118, 0x67a14c, w6ld(item + 0xa7)); /*x45*/
      ebx += ext_42ac56_wx(ebx, 0x67a148); /*x46*/
    }
    if (w6ld(item + 0xab) != 0) { /*x47*/
      ebx += ext_42ac56_wx(ebx, 0x67a0f4, 0x67a154); /*x48*/
      ebx += ext_42ac56_wx(ebx, 0x67a118, 0x67a14c, w6ld(item + 0xab)); /*x49*/
      ebx += ext_42ac56_wx(ebx, 0x67a148); /*x50*/
    }
    ebx += ext_42ac56_wx(ebx, 0x67a160, 0x67a108); /*x51*/
    *(u8 *)ebx = 0xa; /*x52*/
    ebx++; /*x53*/
    so = self + 0x84; /*x54*/
    item = ((W6T1)*(u32 *)(*(u32 *)so + 0x64))(so, (u32)it); /*x55*/
  }
  ebx += ext_42ac56_wx(ebx, 0x67a160, 0x67a0fc); /*x56*/
  ebx += ext_42ac56_wx(ebx, 0x67a160, 0x67a0e8); /*x57*/
  u32 lg = *(u32 *)0x700390; /*x58*/
  u32 x = ((W6T2b)*(u32 *)(*(u32 *)lg + 0x20))(lg, 0x679f78, 0x21c); /*x59*/
  G = *(u32 *)0x70039c; /*x60*/
  ((u32(*)(u32, u32, u32))*(u32 *)(*(u32 *)x + 0x2c))(x, 0x67a168, ext_4cc1d0_wx(G + 0x4a3)); /*x61*/
  G = *(u32 *)0x70039c; /*x62*/
  ext_420ae0_wx(ext_4cc1d0_wx(G + 0x4a3)); /*x63*/
  G = *(u32 *)0x70039c; /*x64*/
  u32 H = *(u32 *)0x700394; /*x65*/
  u32 fh = ((W6T1)*(u32 *)(*(u32 *)H + 0x14))(H, ext_4cc1d0_wx(G + 0x4a3)); /*x66*/
  if (fh != 0) { /*x67*/
    H = *(u32 *)0x700394; /*x68*/
    ((W6T3)*(u32 *)(*(u32 *)H + 0x38))(H, fh, buf, ebx - buf); /*x69*/
    ((W6T1)*(u32 *)(*(u32 *)H + 0x1c))(H, fh); /*x70*/
    ext_634273_wx(buf, 1); /*x71*/
    return 1; /*x72*/
  }
  lg = *(u32 *)0x700390; /*x73*/
  x = ((W6T2b)*(u32 *)(*(u32 *)lg + 0x20))(lg, 0x679f78, 0x226); /*x74*/
  G = *(u32 *)0x70039c; /*x75*/
  ((u32(*)(u32, u32, u32))*(u32 *)(*(u32 *)x + 0x2c))(x, 0x67a180, w6ld(G + 0x4a3)); /*x76*/
  return 0; /*x77*/
}
PCREG(432cf0, GUESS_432cf0);

// 0x494bb0: thiscall(), void (SEH 0x667fc6, state 0 / 1 around the two string temporaries, /GS cookie not reproduced). Walks the timed-event list of this: cur = this vslot 4(); C = this + 0xcc
// (container: vslot 0 update(node, time), vslot 2 non-empty test, 0x493b80 removes a node). While C vslot 2() != 0: scan the list at this[0xad0] (nodes {id, .., next at +0x10}, count this[0xad8]) from index 0:
// ent = [0x70038c] vslot 0xcc(id); a missing ent, a missing / incompatible owner (ent[0x30], else G[0x9b] vslot 0x58(ent[0x1c]); its [8][0x3c] must have bit 0x800000) removes the node (index stays);
// G[0x40] <= ent[0x10] ends everything; an owner with [0x10] == 0 or [0x10][0x10] == 0 logs through [0x700390] vslot 0x20 / X vslot 0x2c (lines 0x118a / 0x1190) plus the fatal pointer [0x7003b0].
// A found node: G[0x38] = ent[0x10]; ent[0x10] += (int)(ent[0xc] * 1024.0); C vslot 0(node, ent[0x10]); skipped to the next round when this[0xbb0] != 0 and ent[0x14] & 0x100 is clear.
// ent[0x1c] != 0: profile record ent[0x34] (created through [0x700390][0xc] vslot 4 when absent) accumulates the low word of the G vslot 0x1c8 time difference, with the selected / counted
// bookkeeping through 0x494ac0 and the globals 0x6ffa84 .. 0x6ffa94 when cur is 0 or ent and [0x6ffa94] == 3.0 (owner vslots 0x164 / 0x160); ent[0x1c] == 0: owner-less variant (ent vslots 0x5c(8, 0, 0) / 0x14) when [0x6ffa94] == 4.0.
extern "C" void THISCALL ext_493b80_wy(u32, u32) __asm__("ext_493b80");
extern "C" void THISCALL ext_494ac0_wy(u32, u32) __asm__("ext_494ac0");
extern "C" void THISCALL ext_4cbec0_wy(u32) __asm__("ext_4cbec0");
static inline void wy_fatal() {
  u32 f = *(u32 *)0x7003b0;
  if (f) ((void (*)())f)();
  else asm volatile("int3");
}
extern "C" void THISCALL GUESS_494bb0(u32 self) {
  SEH_ENTER(0x667fc6);
  u32 cur = ((W6B)*(u32 *)(*(u32 *)self + 4))(self); /*y1*/
  u32 C = self + 0xcc; /*y2*/
  u32 more = ((W6B)*(u32 *)(*(u32 *)C + 8))(C); /*y3*/
  while (more != 0) { /*y4*/
    u32 ent = 0, objv = 0, node = 0, idx = 0; /*y5*/
    bool done = false; /*y6*/
    if (w6ld(self + 0xad8) != 0) { /*y7*/
      for (;;) { /*y8*/
        node = w6ld(self + 0xad0); /*y9*/
        for (u32 k = idx; k != 0; k--) node = w6ld(node + 0x10); /*y10*/
        u32 db = *(u32 *)0x70038c; /*y11*/
        ent = ((W6T1)*(u32 *)(*(u32 *)db + 0xcc))(db, w6ld(node)); /*y12*/
        bool rem = false; /*y13*/
        if (ent != 0) { /*y14*/
          u32 G = *(u32 *)0x70039c; /*y15*/
          if ((s32)w6ld(G + 0x40) <= (s32)w6ld(ent + 0x10)) { done = true; break; } /*y16*/
          objv = w6ld(ent + 0x30); /*y17*/
          if (objv == 0) { /*y18*/
            u32 gm = w6ld(G + 0x9b); /*y19*/
            objv = ((W6T1)*(u32 *)(*(u32 *)gm + 0x58))(gm, w6ld(ent + 0x1c)); /*y20*/
          }
          if (objv != 0) { /*y21*/
            if (w6ld(w6ld(objv + 8) + 0x3c) & 0x800000) { /*y22*/
              if (w6ld(objv + 0x10) == 0) { /*y23*/
                u32 lg = *(u32 *)0x700390; /*y24*/
                u32 x = ((W6T2b)*(u32 *)(*(u32 *)lg + 0x20))(lg, 0x68d798, 0x118a); /*y25*/
                u8 tmp[0x90] __attribute__((aligned(4))); /*y26*/
                u32 sv = ((W6T2b)*(u32 *)(*(u32 *)objv + 0x1d8))(objv, (u32)tmp, 1); /*y27*/
                reg.state = 0; /*y28*/
                u32 nm = ext_4cc1d0_wx(sv); /*y29*/
                ((u32(*)(u32, u32, u32, u32))*(u32 *)(*(u32 *)x + 0x2c))(x, 0x68e058, nm, objv); /*y30*/
                reg.state = -1; /*y31*/
                ext_4cbec0_wy((u32)tmp); /*y32*/
                wy_fatal(); /*y33*/
              }
              if (w6ld(w6ld(objv + 0x10) + 0x10) == 0) { /*y34*/
                u32 lg = *(u32 *)0x700390; /*y35*/
                u32 x = ((W6T2b)*(u32 *)(*(u32 *)lg + 0x20))(lg, 0x68d798, 0x1190); /*y36*/
                u8 tmp2[0x90] __attribute__((aligned(4))); /*y37*/
                u32 sv = ((W6T2b)*(u32 *)(*(u32 *)objv + 0x1d8))(objv, (u32)tmp2, 1); /*y38*/
                reg.state = 1; /*y39*/
                u32 nm = ext_4cc1d0_wx(sv); /*y40*/
                ((u32(*)(u32, u32, u32))*(u32 *)(*(u32 *)x + 0x2c))(x, 0x68e0b8, nm); /*y41*/
                reg.state = -1; /*y42*/
                ext_4cbec0_wy((u32)tmp2); /*y43*/
                wy_fatal(); /*y44*/
              }
              break; /*y45*/
            }
          }
        }
        ext_493b80_wy(C, node); /*y46*/
        (void)rem; /*y47*/
        if (idx == w6ld(self + 0xad8)) break; /*y48*/
      }
    }
    if (done) break; /*y49*/
    u32 found = (idx != w6ld(self + 0xad8)) ? node : 0; /*y50*/
    if (found != 0) { /*y51*/
      u32 G = *(u32 *)0x70039c; /*y52*/
      w6st(G + 0x38, w6ld(ent + 0x10)); /*y53*/
      float f = bitsf(w6ld(ent + 0xc)) * *(float *)0x678620; /*y54*/
      s32 add = _mm_cvttss_si32(_mm_set_ss(f)); /*y55*/
      w6st(ent + 0x10, w6ld(ent + 0x10) + (u32)add); /*y56*/
      u32 tmpt = w6ld(ent + 0x10); /*y57*/
      ((W6T2b)*(u32 *)(*(u32 *)C))(C, found, tmpt); /*y58*/
      bool skip = (*(u8 *)(self + 0xbb0) != 0) && !(w6ld(ent + 0x14) & 0x100); /*y59*/
      if (!skip) { /*y60*/
        if (w6ld(ent + 0x1c) != 0) { /*y61*/
          if (w6ld(*(u32 *)0x700390 + 0xc) == 0) w6st(ent + 0x34, 0); /*y62*/
          G = *(u32 *)0x70039c; /*y63*/
          u64 t0 = ((W6U64)*(u32 *)(*(u32 *)G + 0x1c8))(G, 0x68d798, 0x11ad); /*y64*/
          if (cur == 0 || cur == ent) { /*y65*/
            if (bitsf(*(u32 *)0x6ffa94) == bitsf(*(u32 *)0x680a68)) { /*y66*/
              G = *(u32 *)0x70039c; /*y67*/
              if (*(u32 *)0x6ffa84 != w6ld(G + 0x3c)) { /*y68*/
                *(u32 *)0x6ffa88 = 0; /*y69*/
                u32 o = ((W6B)*(u32 *)(*(u32 *)G + 0x190))(G); /*y70*/
                ((u32(*)(u32, u32, u32, u32))*(u32 *)(*(u32 *)o + 0x184))(o, 0, 4, 0x68e2b0); /*y71*/
                G = *(u32 *)0x70039c; /*y72*/
                *(u32 *)0x6ffa84 = w6ld(G + 0x3c); /*y73*/
              }
              u64 t1 = ((W6U64)*(u32 *)(*(u32 *)G + 0x1c8))(G, 0x68d798, 0x1471); /*y74*/
              *(u32 *)0x6ffa8c = (u32)t1; /*y75*/
              *(u32 *)0x6ffa90 = (u32)(t1 >> 32); /*y76*/
              ((W6B)*(u32 *)(*(u32 *)objv + 0x164))(objv); /*y77*/
              u32 nm = w6ld(objv + 4); /*y78*/
              ext_494ac0_wy(0x6ffa84, nm ? nm : 0x67c8e8); /*y79*/
            } else { /*y80*/
              ((W6B)*(u32 *)(*(u32 *)objv + 0x160))(objv); /*y81*/
            }
          }
          if (w6ld(*(u32 *)0x700390 + 0xc) != 0) { /*y82*/
            G = *(u32 *)0x70039c; /*y83*/
            u64 t2 = ((W6U64)*(u32 *)(*(u32 *)G + 0x1c8))(G, 0x68d798, 0x11b7); /*y84*/
            u64 el = t2 - t0; /*y85*/
            if (w6ld(ent + 0x34) == 0) { /*y86*/
              u32 lg = *(u32 *)0x700390; /*y87*/
              u32 P = w6ld(lg + 0xc); /*y88*/
              u32 r = ((W6T1)*(u32 *)(*(u32 *)P + 4))(P, 0); /*y89*/
              r -= 4; /*y90*/
              w6st(ent + 0x34, r); /*y91*/
              for (u32 k = 0; k < 0x18; k += 4) w6st(r + k, 0); /*y92*/
              u32 gm = w6ld(*(u32 *)0x70039c + 0x9b); /*y93*/
              u32 e8 = ((W6T1)*(u32 *)(*(u32 *)gm + 0x4c))(gm, objv); /*y94*/
              w6st(w6ld(ent + 0x34) + 8, e8); /*y95*/
              u32 db = *(u32 *)0x70038c; /*y96*/
              u32 r2 = ((W6T1)*(u32 *)(*(u32 *)db + 0x20))(db, ent); /*y97*/
              u32 cv; /*y98*/
              if (r2 != 0) { /*y99*/
                cv = 0; /*y100*/
              } else { /*y101*/
                db = *(u32 *)0x70038c; /*y102*/
                u32 fp = w6ld(db + 8); /*y103*/
                if (fp != 0 && !(w6ld(db + 0xc) > ent) && ent < w6ld(db + 0x10)) { /*y104*/
                  cv = ((W6B)fp)(ent); /*y105*/
                } else { /*y106*/
                  if (w6ld(ent - 4) == 0) ((W6T1)*(u32 *)(*(u32 *)db + 0xac))(db, ent); /*y107*/
                  cv = w6ld(ent - 4); /*y108*/
                }
              }
              w6st(w6ld(ent + 0x34) + 0xc, cv); /*y109*/
              w6st(w6ld(ent + 0x34) + 4, 0x8000008); /*y110*/
              w6st(w6ld(ent + 0x34) + 0x10, w6ld(w6ld(objv + 0xc))); /*y111*/
            }
            w6st(w6ld(ent + 0x34), w6ld(w6ld(ent + 0x34)) + (u32)el); /*y112*/
          }
        } else { /*y113*/
          if (cur == 0 || cur == ent) { /*y114*/
            if (!(bitsf(*(u32 *)0x6ffa94) == bitsf(*(u32 *)0x67da1c))) { /*y115*/
              ((W6V3)*(u32 *)(*(u32 *)ent + 0x5c))(ent, 8, 0, 0); /*y116*/
            } else { /*y117*/
              G = *(u32 *)0x70039c; /*y118*/
              if (*(u32 *)0x6ffa84 != w6ld(G + 0x3c)) { /*y119*/
                *(u32 *)0x6ffa88 = 0; /*y120*/
                u32 o = ((W6B)*(u32 *)(*(u32 *)G + 0x190))(G); /*y121*/
                ((u32(*)(u32, u32, u32, u32))*(u32 *)(*(u32 *)o + 0x184))(o, 0, 4, 0x68e2a0); /*y122*/
                G = *(u32 *)0x70039c; /*y123*/
                *(u32 *)0x6ffa84 = w6ld(G + 0x3c); /*y124*/
              }
              u64 t1 = ((W6U64)*(u32 *)(*(u32 *)G + 0x1c8))(G, 0x68d798, 0x1471); /*y125*/
              *(u32 *)0x6ffa8c = (u32)t1; /*y126*/
              *(u32 *)0x6ffa90 = (u32)(t1 >> 32); /*y127*/
              ((W6V3)*(u32 *)(*(u32 *)ent + 0x5c))(ent, 8, 0, 0); /*y128*/
              u32 nm = ((W6B)*(u32 *)(*(u32 *)ent + 0x14))(ent); /*y129*/
              ext_494ac0_wy(0x6ffa84, nm); /*y130*/
            }
          }
        }
      }
    }
    more = ((W6B)*(u32 *)(*(u32 *)C + 8))(C); /*y131*/
  }
  SEH_LEAVE();
}
PCREG(494bb0, GUESS_494bb0);

// 0x617400: thiscall(a, R) ret 8, void (own 16-byte aligned frame, MMX moves and emms, /GS cookie not reproduced). Skinned mesh submission. S = this[4][4][8], T = a[0x14][8], D = R[0x1377], B = R[0x13f6], V = R[0x13f2],
// F = byte R[0x1296]; timers 0x441730 / 0x440530 (texts 0x6bdeb4 .. 0x6bdee4, real code). Device caches (dev vslots 0x14c(0, V[0], 0x24), 0x154(B[0], 0), 0x130(0x152)), 0x610f20 / 0x610e20 / 0x6107e0(R, a[0x20] / [0x24] / [0x28]),
// R vslot 0x29c(S[0x20], S[0x38], S[0x44]); with R[0x115f] & 2: dev vslot 0xc8(0x89, 1) once and 0x611710(R, 0x658db0(T)). X = 0x658d80(T); S[0x98] runs of (count, offset) at S[0x9c] + K20 are copied (memcpy 0x634d22, count * 4 bytes
// from X + offset * 4) into a 0x4e4-byte palette LA. F != 0: the 26 3x4 matrices of LA become a 4x4 column palette OUT (each (s[-0x10], s[0], s[0x10], 0)); the vertices of this[4][0xc] (stride 0x40, n = S[0xe]) are skinned
// with up to four weights (floats at +0x20, bone byte at +0x3c .. +0x3f, matrix = palette + byte * 0x40; packed SSE) into the 0x24-byte vertices returned by 0x60ee10(V, &n, &base). F == 0: the scalar path over 0x34-byte
// source vertices (up to four influences, stops at the first zero weight, w3 = 1 - w0 - w1 - w2, bone byte * 16 into LA). Then V cleanup, and for each of the S[0x3c] index runs (u16 count, u16 length, indices) the 16-bit
// indices + base are written through 0x60ee10-like lock of B and drawn with dev vslot 0x11c(5, base, n, lockoffset, length - 2).
extern "C" void THISCALL ext_610f20_wz(u32, u32) __asm__("ext_610f20");
extern "C" void THISCALL ext_610e20_wz(u32, u32) __asm__("ext_610e20");
extern "C" void THISCALL ext_611710_wz(u32, u32) __asm__("ext_611710");
extern "C" u32 THISCALL ext_658db0_wz(u32) __asm__("ext_658db0");
extern "C" u32 THISCALL ext_658d80_wz(u32) __asm__("ext_658d80");
extern "C" u32 THISCALL ext_60ee10_wz(u32, u32, u32) __asm__("ext_60ee10");
extern "C" void *ext_634d22_wz(void *, const void *, u32) __asm__("ext_634d22");
typedef u32(STDCALL *WZS6)(u32, u32, u32, u32, u32, u32);
typedef u32(STDCALL *WZC5)(u32, u32, u32, u32, u32);
typedef u32(STDCALL *W6B_stack)(u32);
static inline __m128 wz_ld(u32 a) { return _mm_load_ps((const float *)a); }
static inline __m128 wz_ldu(u32 a) { return _mm_loadu_ps((const float *)a); }
extern "C" void THISCALL GUESS_617400(u32 self, u32 a, u32 R) { /*z1*/
  u8 LA[0x4e8] __attribute__((aligned(16))); /*z2*/
  u8 OUT[0x690] __attribute__((aligned(16))); /*z3*/
  ext_441730_wr(0x6bdeb4); /*z4*/
  u32 D = w6ld(R + 0x1377); /*z5*/
  u32 K20 = w6ld(w6ld(*(u32 *)0x70039c + 0x1aa3) + 0x20); /*z6*/
  u32 P4 = w6ld(self + 4); /*z7*/
  u32 B = w6ld(R + 0x13f6); /*z8*/
  u32 S = w6ld(w6ld(P4 + 4) + 8); /*z9*/
  u8 F = *(u8 *)(R + 0x1296); /*z10*/
  u32 V = w6ld(R + 0x13f2); /*z11*/
  u32 edx = w6ld(V); /*z12*/
  if (*(u32 *)0x724970 != edx || *(u32 *)0x7249b0 != 0x24) { /*z13*/
    u32 d = *(u32 *)0x724a00; /*z14*/
    *(u32 *)0x724970 = edx; /*z15*/
    *(u32 *)0x7249b0 = 0x24; /*z16*/
    ((W6S4)*(u32 *)(*(u32 *)d + 0x14c))(d, 0, edx, 0x24); /*z17*/
  }
  edx = w6ld(B); /*z18*/
  if (*(u32 *)0x7249f0 != edx || *(u32 *)0x7249f4 != 0) { /*z19*/
    u32 d = *(u32 *)0x724a00; /*z20*/
    *(u32 *)0x7249f0 = edx; /*z21*/
    *(u32 *)0x7249f4 = 0; /*z22*/
    ((W6S3)*(u32 *)(*(u32 *)d + 0x154))(d, edx, 0); /*z23*/
  }
  if (*(u32 *)0x7249f8 != 0x152) { /*z24*/
    u32 d = *(u32 *)0x724a00; /*z25*/
    *(u32 *)0x7249f8 = 0x152; /*z26*/
    ((W6S2)*(u32 *)(*(u32 *)d + 0x130))(d, 0x152); /*z27*/
  }
  u32 a20 = w6ld(a + 0x20), a24 = w6ld(a + 0x24), a28 = w6ld(a + 0x28); /*z28*/
  ext_610f20_wz(R, a20); /*z29*/
  ext_610e20_wz(R, a24); /*z30*/
  ext_6107e0_wk(R, a28); /*z31*/
  ((W6T3)*(u32 *)(*(u32 *)R + 0x29c))(R, w6ld(S + 0x20), w6ld(S + 0x38), w6ld(S + 0x44)); /*z32*/
  u32 T = w6ld(w6ld(a + 0x14) + 8); /*z33*/
  if (*(u8 *)(R + 0x115f) & 2) { /*z34*/
    if (*(u32 *)0x724948 != 1) { /*z35*/
      u32 d = *(u32 *)0x724a00; /*z36*/
      *(u32 *)0x724948 = 1; /*z37*/
      ((W6S3)*(u32 *)(*(u32 *)d + 0xc8))(d, 0x89, 1); /*z38*/
    }
    ext_611710_wz(R, ext_658db0_wz(T)); /*z39*/
  }
  ext_441730_wr(0x6bdebc); /*z40*/
  u32 X = ext_658d80_wz(T); /*z41*/
  u32 off = 0; /*z42*/
  u32 cnt = w6ld(S + 0x98); /*z43*/
  u32 rp = w6ld(S + 0x9c) + K20; /*z44*/
  if (cnt != 0) { /*z45*/
    do { /*z46*/
      u32 n = w6ld(rp); /*z47*/
      u32 o = w6ld(rp + 4); /*z48*/
      rp += 8; /*z49*/
      ext_634d22_wz((void *)((u32)LA + off * 4), (const void *)(X + o * 4), n * 4); /*z50*/
      off += n; /*z51*/
    } while (--cnt != 0); /*z52*/
  }
  u32 pal = (u32)LA; /*z53*/
  ext_440530_wr(0x6bdebc); /*z54*/
  ext_441730_wr(0x6bdec8); /*z55*/
  if (F != 0) { /*z56*/
    for (u32 g = 0; g < 0x1a; g++) { /*z57*/
      u32 s = (u32)LA + 0x10 + 0x30 * g; /*z58*/
      for (u32 j = 0; j < 4; j++) { /*z59*/
        u32 o = (u32)OUT + 0x10 * (4 * g + j); /*z60*/
        w6st(o, w6ld(s + 4 * j - 0x10)); /*z61*/
        w6st(o + 4, w6ld(s + 4 * j)); /*z62*/
        w6st(o + 8, w6ld(s + 4 * j + 0x10)); /*z63*/
        w6st(o + 12, 0); /*z64*/
      }
    }
    pal = (u32)OUT; /*z65*/
  }
  ext_440530_wr(0x6bdec8); /*z66*/
  u32 nv = *(u16 *)(S + 0xe); /*z67*/
  u32 vsrc = w6ld(S + 0x14) + K20; /*z68*/
  (void)vsrc; /*z69*/
  u32 base = 0; /*z70*/
  u32 dst = ext_60ee10_wz(V, (u32)&nv, (u32)&base); /*z71*/
  ext_441730_wr(0x6bded8); /*z72*/
  if (F != 0) { /*z73*/
    u32 sv = w6ld(P4 + 0xc); /*z74*/
    ext_441730_wr(0x6bdee4); /*z75*/
    u32 ecx = nv; /*z76*/
    u32 esi = sv, edi = dst; /*z77*/
    do { /*z78*/
      __m128 p0 = wz_ld(esi), n0 = wz_ld(esi + 0x10); /*z79*/
      u32 bi = (u32)*(u8 *)(esi + 0x3c) << 6; /*z80*/
      __m128 x = _mm_shuffle_ps(p0, p0, 0), y = _mm_shuffle_ps(p0, p0, 0x55), z = _mm_shuffle_ps(p0, p0, 0xaa); /*z81*/
      __m128 nx = _mm_shuffle_ps(n0, n0, 0), ny = _mm_shuffle_ps(n0, n0, 0x55), nz = _mm_shuffle_ps(n0, n0, 0xaa); /*z82*/
      __m128 r0 = _mm_mul_ps(x, wz_ld(pal + bi)); /*z83*/
      __m128 r3 = _mm_mul_ps(nx, wz_ld(pal + bi)); /*z84*/
      __m128 r1 = _mm_mul_ps(y, wz_ld(pal + bi + 0x10)); /*z85*/
      __m128 r4 = _mm_mul_ps(ny, wz_ld(pal + bi + 0x10)); /*z86*/
      __m128 r2 = _mm_mul_ps(z, wz_ld(pal + bi + 0x20)); /*z87*/
      __m128 r5 = _mm_mul_ps(nz, wz_ld(pal + bi + 0x20)); /*z88*/
      r0 = _mm_add_ps(r0, wz_ld(pal + bi + 0x30)); /*z89*/
      r0 = _mm_add_ps(r0, r1); /*z90*/
      __m128 wv = wz_ld(esi + 0x20); /*z91*/
      __m128 w = _mm_shuffle_ps(wv, wv, 0); /*z92*/
      r0 = _mm_add_ps(r0, r2); /*z93*/
      r0 = _mm_mul_ps(r0, w); /*z94*/
      r3 = _mm_add_ps(r3, r4); /*z95*/
      r3 = _mm_add_ps(r3, r5); /*z96*/
      r3 = _mm_mul_ps(r3, w); /*z97*/
      __m128 acc6 = r0, acc7 = r3; /*z98*/
      static const int sh[3] = {0x55, 0xaa, 0xff};
      u32 offs[3] = {0x3d, 0x3e, 0x3f}; /*z99*/
      bool cont = true; /*z100*/
      for (int q = 0; q < 3 && cont; q++) { /*z101*/
        bi = (u32)*(u8 *)(esi + offs[q]) << 6; /*z102*/
        if (bi == 0) { cont = false; break; }
        p0 = wz_ld(esi); /*z103*/
        n0 = wz_ld(esi + 0x10); /*z104*/
        x = _mm_shuffle_ps(p0, p0, 0); /*z105*/
        y = _mm_shuffle_ps(p0, p0, 0x55); /*z106*/
        z = _mm_shuffle_ps(p0, p0, 0xaa); /*z107*/
        nx = _mm_shuffle_ps(n0, n0, 0); /*z108*/
        ny = _mm_shuffle_ps(n0, n0, 0x55); /*z109*/
        nz = _mm_shuffle_ps(n0, n0, 0xaa); /*z110*/
        r0 = _mm_mul_ps(x, wz_ld(pal + bi)); /*z111*/
        r3 = _mm_mul_ps(nx, wz_ld(pal + bi)); /*z112*/
        r1 = _mm_mul_ps(y, wz_ld(pal + bi + 0x10)); /*z113*/
        r4 = _mm_mul_ps(ny, wz_ld(pal + bi + 0x10)); /*z114*/
        r2 = _mm_mul_ps(z, wz_ld(pal + bi + 0x20)); /*z115*/
        r5 = _mm_mul_ps(nz, wz_ld(pal + bi + 0x20)); /*z116*/
        r0 = _mm_add_ps(r0, wz_ld(pal + bi + 0x30)); /*z117*/
        r0 = _mm_add_ps(r0, r1); /*z118*/
        wv = wz_ld(esi + 0x20); /*z119*/
        w = (q == 0) ? _mm_shuffle_ps(wv, wv, 0x55) : (q == 1) ? _mm_shuffle_ps(wv, wv, 0xaa) : _mm_shuffle_ps(wv, wv, 0xff); /*z120*/
        r0 = _mm_add_ps(r0, r2); /*z121*/
        r0 = _mm_mul_ps(r0, w); /*z122*/
        r3 = _mm_add_ps(r3, r4); /*z123*/
        r3 = _mm_add_ps(r3, r5); /*z124*/
        r3 = _mm_mul_ps(r3, w); /*z125*/
        acc6 = _mm_add_ps(acc6, r0); /*z126*/
        acc7 = _mm_add_ps(acc7, r3); /*z127*/
      }
      (void)sh; /*z128*/
      _mm_storel_pi((__m64 *)edi, acc6); /*z129*/
      __m128 s6 = _mm_shuffle_ps(acc6, acc6, 0x1e); /*z130*/
      _mm_store_ss((float *)(edi + 8), s6); /*z131*/
      _mm_storel_pi((__m64 *)(edi + 0xc), acc7); /*z132*/
      __m128 s7 = _mm_shuffle_ps(acc7, acc7, 0x1e); /*z133*/
      _mm_store_ss((float *)(edi + 0x14), s7); /*z134*/
      w6st(edi + 0x18, w6ld(esi + 0x38)); /*z135*/
      w6st(edi + 0x1c, w6ld(esi + 0x30)); /*z136*/
      w6st(edi + 0x20, w6ld(esi + 0x34)); /*z137*/
      edi += 0x24; /*z138*/
      esi += 0x40; /*z139*/
    } while (--ecx != 0); /*z140*/
    ext_440530_wr(0x6bdee4); /*z141*/
  } else if (nv != 0) { /*z142*/
    u32 sbase = vsrc; /*z143*/
    u32 dv = dst + 8; /*z144*/
    u32 vb = sbase + 0x14; /*z145*/
    u32 idx = 3; /*z146*/
    u32 left = nv; /*z147*/
    do { /*z148*/
      float accX = 0, accY = 0, accZ = 0, accNX = 0, accNY = 0, accNZ = 0; /*z149*/
      u32 j = 0; /*z150*/
      for (;;) { /*z151*/
        float w; /*z152*/
        if (j != 3) w = bitsf(w6ld(sbase + (idx + j) * 4)); /*z153*/
        else { /*z154*/
          float s = bitsf(w6ld(vb - 8)); /*z155*/
          s = s + bitsf(w6ld(vb - 4)); /*z156*/
          s = s + bitsf(w6ld(vb)); /*z157*/
          w = bitsf(w6ld(0x678858)) - s; /*z158*/
        }
        if (w == 0.0f) break; /*z159*/
        u32 m = ((u32)*(u8 *)(vb + j + 4) << 4) + pal; /*z160*/
        j++; /*z161*/
        float x = bitsf(w6ld(vb - 0x14)), y = bitsf(w6ld(vb - 0x10)), z = bitsf(w6ld(vb - 0xc)); /*z162*/
        float nx = bitsf(w6ld(vb + 8)), ny = bitsf(w6ld(vb + 0xc)), nz = bitsf(w6ld(vb + 0x10)); /*z163*/
        float m0 = bitsf(w6ld(m)), m1 = bitsf(w6ld(m + 4)), m2 = bitsf(w6ld(m + 8)), m3 = bitsf(w6ld(m + 0xc)); /*z164*/
        float m4 = bitsf(w6ld(m + 0x10)), m5 = bitsf(w6ld(m + 0x14)), m6 = bitsf(w6ld(m + 0x18)), m7 = bitsf(w6ld(m + 0x1c)); /*z165*/
        float m8 = bitsf(w6ld(m + 0x20)), m9 = bitsf(w6ld(m + 0x24)), m10 = bitsf(w6ld(m + 0x28)), m11 = bitsf(w6ld(m + 0x2c)); /*z166*/
        float tx = m0 * x; /*z167*/
        tx = tx + m1 * y; /*z168*/
        tx = tx + m2 * z; /*z169*/
        tx = tx + m3; /*z170*/
        tx = tx * w; /*z171*/
        float newX = tx + accX; /*z172*/
        float ty = m4 * x; /*z173*/
        ty = ty + m5 * y; /*z174*/
        ty = ty + m6 * z; /*z175*/
        ty = ty + m7; /*z176*/
        ty = ty * w; /*z177*/
        float newY = ty + accY; /*z178*/
        float tz = m8 * x; /*z179*/
        tz = tz + m9 * y; /*z180*/
        tz = tz + m10 * z; /*z181*/
        tz = tz + m11; /*z182*/
        tz = tz * w; /*z183*/
        float newZ = tz + accZ; /*z184*/
        float tnx = m0 * nx; /*z185*/
        tnx = tnx + m1 * ny; /*z186*/
        tnx = tnx + m2 * nz; /*z187*/
        tnx = tnx * w; /*z188*/
        float newNX = tnx + accNX; /*z189*/
        float tny = m4 * nx; /*z190*/
        tny = tny + m5 * ny; /*z191*/
        tny = tny + m6 * nz; /*z192*/
        tny = tny * w; /*z193*/
        float newNY = tny + accNY; /*z194*/
        float tnz = m8 * nx; /*z195*/
        tnz = tnz + m9 * ny; /*z196*/
        tnz = nz * m10 + tnz; /*z197*/
        tnz = tnz * w; /*z198*/
        float newNZ = tnz + accNZ; /*z199*/
        accX = newX; accY = newY; accZ = newZ; accNX = newNX; accNY = newNY; accNZ = newNZ; /*z200*/
        if (j >= 4) break; /*z201*/
      }
      w6st(dv - 8, fbits(accX)); /*z202*/
      w6st(dv - 4, fbits(accY)); /*z203*/
      w6st(dv, fbits(accZ)); /*z204*/
      w6st(dv + 4, fbits(accNX)); /*z205*/
      w6st(dv + 8, fbits(accNY)); /*z206*/
      w6st(dv + 0xc, fbits(accNZ)); /*z207*/
      w6st(dv + 0x10, w6ld(vb + 0x14)); /*z208*/
      w6st(dv + 0x14, w6ld(vb + 0x18)); /*z209*/
      w6st(dv + 0x18, w6ld(vb + 0x1c)); /*z210*/
      idx += 0xd; /*z211*/
      vb += 0x34; /*z212*/
      dv += 0x24; /*z213*/
    } while (--left != 0); /*z214*/
  }
  ext_440530_wr(0x6bded8); /*z215*/
  if (*(u8 *)(V + 0x10) != 0) { /*z216*/
    u32 o = w6ld(V); /*z217*/
    if (o != 0) { /*z218*/
      ((W6B_stack)*(u32 *)(*(u32 *)o + 0x30))(o); /*z219*/
      *(u8 *)(V + 0x10) = 0; /*z220*/
    }
  }
  u32 ip = w6ld(S + 0x3c) + K20; /*z221*/
  u32 runs = *(u16 *)ip; /*z222*/
  ip += 2; /*z223*/
  if (runs != 0) { /*z224*/
    do { /*z225*/
      u32 len = *(u16 *)ip; /*z226*/
      ip += 2; /*z227*/
      u32 lockbase = 0; /*z228*/
      u32 outp = 0; /*z229*/
      u32 edx2; /*z230*/
      if (len > w6ld(B + 4)) { /*z231*/
        edx2 = 0; /*z232*/
      } else { /*z233*/
        edx2 = w6ld(B); /*z234*/
        if (edx2 != 0) { /*z235*/
          u32 eax; /*z236*/
          if (*(u8 *)(B + 0xd) == 0 && w6ld(B + 8) + len < w6ld(B + 4)) eax = 0x1800; /*z237*/
          else { /*z238*/
            *(u8 *)(B + 0xd) = 0; /*z239*/
            eax = 0x2800; /*z240*/
            w6st(B + 8, 0); /*z241*/
          }
          u32 rr = ((WZC5) * (u32 *)(*(u32 *)edx2 + 0x2c))(edx2, w6ld(B + 8) * 2, len * 2, (u32)&outp, eax); /*z242*/
          if (rr == 0) { /*z243*/
            lockbase = w6ld(B + 8); /*z244*/
            *(u8 *)(B + 0xc) = 1; /*z245*/
            w6st(B + 8, lockbase + len); /*z246*/
          }
        }
        edx2 = outp; /*z247*/
      }
      for (u32 k = 0; k < len; k++) { /*z248*/
        u16 v = (u16)(*(u16 *)(ip + 2 * k) + (u16)base); /*z249*/
        *(u16 *)(edx2 + 2 * k) = v; /*z250*/
      }
      ip += 2 * len; /*z251*/
      if (*(u8 *)(B + 0xc) != 0) { /*z252*/
        u32 o = w6ld(B); /*z253*/
        if (o != 0) { /*z254*/
          ((W6B_stack)*(u32 *)(*(u32 *)o + 0x30))(o); /*z255*/
          *(u8 *)(B + 0xc) = 0; /*z256*/
        }
      }
      ((WZS6)*(u32 *)(*(u32 *)D + 0x11c))(D, 5, base, nv, lockbase, len - 2); /*z257*/
    } while (--runs != 0); /*z258*/
  }
  ext_440530_wr(0x6bdeb4); /*z259*/
}
PCREG(617400, GUESS_617400);

// 0x636de0: fastcall(m, stride, a0, a1, a2, a3, a4) ret 0x14, returns 0 (DXT1 style 4x4 block compressor; m selects the 3 / 4 colour mode). Pixels come from a2 + 4 * (a1 * stride + a0), four rows
// of four 32-bit pixels (row pitch stride * 4); channels are unpacked with the shifts at 0x6f5a70 (0, 8, 16, 24): channel 0..2 as ints into PIX[16][4], channel 3 as an alpha mask (0 below 0x80, else 0xff).
// 0x63a2e0 gets the per channel min / max (FR(0x40) / FR(0x30)); equal ranges take the solid colour path (endpoints masked with 0xf8 / 0xfc (green, m == 0)), else the ranges are widened by [0x6f5a80]
// (32) and masked. 0x63a580 picks the channel order, then 0x63a460 / 0x63a1a0 / 0x63a390 search the endpoint grid (step 4 or 8, green 4 when m == 0), 0x63a0c0 assigns the 16 indices.
// The endpoints are ordered (col0 > col1 for m == 0, col0 < col1 otherwise; swapping them negates the indices (m == 0: 3 - i) or permutes them by {2, 1, 0, 3}), the indices are permuted by
// {0, 2, 3, 1} (m == 0) or {0, 2, 1, 3} and the two RGB565 words are written to a4[0] bit by bit (col0 | col1 << 16); 0x63a0c0 runs again, the unpacked pixels are written back to a3 (same
// positions, channels repacked with the 0x6f5a70 shifts, alpha mask at shift 24) and the 2-bit indices are written to a4[1]. The port keeps the original frame in one array so that the helpers
// see the same memory (uninitialised slots are 0xcccccccc like the harness stack fill).
extern "C" u32 FASTCALL ext_63a2e0_wq(u32, u32, u32, u32) __asm__("ext_63a2e0");
extern "C" u32 FASTCALL ext_63a580_wq(u32, u32, u32) __asm__("ext_63a580");
extern "C" u32 FASTCALL ext_63a460_wq(u32, u32, u32, u32, u32, u32) __asm__("ext_63a460");
extern "C" u32 FASTCALL ext_63a1a0_wq(u32, u32, u32, u32, u32, u32) __asm__("ext_63a1a0");
extern "C" u32 FASTCALL ext_63a390_wq(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_63a390");
extern "C" u32 FASTCALL ext_63a0c0_wq(u32, u32, u32, u32, u32) __asm__("ext_63a0c0");
#define FR(X) fr[(0x1d0 - (X)) / 4]
#define FP(X) ((u32)&FR(X))
extern "C" u32 FASTCALL GUESS_636de0(u32 m, u32 stride, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) { /*c1*/
  u32 fr[0x1d0 / 4 + 1]; /*c2*/
  for (u32 i = 0; i < 0x1d0 / 4 + 1; i++) fr[i] = 0xccccccccu;
  u32 ebx = a1 * stride + a0; /*c3*/
  FR(0x1b8) = m; /*c4*/
  FR(0x1cc) = a3; /*c5*/
  ebx <<= 2; /*c6*/
  FR(0x1a8) = a4; /*c7*/
  u32 rowp = a2 + ebx; /*c8*/
  w6st(a4 + 4, 0); /*c9*/
  w6st(a4, 0); /*c10*/
  FR(0x1c4) = stride * 4; /*c11*/
  FR(0x1c8) = ebx; /*c12*/
  FR(0x1bc) = rowp; /*c13*/
  u32 esi = 0; /*c14*/
  u32 edi = FP(0x198); /*c15*/
  do { /*c16*/
    u32 ecx = FR(0x1bc); /*c17*/
    FR(0x1b4) = 4; /*c18*/
    do { /*c19*/
      FR(0x1b0) = ecx; /*c20*/
      u32 pix = w6ld(ecx); /*c21*/
      for (u32 c = 0; c < 4; c++) { /*c22*/
        u32 sh = w6ld(0x6f5a70 + c * 4); /*c23*/
        u32 v = (u32)((s32)pix >> (sh & 31)) & 0xff; /*c24*/
        FR(0x14 - 4 * c) = v; /*c25*/
        if (c != 3) FR(0x1a4 - 4 * (esi + c)) = v; /*c26*/
        else w6st(edi, ((s32)v < 0x80) ? 0 : 0xff); /*c27*/
      }
      ecx = FR(0x1b0); /*c28*/
      esi += 4; /*c29*/
      ecx += 4; /*c30*/
      edi += 0x10; /*c31*/
      FR(0x1b4) = FR(0x1b4) - 1; /*c32*/
      FR(0x1b0) = ecx; /*c33*/
    } while (FR(0x1b4) != 0); /*c34*/
    FR(0x1bc) = FR(0x1bc) + FR(0x1c4); /*c35*/
  } while ((s32)esi < 0x40); /*c36*/
  ext_63a2e0_wq(0x10, FP(0x1a4), FP(0x40), FP(0x30)); /*c37*/
  u32 k = 0; /*c38*/
  while (k < 4) { /*c39*/
    if (FR(0x40 - 4 * k) != FR(0x30 - 4 * k)) break; /*c40*/
    k++; /*c41*/
  }
  if (k != 4) { /*c42*/
    u32 hi = FR(0x2c); /*c43*/
    u32 lo = FR(0x3c); /*c44*/
    u32 pad = w6ld(0x6f5a80); /*c45*/
    for (u32 c = 0; c < 3; c++) { /*c46*/
      if (c == 1) { /*c47*/
        u32 e = lo; /*c48*/
        e = e - pad; /*c49*/
        if ((s32)e < 0) e = 0; /*c50*/
        if (FR(0x1b8) == 0) { /*c51*/
          e &= 0xfc; /*c52*/
          FR(0x48) = e; /*c53*/
          e = hi + pad; /*c54*/
          if ((s32)e > 0xff) e = 0xff; /*c55*/
          e &= 0xfc; /*c56*/
        } else { /*c57*/
          e &= 0xf8; /*c58*/
          FR(0x48) = e; /*c59*/
          e = hi + pad; /*c60*/
          if ((s32)e > 0xff) e = 0xff; /*c61*/
          e &= 0xf8; /*c62*/
        }
        FR(0x60) = e; /*c63*/
      } else { /*c64*/
        u32 c0 = FR(0x40 - 4 * c); /*c65*/
        u32 e = c0 - pad; /*c66*/
        if ((s32)e < 0) e = 0; /*c67*/
        e &= 0xf8; /*c68*/
        FR(0x4c - 4 * c) = e; /*c69*/
        e = c0 + pad; /*c70*/
        if ((s32)e > 0xff) e = 0xff; /*c71*/
        e &= 0xf8; /*c72*/
        FR(0x10 - 4 * c) = e; /*c73*/
        u32 c1 = FR(0x30 - 4 * c); /*c74*/
        e = c1 - pad; /*c75*/
        if ((s32)e < 0) e = 0; /*c76*/
        e &= 0xf8; /*c77*/
        FR(0x58 - 4 * c) = e; /*c78*/
        e = c1 + pad; /*c79*/
        if ((s32)e > 0xff) e = 0xff; /*c80*/
        e &= 0xf8; /*c81*/
        FR(0x64 - 4 * c) = e; /*c82*/
      }
    }
    ebx = FR(0x1b8); /*c83*/
  } else { /*c84*/
    ebx = FR(0x1b8); /*c85*/
    u32 e = FR(0x40) & 0xf8; /*c86*/
    FR(0x64) = e; /*c87*/
    FR(0x4c) = e; /*c88*/
    e = FR(0x3c); /*c89*/
    if (ebx == 0) e &= 0xfc; /*c90*/
    else e &= 0xf8; /*c91*/
    FR(0x48) = e; /*c92*/
    FR(0x60) = e; /*c93*/
    e = FR(0x38) & 0xf8; /*c94*/
    FR(0x5c) = e; /*c95*/
    FR(0x44) = e; /*c96*/
  }
  ext_63a580_wq(0x10, FP(0x1a4), FP(0x10)); /*c97*/
  u32 axis = FR(0x10); /*c98*/
  u32 best = 0x7fffffff; /*c99*/
  FR(0x58) = 0; FR(0x20) = 0; FR(0x3c) = 0; FR(0x2c) = 0; FR(0x54) = 0; FR(0x1c) = 0; /*c100*/
  FR(0x38) = 0; FR(0x28) = 0; FR(0x50) = 0; FR(0x18) = 0; FR(0x34) = 0; FR(0x24) = 0; /*c101*/
  if (axis != 1) FR(0x1bc) = 8; /*c102*/
  else { /*c103*/
    FR(0x1bc) = 4; /*c104*/
    if (ebx != 0) FR(0x1bc) = 8; /*c105*/
  }
  FR(0x1b0) = (axis != 1) ? 8 : 4; /*c106*/
  u32 eax = FR(0x4c - 4 * axis); /*c107*/
  FR(0x3c - 4 * axis) = eax; /*c108*/
  if ((s32)eax <= (s32)FR(0x64 - 4 * axis)) { /*c109*/
    u32 b2 = eax; /*c110*/
    for (;;) { /*c111*/
      FR(0x58 - 4 * axis) = eax; /*c112*/
      u32 e2 = eax; /*c113*/
      for (;;) { /*c114*/
        u32 r = ext_63a460_wq(FR(0x1b8), axis, FP(0x3c), FP(0x58), FP(0x1a4), best); /*c115*/
        axis = FR(0x10); /*c116*/
        if ((s32)r < (s32)best) { /*c117*/
          best = r; /*c118*/
          FR(0x2c - 4 * axis) = b2; /*c119*/
          FR(0x20 - 4 * axis) = e2; /*c120*/
        }
        e2 += FR(0x1b0); /*c121*/
        u32 lim = FR(0x64 - 4 * axis); /*c122*/
        FR(0x58 - 4 * axis) = e2; /*c123*/
        if ((s32)e2 > (s32)lim) break; /*c124*/
      }
      b2 += FR(0x1bc); /*c125*/
      u32 lim = FR(0x64 - 4 * axis); /*c126*/
      FR(0x3c - 4 * axis) = b2; /*c127*/
      eax = FR(0x4c - 4 * axis); /*c128*/
      if ((s32)b2 > (s32)lim) break; /*c129*/
    }
  }
  u32 mm = FR(0x1b8); /*c130*/
  ext_63a1a0_wq(mm, axis, FP(0x2c), FP(0x20), FP(0x1a4), FP(0xa4)); /*c131*/
  axis = FR(0x10); /*c132*/
  FR(0x3c - 4 * axis) = FR(0x2c - 4 * axis); /*c133*/
  FR(0x58 - 4 * axis) = FR(0x20 - 4 * axis); /*c134*/
  if (axis != 1) FR(0x1b4) = 8; /*c135*/
  else { /*c136*/
    FR(0x1b4) = 4; /*c137*/
    if (mm != 0) FR(0x1b4) = 8; /*c138*/
  }
  FR(0x1ac) = 1; /*c139*/
  u32 kk = 1; /*c140*/
  do { /*c141*/
    u32 comp = FR(0x10 - 4 * kk); /*c142*/
    best = 0x7fffffff; /*c143*/
    FR(0x1bc) = comp; /*c144*/
    u32 start = FR(0x4c - 4 * comp); /*c145*/
    u32 hiv = FR(0x64 - 4 * comp); /*c146*/
    FR(0x3c - 4 * comp) = start; /*c147*/
    if ((s32)start <= (s32)hiv) { /*c148*/
      FR(0x1c0) = start; /*c149*/
      for (;;) { /*c150*/
        FR(0x58 - 4 * comp) = start; /*c151*/
        u32 e2 = start; /*c152*/
        for (;;) { /*c153*/
          u32 r = ext_63a390_wq(FR(0x1b8), comp, FP(0x3c), FP(0x58), FP(0x1a4), FP(0xa4), best); /*c154*/
          comp = FR(0x1bc); /*c155*/
          if ((s32)r < (s32)best) { /*c156*/
            best = r; /*c157*/
            FR(0x20 - 4 * comp) = e2; /*c158*/
            FR(0x2c - 4 * comp) = FR(0x3c - 4 * comp); /*c159*/
          }
          e2 += FR(0x1b0); /*c160*/
          FR(0x58 - 4 * comp) = e2; /*c161*/
          if ((s32)e2 > (s32)hiv) break; /*c162*/
        }
        u32 nx = FR(0x1c0) + FR(0x1b4); /*c163*/
        FR(0x1c0) = nx; /*c164*/
        FR(0x3c - 4 * comp) = nx; /*c165*/
        start = FR(0x4c - 4 * comp); /*c166*/
        if ((s32)nx > (s32)hiv) break; /*c167*/
      }
    }
    kk = FR(0x1ac) + 1; /*c168*/
    FR(0x1ac) = kk; /*c169*/
  } while (kk < 3); /*c170*/
  ext_63a0c0_wq(FR(0x1b8), FP(0x2c), FP(0x20), FP(0x1a4), FP(0xa4)); /*c171*/
  u32 R0 = FR(0x2c), G0 = FR(0x28), B0 = FR(0x24), R1 = FR(0x20), G1 = FR(0x1c), B1 = FR(0x18); /*c172*/
  u32 col0 = ((((R0 & 0xfffffff8u) << 5) + (G0 & 0xfffffffcu)) * 8) + (u32)((s32)B0 >> 3); /*c173*/
  u32 col1 = ((((R1 & 0xfffffff8u) << 5) + (G1 & 0xfffffffcu)) * 8) + (u32)((s32)B1 >> 3); /*c174*/
  bool swap = (FR(0x1b8) == 0) ? (col0 < col1) : (col1 < col0); /*c175*/
  u32 bb0 = B0; /*c176*/
  if (swap) { /*c177*/
    u32 tR = R0, tG = G0, tB = B0; /*c178*/
    R0 = R1; G0 = G1; B0 = B1; /*c179*/
    R1 = tR; G1 = tG; B1 = tB; /*c180*/
    FR(0x20) = R1; FR(0x2c) = R0; /*c181*/
    FR(0x1c) = G1; FR(0x28) = G0; /*c182*/
    FR(0x18) = B1; FR(0x24) = B0; /*c183*/
    bb0 = B0; /*c184*/
    if (FR(0x1b8) == 0) { /*c185*/
      for (u32 i = 0; i < 16; i++) FR(0xa4 - 4 * i) = w6ld(0x6c2290 + 4 * (i & 3)) - FR(0xa4 - 4 * i); /*c186*/
    } else { /*c187*/
      FR(0x14) = 2; FR(0x10) = 1; FR(0xc) = 0; FR(0x8) = 3; /*c188*/
      for (u32 i = 0; i < 16; i++) FR(0xa4 - 4 * i) = FR(0x14 - 4 * FR(0xa4 - 4 * i)); /*c189*/
    }
  }
  if (FR(0x1b8) == 0) { /*c190*/
    FR(0x14) = 0; FR(0x10) = 2; FR(0xc) = 3; FR(0x8) = 1; /*c191*/
  } else { /*c192*/
    FR(0x14) = 0; FR(0x10) = 2; FR(0xc) = 1; FR(0x8) = 3; /*c193*/
  }
  for (u32 i = 0; i < 16; i++) FR(0xa4 - 4 * i) = FR(0x14 - 4 * FR(0xa4 - 4 * i)); /*c194*/
  u32 w0 = ((bb0 >> 3) & 0x1f) | ((B1 & 0xf8) << 13) | ((G0 & 0xfc) << 3) | ((G1 & 0xfc) << 19) | ((R0 & 0xf8) << 8) |
           (((R1 & 0x78) << 24)) | ((R1 & 0xffffff80u) << 24); /*c195*/
  w6st(a4, w0); /*c196*/
  ext_63a0c0_wq(FR(0x1b8), FP(0x2c), FP(0x20), FP(0x1a4), FP(0xa4)); /*c197*/
  u32 dp = FR(0x1cc) + FR(0x1c8); /*c198*/
  FR(0x1b4) = dp; /*c199*/
  u32 sp = FP(0x19c); /*c200*/
  u32 ip = FP(0xa4); /*c201*/
  u32 bi = 1; /*c202*/
  do { /*c203*/
    FR(0x1c0) = ip; /*c204*/
    FR(0x1b0) = dp; /*c205*/
    FR(0x1ac) = sp; /*c206*/
    FR(0x1bc) = 4; /*c207*/
    do { /*c208*/
      u32 e0 = w6ld(sp - 8), e1 = w6ld(sp - 4); /*c209*/
      u32 v = (e0 << (w6ld(0x6f5a70) & 31)) | (e1 << (w6ld(0x6f5a74) & 31)) | (w6ld(sp + 4) << (w6ld(0x6f5a7c) & 31)) | (w6ld(sp) << (w6ld(0x6f5a78) & 31)); /*c210*/
      u32 idx = w6ld(ip); /*c211*/
      w6st(FR(0x1b0), v); /*c212*/
      FR(0x1b0) = FR(0x1b0) + 4; /*c213*/
      u32 wp = a4 + ((bi + 0x1f) >> 5) * 4; /*c214*/
      u32 cur = w6ld(wp); /*c215*/
      u32 bp = (bi - 1) & 0x1f; /*c216*/
      cur &= ~(1u << bp); /*c217*/
      cur |= (idx & 1) << bp; /*c218*/
      w6st(wp, cur); /*c219*/
      u32 idx2 = (u32)((s32)idx >> 1) & 1; /*c220*/
      u32 wp2 = a4 + ((bi + 0x20) >> 5) * 4; /*c221*/
      u32 cur2 = w6ld(wp2); /*c222*/
      u32 bp2 = bi & 0x1f; /*c223*/
      cur2 &= ~(1u << bp2); /*c224*/
      cur2 |= idx2 << bp2; /*c225*/
      w6st(wp2, cur2); /*c226*/
      sp = FR(0x1ac) + 0x10; /*c227*/
      FR(0x1ac) = sp; /*c228*/
      bi += 2; /*c229*/
      ip = FR(0x1c0) + 4; /*c230*/
      FR(0x1bc) = FR(0x1bc) - 1; /*c231*/
      FR(0x1c0) = ip; /*c232*/
    } while (FR(0x1bc) != 0); /*c233*/
    dp = FR(0x1b4) + FR(0x1c4); /*c234*/
    FR(0x1b4) = dp; /*c235*/
  } while ((s32)bi < 0x21); /*c236*/
  return 0; /*c237*/
}
PCREG(636de0, GUESS_636de0);
