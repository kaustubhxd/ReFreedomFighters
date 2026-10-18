// batch252021.cpp - Sonnet-w4f hand port of 0x60f1f0 (lifter: `rep stosd`).
#include "ff.h"
#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ce480_thiscall2(u32, u32) __asm__("ext_4ce480");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" void FASTCALL ext_633654(u32 cookie);

// 0x60f1f0: stdcall(a0, a1, a2, a3 = source object, a4 = divisor << 6) ret 0x14, SEH3 (handler 0x66e2c8), void (eax junk).
// Builds a 64 character map in a stack buffer (the 16 bytes at 0x6bd580 four times, zero terminator), walks the entries of a local
// iterator object (slots +0x4c begin, +0x64 next -> {start, length} or null) and fills each span (start / d .. + length / d, '.'), then logs it
// through engine object slot +0x190 -> slot +0x184 (cdecl, 6 arguments).
extern "C" void STDCALL lifted_60f1f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  SEH_ENTER(0x66e2c8);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 L = (u32)(F + 0x300 - 0x74), W = (u32)(F + 0x300 - 0x80), B = (u32)(F + 0x300 - 0x54);
  u32 eng = G(u32, 0x70039c);
  u32 e2 = G(u32, eng + 0x1aa3);
  if (G(u8, e2 + 0x76) != 0) {
    for (u32 i = 0; i < 4; i++) { G(u32, B + 16 * i) = G(u32, 0x6bd580); G(u32, B + 16 * i + 4) = G(u32, 0x6bd584); G(u32, B + 16 * i + 8) = G(u32, 0x6bd588); G(u32, B + 16 * i + 12) = G(u32, 0x6bd58c); }
    G(u8, B + 0x40) = 0;
    u32 d = a4 >> 6;
    ext_4ccbe0_thiscall3(L, 0x80, 1);
    reg.state = 0;
    ext_4ce480_thiscall2(a3, L);
    ((u32(THISCALL *)(u32, u32))(*(u32 *)(G(u32, L) + 0x4c)))(L, W);
    u32 p;
    while ((p = ((u32(THISCALL *)(u32, u32))(*(u32 *)(G(u32, L) + 0x64)))(L, W)) != 0) {
      u32 edi = G(u32, p);
      u32 esi = G(u32, p + 4) / d;
      u32 q = edi / d;
      if (q == 0) q = ((d >> 1) < edi) ? 1 : 0;
      u32 cnt = q + esi;
      if (esi < cnt) { u32 n = cnt - esi; for (u32 k = 0; k < n; k++) G(u8, B + esi + k) = 0x2e; }
    }
    u32 g = G(u32, 0x70039c);
    u32 r = ((u32(THISCALL *)(u32))(*(u32 *)(G(u32, g) + 0x190)))(g);
    ((u32(*)(u32, u32, u32, u32, u32, u32))(*(u32 *)(G(u32, r) + 0x184)))(r, a0, a1, 0x6965cc, a2, B);
    ext_4ccfe0_thiscall1(L);
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
}
PCREG(60f1f0, lifted_60f1f0);

// 0x53ca50: thiscall(this, a, b, flag) ret 0xc, bool in al (upper bits of eax are stack junk in the original). Hand port (lifter: `lift: ebp`).
// A small worklist of index pairs lives in the frame (original [ebp-0x14..]); each pair (x, y) is sorted so x <= y, x selects a record list
// this[0x1201][x] = {count, offset} into the dword pool this[0x1205] (entries: low 16 bits payload, bits 16..29 key, bits 30..31 type), y must lie
// between the first and last key. flag != 0: log through engine [0x700390] (slot +0x20 -> slot +0x2c cdecl) and return 1 (in range) / 0 (out of range);
// flag == 0: find the entry whose key == y, by type: 0 / 1 result |= float tests on this[0x11f9] (0xa4-byte records, float at +8) / this[0x11fd],
// 2 replaces the worklist by (payload, x), (payload, y) with 3 passes, 3 calls the global hook [0x7003b0] (int3 when null).
extern "C" u32 THISCALL lifted_53ca50(u32 ecx_in, u32 a, u32 b, u32 flag) {
  u32 self = ecx_in;
  if (a == b) { ext_633654(G(u32, 0x6f5630)); return 1; }
  u32 W[8] = {a, b, 0, 0, 0, 0, 0, 0};
  u32 cnt = 1, idx = 0; u8 res = 0;
  do {
    u32 ebx = W[idx], esi = W[idx + 1];
    if (ebx != 0xffffffffu && esi != 0xffffffffu) {
      if (esi < ebx) { u32 t = ebx; ebx = esi; esi = t; }
      u32 T1 = G(u32, self + 0x1201), T2 = G(u32, self + 0x1205);
      u32 off = G(u32, T1 + ebx * 8 + 4), n = G(u32, T1 + ebx * 8);
      u32 lst = T2 + off * 4;
      bool fail = esi > (G(u16, lst + n * 4 - 2) & 0x3fffu);
      if (!fail && esi < (G(u16, lst + 2) & 0x3fffu)) fail = true;
      if (fail) {
        if ((flag & 0xff) == 0) { ext_633654(G(u32, 0x6f5630)); return res; }
        u32 E = G(u32, 0x700390);
        u32 R = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(G(u32, E) + 0x20)))(E, 0x6a2b84, 0x62d);
        ((u32(*)(u32, u32, u32, u32))(*(u32 *)(G(u32, R) + 0x2c)))(R, 0x6a2bf0, ebx, esi);
        ext_633654(G(u32, 0x6f5630));
        return 0;
      }
      if (flag & 0xff) {
        u32 E = G(u32, 0x700390);
        u32 R = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(G(u32, E) + 0x20)))(E, 0x6a2b84, 0x637);
        ((u32(*)(u32, u32, u32, u32))(*(u32 *)(G(u32, R) + 0x2c)))(R, 0x6a2c04, ebx, esi);
        ext_633654(G(u32, 0x6f5630));
        return 1;
      }
      bool found = false; u32 v = 0;
      for (u32 k = 0; k < n; k++) {
        v = G(u32, lst + k * 4);
        if (esi == ((v >> 16) & 0x3fffu)) { found = true; break; }
      }
      if (found) {
        u32 edi = v & 0xffffu, t = v >> 30;
        u32 Fp = G(u32, self + 0x11f9);
        if (t == 0) {
          float f = G(float, Fp + edi * 0xa4 + 8);
          if (f != 0.0f) res = 1;
          idx += 2;
        } else if (t == 1) {
          u32 M = G(u32, self + 0x11fd);
          u32 e3 = edi * 3;
          bool cl = false;
          if (G(float, Fp + G(u32, M + e3 * 4) * 0xa4 + 8) != 0.0f) cl = G(float, Fp + G(u32, M + e3 * 4 + 4) * 0xa4 + 8) != 0.0f;
          if (cl) res = 1;
          idx += 2;
        } else if (t == 2) {
          cnt = 3; idx = 0; W[0] = edi; W[1] = ebx; W[2] = edi; W[3] = esi;
        } else {
          u32 hook = G(u32, 0x7003b0);
          if (hook) ((u32(*)())hook)(); else __builtin_trap();
        }
      }
    }
    cnt--;
  } while (cnt != 0);
  ext_633654(G(u32, 0x6f5630));
  return res;
}
PCREG(53ca50, lifted_53ca50);

