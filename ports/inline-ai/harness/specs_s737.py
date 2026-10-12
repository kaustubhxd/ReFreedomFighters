"""specs_s737.py - ZFFActor::CreateLnkAction. operator new (0x41e290, cdecl) is hooked: it logs the size and returns a fresh
block, or 0 in about one case in six (the null path). The two action constructors (0x5eae20, 0x5eaee0) are hooked: they log
their arguments and return their object pointer. ZLNKWHANDS::CreateLnkAction (0x4733d0) is hooked (logged, random result).
The actor's fields +0x7ae, +0x7b2, +0x7b6 are random dwords. The id is 0x11, 0x12, 0x13 or a random other value."""
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _cla(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))

    def h_new(em, r):
        size = em.arg32(0)
        e.calllog.append(('heap', 0x41e290, None, (nostk(size),)))   # cdecl: the caller pops the argument
        if c.rng.random() < 0.17:
            em.ret(eax=0, argbytes=0)
        else:
            em.ret(eax=blocks.pop(0), argbytes=0)
    blocks = [_rnd(c, 0x80) for _ in range(2)]
    e.hook(0x41e290, h_new)

    def h_ctor1(em, r):
        log('act', 0x5eae20, (em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)))
        em.ret(eax=em.reg('ecx'), argbytes=16)

    def h_ctor2(em, r):
        log('act', 0x5eaee0, (em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=em.reg('ecx'), argbytes=12)

    def h_lnk(em, r):
        log('lnk', 0x4733d0, (em.arg32(0),))
        em.ret(eax=ret_lnk, argbytes=4)

    ret_lnk = c.rng.getrandbits(32)
    e.hook(0x5eae20, h_ctor1)
    e.hook(0x5eaee0, h_ctor2)
    e.hook(0x4733d0, h_lnk)

    self_ = _rnd(c, 0x900)
    for off in (0x7ae, 0x7b2, 0x7b6):
        e.w32(self_ + off, c.rng.getrandbits(32))
    idv = c.rng.choice([0x11, 0x12, 0x13, 0x11, c.rng.getrandbits(8), 0x14])
    return [self_, idv]


S(0x59f070, 'ZFFActor::CreateLnkAction', 'thiscall', None, ret='eax', gen=_cla,
  note='b737 residue 11 [medium]; new, action ctors and ZLNKWHANDS hooked')
