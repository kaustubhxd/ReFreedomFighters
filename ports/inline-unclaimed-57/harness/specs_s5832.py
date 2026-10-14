"""specs_s5832.py - residue 9, 0x49eed0 (CMsgForward::CopyEventDataBlock(DBREAD&), gc name map), thiscall, one stack argument, ret 4. The readers 0x4e5e60 and
0x4e5e40 (thiscall, ecx = the reader) are hooked: they return per-case values (dword and word). The sub-object (engine +0x9b) has slot +0x58 (one arg, logged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d9eed0(c):
    e = c.emu
    rnd = c.rng
    rA = rnd.getrandbits(32)
    rB = rnd.getrandbits(32)

    def hA(em, r):
        em.calllog.append(('rdA', 'db' if em.reg('ecx') == db_obj else 'other', None, ()))
        em.ret(eax=rA, argbytes=0)

    def hB(em, r):
        em.calllog.append(('rdB', 'db' if em.reg('ecx') == db_obj else 'other', None, ()))
        em.ret(eax=rB, argbytes=0)

    def h58(em, r):
        em.calllog.append(('s58', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    e.hook(0x4e5e60, hA)
    e.hook(0x4e5e40, hB)
    vt_sub = e.fake_vtable('d9eed0_sub', 200, {0x58: h58})
    sub = _rnd(c, 0x100)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    db_obj = _rnd(c, 0x40)
    self_obj = _rnd(c, 0x100)
    return [self_obj, db_obj]


S(0x49eed0, 'CMsgForward::CopyEventDataBlock (gc map) thiscall', 'thiscall', None, ret=None, gen=_d9eed0,
  note='residue 9; readers 0x4e5e60 and 0x4e5e40 hooked (per-case dword and word); sub slot +0x58 fake')
