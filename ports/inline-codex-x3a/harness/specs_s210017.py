"""specs_s210017.py - Sonnet-w3a: engine compare then member slots, conditional field copy, byte out-param, serializer slots; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _eng(c, mgr_obj, vt_slots=None):
    eng = obj(c, 0x1b00, vt_slots or {}, nslots=0x80)
    _ub(c, eng + 0x9b, mgr_obj)
    c.emu.w32(0x70039c, eng)


def g5d58e0(c):
    clear_hooks(c)
    ax = _r(c) & 0xffff
    _eng(c, obj(c, 0x40, {0x114: pystub(c, 4, ret=ax | (_r(c) & 0xffff0000), this=True)}, nslots=0x60))
    m = 0 if c.rng.random() < 0.3 else obj(c, 0x40, {0x2c: pystub(c, 0, ret=_r(c), this=True)}, nslots=0x20)
    t = obj(c, 0x80, {0x110: pystub(c, 2, ret=_r(c), this=True)}, nslots=0x50)
    _ub(c, t + 0x25, m)
    hook_rec(c, 0x45d380, 2, ret=_r(c), this=True)
    a = ax if c.rng.random() < 0.5 else _r(c)
    a |= c.rng.choice([0, 0x10000, _r(c) & 0xffff0000])
    return [t, a, _r(c)]


def g444310(c):
    clear_hooks(c)
    a = obj(c, 0xa0, {0x1e0: pystub(c, 1, ret=c.rng.choice([0, 1, 0x100, _r(c)]), this=True)}, nslots=0x80)
    g = obj(c, 0x40, {0xbc: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x60)
    c.emu.w32(0x70038c, g)
    hook_rec(c, 0x442c00, 1, ret=_r(c), this=True)
    return [rnd(c, 0xa0), a]


def g561be0(c):
    clear_hooks(c)

    def side(emu, k):
        v = c.rng.choice([0, 0, 1, 0xff])
        p = emu.arg32(1)
        emu.calllog.append(('b', v))
        emu.wbytes(p, bytes([v]))
    g = obj(c, 0x40, {0x90: pystub(c, 2, ret=_r(c), this=True, side=side)}, nslots=0x40)
    o = obj(c, 0x40, {0xe0: pystub(c, 0, ret=c.rng.choice([0, 1, 0x100, 0x101, _r(c)]), this=True)}, nslots=0x40)
    _eng(c, obj(c, 0x40, {0x134: pystub(c, 0, ret=g, this=True)}, nslots=0x60), {0xbc: pystub(c, 0, ret=o, this=True)})
    return []


def g59d3a0(c):
    clear_hooks(c)
    a = obj(c, 0x40, {0x18: pystub(c, 2, ret=_r(c), this=True), 0x40: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20)
    return [rnd(c, 0x40), a]


S(0x5d58e0, 'compare_ax_member_slots', 'thiscall', None, ret='eax', gen=g5d58e0, note='batch210017')
S(0x444310, 'copy_fields_if_flag', 'thiscall', None, ret='eax', gen=g444310, note='batch210017')
S(0x561be0, 'byte_outparam_check', 'cdecl', None, ret='eax', gen=g561be0, note='batch210017')
S(0x59d3a0, 'serialize_four_fields', 'thiscall', None, ret='eax', gen=g59d3a0, note='batch210017')
