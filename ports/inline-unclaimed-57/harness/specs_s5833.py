"""specs_s5833.py - residue 9, 0x5b3e10 (ZActionControlMap::Load2(), gc name map), thiscall, no args. The object O at this+0x5f has slot +0x100 (one arg, returns a
per-case dword) and the dwords +0x85a (0 in about half the cases) and +0x852 (random). The helper 0x591ae0 (thiscall, ecx = O) is hooked (returns a per-case dword).
The object's own slot +0xc (the original tail-jumps there) is a logging stub that writes nothing."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d3e10(c):
    e = c.emu
    rnd = c.rng
    r100 = rnd.getrandbits(32)
    r591 = rnd.getrandbits(32)

    def h100(em, r):
        em.calllog.append(('O100', 0, None, (em.arg32(0),)))
        em.ret(eax=r100, argbytes=4)

    def h591(em, r):
        em.calllog.append(('591', 'O' if em.reg('ecx') == O_obj else 'other', None, ()))
        em.ret(eax=r591, argbytes=0)

    def hc(em, r):
        em.calllog.append(('self_c', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    e.hook(0x591ae0, h591)
    vt_O = e.fake_vtable('d3e10_O', 300, {0x100: h100})
    vt_self = e.fake_vtable('d3e10_self', 200, {0xc: hc})
    O_obj = _rnd(c, 0x900)
    e.w32(O_obj, vt_O)
    e.w32(O_obj + 0x85a, 0 if rnd.random() < 0.5 else rnd.getrandbits(32))
    e.w32(O_obj + 0x852, rnd.getrandbits(32))
    self_obj = _rnd(c, 0x100)
    e.w32(self_obj, vt_self)
    e.w32(self_obj + 0x5f, O_obj)
    return [self_obj]


S(0x5b3e10, 'ZActionControlMap::Load2 (gc map) thiscall', 'thiscall', None, ret=None, gen=_d3e10,
  note='residue 9; helper 0x591ae0 hooked; own vt slot +0xc logs (the original tail-jumps there); O slot +0x100 fake')
