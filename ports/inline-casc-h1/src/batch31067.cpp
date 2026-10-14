// batch31067.cpp - list/table lookups, flag decoder, record compare, linked list/tree inserts, tree iterator.
#include "ff.h"

#define P32(p) (*(u32 *)(p))

// 0x5af170 thiscall ret 4: element after v in the dword list (count this[0], items from this+4); this[1] if v is 0/not found; 0 if v is last.
THISCALL u32 fn5af170(u32 *self, u32 v) {
  u32 n = self[0];
  if (!n) return 0;
  if (v) {
    for (u32 i = 0; i < n; i++)
      if (self[1 + i] == v) return i < n - 1 ? self[2 + i] : 0;
  }
  return self[1];
}
PCREG(5af170, fn5af170);

// 0x4e50c0 thiscall ret 4, bool (arg object): decode a tagged table entry reached via this->[4] and compare a looked-up dword with arg minus this[3].
THISCALL u8 fn4e50c0(u8 *self, u8 *arg) {
  u8 *a = *(u8 **)(self + 4);
  u32 h = P32(a + 4);
  u8 *e;
  if ((int)h < 0) {
    if (h & 0x40000000) e = a + P32(a + 0x10) * 4 + 0x14;
    else e = a + 0x10;
  } else {
    e = 0;
  }
  u32 idx = P32(arg + 0x44);
  if (!(idx < P32(e))) return 0;
  u32 t = P32(e + 4) & 0xc0000000;
  u32 off = 8;
  if (t == 0x40000000 || t == 0x80000000 || t == 0xc0000000) off = P32(e + 8);
  u32 want = (u32)(u32)arg - P32(self + 0xc);
  return P32(e + off + idx * 4) == want;
}
PCREG(4e50c0, fn4e50c0);

// 0x53b860 stdcall ret 0xc (recs, n, key): index of the first 0x89-byte record whose count (+0x25) and dword list (+5) equal the key's, else -1.
STDCALL int fn53b860(u8 *recs, int n, u8 *key) {
  int cnt = (int)P32(key + 0x25);
  for (int k = 0; k < n; k++) {
    u8 *r = recs + 0x89 * k;
    if ((int)P32(r + 0x25) != cnt) continue;
    int j = 0;
    for (; j < cnt; j++)
      if (P32(key + 5 + 4 * j) != P32(r + 5 + 4 * j)) break;
    if (j >= cnt) return k;
  }
  return -1;
}
PCREG(53b860, fn53b860);

// 0x459b90 thiscall ret 0x10 (idx, a, b, c): follow links in the 0x7c-byte record table at this+0x3c, consuming the first nonzero direction per step; returns the record reached.
THISCALL u8 *fn459b90(u8 *self, u32 idx, int a, int b, int c) {
  if (!idx) return 0;
  u8 *base = *(u8 **)(self + 0x3c);
  for (;;) {
    u8 *rec = base + idx * 0x7c - 0x7c;
    if (a > 0) { idx = *(u16 *)(rec + 6); a = 0; }
    else if (a < 0) { idx = *(u16 *)(rec + 4); a = 0; }
    else if (b > 0) { idx = *(u16 *)(rec + 0xa); b = 0; }
    else if (b < 0) { idx = *(u16 *)(rec + 8); b = 0; }
    else if (c > 0) { idx = *(u16 *)(rec + 0xe); c = 0; }
    else if (c < 0) { idx = *(u16 *)(rec + 0xc); c = 0; }
    else return rec;
    if (!idx) return 0;
  }
}
PCREG(459b90, fn459b90);

