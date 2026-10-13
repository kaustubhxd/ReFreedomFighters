"""specs_s9001.py - residue 6 batch 90 (GUESS names).
0x53a9e0 (thiscall, no ret): Dereferences this, calls vtable[4] on the dereferenced object,
then conditionally copies data based on comparison with global at 0x70039c.
"""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _gen_53a9e0(c):
    # 0x53a9e0: thiscall, no arguments - needs this with object pointer at +0
    e = c.emu

    # Create the object that *this points to (with vtable)
    inner_obj = _rnd(c, 0x40)

    # Create vtable for inner_obj with slot at +4
    result_val = c.rng.getrandbits(32)

    def slot4_impl(em, a):
        em.calllog.append(('vt4', 4, em.reg('ecx'), (em.arg32(0),)))
        return (result_val, None)

    vtable = e.logging_vtable('53a9e0_inner_vt', 8 // 4, impl={4: slot4_impl}, argwords={4: 1})
    e.w32(inner_obj, vtable)

    # Create the global object at 0x70039c
    global_obj = _rnd(c, 0x200)
    e.w32(0x70039c, global_obj)

    # Create this object that holds a pointer to inner_obj at offset 0
    this_obj = _rnd(c, 0x40)
    e.w32(this_obj, inner_obj)

    return [this_obj]


S(0x53a9e0, 'GUESS FUN_0053a9e0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_53a9e0,
  note='residue 6 batch 90; dereferences this, calls vtable[4] on that; conditionally copies from global 0x70039c')
