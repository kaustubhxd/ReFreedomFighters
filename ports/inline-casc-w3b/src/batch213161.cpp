#include "ff.h"

extern "C" u32 THISCALL ext_531a50(void *p, void *a, void *b, u32 c);
extern "C" u32 THISCALL ext_52b4e0(void *self, u32 x);
extern "C" void *ext_41e290(u32 size);
extern "C" u32 THISCALL ext_52a700(void *q, void *entry);
extern "C" void THISCALL ext_52c000(void *self, u32 flag);
extern "C" void FASTCALL ext_633654(u32 cookie);

typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V3)(void *, u32, void *, u32);
typedef void (*Hook)();

static inline u32 R32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float RF(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void WF(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline float cf(u32 addr) { return *(const float *)addr; }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// cdecl vcall (M's vtable in ecx) with one argument
static void vt_log1(void *M, u32 off, u32 fmt) {
  u32 vtp = *(u32 *)M, fn = *(u32 *)(vtp + off), rc = vtp, ra = fn;
  asm volatile("pushl %[f]\n\tpushl %[o]\n\tcall *%%eax\n\taddl $8, %%esp"
               : "+a"(ra), "+c"(rc)
               : [f] "r"(fmt), [o] "r"(M)
               : "edx", "memory", "cc");
}
static void log_line(u32 line, u32 fmt) {
  u8 *L = G(u8 *, 0x700390);
  u8 *M = (u8 *)(*(V2 *)(vt(L) + 0x20))(L, 0x6a0f54, line);
  vt_log1(M, 0x2c, fmt);
}
static void assert_hook() {
  Hook h = G(Hook, 0x7003b0);
  if (!h) __builtin_trap();
  h();
}
// ring queue q: [0] base (entries of 0x32 bytes), [4] capacity, [8] head, [0xc] tail, [0x10] cursor
static inline u8 *ring_step(u8 *q, u32 cur) {
  u8 *entry = (u8 *)(cur * 0x32 + R32(q));
  W32(q + 0x10, (u32)((s32)(cur + 1) % (s32)R32(q + 4)));
  return entry;
}

// 0x52c270: thiscall(id, A, B, unused, f, b1, b2) ret 0x1c -> int, /GS. Adds a (ray) segment A..B (y lifted by this[0x20] + [0x67da24]) to the queue this[0x79]:
// with this[0x31] set it first asks 0x531a50(this[0x65], &P, &Q, this[0x49]); a hit creates a 0x20 byte record (P, Q, 0x52b4e0(hit), -1) handed to the owner of `id` (table slot 0x54 ->
// [+0x54] slot 0x128(word [this+0x95], record, 0)), clears the entries of the ring whose [+4] == id and returns -1. Otherwise (or without a hit) the ring is scanned for an entry with [+4] == id
// which is refreshed in place (returns its new serial this[0x75]++); else a new 0x32 byte entry is pushed with 0x52a700 (making room with 0x52c000(1) when needed). Missing queue -> 0.
static u32 body_52c270(u8 *self, u32 id, u8 *A, u8 *B, float f, u8 b1, u8 b2) {
  u8 fr[0x70];
  __builtin_memset(fr, 0xcc, sizeof fr);
#define EBP (fr + 0x60)
#define P(off) (EBP - (off))
  if (G(u8, 0x701b58)) log_line(0x263e, 0x6a128c);
  if (R32(self + 0x79) == 0) {
    log_line(0x2640, 0x6a129c);
    return 0;
  }
  bool flag31 = self[0x31] != 0;
  float base = RF(self + 0x20) + cf(0x67da24);
  WF(P(0x10), RF(A));
  WF(P(8), RF(A + 8));
  WF(P(0x1c), RF(B));
  WF(P(0x14), RF(B + 8));
  WF(P(0xc), base + RF(A + 4));
  WF(P(0x18), base + RF(B + 4));
  u32 hit = 0;
  if (!flag31) {
    log_line(0x264f, 0x6a12d8);
    assert_hook();
  } else {
    hit = ext_531a50((void *)R32(self + 0x65), P(0x10), P(0x1c), R32(self + 0x49));
    if (hit) {
      u32 x = ext_52b4e0(self, hit);
      W32(P(0x20), x);
      u8 *node = (u8 *)ext_41e290(0x20);
      __builtin_memset(node, 0, 0x20);
      WF(node, RF(P(0x10)));
      WF(node + 4, RF(P(0xc)));
      WF(node + 8, RF(P(8)));
      WF(node + 0xc, RF(P(0x1c)));
      WF(node + 0x10, RF(P(0x18)));
      WF(node + 0x14, RF(P(0x14)));
      W32(node + 0x1c, R32(P(0x20)));
      W32(node + 0x18, 0xffffffff);
      if (G(u8, 0x701b58)) log_line(0x265b, 0x6a12ec);
      if (id != 0xffffffffu) {
        u8 *E = G(u8 *, 0x70039c);
        u8 *tbl = (u8 *)R32(E + 0x9b);
        u8 *ent = (u8 *)(*(V1 *)(vt(tbl) + 0x54))(tbl, id);
        if (ent) {
          u8 *item = (u8 *)R32(ent + 0x54);
          if (item) (*(V3 *)(vt(item) + 0x128))(item, *(u16 *)(self + 0x95), node, 0);
        }
      }
      u8 *q = (u8 *)R32(self + 0x79);
      u32 head = R32(q + 8), tail = R32(q + 0xc);
      W32(q + 0x10, head);
      if (head != tail) {
        u32 n = (u32)((s32)(head + 1) % (s32)R32(q + 4));
        W32(q + 0x10, n);
        if (n != tail) {
          u8 *entry = ring_step(q, n);
          if (entry) {
            for (;;) {
              if (R32(entry + 4) == id) W32(entry + 4, 0);
              q = (u8 *)R32(self + 0x79);
              u32 cur = R32(q + 0x10);
              if (cur == R32(q + 0xc)) break;
              entry = ring_step(q, cur);
              if (!entry) break;
            }
          }
        }
      }
      return 0xffffffffu;
    }
  }
  // not found / disabled: search the ring for the id
  u8 *q = (u8 *)R32(self + 0x79);
  u32 head = R32(q + 8), tail = R32(q + 0xc);
  W32(q + 0x10, head);
  u8 *hitentry = 0;
  if (head != tail) {
    u32 n = (u32)((s32)(head + 1) % (s32)R32(q + 4));
    W32(q + 0x10, n);
    if (n != tail) {
      u8 *entry = ring_step(q, n);
      while (entry) {
        if (R32(entry + 4) == id) {
          hitentry = entry;
          break;
        }
        q = (u8 *)R32(self + 0x79);
        u32 cur = R32(q + 0x10);
        if (cur == R32(q + 0xc)) break;
        entry = ring_step(q, cur);
      }
    }
  }
  if (hitentry) {
    u8 *esi = hitentry;
    W32(esi, R32(self + 0x75));
    W32(self + 0x75, R32(self + 0x75) + 1);
    W32(esi + 8, R32(A));
    W32(esi + 0xc, R32(A + 4));
    W32(esi + 0x10, R32(A + 8));
    W32(esi + 0x14, R32(B));
    W32(esi + 0x18, R32(B + 4));
    W32(esi + 0x1c, R32(B + 8));
    esi[0x30] = b1;
    W32(esi + 0x20, 0);
    W32(esi + 0x24, 0);
    W32(esi + 0x28, 0);
    WF(esi + 0x2c, f);
    esi[0x31] = b2;
    return R32(esi);
  }
  u32 serial = R32(self + 0x75);
  q = (u8 *)R32(self + 0x79);
  W32(P(0x54), serial);
  W32(P(0x50), id);
  W32(self + 0x75, serial + 1);
  W32(P(0x34), 0);
  W32(P(0x30), 0);
  W32(P(0x2c), 0);
  W32(P(0x4c), R32(A));
  W32(P(0x48), R32(A + 4));
  W32(P(0x44), R32(A + 8));
  W32(P(0x40), R32(B));
  W32(P(0x3c), R32(B + 4));
  W32(P(0x38), R32(B + 8));
  *P(0x24) = b1;
  *P(0x23) = b2;
  WF(P(0x28), f);
  if ((u8)ext_52a700(q, P(0x54))) return serial;
  ext_52c000(self, 1);
  if ((u8)ext_52a700((void *)R32(self + 0x79), P(0x54))) {
    log_line(0x2693, 0x6a1354);
    return serial;
  }
  log_line(0x268f, 0x6a1318);
  assert_hook();
  return 0;
}
extern "C" u32 THISCALL fn_52c270(u8 *self, u32 id, u8 *A, u8 *B, u32 unused, float f, u32 b1, u32 b2);
extern "C" u32 THISCALL fn_52c270(u8 *self, u32 id, u8 *A, u8 *B, u32 unused, float f, u32 b1, u32 b2) {
  u32 r = body_52c270(self, id, A, B, f, (u8)b1, (u8)b2);
  ext_633654(G(u32, 0x6f5630));
  return r;
}
PCREG(52c270, fn_52c270);
