"""specs_s7575.py - area 73 batch 75 (unmentioned band rows, GUESS names).
FUN_4fc090 (ret 4): copies six words (+0x54, +0x56, +0x58, +0x5a, +0x5c, +0x5e) from the argument object into this.
FUN_4f4f00 (ret 4, returns this): 0x4ee4e0(this) (hooked, zero arguments: the call site pushes none); flag bit 0: bit 2 gives
0x4690b0(this, 0xc3), else 0x45c510(this) (both cdecl, hooked and logged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_fc090(c):
    return [_rnd(c, 0x100), _rnd(c, 0x100)]


def _gen_4f00(c):
    e = c.emu

    def h_4ee4e0(em, r):
        em.calllog.append(('4ee4e0', 0, em.reg('ecx'), ()))
        em.ret(argbytes=0)

    def h_c(em, r):
        em.calllog.append(('45c510', 0, None, (em.arg32(0),)))
        em.ret(argbytes=0)

    def h_d(em, r):
        em.calllog.append(('4690b0', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(argbytes=0)
    e.hook(0x4ee4e0, h_4ee4e0)
    e.hook(0x45c510, h_c)
    e.hook(0x4690b0, h_d)
    return [_rnd(c, 0x100), c.rng.choice([0, 1, 5, c.rng.getrandbits(8)])]


S(0x4fc090, 'GUESS FUN_4fc090 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_fc090,
  note='area 73 batch 75; copies u16 +0x54..+0x5e from the argument to this')
S(0x4f4f00, 'GUESS FUN_4f4f00 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_4f00,
  note='area 73 batch 75; 0x4ee4e0(this); flag&1: flag&4 ? 0x4690b0(this,0xc3) : 0x45c510(this); returns this')
