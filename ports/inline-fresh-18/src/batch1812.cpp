// batch1812.cpp - fresh-18 batch 12 (slice 18): window pop, zip file open, subtitle lines, geom stream load, sound
// pitch slide, draw entry notify, vorbis seed maxima, string map lookup-or-insert.
// SEH frames and stack cookies of the exe are not reproduced (they leave no state behind on return).
#include "ff.h"

static inline u8 *engineObj9b() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

extern "C" void *ext_41e290(u32 size);                                            // operator new, cdecl
extern "C" void ext_634273(void *p, u32 size);                                    // operator delete, cdecl
extern "C" u8 THISCALL ext_4d6520(void *self, u32 name, void *hdr, u32 off);      // FsZip_t::findFile
extern "C" s32 STDCALL ext_62f9d0(void *strm, s32 bits, u32 ver, u32 size);      // inflateInit2_-like, ret 0x10
extern "C" void THISCALL ext_4dc9c0(void *self, u32 v);
extern "C" void THISCALL ext_4dc630(void *self, u32 set, u32 clr);                // ZBaseGeom::SetControl
extern "C" void THISCALL ext_63e850(void *self, void *e);                         // ZDrawBase::GeomEnter
extern "C" u8 THISCALL ext_4dd8d0(void *geom);                                    // ZBaseGeom::WantCameraMsg
extern "C" void THISCALL ext_4db6c0(void *geom, float *a, float *b);              // ZBaseGeom::GetRootTM
extern "C" u16 THISCALL ext_63f090(void *self, void *e);                          // ZDrawBase::NewDrawId
extern "C" u32 THISCALL ext_658d30(void *e);                                      // ZGeomDrawEntry::Bones
extern "C" u8 *THISCALL ext_63f220(void *self, u32 g);                            // ZDrawBase::OnLightNotify
extern "C" void THISCALL ext_658fb0(void *e, void *l);                            // ZGeomDrawEntry::SetEnvironment
extern "C" void ext_4045a0(float *seed, s32 linesper, s32 n);                     // vorbis seed_chase, cdecl
extern "C" void THISCALL ext_431110(void *self, u32 *out, u32 *key);              // lower_bound
extern "C" s32 FASTCALL ext_42feb0(u32 b0, u32 e0, u32 b1, u32 e1);               // string compare
extern "C" void *THISCALL ext_6014a0(void *self, u32 n);                          // CHostInterface::alloc
extern "C" void THISCALL ext_5f10c0(void *self, const void *src);                 // string copy ctor
extern "C" void THISCALL ext_430eb0(void *self, u32 *out, u32 hint, void *pair);  // insert with hint
extern "C" void THISCALL ext_54f870(void *self, u32 p, u32 n);                    // block deallocate

// 0x4f28e0 ZWINDOWS::PopWindow() [high]: walks the window list (+0xcb: begin 0x54, next 0x44, get 0x6c) mapping
// each entry through engine db slot 0x58; the first nonzero window is the top, the next nonzero one the new top.
// Sends 0x200 (lose, flag 1) to the top and 0x100 (gain, flag 0) to the new one through slot 0x2dc with the
// other's handle (db slot 0x4c); always sets +0x63b.
static void THISCALL f4f28e0(u8 *self) {
  u8 *l = self + 0xcb;
  u32 a = 0, b = 0;
  u32 it[4];
  vcall<void>(l, 0x54, it);
  u32 x = vcall<u32>(l, 0x6c, it);
  if (it[0]) {
    do {
      u32 w = vcall<u32>(engineObj9b(), 0x58, x);
      if (a) {
        b = w;
        if (b) break;
      } else
        a = w;
      vcall<void>(l, 0x44, it);
      x = vcall<u32>(l, 0x6c, it);
    } while (it[0]);
    if (a) {
      u32 hb = vcall<u32>(engineObj9b(), 0x4c, b);
      vcall<void>(self, 0x2dc, 0x200u, hb, 1u, a);
    }
    if (b) {
      u32 ha = vcall<u32>(engineObj9b(), 0x4c, a);
      vcall<void>(self, 0x2dc, 0x100u, ha, 0u, b);
    }
  }
  self[0x63b] = 1;
}
PCREG(4f28e0, f4f28e0);

