"""specs_s9901.py - residue 6 batch 99 (GUESS names).
0x4f4760 (thiscall, ret 4): Stores argument at [this+0xb0], conditional vcall if [this+0xac]==0.
"""
from pilot import S

def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a

def _gen_4f4760(c):
    e = c.emu

    # Create vtable with slot at +0x294
    def slot294_impl(em, a):
        em.calllog.append(('vt294', 0x294, em.reg('ecx'), ()))
        return (None, None)

    vtable = e.logging_vtable('4f4760_vt', 170, impl={0x294: slot294_impl}, argwords={0x294: 0})
    this_obj = _rnd(c, 0x300)
    e.w32(this_obj, vtable)

    # Random condition: sometimes vcall happens (0xac is zero), sometimes not
    if c.rng.getrandbits(1):
        e.w32(this_obj + 0xac, 0)  # vcall will happen
    else:
        e.w32(this_obj + 0xac, 1)  # vcall won't happen

    arg = c.rng.getrandbits(32)
    return [this_obj, arg]

S(0x4f4760, 'GUESS FUN_004f4760 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4f4760,
  note='residue 6 batch 99; stores arg at [this+0xb0], conditional vcall if [this+0xac]==0')
