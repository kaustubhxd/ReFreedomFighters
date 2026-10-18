// batch1915.cpp - fresh slice 19, batch 1915 (docs/20-fresh-19.md). Names from the GameCube name map where it has one.
#include "ff.h"

extern "C" u32 ext_4248e0();                                              // mcrdtsc666 (hooked: RDTSC)
extern "C" void THISCALL ext_5f56f0(u8 *p);                               // Process_t::runProcess (hooked)
extern "C" u8 *ext_5fa630();                                              // (no GC name) singleton getter (hooked)
extern "C" void THISCALL ext_5fd2a0(u8 *o, u8 *p);                        // (no GC name) (hooked)
extern "C" void THISCALL ext_5f3b00(u8 *p);                               // (no GC name) destructor body (hooked)
extern "C" void ext_634273(void *p, u32 n);                               // __builtin_delete (sized, cdecl; hooked)
extern "C" void THISCALL ext_4daa20(u8 *g, u32 on);                       // ZBaseGeom::Display(bool) (hooked)
extern "C" u8 *THISCALL ext_4cc930(u8 *o, u32 a, u32 b);                  // (no GC name) constructor ret 8 (hooked)
extern "C" void ext_634d10(u32 p, u32 v, u32 n);                          // jmp [0x676260] (memset shape, cdecl; hooked)

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))
typedef void (*logf_t)(void *, ...);

// 0x5fd6f0 ScriptEngine_t::scheduleProcesses(): with a scheduler (+0x30) its vt[0](&+0x18) does the work. Else each
// process of the array +0x18 (count +0x20) becomes current (+0x38, after mcrdtsc666) and runs; one whose +0xac has bit
// 0x4000 set is taken out of the array (memmove of (n - j) words, one word more than the tail, as the exe does; nothing when
// it is last), count - 1, 0x5fa630()->vt[0x24](p), 0x5fd2a0(+4, p), destructor 0x5f3b00 and sized delete (0xad2). The
// index still advances after a removal, so the next process waits a round. The exe's assert for index >= count can't
// fire (first round only, count > 0) and is not ported.
typedef void *(*mm_t)(void *, const void *, u32);
static void THISCALL schedule_5fd6f0(u8 *self) {
  if (u8 *sch = *(u8 **)(self + 0x30)) {
    vcall<void>(sch, 0, self + 0x18);
    return;
  }
  for (u32 i = 0; i < *(u32 *)(self + 0x20); i++) {
    u8 *p = (*(u8 ***)(self + 0x18))[i];
    ext_4248e0();
    *(u8 **)(self + 0x38) = p;
    ext_5f56f0(p);
    if (!(*(u16 *)(p + 0xac) & 0x4000)) continue;
    u32 n = *(u32 *)(self + 0x20);
    u32 j = 0;
    while (j < n && (*(u8 ***)(self + 0x18))[j] != p) j++;
    if (j == n) continue;
    if (j < n - 1) {
      u8 **a = *(u8 ***)(self + 0x18) + j;
      (*(mm_t *)0x676278u)(a, a + 1, (n - j) * 4);
    }
    (*(u32 *)(self + 0x20))--;
    vcall<void>(ext_5fa630(), 0x24, p);
    ext_5fd2a0(*(u8 **)(self + 4), p);
    ext_5f3b00(p);
    ext_634273(p, 0xad2);
  }
}
PCREG(5fd6f0, schedule_5fd6f0);

