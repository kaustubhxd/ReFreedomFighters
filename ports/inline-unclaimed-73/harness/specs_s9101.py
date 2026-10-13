"""specs_s9101.py - residue 6 batch 91 (GUESS names).
0x5228e0 (thiscall, ret 4): Loads obj from [this+0x1c], calls vcall at [obj][0x398],
then calls 0x5003d0([a+8], vcall_result, 0) and 0x5002f0(eax).
"""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _gen_5228e0(c):
    # 0x5228e0: thiscall(a) - needs this with object at +0x1c, and arg with value at +8
    e = c.emu

    # Create object with vtable
    obj_at_1c = _rnd(c, 0x40)

    # Create vtable with slot at +0x398
    vcall_result = c.rng.getrandbits(32)

    def slot398_impl(em, a):
        em.calllog.append(('vt398', 0x398, em.reg('ecx'), ()))
        return (vcall_result, None)

    vtable = e.logging_vtable('5228e0_vt', 0x400 // 4, impl={0x398: slot398_impl}, argwords={0x398: 0})
    e.w32(obj_at_1c, vtable)

    # Create this object with object pointer at +0x1c
    this_obj = _rnd(c, 0x40)
    e.w32(this_obj + 0x1c, obj_at_1c)

    # Create arg object with value at +8
    arg_obj = _rnd(c, 0x40)
    arg_val = c.rng.getrandbits(32)
    e.w32(arg_obj + 8, arg_val)

    # Hook 0x5003d0
    result_5003d0 = c.rng.getrandbits(32)

    def hook_5003d0(em, r):
        em.calllog.append(('5003d0', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=result_5003d0, argbytes=8)

    e.hook(0x5003d0, hook_5003d0)

    # Hook 0x5002f0
    def hook_5002f0(em, r):
        em.calllog.append(('5002f0', 0, em.reg('ecx'), ()))
        em.ret(argbytes=0)

    e.hook(0x5002f0, hook_5002f0)

    return [this_obj, arg_obj]


S(0x5228e0, 'GUESS FUN_005228e0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_5228e0,
  note='residue 6 batch 91; loads obj from [this+0x1c], calls vcall at [obj][0x398], then 0x5003d0 and 0x5002f0')
