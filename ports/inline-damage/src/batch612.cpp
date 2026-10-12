// batch612.cpp - damage thread, batch 612: CHitpointControl::Notify and FrameUpdate (destroyed -> message).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
#define ENGINE G(u8 *, 0x70039c)

typedef u32 (THISCALL *vPU)(void *self, u32 a);
typedef void (THISCALL *vSend)(void *self, u32 to, u32 msg, void *data);
typedef void (THISCALL *vUU)(void *self, u32 a, u32 b);

// The target handle (+0x50) is resolved from the owner geom (+0x44) on first use (render manager slot 0x4c); the
// message id is +0x54 and the data {last attacker +0x6c, 0}. The owner geom sends it (slot 0x12c).
static inline void send(u8 *self) {
  if (!*(u32 *)(self + 0x50)) {
    u8 *rm = *(u8 **)(ENGINE + 0x9b);
    *(u32 *)(self + 0x50) = ((vPU)VT(rm, 0x4c))(rm, *(u32 *)(self + 0x44));
  }
  u8 *g = *(u8 **)(self + 0x44);
  u32 data[2] = {*(u32 *)(self + 0x6c), 0};
  ((vSend)VT(g, 0x12c))(g, *(u32 *)(self + 0x50), *(u16 *)(self + 0x54), data);
}

// 0x5849d0 CHitpointControl::Notify() (GC 800d0040).
static void THISCALL hpcNotify(u8 *self) { send(self); }
PCREG(5849d0, hpcNotify);

// 0x5843d0 CHitpointControl::FrameUpdate() (GC 800d0174): the explosion delay +0x57 counts down by the frame time
// (engine +0x48); at <= 0 the message goes out and own slot 0x68(0x10, 0) stops the per-frame update (inferred).
static void THISCALL hpcFrameUpdate(u8 *self) {
  float t = *(float *)(self + 0x57) - *(float *)(ENGINE + 0x48);
  *(float *)(self + 0x57) = t;
  if (!(t <= 0.0f)) return;
  send(self);
  ((vUU)VT(self, 0x68))(self, 0x10, 0);
}
PCREG(5843d0, hpcFrameUpdate);
