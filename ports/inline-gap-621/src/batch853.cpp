// batch853.cpp - gap band teardown (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" void THISCALL ext_64b070(u8 *obj);                          // hooked (GUESS)
extern "C" void THISCALL ext_648280(u8 *obj);                          // hooked (GUESS)
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);     // hooked (GUESS): delete-like
extern "C" void __attribute__((cdecl)) ext_634d10(void *p, u32 v, u32 n);   // hooked (GUESS): memset
extern "C" void THISCALL ext_63fc20(u8 *self);                         // hooked (GUESS)
extern "C" void THISCALL ext_65f0f0(u8 *obj);                          // hooked (GUESS)
typedef void (THISCALL *vm0_t)(u8 *self);

// 0x63d840: thiscall() - when this[5] is set: vt[0x64](), destroys the this[0xec] objects at this[0xf0..] (0x64b070, 0x648280 when non-null, then
// 0x634273(obj, 0x182a1)), clears this[0xec] and the 0x80 bytes at this+0x6c, runs 0x63fc20, frees this[0x60] (0x340c) and this[0x64] (1),
// zeroes both, runs 0x65f0f0(this + 0x8270) and clears this[5]
static void THISCALL teardown_63d840(u8 *self) {
  if (self[5] == 0) return;
  (*(vm0_t *)(*(u8 **)self + 0x64))(self);
  if (*(u32 *)(self + 0xec) != 0) {
    u32 i = 0;
    u8 **pp = (u8 **)(self + 0xf0);
    do {
      u8 *o = *pp;
      ext_64b070(o);
      if (o) {
        ext_648280(o);
        ext_634273(o, 0x182a1);
      }
      i++;
      pp++;
    } while (i != *(u32 *)(self + 0xec));
  }
  *(u32 *)(self + 0xec) = 0;
  ext_634d10(self + 0x6c, 0, 0x80);
  ext_63fc20(self);
  ext_634273(*(void **)(self + 0x60), 0x340c);
  u32 q = *(u32 *)(self + 0x64);
  *(u32 *)(self + 0x60) = 0;
  ext_634273((void *)q, 1);
  *(u32 *)(self + 0x64) = 0;
  ext_65f0f0(self + 0x8270);
  self[5] = 0;
}
PCREG(63d840, teardown_63d840);

extern "C" u32 __attribute__((cdecl)) ext_62c640(u32 hi, u32 lo);   // real callee: unit classifier

static inline u32 unitClassBE(const u8 *cvt, const u8 *p) {
  return p[0] == 0 ? (u32)cvt[0x4c + p[1]] : ext_62c640(p[0], p[1]);
}

// 0x622980: cdecl(cvt, s1, s2) -> 0 or 1 - the big-endian twin of 0x6253b0 (class from (hi, lo) = (p[0], p[1])): class - 5: 0 -> 2 bytes compared, 1 -> 3,
// 2 -> 4, 17..22 and 24 -> 2; any other class ends the walk, then the class of the unit at s2 decides (above 0x18, or 3..16 / 23 gives 1, else 0)
static u32 __attribute__((cdecl)) matchPrefixBE_622980(const u8 *cvt, const u8 *s1, const u8 *s2) {
  for (;;) {
    u32 k = unitClassBE(cvt, s1) - 5;
    u32 n = 0;
    if (k <= 0x18) {
      if (k == 0) n = 2;
      else if (k == 1) n = 3;
      else if (k == 2) n = 4;
      else if ((k >= 17 && k <= 22) || k == 24) n = 2;
    }
    if (!n) break;
    for (u32 j = 0; j < n; j++)
      if (s1[j] != s2[j]) return 0;
    s1 += n;
    s2 += n;
  }
  u32 k2 = unitClassBE(cvt, s2) - 5;
  if (k2 > 0x18) return 1;
  return (k2 >= 3 && k2 <= 16) || k2 == 23 ? 1 : 0;
}
PCREG(622980, matchPrefixBE_622980);

typedef u32 (THISCALL *vq_t)(u8 *self);
typedef void (*cb0_t)();

