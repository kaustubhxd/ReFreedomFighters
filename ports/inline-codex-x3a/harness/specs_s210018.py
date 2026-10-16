"""specs_s210018.py - Sonnet-w3a: engine out-param slots, fastcall edx pointer, dtor with buffers, callback classifier, loop; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _eng(c, mgr_obj):
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mgr_obj)
    c.emu.w32(0x70039c, eng)


def g5c2ec0(c):
    clear_hooks(c)

    def side(emu, k):
        emu.w32(emu.arg32(1), c.rng.choice([0, 0, 1, c.rng.getrandbits(32)]))
    g = obj(c, 0x40, {0x88: pystub(c, 2, ret=_r(c), this=True, deref={1: 1}, side=side),
                      0x6c: pystub(c, 3, ret=_r(c), this=True)}, nslots=0x40)
    _eng(c, obj(c, 0x40, {0x134: pystub(c, 0, ret=g, this=True)}, nslots=0x60))
    return [rnd(c, 0x100)]


def g5f0cd0(c):
    clear_hooks(c)
    s = obj(c, 0x40, {0x130: pystub(c, 2, ret=_r(c), this=True)}, nslots=0x50)
    _eng(c, obj(c, 0x40, {0x58: pystub(c, 1, ret=s, this=True), 0x114: pystub(c, 5, ret=_r(c), this=True, deref={4: 1})}, nslots=0x60))
    return [rnd(c, 0x40), _r(c)]


def g477580(c):
    clear_hooks(c)
    o = rnd(c, 0x40)
    for off in (0xc, 0x10, 0x14):
        if c.rng.random() < 0.35: c.emu.w32(o + off, 0)
    hook_rec(c, 0x41e2c0, 1, ret=_r(c), pop=0)
    hook_rec(c, 0x634273, 2, ret=_r(c), pop=0)
    return [o, c.rng.choice([0, 1, 2, 3, _r(c)])]


def g62c6c0(c):
    clear_hooks(c)
    r = c.rng.choice([0, 1, 0x41, 0x7f, 0xff, 0xd7ff, 0xd800, 0xdbff, 0xdfff, 0xe000, 0xfefe, 0xfffe, 0xffff, 0xff00, 0x10000, 0x80000000, _r(c), _r(c) & 0xffff])
    a = rnd(c, 0x180)
    c.emu.w32(a + 0x170, pystub(c, 2, ret=r, pop=0))
    return [a, _r(c)]


def g493090(c):
    clear_hooks(c)
    n = c.rng.choice([0, 1, 2, 3])
    a = rnd(c, 0x40); c.emu.w32(a, n)
    hook_rec(c, 0x4dbe30, 1, ret=_r(c), this=True)
    _eng(c, obj(c, 0x40, {0x2c: pystub(c, 0, ret=c.rng.choice([0, 0, 1, 0x100, _r(c)]), this=True),
                           0x54: pystub(c, 1, ret=lambda e, k: rnd(c, 0x10), this=True)}, nslots=0x30))
    return [a]


S(0x5c2ec0, 'engine_outparam_then_slot6c', 'thiscall', None, ret='eax', gen=g5c2ec0, note='batch210018')
S(0x5f0cd0, 'fastcall_edx_pointer_slot130', 'fastcall', None, ret='eax', gen=g5f0cd0, note='batch210018')
S(0x477580, 'dtor_free_buffers_477580', 'thiscall', None, ret='eax', gen=g477580, note='batch210018')
S(0x62c6c0, 'classify_callback_result', 'cdecl', None, ret='eax', gen=g62c6c0, note='batch210018')
S(0x493090, 'loop_engine_slot54_4dbe30', 'stdcall', None, ret='eax', gen=g493090, note='batch210018')
