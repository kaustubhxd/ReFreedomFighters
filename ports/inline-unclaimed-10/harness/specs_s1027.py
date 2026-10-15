"""specs_s1027.py - unclaimed-10, batch 23 (residue-10 list): ZParamAnim::CopyEventDataBlock (0x4a24a0). Thiscall, one argument
(the DBREAD, a heap object). Readers 0x4e5e60 (A), 0x4e5e80 (B, float in st0), 0x4e5e40 (C) are hooked: each returns a value that
depends on a per-reader counter stored in the DBREAD object (so repeated calls differ, and call order matters), and reader A/C
also fold in the base value. The DBREAD's first dword points to a buffer whose first byte is chosen from the branch cases
(0xff, 0x02, 0x0a, 0x42, random), and is zero in about one case in six (the early stop)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ctr(em, off):
    p = em.reg('ecx')
    n = em.r32(p + off)
    em.w32(p + off, (n + 1) & 0xffffffff)
    return n


def _pa(c):
    e = c.emu
    base80 = c.rng.choice([0.0, 1.0, -2.5, 0.75, 8.0])
    base60 = c.rng.getrandbits(32)
    base40 = c.rng.getrandbits(32)
    e.hook(0x4e5e60, lambda em, r: em.ret(eax=(base60 + _ctr(em, 0x34) * 0x9e3779b9) & 0xffffffff, argbytes=0))
    e.hook(0x4e5e40, lambda em, r: em.ret(eax=(base40 ^ (_ctr(em, 0x38) * 3)) & 0xffffffff, argbytes=0))
    e.hook(0x4e5e80, lambda em, r: em.ret(st0=base80 + _ctr(em, 0x30) * 0.5, argbytes=0))
    db = _rnd(c, 0x40)
    e.w32(db + 0x30, 0)
    e.w32(db + 0x34, 0)
    e.w32(db + 0x38, 0)
    if c.rng.random() < 0.16:
        e.w32(db, 0)
    else:
        buf = _rnd(c, 0x10)
        b0 = c.rng.choice([0xff, 0x02, 0x0a, 0x42, c.rng.getrandbits(8)])
        e.wbytes(buf, bytes([b0]) + bytes(c.rng.getrandbits(8) for _ in range(15)))
        e.w32(db, buf)
    return [_rnd(c, 0x800), db]


S(0x4a24a0, 'ZParamAnim::CopyEventDataBlock (unknown) thiscall', 'thiscall', None, ret=None, gen=_pa,
  note='unclaimed-10 batch 23; readers 0x4e5e60/0x4e5e80/0x4e5e40 hooked with counters in the DBREAD')
