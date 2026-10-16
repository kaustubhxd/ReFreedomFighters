"""specs_s210078.py - Sonnet-w3a: 0x5d8340. Reader hooks 0x4e5ea0 (name pointer, lengths around 99 / 100) and 0x4e5e60 (two tagged values); the copy import at IAT 0x67642c is a recorder stub (3 args); the byte read through [s] covers 0xff, 0x3f-masked and plain values; the [0x7003b0] handler stub is always set."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g5d8340(c):
    clear_hooks(c)
    e = c.emu
    n = c.rng.choice([0, 1, 50, 98, 99, 100, 101, 150])
    nm = rnd(c, 0x100)
    e.wbytes(nm, bytes(c.rng.randrange(1, 256) for _ in range(n)) + b'\0')
    vals = [c.rng.choice([0, 1, _r(c), 0x100]), _r(c)]
    hook_rec(c, 0x4e5ea0, 0, ret=nm, this=True)
    hook_rec(c, 0x4e5e60, 0, ret=lambda emu, k: vals[min(k, 1)], this=True)
    e.w32(0x67642c, pystub(c, 3, ret=_r(c), pop=0))
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda e2, r_: (e2.calllog.append(('assert',)), e2.ret(eax=_r(c)))))
    mg = obj(c, 0x40, {0x58: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x30)
    so = rnd(c, 0x200)
    e.wbytes(so + 0x9b, mg.to_bytes(4, 'little'))
    e.w32(0x70039c, so)
    data = rnd(c, 0x10)
    e.wbytes(data, bytes([c.rng.choice([0xff, 0xff, 0x3f, 0x00, 0x7f, 0xc0, 0x41])]))
    s = rnd(c, 0x10); e.w32(s, data)
    return [rnd(c, 0xd0), s]


S(0x5d8340, 'read_name_and_fields', 'thiscall', None, ret=None, gen=g5d8340, note='batch210078')
