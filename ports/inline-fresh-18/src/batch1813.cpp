// batch1813.cpp - fresh-18 batch 13 (slice 18): map holder dtor, particle save, force feedback event, vorbis
// seed_chase, named object ctor, zlib fill_window, game window creation, key activation names.
// SEH frames and stack cookies of the exe are not reproduced (they leave no state behind on return).
#include "ff.h"

static inline u8 *engineObj9b() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
typedef void (*voidfn)();
static inline void ffAssert() {
  voidfn h = G(voidfn, 0x7003b0);
  if (h) h(); else __builtin_debugtrap();
}
static inline void *logger(u32 file, u32 line) { return vcall<void *>(G(void *, 0x700390), 0x20, file, line); }

extern "C" void *ext_41e290(u32 size);                                            // operator new, cdecl
extern "C" void *ext_634d22(void *d, const void *s, u32 n);                       // memcpy
extern "C" void THISCALL ext_5fb600(void *self);
extern "C" void THISCALL ext_54f870(void *self, u32 p, u32 n);                    // block deallocate
extern "C" void FASTCALL ext_54f2b0(s32 hr, u32 where);                           // DirectX error report
extern "C" void THISCALL ext_449d40(void *self, u32 a, u32 b, u32 c);             // base ctor
extern "C" void *THISCALL ext_4ccba0(void *self);                                 // REFTAB32::REFTAB32
extern "C" u32 STDCALL ext_6316e0(u32 adler, u32 buf, u32 len);                   // adler32

// 0x606ce0 GUESS dtor: clears the map (0x5fb600), frees the u32 vector at +3 (0x54f870 with its byte capacity).
static void THISCALL f606ce0(u8 *self) {
  ext_5fb600(self);
  u32 *v = (u32 *)(self + 3);
  s32 n = (s32)(v[2] - v[0]) >> 2;
  if (n) ext_54f870(v, v[0], (u32)n << 2);
}
PCREG(606ce0, f606ce0);

// 0x547520 ConstrainedParticleSystem::Save(ZSaveGame*) [high]: writes (slot 0x44 u32, 0x68 vec3, 0x4c float) the
// particles (+0xf, 0x34 each: +0xc, +0, +0x18, +0x24), the constraints (+0x13, 12 each: logged with index and
// length, then length, a, b) and the springs (+0x17, 12 each). The log's last pushed word is reused as the float
// argument of the following slot 0x4c call (stack-word sharing). Returns true.
typedef void (*logFn)(void *, u32, u32, double, u32, u32);
static u8 THISCALL f547520(u8 *self, void *sg) {
  vcall<void>(sg, 0x44, *(u32 *)(self + 0x28));
  u8 *p = *(u8 **)(self + 0xf);
  for (s32 i = 0; i < *(s32 *)(self + 0x28); i++, p += 0x34) {
    vcall<void>(sg, 0x68, p + 0xc);
    vcall<void>(sg, 0x68, p);
    vcall<void>(sg, 0x68, p + 0x18);
    vcall<void>(sg, 0x68, p + 0x24);
  }
  vcall<void>(sg, 0x44, *(u32 *)(self + 0x2c));
  u32 *c = *(u32 **)(self + 0x13);
  for (s32 i = 0; i < *(s32 *)(self + 0x2c); i++, c += 3) {
    void *lg = logger(0x6a2e20, 0xb48);
    (*(logFn *)(*(u8 **)lg + 0x2c))(lg, 0x6a2e8c, i, (double)bitsf(c[2]), c[0], c[1]);
    vcall<void>(sg, 0x4c, bitsf(c[2]));
    vcall<void>(sg, 0x44, c[0]);
    vcall<void>(sg, 0x44, c[1]);
  }
  vcall<void>(sg, 0x44, *(u32 *)(self + 0x30));
  c = *(u32 **)(self + 0x17);
  for (s32 i = 0; i < *(s32 *)(self + 0x30); i++, c += 3) {
    vcall<void>(sg, 0x4c, bitsf(c[2]));
    vcall<void>(sg, 0x44, c[0]);
    vcall<void>(sg, 0x44, c[1]);
  }
  return 1;
}
PCREG(547520, f547520);

