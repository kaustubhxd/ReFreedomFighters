"""specs_s1901.py - unclaimed-66 batch 1901 (residue 5): ZFFSearchLightGroup::CopyEventDataBlock(DBREAD&), thiscall, one
argument (ret 4), void.

The DBREAD readers are STUBS (hooks): 0x4e5e80 returns a random float on ST0 (logged), 0x4e5e60 returns a random dword (logged).
They are not verified here. The object is 0x100 random bytes; the DBREAD object is 0x40 random bytes (only passed as ECX)."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _copy(c):
    self = _rnd(c, 0x100)
    db = _rnd(c, 0x40)

    def hf(e):
        v = c.rng.uniform(-100.0, 100.0)
        e.calllog.append(('DBREAD float (stub)', 0x4e5e80, e.reg('ecx'), ()))
        return (0, struct.unpack('<f', struct.pack('<f', v))[0])

    def hd(e):
        e.calllog.append(('DBREAD dword (stub)', 0x4e5e60, e.reg('ecx'), ()))
        return (c.rng.getrandbits(32), None)

    def mk(addr, impl):
        def h(e, r):
            eax, st0 = impl(e)
            e.ret(eax=eax, argbytes=0, st0=st0)
        c.emu.hook(addr, h)
    mk(0x4e5e80, hf)
    mk(0x4e5e60, hd)
    return [self, db]


S(0x5c6610, 'ZFFSearchLightGroup::CopyEventDataBlock (unknown)', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-66 batch 1901 (residue 5); DBREAD readers 0x4e5e80/0x4e5e60 STUBBED')
