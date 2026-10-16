#include "ff.h"

typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" float FASTCALL ext_4e0830(void *a, void *b);
extern "C" u8 *THISCALL ext_5003d0(void *tab, u32 k);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

static inline void assert_hook() {
  typedef u32 (*Hook)();
  Hook h = G(Hook, 0x7003b0);
  if (!h) __builtin_trap();
  h();
}

// type byte of a slot must be 0 or 1, else an error line is logged (manager [0x700390] slot 0x20(0x69c8e0, 0x104), then the cdecl-style slot 0x2c of the returned object with 3 arguments)
// and the assert hook [0x7003b0] runs
static inline void check_slot(u8 *p) {
  u8 t = p[4];
  if (t == 0 || t == 1) return;
  void *L = G(void *, 0x700390);
  u8 *M = (u8 *)(*(V2 *)(vt(L) + 0x20))(L, 0x69c8e0, 0x104);
  u32 ra = *(u32 *)(*(u8 **)M + 0x2c), rc = *(u32 *)M;
  asm volatile(
      "pushl %[f]\n\t"
      "pushl %[g]\n\t"
      "pushl %[m]\n\t"
      "call *%%eax\n\t"
      "addl $12, %%esp"
      : "+a"(ra), "+c"(rc)
      : [f] "r"(0x69c938), [g] "r"(0x69c6b0), [m] "r"(M)
      : "edx", "memory", "cc");
  assert_hook();
}

// 0x559f90: thiscall(rec) ret 4, no defined return value (/GS protected): this->[0x1c]'s slot 0x84(&pos) gives a position; the first of the global table's ([0x7003b8] + 0xc6d, count at +0xc69, 9 byte
// entries) active entries (byte +8) whose object ([[0x70039c]+0x9b] slot 0x58(entry id [+4]) then its slot 0x84) lies closer than the exe constant [0x692798] to pos (0x4e0830) supplies its id; with
// that id slot 0 of the list rec->[8] (0x5003d0(list, 0)) is set, else slot [list.[0]] + index * 8 of the vector list (with assert hook calls for an out of range index or an empty list, where
// the first element is used) is cleared. In both cases the slot's type byte (checked to be 0 or 1) is set to 1.
extern "C" void THISCALL fn_559f90(u8 *self, u8 *rec) {
  u32 pos[3] = {0, 0, 0};
  void *A = (void *)rd32u(self + 0x1c);
  (*(V1 *)(vt(A) + 0x84))(A, (u32)pos);
  u8 *P = G(u8 *, 0x7003b8);
  u32 base = (u32)P + 0xc6d;
  u32 e = base;
  u32 cnt = rd32u(P + 0xc69);
  bool found = false;
  u32 fid = 0;
  if (e != base + cnt * 8 + cnt) {
    do {
      u8 *ent = (u8 *)e;
      if (ent[8]) {
        u8 *g = G(u8 *, 0x70039c);
        void *T = (void *)rd32u(g + 0x9b);
        void *Y = (void *)(*(V1 *)(vt(T) + 0x58))(T, rd32u(ent + 4));
        u32 v2[3] = {0, 0, 0};
        (*(V1 *)(vt(Y) + 0x84))(Y, (u32)v2);
        float d = ext_4e0830(v2, pos);
        if (G(float, 0x692798) > d) {
          fid = rd32u(ent + 4);
          found = true;
          break;
        }
      }
      cnt = rd32u(P + 0xc69);
      e += 9;
    } while (e != base + cnt * 8 + cnt);
  }
  u8 *slot;
  if (found) {
    slot = ext_5003d0((void *)rd32u(rec + 8), 0);
    check_slot(slot);
    wr32u(slot, fid);
  } else {
    u8 *V = (u8 *)rd32u(rec + 8);
    u8 *H;
    if (rd32u(V + 8) > 0) {
      u32 idx = rd32u(V + 4);
      H = (u8 *)rd32u(V);
      if (!(idx < rd32u(H + 8))) assert_hook();
      slot = (u8 *)rd32u(H) + idx * 8;
    } else {
      assert_hook();
      H = (u8 *)rd32u(V);
      if (!(rd32u(H + 8) > 0)) assert_hook();
      slot = (u8 *)rd32u(H);
    }
    check_slot(slot);
    wr32u(slot, 0);
  }
  slot[4] = 1;
  ext_633654(G(u32, 0x6f5630));
}
PCREG(559f90, fn_559f90);
