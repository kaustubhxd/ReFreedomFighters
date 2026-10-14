"""specs_s5837.py - residue 9, 0x4fc0d0 (CMAINCAMERACONTROL::CopyEventDataBlock(DBREAD&), gc name map), thiscall, one stack argument, ret 4. The readers 0x4e5e60
(dword) and 0x4e5e40 (word) are hooked: they return per-case values and log whether ecx is the argument object."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d0d0(c):
    e = c.emu
    rnd = c.rng
    seqA = [rnd.getrandbits(32) for _ in range(2)]
    seqB = [rnd.getrandbits(32) for _ in range(4)]
    ia = [0]
    ib = [0]

    def hA(em, r):
        k = ia[0]
        ia[0] += 1
        em.calllog.append(('rdA', k, 'db' if em.reg('ecx') == db_obj else 'other', ()))
        em.ret(eax=seqA[k], argbytes=0)

    def hB(em, r):
        k = ib[0]
        ib[0] += 1
        em.calllog.append(('rdB', k, 'db' if em.reg('ecx') == db_obj else 'other', ()))
        em.ret(eax=seqB[k], argbytes=0)

    e.hook(0x4e5e60, hA)
    e.hook(0x4e5e40, hB)
    db_obj = _rnd(c, 0x40)
    self_obj = _rnd(c, 0x100)
    return [self_obj, db_obj]


S(0x4fc0d0, 'CMAINCAMERACONTROL::CopyEventDataBlock (gc map) thiscall', 'thiscall', None, ret=None, gen=_d0d0,
  note='residue 9; readers 0x4e5e60 and 0x4e5e40 hooked (per-case dword and words)')
