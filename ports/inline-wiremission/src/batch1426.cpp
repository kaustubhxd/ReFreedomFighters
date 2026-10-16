// batch1426.cpp - missions thread, batch 1426: ZFFCareTaker_C08C (bomb director): Init and Command.
//
// Layout: +0x44 event sender, +0x48 the last item object (used by the final flag calls), +0x4c REFTAB list of item
// handles (an embedded list object: slot 0x4c starts, slot 0x5c gives the next item).
#include "missions.h"

extern "C" void THISCALL ext_4e6330(u32 *db, u8 *tab);                             // DBREAD::GetRefTab(REFTAB*)
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);   // PSVECSubtract (dst = a - b)
typedef double(VECTORCALL *libm1)(double);
#define CARETAKER_C08C_CPP 0x6b32b8u

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }
static inline u8 *byHandle(u32 h) { return vcall<u8 *, u32>(mgr(), 0x58, h); }
#define U32(o) (*(u32 *)(ct + (o)))

// 0x5bd070 ZFFCareTaker_C08C::Init(ZGROUP*, DBREAD&): the REFTAB list at +0x4c from the data, then registration as
// "ObjectItemNotify" (manager slot 0x4c(sender, 0x10) -> handle, registry slot 0x60(name, handle)).
static void THISCALL c08cInit(u8 *ct, void *group, u32 *db) {
  (void)group;
  ext_4e6330(db, ct + 0x4c);
  u8 *reg = vcall<u8 *>(mgr(), 0x138);
  u32 t = vcall<u32, u32, u32>(mgr(), 0x4c, U32(0x44), 0x10);
  vcall<void, const char *, u32>(reg, 0x60, (const char *)0x6b2cd8, t);
}
PCREG(5bd070, c08cInit);

// 0x5bd0d0 ZFFCareTaker_C08C::Command(unsigned short msg, void *data). On MSG_ITEMNOTIFY (line 0x2c, id compared):
//   the +0x4c list is walked. For each item handle: count++, the item object goes to +0x48, and the distance from the
//   item to the bomb (data[1]) is measured (squares summed as ((y*y + x*x) + z*z), CRT sqrt). Within 1000 units:
//   BOMB_WAS_BLOWN (line 0x47) is sent to the item (two-word send), and "The bomb was blown %i" (line 0x48) logs count.
//   Afterwards the object at +0x48 gets slot 0x2f0(0, 0, 1), and its object from slot 0x20 gets slot 0x210(1).
// Returns 0.
static u32 THISCALL c08cCommand(u8 *ct, u32 msg, u32 *data) {
  u16 want = vcall<u16, const char *, u32, const char *, u32>(mgr(), 0x114, (const char *)0x6b2da8, 0,
                                                              (const char *)CARETAKER_C08C_CPP, 0x2c);   // MSG_ITEMNOTIFY
  if ((u16)msg != want)
    return 0;
  u8 *list = ct + 0x4c;
  u32 it = 0;
  vcall<void, u32 *>(list, 0x4c, &it);
  u32 item = vcall<u32, u32 *>(list, 0x5c, &it);
  u32 count = 0;
  while (it) {
    if (item) {
      count++;
      u8 *obj = byHandle(item);
      U32(0x48) = (u32)obj;
      u8 *bomb = byHandle(data[1]);
      float pb[3], pi[3], mat[9], d[3];
      vcall<void, float *, float *>(obj, 0x80, mat, pi);
      vcall<void, float *, float *>(bomb, 0x80, mat, pb);
      ext_43e920(d, pb, pi);
      float s = d[1] * d[1] + d[0] * d[0];
      s = s + d[2] * d[2];
      float dd = (float)(*(libm1 *)0x676330)((double)s);
      if (comiss_gt(1000.0f, dd)) {
        u16 id = vcall<u16, const char *, u32, const char *, u32, u32>(mgr(), 0x114, (const char *)0x6a4e1c, 0,
                                                                       (const char *)CARETAKER_C08C_CPP, 0x47, 0);   // BOMB_WAS_BLOWN
        vcall<void, u32, u32>(*(u8 **)(ct + 0x44), 0x12c, item, (u32)id);
        LOGF(CARETAKER_C08C_CPP, 0x48, (const char *)0x6b32f0, count);
      }
    }
    item = vcall<u32, u32 *>(list, 0x5c, &it);
  }
  u8 *o = vcall<u8 *>(*(u8 **)(ct + 0x48), 0x20);
  vcall<void, u32, u32, u32>(o, 0x2f0, 0, 0, 1);
  u8 *o2 = vcall<u8 *>(*(u8 **)(ct + 0x48), 0x20);
  if (o2)
    vcall<void, u32>(o2, 0x210, 1);
  return 0;
}
PCREG(5bd0d0, c08cCommand);
