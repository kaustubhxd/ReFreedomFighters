"""specs_s213015.py - batch 213015: indexed sub-object fill (float arg) and a kind-driven field select, Sonnet-w3b."""
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g5a57a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x640)
    subs = []
    for off in (0x5f8, 0x5fc, 0x600, 0x604, 0x608, 0x60c, 0x610, 0x614, 0x618, 0x61c, 0x620, 0x624):
        s = rnd(c, 0x60)
        idx = r.getrandbits(8)
        cap = r.choice([idx, idx + 1, idx + 2, idx - 1, r.getrandbits(8), 0]) & 0xffffffff
        e.wbytes(s + 0x42, idx.to_bytes(4, 'little'))
        e.wbytes(s + 0x3e, cap.to_bytes(4, 'little'))
        e.w32(o + off, s)
        subs.append(s)
    hook_rec(c, 0x5ec670, 2, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x5ec5f0, 2, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x5ec340, 2, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x5ec5a0, 1, ret=r.getrandbits(32), this=True)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    k = r.random()
    if k < 0.9:
        sel = r.randint(0, 12)
    else:
        s = rnd(c, 0x60)
        idx = r.getrandbits(8)
        e.wbytes(s + 0x42, idx.to_bytes(4, 'little'))
        e.wbytes(s + 0x3e, r.choice([idx, idx + 1, 0]).to_bytes(4, 'little'))
        sel = s     # sel above 12: it is used as the object itself
    x = r.choice([0.0, 1.5, -2.25, r.uniform(-100, 100)])
    return [o, r.getrandbits(32), sel, F(x), r.getrandbits(32)]


def _kobj(c, k):
    return obj(c, 0x20, {0x330: pystub(c, 0, ret=k, this=True)}, nslots=0xcd)


def g5919f0(c):
    clear_hooks(c)
    r = c.rng
    k = r.randint(0, 14) if r.random() < 0.9 else r.getrandbits(32)
    ke = _kobj(c, k)
    res = r.choice([0, 1, 0x100, 0xff, r.getrandbits(32)])
    o = obj(c, 0x20, {0x1e0: pystub(c, 1, ret=res, this=True), 0x350: pystub(c, 0, ret=ke, this=True)}, nslots=0x15d)
    oo = o if r.random() < 0.93 else 0
    this = obj(c, 0x7c0, {0x504: pystub(c, 0, ret=oo, this=True)}, nslots=0x142)
    flags = r.choice([0, 0x400, 2, 0x402, r.getrandbits(32), r.getrandbits(32)])
    c.emu.wbytes(this + 0x417, flags.to_bytes(4, 'little'))
    hook_rec(c, 0x591b20, 0, ret=r.choice([0x10, 0x10, 0, r.getrandbits(32)]), this=True)
    return [this]


S(0x5a57a0, 'fill_indexed_sub', 'thiscall', None, ret='eax', gen=g5a57a0)
S(0x5919f0, 'field_by_kind_flags', 'thiscall', None, ret='eax', gen=g5919f0)
