#include "ff.h"

typedef u32(THISCALL *V2)(void *, u32, u32);

extern "C" u32 THISCALL ext_52cf00(void *a, u32 flag);
extern "C" void THISCALL ext_52cf10(void *a);
extern "C" void THISCALL ext_52cf40(void *a);
extern "C" u32 THISCALL ext_52b0c0(void *s);
extern "C" void THISCALL ext_52c6e0(void *self, void *rec, void *dst);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x52c000: thiscall(flag) ret 4, no /GS, returns nothing useful. this+0x18 = helper object A, this+0x1c = state S, this+0x79 = ring of 0x32-byte records (base [0], capacity [4],
// head [8], tail [0xc]). The low byte of the flag is toggled in A (0x52cf00, pushes the stack dword back with its low byte replaced by A's old byte) when A and the flag exist.
// S: byte +0x48, dwords +0x49 / +0x4d, entry pointer +0x44 (byte +0x10, dwords +0 and +4), byte +0x99 / +0x230, record copy at +0x1fe (dword +0x202 is the record's field +4).
// Pops ring records into S+0x1fe until one has a nonzero field +4 or the ring is empty, then (via 0x52b0c0 and the S[0x4d] counter) either returns early, calls 0x52c6e0(this, S+0x1fe, S+0x51)
// or stamps the entry's timestamp from the engine slot 0x1c8(0x6a0ea8, 0x3d) and sets S[0x48] = 1, S[0x230] = 0.
extern "C" void THISCALL fn_52c000(u8 *self, u32 arg) {
  u8 bl = (u8)arg;
  u8 *A = (u8 *)rd32u(self + 0x18);
  u8 *S = (u8 *)rd32u(self + 0x1c);
  if (A && bl) arg = (arg & ~0xffu) | (u8)ext_52cf00(A, 0);
  u8 old48 = S[0x48];
  wr32u(S + 0x4d, 0);
  if (old48 != 0) {
    S[0x48] = 0;
    wr32u(S + 0x49, 0);
  }
  u8 *E = (u8 *)rd32u(S + 0x44);
  wr32u(S + 0x4d, 1);
  if (E && E[0x10] != 0 && (S[0x48] != 0 || rd32u(S + 0x49) != 0)) goto L17c;
  {
    A = (u8 *)rd32u(self + 0x18);
    if (A) ext_52cf10(A);
    u8 *R = (u8 *)rd32u(self + 0x79);
    u32 h = rd32u(R + 8);
    u8 al;
    if (h == rd32u(R + 0xc)) {
      al = 0;
    } else {
      __builtin_memcpy(S + 0x1fe, (u8 *)rd32u(R) + h * 0x32, 0x32);
      al = 1;
    }
    S[0x230] = al;
    if (al != 0) {
      while (rd32u(S + 0x202) == 0) {
        R = (u8 *)rd32u(self + 0x79);
        h = rd32u(R + 8);
        if (h == rd32u(R + 0xc)) {
          al = 0;
        } else {
          __builtin_memcpy(S + 0x1fe, (u8 *)rd32u(R) + h * 0x32, 0x32);
          int nh = (int)(h + 1) % (int)rd32u(R + 4);
          al = 1;
          wr32u(R + 8, (u32)nh);
        }
        S[0x230] = al;
        R = (u8 *)rd32u(self + 0x79);
        h = rd32u(R + 8);
        if (h == rd32u(R + 0xc)) {
          S[0x230] = 0;
          break;
        }
        __builtin_memcpy(S + 0x1fe, (u8 *)rd32u(R) + h * 0x32, 0x32);
        S[0x230] = 1;
      }
    }
    if ((u8)ext_52b0c0(S) != 0) goto L21c;
  }
L17c : {
  u32 ecx = rd32u(S + 0x4d);
  wr32u(S + 0x4d, ecx + 1);
  E = (u8 *)rd32u(S + 0x44);
  bool to1df = false;
  if (E && E[0x10] != 0) {
    if (S[0x48] != 0)
      to1df = true;
    else if (ecx != rd32u(S + 0x49))
      to1df = true;
  }
  if (!to1df) {
    A = (u8 *)rd32u(self + 0x18);
    if (A) ext_52cf40(A);
    if (S[0x230] != 0) {
      ext_52c6e0(self, S + 0x1fe, S + 0x51);
      if (S[0x99] == 0) goto L21c;
      S[0x230] = 0;
    }
    if ((u8)ext_52b0c0(S) != 0) goto L21c;
  }
  E = (u8 *)rd32u(S + 0x44);
  if (E && E[0x10] != 0) {
    u8 *eng = G(u8 *, 0x70039c);
    u32 r = (*(V2 *)(vt(eng) + 0x1c8))(eng, 0x6a0ea8, 0x3d);
    u8 *E2 = (u8 *)rd32u(S + 0x44);
    u32 d = r - rd32u(E2);
    if (d > rd32u(E2 + 4)) wr32u(E2, r);
  }
  S[0x48] = 1;
  S[0x230] = 0;
}
L21c:
  A = (u8 *)rd32u(self + 0x18);
  if (A && bl) ext_52cf00(A, arg);
}
PCREG(52c000, fn_52c000);
