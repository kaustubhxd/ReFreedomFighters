// batch67.cpp - grenade flight, inline session batch 67: ZProjectile::Explode (0x4b95d0).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef void(THISCALL *vcallV0)(void *self);
typedef u32(THISCALL *regFn)(void *self, u32 name, u32 a, u32 file, u32 line);
typedef void(THISCALL *sendCmdFn)(void *self, u32 cmd, void *data, void *sender);

extern "C" void THISCALL ext_4ba7f0(u8 *self, u8 *coli);   // ZProjectile::ShotImpact

// 0x4b95d0 ZProjectile::Explode(const float *vel), thiscall, ret 4. Runs ShotImpact on the projectile's COLI (+0x8d),
// then registers the explosion message (ZEngineDataBase::RegisterZMsg, render manager slot 0x114, ZProjectile.cpp line
// 401) and sends it to its own geometry (+0x44, ZGEOM::SendCommand, slot 0x128 through the vtable read before the
// register call; no sender) with a block of the hit point (COLI +0x28), the velocity, the surface normal (+0x75), the
// owner (+0x5d) and the hit handle (COLI +0x44). The geometry is hidden (slot 0x28) when byte +0x50 is set. Flags 2
// and 4 in +0x89 mark it done. (The compiler pushes SendCommand's last two arguments before RegisterZMsg's four.)
static void THISCALL explode(u8 *self, const float *vel) {
  ext_4ba7f0(self, *(u8 **)(self + 0x8d));
  u8 *coli = *(u8 **)(self + 0x8d);
  u32 blk[11];
  float *f = (float *)blk;
  f[0] = *(float *)(coli + 0x28);
  f[1] = *(float *)(coli + 0x2c);
  f[2] = *(float *)(coli + 0x30);
  f[3] = vel[0];
  f[4] = vel[1];
  f[5] = vel[2];
  f[6] = *(float *)(self + 0x75);
  f[7] = *(float *)(self + 0x79);
  f[8] = *(float *)(self + 0x7d);
  blk[9] = *(u32 *)(self + 0x5d);
  blk[10] = *(u32 *)(coli + 0x44);
  void **gvt = *(void ***)*(u8 **)(self + 0x44);
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u16 id = (u16)((regFn)VT(rm, 0x114))(rm, 0x692b34u, 0, 0x692ab4u, 0x191);
  ((sendCmdFn)gvt[0x128 / 4])(*(u8 **)(self + 0x44), id, blk, 0);
  if (self[0x50]) {
    u8 *g = *(u8 **)(self + 0x44);
    ((vcallV0)VT(g, 0x28))(g);
  }
  *(u32 *)(self + 0x89) |= 6;
}
PCREG(4b95d0, explode);
