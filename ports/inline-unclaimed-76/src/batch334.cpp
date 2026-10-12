// batch334.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): two members (GUESS).
// 0x602260 (thiscall, one argument n, ret 4): buf = 0x41e290(n) (exe allocator, cdecl); [this+4] = [this+8] = buf; [this+0xc] = buf + n - 1;
//   [this+0x10] = n; byte [this+0x14] = 0.
// 0x610170 (stdcall, one byte argument, ret 4): v = (u8)arg; if [0x72493c] != v: [0x72493c] = v; call [0x724a00].vtbl[0xc8] with ECX = the vtable
//   pointer and three stack words (obj, 0xe, v) (the callee pops them). Then [0x724944] = (arg == 0).
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_41e290(u32 size);
typedef u32(THISCALL * slot_c8_t)(u32 vt, u32 obj, u32 e, u32 v);

static void THISCALL setRange_602260(u8 *self, u32 n) {
    u32 buf = ext_41e290(n);
    *(u32 *)(self + 4u) = buf;
    *(u32 *)(self + 8u) = buf;
    *(u32 *)(self + 0xcu) = buf + n - 1u;
    *(u32 *)(self + 0x10u) = n;
    *(u8 *)(self + 0x14u) = 0u;
}
PCREG(602260, setRange_602260);

static void STDCALL flag_610170(u32 argWord) {
    u32 v = (u8)argWord;
    if (G(u32, 0x72493cu) != v) {
        G(u32, 0x72493cu) = v;
        u32 obj = G(u32, 0x724a00u);
        u32 vt = *(u32 *)obj;
        ((slot_c8_t)*(u32 *)(vt + 0xc8u))(vt, obj, 0xeu, v);
    }
    G(u32, 0x724944u) = (u8)argWord == 0 ? 1u : 0u;
}
PCREG(610170, flag_610170);
