"""specs_s32083.py - h2 (Sonnet) batch 32083: eight tier C wrappers. Slots and the import are recorder stubs returning random eax."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g4efdd0(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0xa0, {0x224: pystub(c, 5, ret=r.getrandbits(32), this=True)}, nslots=0x224 // 4 + 1)
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def g535570(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c, table_slots={0x60: pystub(c, 1, ret=r.getrandbits(32), this=True)})
    hook_rec(c, 0x533e00, 0, this=True, pop=0, ret=r.choice([0, r.getrandbits(32)]))
    return [rnd(c, 0xa0)]


def g5c7720(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x20, {0x60: pystub(c, 1, ret=r.getrandbits(32), this=True)})
    return [rnd(c, 0x60), o]


def g421ea0(c):
    clear_hooks(c)
    r = c.rng
    f = pystub(c, 0, ret=r.getrandbits(32))
    c.emu.w32(0x6760b4, pystub(c, 2, ret=(f if r.random() < 0.7 else 0)))
    p = rnd(c, 0x20)
    return [0 if r.random() < 0.2 else p]


def g445390(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    if r.random() < 0.7:
        o = obj(c, 0x20, {0x2c: pystub(c, 0, this=True)})
        e.wbytes(so + 0x190f, o.to_bytes(4, 'little'))
    else:
        e.wbytes(so + 0x190f, bytes(4))
    me = rnd(c, 0x60)
    e.w32(me + 0x48, r.getrandbits(32) & ~0x20 if r.random() < 0.7 else r.getrandbits(32) | 0x20)
    return [me]


def g466870(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x20, {0x10: pystub(c, 4, ret=r.getrandbits(32), this=True)})
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x6c, o)
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def g470c20(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c, table_slots={0x4c: pystub(c, 1, ret=r.getrandbits(32), this=True)})
    return [rnd(c, 0xc0), r.getrandbits(32)]


def g4759f0(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x20, {0x2d0: pystub(c, 2, ret=r.getrandbits(32), this=True)}, nslots=0x2d0 // 4 + 1)
    me = obj(c, 0x40, {0x504: pystub(c, 0, ret=(o if r.random() < 0.75 else 0), this=True)}, nslots=0x504 // 4 + 1)
    return [me, r.getrandbits(32)]


S(0x4efdd0, 'GUESS slot 0x224(a,b,c,d,byte)', 'thiscall', None, ret='eax', gen=g4efdd0, note='batch32083')
S(0x535570, 'GUESS lookup then table slot 0x60', 'thiscall', None, ret='eax', gen=g535570, note='batch32083')
S(0x5c7720, 'GUESS clear bit 6, slot 0x60(byte), true', 'thiscall', None, ret='al', gen=g5c7720, note='batch32083')
S(0x421ea0, 'GUESS import returns fn, call it', 'stdcall', None, ret=None, gen=g421ea0, note='batch32083')
S(0x445390, 'GUESS once-only engine object notify', 'thiscall', None, ret=None, gen=g445390, note='batch32083')
S(0x466870, 'GUESS forward to [this+0x6c] slot 0x10', 'thiscall', None, ret='eax', gen=g466870, note='batch32083')
S(0x470c20, 'GUESS store table slot 0x4c result', 'thiscall', None, ret=None, gen=g470c20, note='batch32083')
S(0x4759f0, 'GUESS slot 0x504 object slot 0x2d0(a,0)', 'thiscall', None, ret='eax', gen=g4759f0, note='batch32083')
