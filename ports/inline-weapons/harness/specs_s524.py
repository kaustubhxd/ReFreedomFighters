"""specs_s524.py - weapons batch 524: ZLNKWHANDS ControlPushButton / ControlPickup."""
from pilot import S
from wkit import rnd, stub, obj, b, sysobj, seq_stub


def _item(c):
    r = c.rng
    t = obj(c, 0x40, {0x308: stub(c, 0, ret=r.choice((0, 1, 2))), 0x300: stub(c, 0, ret=r.choice((0, 2, 1)))})
    return obj(c, 0x40, {0x2e8: stub(c, 0, ret=t), 0x1e0: stub(c, 1, ret=b(c, 0.5))})


def _push(c):
    r = c.rng
    sysobj(c, {0x4c: stub(c, 1, ret=r.getrandbits(32))})
    s = obj(c, 0x600, {0x3f0: stub(c, 0, ret=r.choice((0, 0, 3))), 0x514: stub(c, 0, ret=r.choice((0, 1, 2))),
                       0x45c: stub(c, 2)})
    return [s, r.getrandbits(32)]


def _pick(c):
    r = c.rng
    acts = [r.choice((0, 3, 4, 4, 5, 6, 9, 0xa)) for _ in range(6)]
    s = obj(c, 0x600, {0x3f0: seq_stub(c, 0, acts), 0x500: stub(c, 0, ret=0 if r.random() < 0.3 else _item(c)),
                       0x504: stub(c, 0, ret=0 if r.random() < 0.3 else _item(c)), 0x45c: stub(c, 2)})
    return [s, _item(c)]


S(0x473240, 'ZLNKWHANDS::ControlPushButton', 'thiscall', None, ret=None, gen=_push)
S(0x4730b0, 'ZLNKWHANDS::ControlPickup', 'thiscall', None, ret='eax', gen=_pick)
