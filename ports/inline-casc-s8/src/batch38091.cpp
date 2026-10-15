// batch38091.cpp - cascade s8 batch 38091: 0x4e8450 (red-black tree erase fix-up, MSVC std::map style: nodes {+0 parent, +4 left, +8 right, +0x10 colour byte (0 black, 1 red)}).
#include "ff.h"

#define NODE(p, off) (*(u8 **)((u8 *)(p) + (off)))
#define COL(p) (*((u8 *)(p) + 0x10))

// tree header: +4 root, +8 nil node
static void lrot(u8 *t, u8 *p) {
  u8 *w = NODE(p, 8);
  NODE(p, 8) = NODE(w, 4);
  if (NODE(w, 4) != NODE(t, 8)) NODE(NODE(w, 4), 0) = p;
  NODE(w, 0) = NODE(p, 0);
  u8 *pp = NODE(p, 0);
  if (pp == NODE(t, 8)) NODE(t, 4) = w;
  else if (p == NODE(pp, 4)) NODE(pp, 4) = w;
  else NODE(pp, 8) = w;
  NODE(w, 4) = p;
  NODE(p, 0) = w;
}
static void rrot(u8 *t, u8 *p) {
  u8 *w = NODE(p, 4);
  NODE(p, 4) = NODE(w, 8);
  if (NODE(w, 8) != NODE(t, 8)) NODE(NODE(w, 8), 0) = p;
  NODE(w, 0) = NODE(p, 0);
  u8 *pp = NODE(p, 0);
  if (pp == NODE(t, 8)) NODE(t, 4) = w;
  else if (p == NODE(pp, 8)) NODE(pp, 8) = w;
  else NODE(pp, 4) = w;
  NODE(w, 8) = p;
  NODE(p, 0) = w;
}

// 0x4e8450, thiscall(node) ret 4, void.
static void THISCALL fn4e8450(u8 *t, u8 *x) {
  while (x != NODE(t, 4) && COL(x) == 0) {
    u8 *p = NODE(x, 0);
    if (x == NODE(p, 4)) {
      u8 *w = NODE(p, 8);
      if (COL(w) == 1) {
        COL(w) = 0;
        COL(NODE(x, 0)) = 1;
        lrot(t, NODE(x, 0));
        p = NODE(x, 0);
        w = NODE(p, 8);
      }
      if (COL(NODE(w, 4)) == 0 && COL(NODE(w, 8)) == 0) {
        COL(w) = 1;
        x = NODE(x, 0);
      } else {
        if (COL(NODE(w, 8)) == 0) {
          COL(NODE(w, 4)) = 0;
          COL(w) = 1;
          rrot(t, w);
          p = NODE(x, 0);
          w = NODE(p, 8);
        }
        COL(w) = COL(p);
        COL(NODE(x, 0)) = 0;
        COL(NODE(w, 8)) = 0;
        lrot(t, NODE(x, 0));
        x = NODE(t, 4);
      }
    } else {
      u8 *w = NODE(p, 4);
      if (COL(w) == 1) {
        COL(w) = 0;
        COL(NODE(x, 0)) = 1;
        rrot(t, NODE(x, 0));
        p = NODE(x, 0);
        w = NODE(p, 4);
      }
      if (COL(NODE(w, 8)) == 0 && COL(NODE(w, 4)) == 0) {
        COL(w) = 1;
        x = NODE(x, 0);
      } else {
        if (COL(NODE(w, 4)) == 0) {
          COL(NODE(w, 8)) = 0;
          COL(w) = 1;
          lrot(t, w);
          p = NODE(x, 0);
          w = NODE(p, 4);
        }
        COL(w) = COL(p);
        COL(NODE(x, 0)) = 0;
        COL(NODE(w, 4)) = 0;
        rrot(t, NODE(x, 0));
        x = NODE(t, 4);
      }
    }
  }
  COL(x) = 0;
}
PCREG(4e8450, fn4e8450);
