"""specs_s8942.py - residue 6 batch 89 (GUESS names).
0x451ce0 (thiscall, ret 4): Calls thunk 0x45d5b0 which tail-jumps to vtable[0x48]; then calls vtable[0xb4](1).
0x6038e0 (cdecl, plain ret): Calls 0x634d10(0xc8, 0, 0x7246a0); stores 0 at global 0x724698.
0x4ea260 (thiscall, ret 4): Gets object at global[0x70039c]+0x9b; calls vtable[0x54] with [this+4]; returns result or arg.
"""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _gen_451ce0(c):
    # 0x451ce0: thiscall(a) - needs this with vtable slots at +0x48 and +0xb4
    e = c.emu

    # Create this object with vtable
    this_obj = _rnd(c, 0x40)

    # Create vtable with logging slots
    def slot48_impl(em, a):
        em.calllog.append(('vt48', 0x48, em.reg('ecx'), (em.arg32(0),)))
        return (0, None)

    def slotb4_impl(em, a):
        em.calllog.append(('vtb4', 0xb4, em.reg('ecx'), (em.arg32(0),)))
        return (0, None)

    vtable = e.logging_vtable('451ce0_vt', 0xb8 // 4, impl={0x48: slot48_impl, 0xb4: slotb4_impl},
                               argwords={0x48: 1, 0xb4: 1})
    e.w32(this_obj, vtable)

    return [this_obj, c.rng.getrandbits(32)]


def _gen_6038e0(c):
    # 0x6038e0: cdecl, no arguments
    e = c.emu

    def hook_634d10(em, r):
        em.calllog.append(('634d10', 0, None, (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=0xc)

    e.hook(0x634d10, hook_634d10)

    return []


def _gen_4ea260(c):
    # 0x4ea260: thiscall(a) - needs global at 0x70039c and object at global+0x9b
    e = c.emu

    # Create global object
    global_obj = _rnd(c, 0x100)

    # Create object at global+0x9b
    obj_at_9b = _rnd(c, 0x60)

    # Create vtable for obj_at_9b with slot at +0x54
    r_val = c.rng.getrandbits(32)

    def slot54_impl(em, a):
        em.calllog.append(('vt54', 0x54, em.reg('ecx'), (em.arg32(0),)))
        return (r_val, None)

    vtable = e.logging_vtable('4ea260_vt', 0x60 // 4, impl={0x54: slot54_impl}, argwords={0x54: 1})
    e.w32(obj_at_9b, vtable)

    # Store pointers
    e.w32(global_obj, 0)  # first dword
    e.w32(global_obj + 0x9b, obj_at_9b)  # global+0x9b points to our object

    # Set up global at 0x70039c
    e.w32(0x70039c, global_obj)

    # Create this object with [this+4] containing a random value
    this_obj = _rnd(c, 0x20)
    e.w32(this_obj + 4, c.rng.getrandbits(32))

    return [this_obj, c.rng.getrandbits(32)]


S(0x451ce0, 'GUESS FUN_00451ce0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_451ce0,
  note='residue 6 batch 89; calls thunk 0x45d5b0 -> vtable[0x48]; then calls vtable[0xb4](1)')
S(0x6038e0, 'GUESS FUN_006038e0 (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen_6038e0,
  note='residue 6 batch 89; calls 0x634d10(0xc8, 0, 0x7246a0); stores 0 at 0x724698')
S(0x4ea260, 'GUESS FUN_004ea260 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_4ea260,
  note='residue 6 batch 89; gets global[0x70039c]+0x9b; calls vtable[0x54]; returns result or arg')