// 0x6386c0: thiscall(mode, out) ret 8 - total size of a block-compressed surface with mip chain. vt[0x88]() is called for its effect, then
// size = vt[0x84](), n = vt[0x34]() levels, w = vt[0x1c](), h = vt[0x20](). *out = ((size + 15) >> 4) << 5 and the result is that plus 32 x
// the sum over levels of ceil(h/8) * ceil(w/8) for mode 4 or ceil(h/4) * ceil(w/8) for mode 8 (w and h halve down to 1 each level); other
// modes call the assert hook [0x7003b0] (int3 when unset: the port traps) with no level sum.
static u32 THISCALL surfaceSize_6386c0(u8 *self, u32 mode, u32 *out) {
  (*(vq_t *)(*(u8 **)self + 0x88))(self);
  u32 size = (*(vq_t *)(*(u8 **)self + 0x84))(self);
  u32 n = (*(vq_t *)(*(u8 **)self + 0x34))(self);
  u32 w = (*(vq_t *)(*(u8 **)self + 0x1c))(self);
  u32 h = (*(vq_t *)(*(u8 **)self + 0x20))(self);
  u32 base = ((size + 0xf) >> 4) << 5;
  u32 sum = 0;
  if (mode == 4) {
    if (n) {
      do {
        sum += ((h + 7) >> 3) * ((w + 7) >> 3);
        if (w > 1) w >>= 1;
        if (h > 1) h >>= 1;
      } while (--n);
    }
  } else if (mode == 8) {
    if (n) {
      do {
        sum += ((h + 3) >> 2) * ((w + 7) >> 3);
        if (w > 1) w >>= 1;
        if (h > 1) h >>= 1;
      } while (--n);
    }
  } else {
    cb0_t cb = G(cb0_t, 0x7003b0);
    if (!cb) __builtin_trap();
    cb();
  }
  *out = base;
  return base + (sum << 5);
}
PCREG(6386c0, surfaceSize_6386c0);

extern "C" u8 *STDCALL ext_64c7e0(u32 idx);                                   // hooked (GUESS): lookup, ret 4
extern "C" void __attribute__((cdecl)) ext_634d22(void *dst, void *src, u32 n);   // hooked (GUESS): memmove
typedef u8 *(THISCALL *vnew_t)(u8 *self, u32 n);
typedef void (THISCALL *vdel_t)(u8 *self, u8 *p, u32 n);

// 0x63b850: thiscall(a, b) ret 8 - the adding counterpart of 0x63d2f0: with id = u16 a[0x5a] (0 returns), ent = this[0x68][(id & 0xfff)*4] and
// key = [[0x70039c]+0x1aa3][0x20] + b: when the entry already has pairs (ent[0x3d] = cnt, size = cnt * 8, a zero size returns) it grows ent[0x40]
// to size + 8 bytes (vt[0x20], copy through 0x634d22, free the old through vt[0x24]), appends the pair (0, key), bumps the byte count, and for each
// of the this[0xec] listeners whose table word at c[0x10071] + 4 * (id & 0xfff) is nonzero sets bit 0x80 of the byte-flag word at +0x14 of 0x64c7e0(id)
static void THISCALL addPair_63b850(u8 *self, u8 *a, u32 b) {
  u32 id = *(u16 *)(a + 0x5a);
  if (!id) return;
  u32 low = id & 0xfff;
  u8 *ent = *(u8 **)(*(u8 **)(self + 0x68) + low * 4);
  u8 *g = G(u8 *, 0x70039c);
  u32 key = b + *(u32 *)(*(u8 **)(g + 0x1aa3) + 0x20);
  u32 size = (u32)ent[0x3d] << 3;
  if (size == 0) return;
  u8 *vt = *(u8 **)self;
  u8 *old = *(u8 **)(ent + 0x40);
  u8 *na = (*(vnew_t *)(vt + 0x20))(self, size + 8);
  *(u8 **)(ent + 0x40) = na;
  ext_634d22(na, old, size);
  (*(vdel_t *)(*(u8 **)self + 0x24))(self, old, size);
  u8 cnt = ent[0x3d];
  ent[0x3d] = cnt + 1;
  u8 *arr = *(u8 **)(ent + 0x40);
  *(u32 *)(arr + cnt * 8 + 4) = key;
  *(u32 *)(arr + cnt * 8) = 0;
  if (*(u32 *)(self + 0xec) != 0) {
    u32 i = 0;
    u8 **pp = (u8 **)(self + 0xf0);
    do {
      u8 *c = *pp;
      u32 f = *(u32 *)(c + 0x10071);
      if (*(u32 *)(f + low * 4) != 0) {
        u8 *r = ext_64c7e0(id);
        r[0x14] |= 0x80;
      }
      i++;
      pp++;
    } while (i != *(u32 *)(self + 0xec));
  }
}
PCREG(63b850, addPair_63b850);

extern "C" u32 THISCALL ext_658d30(u8 *ent);               // hooked (GUESS): liveness / kind test
extern "C" u32 THISCALL ext_658d50(u8 *ent);               // hooked (GUESS): size of the +0x48 block
extern "C" void THISCALL ext_658fb0(u8 *ent, u32 arg);     // hooked (GUESS): ret 4
extern "C" void THISCALL ext_63faa0(u8 *self, u8 *ent);    // hooked (GUESS): ret 4 (batch 845)
typedef void (THISCALL *vdel2_t)(u8 *self, u8 *p, u32 n);
typedef u32 (THISCALL *vq1_t)(u8 *self, u32 a);
typedef void (THISCALL *vq2_t)(u8 *self, u32 a, u32 b);

