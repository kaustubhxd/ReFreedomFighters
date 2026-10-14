// batch37065.cpp - cascade s6 batch 37065: 0x430fc0.
#include "ff.h"

extern "C" u32 *THISCALL ext_4300c0(u8 *self, u32 *pairp, u32 hint, u32 parent, u32 pair);   // tree node insert, ret 0x10; returns pointer to the new iterator
#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// Ordering of two byte ranges: memcmp-style over the shorter length, then the shorter range sorts first. Returns -1, 0 or 1.
static s32 rangecmp(const u8 *a, s32 alen, const u8 *b, s32 blen) {
  s32 n = alen < blen ? alen : blen;
  for (s32 i = 0; i < n; i++) {
    if (a[i] != b[i]) return a[i] < b[i] ? -1 : 1;
  }
  if (alen < blen) return -1;
  return alen > blen ? 1 : 0;
}

// Red-black tree iterator step back (0x42ffc0). Node: +0 header flag byte, +1 parent, +5 left, +9 right.
static u32 prevnode(u32 esi) {
  if (*(u8 *)esi == 0 && D32(D32(esi, 1), 1) == esi) return D32(esi, 9);
  u32 ecx = D32(esi, 5);
  if (ecx) {
    u32 eax = D32(ecx, 9);
    if (eax == 0) return ecx;
    do {
      ecx = eax;
      eax = D32(ecx, 9);
    } while (eax);
    return ecx;
  }
  ecx = D32(esi, 1);
  if (esi == D32(ecx, 5)) {
    u32 eax;
    do {
      eax = ecx;
      ecx = D32(ecx, 1);
    } while (eax == D32(ecx, 5));
  }
  return ecx;
}

// 0x430fc0, thiscall(this, out, pairp) ret 8: find-or-insert in a tree of byte-range keys (node key range at +0xd/+0x11). pairp points at {begin, end}. out = {node, inserted byte}.
static void THISCALL fn430fc0(u8 *self, u8 *out, u32 *pairp) {
  u32 hdr = D32(self, 0);
  u32 node = hdr;
  u32 cur = D32(hdr, 1);
  bool left = true;
  const u8 *kb = (const u8 *)pairp[0];
  s32 klen = (s32)(pairp[1] - pairp[0]);
  while (cur) {
    node = cur;
    s32 r = rangecmp(kb, klen, (const u8 *)D32(node, 0xd), (s32)(D32(node, 0x11) - D32(node, 0xd)));
    left = r < 0;
    cur = left ? D32(node, 5) : D32(node, 9);
  }
  u32 esi = node;
  bool insert = false;
  if (left) {
    if (node == D32(hdr, 5)) insert = true;
    else esi = prevnode(node);
  }
  if (!insert) {
    s32 r = rangecmp((const u8 *)D32(esi, 0xd), (s32)(D32(esi, 0x11) - D32(esi, 0xd)), kb, klen);
    if (r < 0) insert = true;
  }
  if (insert) {
    u32 pp = (u32)pairp;
    u32 *it = ext_4300c0(self, &pp, 0, node, (u32)pairp);
    D32(out, 0) = *it;
    out[4] = 1;
    return;
  }
  D32(out, 0) = esi;
  out[4] = 0;
}
PCREG(430fc0, fn430fc0);