// 0x421240: thiscall(this, out) ret 4, returns out (eax). Hand port (lifter: `sbb edx, [ebp-8]`). Frame timer update with SSE doubles:
// clock() * 0.001 -> this[0xc] (as float rounded double); this[0x24] = this[0x1c]; delta = new - old as float -> this[0x20]; this[4] += delta;
// this[0x1c] = (int)(this[4] * 1024); the 64-bit tick at this[0x23c6] comes from QueryPerformanceCounter (flag this[0x1e90]) or from engine slot +0x1c8 (edx:eax);
// unless this[0x25e8] is set the smoothed value this[0x23ce] (0.3 / 0.7 blend, clamped through minsd) and this[0x34] / this[0x14] / this[0x30] are updated;
// finally nine registration calls vslot +0x1fc(this, ptr, size, id, file 0x677fb4, line) and *out = this[0x30].
#define IAT_clock() (((s32(*)())(*(u32 *)0x676434))())
#define IAT_qpc(p) (((u32(STDCALL *)(u32))(*(u32 *)0x6760e0))(p))
static inline double i64_to_double(u32 lo, u32 hi) {   // 0x633c60: (double)(s32)lo + [0x6c1610 + (lo >> 31) * 8] + (double)(s32)hi * [0x6c1618]
  double a = (double)(s32)lo;
  a += G(double, 0x6c1610 + (lo >> 31) * 8);
  double b = (double)(s32)hi * G(double, 0x6c1618);
  return a + b;
}
static inline double minsd(double dst, double src) { return dst < src ? dst : src; }
extern "C" u32 THISCALL lifted_421240(u32 self, u32 out) {
  double old = G(double, self + 0xc);
  s32 ck = IAT_clock();
  double x1 = (double)ck * G(double, 0x6785e8);
  G(double, self + 0xc) = (double)(float)x1;
  G(u32, self + 0x24) = G(u32, self + 0x1c);
  u8 flag = G(u8, self + 0x1e90);
  u32 esi = self + 0x23c6;
  float f = (float)(x1 - old);
  G(float, self + 0x20) = f;
  double d4 = (double)f + G(double, self + 4);
  G(double, self + 4) = d4;
  G(s32, self + 0x1c) = (s32)(d4 * G(double, 0x678618));
  u32 old_lo = G(u32, esi), old_hi = G(u32, esi + 4);
  if (flag != 0) {
    u32 qpc[2];
    u32 r = IAT_qpc((u32)qpc);
    G(u8, self + 0x1e90) = r != 0;
    G(u32, esi) = qpc[0]; G(u32, esi + 4) = qpc[1];
  } else {
    u32 gg = G(u32, 0x70039c);
    u64 v = ((u64(THISCALL *)(u32, u32, u32))(*(u32 *)(G(u32, gg) + 0x1c8)))(gg, 0x677fb4, 0x967);
    G(u32, esi) = (u32)v; G(u32, esi + 4) = (u32)(v >> 32);
  }
  if (G(u8, self + 0x25e8) == 0) {
    double acc;
    if (G(u8, self + 0x1b5c) != 0) {
      float r = G(float, self + 0x1b40) * G(float, self + 0x20);
      G(float, self + 0x34) = r;
      acc = (double)r;
    } else {
      u32 lo = G(u32, esi) - old_lo; u32 borrow = G(u32, esi) < old_lo; u32 hi = G(u32, esi + 4) - old_hi - borrow;
      double dd = i64_to_double(lo, hi);
      float q = (float)dd / G(float, self + 0x58);
      double xm1 = minsd(G(double, 0x678610), (double)q);
      if (G(double, self + 0x23ce) == 0.0) G(double, self + 0x23ce) = xm1;
      double cur = G(double, self + 0x23ce);
      double x1b = xm1 * G(double, 0x678600);
      double x0 = cur * G(double, 0x678608);
      x0 = x0 + x1b;
      double m = minsd(G(double, 0x6785f8), x0);
      G(double, self + 0x23ce) = x0;
      m = m * (double)G(float, self + 0x1b40);
      float f2 = (float)m;
      G(float, self + 0x34) = f2;
      acc = (double)f2;
    }
    acc = acc + G(double, self + 0x14);
    G(double, self + 0x14) = acc;
    G(s32, self + 0x30) = (s32)(acc * G(double, 0x678618));
  }
  G(u8, self + 0x25e8) = 0;
  typedef u32 (THISCALL *REG)(u32, u32, u32, u32, u32, u32);
#define REGCALL(ptr, size, id, line) ((REG)(*(u32 *)(G(u32, self) + 0x1fc)))(self, (ptr), (size), (id), 0x677fb4, (line))
  REGCALL(self + 0xc, 8, 6, 0x984);
  REGCALL(self + 0x24, 4, 7, 0x985);
  REGCALL(self + 0x20, 4, 8, 0x986);
  REGCALL(self + 0x1c, 4, 9, 0x987);
  REGCALL(self + 0x1e90, 1, 0xa, 0x989);
  REGCALL(self + 0x23c6, 8, 0xb, 0x98a);
  REGCALL(self + 0x23ce, 8, 0xc, 0x98c);
  REGCALL(self + 0x34, 4, 0xd, 0x98d);
  REGCALL(self + 0x30, 4, 0xe, 0x98e);
  G(u32, out) = G(u32, self + 0x30);
  return out;
}
PCREG(421240, lifted_421240);

