"""specs_s338.py - gap band, batch 338: 0x6046d0 (scalar deleting destructor: frees are the CRT wrapper 0x634273, hooked) and 0x604310
(thiscall with one argument: the helper 0x603990 is hooked; the object's slot 0x38 returns a per-run value; the argument's slot 0 is a
thiscall stub with one argument that logs it)."""
from pilot import S


def _rec_free(em, r):
    # 0x634273 (cdecl, two arguments): free wrapper, recorded by address
    em.calllog.append(('free634273', 0, None, (em.arg32(0), em.arg32(1))))
    em.ret(eax=0, argbytes=0)


def _gen_dtor(c):
    e = c.emu
    rng = c.rng
    e.hook(0x634273, _rec_free)
    o = e.alloc(0x40, 4)
    e.wbytes(o, rng.randbytes(0x40))
    e.w32(o + 0xc, rng.getrandbits(32))
    return [o, rng.getrandbits(32)]


def _gen_link(c):
    e = c.emu
    rng = c.rng
    rv = rng.getrandbits(32)

    def rec(em, r):
        em.calllog.append(('h603990', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def slot38(em, r):
        em.calllog.append(('slot38', 0x38, em.reg('ecx'), ()))
        em.ret(eax=rv, argbytes=0)

    def slot0(em, r):
        em.calllog.append(('argslot0', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    e.hook(0x603990, rec)
    this = e.alloc(0x40, 4)
    e.w32(this, e.fake_vtable('this338', 0x80, {0x38: slot38}))
    arg = e.alloc(0x40, 4)
    e.w32(arg, e.fake_vtable('arg338', 0x20, {0: slot0}))
    return [this, arg]


S(0x6046d0, 'dtor6046d0 (GUESS)', 'thiscall', None, ret='eax', gen=_gen_dtor, note='batch338; ret 4; free 0x634273 hooked')
S(0x604310, 'link604310 (GUESS)', 'thiscall', None, ret=None, gen=_gen_link, note='batch338; ret 4; helper 0x603990 hooked')
