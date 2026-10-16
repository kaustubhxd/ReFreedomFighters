// batch347.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x602d30 (cdecl, no arguments, plain ret; GUESS). If [0x724694] != 0
// it returns that value. Else: obj = logger.vtbl[0x20](logger, 0x6b98c8, 0x27) (logger = [0x700390], thiscall, two stack words); then
// obj.vtbl[0x2c](obj, 0x69c6b0, 0x6b98fc) (cdecl, three arguments); then the callback [0x7003b0] is tail-called with no arguments (the
// exe int3s when it is null; the fixture always sets it). The tail call is a plain call here, since the callee takes no arguments.
#include "ff.h"

typedef u32(THISCALL * logslot20_t)(u32 lg, u32 a, u32 b);
typedef void(__attribute__((cdecl)) * reportslot2c_t)(u32 obj, u32 a, u32 b);
typedef u32(__attribute__((cdecl)) * callback_t)(void);

static u32 __attribute__((cdecl)) debugThunk_602d30(void) {
    u32 flag = G(u32, 0x724694u);
    if (flag != 0u) return flag;
    u32 lg = G(u32, 0x700390u);
    u32 obj = ((logslot20_t)*(u32 *)(*(u32 *)lg + 0x20u))(lg, 0x6b98c8u, 0x27u);
    ((reportslot2c_t)*(u32 *)(*(u32 *)obj + 0x2cu))(obj, 0x69c6b0u, 0x6b98fcu);
    return ((callback_t)G(u32, 0x7003b0u))();
}
PCREG(602d30, debugThunk_602d30);
