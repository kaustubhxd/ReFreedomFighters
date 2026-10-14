// batch38051.cpp - cascade s8 batch 38051: 0x5fc2f0 (std::map<string> insert with a position hint).
#include "ff.h"

extern "C" void THISCALL ext_5fb400(u8 *tree, u8 *ret, u8 *a, u8 *b, u8 *key);   // ret 0x10, writes *ret
extern "C" u8 *THISCALL ext_5fc480(u8 *tree, u8 *tmp, u8 *key);                  // ret 8, returns an iterator cell
extern "C" u32 THISCALL ext_5fb270(u8 *cmp, u8 *key, u8 *nodekey);               // ret 8, AL = key < node key
extern "C" void THISCALL ext_42ffc0(u8 **it);                                    // --it
typedef int (*cmpn_t)(const char *, const char *, s32);
#define imp_cmpn G(cmpn_t, 0x676408)
#define U32AT(p, off) (*(u32 *)((u8 *)(p) + (off)))   // packed (unaligned) node fields

// compares the string range key = {begin, end} against the key stored in a node (packed fields +0xd begin, +0x11 end); first = true gives cmp(key, node), false cmp(node, key). Returns true when
// the first string sorts before the second: strncmp over the common length, then the shorter first.
static bool less_than(const char *b1, s32 l1, const char *b2, s32 l2) {
  s32 n = l1 < l2 ? l1 : l2;
  int r = imp_cmpn(b1, b2, n);
  if (r != 0) return r < 0;
  return l1 < l2;
}

// 0x5fc2f0, thiscall(ret, hint, key) ret 0xc -> *ret = iterator. The red-black map's head node is *this ({+1 parent, +5 leftmost, +9 rightmost}; nodes have the packed key range at +0xd / +0x11), this[4]
// is the size. If the hint is begin() and the key sorts before it, or the hint is end() and the rightmost node sorts before the key, or the hint's predecessor sorts before the key and the key before
// the hint (0x5fb270), the new node goes right there (0x5fb400 with the matching neighbour arguments); every other case falls back to the ordinary insert 0x5fc480 and copies its iterator.
static u8 *THISCALL fn5fc2f0(u8 *self, u8 *ret, u8 *hint, u8 *key) {
  u8 *head = *(u8 **)self;
  const char *kb = *(const char **)key;
  s32 klen = (s32)(*(u32 *)(key + 4) - (u32)kb);
  if ((u32)hint == U32AT(head, 5)) {
    if (*(u32 *)(self + 4) > 0) {
      const char *nb = (const char *)U32AT(hint, 0xd);
      s32 nlen = (s32)(U32AT(hint, 0x11) - (u32)nb);
      if (less_than(kb, klen, nb, nlen)) {
        ext_5fb400(self, ret, hint, hint, key);
        return ret;
      }
    }
  } else if (hint == head) {
    u8 *last = (u8 *)U32AT(head, 9);
    const char *nb = (const char *)U32AT(last, 0xd);
    s32 nlen = (s32)(U32AT(last, 0x11) - (u32)nb);
    if (less_than(nb, nlen, kb, klen)) {
      ext_5fb400(self, ret, 0, (u8 *)U32AT(head, 9), key);
      return ret;
    }
  } else {
    u8 *pred = hint;
    ext_42ffc0(&pred);
    const char *pb = (const char *)U32AT(pred, 0xd);
    s32 plen = (s32)(U32AT(pred, 0x11) - (u32)pb);
    if (less_than(pb, plen, kb, klen)) {
      if ((u8)ext_5fb270(self + 8, key, hint + 0xd)) {
        if (U32AT(pred, 9) == 0) {
          ext_5fb400(self, ret, 0, pred, key);
          return ret;
        }
        ext_5fb400(self, ret, hint, hint, key);
        return ret;
      }
    }
  }
  u8 tmp[0xc];
  u8 *it = ext_5fc480(self, tmp, key);
  *(u32 *)ret = *(u32 *)it;
  return ret;
}
PCREG(5fc2f0, fn5fc2f0);