// 0x4d7220 FsZip_t::open(const char*, IOFSAccess_t) [high]: read mode (3) only; finds the local header (+4), sets
// the data position (+0x1e, +0x22 from the stream's slot 0xc), size (+0x2a <- header +0x12) and a raw inflate
// stream (+0x26, input buffer +0x2e, inflateInit2_(-15, "1.x" 0x69688c, 0x38)); any failure frees both blocks.
static u8 *THISCALL f4d7220(u8 *self, u32 name, u32 mode) {
  u8 *n = (u8 *)ext_41e290(0x432);
  if (n) *(void **)(n + 0x26) = ext_41e290(0x38);
  else n = 0;
  *(u32 *)(n + 0x1e) = 0;
  *(u32 *)n = mode;
  if (mode == 3 && ext_4d6520(self, name, n + 4, 0)) {
    u32 v = vcall<u32>(*(void **)(self + 0x15), 0xc, *(u32 *)(self + 0x11));
    *(u32 *)(n + 0x1e) = v;
    *(u32 *)(n + 0x22) = v;
    *(u32 *)(n + 0x2a) = *(u32 *)(n + 0x12);
    u32 *z = *(u32 **)(n + 0x26);
    z[8] = 0;
    z[9] = 0;
    z[0] = (u32)(n + 0x2e);
    z[1] = 0;
    s32 r = ext_62f9d0(*(void **)(n + 0x26), -15, 0x69688c, 0x38);
    *(s32 *)(n + 0x42e) = r;
    if (!r) {
      self[0x6e] = 0;
      return n;
    }
  }
  ext_634273(*(void **)(n + 0x26), 0x38);
  ext_634273(n, 0x432);
  return 0;
}
PCREG(4d7220, f4d7220);

// 0x572720 CSubtitle::DisplayNextLines() [medium]: past the last line hides both text windows (slot 0xbc(1)),
// clears +0x86c and sends the done message (+0x86e) to the owner group; else skips to the next string start
// in the line buffer (+0x5c, index +0x860 < +0x85c), shows it in both windows (slot 0x284, 0xbc(0)) and sets the
// line timer +0x50 = (now - (int)(duration * -1024)) / 1024.
static void THISCALL f572720(u8 *self) {
  s32 cnt = *(s32 *)(self + 0x85c);
  if (*(s32 *)(self + 0x860) >= cnt) {
    vcall<void>(*(void **)(self + 0x872), 0xbc, 1u);
    void *w = *(void **)(self + 0x876);
    if (w) vcall<void>(w, 0xbc, 1u);
    self[0x86c] = 0;
    if (*(u32 *)(self + 0x86e))
      vcall<void>(*(void **)(self + 0x44), 0x12c, *(u32 *)(self + 0x86e), (u32) * (u16 *)(self + 0x4c), 0u);
    return;
  }
  if (self[*(s32 *)(self + 0x860) + 0x5c]) {
    while (*(s32 *)(self + 0x860) < cnt) {
      s32 i = ++*(s32 *)(self + 0x860);
      if (!self[i + 0x5c]) break;
    }
  }
  if (*(s32 *)(self + 0x860) >= cnt) return;
  s32 i = ++*(s32 *)(self + 0x860);
  vcall<void>(*(void **)(self + 0x872), 0x284, self + 0x5c + i);
  vcall<void>(*(void **)(self + 0x872), 0xbc, 0u);
  void *w = *(void **)(self + 0x876);
  if (w) {
    vcall<void>(w, 0x284, self + 0x5c + *(s32 *)(self + 0x860));
    vcall<void>(*(void **)(self + 0x876), 0xbc, 0u);
  }
  s32 t = (s32)(*(float *)(self + 0x54) * G(float, 0x67862c));
  s32 now = *(s32 *)(G(u8 *, 0x70039c) + 0x40);
  self[0x86c] = 1;
  *(float *)(self + 0x50) = (float)(now - t) * G(float, 0x6785e4);
}
PCREG(572720, f572720);

// 0x4dbbe0 GUESS ZBaseGeom load from stream (slot 0x18 = read(dst, size)): byte +0x59, control flags (bit 30
// dropped); bit 20: transform block (0x24 at +0, 3x 0xc, +0x4c, +0x6c); bit 18: material id (+0x5c released via
// db+8 slot 0x5c) and a 16-bit table index read into the argument slot (0xffff none; else 0x4dc9c0 with entry
// +0x54 of db+8 slot 0x4c's 0x70-byte table); then the attached object (+0x54) slot 0x14 load (fail -> 0), and
// SetControl(flags | 0x1000000, ~that).
static u8 THISCALL f4dbbe0(u8 *self, u32 sarg) {
  void *st = (void *)sarg;
  u32 f;
  vcall<void>(st, 0x18, self + 0x59, 1u);
  vcall<void>(st, 0x18, &f, 4u);
  f &= 0xbfffffff;
  if (f & 0x100000) {
    vcall<void>(st, 0x18, self, 0x24u);
    vcall<void>(st, 0x18, self + 0x24, 0xcu);
    vcall<void>(st, 0x18, self + 0x30, 0xcu);
    vcall<void>(st, 0x18, self + 0x40, 0xcu);
    vcall<void>(st, 0x18, self + 0x4c, 4u);
    vcall<void>(st, 0x18, self + 0x6c, 4u);
  }
  if (f & 0x40000) {
    u16 m = *(u16 *)(self + 0x5c);
    if (m) vcall<void>(*(void **)(engineObj9b() + 8), 0x5c, (u32)m);
    vcall<void>(st, 0x18, &sarg, 2u);
    if ((u16)sarg != 0xffff) {
      u8 *t = vcall<u8 *>(*(void **)(engineObj9b() + 8), 0x4c);
      ext_4dc9c0(self, *(u32 *)(t + (u32)(u16)sarg * 0x70 + 0x54));
    }
  }
  void *g = *(void **)(self + 0x54);
  if (g && !vcall<u8>(g, 0x14, st)) {
    asm volatile("" ::"r"(&f), "r"(&sarg) : "memory");
    return 0;
  }
  f |= 0x1000000;
  asm volatile("" ::"r"(&f), "r"(&sarg) : "memory");
  ext_4dc630(self, f, ~f);
  asm volatile("" ::"r"(&f) : "memory");
  return 1;
}
PCREG(4dbbe0, f4dbbe0);