// 0x63e910: thiscall(ent) ret 4 - releases an entry's resources: clears +0xc of every object referenced by the pairs in ent[0x40] (ent[0x3d] pairs of 8
// bytes) and frees that array (vt[0x24](ptr, cnt << 3)); when 0x658d30(ent) is nonzero: 0x63faa0(ent), and if ent[0x38] is set a notification chain
// (o = ent[0x38][0x54]; v = [[0x70039c]+0x1aa3][0x18]->vt[0xc4](o[8][0x6c]); o->vt[0x284](0x658d30(ent), v)), then frees ent[0x48] with the size from
// 0x658d50(ent); finally, with ent[0x3c] bit 8 and ent[0x44] set, decrements the u16 at ent[0x44] + 0x3e and runs 0x658fb0(ent, 0)
static void THISCALL releaseResources_63e910(u8 *self, u8 *ent) {
  u8 *p = *(u8 **)(ent + 0x40);
  if (p) {
    u32 i = 0;
    if (ent[0x3d] != 0) {
      do {
        u8 *o = *(u8 **)p;
        if (o) *(u32 *)(o + 0xc) = 0;
        i++;
        p += 8;
      } while (i != ent[0x3d]);
    }
    (*(vdel2_t *)(*(u8 **)self + 0x24))(self, *(u8 **)(ent + 0x40), (u32)ent[0x3d] << 3);
    *(u32 *)(ent + 0x40) = 0;
  }
  if (ext_658d30(ent) != 0) {
    ext_63faa0(self, ent);
    u8 *s = *(u8 **)(ent + 0x38);
    if (s) {
      u8 *o = *(u8 **)(s + 0x54);
      u32 q = *(u32 *)(*(u8 **)(o + 8) + 0x6c);
      u8 *g = G(u8 *, 0x70039c);
      u8 *o2 = *(u8 **)(*(u8 **)(g + 0x1aa3) + 0x18);
      u32 v = (*(vq1_t *)(*(u8 **)o2 + 0xc4))(o2, q);
      u32 r2 = ext_658d30(ent);
      (*(vq2_t *)(*(u8 **)o + 0x284))(o, r2, v);
    }
    u32 sz = ext_658d50(ent);
    (*(vdel2_t *)(*(u8 **)self + 0x24))(self, *(u8 **)(ent + 0x48), sz);
    *(u32 *)(ent + 0x48) = 0;
  }
  if (*(u32 *)(ent + 0x3c) & 8) {
    u8 *w = *(u8 **)(ent + 0x44);
    if (w) {
      *(u16 *)(w + 0x3e) += 0xffff;
      ext_658fb0(ent, 0);
    }
  }
}
PCREG(63e910, releaseResources_63e910);

// 0x629580: cdecl(cvt, p, end, out) -> 0, 0xd, -1 or -2 - little-endian reader for the rest of an XML comment after "<!" (expects a "-" unit first, then
// scans for "-->"). Units are (lo = p[0], hi = p[1]); the class is cvt[0x4c + lo] for hi == 0 else 0x62c640(hi, lo) (real). A class maps to an action:
// 0, 1 and 8 stop (*out = p, return 0); 5 skips 2 (needs 2 bytes left, else -2); 6 skips 3 (needs 3); 7 skips 4 (needs 4); 27 ('-') skips 2 and, when the
// next unit is "-" and then ">", sets *out past it and returns 13 (a "-" not followed by ">" stops with *out = p, return 0); everything else skips 2.
// Reaching end returns -1.
static s32 __attribute__((cdecl)) readCommentLE_629580(const u8 *cvt, const u8 *p, const u8 *end, const u8 **out) {
  if (p == end) return -1;
  if (!(p[1] == 0 && p[0] == 0x2d)) {
    *out = p;
    return 0;
  }
  p += 2;
  if (p == end) return -1;
  s32 rem = (s32)(end - p);
  for (;;) {
    u32 hi = p[1], lo = p[0];
    u32 cls = hi == 0 ? (u32)cvt[0x4c + lo] : ext_62c640(hi, lo);
    u32 act = 5;
    if (cls <= 0x1b) {
      static const u8 tab[28] = {0, 0, 5, 5, 5, 1, 2, 3, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4};
      act = tab[cls];
    }
    if (act == 0) {
      *out = p;
      return 0;
    }
    if (act == 1) {
      if (rem < 2) return -2;
      p += 2;
      rem -= 2;
    } else if (act == 2) {
      if (rem < 3) return -2;
      p += 3;
      rem -= 3;
    } else if (act == 3) {
      if (rem < 4) return -2;
      p += 4;
      rem -= 4;
    } else if (act == 5) {
      p += 2;
      rem -= 2;
    } else {
      p += 2;
      rem -= 2;
      if (p == end) return -1;
      if (p[1] == 0 && p[0] == 0x2d) {
        p += 2;
        if (p == end) return -1;
        if (p[1] == 0 && p[0] == 0x3e) {
          *out = p + 2;
          return 0xd;
        }
        *out = p;
        return 0;
      }
    }
    if (p == end) return -1;
  }
}
PCREG(629580, readCommentLE_629580);