// 0x60cf30: thiscall(this) plain ret, returns the tail call's eax on the reset paths (junk otherwise: the spec ignores eax). Hand port
// (lifter: SSE prologue). Display device loss / reset handler: optionally logs the engine's timing floats, tests the device
// (slot +0x3c(D, 0, 0, 0, 0)), on DEVICELOST (0x88760868) / NOTRESET (0x88760869) runs the reset sequence and logs every step through engine B.
extern "C" u32 THISCALL ext_60d610_thiscall1(u32) __asm__("ext_60d610");
extern "C" u32 THISCALL ext_608330_thiscall1(u32) __asm__("ext_608330");
#define LOG_B(line, fmt) do { u32 Eb = G(u32, 0x700390); u32 Rb = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(G(u32, Eb) + 0x20)))(Eb, 0x6bcb80, (line)); \
  ((u32(*)(u32, u32))(*(u32 *)(G(u32, Rb) + 0x2c)))(Rb, (fmt)); } while (0)
static inline void log_timing(u32 slot, u32 line) {
  u32 A = G(u32, 0x70039c);
  if (G(float, A + 0x9c7) != 0.0f && G(float, A + 0x9c3) != 0.0f) {
    u64 v = ((u64(THISCALL *)(u32, u32, u32))(*(u32 *)(G(u32, A) + 0x1c8)))(A, 0x67a7f8, line);
    u32 A2 = G(u32, 0x70039c);
    ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(G(u32, A2) + slot)))(A2, (u32)v, (u32)(v >> 32), 0x6bd474);
  }
}
extern "C" u32 THISCALL lifted_60cf30(u32 self) {
  log_timing(0x178, 0x259);
  u32 D = G(u32, self + 0x1377);
  u32 r = ((u32(STDCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(G(u32, D) + 0x3c)))(D, 0, 0, 0, 0);
  log_timing(0x17c, 0x260);
  if (r == 0x88760868u) {
    G(u8, 0x724b34) = 1;
    LOG_B(0x765, 0x6bd47c);
    D = G(u32, self + 0x1377);
    if (((u32(STDCALL *)(u32))(*(u32 *)(G(u32, D) + 0xc)))(D) == 0x88760869u) {
      LOG_B(0x767, 0x6bd488);
      ext_60d610_thiscall1(self);
      D = G(u32, self + 0x1377);
      u32 q = ((u32(STDCALL *)(u32, u32))(*(u32 *)(G(u32, D) + 0x38)))(D, self + 0x137b);
      if (q != 0) {
        LOG_B(0x770, 0x6bd4a8);
      } else {
        LOG_B(0x76b, 0x6bd49c);
        ext_608330_thiscall1(self);
        u32 H = G(u32, self + 0xbd);
        ((u32(THISCALL *)(u32))(*(u32 *)(G(u32, H) + 0x64)))(H);
        G(u8, 0x724b34) = 0;
      }
    }
  }
  if (G(u8, self + 0x13f1) == 0) return 0;
  G(u8, self + 0x13f1) = 0;
  ext_60d610_thiscall1(self);
  D = G(u32, self + 0x1377);
  u32 esi = self + 0x13af;
  u32 q2 = ((u32(STDCALL *)(u32, u32))(*(u32 *)(G(u32, D) + 0x38)))(D, esi);
  if (q2 != 0) {
    LOG_B(0x794, 0x6bd4b8);
    D = G(u32, self + 0x1377);
    ((u32(STDCALL *)(u32, u32))(*(u32 *)(G(u32, D) + 0x38)))(D, self + 0x137b);
  } else {
    LOG_B(0x797, 0x6bd4f0);
    u32 t[13];
    for (u32 i = 0; i < 13; i++) t[i] = G(u32, esi + 4 * i);
    for (u32 i = 0; i < 12; i++) G(u32, self + 0x137b + 4 * i) = t[i];
    G(u32, self + 0x13ab) = t[12];
  }
  ext_608330_thiscall1(self);
  u32 H = G(u32, self + 0xbd);
  return ((u32(THISCALL *)(u32))(*(u32 *)(G(u32, H) + 0x64)))(H);
}
PCREG(60cf30, lifted_60cf30);

// 0x4261c0: stdcall(dest, format, args) ret 0xc -> number of characters written. Hand port (lifter: `dst esp`; jump table + _alloca).
// A printf wrapper with a vector conversion: `%[rows.]colsv` (rows default 1, cols default 3, a single number is the column count) prints
// rows x cols floats from a float pointer taken from the argument array as "[% 8f,% 8f,...]". Everything before a `v` conversion is first
// formatted by the CRT (0x42abee vsprintf on a stack copy of the literal segment), the argument cursor advancing 4 bytes per ordinary conversion,
// 8 per `f` (counted twice) and 4 for the vector pointer; `%%` is skipped, flags / other letters end the conversion parse (each counted once).
extern "C" u32 ext_42abee_cdecl(...) __asm__("ext_42abee");
extern "C" u32 ext_42ac56_cdecl(...) __asm__("ext_42ac56");
extern "C" u32 ext_634d22_cdecl(...) __asm__("ext_634d22");
extern "C" u32 STDCALL lifted_4261c0(u32 dest0, u32 fmt, u32 args) {
  u32 dest = dest0, p = fmt, seg = fmt, nf = 0, argp = args;
  while (G(u8, p) != 0) {
    if (G(u8, p) != 0x25) { p++; continue; }
    u32 sp = p + 1;
    if (G(u8, sp) == 0x25) { p += 2; continue; }
    bool dot = false; s32 n1 = 0, n2 = 0; bool vec = false;
    for (;;) {
      s32 ch = (s32)(s8)G(u8, sp);
      u32 idx = (u32)(ch - 0x2e);
      u32 cls = idx > 0x48 ? 4 : G(u8, 0x4263bc + idx);
      u8 al = 0;
      if (cls == 0) {
        if (!dot) { dot = true; al = 1; }
      } else if (cls == 1) {
        if (dot) n1 = ch + (n1 * 5 - 0x18) * 2; else n2 = ch + (n2 * 5 - 0x18) * 2;
        al = 1;
      } else if (cls == 2) {
        nf++;
      } else if (cls == 3) {
        vec = true; break;
      }
      sp++;
      if (!al) break;
    }
    if (!vec) { nf++; p++; continue; }
    if (dot) { s32 t = n2; n2 = n1; n1 = t; }   // [-0x10] = rows, [-0xc] = cols
    s32 rows = n1 != 0 ? n1 : 1, cols = n2 != 0 ? n2 : 3;
    u32 len = p - seg;
    u8 *buf = (u8 *)__builtin_alloca(len + 1);
    ext_634d22_cdecl(buf, seg, len);
    buf[len] = 0;
    dest += ext_42abee_cdecl(dest, (u32)buf, argp);
    argp = argp + nf * 4 + 4;
    u32 vp = G(u32, argp - 4);
    if (rows > 0) {
      do {
        G(u8, dest) = 0x5b; dest++;
        s32 c = cols;
        if (c > 0) {
          do {
            dest += ext_42ac56_cdecl(dest, 0x678704, (double)G(float, vp));
            vp += 4;
            if (c > 1) { G(u8, dest) = 0x2c; dest++; }
            c--;
          } while (c > 0);
        }
        G(u8, dest) = 0x5d; dest++;
        rows--;
      } while (rows > 0);
    }
    G(u8, dest) = 0;
    seg = sp + 1;
    p = sp + 1;
    nf = 0;
  }
  u32 n = ext_42abee_cdecl(dest, seg, argp);
  ext_633654(G(u32, 0x6f5630));
  return n + (dest - dest0);
}
PCREG(4261c0, lifted_4261c0);

// 0x61aed0: stdcall(src, count, flags) ret 0xc, void (eax junk). Hand port (lifter: MMX `pxor mm7`). Transposes vertices (0x24 bytes each, four per
// pass, pass stride 0x90) into the fixed SoA buffer 0x812a40 (arrays of 4 floats, 0x80 apart, + 0x10 per pass): floats at vertex +0 / +4 -> 0x000 / 0x080,
// +8 / +0xc -> 0x100 / 0x180, +0x10 / +0x14 -> 0x200 / 0x280; the four colour bytes at +0x18 as floats times a constant vector (0x6bde30, or 0x6bde50 when
// bit 0x2000 of flags is clear): b3 -> 0x300, b2 -> 0x380, b1 -> 0x400, b0 -> 0x480; with the flag a second constant vector (0x6bde40) minus b3 * k goes to
// 0x500 / 0x580 / 0x600; without the flag the 0x180 bytes at 0x812f40 are cleared afterwards (memset 0x634d10).
extern "C" u32 ext_634d10b_cdecl(...) __asm__("ext_634d10");
extern "C" void STDCALL lifted_61aed0(u32 src, u32 count, u32 flags) {
  u32 dst = 0x812a40;
  bool fl = (flags & 0x2000) != 0;
  u32 kaddr = fl ? 0x6bde30 : 0x6bde50;
  u32 it = (count + 3) >> 2;
  do {
    u32 v[4] = {src, src + 0x24, src + 0x48, src + 0x6c};
    static const u32 foff[3] = {0, 8, 0x10};
    for (u32 g = 0; g < 3; g++)
      for (u32 j = 0; j < 4; j++) {
        G(u32, dst + g * 0x100 + 0x10 * 0 + j * 4) = G(u32, v[j] + foff[g]);
        G(u32, dst + g * 0x100 + 0x80 + j * 4) = G(u32, v[j] + foff[g] + 4);
      }
    for (u32 j = 0; j < 4; j++) {
      u32 w = G(u32, v[j] + 0x18);
      float b0 = (float)(w & 0xff), b1 = (float)((w >> 8) & 0xff), b2 = (float)((w >> 16) & 0xff), b3 = (float)(w >> 24);
      float k = G(float, kaddr + 4 * j);
      G(float, dst + 0x300 + j * 4) = b3 * k;
      G(float, dst + 0x380 + j * 4) = b2 * k;
      G(float, dst + 0x400 + j * 4) = b1 * k;
      G(float, dst + 0x480 + j * 4) = b0 * k;
      if (fl) {
        float r = G(float, 0x6bde40 + 4 * j) - b3 * k;
        G(float, dst + 0x500 + j * 4) = r; G(float, dst + 0x580 + j * 4) = r; G(float, dst + 0x600 + j * 4) = r;
      }
    }
    src += 0x90; dst += 0x10;
    it--;
  } while (it != 0);
  if (!fl) ext_634d10b_cdecl(0x812f40, 0, 0x180);
}
PCREG(61aed0, lifted_61aed0);

// 0x661370: stdcall(hit, node, org, dir, flag, mask) ret 0x18 -> al. Hand port (lifter: `lift: ch`, 8-bit ch register). Ray vs a mesh made of a chain
// of nodes (engine[+0x1aa3][+0x20] = base; node = base + offset; next offset at node +8, mask at +0x2c, strip data at +0x3c, vertices (36 bytes) at +0x14):
// for every node whose mask & `mask` is set and every strip {n, n indices}, each triangle (i, i+1, i+2) with alternating winding is tested by 0x4e2560
// (this = org, edx = dir, vertices, &t, flag); the hit with 0 <= t < hit[0] and t <= 1.0 is stored (hit[0] = t, the three vertices at +0x14 / +0x20 / +0x2c,
// triangle number at +0x38); after a strip with a hit 0x443ef0(hit + 4, org, dir, t) fills the hit point, hit[0x40] = hit[0x44] = 0 and the result is 1.
extern "C" u32 FASTCALL ext_443ef0_fastcall4b(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_4e2560_fastcall7b(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_4e2560");
extern "C" u32 STDCALL lifted_661370(u32 hit, u32 node_off, u32 org, u32 dir, u32 flag, u32 mask) {
  u32 base = G(u32, G(u32, 0x70039c) + 0x1aa3);
  base = G(u32, base + 0x20);
  u8 result = 0;
  u32 off = node_off;
  while (off != 0) {
    u32 node = base + off;
    if (G(u32, node + 0x2c) & mask) {
      u32 P = G(u32, node + 0x3c) + base;
      u32 V = G(u32, node + 0x14) + base;
      u32 strips = G(u16, P); P += 2;
      while (strips != 0) {
        u32 n = G(u16, P); P += 2;
        u32 Pn = P;
        bool hitflag = false, flip = false;
        u32 i = 0;
        if (n - 2 != 0) {
          u32 esi = P + 4;
          do {
            u32 ia = G(u16, esi - 4), ib = G(u16, esi - 2), ic = G(u16, esi);
            u32 va = V + ia * 36, vb = V + ib * 36, vc = V + ic * 36;
            float t = 0;
            u32 r;
            if (flip) r = ext_4e2560_fastcall7b(org, dir, va, vc, vb, (u32)&t, flag);
            else r = ext_4e2560_fastcall7b(org, dir, va, vb, vc, (u32)&t, flag);
            if ((r & 0xff) != 0 && !(t < 0.0f) && (G(float, hit) > t) && !(1.0f < t)) {
              G(float, hit) = t;
              u32 v1 = flip ? vc : vb, v2 = flip ? vb : vc;
              for (u32 k = 0; k < 3; k++) {
                G(u32, hit + 0x14 + 4 * k) = G(u32, va + 4 * k);
                G(u32, hit + 0x20 + 4 * k) = G(u32, v1 + 4 * k);
                G(u32, hit + 0x2c + 4 * k) = G(u32, v2 + 4 * k);
              }
              G(u32, hit + 0x38) = i;
              hitflag = true;
            }
            i++; flip = !flip; esi += 2;
          } while (i < n - 2);
          if (hitflag) {
            float bt = G(float, hit);
            ext_443ef0_fastcall4b(hit + 4, org, dir, *(u32 *)&bt);
            G(u32, hit + 0x40) = 0; G(u32, hit + 0x44) = 0;
            result = 1;
          }
        }
        strips--;
        P = Pn + n * 2;
      }
    }
    off = G(u32, node + 8);
  }
  return result;
}
PCREG(661370, lifted_661370);

// 0x4235b0: thiscall(this, out, size, index, name, unused) ret 0x14 -> bytes consumed so far (0 on failure / done). Hand port (lifter: `lift: esp`, rep movsd vararg block).
// Streaming reader of a packed resource file: on the first call the file named by the string object this + 0x255b is sized and read through engine object
// [0x700394] (slot +0x30 size, slot +0x60 read), then each call decodes the next RLE chunk (real 0x4247e0) into a temporary, ADDS it bytewise to the per-index
// record buffer this[0x25eb + index * 8] (allocated size + 0x1c bytes, zeroed), checks the record header (index, size, the last <= 15 characters of `name`
// compared with _stricmp against the record text) and copies size bytes from record + 0x1c to out. Any failure sets the flag byte this[0x1b3f]
// (error log through engine B [0x700390] slot +0x20 -> slot +0x2c cdecl with the 0x80-byte string object by value when the file size is <= 0).
extern "C" u32 THISCALL ext_4cc5f0_t1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4cc1d0_t1(u32) __asm__("ext_4cc1d0");
extern "C" u32 ext_41e290_c1(...) __asm__("ext_41e290");
extern "C" u32 ext_634d10_c3(...) __asm__("ext_634d10");
extern "C" u32 ext_634d22_c3(...) __asm__("ext_634d22");
extern "C" u32 ext_634273_c2(...) __asm__("ext_634273");
extern "C" u32 THISCALL ext_4247e0_t5(u32, u32, u32, u32, u32) __asm__("ext_4247e0");
struct Blob128 { u32 w[32]; };
extern "C" u32 THISCALL lifted_4235b0(u32 self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4_unused) {
  if (G(u8, self + 0x1b3f) != 0) return 0;
  u32 S = self + 0x255b;
  if (ext_4cc5f0_t1(S) == 0) return 0;
  if (G(u32, self + 0x25dc) == 0) {
    u32 gg = G(u32, 0x700394);
    u32 cs = ext_4cc1d0_t1(S);
    u32 size = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(G(u32, gg) + 0x30)))(gg, cs, 0);
    G(u32, self + 0x25e4) = size;
    if ((s32)size <= 0) {
      u32 E = G(u32, 0x700390);
      u32 R = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(G(u32, E) + 0x20)))(E, 0x677fb4, 0xbc4);
      Blob128 b; for (u32 i = 0; i < 32; i++) b.w[i] = G(u32, S + 4 * i);
      ((u32(*)(u32, u32, Blob128))(*(u32 *)(G(u32, R) + 0x2c)))(R, 0x678508, b);
      G(u8, self + 0x1b3f) = 1;
      return 0;
    }
    u32 buf = ext_41e290_c1(size);
    G(u32, self + 0x25dc) = buf; G(u32, self + 0x25e0) = buf;
    u32 g2 = G(u32, 0x700394);
    u32 cs2 = ext_4cc1d0_t1(S);
    ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(G(u32, g2) + 0x60)))(g2, cs2, buf, G(u32, self + 0x25e4), 0, 0);
  }
  if ((s32)(G(u32, self + 0x25e0) - G(u32, self + 0x25dc)) >= (s32)G(u32, self + 0x25e4)) { G(u8, self + 0x1b3f) = 1; return 0; }
  u32 ent = self + a2 * 8;
  bool skip = false;
  if (G(u32, ent + 0x25eb) == 0) {
    u32 len = a1 + 0x1c;
    u32 p = ext_41e290_c1(len);
    ext_634d10_c3(p, 0, len);
    G(u32, ent + 0x25eb) = p; G(u32, ent + 0x25ef) = len;
    if (p == 0) skip = true;
  }
  if (!skip) {
    u32 el = G(u32, ent + 0x25ef);
    u32 cur = G(u32, self + 0x25e0);
    u32 chunk = G(u32, cur);
    cur += 4; G(u32, self + 0x25e0) = cur;
    u32 tmp = ext_41e290_c1(el);
    u32 dummy = 0;
    ext_4247e0_t5((u32)&dummy, tmp, tmp + el, G(u32, self + 0x25e0), chunk + G(u32, self + 0x25e0));
    for (u32 i = 0; i < el; i++) G(u8, G(u32, ent + 0x25eb) + i) = (u8)(G(u8, G(u32, ent + 0x25eb) + i) + G(u8, tmp + i));
    ext_634273_c2(tmp, 1);
    G(u32, self + 0x25e0) += chunk;
  }
  u32 rec = G(u32, ent + 0x25eb);
  u32 id = G(u32, rec), sz = G(u32, rec + 4);
  rec += 8;
  u32 name16[4] = {0, 0, 0, 0};
  u32 n = 0; while (G(u8, a3 + n) != 0) n++;
  u32 m = n > 0xf ? 0xf : n;
  ext_634d22_c3((u32)name16, a3 + (n - m), m + 1);
  if (a2 != id || a1 != sz) { G(u8, self + 0x1b3f) = 1; return 0; }
  if (((s32(*)(u32, u32))(*(u32 *)0x676414))((u32)name16, rec) != 0) { G(u8, self + 0x1b3f) = 1; return 0; }
  ext_634d22_c3(a0, rec + 0x14, a1);
  ext_633654(G(u32, 0x6f5630));
  return G(u32, self + 0x25e0) - G(u32, self + 0x25dc);
}
PCREG(4235b0, lifted_4235b0);

