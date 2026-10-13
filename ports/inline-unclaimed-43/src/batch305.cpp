// batch305.cpp - path probe, 0x558fe0 (area 43, 2026-10-12). No name-map entry.
// thiscall (this = ECX), one stack argument P (an object), ret 4. Frame EBP-relative.
// Steps: r1 = array0(P+4)[0]; r2 = engine(g_pSysInterface->[0x9b]) slot 0x58(*r1); r2 slot 0x84(tmp);
// ebx = this->[0x1c] slot 0x5d0().
//   ebx != 0: GetPos(this->[0x1c]->[+8], vec); this->[0x1c] slot 0x84(vec); dist = FindPathLength(ebx, vec, tmp)
//             (ST0, stored as a float); r3 = array0(P+8); (r3 value = dist bits, type 2) via 0x602cd0(r3, &dist).
//   ebx == 0: r3 = array0(P+8); 0x500360(r3, -1.0f).
// Element records are 8 bytes: value dword at +0, type byte at +4 (0 or 2 on the normal path).
// The original's stack pushes at the 5003d0/602cd0 pair are two sequential calls (the pushed &dist is the argument of
// 602cd0, which pops it), so the port makes the two calls in order.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 index);                   // array element address (ret 4)
extern "C" void THISCALL ext_602cd0(u8 *rec, const u32 *src);             // record value = *src, type 2 (ret 4)
extern "C" void THISCALL ext_500360(u8 *rec, float v);                    // record value = v, type 2 (ret 4)
extern "C" void THISCALL ext_4db500(u8 *obj, float *out);                 // GetPos (ret 4)
extern "C" float THISCALL ext_52b330(u8 *self, const float *a, const float *b);   // FindPathLength (ret 8, ST0)

static void THISCALL pathProbe(u8 *self, u8 *p) {
  float vec[3];
  float tmp[3] = {0.0f, 0.0f, 0.0f};
  float dist;
  u8 *r1 = ext_5003d0((u8 *)U32(p, 4), 0);
  u8 *eng = (u8 *)G(u32, 0x70039c);
  u8 *r2 = vcall<u8 *>((void *)U32(eng, 0x9b), 0x58, *(u32 *)r1);
  vcall<void>((void *)r2, 0x84, (void *)tmp);
  u8 *M = (u8 *)U32(self, 0x1c);
  u8 *ebx = vcall<u8 *>((void *)M, 0x5d0);
  u8 *Q = (u8 *)U32(p, 8);
  if (ebx != 0) {
    ext_4db500((u8 *)U32(M, 8), vec);
    vcall<void>((void *)M, 0x84, (void *)vec);
    dist = ext_52b330(ebx, vec, tmp);
    u8 *r3 = ext_5003d0(Q, 0);
    ext_602cd0(r3, (const u32 *)&dist);
  } else {
    u8 *r3 = ext_5003d0(Q, 0);
    ext_500360(r3, -1.0f);
  }
}
PCREG(558fe0, pathProbe);
