#include "ff.h"

typedef void(THISCALL *V1)(void *, u32);
typedef void(THISCALL *VF)(void *, u32, float);
typedef u32(THISCALL *V0)(void *);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// (0xf000 * x) >> 10 as shrd (low 32 bits), then an arithmetic >> 10
static inline s32 fx(s32 x) {
  long long p = (long long)0xf000 * (long long)x;
  return (s32)(u32)(p >> 10) >> 10;
}

// 0x45c180: thiscall(), no arguments, void. Timed ring of 8-bit ids: head this[0x3c], tail this[0x38], capacity (power of two) this[0x1c], keep-count this[0x18], id bytes at
// this[0x248], per-id stamps this[0x250] (dwords, 0 -> now), per-id handles this[0x40], output list this[0x24c] with count this[0x30]. now = fx(engine tick [eng+0x40]) is stored to this[0x24].
// Pass 1 pops ids from the head whose stamp is <= tmpA = fx(tick - (int)(this[0x2c] * 1024)) (appending to the list, destroying the handle through the engine object
// [eng+0x190f] slot 0x20() -> slot 0x40(handle)); pass 2 calls this slot 0x220(id) for every remaining id and, when its stamp is <= tmpB = fx(tick - (int)(this[0x28] * 1024)),
// slot 0x218(id, (stamp - tmpB) * (1.0f / (tmpA - tmpB))); entries before the trimmed head (only the newest this[0x18] are kept) get slot 0x220 only.
extern "C" void THISCALL fn_45c180(u8 *self) {
  s32 tail = (s32)rd32u(self + 0x38);
  s32 ebx = (s32)rd32u(self + 0x3c);
  s32 cnt = (s32)((u32)tail - (u32)ebx);
  if (cnt < 0) cnt = (s32)((u32)cnt + rd32u(self + 0x1c));
  s32 th = (s32)rd32u(self + 0x18);
  if (cnt > th) ebx = (s32)(((u32)tail - (u32)th) & (rd32u(self + 0x1c) - 1));
  s32 local8 = ebx;
  u8 *eng = G(u8 *, 0x70039c);
  float x = rdf(self + 0x2c) * G(float, 0x678620);
  s32 now = fx((s32)rd32u(eng + 0x40));
  s32 ecx = (s32)x;
  wr32u(self + 0x24, (u32)now);
  eng = G(u8 *, 0x70039c);
  s32 tmpA = fx((s32)((u32)rd32u(eng + 0x40) - (u32)ecx));
  if ((s32)rd32u(self + 0x3c) != tail) {
    for (;;) {
      u32 h = rd32u(self + 0x3c);
      if ((s32)h == ebx) break;
      u32 id = ((u8 *)rd32u(self + 0x248))[h];
      u32 *ts = (u32 *)rd32u(self + 0x250);
      if (ts[id] == 0) ts[id] = rd32u(self + 0x24);
      ts = (u32 *)rd32u(self + 0x250);
      if ((s32)ts[id] > tmpA) break;
      u32 c0 = rd32u(self + 0x30);
      ((u32 *)rd32u(self + 0x24c))[c0] = id;
      u32 *hd = (u32 *)rd32u(self + 0x40);
      wr32u(self + 0x30, rd32u(self + 0x30) + 1);
      if (hd[id] == 0) {
        typedef void (*Hook)();
        Hook hk = G(Hook, 0x7003b0);
        if (!hk) __builtin_trap();
        hk();
      }
      u8 *K = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x190f);
      u8 *Mo = (u8 *)(*(V0 *)(vt(K) + 0x20))(K);
      (*(V1 *)(vt(Mo) + 0x40))(Mo, ((u32 *)rd32u(self + 0x40))[id]);
      ((u32 *)rd32u(self + 0x40))[id] = 0;
      u32 nh = (rd32u(self + 0x3c) + 1) & (rd32u(self + 0x1c) - 1);
      wr32u(self + 0x3c, nh);
      if ((s32)nh == (s32)rd32u(self + 0x38)) break;
    }
  }
  float y = rdf(self + 0x28) * G(float, 0x678620);
  s32 edi = (s32)rd32u(self + 0x3c);
  eng = G(u8 *, 0x70039c);
  s32 tmpB = fx((s32)((u32)rd32u(eng + 0x40) - (u32)(s32)y));
  float inv = G(float, 0x678858) / (float)(s32)((u32)tmpA - (u32)tmpB);
  if (edi != (s32)rd32u(self + 0x38)) {
    for (;;) {
      if (edi == local8) break;
      u32 cap1 = rd32u(self + 0x1c) - 1;
      u32 id = ((u8 *)rd32u(self + 0x248))[edi];
      edi = (s32)((u32)(edi + 1) & cap1);
      (*(V1 *)(vt(self) + 0x220))(self, id);
      u32 *ts = (u32 *)rd32u(self + 0x250);
      if (ts[id] == 0) ts[id] = rd32u(self + 0x24);
      ts = (u32 *)rd32u(self + 0x250);
      s32 st = (s32)ts[id];
      if (!(st > tmpB)) (*(VF *)(vt(self) + 0x218))(self, id, (float)(s32)((u32)st - (u32)tmpB) * inv);
      if (edi == (s32)rd32u(self + 0x38)) break;
    }
    if (edi != (s32)rd32u(self + 0x38)) {
      do {
        u32 id = ((u8 *)rd32u(self + 0x248))[edi];
        (*(V1 *)(vt(self) + 0x220))(self, id);
        edi = (s32)((u32)(edi + 1) & (rd32u(self + 0x1c) - 1));
      } while (edi != (s32)rd32u(self + 0x38));
    }
  }
}
PCREG(45c180, fn_45c180);