// 0x633910: CRT float -> unsigned conversion taking its value in xmm0 (called, not reimplemented).
static inline u32 crtFtoui(float t) {
  u32 r;
  asm volatile("call *%[f]"
               : "=a"(r), "+Yz"(t)
               : [f] "S"(0x633910u)
               : "ecx", "edx", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  return r;
}

// 0x54c7a0 GUESS force feedback event: type 1 fills a 0x40-byte effect record from the event (+0x94.. floats,
// durations through the CRT conversion) and sends it to the effect (+0x63f0, COM slot 0x30(rec, 1)); type 10 sends
// the clamped (+-10000) level from slot 0x7c to the device (+0x63ec, COM slot 0x40), reporting a failure (0x54f2b0).
typedef s32(STDCALL *com2)(void *, u32);
typedef s32(STDCALL *com3)(void *, void *, u32);
static void THISCALL f54c7a0(u8 *self, u8 *ev) {
  s32 t = *(s32 *)(ev + 0x24);
  if (t == 1) {
    void *o = *(void **)(self + 0x63f0);
    if (!o) return;
    u32 r[16];
    r[0] = 0x40;
    r[7] = crtFtoui(*(float *)(ev + 0xb4));
    r[8] = crtFtoui(*(float *)(ev + 0xb8));
    r[14] = *(u32 *)(ev + 0xb0);
    r[13] = *(u32 *)(ev + 0xac);
    r[9] = *(u32 *)(ev + 0x70);
    r[10] = *(u32 *)(ev + 0x74);
    r[11] = *(u32 *)(ev + 0x78);
    r[12] = (u32)(s32) * (float *)(ev + 0xbc);
    r[15] = 0;
    r[1] = *(u32 *)(ev + 0x94);
    r[2] = *(u32 *)(ev + 0x98);
    r[3] = *(u32 *)(ev + 0x9c);
    r[4] = *(u32 *)(ev + 0xa0);
    r[5] = *(u32 *)(ev + 0xa4);
    r[6] = *(u32 *)(ev + 0xa8);
    (*(com3 *)(*(u8 **)o + 0x30))(o, r, 1);
    asm volatile("" ::"r"(r) : "memory");
    return;
  }
  if (t != 10) return;
  s32 v = vcall<s32>(self, 0x7c, ev);
  if (v < 0) v = v < -10000 ? -10000 : v;
  else if (v > 0) v = v > 10000 ? 10000 : v;
  else v = 0;
  void *d = *(void **)(self + 0x63ec);
  s32 hr = (*(com2 *)(*(u8 **)d + 0x40))(d, (u32)v);
  if (hr < 0) ext_54f2b0(hr, 0x6a3c44);
}
PCREG(54c7a0, f54c7a0);

// 0x4045a0 vorbis psy seed_chase(seeds, linesper, n) (libvorbis psy.c): stack of falling seeds (overlapping
// ones popped), then each stack entry fills the seeds up to the next rise or linesper past it. x87 compares:
// unordered counts as "less" in the push test and as "<=" in the pop test.
static void f4045a0(float *seeds, s32 lp, s32 n) {
  s32 *ps = (s32 *)__builtin_alloca(n * 4);
  u32 *as = (u32 *)__builtin_alloca(n * 4);
  s32 st = 0;
  for (s32 i = 0; i < n; i++) {
    if (st >= 2) {
      for (;;) {
        if (!(seeds[i] >= bitsf(as[st - 1]))) break;
        if (i >= ps[st - 1] + lp) break;
        if (st <= 1) break;
        if (bitsf(as[st - 1]) > bitsf(as[st - 2])) break;
        if (i >= ps[st - 2] + lp) break;
        st--;
      }
    }
    ps[st] = i;
    as[st] = *(u32 *)&seeds[i];
    st++;
  }
  s32 pos = 0;
  for (s32 i = 0; i < st; i++) {
    s32 end;
    if (i < st - 1 && bitsf(as[i + 1]) > bitsf(as[i])) end = ps[i + 1];
    else end = ps[i] + lp + 1;
    if (end > n) end = n;
    for (; pos < end; pos++) *(u32 *)&seeds[pos] = as[i];
  }
}
PCREG(4045a0, f4045a0);

// 0x4ee2e0 GUESS named object ctor (vt 0x6978c4) after base 0x449d40(a, b, c): looks up the name 0x697b08 in the
// name table (db slot 0x138 -> slot 0x88(name, &handle), db slot 0x58) and asserts if another object owns it,
// registers itself (slot 0x60(name, db slot 0x4c(this), 4); the 4 stays pushed from the slot 0x4c call) and
// allocates a REFTAB32 at +0x18.
typedef void (*cdeclLog4)(void *, u32, u32, u32);
static u8 *THISCALL f4ee2e0(u8 *self, u32 a, u32 b, u32 c) {
  ext_449d40(self, a, b, c);
  *(u32 *)self = 0x6978c4;
  void *t = vcall<void *>(engineObj9b(), 0x138);
  c = 0;
  vcall<void>(t, 0x88, 0x697b08u, &c);
  u8 *o = vcall<u8 *>(engineObj9b(), 0x58, c);
  if (o && o != self) {
    void *lg = logger(0x697b1c, 0x1d6);
    u32 n1 = *(u32 *)(o + 4) ? *(u32 *)(o + 4) : 0x67c8e8;
    u32 n2 = *(u32 *)(self + 4) ? *(u32 *)(self + 4) : 0x67c8e8;
    (*(cdeclLog4 *)(*(u8 **)lg + 0x2c))(lg, 0x697b48, n2, n1);
    ffAssert();
  }
  void *t2 = vcall<void *>(engineObj9b(), 0x138);
  u32 h = vcall<u32>(engineObj9b(), 0x4c, self);
  vcall<void>(t2, 0x60, 0x697b08u, h, 4u);
  void *n = ext_41e290(0xac);
  c = (u32)n;  // the exe keeps the new block in the same argument slot
  asm volatile("" ::"r"(&c) : "memory");
  *(void **)(self + 0x18) = n ? ext_4ccba0(n) : 0;
  return self;
}
PCREG(4ee2e0, f4ee2e0);

// 0x62f1e0 zlib deflate fill_window(s) (deflate.c, read_buf inlined): slides the window down by w_size once
// strstart passes w_size + MAX_DIST (head and prev chains rebased), reads input (adler32 0x6316e0 unless the
// stream state's +0x18 is set) and primes ins_h; repeats while lookahead < MIN_LOOKAHEAD and input remains.
static void f62f1e0(u32 *s) {
  u32 ws = s[0x24 / 4];
  for (;;) {
    u32 more = s[0x34 / 4] - s[0x64 / 4] - s[0x6c / 4];
    u32 room;
    if (more == 0 && s[0x64 / 4] == 0 && s[0x6c / 4] == 0) room = ws;
    else if (more == 0xffffffff) room = 0xfffffffe;
    else {
      room = more;
      if (s[0x64 / 4] >= s[0x24 / 4] - 0x106 + ws) {
        u8 *w = (u8 *)s[0x30 / 4];
        ext_634d22(w, w + ws, ws);
        s[0x68 / 4] -= ws;
        s[0x64 / 4] -= ws;
        s[0x54 / 4] -= ws;
        u32 k = s[0x44 / 4];
        u16 *p = (u16 *)s[0x3c / 4] + k;
        do {
          u32 m = *--p;
          *p = (u16)(m >= ws ? m - ws : 0);
        } while (--k);
        k = ws;
        p = (u16 *)s[0x38 / 4] + ws;
        do {
          u32 m = *--p;
          *p = (u16)(m >= ws ? m - ws : 0);
        } while (--k);
        room = more + ws;
      }
    }
    u32 *strm = (u32 *)s[0];
    if (!strm[1]) return;
    u8 *dst = (u8 *)(s[0x6c / 4] + s[0x64 / 4] + s[0x30 / 4]);
    u32 len = strm[1] > room ? room : strm[1];
    if (len) {
      strm[1] -= len;
      if (!*(u32 *)(strm[0x1c / 4] + 0x18)) strm[0x30 / 4] = ext_6316e0(strm[0x30 / 4], strm[0], len);
      ext_634d22(dst, (void *)strm[0], len);
      strm[0] += len;
      strm[2] += len;
    }
    s[0x6c / 4] += len;
    u32 la = s[0x6c / 4];
    if (la >= 3) {
      u8 *w = (u8 *)(s[0x30 / 4] + s[0x64 / 4]);
      u32 hsh = w[0];
      s[0x40 / 4] = hsh;
      s[0x40 / 4] = ((hsh << (s[0x50 / 4] & 31)) ^ w[1]) & s[0x4c / 4];
    }
    if (la >= 0x106 || !((u32 *)s[0])[1]) return;
  }
}
PCREG(62f1e0, f62f1e0);

// 0x6526e0 GUESS game window creation (window class 0x7f5a10, wndproc 0x655a10): adjusts the rect, registers the
// class on first use (icon/cursor 0x7f00, stock brush 4), creates the window with this object published in
// 0x725824 for the wndproc and stores the object as GWL_USERDATA of +0x133.
typedef u32(STDCALL *w4)(u32, u32, u32, u32);
typedef u32(STDCALL *w3)(u32, u32, u32);
typedef u32(STDCALL *w2)(u32, u32);
typedef u32(STDCALL *w1)(u32);
typedef u32(STDCALL *w12)(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
static u8 THISCALL f6526e0(u8 *self, u32 cls, u32 title, u32 style, u32 ex, u32 *rc, u32 parent, u32) {
  u32 r[4] = {rc[0], rc[1], rc[2], rc[3]};
  (*(w4 *)0x676218)((u32)r, style, 0, ex);
  if (!cls) {
    u32 wc[12];
    if (!(*(w3 *)0x67618c)(*(u32 *)(self + 0x12f), 0x7f5a10, (u32)wc)) {
      wc[0] = 0x30;
      wc[1] = 0x2b;
      wc[2] = 0x655a10;
      wc[3] = 0;
      wc[4] = 0;
      wc[5] = *(u32 *)(self + 0x12f);
      wc[6] = (*(w2 *)0x676248)(0, 0x7f00);
      wc[7] = (*(w2 *)0x6761cc)(0, 0x7f00);
      wc[8] = (*(w1 *)0x676034)(4);
      wc[9] = 0;
      wc[10] = 0x7f5a10;
      wc[11] = 0;
      if (!(u16)(*(w1 *)0x676188)((u32)wc)) {
        asm volatile("" ::"r"(wc), "r"(r) : "memory");
        return 0;
      }
    }
    asm volatile("" ::"r"(wc) : "memory");
    cls = 0x7f5a10;
  }
  G(u8 *, 0x725824) = self;
  (*(w12 *)0x676190)(ex, cls, title, style, r[0], r[1], r[2] - r[0], r[3] - r[1], parent, 0, *(u32 *)(self + 0x12f), 0);
  (*(w3 *)0x6761fc)(*(u32 *)(self + 0x133), 0xffffffeb, (u32)self);
  G(u32, 0x725824) = 0;
  asm volatile("" ::"r"(r) : "memory");
  return 1;
}
PCREG(6526e0, f6526e0);

// 0x43b820 CConfigReader::ExtractMappingActivation(const char*) [high]: activation name (_stricmp, IAT 0x676414) to
// mode +0xb1: 0x67a0a8 2, 0x67a0e0 8, 0x67a0ac 3, 0x67c0e4 5, 0x67a0a0 1, 0x67a0c8 6, 0x67a0d4 7, 0x67a0b4 4;
// 0x677b5c sets the flag +0xb0; anything else is logged. +0xb0..+0xb6 are cleared first.
typedef s32 (*stricmpFn)(const char *, const char *);
typedef void (*cdeclLog3)(void *, u32, u32);
static void THISCALL f43b820(u8 *self, const char *s) {
  stricmpFn cmp = *(stricmpFn *)0x676414;
  self[0xb0] = 0;
  *(u32 *)(self + 0xb1) = 0;
  *(u16 *)(self + 0xb5) = 0;
  static const u32 names[8] = {0x67a0a8, 0x67a0e0, 0x67a0ac, 0x67c0e4, 0x67a0a0, 0x67a0c8, 0x67a0d4, 0x67a0b4};
  static const u32 modes[8] = {2, 8, 3, 5, 1, 6, 7, 4};
  for (int i = 0; i < 8; i++)
    if (!cmp(s, (const char *)names[i])) {
      *(u32 *)(self + 0xb1) = modes[i];
      return;
    }
  if (!cmp(s, (const char *)0x677b5c)) {
    self[0xb0] = 1;
    return;
  }
  void *lg = logger(0x67bd78, 0x279);
  (*(cdeclLog3 *)(*(u8 **)lg + 0x2c))(lg, 0x67c0f0, (u32)s);
}
PCREG(43b820, f43b820);