// 0x4e69b0 (no GC name) fastcall (keys, vals; lo, hi) ret 8: quicksort of unsigned keys with a parallel value array; the
// pivot index comes from the global generator 0x6e7b9c (s += 3 + rol(s, s & 31); (s & 0xffffff) % (hi - lo + 1) + lo,
// signed); recursion on the left part, loop on the right.
static void FASTCALL qsort_4e69b0(u32 *k, u32 *v, s32 lo, s32 hi) {
  for (;;) {
    u32 s = G(u32, 0x6e7b9c);
    u32 r = s & 31;
    s = s + 3 + (r ? (s << r) | (s >> (32 - r)) : s);
    G(u32, 0x6e7b9c) = s;
    s32 i = lo, j = hi;
    u32 piv = k[(s32)(G(u32, 0x6e7b9c) & 0xffffff) % (hi - lo + 1) + lo];
    do {
      while (k[i] < piv) i++;
      while (k[j] > piv) j--;
      if (i > j) break;
      u32 t = k[i];
      k[i] = k[j];
      k[j] = t;
      t = v[i];
      v[i] = v[j];
      v[j] = t;
      i++;
      j--;
    } while (i <= j);
    if (lo < j) qsort_4e69b0(k, v, lo, j);
    if (i >= hi) return;
    lo = i;
  }
}
PCREG(4e69b0, qsort_4e69b0);

// 0x4c85f0 CRootGroup::ToggleLightDisplay(): flips +0x51; every geom of the db list +0xadc (first at +8, next by list
// vt[0x50](&cur)) whose type flags (+0x54 -> +0xc -> +0x23, 0x200002 without +0x54) have 0x800000 gets Display(+0x51);
// db +0xbad = +0x51; log "Lights Display On" / "Off" (eventsbase.cpp lines 0x2a4 / 0x2a6).
static void THISCALL toggle_4c85f0(u8 *self) {
  self[0x51] = self[0x51] == 0;
  u8 *cur = *(u8 **)(*(u8 **)(DB + 0xadc) + 8);
  while (cur) {
    u8 *t = *(u8 **)(cur + 0x54);
    u32 f = t ? *(u32 *)(*(u8 **)(t + 0xc) + 0x23) : 0x200002;
    if (f & 0x800000) ext_4daa20(cur, self[0x51]);
    vcall<void>(*(u8 **)(DB + 0xadc), 0x50, &cur);
  }
  DB[0xbad] = self[0x51];
  bool on = self[0x51] != 0;
  void *log = vcall<void *>(*(void **)0x700390u, 0x20, 0x694ad8u, on ? 0x2a4u : 0x2a6u);
  (*(logf_t *)(*(u8 **)log + 0x2c))(log, on ? 0x694c44u : 0x694c58u);
}
PCREG(4c85f0, toggle_4c85f0);

// 0x41e4b0 ZSysMem::CheckAndInitRefs(): vt[0x44](); 0x19 bytes from the allocator [0x70038c] (vt[8]) or malloc, built by
// 0x4cc930(0x12, 0x40000) into +4; +0x24 = (+4)->+4; +0x28 = (n + 1) words (n = (+4)->+0x10; size -1 on overflow, masked
// with 0x1fffffff for malloc) and 0x634d10(+0x28, 0, n + 1). (SEH frame not ported.)
typedef u8 *(*malloc_t)(u32);
static void THISCALL initRefs_41e4b0(u8 *self) {
  vcall<void>(self, 0x44);
  u8 *al = G(u8 *, 0x70038c);
  u8 *a = al ? vcall<u8 *>(al, 8, 0x19u) : (*(malloc_t *)0x6762f0u)(0x19);
  u8 *o = a ? ext_4cc930(a, 0x12, 0x40000) : 0;
  *(u8 **)(self + 4) = o;
  *(u32 *)(self + 0x24) = *(u32 *)(o + 4);
  unsigned long long sz = ((unsigned long long)(*(u32 *)(o + 0x10) + 1)) * 4;
  u32 n = sz >> 32 ? 0xffffffffu : (u32)sz;
  al = G(u8 *, 0x70038c);
  u8 *b = al ? vcall<u8 *>(al, 8, n) : (*(malloc_t *)0x6762f0u)(n & 0x1fffffff);
  *(u8 **)(self + 0x28) = b;
  ext_634d10((u32)b, 0, *(u32 *)(*(u8 **)(self + 4) + 0x10) + 1);
}
PCREG(41e4b0, initRefs_41e4b0);
