"""specs_s81.py - unclaimed-68 batch 81 (slice 7). Destructor pattern.
Exe callees: CRT delete at 0x634273 (hooked), tail jump to 0x6363a0 (hooked).
"""
from pilot import S
from engine_stubs import zero_obj


def _g636430(c):
    # 0x636430: destructor. Thiscall, no args, ret 0.
    # Conditionally calls CRT delete twice, sets vtables, tail jumps to exe.
    self_obj = zero_obj(c, 0x3b)  # Need at least +0x3a for the condition check

    # Randomly set the condition flags to exercise both paths
    c.emu.w8(self_obj + 0x3a, c.rng.choice([0, 1]))
    c.emu.w8(self_obj + 0x31, c.rng.choice([0, 1]))

    # Set up pointers that will be passed to CRT delete (if conditions are true)
    if c.rng.random() < 0.5:
        ptr1 = zero_obj(c, 16)
        c.emu.w32(self_obj + 0x36, ptr1)
    else:
        c.emu.w32(self_obj + 0x36, 0)

    if c.rng.random() < 0.5:
        ptr2 = zero_obj(c, 16)
        c.emu.w32(self_obj + 0x2d, ptr2)
    else:
        c.emu.w32(self_obj + 0x2d, 0)

    # Hook CRT delete at 0x634273
    def crt_delete_hook(em, r):
        ptr = em.arg32(0)
        size = em.arg32(1)
        em.calllog.append(('crt_delete_636430', ptr, size))
        return (None, None)

    c.emu.hook(0x634273, crt_delete_hook)

    # Hook tail jump target 0x6363a0
    def ext_6363a0_hook(em, r):
        em.calllog.append(('ext_6363a0_636430', em.reg('ecx')))
        return (None, None)

    c.emu.hook(0x6363a0, ext_6363a0_hook)

    return [self_obj]


S(0x636430, 'FUN_636430 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_g636430,
  note='unclaimed-68 batch 81: destructor with conditional CRT deletes and tail jump')
