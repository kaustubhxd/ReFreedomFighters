"""specs_s727.py - soldier AI batch 727: ZFFActorIf::CheckPosition. Three float inputs (the point). The actor (this+0x1c) has
slot 0x5d0 returning the pathfinder (present in most cases, null otherwise, which takes the warning path). The pathfinder has
slot 0x220 which logs the point it is given and returns a bool. The output accessor holds one item. The logger and printf
come from the shared _log_world hooks; the typed setter 0x5002f0 runs as exe code."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s709 import _log_world
from specs_s705 import nostk


def _f(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _list(c, e, items, count):
    """accessor object: +0 -> inner (items at +0, count at +8); items are 8 bytes (value, type byte)."""
    inner = _rnd(c, 0x20)
    arr = _rnd(c, 8 * max(count, 2))
    for i in range(max(count, 2)):
        e.wbytes(arr + 8 * i, struct.pack('<II', items[i] if i < len(items) else c.rng.getrandbits(32), 0))
    e.w32(inner, arr)
    e.w32(inner + 8, count)
    acc = _rnd(c, 0x20)
    e.w32(acc, inner)
    e.w32(acc + 4, 0)
    e.w32(acc + 8, count)
    return acc


def _cp(c):
    e = c.emu
    _log_world(c)
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))

    pts = [c.rng.uniform(-200.0, 200.0) for _ in range(3)]
    items = [_f(p) for p in pts]
    flag = c.rng.choice([0, 1])

    def pf220(em, r):
        p = em.arg32(0)
        log('pf', 0x220, (em.rbytes(p, 12),))
        em.ret(eax=flag, argbytes=4)
    pf = _rnd(c, 0x40)
    e.w32(pf, e.fake_vtable('pf', 0x240, {0x220: pf220}))

    has_pf = c.rng.random() < 0.8

    def m5d0(em, r):
        log('actor', 0x5d0, ())
        em.ret(eax=pf if has_pf else 0, argbytes=0)
    actor = _rnd(c, 0x80)
    e.w32(actor, e.fake_vtable('actor', 0x600, {0x5d0: m5d0}))

    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x1c, actor)

    args = _rnd(c, 0x20)
    e.w32(args + 4, _list(c, e, items, 3))
    e.w32(args + 8, _list(c, e, [c.rng.getrandbits(32)], 1))
    return [self_, args]


S(0x558810, 'ZFFActorIf::CheckPosition', 'thiscall', None, ret=None, gen=_cp,
  note='b727 [low]; pathfinder and actor slots are fakes; the warning path runs without a pathfinder')