// 0x627a80: cdecl(quote, cvt, p, end, out) -> 0, 0x1b, -1, -2 or -27 - big-endian reader for a quoted value. Units (hi = p[0], lo = p[1]) are classed (hi == 0:
// cvt[0x4c + lo], else 0x62c640(hi, lo) real). Class actions (table 0x627b80 / jump table 0x627b68, decoded from the image): 0, 1, 8 stop (*out = p, return 0); 5
// skips 2 (needs 2 bytes left else -2); 6 skips 3 (needs 3); 7 skips 4 (needs 4); 12 and 13 skip 2 and, when the class equals `quote`, end the value: end of input gives -27,
// otherwise *out = p and the class of the next unit (minus 9, tables 0x627b90 / 0x627b98) decides 0x1b (classes 9..11, 20, 21, 30) or 0; any other class skips 2. End returns -1.
static s32 __attribute__((cdecl)) readQuotedBE_627a80(u32 quote, const u8 *cvt, const u8 *p, const u8 *end, const u8 **out) {
  if (p == end) return -1;
  s32 rem = (s32)(end - p);
  for (;;) {
    u32 hi = p[0], lo = p[1];
    u32 cls = hi == 0 ? (u32)cvt[0x4c + lo] : ext_62c640(hi, lo);
    u32 act = 5;
    if (cls <= 0xd) {
      static const u8 tab[14] = {0, 0, 5, 5, 5, 1, 2, 3, 0, 5, 5, 5, 4, 4};
      act = tab[cls];
    }
    if (act == 0) {
      *out = p;
      return 0;
    }
    if (act == 1) {
      if (rem < 2) return -2;
      p += 2;
      rem -= 2;
    } else if (act == 2) {
      if (rem < 3) return -2;
      p += 3;
      rem -= 3;
    } else if (act == 3) {
      if (rem < 4) return -2;
      p += 4;
      rem -= 4;
    } else if (act == 5) {
      p += 2;
      rem -= 2;
    } else {
      p += 2;
      rem -= 2;
      if (cls == quote) {
        if (p == end) return -27;
        *out = p;
        u32 h2 = p[0], l2 = p[1];
        u32 c2 = h2 == 0 ? (u32)cvt[0x4c + l2] : ext_62c640(h2, l2);
        u32 k = c2 - 9;
        if (k > 0x15) return 0;
        static const u8 t2[22] = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0};
        return t2[k] ? 0 : 0x1b;
      }
    }
    if (p == end) return -1;
  }
}
PCREG(627a80, readQuotedBE_627a80);

extern "C" void THISCALL ext_4d06a0(u32 *self, u32 *arg);                 // hooked (GUESS): ret 4
extern "C" u32 THISCALL ext_639df0(u32 *self, u32 pixel, u32 extra);      // hooked (GUESS): ret 8
typedef u8 *(THISCALL *vsurf_t)(u8 *self, u32 a);

// 0x6387d0: thiscall(a, b) ret 8 - converts a block of pixels: surf = this->vt[0x38](b) (dword pitch at +4, base at +0x10); two local mask structs
// ({0xff, 0xff00, 0xff0000, 0xff000000} and {a[0x14], a[0x18], a[0x1c], a[0x20]}) are handed to 0x4d06a0 (hooked, which in the original fills the converter);
// then for each of a[0xc] rows and a[8] columns the source dword (rows start at (a[4] * pitch + a[0]) * 4 + base, advancing pitch * 4) is converted by
// 0x639df0(pixel, a[0x28] byte) and stored to the destination a[0x2c] (rows advance a[0x10] bytes) as a u16 when a[0x24] == 16 else as a dword.
// /GS cookie not modelled (0x633654 hooked in the spec).
static void THISCALL convertPixels_6387d0(u8 *self, u8 *a, u32 b) {
  u8 *surf = (*(vsurf_t *)(*(u8 **)self + 0x38))(self, b);
  u32 L1[4] = {0xff, 0xff00, 0xff0000, 0xff000000};
  u32 L2[4];
  ext_4d06a0(L1, L1);
  L2[0] = *(u32 *)(a + 0x14);
  L2[1] = *(u32 *)(a + 0x18);
  L2[2] = *(u32 *)(a + 0x1c);
  L2[3] = *(u32 *)(a + 0x20);
  ext_4d06a0(L1, L2);
  u8 *src = (u8 *)(*(u32 *)(surf + 0x10) + (*(u32 *)(a + 4) * *(u32 *)(surf + 4) + *(u32 *)a) * 4);
  u8 *dst = *(u8 **)(a + 0x2c);
  s32 y = 0;
  if ((s32)*(u32 *)(a + 0xc) > 0) {
    do {
      if ((s32)*(u32 *)(a + 8) > 0) {
        u8 *sp = src;
        s32 x = 0;
        do {
          u32 r = ext_639df0(L1, *(u32 *)sp, a[0x28]);
          if (*(u32 *)(a + 0x24) == 0x10)
            *(u16 *)(dst + x * 2) = (u16)r;
          else
            *(u32 *)(dst + x * 4) = r;
          x++;
          sp += 4;
        } while (x < (s32)*(u32 *)(a + 8));
      }
      y++;
      src += *(u32 *)(surf + 4) * 4;
      dst += *(u32 *)(a + 0x10);
    } while (y < (s32)*(u32 *)(a + 0xc));
  }
}
PCREG(6387d0, convertPixels_6387d0);

