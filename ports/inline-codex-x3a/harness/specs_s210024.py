"""specs_s210024.py - Sonnet-w3a: flag lookup chain, slot fan-out, conditional slot, dtor with flags, field reader; callees hooked (vtable word logged in the dtor)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _vt(o): return lambda emu, k: emu.calllog.append(('vt', emu.r32(o)))


def _eng(c, mgr_obj):
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mgr_obj)
    c.emu.w32(0x70039c, eng)


def g55cec0(c):
    clear_hooks(c)
    a = rnd(c, 0x10); c.emu.w32(a + 8, rnd(c, 0x20))
    t = rnd(c, 0x40); inner = rnd(c, 0x800); c.emu.w32(t + 0x1c, inner); _ub(c, inner + 0x78a, _r(c))
    p = 0 if c.rng.random() < 0.25 else obj(c, 0x40, {0x300: pystub(c, 0, ret=c.rng.choice([0, 1, 2, 2, 3]), this=True)}, nslots=0xd0)
    o = 0 if c.rng.random() < 0.2 else obj(c, 0x40, {0x2e8: pystub(c, 0, ret=p, this=True)}, nslots=0xa0)
    _eng(c, obj(c, 0x40, {0x58: pystub(c, 1, ret=o, this=True)}, nslots=0x20))
    hook_rec(c, 0x5003d0, 1, ret=lambda e, k: rnd(c, 8), this=True)
    hook_rec(c, 0x5002f0, 1, ret=_r(c), this=True)
    return [t, a]


def g5c33a0(c):
    clear_hooks(c)
    a = obj(c, 0x40, {0x68: pystub(c, 1, ret=_r(c), this=True), 0x50: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20)
    return [rnd(c, 0x140), a]


def g5c55a0(c):
    clear_hooks(c)
    t = rnd(c, 0x160)
    n130 = [0]

    def h130(emu, r_):
        k = n130[0]; n130[0] += 1
        a = [emu.arg32(0), emu.arg32(1)] + ([emu.arg32(2)] if k == 0 else [])
        emu.calllog.append(('s130', k, emu.reg('ecx'), tuple(a)))
        emu.ret(eax=0x5eed0000 + k, argbytes=12 if k == 0 else 8)
    m = obj(c, 0x40, {0x130: c.emu.stub_fn('slot130', h130)}, nslots=0x50)
    hook_rec(c, 0x5c5620, 0, ret=c.rng.choice([0, 1, 5]), this=True)
    hook_rec(c, 0x5c5810, 0, ret=_r(c), this=True)
    _eng(c, obj(c, 0x40, {0x114: pystub(c, 5, ret=_r(c), this=True)}, nslots=0x60))
    tt = obj(c, 0x160, {0x68: pystub(c, 2, ret=_r(c), this=True)}, nslots=0x20)
    c.emu.w32(tt + 0x44, m)
    c.emu.wbytes(tt + 0x14c, (_r(c) & 0xffff).to_bytes(2, 'little'))
    return [tt]


def g5d88d0(c):
    clear_hooks(c)
    o = rnd(c, 0x40)
    if c.rng.random() < 0.3: c.emu.w32(o + 0x20, 0)
    if c.rng.random() < 0.3: c.emu.w32(o + 0x24, 0)
    hook_rec(c, 0x41e2c0, 1, ret=_r(c), pop=0, side=_vt(o))
    hook_rec(c, 0x634273, 2, ret=_r(c), pop=0, side=_vt(o))
    hook_rec(c, 0x43de70, 0, ret=_r(c), this=True, side=_vt(o))
    hook_rec(c, 0x45c510, 1, ret=_r(c), pop=0)
    hook_rec(c, 0x4690b0, 2, ret=_r(c), pop=0)
    return [o, c.rng.choice([0, 1, 4, 5, 2, 7, _r(c)])]


def g5d8cf0(c):
    clear_hooks(c)
    hook_rec(c, 0x610100, 1, ret=_r(c))
    for h in (0x4e12e0, 0x4e11e0, 0x4e12f0):
        hook_rec(c, h, 2, ret=_r(c), this=True)
    return [rnd(c, 0x60), rnd(c, 0x20)]


S(0x55cec0, 'flag_lookup_chain_55cec0', 'thiscall', None, ret='eax', gen=g55cec0, note='batch210024')
S(0x5c33a0, 'slot_fanout_serialize', 'thiscall', None, ret='eax', gen=g5c33a0, note='batch210024')
S(0x5c55a0, 'conditional_slot_130', 'thiscall', None, ret='eax', gen=g5c55a0, note='batch210024')
S(0x5d88d0, 'dtor_flags_5d88d0', 'thiscall', None, ret='eax', gen=g5d88d0, note='batch210024')
S(0x5d8cf0, 'read_fields_six_calls', 'thiscall', None, ret='eax', gen=g5d8cf0, note='batch210024')
