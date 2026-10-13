// fb1212.cpp - fresh slice 17, batch 12.
#include "ff.h"

extern "C" u32 ext_40e240(void *s, float *buf);
extern "C" u32 ext_407770(float *buf, u32 out, u32 n, u32 t);
extern "C" u32 ext_4690b0(void *p, u32 line);                                 // empty (operator delete stand-in)

typedef void (*voidfn)();
#define g_pAssertHook G(voidfn, 0x7003b0)

static inline void *engineDb() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x4078d0 (GUESS spectrum helper, cdecl (in, out, s)): n = s+0xc; complex buffer of n pairs on the stack (alloca),
// re = in[i] * (0.5 / n) (0x6bdffc; long double = x87, follows the control word like the exe), im = 0, then the last imaginary part is set to
// in[n-1] * (0.5 / n); 0x40e240(s, buf) transforms it, the two halves of the 2n floats are swapped (the floats moving from
// the low half go through fld/fstp; the port does the same with inline x87) and 0x407770(buf, out, 2n, s+0x10) returns the result.
static inline void x87Move(u32 *dst, const u32 *src) {   // fld dword / fstp dword, exactly as the original
  asm volatile("flds %1\n\tfstps %0" : "=m"(*dst) : "m"(*src));
}
static u32 spectrum4078d0(float *in, u32 out, u8 *s) {
  s32 n = *(s32 *)(s + 0xc);
  u32 t = *(u32 *)(s + 0x10);
  float *buf = (float *)__builtin_alloca(((u32)n * 8 + 3) & ~3u);
  long double sc = (long double)G(float, 0x6bdffc) / (long double)n;
  for (s32 i = 0; i < n; i++) {
    buf[2 * i] = (float)(sc * (long double)in[i]);
    ((u32 *)buf)[2 * i + 1] = 0;
  }
  buf[2 * n - 1] = (float)(sc * (long double)in[n - 1]);
  s32 m = n * 2;
  ext_40e240(s, buf);
  s32 h = m / 2;
  u32 *b = (u32 *)buf;
  for (s32 k = 0; k < h; k++) {
    u32 lo = b[k];
    b[k] = b[h + k];
    x87Move(&b[h + k], &lo);
  }
  return ext_407770(buf, out, (u32)m, t);
}
PCREG(4078d0, spectrum4078d0);

// 0x449050 ZSPOTLIGHT::Draw(ZDrawBuffer* db, ZCAMERA* cam, const float* a, const float* b): only when enabled (+0x14 bit 0).
// Gets the light's 0x38-byte record from (engine +0x1aa3)->+0x18 slot +0x84(geom +8 ->+0x6c, &rec), then db slot
// +0x94(a, b, cam, (+0x14 >> 3) & 1), slot +0x9c(a, b, rec+0x24, rec+0x1c) and slot +0x98(a, b, rec+0x28, rec+0x18).
static void THISCALL draw449050(u8 *self, void *db, u32 cam, u32 a, u32 b) {
  if (!(self[0x14] & 1))
    return;
  u32 rec[14];
  vcall<u32>(*(void **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18), 0x84, *(u32 *)(*(u8 **)(self + 8) + 0x6c), rec);
  vcall<u32>(db, 0x94, a, b, cam, (u32)((*(u32 *)(self + 0x14) >> 3) & 1));
  vcall<u32>(db, 0x9c, a, b, rec[0x24 / 4], rec[0x1c / 4]);
  vcall<u32>(db, 0x98, a, b, rec[0x28 / 4], rec[0x18 / 4]);
}
PCREG(449050, draw449050);

