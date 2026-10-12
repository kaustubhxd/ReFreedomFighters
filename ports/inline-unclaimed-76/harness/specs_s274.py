"""specs_s274.py - unclaimed area 76 (docs/20-unclaimed-76.md), residue-15 list: 0x5bd970, CCheckInsideByType::Load,
seven calls on the loader object (stack argument) through slots 0x40, 0x44, 0x48, 0x68 and 0x18."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _load(c):
    e = c.emu
    ld_vt = e.logging_vtable('ldr5bd', 0x1b, impl={}, argwords={0x18: 2, 0x40: 1, 0x44: 1, 0x48: 1, 0x68: 1})
    ld = _rnd(c, 0x40)
    e.w32(ld, ld_vt)
    self_ = _rnd(c, 0x100)
    return [self_, ld]


S(0x5bd970, 'load (GUESS)', 'thiscall', None, ret='al', gen=_load, note='batch274; ret 4; residue-15 list')
