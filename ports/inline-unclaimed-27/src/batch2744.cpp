#include "ff.h"
// batch2744.cpp - unclaimed-27 batch 46 (residue 6). Fifteen more copies of the splice in batches 44 and 45, each with its own globals.
// Names unknown (GUESS).
template <u32 CG, u32 AG>
static void funcSpliceAt() {
  u32 c = G(u32, CG);
  u32 a = G(u32, AG);
  if (c != 0) {
    *(u32 *)(unsigned long)(c + 0x14) = a;
    a = G(u32, AG);
    c = G(u32, CG);
  } else {
    G(u32, 0x7003bc) = a;
  }
  if (a != 0) {
    *(u32 *)(unsigned long)(a + 0x10) = c;
  } else {
    G(u32, 0x7003c0) = c;
  }
  G(u32, CG) = 0;
  G(u32, AG) = 0;
}

static void funcSplice6704e0() { funcSpliceAt<0x6e6024u, 0x6e6028u>(); }
PCREG(6704e0, funcSplice6704e0);
static void funcSplice670620() { funcSpliceAt<0x6e60ccu, 0x6e60d0u>(); }
PCREG(670620, funcSplice670620);
static void funcSplice670760() { funcSpliceAt<0x6e62a0u, 0x6e62a4u>(); }
PCREG(670760, funcSplice670760);
static void funcSplice6708a0() { funcSpliceAt<0x6e63ccu, 0x6e63d0u>(); }
PCREG(6708a0, funcSplice6708a0);
static void funcSplice6709e0() { funcSpliceAt<0x6e64e4u, 0x6e64e8u>(); }
PCREG(6709e0, funcSplice6709e0);
static void funcSplice670b20() { funcSpliceAt<0x6e658cu, 0x6e6590u>(); }
PCREG(670b20, funcSplice670b20);
static void funcSplice670c60() { funcSpliceAt<0x6e6708u, 0x6e670cu>(); }
PCREG(670c60, funcSplice670c60);
static void funcSplice670da0() { funcSpliceAt<0x6e6c1cu, 0x6e6c20u>(); }
PCREG(670da0, funcSplice670da0);
static void funcSplice670ee0() { funcSpliceAt<0x6e689cu, 0x6e68a0u>(); }
PCREG(670ee0, funcSplice670ee0);
static void funcSplice674fe0() { funcSpliceAt<0x6ef704u, 0x6ef708u>(); }
PCREG(674fe0, funcSplice674fe0);
static void funcSplice675120() { funcSpliceAt<0x6ef7e4u, 0x6ef7ecu>(); }
PCREG(675120, funcSplice675120);
static void funcSplice675260() { funcSpliceAt<0x6ef8e4u, 0x6ef8e8u>(); }
PCREG(675260, funcSplice675260);
static void funcSplice6753a0() { funcSpliceAt<0x6ef9c4u, 0x6ef9c8u>(); }
PCREG(6753a0, funcSplice6753a0);
static void funcSplice6754e0() { funcSpliceAt<0x6efaa4u, 0x6efaa8u>(); }
PCREG(6754e0, funcSplice6754e0);
static void funcSplice675620() { funcSpliceAt<0x6efb84u, 0x6efb88u>(); }
PCREG(675620, funcSplice675620);
