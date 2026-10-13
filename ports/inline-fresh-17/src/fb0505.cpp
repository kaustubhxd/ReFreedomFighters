// fb0505.cpp - fresh slice 17, batch 5.
#include "ff.h"

extern "C" u32 THISCALL ext_578560(void *self);
extern "C" u32 THISCALL ext_57a440(void *self);
extern "C" u32 THISCALL ext_57c7c0(void *self);
extern "C" u32 THISCALL ext_5c0a60(void *self);    // CEnemyFlag::CEnemyFlag()
extern "C" u8 *THISCALL ext_5003d0(void *arr, u32 i);
extern "C" u32 THISCALL ext_4e5e60(void *rd);      // DBREAD::operator unsigned int()
extern "C" u32 THISCALL ext_4e5e40(void *rd);      // DBREAD::operator unsigned short() (AX)
extern "C" u32 THISCALL ext_448a30(u8 *self, void *blk);   // ZLIGHT::CopyDataBlock
extern "C" u32 THISCALL ext_4e1600(void *blk);     // DBLK::GetType() (AL)
extern "C" u32 THISCALL ext_4e12f0(void *blk, float *dst, int n);
extern "C" u32 THISCALL ext_4e12e0(void *blk, u32 *dst, int n);
extern "C" u32 THISCALL ext_4e1b30(void *blk);     // DBLK::NextBlock()

typedef u32 (*voidfn)();
#define g_pAssertHook G(voidfn, 0x7003b0)
static inline void assertHook() {
  if (!g_pAssertHook)
    __builtin_debugtrap();
  g_pAssertHook();
}

// Four object factories with one shape (SEH frame not reproduced: it only guards the constructor call and is restored
// on return). The allocator is the engine db's (+0x9b) object at +8, slot +0x44(x) where x arrives in ECX (LTCG
// register argument, passed straight on). A non-null block is constructed in place; returns the block.
static inline void *engineAlloc(u32 x) {
  void *a = *(void **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 8);
  return (void *)vcall<u32>(a, 0x44, x);
}
// 0x578890 (GUESS factory for the object built by 0x578560)
static void *FASTCALL create578890(u32 x) {
  void *p = engineAlloc(x);
  if (p)
    ext_578560(p);
  return p;
}
PCREG(578890, create578890);
// 0x57a550 (GUESS factory for 0x57a440)
static void *FASTCALL create57a550(u32 x) {
  void *p = engineAlloc(x);
  if (p)
    ext_57a440(p);
  return p;
}
PCREG(57a550, create57a550);
// 0x57cad0 (GUESS factory for 0x57c7c0)
static void *FASTCALL create57cad0(u32 x) {
  void *p = engineAlloc(x);
  if (p)
    ext_57c7c0(p);
  return p;
}
PCREG(57cad0, create57cad0);
// 0x5c0f50 (GUESS CEnemyFlag factory)
static void *FASTCALL create5c0f50(u32 x) {
  void *p = engineAlloc(x);
  if (p)
    ext_5c0a60(p);
  return p;
}
PCREG(5c0f50, create5c0f50);

// 0x4ce110 STRREFTAB::FindStr(const char*): null table -> 0. Iterates (slot +0x4c starts a 12-byte iterator, slot +0x64
// returns the next entry) and returns the first entry whose string (entry[0]) matches by _stricmp; 0 when none.
typedef int (*stricmp_t)(const char *, const char *);
static u32 *THISCALL findStr4ce110(u8 *self, const char *s) {
  if (!self)
    return 0;
  u32 it[3];
  vcall<u32>(self, 0x4c, (void *)it);
  for (u32 *e = (u32 *)vcall<u32>(self, 0x64, (void *)it); e; e = (u32 *)vcall<u32>(self, 0x64, (void *)it))
    if ((*(stricmp_t *)0x676414)((const char *)e[0], s) == 0)
      return e;
  return 0;
}
PCREG(4ce110, findStr4ce110);

