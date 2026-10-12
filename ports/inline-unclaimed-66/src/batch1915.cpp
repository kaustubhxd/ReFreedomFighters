// batch1915.cpp - unclaimed-66 batch 15: GUESS FUN_00628c80, the encoding/BOM dispatcher. cdecl, six arguments, ret.
// A label-for-label translation of the PC code (each label is one asm block; the asm addresses are in the comments).
//   T   dword table: T[2] = T+8, T[4] = T+0x10, T[5] = T+0x14; T[(s8)R[0x49]] is an entry object X.
//   R   reader: R+0x49 mode byte, R+0x4c = P (pointer to the result dword).
//   mode edx; pos esi; end ebx; out = pointer to a byte pointer (the next position).
// Returns: -4 (empty), -1 (no decision), 0xe (a stored value), or the callee's EAX (X[mode](X, pos, end, out)).
#include "ff.h"

u32 bomDispatch(u32 *T, u8 *R, u32 mode, u8 *pos, u8 *end, u8 **out) {
  u8 *P = *(u8 **)(R + 0x4c);  // [ebp-8]: the result slot (a pointer value stored in the reader)
  u8 bmode = 0;                // [ebp+0x1b]
  u8 b0 = 0;                   // [ebp+0x17]
  u8 b1 = 0;                   // [ebp-1]
  u32 X = 0;
  u32 v = 0;

  if (pos == end) return 0xfffffffc;            // 628c8e..628c93
  if (pos + 1 == end) goto ONE_BYTE;            // 628caa..628caf
  goto TWO;                                      // 628cfb

ONE_BYTE:                                        // 628cb1
  bmode = R[0x49];
  if ((u8)(bmode - 3) <= 2) goto RET_M1;        // 628cb7..628cbb
  {
    u8 c = pos[0];                               // 628cbd
    if (c > 0xef) {                              // 628cc0 (ja 628cd7)
      if (c < 0xfe) goto FALLBACK;               // 628cd7 cmp 0xfe; jb 628e09
      goto ONE_HIGH;                             // 628ce2 (fall through)
    }
    if (c == 0xef) goto ONE_HIGH;                // 628cc7 je 628ce2
    if (c == 0) goto RET_M1;                     // 628cc9 je 628cf1
    if (c == 0x3c) goto RET_M1;                  // 628ccd je 628cf1
    goto FALLBACK;                               // 628cd2 jmp 628e09
  }

ONE_HIGH:                                        // 628ce2
  if (bmode != 0) goto RET_M1;                   // 628ce6 jne 628cf1
  if (mode == 1) goto FALLBACK;                  // 628cea je 628e09
  goto RET_M1;                                   // 628cf1

TWO:                                             // 628cfb
  b0 = pos[0];                                   // 628cfb..628cfd: bl = [esi]
  b1 = pos[1];                                   // 628cfd: al = [eax], and eax is esi+1 here (the lea at 628caa
                                                 // overwrote the saved pointer), so b1 is the second input byte
  v = ((u32)b0 << 8) | b1;                       // 628d00..628d0b
  if (v > 0xfeff) {                              // 628d13 ja 628dca
    if (v == 0xfffe) goto FFFE;                  // 628dca cmp 0xfffe; je 628dfe
    goto OTHER;                                  // 628dd2
  }
  if (v == 0xfeff) goto FEFF;                    // 628d1f je 628da0
  if (v == 0x3c00) goto C3C00;                   // 628d27 je 628d88
  if (v != 0xefbb) goto OTHER;                   // 628d2f jne 628dd2
  if (mode == 1) {                               // 628d35 cmp edx,1; jne 628d61
    s32 m = (s8)R[0x49];                         // 628d3a movsx
    if (m == 0 || m == 4 || m == 5 || m == 3) goto FALLBACK;  // 628d40..628d5b
  }
  if (pos + 2 == end) goto RET_M1;               // 628d61..628d66 je 628cf1
  if (pos[2] != 0xbf) goto FALLBACK;             // 628d68 jne 628e09
  *(u32 *)P = T[2];                              // 628d71..628d7c: [P] = [T+8]
  return 0xe;                                    // 628d7e

C3C00:                                           // 628d88
  {
    u8 al = R[0x49];
    if (al == 4 || al == 3) {                    // 628d8b..628d91
      if (mode == 1) goto FALLBACK;              // 628d93..628d96 je 628e09
    }
    X = T[5];                                    // 628d98..628d9e: T+0x14
    goto DISPATCH;                               // 628e13
  }

FEFF:                                            // 628da0
  if (R[0x49] == 0 && mode == 1) goto FALLBACK;  // 628da0..628da9
  goto FEFF_B;                                   // 628dab

FEFF_B:                                          // 628dab..628dc1
  *out = pos + 2;                                // [out] = pos+2
  *(u32 *)P = T[4];                              // T+0x10
  return 0xe;

FFFE:                                            // 628dfe
  if (R[0x49] == 0 && mode == 1) goto FALLBACK;  // 628e02..628e07 (fall through to 628e09)
  goto FFFE_B;                                   // 628e2d

FFFE_B:                                          // 628e2d..628e43
  *out = pos + 2;
  *(u32 *)P = T[5];                              // T+0x14
  return 0xe;

OTHER:                                           // 628dd2
  if (b0 != 0) goto OTHER_NZ;                    // 628dd6 jne 628deb
  if (mode == 1 && R[0x49] == 5) goto FALLBACK;  // 628dd8..628de1
  X = T[4];                                      // 628de3..628de9: T+0x10
  goto DISPATCH;

OTHER_NZ:                                        // 628deb
  if (b1 != 0) goto FALLBACK;                    // 628def jne 628e09
  if (mode == 1) goto FALLBACK;                  // 628df1..628df4
  X = T[5];                                      // 628df6..628dfc: T+0x14
  goto DISPATCH;

FALLBACK:                                        // 628e09
  X = T[(s32)(s8)R[0x49]];                       // movsx ecx; mov eax,[T+ecx*4]
  goto DISPATCH;

DISPATCH:                                        // 628e13
  *(u32 *)P = X;                                 // mov [ecx], eax (ecx = P)
  {
    u32 fn = ((u32 *)X)[mode];                   // mov eax,[eax+edx*4]
    typedef u32(*fn_t)(u32, u8 *, u8 *, u8 **);  // cdecl: (X, pos, end, out)
    return ((fn_t)fn)(X, pos, end, out);         // 628e21 call eax; add esp,0x10
  }

RET_M1:                                          // 628cf1
  return 0xffffffff;
}

// 0x628c80, GUESS FUN_00628c80: the cdecl entry (the body is bomDispatch, a label-for-label translation).
static u32 cdeclBomDispatch(u32 *T, u8 *R, u32 mode, u8 *pos, u8 *end, u8 **out) {
  return bomDispatch(T, R, mode, pos, end, out);
}
PCREG(628c80, cdeclBomDispatch);
