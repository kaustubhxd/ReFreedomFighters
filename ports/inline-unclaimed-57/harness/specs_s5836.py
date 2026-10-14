"""specs_s5836.py - residue 9, 0x4fcfd0 (CMAINCAMERACONTROL::Load2(), gc name map), thiscall, no args. The sub-object (engine +0x9b) has slot +0x58 (one arg, returns
object O) and slot +0x4c (two args, returns a per-case dword). O has slot +0x128 (two args, logged). The tail target 0x4fdac0 is a logging stub (plain ret) that
the original tail-jumps to; the word at this+0x80 is random."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d5fd0(c):
    e = c.emu
    rnd = c.rng
    r4c = rnd.getrandbits(32)

    def h58(em, r):
        em.calllog.append(('s58', 0, None, (em.arg32(0),)))
        em.ret(eax=O_obj, argbytes=4)

    def h4c(em, r):
        em.calllog.append(('s4c', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=r4c, argbytes=8)

    def h128(em, r):
        em.calllog.append(('O128', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def htail(em, r):
        em.calllog.append(('tail4fdac0', 'self' if em.reg('ecx') == self_obj else 'other', None, ()))
        em.ret(eax=0, argbytes=0)

    e.hook(0x4fdac0, htail)
    vt_sub = e.fake_vtable('d5fd0_sub', 200, {0x58: h58, 0x4c: h4c})
    vt_O = e.fake_vtable('d5fd0_O', 300, {0x128: h128})
    O_obj = _rnd(c, 0x40)
    e.w32(O_obj, vt_O)
    sub = _rnd(c, 0x100)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x100)
    e.wbytes(self_obj + 0x80, rnd.getrandbits(16).to_bytes(2, 'little'))
    e.w32(self_obj + 0x44, rnd.getrandbits(32))
    e.w32(self_obj + 0x78, rnd.getrandbits(32))
    return [self_obj]


S(0x4fcfd0, 'CMAINCAMERACONTROL::Load2 (gc map) thiscall', 'thiscall', None, ret=None, gen=_d5fd0,
  note='residue 9; tail target 0x4fdac0 hooked (logs); sub slots +0x58, +0x4c and O slot +0x128 fake')
