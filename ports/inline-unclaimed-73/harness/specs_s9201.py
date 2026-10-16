"""specs_s9201.py - residue 6 batch 92 (GUESS names).
0x4cef60 (thiscall, ret 4): Calls vcall at [this][0x78], compares with [this+0x28],
stores 0 if equal, then calls ext_4cee80(this, a).
"""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_4cef60(c):
    # 0x4cef60: thiscall(a) - needs this with vtable at [0] and value at +0x28
    e = c.emu

    # Create a properly sized vtable (at least 0x80 bytes for the 0x78 slot)
    vcall_result = c.rng.getrandbits(32)

    def slot78_impl(em, a):
        em.calllog.append(('vt78', 0x78, em.reg('ecx'), ()))
        return (vcall_result, None)

    # Create vtable with slot at +0x78 (0x78/4 = 30)
    vtable = e.logging_vtable('4cef60_vt', 32, impl={0x78: slot78_impl}, argwords={0x78: 0})

    # Create this object with valid vtable pointer and value at +0x28
    this_obj = _rnd(c, 0x40)
    e.w32(this_obj, vtable)

    # Store value at +0x28 - sometimes match vcall_result, sometimes not
    if c.rng.getrandbits(1):
        # Match case: stored value == vcall_result -> should store 0
        stored_initial = vcall_result
    else:
        # Non-match case: stored value != vcall_result -> should not change
        stored_initial = vcall_result ^ 0xffffffff
    e.w32(this_obj + 0x28, stored_initial)

    # Create arg value
    arg = c.rng.getrandbits(32)

    # Hook ext_4cee80 with proper signature
    def hook_4cee80(em, r):
        em.calllog.append(('4cee80', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(argbytes=4)

    e.hook(0x4cee80, hook_4cee80)

    return [this_obj, arg]


S(0x4cef60, 'GUESS FUN_004cef60 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4cef60,
  note='residue 6 batch 92; calls vcall at [this][0x78], compares with [this+0x28], calls ext_4cee80')
