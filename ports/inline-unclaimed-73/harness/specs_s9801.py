"""specs_s9801.py - residue 6 batch 98 (GUESS names).
0x4cdca0 (thiscall, ret void): If [this+0x1c] is non-zero, calls vcall [ecx][0] with arg 1,
then stores 0 at [this+0x1c].
"""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_4cdca0(c):
    # 0x4cdca0: thiscall() -> void - calls vcall at [ecx][0] if [this+0x1c] is non-zero
    e = c.emu

    # Create this object with pointer to object at +0x1c
    this_obj = _rnd(c, 0x30)

    # Decide: sometimes null, sometimes valid pointer
    if c.rng.getrandbits(1):
        # Null case - no vcall happens
        e.w32(this_obj + 0x1c, 0)
        obj = None
    else:
        # Valid pointer case
        def slot0_impl(em, a):
            em.calllog.append(('vt0', 0, em.reg('ecx'), (em.arg32(0),)))
            return (None, None)

        vtable = e.logging_vtable('4cdca0_vt', 4, impl={0: slot0_impl}, argwords={0: 1})
        obj = _rnd(c, 0x20)
        e.w32(obj, vtable)
        e.w32(this_obj + 0x1c, obj)

    return [this_obj]


S(0x4cdca0, 'GUESS FUN_004cdca0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4cdca0,
  note='residue 6 batch 98; conditional vcall at [ecx][0] if [this+0x1c] non-zero')
