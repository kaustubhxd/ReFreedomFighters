// batch0106.cpp - fresh-01 batch 6 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" u8 FASTCALL ext_4cc4b0(u32 a, u32 b);                       // case-insensitive char equal (cl, dl)
extern "C" void THISCALL ext_4a6270(u8 *p);                            // constructor (name map: static init)
extern "C" void THISCALL ext_4b1ca0(u8 *p);                            // CCutSequenceCharacterSound ctor
extern "C" u32 THISCALL ext_603500(u8 *p, u32 n);                      // OpaqueUserType_t::OpaqueUserType_t(int)
extern "C" void *ext_41e290(u32 size);                                 // operator new (cdecl)
extern "C" void FASTCALL ext_633654(u32 cookie);                       // __security_check_cookie

typedef u32 (*handlerFn)();
typedef void *(*memcpyFn)(void *, const void *, u32);
typedef void (*qsortFn)(void *, u32, u32, u32);

// 0x4d0950 (unnamed, id pool): p = pool(this+0x1ea) slot 8(arg, 0); a null p calls the handler at [0x7003b0] (int3
// when unset) and goes on; then the free count this+0xd628 is decremented and slot [this+0xc628 + count*4] =
// pool slot 4(p). The pool's vtable is read before the decrement. Returns the stored value.
static u32 THISCALL pool4d0950(u8 *self, u32 arg) {
  u8 *pool = self + 0x1ea;
  u32 p = vcall<u32>(pool, 8, arg, 0u);
  if (!p) {
    handlerFn h = G(handlerFn, 0x7003b0);
    if (!h) __builtin_debugtrap();
    h();
  }
  u8 *vt = *(u8 **)pool;
  s32 i = --*(s32 *)(self + 0xd628);
  typedef u32(THISCALL * f4)(void *, u32);
  u32 v = (*(f4 *)(vt + 4))(pool, p);
  *(u32 *)(self + i * 4 + 0xc628) = v;
  return v;
}
PCREG(4d0950, pool4d0950);

// 0x499810 (unnamed): when bit 0x8000000 of entry+0x3c is clear, table([this+0x5d])[i] = v with
// i = (s32)(entry - [this+0x14]+4)/112 - (u32)[this+0x28]/112 (entries are 112 bytes); when set, v is written to address
// 0 (a crash in the original too).
static void THISCALL setSlot499810(u8 *self, u8 *entry, u32 v) {
  if (*(u32 *)(entry + 0x3c) & 0x8000000) {
    u32 *z;
    asm volatile("xor %0, %0" : "=r"(z));
    *z = v;
    return;
  }
  s32 a = (s32)((u32)entry - *(u32 *)(*(u8 **)(self + 0x14) + 4)) / 112;
  s32 b = (s32)(*(u32 *)(self + 0x28) / 112u);
  *(u32 *)(*(u8 **)(self + 0x5d) + (a - b) * 4) = v;
}
PCREG(499810, setSlot499810);

// 0x5f1050 (unnamed, find_last_of style, fastcall: out in ECX, set begin in EDX; stack: last, first, set end, unused):
// scans backwards from last to first for a character (p[-1]) that equals (case-insensitive, 0x4cc4b0) one in
// [set begin, set end); *out = p (one past the match), or first when none; returns out.
static const u8 **FASTCALL findLastOf5f1050(const u8 **out, const u8 *sb, const u8 *last, const u8 *first,
                                            const u8 *se, u32 unused) {
  while (last != first) {
    for (const u8 *q = sb; q != se; q++)
      if (ext_4cc4b0(last[-1], *q)) {
        *out = last;
        return out;
      }
    last--;
  }
  *out = first;
  return out;
}
PCREG(5f1050, findLastOf5f1050);

// 0x5fba50 (unnamed, string find_last_of(s, pos)): buffer [this+0]..[this+4]; -1 when it is empty; else searches
// [begin, begin + 1 + min(pos, size - 1)) backwards for any character of s (case-insensitive) and returns its index,
// or -1.
static s32 THISCALL strFindLastOf(u8 **self, const u8 *s, u32 pos) {
  u32 len = 0;
  while (s[len]) len++;
  u8 *b = self[0];
  u32 size = (u32)(self[1] - b);
  if (size < 1) return -1;
  u32 m = size - 1;
  if (pos < m) m = pos;
  const u8 *r;
  findLastOf5f1050(&r, s, b + 1 + m, b, s + len, (u32)s);
  if (r == self[0]) return -1;
  return (s32)(r - self[0]) - 1;
}
PCREG(5fba50, strFindLastOf);

