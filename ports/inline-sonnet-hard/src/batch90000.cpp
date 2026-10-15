// batch 90000: 0x44b740 ZSoundObject::~ZSoundObject (SEH frame; body forwards its stack arg to a sound-system vtable slot)
#include "ff.h"

struct VObj { void **vt; };

static void dtor_44b740(u32 arg) {
  VObj *snd = *(VObj **)(*(u32 *)0x70039c + 0x1a9f);
  if (snd)
    ((void(THISCALL *)(VObj *, u32))snd->vt[0x118 / 4])(snd, arg);
}

PCREG(44b740, dtor_44b740);
