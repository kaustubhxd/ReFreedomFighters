// batch339.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): two thiscall members with two stack arguments (ret 8, GUESS).
// 0x604340(A, b): 0x603c80(this, A, b) (exe, ECX = this, two stack words, callee pops); A.vtbl[0x50](A, &b) (one argument, the address of
//   the b slot); r = this.vtbl[0x50](this, b); returns r.
// 0x604510(A, b): 0x604030(this, A, b) (exe, same convention); v = this.vtbl[0x54](this); return A.vtbl[0x44](A, v) (the call's eax).
#include "ff.h"

extern "C" u32 THISCALL ext_603c80(u8 *self, u32 a, u32 b);
extern "C" u32 THISCALL ext_604030(u8 *self, u32 a, u32 b);
typedef u32(THISCALL * slot_u32_t)(u32 self, u32 arg);
typedef u32(THISCALL * slot_none_t)(u32 self);

static u32 THISCALL link_604340(u8 *self, u32 a, u32 b) {
    ext_603c80(self, a, b);
    ((slot_u32_t)*(u32 *)(*(u32 *)a + 0x50u))(a, (u32)&b);
    return ((slot_u32_t)*(u32 *)(*(u32 *)self + 0x50u))((u32)self, b);
}
PCREG(604340, link_604340);

static u32 THISCALL link_604510(u8 *self, u32 a, u32 b) {
    ext_604030(self, a, b);
    u32 v = ((slot_none_t)*(u32 *)(*(u32 *)self + 0x54u))((u32)self);
    return ((slot_u32_t)*(u32 *)(*(u32 *)a + 0x44u))(a, v);
}
PCREG(604510, link_604510);
