"""specs_s1977.py - slice-5 batch 110 (GUESS name): 0x662dd0

THISCALL(this, v), ret 4: calls 0x4e0830 (FASTCALL ECX=v, EDX=this+4, returns float),
compares with 0x67a284, if greater copies 3 dwords from v to this+4 and calls 0x662cf0(this).

0x4e0830 is a GUESS stub hooked by address: it takes v and this+4, returns a random float.
0x662cf0 is a GUESS stub hooked by address: it takes this, no return value."""
from pilot import S


def _gen(c):
    # Set the threshold at 0x67a284
    threshold = c.rng.uniform(-100.0, 100.0)
    c.emu.wf32(0x67a284, threshold)

    # Random return value from 0x4e0830: 50% above threshold, 50% below
    above_threshold = c.rng.random() < 0.5
    if above_threshold:
        return_val = threshold + c.rng.uniform(0.1, 100.0)
    else:
        return_val = threshold - c.rng.uniform(0.1, 100.0)

    # Hook 0x4e0830: takes ECX=v, EDX=this+4, returns float on ST0
    def h4e0830(e, r):
        v = e.reg('ecx')
        this_plus_4 = e.reg('edx')
        e.calllog.append(('0x4e0830 (GUESS stub)', 0x4e0830, v, (this_plus_4,)))
        e.ret(eax=0, st0=return_val, argbytes=0)
    c.emu.hook(0x4e0830, h4e0830)

    # Hook 0x662cf0: takes ECX=this, no arguments
    def h662cf0(e, r):
        this = e.reg('ecx')
        e.calllog.append(('0x662cf0 (GUESS stub)', 0x662cf0, this, ()))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x662cf0, h662cf0)

    # Create random objects for v and this
    v = c.emu.alloc(0x40, 4)
    c.emu.wbytes(v, bytes(c.rng.getrandbits(8) for _ in range(12)))  # 3 dwords for copying

    this = c.emu.alloc(0x40, 4)
    c.emu.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x40)))

    return [this, v]


S(0x662dd0, 'GUESS FUN_00662dd0 (float compare and copy)', 'thiscall', None, ret=None,
  gen=_gen, note='slice-5 batch 1977 (110); 0x4e0830 and 0x662cf0 GUESS stubs')
