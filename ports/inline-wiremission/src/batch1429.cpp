// batch1429.cpp - missions thread, batch 1429: ZObjectives::Command (the map's Msg_SetMap handler).
// Interface slots are unnamed and are called by number. The code keeps the original's `this` (ECX) values:
//   - ZSysInterface slot 0x190() gives object A; the same slot gives object B (two calls);
//   - A's slot 0x198 is called with ECX = the output buffer (buf1), arguments (A, buf1, fmt, zone);
//   - B's slot 0x198 is called with ECX = B's vtable pointer, arguments (B, buf2, fmt, this+0x206);
//   - the window object at [this+0x18c]: slot 0x2a0(int) and slot 0x284(const char*).
#include "missions.h"

extern "C" u32 THISCALL ext_573860(u8 *self, u32 msg, u32 data);   // ZBaseMap::Command(unsigned short, void*)
#define OBJECTIVES_CPP 0x6a98acu

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }

// Unnamed slots.
static inline u8 *sys190() { return ((u8 *(THISCALL *)(u8 *))(*(void ***)sysi())[0x190 / 4])(sysi()); }
// The formatter at slot 0x198 is caller-cleaned (the original does `add esp, 0x10` after each call), with ECX = this.
// Four words pushed in the original's order: s (deepest), fmt, buf, a (top).
static void callFmt198(void *fn, void *ecxv, void *a, void *buf, const char *fmt, const char *s) {
  void *arr[6] = {(void *)s, (void *)fmt, buf, a, ecxv, fn};
  asm volatile("pushl 0(%0)\n\tpushl 4(%0)\n\tpushl 8(%0)\n\tpushl 12(%0)\n\tmovl 16(%0), %%ecx\n\tcalll *20(%0)\n\taddl $16, %%esp"
               :
               : "r"(arr)
               : "eax", "ecx", "edx", "memory", "cc");
}
// buf1 = format of (A, buf1, fmt, zone) with this = buf1.
static void formatA(u8 *a, char *buf, const char *fmt, const char *s) {
  callFmt198((*(void ***)a)[0x198 / 4], buf, a, buf, fmt, s);
}
// buf2 = format of (B, buf2, fmt, this+0x206) with this = B's vtable pointer.
static void formatB(u8 *b, char *buf, const char *fmt, const char *s) {
  callFmt198((*(void ***)b)[0x198 / 4], *(void **)b, b, buf, fmt, s);
}
static inline void slot2a0(u8 *o, s32 v) { ((void(THISCALL *)(u8 *, s32))(*(void ***)o)[0x2a0 / 4])(o, v); }
static inline void slot284(u8 *o, const char *s) { ((void(THISCALL *)(u8 *, const char *))(*(void ***)o)[0x284 / 4])(o, s); }

static bool sameStr(const u8 *a, const u8 *b) {
  for (;;) {
    if (a[0] != b[0]) return false;
    if (a[0] == 0) return true;
    if (a[1] != b[1]) return false;
    if (a[1] == 0) return true;
    a += 2;
    b += 2;
  }
}

// 0x5779a0 ZObjectives::Command(unsigned short msg, void *data). Msg_SetMap (line 0xe6); data is the zone name.
//  - another message: ZBaseMap::Command(msg, data), its result returned.
//  - data null: return 0.
//  - the name is copied to this+0x206; this+0x1b0 = rc[0]("Menu/GoToAnotherZone/SubZoneTitle", data);
//    a copy of the name gives this+0x1b4 = rc[0]("Menu/GoToAnotherZone/ZoneSubTitle", copy).
//  - buf1 = "%sB/Briefing" of the zone name at [this+0x94]+0x48 (A's slot 0x198); buf1[3] = 'R';
//    buf2 = "%s_Summary" of this+0x206 (B's slot 0x198).
//  - window = [this+0x18c]: zone "C01A" -> window.slot284(" "); otherwise window.slot2a0((int)(0.75 * sys_int(+0x6f)))
//    and window.slot284(rc[0](buf1, buf2)).
//  Returns 0 on this path.
static u32 THISCALL zobjCommand(u8 *self, u32 msg, u32 data) {
  u16 id = vcall<u16, const char *, u32, const char *, u32>(mgr(), 0x114, (const char *)0x6a77a0, 0,
                                                            (const char *)OBJECTIVES_CPP, 0xe6);   // Msg_SetMap
  if ((u16)msg != id)
    return ext_573860(self, msg, data);
  if (!data)
    return 0;
  {
    char *d = (char *)(self + 0x206);
    const char *s = (const char *)data;
    while ((*d++ = *s++) != 0) {}
  }
  u8 *rc = *(u8 **)(mgr() + 0xae4);
  *(const char **)(self + 0x1b0) =
      vcall<const char *, const char *, const char *>(rc, 0, (const char *)0x6a930c, (const char *)data);
  char tmp[0x80];
  {
    char *d = tmp;
    const char *s = (const char *)data;
    while ((*d++ = *s++) != 0) {}
  }
  *(const char **)(self + 0x1b4) =
      vcall<const char *, const char *, const char *>(rc, 0, (const char *)0x6a925c, tmp);
  char buf1[0x80], buf2[0x80];
  const char *zone = (const char *)(*(u8 **)(self + 0x94) + 0x48);
  formatA(sys190(), buf1, (const char *)0x6a98d8, zone);   // "%sB/Briefing"
  buf1[3] = 'R';
  formatB(sys190(), buf2, (const char *)0x6a98e8, (const char *)(self + 0x206));   // "%s_Summary"
  u8 *win = *(u8 **)(self + 0x18c);
  if (sameStr((const u8 *)zone, (const u8 *)0x6a7808)) {   // "C01A"
    slot284(win, (const char *)0x679e6c);                  // " "
    return 0;
  }
  s32 v = (s32)((float)(s32)*(s32 *)(sysi() + 0x6f) * 0.75f);
  slot2a0(win, v);
  const char *text3 = vcall<const char *, const char *, const char *>(rc, 0, buf1, buf2);
  slot284(win, text3);
  return 0;
}
PCREG(5779a0, zobjCommand);
