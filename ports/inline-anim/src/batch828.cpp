// batch828.cpp - animation layer thread, batch 828: bone-anim callback <-> id map. The only callback in this build is
// the exe function at 0x465710; it is the id 1 (BoneAnimIdToCallBack) and any other value maps to null.
#include "ff.h"

static const u32 kCallBack = 0x465710;   // the one bone-anim callback (ZIKLNKOBJ::... in the exe; not ported here)

// ZIKLNKOBJ::BoneAnimCallBackToId(callback) [medium]: 1 when the pointer is the known callback, else 0.
static u32 THISCALL BoneAnimCallBackToId(void *, u32 fn) { return fn == kCallBack ? 1u : 0u; }
PCREG(465850, BoneAnimCallBackToId);

// ZIKLNKOBJ::BoneAnimIdToCallBack(id) [medium]: the callback for id 1, else null.
static u32 THISCALL BoneAnimIdToCallBack(void *, u32 id) { return id == 1 ? kCallBack : 0u; }
PCREG(465870, BoneAnimIdToCallBack);
