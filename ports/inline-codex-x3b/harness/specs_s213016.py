"""specs_s213016.py - batch 213016: state change request dispatcher, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g56cef0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    busy = r.choice([0, 0, 0, 1, 0x100, 0xff, r.getrandbits(32)])
    o44 = obj(c, 0x20, {0x12c: pystub(c, 2, ret=r.getrandbits(32), this=True)}, nslots=0x4c)
    slots = {0xd8: pystub(c, 0, ret=busy, this=True),
             0x9c: pystub(c, 1, ret=r.getrandbits(32), this=True),
             0xd0: pystub(c, 1, ret=r.getrandbits(32), this=True)}
    this = obj(c, 0x1d0, slots, nslots=0x3a)
    e.w32(this + 0x44, o44)
    if r.random() < 0.3:
        e.w32(this + 0x1be, 3)
    tab = obj(c, 0x40, {0x114: pystub(c, 5, ret=r.getrandbits(32), this=True, deref={4: 1})}, nslots=0x46)
    eng = rnd(c, 0x1b00)
    e.w32(0x70039c, eng)
    e.w32(eng + 0x9b, tab)
    hook_rec(c, 0x562c20, 1, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x56d280, 0, ret=r.getrandbits(32), this=True)
    sel = r.randint(0, 7) if r.random() < 0.92 else r.getrandbits(32)
    return [this, sel]


S(0x56cef0, 'state_request', 'thiscall', None, ret='eax', gen=g56cef0)