// 0x6058d0 (GUESS slot assign between two arrays): asserts first (hook). dst = 0x5003d0(arg[2], 0), src = 0x5003d0(arg[1], 0);
// when different, a kind-4 dst releases its object (slot +0x28); a kind-4 src gives a new object from its slot +0x24,
// any other kind copies the word; the kind byte is copied.
static void THISCALL slotAssign6058d0(u8 *, u8 *arg) {
  assertHook();
  u8 *src = ext_5003d0(*(void **)(arg + 4), 0);
  u8 *dst = ext_5003d0(*(void **)(arg + 8), 0);
  if (src == dst)
    return;
  if (dst[4] == 4)
    vcall<u32>(*(void **)dst, 0x28);
  if (src[4] != 4) {
    *(u32 *)dst = *(u32 *)src;
    dst[4] = src[4];
    return;
  }
  *(u32 *)dst = vcall<u32>(*(void **)src, 0x24);
  dst[4] = src[4];
}
PCREG(6058d0, slotAssign6058d0);

// 0x5bfa10 CLogicOperatorEvaluatorTriggerFunctions::ReadInput(DBREAD&): reads u32 +0x48, u16 +0x51/+0x53/+0x55/+0x57,
// u32 +0x5d, u16 +0x66/+0x68, u32 +0x6e in that order.
static void THISCALL readInput5bfa10(u8 *self, void *rd) {
  *(u32 *)(self + 0x48) = ext_4e5e60(rd);
  *(u16 *)(self + 0x51) = (u16)ext_4e5e40(rd);
  *(u16 *)(self + 0x53) = (u16)ext_4e5e40(rd);
  *(u16 *)(self + 0x55) = (u16)ext_4e5e40(rd);
  *(u16 *)(self + 0x57) = (u16)ext_4e5e40(rd);
  *(u32 *)(self + 0x5d) = ext_4e5e60(rd);
  *(u16 *)(self + 0x66) = (u16)ext_4e5e40(rd);
  *(u16 *)(self + 0x68) = (u16)ext_4e5e40(rd);
  *(u32 *)(self + 0x6e) = ext_4e5e60(rd);
}
PCREG(5bfa10, readInput5bfa10);

// 0x4488d0 ZGateLightSpot::CopyDataBlock(DBLK*): ZLIGHT part first; a type-1 block holds three floats that are read and
// dropped (old format); then the next block gives this+0x1c and this+0x20, and the block after it is skipped to.
static void THISCALL copyDataBlock4488d0(u8 *self, void *blk) {
  float skip[3];
  ext_448a30(self, blk);
  if ((u8)ext_4e1600(blk) == 1) {
    ext_4e12f0(blk, &skip[0], 1);
    ext_4e12f0(blk, &skip[1], 1);
    ext_4e12f0(blk, &skip[2], 1);
  }
  ext_4e1b30(blk);
  ext_4e12e0(blk, (u32 *)(self + 0x1c), 1);
  ext_4e12e0(blk, (u32 *)(self + 0x20), 1);
  ext_4e1b30(blk);
}
PCREG(4488d0, copyDataBlock4488d0);

// 0x648810 (GUESS sorted insert, up to 16 pairs): count at +0, values at +4, keys (signed, descending) at +0x44.
// Asserts when already full. The insert index i is the first key below `key` (count when none). The shift moves
// pairs i-1 .. count-1 up by one (one more than needed; the extra copy lands in slot i, which the store then
// overwrites), then stores the pair at i, counts, returns i.
static u32 THISCALL sortedInsert648810(u8 *self, u32 *pval, s32 key) {
  if (*(s32 *)self == 0x10)
    assertHook();
  s32 n = *(s32 *)self;
  s32 *keys = (s32 *)(self + 0x44);
  u32 *vals = (u32 *)(self + 4);
  s32 i = 0;
  if (n) {
    for (; i != n; i++)
      if (keys[i] < key)
        break;
    if (i != n && n != i - 1)
      for (s32 j = n - 1, k = n - (i - 1); k; j--, k--) {
        keys[j + 1] = keys[j];
        vals[j + 1] = vals[j];
      }
  }
  keys[i] = key;
  vals[i] = *pval;
  *(s32 *)self += 1;
  return (u32)i;
}
PCREG(648810, sortedInsert648810);
