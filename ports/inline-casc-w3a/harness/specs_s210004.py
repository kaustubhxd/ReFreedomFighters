"""specs_s210004.py - Sonnet-w3a: vtable dispatchers, forwarders and member chains; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g46e660(c):
    clear_hooks(c)
    r = 0 if c.rng.random() < 0.4 else rnd(c, 0x40)
    return [obj(c, 0x80, {0x25c: pystub(c, 2, ret=r, this=True)}, nslots=0xa0)]


def g42abee(c):
    clear_hooks(c)
    hook_rec(c, 0x42abbd, 5, ret=_r(c), pop=0)
    return [_r(c), _r(c), _r(c)]


def g45c680(c):
    clear_hooks(c)
    o = obj(c, 0x40, {0x34: pystub(c, 0, ret=_r(c), this=True), 0x30: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20)
    return [o, c.rng.choice([0, 1, 0x100, 0x1ff, _r(c)])]


def g4d3cf0(c):
    clear_hooks(c)
    hook_rec(c, 0x4d24e0, 4, ret=_r(c), this=True)
    return [rnd(c, 0x80), _r(c), _r(c), _r(c)]


def g4d6010(c):
    clear_hooks(c)
    r = obj(c, 0x40, {0x2c: pystub(c, 2, ret=_r(c), pop=0)}, nslots=0x20)
    g = obj(c, 0x40, {0x20: pystub(c, 2, ret=r, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, g)
    return [_r(c)]


def g4da340(c):
    clear_hooks(c)
    o = rnd(c, 0x80)
    m = 0 if c.rng.random() < 0.3 else obj(c, 0x40, {0x124: pystub(c, 4, ret=_r(c), this=True)}, nslots=0x60)
    c.emu.w32(o + 0x54, m)
    return [o, _r(c), _r(c), _r(c), _r(c)]


def g4e5e40(c):
    clear_hooks(c)
    hook_rec(c, 0x4e5f10, 0, ret=_r(c), this=True)
    hook_rec(c, 0x4e6420, 0, ret=_r(c), this=True)
    return [rnd(c, 0x40)]


def g5ef050(c):
    clear_hooks(c)
    o = rnd(c, 0x40)
    for off in (4, 8):
        c.emu.w32(o + off, rnd(c, 0x40))
    hook_rec(c, 0x5acac0, 1, ret=_r(c), this=True)
    return [o, _r(c)]


def g5fb530(c):
    clear_hooks(c)
    o = rnd(c, 0x80)
    hook_rec(c, 0x5fcb80, 5, ret=_r(c), this=True)
    return [o, _r(c), _r(c), _r(c), _r(c)]


def g636400(c):
    clear_hooks(c)
    o = rnd(c, 0x80)
    if c.rng.random() < 0.4: c.emu.wbytes(o + 0x31, b'\x00')
    hook_rec(c, 0x634273, 2, ret=_r(c), pop=0)
    hook_rec(c, 0x6363a0, 0, ret=_r(c), this=True)
    return [o]


def g437050(c):
    clear_hooks(c)
    r = 0 if c.rng.random() < 0.25 else rnd(c, 0x40)
    if r and c.rng.random() < 0.5: c.emu.w32(r, 0)
    return [obj(c, 0x40, {0x58: pystub(c, 1, ret=r, this=True)}, nslots=0x20), _r(c)]


S(0x46e660, 'vslot_25c_or_this', 'thiscall', None, ret='eax', gen=g46e660, note='batch210004')
S(0x42abee, 'forward_42abbd', 'cdecl', None, ret='eax', gen=g42abee, note='batch210004')
S(0x45c680, 'flag_dispatch_slots_34_30', 'thiscall', None, ret='eax', gen=g45c680, note='batch210004')
S(0x4d3cf0, 'forward_4d24e0_scaled', 'thiscall', None, ret='eax', gen=g4d3cf0, note='batch210004')
S(0x4d6010, 'engine_obj_two_calls', 'stdcall', None, ret='eax', gen=g4d6010, note='batch210004')
S(0x4da340, 'member_slot_124_or_zero', 'thiscall', None, ret='eax', gen=g4da340, note='batch210004')
S(0x4e5e40, 'chain_4e5f10_4e6420_ax', 'thiscall', None, ret='eax', gen=g4e5e40, note='batch210004')
S(0x5ef050, 'set_flag_bytes_forward_5acac0', 'thiscall', None, ret='eax', gen=g5ef050, note='batch210004')
S(0x5fb530, 'forward_5fcb80_with_byte', 'thiscall', None, ret='eax', gen=g5fb530, note='batch210004')
S(0x636400, 'dtor_set_vt_free_636400', 'thiscall', None, ret='eax', gen=g636400, note='batch210004')
S(0x437050, 'slot58_mark_result', 'thiscall', None, ret='eax', gen=g437050, note='batch210004')