extern "C" u32 THISCALL ext_4ce7b0(u8 *obj);               // hooked (GUESS): allocates an id
typedef u8 *(THISCALL *vpool_t)(u8 *self);
typedef void (THISCALL *vent_t)(u8 *self, u8 *ent);

// 0x63f2d0: thiscall(a) ret 4 -> entry - gets (or creates) the table entry of the object b = a[8] and returns it. With id = u16 b[0x5a] != 0: ent = this[0x68][(id & 0xfff) * 4]; when
// ent[5] bit 0 is clear the previous owner link (u16 ent[6], 0xffff = none) is cleared in this[0x270 + 4 * link], the bit is set and ent[0] = [[0x70039c] + 0x3c]; with ent[0x42] bit 0 set,
// vt[0x8c](ent) and vt[0x88](ent) run. Without an id: ent = this[0x21c]->vt[8](), ent[0x3c] = a, id = (0x4ce7b0(this + 0xb990) + 1) & 0xfff (0 calls the assert hook [0x7003b0],
// int3 when unset: the port traps), this[0x68][id * 4] = ent, b[0x5a] = id, the same owner-link clear, ent[5] |= 1, ent[0] = [[0x70039c] + 0x3c], vt[0x88](ent).
static u8 *THISCALL getEntry_63f2d0(u8 *self, u8 *a) {
  u8 *b = *(u8 **)(a + 8);
  u32 id = *(u16 *)(b + 0x5a);
  u8 *ent;
  if (id) {
    ent = *(u8 **)(*(u8 **)(self + 0x68) + (id & 0xfff) * 4);
    if (!(ent[5] & 1)) {
      u32 w = *(u16 *)(ent + 6);
      if ((u16)w != 0xffff) {
        *(u16 *)(ent + 6) = 0xffff;
        *(u32 *)(self + w * 4 + 0x270) = 0;
      }
      ent[5] |= 1;
      *(u32 *)ent = *(u32 *)(G(u8 *, 0x70039c) + 0x3c);
    }
    if (ent[0x42] & 1) {
      (*(vent_t *)(*(u8 **)self + 0x8c))(self, ent);
      (*(vent_t *)(*(u8 **)self + 0x88))(self, ent);
    }
    return ent;
  }
  u8 *pool = *(u8 **)(self + 0x21c);
  ent = (*(vpool_t *)(*(u8 **)pool + 8))(pool);
  *(u8 **)(ent + 0x3c) = a;
  u32 n = (ext_4ce7b0(self + 0xb990) + 1) & 0xfff;
  if (n == 0) {
    cb0_t cb = G(cb0_t, 0x7003b0);
    if (!cb) __builtin_trap();
    cb();
  }
  *(u8 **)(*(u8 **)(self + 0x68) + n * 4) = ent;
  *(u16 *)(b + 0x5a) = (u16)n;
  u32 w = *(u16 *)(ent + 6);
  if ((u16)w != 0xffff) {
    *(u16 *)(ent + 6) = 0xffff;
    *(u32 *)(self + w * 4 + 0x270) = 0;
  }
  ent[5] |= 1;
  *(u32 *)ent = *(u32 *)(G(u8 *, 0x70039c) + 0x3c);
  (*(vent_t *)(*(u8 **)self + 0x88))(self, ent);
  return ent;
}
PCREG(63f2d0, getEntry_63f2d0);

