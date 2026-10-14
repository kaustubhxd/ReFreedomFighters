// batch38043.cpp - cascade s8 batch 38043: 0x5b0010 (build the caption text of an object for the HUD list).
#include "ff.h"

extern "C" u32 THISCALL ext_5afef0(u8 *self, u8 *obj);   // ret 4
extern "C" void THISCALL ext_5aa020(u8 *list, u32 a);    // ret 4
extern "C" void THISCALL ext_5aa060(u8 *list, char *s);  // ret 4
typedef int (*stricmp_t)(const char *, const char *);
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(*fmt3_t)(void *, char *, u32, u32);
typedef u32(*fmt4_t)(void *, char *, u32, u32, u32);
#define imp_stricmp G(stricmp_t, 0x676414)
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)

static const char *obj_name(u8 *obj) {
  u8 *n = (u8 *)SLOT(obj, 0x2e8, v0_t)(obj);
  const char *s = (const char *)0x67c8e8;
  if (*(u32 *)(n + 4)) s = *(const char **)(n + 4);
  return s;
}

// 0x5b0010, thiscall(obj) ret 4. For a flagged object (slot 0x1e0(0x1007d2)) a caption is formatted into a 0x20-byte stack buffer through the engine's text object (slot 0x190 -> 0x198, a sprintf-like call): an
// object named like 0x6ad8b4 / 0x6b0090 gets an empty caption, one named 0x690aec / 0x690af4 the sum of its slot 0x35c value and the helper result (ebx) with the format 0x6784f4, any other the
// 0x6b113c format with both numbers; ebx is 0 unless the list at this[0x1d0b] (slot 0x55c) finds a partner and obj slots 0x328 / 0x364 allow it (partner slot 0x320). An unflagged object uses 0x5afef0
// (a value <= 1 clears the list entry with 0x5aa020 and returns, larger values are formatted with 0x6784f4). Finally the caption goes to 0x5aa060 of the list at this[0x1d0f] when it exists.
static void THISCALL fn5b0010(u8 *self, u8 *obj) {
  if (!obj) return;
  char buf[0x20];
  if ((u8)SLOT(obj, 0x1e0, v1_t)(obj, 0x1007d2)) {
    u32 l28 = SLOT(obj, 0x328, v0_t)(obj);
    u8 *lst = *(u8 **)(self + 0x1d0b);
    u8 *ebx = (u8 *)SLOT(lst, 0x55c, v1_t)(lst, (u32)obj);
    if (ebx && l28 != 0 && SLOT(obj, 0x364, v0_t)(obj) != 0) ebx = (u8 *)SLOT(ebx, 0x320, v0_t)(ebx);
    else ebx = 0;
    l28 = SLOT(obj, 0x35c, v0_t)(obj);
    bool empty = false, sum = false;
    if (imp_stricmp(obj_name(obj), (const char *)0x6ad8b4) == 0) empty = true;
    else if (imp_stricmp(obj_name(obj), (const char *)0x6b0090) == 0) empty = true;
    else if (imp_stricmp(obj_name(obj), (const char *)0x690aec) == 0) sum = true;
    else if (imp_stricmp(obj_name(obj), (const char *)0x690af4) == 0) sum = true;
    if (empty) {
      buf[0] = 0;
    } else if (sum) {
      u8 *a = (u8 *)SLOT(ENG, 0x190, v0_t)(ENG);
      (*(fmt3_t **)a)[0x198 / 4](a, buf, 0x6784f4, l28 + (u32)ebx);
    } else {
      u8 *a = (u8 *)SLOT(ENG, 0x190, v0_t)(ENG);
      (*(fmt4_t **)a)[0x198 / 4](a, buf, 0x6b113c, l28, (u32)ebx);
    }
  } else {
    u32 r = ext_5afef0(self, obj);
    if (r <= 1) {
      ext_5aa020(*(u8 **)(self + 0x1d0f), 0);
      return;
    }
    u8 *a = (u8 *)SLOT(ENG, 0x190, v0_t)(ENG);
    (*(fmt3_t **)a)[0x198 / 4](a, buf, 0x6784f4, r);
  }
  u8 *l = *(u8 **)(self + 0x1d0f);
  if (l) ext_5aa060(l, buf);
}
PCREG(5b0010, fn5b0010);
