"""specs_s34024.py - cascade tier E, batch 34024.
0x52cb00: hooked 0x45f960 returns 0/1 (high bytes random); the stream s has slots 0x44 and 0x10 as recorders; the pointer at +0x79 (unaligned) leads to a record of random dwords.
0x5590d0 / 0x559140: hooked 0x5003d0 returns an entry with kind byte 0, 1 or another value (logger object at 0x700390 and assert hook set); [this+0x1c] is an object whose slot 0x6d8
is a recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _g52cb00(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x45f960, 1, ret=r.choice([0, 1, 1]) | (r.getrandbits(24) << 8), this=True)
    s = obj(c, 0x20, {0x44: pystub(c, 1, this=True), 0x10: pystub(c, 2, this=True)}, nslots=0x50)
    me = rnd(c, 0x100)
    c.emu.wbytes(me + 0x79, rnd(c, 0x20).to_bytes(4, 'little'))
    return [me, s]


def _gentry(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    e = rnd(c, 0x20)
    c.emu.wbytes(e + 4, bytes([r.choice([0, 1, 0, 1, 2, 3, 0x80, r.getrandbits(8)])]))
    hook_rec(c, 0x5003d0, 1, ret=e, this=True)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 3, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, lg)
    o = obj(c, 0x20, {0x6d8: pystub(c, 2, this=True)}, nslots=0x700 // 4)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x1c, o)
    a = rnd(c, 0x20)
    c.emu.w32(a + 4, rnd(c, 0x20))
    return [me, a]


S(0x52cb00, 'GUESS write record to stream when accepted', 'thiscall', None, ret='al', gen=_g52cb00, note='batch34024')
S(0x5590d0, 'GUESS send entry byte with flag 1', 'thiscall', None, ret=None, gen=_gentry, note='batch34024')
S(0x559140, 'GUESS send entry byte with flag 0', 'thiscall', None, ret=None, gen=_gentry, note='batch34024')
