// batch730.cpp - soldier AI, batch 730 (2026-10-12): CActorActionMarker::Add(ZCTRLIKLNKOBJ* obj, EACTIONMARKER type, float time)
// (0x5eab20). The marker holds up to 16 records (count at +0x44, record pointers from +4). Record: obj at +0, type at +4,
// time at +8, a at +0xc, b at +0x10, flag byte at +0x14. The flag is 1 when the time is not negative (NaN counts as not
// negative) and 0 otherwise, and a negative time is stored as its absolute value. An existing record for obj keeps its
// slot: when the type changes, a and b are set from the old type and time (type 1) or to zero (other types), and the
// time is replaced. A new record is appended at the count with a = b = 0. A full marker (16) does nothing.
#include "ff.h"

struct MarkerRec {
  u32 obj;      // +0
  u32 type;     // +4
  float time;   // +8
  u32 a;        // +0xc
  u32 b;        // +0x10
  u8 flag;      // +0x14
};

// 0x5eab20 CActorActionMarker::Add(ZCTRLIKLNKOBJ* obj, ZOnScreenDisplay::EACTIONMARKER type, float time) [medium].
static void THISCALL marker_Add(u8 *self, void *obj, u32 type, float time) {
  u32 n = *(u32 *)(self + 0x44);
  if (n == 0x10)
    return;
  MarkerRec **arr = (MarkerRec **)(self + 4);

  u32 k = 0;
  while (k < n && *(void **)arr[k] != obj)
    k++;

  bool nonneg = !(time < 0.0f);
  if (!nonneg)
    time = -time;

  if (k < n) {
    MarkerRec *r = arr[k];
    r->flag = nonneg ? 1 : 0;
    if (type != r->type) {
      if (type == 1) {
        r->a = r->type;
        r->b = *(u32 *)&r->time;   // the old time (dword view) goes to +0x10
      } else {
        r->a = 0;
        r->b = 0;
      }
      r->type = type;
    }
    r->time = time;
    return;
  }

  MarkerRec *r = arr[n];
  r->flag = nonneg ? 1 : 0;
  r->obj = (u32)obj;
  r->type = type;
  r->time = time;
  r->a = 0;
  r->b = 0;
  *(u32 *)(self + 0x44) = n + 1;
}
PCREG(5eab20, marker_Add);