// ZDrawArray<...>::Remove(entry) for two more entry types (same body as 0x64da90, fb1010.cpp): block = slot +0x2c(entry),
// entry flag 0x02 cleared (+5 or +9), entry pushed on the block's free list (slot index = (entry - block - 0x10) / size,
// signed), use count dropped; an empty block is unlinked and released (slot +0x34), else moved to the ring head.
static inline void drawArrayRemove(u8 *self, u8 *ent, s32 size, u32 flagOff) {
  *(u32 *)(self + 0xc) -= 1;
  u8 *blk = vcall<u8 *>(self, 0x2c, ent);
  ent[flagOff] &= 0xfd;
  blk[0] -= 1;
  *(u16 *)ent = *(u16 *)(blk + 2);
  *(u16 *)(blk + 2) = (u16)((s32)(ent - blk - 0x10) / size);
  if (blk[0] == 0) {
    if (*(u8 **)(self + 8) == blk) {
      u8 *n = *(u8 **)(blk + 8);
      *(u8 **)(self + 8) = n == blk ? 0 : n;
    }
    *(u32 *)(*(u8 **)(blk + 8) + 0xc) = *(u32 *)(blk + 0xc);
    *(u32 *)(*(u8 **)(blk + 0xc) + 8) = *(u32 *)(blk + 8);
    vcall<u32>(self, 0x34, blk);
    return;
  }
  if (blk == *(u8 **)(self + 8))
    return;
  *(u32 *)(*(u8 **)(blk + 8) + 0xc) = *(u32 *)(blk + 0xc);
  *(u32 *)(*(u8 **)(blk + 0xc) + 8) = *(u32 *)(blk + 8);
  u8 *h = *(u8 **)(self + 8);
  *(u8 **)(blk + 8) = h;
  u8 *t = *(u8 **)(h + 0xc);
  *(u8 **)(blk + 0xc) = t;
  *(u8 **)(t + 8) = blk;
  *(u8 **)(h + 0xc) = blk;
  *(u8 **)(self + 8) = blk;
}
// 0x6152d0 ZDrawArray<ZPrimInstDrawEntryGC, ZPrimInstDrawEntry, ZArrayBlock>::Remove: entries 0x1c bytes, flag at +5.
static void THISCALL remove6152d0(u8 *self, u8 *ent) { drawArrayRemove(self, ent, 0x1c, 5); }
PCREG(6152d0, remove6152d0);
// 0x615f50 ZDrawArray<ZCameraViewEntryGC, ZCameraViewEntry, ZArrayBlock>::Remove: entries 0x138 bytes, flag at +9.
static void THISCALL remove615f50(u8 *self, u8 *ent) { drawArrayRemove(self, ent, 0x138, 9); }
PCREG(615f50, remove615f50);

// 0x4d43d0 (GUESS cycle text slots(bool forward)): with slot 0 (+0xfb7) set, the index (+0x10d7) steps forward (wraps
// 20 -> 0) or back (-1 -> 19) to the next non-empty slot of the 20 string pointers at +0xfb7; that string is copied to
// +0x1008 and +0x10cf = strlen(+0x1007) (the original measures from one byte before the copy).
static void THISCALL cycleText4d43d0(u8 *self, u32 fwd) {
  if (!*(u32 *)(self + 0xfb7))
    return;
  s32 *idx = (s32 *)(self + 0x10d7);
  if (fwd & 0xff) {
    do {
      if (++*idx == 0x14)
        *idx = 0;
    } while (!*(u32 *)(self + *idx * 4 + 0xfb7));
  } else {
    do {
      if (--*idx == -1)
        *idx = 0x13;
    } while (!*(u32 *)(self + *idx * 4 + 0xfb7));
  }
  const char *s = *(const char **)(self + *idx * 4 + 0xfb7);
  if (!s)
    return;
  char *d = (char *)(self + 0x1008);
  char ch;
  do {
    ch = *s++;
    *d++ = ch;
  } while (ch);
  volatile const char *p = (const char *)(self + 0x1007);
  u32 len = 0;
  while (p[len])
    len++;
  *(u32 *)(self + 0x10cf) = len;
}
PCREG(4d43d0, cycleText4d43d0);

// 0x4c3990 / 0x5d38d0: deleting destructors of two ZEventBase-like classes (ZParticleEmitter, CMPCheckInsideHill) with the
// same body: +0x44 = +0x30 = 0, vtable 0x686874, engine db slot +0x34(this) (unregister). Flag bit 0 without bit 2 hits the
// assert hook (int3 when none); bits 0 and 2 call the empty 0x4690b0(this, line 0xa6 / 0x89). Returns this. SEH not
// reproduced.
static inline u8 *eventDtor(u8 *self, u32 flags, u32 line) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<u32>(engineDb(), 0x34, self);
  if (flags & 1) {
    if (!(flags & 4)) {
      if (!g_pAssertHook)
        __builtin_debugtrap();
      g_pAssertHook();
      return self;
    }
    ext_4690b0(self, line);
  }
  return self;
}
static u8 *THISCALL dtor4c3990(u8 *self, u32 flags) { return eventDtor(self, flags, 0xa6); }
PCREG(4c3990, dtor4c3990);
static u8 *THISCALL dtor5d38d0(u8 *self, u32 flags) { return eventDtor(self, flags, 0x89); }
PCREG(5d38d0, dtor5d38d0);
