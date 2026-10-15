// batch95000.cpp - hard-function trial opus5: 0x479190 (407 instructions, 71 calls), a Load(stream) of a large object (GUESS name).
#include "ff.h"

typedef u32 __attribute__((aligned(1))) u32u;

struct Stream;
typedef Stream *(THISCALL *srd_t)(Stream *, void *);          // read into *p, returns the stream for chaining (slots 0x40/0x50/0x68/0x6c)
typedef void(THISCALL *sraw_t)(Stream *, void *, u32);        // slot 0x18: raw read (ptr, size)
typedef u32(THISCALL *s0_t)(Stream *);                        // slot 0x30
typedef void(THISCALL *s48_t)(Stream *, u32 *);               // slot 0x48
typedef u32(THISCALL *o58_t)(void *, u32);                    // engine sub-object slot 0x58

static inline Stream *R(Stream *s, u32 slot, void *p) { return (*(srd_t **)s)[slot / 4](s, p); }
static inline void RAW(Stream *s, void *p, u32 n) { ((sraw_t)(*(void ***)s)[0x18 / 4])(s, p, n); }

extern "C" void THISCALL ext_474770(u8 *self, Stream *s);    // base Load, ret 4
extern "C" void *ext_41e290(u32 size);                        // operator new, cdecl
extern "C" u8 *THISCALL ext_476dc0(void *mem, u32 n);         // constructor, ret 4, returns this

// MSVC C++ EH registration record: next, handler, state (the /GS cookie push before it is not modelled).
struct SehRecord {
  u32 next;
  u32 handler;
  u32 state;
};
static inline u32 seh_head() {
  u32 v;
  __asm__ volatile("movl %%fs:0, %0" : "=r"(v));
  return v;
}
static inline void seh_set(u32 v) { __asm__ volatile("movl %0, %%fs:0" : : "r"(v) : "memory"); }

// 0x479190, thiscall(stream) ret 4, returns true. Reads every saved field of the object in a fixed order; an optional
// sub-object (+0x695) is created with new(0x18) + 0x476dc0 inside EH state 0, then its two arrays are read raw.
static bool THISCALL fn479190(u8 *self, Stream *s) {
  volatile SehRecord rec;
  rec.next = seh_head();
  rec.handler = 0x66726f;
  rec.state = 0xffffffff;
  seh_set((u32)&rec);

  u32 l10, l14, l18, l1c, l20, l28;
  u8 flag;
  ext_474770(self, s);
  R(R(s, 0x40, self + 0x5ce), 0x50, self + 0x624);
  R(R(s, 0x40, self + 0x640), 0x50, self + 0x644);
  R(R(R(R(s, 0x40, self + 0x64c), 0x40, self + 0x650), 0x40, self + 0x654), 0x40, self + 0x658);
  R(s, 0x40, &l10);
  R(s, 0x6c, self + 0x660);
  R(R(s, 0x50, self + 0x678), 0x6c, self + 0x67c);
  *(u32 *)(self + 0x65c) = l10;
  R(s, 0x40, &l14);
  void *o = *(void **)(*(u8 **)0x70039c + 0x9b);
  *(u32u *)(self + 0x5b2) = (*(o58_t **)o)[0x58 / 4](o, l14);
  R(s, 0x68, self + 0x690);
  R(s, 0x68, &flag);
  if (flag) {
    RAW(s, &l18, 4);
    void *mem = ext_41e290(0x18);
    rec.state = 0;
    u8 *p = mem ? ext_476dc0(mem, l18) : 0;
    *(u8 **)(self + 0x695) = p;
    rec.state = 0xffffffff;
    R(s, 0x50, (u8 *)((u32)p + 4));     // p may be NULL (failed new): the original passes 4
    u8 *q = *(u8 **)(self + 0x695);
    RAW(s, *(void **)(q + 0xc), *(u32 *)(q + 8) << 4);
    q = *(u8 **)(self + 0x695);
    RAW(s, *(void **)(q + 0x10), *(u32 *)(q + 8) << 2);
  }
  R(R(R(R(R(s, 0x68, self + 0x699), 0x6c, self + 0x69a), 0x6c, self + 0x6a6), 0x50, self + 0x6b2), 0x50, self + 0x6b6);
  R(R(R(R(s, 0x40, self + 0x6bf), 0x68, self + 0x6c5), 0x50, self + 0x6ba), 0x68, self + 0x6c4);
  *(u32u *)(self + 0x6c6) = 0;
  R(s, 0x50, self + 0x6ca);
  R(s, 0x50, self + 0x688);
  R(R(R(s, 0x68, self + 0x6fe), 0x40, self + 0x6ff), 0x68, self + 0x703);
  R(R(s, 0x68, self + 0x704), 0x68, self + 0x705);
  R(R(R(s, 0x50, self + 0x706), 0x50, self + 0x70a), 0x50, self + 0x70e);
  R(R(R(R(s, 0x50, self + 0x712), 0x50, self + 0x716), 0x50, self + 0x71a), 0x50, self + 0x71e);
  R(R(R(s, 0x50, self + 0x722), 0x68, self + 0x726), 0x40, self + 0x727);
  R(s, 0x40, self + 0x736);
  R(s, 0x40, self + 0x73a);
  R(s, 0x40, self + 0x732);
  R(s, 0x68, self + 0x72f);
  R(s, 0x50, self + 0x68c);
  R(s, 0x40, self + 0x648);
  u8 *e = self + 0x4b6;
  for (int i = 0; i < 16; i++, e += 0x10) {
    R(R(R(R(s, 0x40, e - 4), 0x40, e), 0x40, &l1c), 0x40, &l20);
    *(u32u *)(e + 4) = l1c;
    *(u32u *)(e + 8) = l20;
  }
  R(s, 0x40, self + 0x4ae);
  R(s, 0x68, self + 0x754);
  R(R(R(R(s, 0x50, self + 0x755), 0x50, self + 0x759), 0x50, self + 0x75d), 0x50, self + 0x765);
  R(R(s, 0x50, self + 0x769), 0x50, self + 0x76d);
  R(s, 0x68, self + 0x771);
  *(u32u *)(self + 0x74f) = ((s0_t)(*(void ***)s)[0x30 / 4])(s);
  R(s, 0x68, self + 0x5d2);
  ((s48_t)(*(void ***)s)[0x48 / 4])(s, &l28);
  *(u32u *)(self + 0x72b) = l28;

  seh_set(rec.next);
  return true;
}
PCREG(479190, fn479190);
