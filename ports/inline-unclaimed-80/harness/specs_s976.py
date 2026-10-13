"""specs_s976.py - unclaimed-80 residue-19 batch 54 (docs/20-unclaimed-80.md), see src/batch976.cpp. The callee 0x4e5e80 (claimed in many
docs) is hooked by address with a recording thiscall stub that returns a per-case finite float in st0 (the stub logs ecx). The argument and
self are 0x60-byte random blocks."""
import struct
from pilot import S, F


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    vals = [c.rng.uniform(-100.0, 100.0) for _ in range(3)]
    idx = {'k': 0}

    def h(em, r):
        c.emu.calllog.append(('4e5e80', None, em.reg('ecx'), ()))
        v = vals[idx['k'] % 3]
        idx['k'] += 1
        em.ret(eax=0, argbytes=0, st0=F(v))

    c.emu.hook(0x4e5e80, h)
    return [_rnd(c, 0x60), _rnd(c, 0x60)]


S(0x4bce30, 'three float reads into fields (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-80 residue-19; callee 0x4e5e80 hooked by address (claimed elsewhere), float in st0; stored at +0x48, +0x4c, +0x50')
