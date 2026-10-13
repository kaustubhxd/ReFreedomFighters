// batch1422.cpp - missions thread, batch 1422: ZFFCareTaker_C04B::Command (the rebel base: two bombs, the helipad and
// the train). Layout from the code: +0x44 event sender, +0x4c byte "train bomb placed", +0x4d byte "helipad bomb
// placed", +0x4e the object of the event's data (the bomb), +0x52 train handle, +0x56 helipad handle.
//
// GUESS (for the reader only; the code follows the machine code): the two handles are the helipad and the train, and
// the bomb must be within 1000 units of each. The original computes both distances from the bomb's position and
// sends BOMB_WAS_PLACED to the helipad or train when it is close, else logs "too far away".
#include "missions.h"

extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);   // PSVECSubtract (dst = a - b)
extern "C" float FASTCALL ext_634d7c(double *x);   // (not used; the CRT sqrt goes through libm1 below)
typedef double(VECTORCALL *libm1)(double);
#define CARETAKER_C04B_CPP 0x6b2fe4u

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }
static inline u8 *byHandle(u32 h) { return vcall<u8 *, u32>(mgr(), 0x58, h); }
static inline u16 msgId(const char *name, u32 line) {
  return vcall<u16, const char *, u32, const char *, u32>(mgr(), 0x114, name, 0, (const char *)CARETAKER_C04B_CPP, line);
}
#define U32(o) (*(u32 *)(ct + (o)))
static inline void send(u8 *ct, u32 target, u32 msg) {
  vcall<void, u32, u32, u32>(*(u8 **)(ct + 0x44), 0x12c, target, msg, 0);
}
static inline void logf(u32 line, const char *text) {
  void *lg = G(void *, 0x700390);
  void *pr = ((void *(THISCALL *)(void *, const char *, u32))(*(void ***)lg)[0x20 / 4])(lg, (const char *)CARETAKER_C04B_CPP, line);
  ((void(*)(void *, const char *))(*(void ***)pr)[0x2c / 4])(pr, text);
}
// Distance from point a to point b, as the original: squares summed as ((y*y + x*x) + z*z), CRT sqrt in double, rounded.
static float dist(const float *a, const float *b) {
  float d[3];
  ext_43e920(d, a, b);
  float s = d[1] * d[1] + d[0] * d[0];
  s = s + d[2] * d[2];
  return (float)(*(libm1 *)0x676330)((double)s);
}

// 0x5bc6e0 ZFFCareTaker_C04B::Command(unsigned short msg, void *data). Returns 0.
//  MSG_EVENT_STARTED (line 0x34): data[1] is the bomb. U = its position. Helipad (+0x56) within 1000 of the bomb:
//    BOMB_WAS_PLACED to the helipad (line 0x4e) and the helipad log (+0x4d = 1); otherwise the "too far away" log.
//    Then the same for the train (+0x52, lines 0x57/0x58/0x5c, +0x4c).
//  MSG_ITEMNOTIFY (line 0x65): with +0x4d, BOMB_WAS_BLOWN (line 0x66) to the helipad; with +0x4c, the same (0x67) to the
//    train. Then the bomb object (+0x4e) gets slot 0x2f0(0, 0, 1), and its object from slot 0x20 slot 0x210(1).
static u32 THISCALL c04bCommand(u8 *ct, u32 msg, u32 *data) {
  u16 m = (u16)msg;
  if (m == msgId((const char *)0x6b2d24, 0x34)) {   // MSG_EVENT_STARTED
    u8 *bomb = byHandle(data[1]);
    U32(0x4e) = (u32)bomb;
    float mat[9], pb[3], pc[3];
    vcall<void, float *, float *>(bomb, 0x80, mat, pb);
    u8 *helipad = byHandle(U32(0x56));
    vcall<void, float *, float *>(helipad, 0x80, mat, pc);
    if (comiss_gt(1000.0f, dist(pc, pb))) {
      send(ct, U32(0x56), msgId((const char *)0x6a4e0c, 0x4e));   // BOMB_WAS_PLACED
      logf(0x4f, (const char *)0x6b301c);   // Helipad - a bomb was placed correctly
      ct[0x4d] = 1;
    } else {
      logf(0x53, (const char *)0x6b3058);   // ... too far away from the helipad
      ct[0x4d] = 0;
    }
    u8 *train = byHandle(U32(0x52));
    vcall<void, float *, float *>(train, 0x80, mat, pc);
    if (comiss_gt(1000.0f, dist(pc, pb))) {
      send(ct, U32(0x52), msgId((const char *)0x6a4e0c, 0x57));   // BOMB_WAS_PLACED
      logf(0x58, (const char *)0x6b30a0);   // Train - a bomb was placed correctly near the train
      ct[0x4c] = 1;
    } else {
      logf(0x5c, (const char *)0x6b30f0);   // ... too far away from the train
      ct[0x4c] = 0;
    }
  }
  if (m == msgId((const char *)0x6b2da8, 0x65)) {   // MSG_ITEMNOTIFY
    if (ct[0x4d])
      send(ct, U32(0x56), msgId((const char *)0x6a4e1c, 0x66));   // BOMB_WAS_BLOWN
    if (ct[0x4c])
      send(ct, U32(0x52), msgId((const char *)0x6a4e1c, 0x67));   // BOMB_WAS_BLOWN
    u8 *bomb = (u8 *)U32(0x4e);
    vcall<void, u32, u32, u32>(vcall<u8 *>(bomb, 0x20), 0x2f0, 0, 0, 1);
    u8 *o = vcall<u8 *>(bomb, 0x20);
    if (o)
      vcall<void, u32>(o, 0x210, 1);
  }
  return 0;
}
PCREG(5bc6e0, c04bCommand);