// 0x4bfee0 ZSoundSegmentPitch::FrameUpdate() [high]: once the start time (+0x4e, set to now on first use) plus the
// delay (+0x52) is reached, slides the pitch (+0x5a) from the sound's current value (slot 0x228) towards +0x5e at
// the rate (+0x5e - start) / (+0x56 - +0x52) per engine time step (+0x48); clamps and stops (slot 0x68(0x10, 0)) at
// the target or at the end time, then sets the pitch (slot 0x218).
static void THISCALL f4bfee0(u8 *self) {
  if (!self[0x4c]) return;
  if (*(float *)(self + 0x4e) == G(float, 0x6785d0))
    *(float *)(self + 0x4e) = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * G(float, 0x6785e4);
  s32 t = (s32)((*(float *)(self + 0x52) + *(float *)(self + 0x4e)) * G(float, 0x678620));
  if (*(s32 *)(G(u8 *, 0x70039c) + 0x40) < t) return;
  if (!self[0x4d]) {
    s32 v = vcall<s32>(*(void **)(self + 0x44), 0x228);
    self[0x4d] = 1;
    float fv = (float)v;
    *(float *)(self + 0x5a) = fv;
    *(float *)(self + 0x62) =
        ((float)*(s32 *)(self + 0x5e) - fv) / (*(float *)(self + 0x56) - *(float *)(self + 0x52));
  }
  float x = *(float *)(G(u8 *, 0x70039c) + 0x48) * *(float *)(self + 0x62) + *(float *)(self + 0x5a);
  *(float *)(self + 0x5a) = x;
  float tg = (float)*(s32 *)(self + 0x5e);
  bool pos = !(*(float *)(self + 0x62) <= 0.0f);
  if (pos ? x > tg : tg > x) {
    *(float *)(self + 0x5a) = tg;
    vcall<void>(self, 0x68, 0x10u, 0u);
  }
  s32 t2 = (s32)((*(float *)(self + 0x56) + *(float *)(self + 0x4e)) * G(float, 0x678620));
  if (*(s32 *)(G(u8 *, 0x70039c) + 0x40) >= t2) {
    *(float *)(self + 0x5a) = (float)*(s32 *)(self + 0x5e);
    vcall<void>(self, 0x68, 0x10u, 0u);
  }
  vcall<void>(*(void **)(self + 0x44), 0x218, (s32) * (float *)(self + 0x5a));
}
PCREG(4bfee0, f4bfee0);

// 0x63f0e0 ZDrawBase::OnGeomNotify(ZRoomDrawEntry*, ZBaseGeom*) [high]: a geom with a draw id (+0x5a) re-enters
// its entry (table +0x68) unless flagged; else takes a new entry from the pool (+0x220 slot 8), sets flags from
// the geom (0x60 from slot 0xec of +0x54, 0x20 WantCameraMsg), root TM, registers it (slots 0x84, 0x90; refused:
// slot 0x94 and back to the pool) and gives it a draw id; without bones, links the room's (or default) light.
static u8 *THISCALL f63f0e0(u8 *self, u8 *room, u8 *geom) {
  u16 id = *(u16 *)(geom + 0x5a);
  if (id) {
    u8 *e = (*(u8 ***)(self + 0x68))[id & 0xfff];
    if (!(e[5] & 1)) ext_63e850(self, e);
    return e;
  }
  u8 *e = vcall<u8 *>(*(void **)(self + 0x220), 8);
  if (!e) return 0;
  void *m = *(void **)(geom + 0x54);
  if (m && vcall<u8>(m, 0xec)) e[5] |= 0x60;
  if (ext_4dd8d0(geom)) e[5] |= 0x20;
  *(u8 **)(e + 0x38) = geom;
  ext_4db6c0(geom, (float *)(e + 8), (float *)(e + 0x2c));
  vcall<void>(self, 0x84, e);
  if (!vcall<u8>(self, 0x90, e)) {
    vcall<void>(self, 0x94, e);
    vcall<void>(*(void **)(self + 0x220), 0xc, e);
    return 0;
  }
  *(u16 *)(geom + 0x5a) = ext_63f090(self, e);
  ext_63e850(self, e);
  if (ext_658d30(e)) return e;
  if (!room) return e;
  void *c = *(void **)(room + 0x3c);
  if (!c) return e;
  u32 r = vcall<u32>(c, 0x358);
  if (!r) {
    if (!(*(u32 *)(geom + 0x3c) & 0x40000000)) return e;
    r = vcall<u32>(*(void **)(engineObj9b() + 0xadc), 0x358);
    if (!r) return e;
  }
  u8 *l = ext_63f220(self, r);
  if (l) {
    ext_658fb0(e, l);
    (*(u16 *)(l + 0x3e))++;
  }
  return e;
}
PCREG(63f0e0, f63f0e0);

