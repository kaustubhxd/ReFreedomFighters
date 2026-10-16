"""specs_s210025.py - Sonnet-w3a: byte compare, state-dependent slots, array remove, engine lookups, serializer; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _eng(c, mgr_obj):
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mgr_obj)
    c.emu.w32(0x70039c, eng)


def g4309b0(c):
    clear_hooks(c)
    n = c.rng.choice([0, 1, 2, 3, 4, 5, 7, 8, 9, 12])
    a = rnd(c, 0x20); b = rnd(c, 0x20)
    data = c.emu.rbytes(a, 0x20)
    bb = bytearray(data)
    if c.rng.random() < 0.7:
        if c.rng.random() < 0.6 and n:
            bb[c.rng.randrange(0, n)] = c.rng.randrange(0, 256)
    else:
        bb = bytearray(c.rng.getrandbits(8) for _ in range(0x20))
    c.emu.wbytes(b, bytes(bb))
    return [a, b, n]


def g4a5fe0(c):
    clear_hooks(c)
    o = rnd(c, 0x60); c.emu.w32(o + 0x4c, c.rng.choice([1, 1, 0, 5]))
    o2 = 0 if c.rng.random() < 0.2 else obj(c, 0x40, {0x210: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x90)
    k = [0]
    m = obj(c, 0x40, {0x20: pystub(c, 0, ret=lambda e, n: o if n == 0 else o2, this=True),
                      0x210: pystub(c, 1, ret=_r(c), this=True), 0x28: pystub(c, 0, ret=_r(c), this=True)}, nslots=0x90)
    t = obj(c, 0xc8, {0x68: pystub(c, 2, ret=_r(c), this=True)}, nslots=0x20)
    c.emu.w32(t + 0x44, 0 if c.rng.random() < 0.15 else m)
    for off in (0x8f, 0x90, 0x91):
        c.emu.wbytes(t + off, bytes([c.rng.choice([0, 1])]))
    if c.emu.r32(t + 0x44) == 0:
        c.emu.wbytes(t + 0x90, b'\x00'); c.emu.wbytes(t + 0x91, b'\x00')
        if c.rng.random() < 0.5: c.emu.wbytes(t + 0x8f, b'\x01')
        else: c.emu.wbytes(t + 0x8f, b'\x00')
    return [t]


def g4dc140(c):
    clear_hooks(c)
    t = rnd(c, 0x40)
    n = c.rng.choice([0, 1, 2, 3, 4, 5, 6])
    c.emu.wbytes(t + 0x1c, bytes([n]))
    keys = [c.rng.choice([1, 2, 3, 4, 5, 6]) for _ in range(8)]
    for i, k in enumerate(keys): c.emu.w32(t + 4 * i, k)
    return [t, c.rng.choice([1, 2, 3, 4, 5, 6, 7])]


def g5d3eb0(c):
    clear_hooks(c)
    _eng(c, obj(c, 0x40, {0x114: pystub(c, 4, ret=lambda e, k: c.rng.getrandbits(32), this=True)}, nslots=0x60))
    return [rnd(c, 0x90)]


def g5d8ee0(c):
    clear_hooks(c)
    hook_rec(c, 0x45f3c0, 1, ret=_r(c), this=True)
    a = obj(c, 0x40, {0x40: pystub(c, 1, ret=_r(c), this=True), 0x48: pystub(c, 1, ret=_r(c), this=True), 0x50: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20)
    return [rnd(c, 0x60), a]


S(0x4309b0, 'memcmp_sign', 'fastcall', None, ret='eax', gen=g4309b0, note='batch210025')
S(0x4a5fe0, 'state_dependent_slots_4a5fe0', 'thiscall', None, ret=None, gen=g4a5fe0, note='batch210025')
S(0x4dc140, 'remove_key_from_array', 'thiscall', None, ret='eax', gen=g4dc140, note='batch210025')
S(0x5d3eb0, 'init_four_engine_ids', 'thiscall', None, ret='eax', gen=g5d3eb0, note='batch210025')
S(0x5d8ee0, 'serialize_six_fields', 'thiscall', None, ret='eax', gen=g5d8ee0, note='batch210025')