// 0x5ed340 thiscall ret 0xc (a, b, idx): set field +4 to a and halfword +0xc to b on one (idx) or all (-1) records of the pointer array; flag byte this+0xa6 when anything changed.
THISCALL void fn5ed340(u8 *self, u32 a, int b, int idx) {
  if (idx == -1) {
    u32 *p = *(u32 **)(self + 0xcb);
    u32 *end = *(u32 **)(self + 0xcf);
    if (p == end) return;
    do {
      u8 *r = (u8 *)*p;
      if (P32(r + 4) != a || (int)*(s16 *)(r + 0xc) != b) self[0xa6] = 1;
      p++;
      P32(r + 4) = a;
      *(u16 *)(r + 0xc) = (u16)b;
    } while (p != end);
  } else {
    u8 *r = (u8 *)(*(u32 **)(self + 0xcb))[idx];
    if (P32(r + 4) != a || (int)*(s16 *)(r + 0xc) != b) self[0xa6] = 1;
    P32(r + 4) = a;
    *(u16 *)(r + 0xc) = (u16)b;
  }
}
PCREG(5ed340, fn5ed340);

// 0x4920e0 thiscall ret 8 (before, node): insert node into the doubly linked list (head this+0xa04, prev +0xc, next +0x10) before 'before', or at the tail when before is 0.
THISCALL void fn4920e0(u8 *self, u8 *before, u8 *node) {
  if (!before) {
    u8 *p = *(u8 **)(self + 0xa04);
    if (!p) {
      P32(node + 0xc) = 0;
      P32(node + 0x10) = 0;
      *(u8 **)(self + 0xa04) = node;
      return;
    }
    while (P32(p + 0x10)) p = *(u8 **)(p + 0x10);
    P32(node + 0xc) = (u32)(u32)p;
    P32(node + 0x10) = 0;
    P32(p + 0x10) = (u32)(u32)node;
    return;
  }
  u8 *prev = *(u8 **)(before + 0xc);
  P32(node + 0xc) = (u32)(u32)prev;
  P32(node + 0x10) = (u32)(u32)before;
  if (prev) P32(prev + 0x10) = (u32)(u32)node;
  else *(u8 **)(self + 0xa04) = node;
  P32(before + 0xc) = (u32)(u32)node;
}
PCREG(4920e0, fn4920e0);

// 0x4e8160 thiscall ret 4 (node): binary-search-tree insert with sentinel [this+8], root [this+4], key at +0xc, left +4, right +8, parent +0.
THISCALL void fn4e8160(u8 *self, u8 *node) {
  u8 *nil = *(u8 **)(self + 8);
  P32(node + 4) = (u32)(u32)nil;
  P32(node + 8) = (u32)(u32)nil;
  P32(node) = (u32)(u32)nil;
  u8 *y = nil;
  u8 *p = *(u8 **)(self + 4);
  if (p != nil) {
    int key = (int)P32(node + 0xc);
    do {
      y = p;
      p = (key < (int)P32(p + 0xc)) ? *(u8 **)(p + 4) : *(u8 **)(p + 8);
    } while (p != nil);
  }
  P32(node) = (u32)(u32)y;
  if (y == *(u8 **)(self + 8)) { *(u8 **)(self + 4) = node; return; }
  if ((int)P32(node + 0xc) < (int)P32(y + 0xc)) P32(y + 4) = (u32)(u32)node;
  else P32(y + 8) = (u32)(u32)node;
}
PCREG(4e8160, fn4e8160);

// 0x42b0f0 thiscall ret 0xc (cur, end, unused): advance a tree iterator (parent +1, left +5, right +9, in-order) from cur to end, counting steps in [this].
THISCALL void fn42b0f0(u32 *self, u8 *cur, u8 *end, u32) {
  if (cur == end) return;
  u32 cnt = *self;
  do {
    u8 *r = *(u8 **)(cur + 9);
    if (r) {
      cur = r;
      u8 *l;
      while ((l = *(u8 **)(cur + 5)) != 0) cur = l;
    } else {
      u8 *par = *(u8 **)(cur + 1);
      if (cur == *(u8 **)(par + 9)) {
        do {
          cur = par;
          par = *(u8 **)(par + 1);
        } while (cur == *(u8 **)(par + 9));
      }
      if (*(u8 **)(cur + 9) != par) cur = par;
    }
    cnt++;
    *self = cnt;
  } while (cur != end);
}
PCREG(42b0f0, fn42b0f0);
