"""specs_s1904.py - unclaimed-66 batch 1904 (residue 5): CHitpointControl::CopyEventDataBlock(DBREAD&), thiscall, one
argument (ret 4), void.

The DBREAD readers are STUBS (hooks, logged, unverified): 0x4e5e80 returns a random float on ST0, 0x4e5e60 a random dword,
0x4e5e40 a random word in EAX, 0x4e5ef0 a random byte in EAX. The DBREAD object's first dword points to a tag byte; the tag
is chosen from 0xff, 2, 8, 0x42 and random values, so each gated branch runs and is skipped."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _copy(c):
    self = _rnd(c, 0x100)
    tagbuf = c.emu.alloc(4, 4)
    tag = c.rng.choice([0xff, 0x02, 0x08, 0x42, 0x0a, c.rng.getrandbits(8)])
    c.emu.wbytes(tagbuf, bytes([tag, 0, 0, 0]))
    db = c.emu.alloc(0x40, 4)
    c.emu.w32(db, tagbuf)

    def mk(addr, name, impl):
        def h(e, r):
            e.calllog.append((name, addr, e.reg('ecx'), ()))
            eax, st0 = impl(e)
            e.ret(eax=eax, argbytes=0, st0=st0)
        c.emu.hook(addr, h)

    mk(0x4e5e80, 'DBREAD float (stub)', lambda e: (0, struct.unpack('<f', struct.pack('<f', c.rng.uniform(-50, 50)))[0]))
    mk(0x4e5e60, 'DBREAD dword (stub)', lambda e: (c.rng.getrandbits(32), None))
    mk(0x4e5e40, 'DBREAD word (stub)', lambda e: (c.rng.getrandbits(16), None))
    mk(0x4e5ef0, 'DBREAD byte (stub)', lambda e: (c.rng.getrandbits(8), None))
    return [self, db]


S(0x5827d0, 'CHitpointControl::CopyEventDataBlock (unknown)', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-66 batch 1904 (residue 5); DBREAD readers 0x4e5e80/0x4e5e60/0x4e5e40/0x4e5ef0 STUBBED; tag-gated reads')
