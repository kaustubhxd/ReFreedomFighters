"""specs_s213019.py - batch 213019: request dispatcher with an engine lookup, and a kind-byte reader with out slot, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g562c90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    busy = r.choice([0, 0, 0, 1, 0x100, 0xff, r.getrandbits(32)])

    def outw(emu, k):
        emu.w32(emu.arg32(1), r.getrandbits(32))
    o88 = obj(c, 0x20, {0x88: pystub(c, 2, ret=r.getrandbits(32), this=True, nullflag=(1,), side=outw)}, nslots=0x24)
    o44 = obj(c, 0x20, {0x12c: pystub(c, 2, ret=r.getrandbits(32), this=True)}, nslots=0x4c)
    slots = {0xd8: pystub(c, 0, ret=busy, this=True),
             0xd0: pystub(c, 1, ret=r.getrandbits(32), this=True)}
    this = obj(c, 0x60, slots, nslots=0x38)
    e.w32(this + 0x44, o44)
    tab = obj(c, 0x40, {0x138: pystub(c, 0, ret=o88, this=True),
                        0x114: pystub(c, 5, ret=r.getrandbits(32), this=True, deref={4: 1})}, nslots=0x46)
    eng = rnd(c, 0x1b00)
    e.w32(0x70039c, eng)
    e.w32(eng + 0x9b, tab)
    hook_rec(c, 0x562c20, 1, ret=r.getrandbits(32), this=True)
    sel = r.randint(0, 6) if r.random() < 0.92 else r.getrandbits(32)
    return [this, sel]


def g605940(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def outw(emu, k):
        v = r.choice([0, 1, 2, 3, 4, 5, 6, 0x103, r.getrandbits(32), r.randint(0, 255)])
        emu.w32(emu.arg32(0), v)
    a = obj(c, 0x20, {0x5c: pystub(c, 1, ret=r.getrandbits(32), this=True, deref={0: 1}, side=outw),
                      0x60: pystub(c, 1, ret=r.getrandbits(32), this=True),
                      0x64: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x1a)
    this = rnd(c, 0x20)
    hook_rec(c, 0x5f5620, 1, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x5fa1e0, 1, ret=r.getrandbits(32), this=True)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    cc = rnd(c, 0x20) if r.random() < 0.8 else 0
    bb = rnd(c, 0x20)
    return [this, a, bb, cc]


S(0x562c90, 'request_with_lookup', 'thiscall', None, ret='eax', gen=g562c90)
S(0x605940, 'read_kind_dispatch', 'thiscall', None, ret='eax', gen=g605940)
