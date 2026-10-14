// u18_16.cpp - core-todo residue 17 (unclaimed-18 thread): ZActor::OnCameraEnter (0x479750).
#include "ff.h"

// 0x479750, ZActor::OnCameraEnter() (GC map high). thiscall, void. Calls slot 0x32c(1); when the field at +0x65c is set:
// slot 0x57c fills two vectors (a, b), slot 0x620(b, 1, 1) is called, and the object at +0x6c is asked by slots 0x34 and
// (if that is false) 0x38; when either says yes, b.y += 20.0. Then slot 0x578(a, b) and b.y is stored at +0x706 and +0x70a,
// and -1.0 at +0x70e. The vectors are uninitialised in the exe; the callees write them, and so do the fakes here.
static void THISCALL actorOnCameraEnter(u8 *self) {
  vcall<void>(self, 0x32c, 1u);
  if (*(u32 *)(self + 0x65c) == 0)
    return;
  float a[3] = {0.0f, 0.0f, 0.0f};
  float b[3] = {0.0f, 0.0f, 0.0f};
  vcall<void>(self, 0x57c, (void *)a, (void *)b);
  vcall<void>(self, 0x620, (void *)b, 1u, 1u);
  bool cond = vcall<u8>(*(void **)(self + 0x6c), 0x34) != 0;
  if (!cond)
    cond = vcall<u8>(*(void **)(self + 0x6c), 0x38) != 0;
  if (cond)
    b[1] = b[1] + 20.0f;
  vcall<void>(self, 0x578, (void *)a, (void *)b);
  *(float *)(self + 0x706) = b[1];
  *(float *)(self + 0x70a) = b[1];
  *(u32 *)(self + 0x70e) = 0xbf800000u;
}
PCREG(479750, actorOnCameraEnter);