// 0x404460 vorbis psy max_seeds(look, seed, flr) (libvorbis psy.c): per octave band the minimum seed above NEGINF
// (0x6be090, -9999), capped by vi->tone_abs_limit (+0x7c), raises the floor; the tail uses the last seed. x87
// compares: an unordered compare takes the "less" branch. The band store goes through fld/fstp, which would quiet
// a signalling NaN on hardware (Unicorn keeps it); the port copies the bits, SNaN seeds are not generated.
static inline bool ltu(float a, float b) { return !(a >= b); }   // C0 set: less or unordered
static inline bool equ(float a, float b) { return !(a < b || a > b); }
static void f404460(u8 *p, float *seed, float *flr) {
  s32 lp = *(s32 *)(p + 0x28);
  ext_4045a0(seed, lp, *(s32 *)(p + 0x2c));
  s32 pos = **(s32 **)(p + 0x18) - (lp >> 1) - *(s32 *)(p + 0x20);
  s32 lin = 0;
  if (*(s32 *)p > 1) {
    do {
      u32 mn = fbits(seed[pos]);
      s32 *oct = *(s32 **)(p + 0x18);
      s32 end = ((oct[lin + 1] + oct[lin]) >> 1) - *(s32 *)(p + 0x20);
      u32 lim = *(u32 *)(*(u8 **)(p + 4) + 0x7c);
      if (bitsf(mn) > bitsf(lim)) mn = lim;
      const float ni = G(float, 0x6be090);
      while (pos + 1 <= end) {
        pos++;
        float s = seed[pos];
        if ((s > ni && ltu(s, bitsf(mn))) || equ(bitsf(mn), ni)) mn = fbits(s);
      }
      s32 e2 = *(s32 *)(p + 0x20) + pos;
      for (; lin < *(s32 *)p && (*(s32 **)(p + 0x18))[lin] <= e2; lin++)
        if (ltu(flr[lin], bitsf(mn))) *(u32 *)&flr[lin] = mn;
    } while (lin + 1 < *(s32 *)p);
  }
  u32 mn = *(u32 *)&seed[*(s32 *)(p + 0x2c) - 1];
  for (; lin < *(s32 *)p; lin++)
    if (ltu(flr[lin], bitsf(mn))) *(u32 *)&flr[lin] = mn;
}
PCREG(404460, f404460);

// 0x42be20 GUESS map<string, string>::operator[](const string&): lower_bound (0x431110); a match (compare
// 0x42feb0 >= 0 against the node key +0xd/+0x11) returns the node value (+0x19); else inserts {key, ""} with
// the hint (0x430eb0) and frees the three temporary strings.
static inline void strFree(u32 *s, u32 cap) {
  u32 b = s[0], n = cap - b;
  if (b && n) ext_54f870(s, b, n);
}
static u32 THISCALL f42be20(u32 *self, u32 *key) {
  u32 it;
  ext_431110(self, &it, key);
  u8 *e = (u8 *)it;
  if ((u32)e != self[0] && ext_42feb0(key[0], key[1], *(u32 *)(e + 0xd), *(u32 *)(e + 0x11)) >= 0)
    return (u32)e + 0x19;
  u32 tmp[3] = {0, 0, 0};
  char *p = (char *)ext_6014a0(tmp, 8);
  tmp[0] = (u32)p;
  tmp[1] = (u32)p;
  tmp[2] = (u32)(p + 8);
  if (p) *p = 0;
  *p = 0;
  u32 pr[6];
  ext_5f10c0(pr, key);
  ext_5f10c0(pr + 3, tmp);
  ext_430eb0(self, &it, (u32)e, pr);
  e = (u8 *)it;
  strFree(pr + 3, pr[5]);
  strFree(pr, pr[2]);
  strFree(tmp, tmp[2]);
  return (u32)e + 0x19;
}
PCREG(42be20, f42be20);
