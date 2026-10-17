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
              if (rem < 4) return -2;
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
