// batch38005.cpp - cascade s8 batch 38005: 0x4e81d0 (red-black tree insert with rebalance).
#include "ff.h"

extern "C" void THISCALL ext_4e8160(u8 *tree, u8 *node);   // thiscall, ret 4 (plain BST insert)

// Node: +0 parent, +4 left, +8 right, +0x10 color byte (1 = red). Tree: +4 root, +8 nil node.
#define PAR(n) (*(u8 **)(n))
#define LEFT(n) (*(u8 **)((n) + 4))
#define RIGHT(n) (*(u8 **)((n) + 8))
#define COL(n) ((n)[0x10])

// 0x4e81d0, thiscall(node) ret 4: inserts the node with 0x4e8160, colors it red and runs the standard red-black fix-up loop; paints the root black and returns it.
static u8 *THISCALL fn4e81d0(u8 *self, u8 *x) {
  ext_4e8160(self, x);
  COL(x) = 1;
  u8 *nil = *(u8 **)(self + 8);
  while (x != *(u8 **)(self + 4)) {
    u8 *p = PAR(x);
    if (COL(p) != 1) break;
    u8 *g = PAR(p);
    u8 *u = LEFT(g);
    if (p == u) {   // parent is the left child
      u = RIGHT(g);
      if (COL(u) == 1) {
        COL(p) = 0;
        COL(u) = 0;
        COL(PAR(PAR(x))) = 1;
        x = PAR(PAR(x));
        continue;
      }
      if (x == RIGHT(p)) {
        x = p;
        u8 *c = RIGHT(x);
        RIGHT(x) = LEFT(c);
        u8 *t = LEFT(c);
        if (t != nil) PAR(t) = x;
        PAR(c) = PAR(x);
        u8 *q = PAR(x);
        if (q == nil) *(u8 **)(self + 4) = c;
        else if (x == LEFT(q)) LEFT(q) = c;
        else RIGHT(q) = c;
        LEFT(c) = x;
        PAR(x) = c;
      }
      COL(PAR(x)) = 0;
      COL(PAR(PAR(x))) = 1;
      g = PAR(PAR(x));
      u8 *c = LEFT(g);
      LEFT(g) = RIGHT(c);
      u8 *t = RIGHT(c);
      if (t != nil) PAR(t) = g;
      PAR(c) = PAR(g);
      u8 *q = PAR(g);
      if (q == nil) {
        *(u8 **)(self + 4) = c;
        RIGHT(c) = g;
      } else if (g == RIGHT(q)) {
        RIGHT(q) = c;
        RIGHT(c) = g;
      } else {
        LEFT(q) = c;
        RIGHT(c) = g;
      }
      PAR(g) = c;
    } else {   // parent is the right child
      if (COL(u) == 1) {
        COL(p) = 0;
        COL(u) = 0;
        COL(PAR(PAR(x))) = 1;
        x = PAR(PAR(x));
        continue;
      }
      if (x == LEFT(p)) {
        x = p;
        u8 *c = LEFT(x);
        LEFT(x) = RIGHT(c);
        u8 *t = RIGHT(c);
        if (t != nil) PAR(t) = x;
        PAR(c) = PAR(x);
        u8 *q = PAR(x);
        if (q == nil) *(u8 **)(self + 4) = c;
        else if (x == RIGHT(q)) RIGHT(q) = c;
        else LEFT(q) = c;
        RIGHT(c) = x;
        PAR(x) = c;
      }
      COL(PAR(x)) = 0;
      COL(PAR(PAR(x))) = 1;
      g = PAR(PAR(x));
      u8 *c = RIGHT(g);
      RIGHT(g) = LEFT(c);
      u8 *t = LEFT(c);
      if (t != nil) PAR(t) = g;
      PAR(c) = PAR(g);
      u8 *q = PAR(g);
      if (q == nil) *(u8 **)(self + 4) = c;
      else if (g == LEFT(q)) LEFT(q) = c;
      else RIGHT(q) = c;
      LEFT(c) = g;
      PAR(g) = c;
    }
  }
  u8 *root = *(u8 **)(self + 4);
  COL(root) = 0;
  return root;
}
PCREG(4e81d0, fn4e81d0);