// 0x625cc0: cdecl(cvt, p, end, pos) - little-endian scan that tracks a position {line (+0), column (+4)} in a text of 16-bit units (lo = p[0], hi = p[1]). Each unit's class: hi == 0 uses
// cvt[0x4c + lo]; other units use the inline table (hi - 0xd8: 0..3 -> 7, 4..7 -> 8, 0x27 -> 0 when lo >= 0xfe else 0x1d, the rest and out of range -> 0x1d). class - 5: 1 steps 3 bytes, 2 steps 4,
// 4 (class 9) bumps the line, skips the unit and an immediately following class 10 unit and resets the column, 5 (class 10) bumps the line and resets the column; others step 2. Every step but the
// line breaks adds 1 to the column.
static void __attribute__((cdecl)) trackPos_625cc0(const u8 *cvt, const u8 *p, const u8 *end, u32 *pos) {
  if (p == end) return;
  u32 col = pos[1];
  do {
    u32 hi = p[1], lo = p[0];
    u32 cls;
    if (hi == 0) {
      cls = cvt[0x4c + lo];
    } else {
      u32 idx = hi - 0xd8;
      if (idx > 0x27) cls = 0x1d;
      else if (idx < 4) cls = 7;
      else if (idx < 8) cls = 8;
      else if (idx == 0x27) cls = lo < 0xfe ? 0x1d : 0;
      else cls = 0x1d;
    }
    u32 k = cls - 5;
    u32 step = 2;
    if (k <= 5) {
      if (k == 1) step = 3;
      else if (k == 2) step = 4;
      else if (k == 4) {
        pos[0] += 1;
        p += 2;
        if (p != end) {
          u32 h2 = p[1], l2 = p[0];
          u32 c2 = h2 == 0 ? (u32)cvt[0x4c + l2] : ext_62c640(h2, l2);
          if (c2 == 10) p += 2;
        }
        col = 0xffffffffu;
        pos[1] = 0xffffffffu;
        step = 0;
      } else if (k == 5) {
        col = 0xffffffffu;
        pos[1] = 0xffffffffu;
        pos[0] += 1;
      }
    }
    p += step;
    col += 1;
    pos[1] = col;
  } while (p != end);
}
PCREG(625cc0, trackPos_625cc0);

// 0x622540: cdecl(unused, begin, end) -> character - big-endian XML entity name matcher. The unit count n = (end - begin) / 2 (truncating toward zero) selects: 2 units "lt" -> '<' (0x3c),
// "gt" -> '>' (0x3e); 3 units "amp" -> '&' (0x26); 4 units "apos" -> '\'' (0x27) or "quot" -> '"' (0x22). Units are (0, ch) pairs; anything else returns 0.
static u32 __attribute__((cdecl)) entityBE_622540(u32 unused, const u8 *b, const u8 *e) {
  (void)unused;
  s32 len = (s32)(e - b);
  s32 n = (len - (len >> 31)) >> 1;
  if (n == 2) {
    if (b[2] == 0 && b[3] == 0x74 && b[0] == 0) {
      if ((s8)b[1] == 0x67) return 0x3e;
      if ((s8)b[1] == 0x6c) return 0x3c;
    }
    return 0;
  }
  if (n == 3) {
    if (b[0] == 0 && b[1] == 0x61 && b[2] == 0 && b[3] == 0x6d && b[4] == 0 && b[5] == 0x70) return 0x26;
    return 0;
  }
  if (n == 4) {
    if (b[0] != 0) return 0;
    if ((s8)b[1] == 0x61) {
      if (b[2] == 0 && b[3] == 0x70 && b[4] == 0 && b[5] == 0x6f && b[6] == 0 && b[7] == 0x73) return 0x27;
      return 0;
    }
    if ((s8)b[1] == 0x71) {
      if (b[2] == 0 && b[3] == 0x75 && b[4] == 0 && b[5] == 0x6f && b[6] == 0 && b[7] == 0x74) return 0x22;
    }
    return 0;
  }
  return 0;
}
PCREG(622540, entityBE_622540);

// 0x624350: cdecl(cvt, p, end, out) -> 0, 0x2a, -1 or -2 - little-endian scan for the end of a conditional section "<![ ... ]]>" that tracks nesting. The length is rounded down to whole units. Units (lo = p[0],
// hi = p[1]) are classed (hi == 0: cvt[0x4c + lo], else the real 0x62c640(hi, lo)); class actions (jump table 0x624460): 0, 1, 8 stop (*out = p, 0); 2 expects "!" then "[" units after it
// and increments the depth (a mismatch just continues); 4 expects "]" then ">" after it: at depth 0 *out = past the ">" and 0x2a is returned, else the depth drops; 5 skips 2 (needs 2 left, else -2); 6 skips 3
// (needs 3); 7 skips 4 (needs 4); every other class skips 2. Reaching end returns -1.
static s32 __attribute__((cdecl)) endCondSection_624350(const u8 *cvt, const u8 *p, const u8 *end, const u8 **out) {
  s32 len = (s32)(end - p);
  if (len & 1) end = p + (len & ~1);
  u32 depth = 0;
  if (p == end) return -1;
  s32 rem = (s32)(end - p);
#define UNIT_IS(q, ch) ((q)[1] == 0 && (q)[0] == (ch))
  for (;;) {
    u32 hi = p[1], lo = p[0];
    u32 cls = hi == 0 ? (u32)cvt[0x4c + lo] : ext_62c640(hi, lo);
    if (cls == 0 || cls == 1 || cls == 8) {
      *out = p;
      return 0;
    }
    if (cls == 2) {
      p += 2;
      rem -= 2;
      if (p == end) return -1;
      if (UNIT_IS(p, 0x21)) {
        p += 2;
        rem -= 2;
        if (p == end) return -1;
        if (UNIT_IS(p, 0x5b)) {
          depth++;
          p += 2;
          rem -= 2;
        }
      }
    } else if (cls == 4) {
      p += 2;
      rem -= 2;
      if (p == end) return -1;
      if (UNIT_IS(p, 0x5d)) {
        p += 2;
        rem -= 2;
        if (p == end) return -1;
        if (UNIT_IS(p, 0x3e)) {
          p += 2;
          rem -= 2;
          if (depth == 0) {
            *out = p;
            return 0x2a;
          }
          depth--;
        }
      }
    } else if (cls == 5) {
      if (rem < 2) return -2;
      p += 2;
      rem -= 2;
    } else if (cls == 6) {
      if (rem < 3) return -2;
      p += 3;
      rem -= 3;
    } else if (cls == 7) {
      if (rem < 4) return -2;
      p += 4;
      rem -= 4;
    } else {
      p += 2;
      rem -= 2;
    }
    if (p == end) return -1;
  }
#undef UNIT_IS
}
PCREG(624350, endCondSection_624350);