// (the CRT thunks 0x634cec / 0x634cfe / 0x634d04 / 0x634cf8 are stdcall: no `add esp` after them)
// 0x612e70: thiscall(this, image, a1) ret 8, SEH3 (handler 0x66e370; try level 0 after the CRT context, 1 once the surface object exists). Hand port
// (lifter: `rep stosd`). Looks the image's name (image slot +4) up in the 19-entry table this + 0x2203c (16 bytes each: name, arg, x, y offsets, case
// sensitive compare); not found: 0x6130c0(this, image, a1). Found: one-time CRT init 0x634cec (when [0x724b70] == 0), context ctx via 0x634cfe(entry[1], &ctx),
// width / height from image slots +0x1c / +0x20, a width * height pixel buffer (0x41e290, filled with 0xff000000), every pixel from 0x634d04(ctx, x0 + col,
// y0 + row, &pixel) (a non-zero result is kept as the error and the pixel left), a surface object L built by 0x636020(L, buf, w, h, 0xff0000, 0xff00, 0xff, 0xff000000, 0),
// L + 0x1c = image slot +0x50, 0x639d00(L, image slot +4), L + 0x20 = image slot +0x48, free the buffer (0x41e2c0), 0x6130c0(this, L, a1), destroy L (0x6363a0),
// release the context (0x634cf8) whose result is returned.
extern "C" u32 THISCALL ext_6130c0_t3(u32, u32, u32) __asm__("ext_6130c0");
extern "C" u32 THISCALL ext_636020_t9(u32, u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_636020");
extern "C" u32 THISCALL ext_639d00_t2(u32, u32) __asm__("ext_639d00");
extern "C" u32 THISCALL ext_6363a0_t1b(u32) __asm__("ext_6363a0");
extern "C" u32 STDCALL ext_634cec_c(u32, u32, u32) __asm__("ext_634cec");
extern "C" u32 STDCALL ext_634cfe_c(u32, u32) __asm__("ext_634cfe");
extern "C" u32 STDCALL ext_634d04_c(u32, u32, u32, u32) __asm__("ext_634d04");
extern "C" u32 STDCALL ext_634cf8_c(u32) __asm__("ext_634cf8");
extern "C" u32 ext_41e290_d(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_d(...) __asm__("ext_41e2c0");
extern "C" u32 THISCALL lifted_612e70(u32 self, u32 I, u32 a1) {
  SEH_ENTER(0x66e370);
  u8 F[0x400] __attribute__((aligned(4)));
  u32 L = (u32)(F + 0x300 - 0x40);
  u32 ebx = self + 0x2203c, edi = ebx + 0x130;
  for (; ebx != edi; ebx += 0x10) {
    u32 p = ((u32(THISCALL *)(u32))(*(u32 *)(G(u32, I) + 4)))(I);
    u32 q = G(u32, ebx);
    bool eq = true;
    for (;;) { u8 c = G(u8, p), d = G(u8, q); if (c != d) { eq = false; break; } if (c == 0) break; p++; q++; }
    if (eq) goto found;
  }
  {
    u32 r = ext_6130c0_t3(self, I, a1);
    SEH_LEAVE();
    ext_633654(G(u32, 0x6f5630));
    return r;
  }
found:
  if (G(u32, 0x724b70) == 0) ext_634cec_c(0x724b70, 0x6efd04, 0);
  u32 ctx = 0;
  ext_634cfe_c(G(u32, ebx + 4), (u32)&ctx);
  reg.state = 0;
  u32 width = ((u32(THISCALL *)(u32))(*(u32 *)(G(u32, I) + 0x1c)))(I);
  u32 height = ((u32(THISCALL *)(u32))(*(u32 *)(G(u32, I) + 0x20)))(I);
  u32 n = height * width;
  u64 n4 = (u64)n * 4;
  u32 buf = ext_41e290_d(n4 > 0xffffffffull ? 0xffffffffu : (u32)n4);
  if (buf != 0 && n != 0) for (u32 i = 0; i < n; i++) G(u32, buf + 4 * i) = 0xff000000;
  if ((s32)height > 0) {
    u32 rowp = buf;
    for (s32 row = 0; row < (s32)height; row++) {
      if ((s32)width > 0) {
        u32 p = rowp;
        for (s32 col = 0; col < (s32)width; col++) {
          u32 pixel = 0;
          u32 r = ext_634d04_c(ctx, G(u32, ebx + 8) + (u32)col, G(u32, ebx + 0xc) + (u32)row, (u32)&pixel);
          if (r == 0) G(u32, p) = pixel;
          p += 4;
        }
      }
      rowp += width * 4;
    }
  }
  ext_636020_t9(L, buf, width, height, 0xff0000, 0xff00, 0xff, 0xff000000, 0);
  reg.state = 1;
  G(u32, L + 0x1c) = ((u32(THISCALL *)(u32))(*(u32 *)(G(u32, I) + 0x50)))(I);
  u32 nm = ((u32(THISCALL *)(u32))(*(u32 *)(G(u32, I) + 4)))(I);
  ext_639d00_t2(L, nm);
  G(u32, L + 0x20) = ((u32(THISCALL *)(u32))(*(u32 *)(G(u32, I) + 0x48)))(I);
  ext_41e2c0_d(buf);
  ext_6130c0_t3(self, L, a1);
  ext_6363a0_t1b(L);
  u32 ret = ext_634cf8_c(ctx);
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(612e70, lifted_612e70);

// 0x424130: thiscall(this) plain ret -> al (1 success / 0 early failure), SEH3 (handler 0x664470, try level 0 around the temporary string, 1 around the
// 0x5328b0 construction). Hand port (lifter: `rep movsd` vararg block). Application / world initialisation sequence: logs the 0x80-byte string object
// at this + 0x1997 through engine B ([0x700390] slot +0x20 -> slot +0x2c), loads it through this-slot +0x6c (failure: log + return 0), slot +0x58, optionally
// (this[0x25e9]) stamps the engine log with the date (_time32 / _ctime32 / sprintf 0x42ac56 -> engine [0x700394] slot +0x18 / +0x68), stores the string from this-slot +0x148
// into this + 0x2a3, runs slots +0x16c / +0x170 / +0xc0 / +0xbc, tells the returned object (slot +0xd8) whether this[0x6f] * 3 > this[0x73] * 4, creates the
// 0x48a440 object (this[0x223d], AddRef slot +0xc), compares the string at this + 0x1e91 with 0x677f44 (_stricmp: equal -> this[0x1aa3] = 0x607c20()), AddRefs and
// reports a missing this[0x1aa3] through engine B slot +0x24, constructs the 0x548e byte object (0x41e290 + 0x5328b0) into this[0x1a9f], AddRefs the
// globals / sub objects (this[0x9b] slot +0x11c, this slot +0x16c, [[0x70039c] + 0x190f] slot +0x23c) and returns 1.
extern "C" u32 THISCALL ext_4cbee0_t2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cbec0_t1(u32) __asm__("ext_4cbec0");
extern "C" u32 ext_48a440_t0() __asm__("ext_48a440");
extern "C" u32 ext_607c20_t0() __asm__("ext_607c20");
extern "C" u32 THISCALL ext_5328b0_t1(u32) __asm__("ext_5328b0");
extern "C" u32 ext_42ac56_d(...) __asm__("ext_42ac56");
#define VS(obj, off) (*(u32 *)(G(u32, (obj)) + (off)))
#define LOG2B(line, fmt) do { u32 Eb = G(u32, 0x700390); u32 Rb = ((u32(THISCALL *)(u32, u32, u32))VS(Eb, 0x20))(Eb, 0x677fb4, (line)); \
  ((u32(*)(u32, u32))VS(Rb, 0x2c))(Rb, (fmt)); } while (0)
extern "C" u32 THISCALL lifted_424130(u32 self) {
  SEH_ENTER(0x664470);
  u8 F[0x400] __attribute__((aligned(4)));
  u32 tmpstr = (u32)(F + 0x300 - 0x290), buf294 = (u32)(F + 0x300 - 0x294), buf210 = (u32)(F + 0x300 - 0x210);
  u32 result = 1;
  {
    u32 E = G(u32, 0x700390);
    u32 R = ((u32(THISCALL *)(u32, u32, u32))VS(E, 0x20))(E, 0x677fb4, 0x631);
    Blob128 b; for (u32 i = 0; i < 32; i++) b.w[i] = G(u32, self + 0x1997 + 4 * i);
    ((u32(*)(u32, u32, Blob128))VS(R, 0x2c))(R, 0x6780c4, b);
  }
  {
    u32 cs = ext_4cc1d0_t1(self + 0x1997);
    u32 ok = ((u32(THISCALL *)(u32, u32))VS(self, 0x6c))(self, cs);
    if ((ok & 0xff) == 0) {
      LOG2B(0x635, 0x6780e8);
      result = 0;
      goto done;
    }
  }
  ((u32(THISCALL *)(u32))VS(self, 0x58))(self);
  if (G(u8, self + 0x25e9) != 0) {
    G(u32, self + 0x23d6) = 0x4245d0;
    u32 gg = G(u32, 0x700394);
    u32 cs2 = ext_4cc1d0_t1(self + 0x2242);
    ((u32(THISCALL *)(u32, u32))VS(gg, 0x18))(gg, cs2);
    ((u32(*)(u32))(*(u32 *)0x676438))(buf294);
    u32 tv = ((u32(*)(u32))(*(u32 *)0x676440))(buf294);
    ext_42ac56_d(buf210, 0x67810c, tv);
    u32 len = 0; while (G(u8, buf210 + len) != 0) len++;
    u32 g2 = G(u32, 0x700394);
    u32 cs3 = ext_4cc1d0_t1(self + 0x2242);
    ((u32(THISCALL *)(u32, u32, u32, u32))VS(g2, 0x68))(g2, cs3, buf210, len);
  }
  {
    u32 cs4 = ext_4cc1d0_t1(self + 0x2a3);
    u32 sv = ((u32(THISCALL *)(u32, u32, u32))VS(self, 0x148))(self, tmpstr, cs4);
    reg.state = 0;
    ext_4cbee0_t2(self + 0x2a3, sv);
    reg.state = -1;
    ext_4cbec0_t1(tmpstr);
  }
  ((u32(THISCALL *)(u32))VS(self, 0x16c))(self);
  ((u32(THISCALL *)(u32))VS(self, 0x170))(self);
  ((u32(THISCALL *)(u32))VS(self, 0xc0))(self);
  {
    u32 O = ((u32(THISCALL *)(u32))VS(self, 0xbc))(self);
    s32 a = (s32)(G(u32, self + 0x6f) * 3), b = (s32)(G(u32, self + 0x73) << 2);
    ((u32(THISCALL *)(u32, u32))VS(O, 0xd8))(O, a > b ? 1 : 0);
  }
  {
    u32 o = ext_48a440_t0();
    G(u32, self + 0x223d) = o;
    if (o != 0) ((u32(THISCALL *)(u32))VS(o, 0xc))(o);
  }
  {
    u32 cs5 = ext_4cc1d0_t1(self + 0x1e91);
    if (((s32(*)(u32, u32))(*(u32 *)0x676414))(cs5, 0x677f44) == 0) G(u32, self + 0x1aa3) = ext_607c20_t0();
  }
  {
    u32 a2 = G(u32, self + 0x1aa3);
    if (a2 != 0) ((u32(THISCALL *)(u32))VS(a2, 0xc))(a2);
  }
  if (G(u32, self + 0x1aa3) == 0) {
    u32 cs6 = ext_4cc1d0_t1(self + 0x1e91);
    u32 E = G(u32, 0x700390);
    if (G(u8, cs6) == 0) {
      ((u32(*)(u32, u32))VS(E, 0x24))(E, 0x678128);
    } else {
      u32 cs7 = ext_4cc1d0_t1(self + 0x1e91);
      ((u32(*)(u32, u32, u32))VS(E, 0x24))(E, 0x678154, cs7);
    }
  }
  G(u32, self + 0x1a9f) = 0;
  {
    u32 p = ext_41e290_c1(0x548e);
    reg.state = 1;
    u32 o3 = 0;
    if (p != 0) o3 = ext_5328b0_t1(p);
    reg.state = -1;
    G(u32, self + 0x1a9f) = o3;
    if (o3 != 0) ((u32(THISCALL *)(u32))VS(o3, 0xc))(o3);
  }
  {
    u32 a4 = G(u32, 0x7003a0);
    if (a4 != 0) ((u32(THISCALL *)(u32))VS(a4, 0xc))(a4);
  }
  {
    u32 a5 = G(u32, self + 0x9b);
    ((u32(THISCALL *)(u32))VS(a5, 0x11c))(a5);
  }
  ((u32(THISCALL *)(u32))VS(self, 0x16c))(self);
  {
    u32 a6 = G(u32, G(u32, 0x70039c) + 0x190f);
    if (a6 != 0) ((u32(THISCALL *)(u32))VS(a6, 0x23c))(a6);
  }
done:
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return result;
}
PCREG(424130, lifted_424130);
