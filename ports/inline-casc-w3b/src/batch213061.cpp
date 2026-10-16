#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V3)(void *, u32, u32, u32);

extern "C" u32 THISCALL ext_564600(void *self, u32 a);
extern "C" u32 THISCALL ext_5646e0(void *self, u32 a);
extern "C" u32 THISCALL ext_565100(void *self, u32 a);
extern "C" u32 THISCALL ext_56b460(void *self, u32 a);
extern "C" u32 THISCALL ext_56c6a0(void *self);
extern "C" u32 THISCALL ext_562bc0(void *self);
extern "C" u32 THISCALL ext_563400(void *self);
extern "C" u32 THISCALL ext_563440(void *self);
extern "C" u32 THISCALL ext_5ae710(void *self, u32 a);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

// 0x56b730: thiscall(msg) ret 4, no defined return value: message handler of a screen state machine, selected by this->[0xc82] - 8 (byte map at 0x56b910,
// 13 jump table targets at 0x56b8dc). Messages: 0x457 and 0x8ae (state-specific actions through slot 0xd0 / 0xfc / 0x564600 / 0x565100), 0xd05; states 26, 27, 30 ignore
// the message (26: scan reset through slot 0x20 of this->[0xc5e], 27: 0x5ae710 and an engine table call, 30: 0x563440), anything unlisted calls 0x5646e0(msg).
extern "C" void THISCALL fn_56b730(u8 *self, u32 msg) {
  u32 st = rd32u(self + 0xc82) - 8;
  static const u8 map[25] = {0, 0, 12, 12, 12, 0, 12, 12, 1, 2, 0, 12, 3, 4, 12, 5, 6, 12, 7, 8, 12, 9, 10, 12, 11};
  u32 k = st > 0x18 ? 12 : map[st];
  switch (k) {
    case 0:  // states 8, 9, 13, 18
      if (msg == 0xd05) (*(V1 *)(*(u8 **)self + 0xd0))(self, 0);
      return;
    case 1:  // 16
      if (msg == 0x457) { (*(V1 *)(*(u8 **)self + 0xd0))(self, 0); return; }
      if (msg == 0x8ae) ext_564600(self, 0);
      return;
    case 2:  // 17
      if (msg == 0x457) { ext_564600(self, 1); return; }
      if (msg == 0x8ae) ext_564600(self, 3);
      return;
    case 3:  // 20
      if (msg == 0x457) { (*(V1 *)(*(u8 **)self + 0xfc))(self, 0); return; }
      if (msg == 0x8ae) ext_564600(self, 3);
      return;
    case 4:  // 21
      if (rd32u(self + 0xcee) != 4) return;
      if (msg == 0x457) { (*(V1 *)(*(u8 **)self + 0xd0))(self, 0); return; }
      if (msg != 0x8ae) return;
      if ((u8)ext_563400(self)) { ext_565100(self, 0x17); return; }
      ext_564600(self, 4);
      return;
    case 5:  // 23
      if (rd32u(self + 0xcee) != 4) return;
      if (msg == 0x457) { (*(V1 *)(*(u8 **)self + 0xd0))(self, 0); return; }
      if (msg == 0x8ae) ext_564600(self, 4);
      return;
    case 6:  // 24
      if (msg == 0x457) { (*(V1 *)(*(u8 **)self + 0xd0))(self, 0); return; }
      if (msg == 0x8ae) ext_564600(self, 5);
      return;
    case 7: {  // 26
      void *o = (void *)rd32u(self + 0xc5e);
      wr32u(self + 0xce2, 0);
      wr32u(self + 0xce6, (*(V0 *)(*(u8 **)o + 0x20))(o));
      ext_56c6a0(self);
      ext_56b460(self, rd32u(self + 0xce2));
      return;
    }
    case 8: {  // 27
      ext_5ae710((u8 *)rd32u(self + 0x94) + 0x57, 0);
      u8 *eng = G(u8 *, 0x70039c);
      void *tab = (void *)rd32u(eng + 0x9b);
      void *x = (void *)(*(V0 *)(*(u8 **)tab + 0x134))(tab);
      (*(V3 *)(*(u8 **)x + 0x5c))(x, 0x6a777c, 0, 2);
      ext_562bc0(self);
      return;
    }
    case 9:  // 29
      ext_564600(self, 1);
      return;
    case 10:  // 30
      ext_563440(self);
      return;
    case 11:  // 32
      (*(V1 *)(*(u8 **)self + 0xd0))(self, 0);
      return;
    default:
      ext_5646e0(self, msg);
      return;
  }
}
PCREG(56b730, fn_56b730);