// 0x626500: cdecl(cvt, p, end, out) - the big-endian twin of 0x624350 (units are (hi = p[0], lo = p[1]); same actions, jump table 0x626610).
static s32 __attribute__((cdecl)) endCondSectionBE_626500(const u8 *cvt, const u8 *p, const u8 *end, const u8 **out) {
  s32 len = (s32)(end - p);
  if (len & 1) end = p + (len & ~1);
  u32 depth = 0;
  if (p == end) return -1;
  s32 rem = (s32)(end - p);
#define UNIT_IS(q, ch) ((q)[0] == 0 && (q)[1] == (ch))
  for (;;) {
    u32 hi = p[0], lo = p[1];
    u32 cls = hi == 0 ? (u32)cvt[0x4c + lo] : ext_62c640(hi, lo);
    if (cls == 0 || cls == 1 || cls == 8) {
      *out = p;
      return 0;
    }
    if (cls == 2) {
      p += 2;
      rem -= 2;
      if (p == end) return -1;
      if (UNIT_IS(p, 0x21)) {
        p += 2;
        rem -= 2;
        if (p == end) return -1;
        if (UNIT_IS(p, 0x5b)) {
          depth++;
          p += 2;
          rem -= 2;
        }
      }
    } else if (cls == 4) {
      p += 2;
      rem -= 2;
      if (p == end) return -1;
      if (UNIT_IS(p, 0x5d)) {
        p += 2;
        rem -= 2;
        if (p == end) return -1;
        if (UNIT_IS(p, 0x3e)) {
          p += 2;
          rem -= 2;
          if (depth == 0) {
            *out = p;
            return 0x2a;
          }
          depth--;
        }
      }
    } else if (cls == 5) {
      if (rem < 2) return -2;
      p += 2;
      rem -= 2;
    } else if (cls == 6) {
      if (rem < 3) return -2;
      p += 3;
      rem -= 3;
    } else if (cls == 7) {
      if (rem < 4) return -2;
      p += 4;
      rem -= 4;
    } else {
      p += 2;
      rem -= 2;
    }
    if (p == end) return -1;
  }
#undef UNIT_IS
}
PCREG(626500, endCondSectionBE_626500);

typedef u32 (__attribute__((cdecl)) *seqchk_t)(const u8 *cvt, const u8 *p);

// 0x62b2f0: cdecl(quote, cvt, p, end, out) -> 0, 0x1b, -1, -2 or -27 - the single-byte-unit form of readQuotedBE (0x627a80, batch 857). The class of each byte is cvt[0x4c + byte]; actions (table 0x62b418 /
// jump table 0x62b400): 0, 1, 8 stop (*out = p, 0); 5 needs 2 bytes left (else -2) and calls cvt[0x164](cvt, p): nonzero stops, else skips 2; 6 needs 3, cvt[0x168], skips 3; 7 needs 4, cvt[0x16c], skips 4;
// 12 and 13 skip 1 and, when the class equals `quote`, end the value: end of input -27, else *out = p and the class of the next byte minus 9 (tables 0x62b428 / 0x62b430) decides 0x1b or 0; every other class skips 1.
static s32 __attribute__((cdecl)) readQuotedByte_62b2f0(u32 quote, const u8 *cvt, const u8 *p, const u8 *end, const u8 **out) {
  if (p == end) return -1;
  s32 rem = (s32)(end - p);
  for (;;) {
    u32 cls = cvt[0x4c + *p];
    u32 act = 5;
    if (cls <= 0xd) {
      static const u8 tab[14] = {0, 0, 5, 5, 5, 1, 2, 3, 0, 5, 5, 5, 4, 4};
      act = tab[cls];
    }
    if (act == 0) {
      *out = p;
      return 0;
    }
    if (act == 1 || act == 2 || act == 3) {
      u32 n = act + 1;
      if (rem < (s32)n) return -2;
      u32 r = (*(seqchk_t *)(cvt + 0x164 + 4 * (act - 1)))(cvt, p);
      if (r) {
        *out = p;
        return 0;
      }
      p += n;
      rem -= n;
    } else if (act == 5) {
      p++;
      rem--;
    } else {
      p++;
      rem--;
      if (cls == quote) {
        if (p == end) return -27;
        *out = p;
        u32 k = (u32)cvt[0x4c + *p] - 9;
        if (k > 0x15) return 0;
        static const u8 t2[22] = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0};
        return t2[k] ? 0 : 0x1b;
      }
    }
    if (p == end) return -1;
  }
}
PCREG(62b2f0, readQuotedByte_62b2f0);

