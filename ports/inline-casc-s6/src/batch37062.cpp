// batch37062.cpp - cascade s6 batch 37062: 0x56fc90.
#include "ff.h"

extern "C" void THISCALL ext_56ef50(u8 *self, u8 *line);   // ret 4
extern "C" void THISCALL ext_56fb10(u8 *self);             // plain ret
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
#define F32(o) (*(u32 *)(self + (o)))

static s32 slen(const u8 *p) {
  const u8 *q = p;
  while (*q) q++;
  return (s32)(q - p);
}

// 0x56fc90, thiscall, no args: when the flag byte this+0x198 is set, takes the text the formatting object at [[engine+0x9b]+0xae4] returns for (0x6a67e8, 0x6a84f4), copies it to a
// 0x100-byte stack buffer and hands every newline-terminated line to 0x56ef50. The remaining tail is appended to the edit buffer at this+0x1c9 when it still fits in 0x20
// characters (and the buffer is not empty-with-leading-space): its length goes to the array at this+0x3b2 (count +0x4b2), the object at +0x5ce (slot 0x284) and 0x56fb10 are
// told; otherwise the object at +0x5ca (slot 0x248, colour 0xff0000) is. Finally this+0x195 = 1, the object at +0x5da (slot 0xbc(0)) and +0x5e2 (slot 0x360 with the buffer)
// are told and this+0x198 is cleared.
static void THISCALL fn56fc90(u8 *self) {
  u8 buf[0x104];
  if (*(u8 *)(self + 0x198) == 0) return;
  void *fmt = *(void **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 0xae4);
  const u8 *src = (const u8 *)(*(v2_t **)fmt)[0]((fmt), 0x6a67e8, 0x6a84f4);
  {
    u8 *d = buf;
    const u8 *s = src;
    u8 c;
    do {
      c = *s++;
      *d++ = c;
    } while (c);
  }
  s32 len = slen(buf);
  u8 *p = buf;
  for (s32 i = 0; i < len; i++) {
    if (buf[i] == 0xa) {
      buf[i] = 0;
      ext_56ef50(self, p);
      p = buf + i + 1;
    }
  }
  u8 *edi = self + 0x1c9;
  s32 len1 = slen(edi);
  s32 len2 = slen(p);
  if (len1 < 0x20 - len2 && !(len1 == 0 && *p == 0x20)) {
    u8 *d = edi + len1;
    for (s32 k = 0; k <= len2; k++) d[k] = p[k];
    u32 cnt = F32(0x4b2);
    F32(0x3b2 + cnt * 4) = (u32)len2;
    void *o = *(void **)(self + 0x5ce);
    F32(0x4b2) = cnt + 1;
    (*(v1_t **)o)[0x284 / 4](o, (u32)edi);
    ext_56fb10(self);
  } else {
    void *o = *(void **)(self + 0x5ca);
    (*(v1_t **)o)[0x248 / 4](o, 0xff0000);
  }
  *(u8 *)(self + 0x195) = 1;
  void *o2 = *(void **)(self + 0x5da);
  (*(v1_t **)o2)[0xbc / 4](o2, 0);
  void *o3 = *(void **)(self + 0x5e2);
  (*(v1_t **)o3)[0x360 / 4](o3, (u32)edi);
  *(u8 *)(self + 0x198) = 0;
}
PCREG(56fc90, fn56fc90);