// 0x429b50 (unnamed): slot 0x2c on each of the [this+0xc] objects at this+4, slot 0x2c on each of the [this+0x1c]
// objects at this+0x10, and slot 0x54 on each of the [this+0x60] objects at this+0x20. Counts are re-read every step.
static void THISCALL callAll429b50(u8 *self) {
  for (u32 i = 0; i < *(u32 *)(self + 0xc); i++) vcall<void>(((u8 **)(self + 4))[i], 0x2c);
  for (u32 i = 0; i < *(u32 *)(self + 0x1c); i++) vcall<void>(((u8 **)(self + 0x10))[i], 0x2c);
  for (u32 i = 0; i < *(u32 *)(self + 0x60); i++) vcall<void>(((u8 **)(self + 0x20))[i], 0x54);
}
PCREG(429b50, callAll429b50);

// 0x4a63d0 / 0x4b2950 (unnamed factories): p = allocator (render+8 object) slot 0x44; the incoming ECX is pushed as
// that call's stack word (GUESS: the slot takes one argument; the push is kept as is). When p is set, the class
// constructor runs on it. Returns p.
static u8 *THISCALL factory4a63d0(u32 ecxIn) {
  u8 *a = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 8);
  u8 *p = vcall<u8 *>(a, 0x44, ecxIn);
  if (p) ext_4a6270(p);
  return p;
}
PCREG(4a63d0, factory4a63d0);

static u8 *THISCALL factory4b2950(u32 ecxIn) {
  u8 *a = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 8);
  u8 *p = vcall<u8 *>(a, 0x44, ecxIn);
  if (p) ext_4b1ca0(p);
  return p;
}
PCREG(4b2950, factory4b2950);

// 0x4d3f10 (unnamed sorted dword array constructor (src, n)): n at +8, vtable 0x6965c0, +0xc = +0x10 = 0; data (+4) =
// new(n*4, or -1 on overflow); copies n dwords from src and qsorts them (4 bytes, compare 0x4cc600). Returns this.
static u8 *THISCALL sortedArrayCtor(u8 *self, const void *src, u32 n) {
  *(u32 *)(self + 8) = n;
  u64 bytes = (u64)n * 4;
  *(u32 *)self = 0x6965c0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  void *p = ext_41e290((bytes >> 32) ? 0xffffffffu : (u32)bytes);
  *(void **)(self + 4) = p;
  (*(memcpyFn *)0x67626c)(p, src, *(u32 *)(self + 8) << 2);
  (*(qsortFn *)0x676450)(*(void **)(self + 4), *(u32 *)(self + 8), 4, 0x4cc600);
  return self;
}
PCREG(4d3f10, sortedArrayCtor);

// 0x5f30d0, OpaqueUserTypeFactory_t::produceOpaqueObject(const char*, int): new(0x18) then OpaqueUserType_t(n) on it
// (returns its EAX); 0 when new fails. The name is not used.
static u32 THISCALL userTypeProduce(u8 *self, u32 name, u32 n) {
  u8 *p = (u8 *)ext_41e290(0x18);
  if (!p) return 0;
  return ext_603500(p, n);
}
PCREG(5f30d0, userTypeProduce);

// 0x5bf550, ZCenter::Init(): v = {(float)(engine+0x6f / 2), (float)(engine+0x73 / 2), 0} (signed halves, truncated);
// (this+0x44 object) slot 0x70(&v); own slot 0x58.
static void THISCALL centerInit(u8 *self) {
  u8 *g = G(u8 *, 0x70039c);
  float v[3];
  v[0] = (float)(*(s32 *)(g + 0x6f) / 2);
  v[2] = bitsf(0);
  v[1] = (float)(*(s32 *)(g + 0x73) / 2);
  vcall<void>(*(u8 **)(self + 0x44), 0x70, (float *)v);
  vcall<void>(self, 0x58);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(5bf550, centerInit);
