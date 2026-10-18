#include "ff.h"

typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V3)(void *, u32, u32, u32);
typedef float(THISCALL *VF1)(void *, u32);
typedef int (*StrnCmp)(u32, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" u32 THISCALL ext_5fb8b0(void *self, u32 pat);
extern "C" u32 ext_5fa630();

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

static inline u32 cdecl4_ecx(u32 fn, u32 ecx_, u32 a, u32 b, u32 c, u32 d) {
  u32 r;
  __asm__ volatile("pushl %[d]; pushl %[c]; pushl %[b]; pushl %[a]; call *%%eax; addl $16,%%esp"
                   : "=a"(r), "+c"(ecx_) : "0"(fn), [a] "r"(a), [b] "r"(b), [c] "r"(c), [d] "r"(d) : "edx", "memory", "cc");
  return r;
}
static inline u32 cdecl2_ecx(u32 fn, u32 ecx_, u32 a, u32 b) {
  u32 r;
  __asm__ volatile("pushl %[b]; pushl %[a]; call *%%eax; addl $8,%%esp" : "=a"(r), "+c"(ecx_) : "0"(fn), [a] "r"(a), [b] "r"(b) : "edx", "memory", "cc");
  return r;
}

// 0x5fcd70: thiscall(flagbyte*) ret 0xc taking (A, B, C): while *flag == 0, walks A's node list ([A+0x30] -> {data, ?, count}, cursor A[0x34] from 0) and for every node
// by type ([node] 0x14, 0x15, 0x16, 0x24, else) asks C (the reader: slots 0x10, 0, 4, 8, 0x14) for a value, optionally pushes it through B's slot 0 (the writer) and stores the result
// at [[B+0x9e] + node[8]]. Text-valued nodes (node[0x20..0x24] is the type tag text) select the variant by an _strnicmp of 4 / 6 characters against fixed tags (import 0x676408) and
// by 0x5fb8b0 text checks; unknown types format a message through the log object returned by 0x5fa630 (slots 0x14 and 0xc).
static void handle(u8 *node, u8 *B, u8 *C) {
  u8 buf[0x200];
  u32 kind = rd32u(node);
  u8 *dest;
  if (kind == 0x16) {
    u32 r = (*(V3 *)(vt(C) + 0x10))(C, rd32u(node + 0x14), (u32)(node + 0x38), (u32)(B + 0xaca));
    wr32u((u8 *)rd32u(B + 0x9e) + rd32u(node + 8), r);
    return;
  }
  if (kind == 0x24) {
    u32 r = (*(V1 *)vt(C))(C, rd32u(node + 0x14));
    wr32u((u8 *)rd32u(B + 0x9e) + rd32u(node + 8), r);
    return;
  }
  if (kind == 0x14) {
    int len = (int)rd32u(node + 0x24) - (int)rd32u(node + 0x20);
    int n = len > 4 ? 4 : len;
    int rc = G(StrnCmp, 0x676408)(rd32u(node + 0x20), 0x6b92d0, (u32)n);
    if (rc == 0 && len == 4) {
      u32 r = (*(V1 *)vt(C))(C, rd32u(node + 0x14));
      wr32u((u8 *)rd32u(B + 0x9e) + rd32u(node + 8), r);
      return;
    }
    if (ext_5fb8b0(node + 0x20, 0x6b869c) != 0) return;
    float f = (*(VF1 *)(vt(C) + 4))(C, rd32u(node + 0x14));
    dest = (u8 *)rd32u(B + 0x9e) + rd32u(node + 8);
    __builtin_memcpy(dest, &f, 4);
    return;
  }
  if (kind == 0x15) {
    int len = (int)rd32u(node + 0x24) - (int)rd32u(node + 0x20);
    int n = len > 6 ? 6 : len;
    int rc = G(StrnCmp, 0x676408)(rd32u(node + 0x20), 0x6b87a8, (u32)n);
    if (rc == 0 && len == 6) {
      u32 v = (*(V1 *)(vt(C) + 8))(C, rd32u(node + 0x14));
      u32 r = (*(V2 *)vt(B))(B, rd32u(node + 0x38), v);
      wr32u((u8 *)rd32u(B + 0x9e) + rd32u(node + 8), r);
      return;
    }
    if (ext_5fb8b0(node + 0x20, 0x6b876c) == 0) {
      u8 *vb = vt(B);
      u32 v = (*(V1 *)vt(C))(C, rd32u(node + 0x14));
      u32 r = (*(V2 *)vb)(B, rd32u(node + 0x38), v);
      wr32u((u8 *)rd32u(B + 0x9e) + rd32u(node + 8), r);
      return;
    }
    if (ext_5fb8b0(node + 0x20, 0x6b878c) == 0) {
      float f = (*(VF1 *)(vt(C) + 4))(C, rd32u(node + 0x14));
      u32 bits;
      __builtin_memcpy(&bits, &f, 4);
      u32 r = (*(V2 *)vt(B))(B, rd32u(node + 0x38), bits);
      wr32u((u8 *)rd32u(B + 0x9e) + rd32u(node + 8), r);
      return;
    }
    u8 *vb = vt(B);
    u32 v = (*(V1 *)(vt(C) + 0x14))(C, rd32u(node + 0x14));
    u32 r = (*(V2 *)vb)(B, rd32u(node + 0x38), v);
    wr32u((u8 *)rd32u(B + 0x9e) + rd32u(node + 8), r);
    return;
  }
  u8 *P = (u8 *)ext_5fa630();
  cdecl4_ecx(rd32u(vt(P) + 0x14), rd32u(P), (u32)P, (u32)buf, 0x6b92d8, rd32u(node + 0x14));
  u8 *P2 = (u8 *)ext_5fa630();
  cdecl2_ecx(rd32u(vt(P2) + 0xc), rd32u(P2), (u32)P2, (u32)buf);
}

extern "C" void THISCALL fn_5fcd70(u8 *flagp, u8 *A, u8 *B, u8 *C) {
  u8 *node;
  u32 cnt;
  u8 *L;
  if (*flagp != 0) goto done;
  wr32u(A + 0x34, 0);
  L = (u8 *)rd32u(A + 0x30);
  if (rd32u(A + 0x34) >= rd32u(L + 8)) goto done;
  node = (u8 *)rd32u((u8 *)rd32u((u8 *)rd32u(A + 0x30)) + rd32u(A + 0x34) * 4);
  if (node == 0) goto done;
  for (;;) {
    handle(node, B, C);
    L = (u8 *)rd32u(A + 0x30);
    cnt = rd32u(A + 0x34);
    if (cnt < rd32u(L + 8)) wr32u(A + 0x34, cnt + 1);
    L = (u8 *)rd32u(A + 0x30);
    cnt = rd32u(A + 0x34);
    if (cnt >= rd32u(L + 8)) break;
    node = (u8 *)rd32u((u8 *)rd32u((u8 *)rd32u(A + 0x30)) + cnt * 4);
    if (node == 0) break;
  }
done:
  ext_633654(G(u32, 0x6f5630));
}
PCREG(5fcd70, fn_5fcd70);
