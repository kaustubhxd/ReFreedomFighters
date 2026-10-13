"""specs_s326.py - area 71 batch 326: 0x5edc60, thiscall, one stack argument, ret 4. If the dword at this+0xdf differs from the
argument, store it and set the byte at +0xa6. Half the cases pass the stored value (no change)."""
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    o = E.zero_obj(c, 0x100)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x100)))
    v = r.getrandbits(32)
    if r.random() < 0.5:
        c.emu.w32(o + 0xdf, v)
    c.emu.mu.ctl_flush_tb()
    return [o, v]


S(0x5edc60, 'set +0xdf if changed, flag +0xa6 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='area 71 batch 326 (leaf, residue 10)')
