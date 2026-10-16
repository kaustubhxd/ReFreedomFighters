"""specs_s210012.py - Sonnet-w3a: engine-table call chains with constants; every slot is a recording stub."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _eng(c, mgr_obj):
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mgr_obj)
    c.emu.w32(0x70039c, eng)


def g5c2f30(c):
    clear_hooks(c)
    g = obj(c, 0x40, {0x14: pystub(c, 4, ret=_r(c), this=True), 0x5c: pystub(c, 3, ret=_r(c), this=True)}, nslots=0x30)
    _eng(c, obj(c, 0x40, {0x134: pystub(c, 0, ret=g, this=True)}, nslots=0x60))
    return [rnd(c, 0x100)]


def g5d5620(c):
    clear_hooks(c)
    o = obj(c, 0x80, {0x27c: pystub(c, 1, ret=_r(c), this=True), 0x250: pystub(c, 0, ret=_r(c), this=True)}, nslots=0xa0)
    p = rnd(c, 0x40)
    _eng(c, obj(c, 0x40, {0x58: pystub(c, 1, ret=lambda e, k: o if k % 2 == 0 else p, this=True)}, nslots=0x20))
    return [rnd(c, 0x60)]


def g5da280(c):
    clear_hooks(c)
    hook_rec(c, 0x4e5e60, 0, ret=_r(c), this=True)
    hook_rec(c, 0x4e6180, 1, ret=_r(c), this=True)
    return [rnd(c, 0x80), rnd(c, 0x40)]


def g5f0d30(c):
    clear_hooks(c)
    s = obj(c, 0x40, {0x130: pystub(c, 3, ret=_r(c), this=True)}, nslots=0x50)
    _eng(c, obj(c, 0x40, {0x58: pystub(c, 0, ret=s, this=True), 0x114: pystub(c, 5, ret=_r(c), this=True)}, nslots=0x60))
    return [rnd(c, 0x20)]


S(0x5c2f30, 'engine_two_slot_calls', 'thiscall', None, ret='eax', gen=g5c2f30, note='batch210012')
S(0x5d5620, 'engine_obj_reset_tail', 'thiscall', None, ret='eax', gen=g5d5620, note='batch210012')
S(0x5da280, 'read_four_fields_then_4e6180', 'thiscall', None, ret='eax', gen=g5da280, note='batch210012')
S(0x5f0d30, 'engine_slot_114_then_130', 'thiscall', None, ret='eax', gen=g5f0d30, note='batch210012')
