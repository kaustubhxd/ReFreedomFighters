"""specs_s1023.py - unclaimed-04 batch 24 (docs/20-unclaimed-04.md): ZTarget-like tail-call wrapper 0x45ba30 (thiscall, no
arguments). It calls vt[0x110] with (0x10, 0) (recording stub), then 0x43e0f0 (original code, thiscall, no arguments),
then tail-jumps through vt[0x214] with ecx = this. The slot 0x214 function is a recording stub with no stack arguments
(the verified form; see the claim in docs/20-unclaimed-04.md). The object is 0x100 random bytes, and its vtable covers
slots up to 0x214."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _tail(c):
    vt_ret = c.rng.getrandbits(32)

    def h110(em, r):
        em.calllog.append(('vt.110', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=vt_ret, argbytes=8)

    def h214(em, r):
        em.calllog.append(('vt.214', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    vt = c.emu.fake_vtable('tail wrapper', 0x214 // 4 + 1, {0x110: h110, 0x214: h214})
    o = _rnd(c, 0x100)
    c.emu.w32(o, vt)
    # 0x43e0f0 reads the owner at +8 and its flag dword at +0x3c; bit 0x40000000 set means it calls 0x4dc630
    owner = _rnd(c, 0x100)
    flags = c.rng.getrandbits(32)
    if c.rng.random() < 0.5:
        flags &= ~0x40000000 & 0xffffffff
    else:
        flags |= 0x40000000
    c.emu.w32(owner + 0x3c, flags)
    c.emu.w32(o + 8, owner)
    return [o]


def _setup(c):
    def h4dc630(em, r):
        em.calllog.append(('4dc630', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    c.emu.hook(0x4dc630, h4dc630)


S(0x45ba30, 'unknown::tail_via_vt214 (unknown) thiscall', 'thiscall', None, ret=None, gen=_tail, setup=_setup,
  note='unclaimed-04 batch 24; tail through slot 0x214 (arity 0, the verified form); 0x43e0f0 original')