// 0x6261b0: cdecl(cvt, p, end, out) -> 0, 0x2a, -1 or -2 - the single-byte-unit form of endCondSection (0x624350 / 0x626500): classes cvt[0x4c + byte]; 0, 1, 8 stop (*out = p, 0); 2 expects '!' then '[' bytes after it
// and increments the depth (a mismatch continues); 4 expects ']' then '>' after it: at depth 0 *out = past the '>' and 0x2a, else the depth drops; 5, 6, 7 need 2, 3, 4 bytes left (else -2), call the checker
// cvt[0x164 / 0x168 / 0x16c](cvt, p) (nonzero stops with *out = p, 0) and skip 2, 3, 4; every other class skips 1. End returns -1.
static s32 __attribute__((cdecl)) endCondSectionByte_6261b0(const u8 *cvt, const u8 *p, const u8 *end, const u8 **out) {
  u32 depth = 0;
  if (p == end) return -1;
  s32 rem = (s32)(end - p);
  for (;;) {
    u32 cls = cvt[0x4c + *p];
    if (cls == 0 || cls == 1 || cls == 8) {
      *out = p;
      return 0;
    }
    if (cls == 2) {
      p++;
      rem--;
      if (p == end) return -1;
      if (*p == 0x21) {
        p++;
        rem--;
        if (p == end) return -1;
        if (*p == 0x5b) {
          depth++;
          p++;
          rem--;
        }
      }
    } else if (cls == 4) {
      p++;
      rem--;
      if (p == end) return -1;
      if (*p == 0x5d) {
        p++;
        rem--;
        if (p == end) return -1;
        if (*p == 0x3e) {
          p++;
          rem--;
          if (depth == 0) {
            *out = p;
            return 0x2a;
          }
          depth--;
        }
      }
    } else if (cls == 5 || cls == 6 || cls == 7) {
      u32 n = cls - 3;
      if (rem < (s32)n) return -2;
      if ((*(seqchk_t *)(cvt + 0x164 + 4 * (cls - 5)))(cvt, p)) {
        *out = p;
        return 0;
      }
      p += n;
      rem -= n;
    } else {
      p++;
      rem--;
    }
    if (p == end) return -1;
  }
}
PCREG(6261b0, endCondSectionByte_6261b0);

extern "C" void FASTCALL ext_6383a0(u32 flag, s32 *buf, s32 *a, s32 *b);   // hooked (GUESS): fills the 4-entry palette (16 dwords), ret 8

// 0x63a460: fastcall(flag, ch, A, B, px, limit) ret 0x10 - /GS cookie not modelled. A and B are 3-dword endpoint colours ((v >> 5 | v) widening, the second component uses >> 6 for B and for A when flag == 0);
// 0x6383a0 fills a 16-dword palette (4 entries x 4 channels); then for up to 16 pixels (16 bytes each, channel ch at +4 * ch, alpha at +12) the squared error is summed: against palette entry 3 when the
// pixel's alpha is 0, else the minimum over the four entries (signed 32-bit squares and signed compares); stops once the sum exceeds limit (signed) and returns the sum.
static s32 FASTCALL paletteError_63a460(u32 flag, u32 ch, s32 *A, s32 *B, s32 *px, s32 limit) {
  s32 LA[3], LB[3], buf[16];
  LA[0] = (A[0] >> 5) | A[0];
  LB[0] = (B[0] >> 5) | B[0];
  LA[1] = (flag == 0 ? (A[1] >> 6) : (A[1] >> 5)) | A[1];
  LB[1] = (B[1] >> 6) | B[1];
  LA[2] = (A[2] >> 5) | A[2];
  LB[2] = (B[2] >> 5) | B[2];
  ext_6383a0(flag, buf, LA, LB);
  s32 sum = 0;
  for (int i = 0; i < 16; i++) {
    s32 term;
    s32 *p = px + 4 * i;
    if (p[3] == 0) {
      s32 d = p[ch] - buf[12 + ch];
      term = (s32)((u32)d * (u32)d);
    } else {
      s32 v = p[ch];
      s32 m = 0x7fffffff;
      for (int k = 0; k < 4; k++) {
        s32 d = v - buf[4 * k + ch];
        s32 sq = (s32)((u32)d * (u32)d);
        if (sq < m) m = sq;
      }
      term = m;
    }
    sum = (s32)((u32)sum + (u32)term);
    if (sum > limit) break;
  }
  return sum;
}
PCREG(63a460, paletteError_63a460);
