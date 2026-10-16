"""specs_s213026.py - batch 213026: object fetch by kind with an engine lookup, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def g471ff0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x20)
    this = obj(c, 0x20, {0x3ec: pystub(c, 1, ret=o, this=True),
                         0x3d8: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x100)
    tab = obj(c, 0x40, {0x58: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x18)
    eng = rnd(c, 0x1b00)
    e.w32(0x70039c, eng)
    e.w32(eng + 0x9b, tab)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    a = r.randint(0, 17) if r.random() < 0.92 else r.getrandbits(32)
    return [this, a, r.getrandbits(32)]


S(0x471ff0, 'fetch_obj_by_kind', 'thiscall', None, ret='eax', gen=g471ff0)


def g56c5a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    from recruits_util import hook_rec
    o = obj(c, 0x20, {0x34: pystub(c, 0, ret=r.getrandbits(32), this=True),
                      0x3c: pystub(c, 0, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]), this=True)}, nslots=0x10)
    this = obj(c, 0xd00, {0x104: pystub(c, 0, ret=r.getrandbits(32), this=True)}, nslots=0x42)
    e.wbytes(this + 0xc5e, o.to_bytes(4, 'little'))
    e.wbytes(this + 0xcee, r.choice([0, 1, 2, 3, 4, 5, 6, r.getrandbits(32)]).to_bytes(4, 'little'))
    hook_rec(c, 0x565020, 2, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x564600, 1, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x565100, 1, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x56c6a0, 0, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x56b460, 1, ret=r.getrandbits(32), this=True)
    return [this, r.getrandbits(32), r.choice([0, 1, 0x100, 0xff, r.getrandbits(32)])]


S(0x56c5a0, 'mode_dispatch', 'thiscall', None, ret='eax', gen=g56c5a0)
