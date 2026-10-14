"""specs_s947.py - area 56 residue 15, claim A6: CCheckVisible::Save(ZSaveGame*) (0x4ab870).

The object is 0x16000 random bytes (the fields reach +0x15e7c). The save object is a fake object with GUESS recording
handlers (unverified callees): slot 0x10 logs its pointer (heap) and its count; slots 0x3c and 0x4c log their values
(the float is logged as its bits). The save handlers write nothing. The return is the bool in al."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu

    def h10(e2, r):
        e2.calllog.append(('Sv10', e2.arg32(0), e2.arg32(1)))
        e2.ret(argbytes=8)

    def h3c(e2, r):
        e2.calllog.append(('Sv3c', e2.arg32(0)))
        e2.ret(argbytes=4)

    def h4c(e2, r):
        e2.calllog.append(('Sv4c', e2.arg32(0)))
        e2.ret(argbytes=4)

    sv = e.fake_object('checkvisible_save', 0x40, slots={0x10: h10, 0x3c: h3c, 0x4c: h4c})
    this = _rnd(c, 0x16000)
    return [this, sv]


S(0x4ab870, 'CCheckVisible::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-56 A6; save slots 0x10/0x3c/0x4c are GUESS recording stubs (unverified)')
