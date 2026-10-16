// batch6517.cpp - unclaimed-65: batch 17 (docs/20-unclaimed-65.md, claim 17). Thiscall, one stack argument (DBREAD&, ret 4).
// SEH frame not reproduced (the fs:[0] writes are not compared); the cookie check is not called.
#include "ff.h"

extern "C" void THISCALL ext_4ccba0(u8 *loc);                      // builds the local struct (no-op in the harness)
extern "C" u32 THISCALL ext_4e6330(u8 *dbread, u8 *loc);            // DBREAD read into the struct (one argument, ret 4)
extern "C" void THISCALL ext_4ccf60(u8 *loc);                      // releases the struct (no-op in the harness)

typedef u32(THISCALL *F0)(u8 *self);
typedef u32(THISCALL *F1)(u8 *self, u32 a);

static u32 vc0(u8 *o, u32 s) { return ((F0)(*(const u32 *)(*(const u32 *)o + s)))(o); }
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }

// 0x5c3b00, COpenSewer::ReadInput(DBREAD&) (residue 16). SEH frame not reproduced.
static void THISCALL openSewerReadInput(u8 *self, u8 *dbread) {
  u8 loc[0xc0];
  ext_4ccba0(loc);
  ext_4e6330(dbread, loc);
  u8 *render = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  if (!((u8)vc0(render, 0x2c))) {
    u32 tmp = 0;
    const u32 *lvt = (const u32 *)loc;
    (void)lvt;
    // the struct's first dword is its vtable; the calls take the struct's address as this
    u32 vt0 = *(const u32 *)loc;
    ((F1)(*(const u32 *)(vt0 + 0x4c)))((u8 *)loc, (u32)&tmp);
    u32 item = ((F1)(*(const u32 *)(vt0 + 0x5c)))((u8 *)loc, (u32)&tmp);
    while (tmp) {
      u8 *base = G(u8 *, 0x7003b8) + 0xc69;
      const u32 cnt = *(const u32 *)base;
      u8 *rec = base + 9 * cnt + 4;
      *(u32 *)rec = (u32)self;
      *(u32 *)(rec + 4) = item;
      rec[8] = 0;
      *(u32 *)base = cnt + 1;
      item = ((F1)(*(const u32 *)(vt0 + 0x5c)))((u8 *)loc, (u32)&tmp);
    }
  }
  ext_4ccf60(loc);
}
PCREG(5c3b00, openSewerReadInput);
