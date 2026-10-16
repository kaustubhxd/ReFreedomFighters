"""specs_s210021.py - Sonnet-w3a: table clear, dtor with record array, stack-buffer slot loop, out-param init, member loop; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _eng(c, mgr_obj):
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mgr_obj)
    c.emu.w32(0x70039c, eng)


def _vt(o): return lambda emu, k: emu.calllog.append(('vt', emu.r32(o)))


def g630c50(c):
    clear_hooks(c); return [rnd(c, 0x16b0)]


def g6363a0(c):
    clear_hooks(c)
    t = rnd(c, 0x40)
    n = c.rng.choice([0, 1, 2, 3])
    c.emu.w32(t + 0x10, n)
    buf = 0 if (n == 0 and c.rng.random() < 0.4) else rnd(c, 0x80)
    c.emu.w32(t + 0x14, buf)
    if c.rng.random() < 0.5: c.emu.wbytes(t + 0x28, b'\x00')
    for i in range(n):
        if buf: c.emu.wbytes(buf + i * 0x14 + 0xc, bytes([c.rng.choice([0, 1, 1])]))
    hook_rec(c, 0x634273, 2, ret=_r(c), pop=0, side=_vt(t))
    return [t]


def g439bd0(c):
    clear_hooks(c)
    cnt = c.rng.choice([0, 1, 2, 3])

    def side4c(emu, k):
        p = emu.arg32(0)
        vals = [c.rng.getrandbits(32) for _ in range(3)]
        for i, v in enumerate(vals): emu.w32(p + 4 * i, v)
        emu.calllog.append(('buf', tuple(vals)))

    def side64(emu, k):
        p = emu.arg32(0)
        emu.calllog.append(('buf64', tuple(emu.r32(p + 4 * i) for i in range(3))))
    a = obj(c, 0x40, {0x4c: pystub(c, 1, ret=_r(c), this=True, stackmark=(0,), side=side4c),
                      0x64: pystub(c, 1, ret=lambda e, k: (c.rng.getrandbits(32) | 1) if k < cnt else 0, this=True, stackmark=(0,), side=side64)}, nslots=0x30)
    t = obj(c, 0x40, {4: pystub(c, 1, ret=_r(c), this=True)}, nslots=8)
    return [t, 0 if c.rng.random() < 0.15 else a]


def g5d5ae0(c):
    clear_hooks(c)
    a = rnd(c, 0x40)
    t = rnd(c, 0x60)

    def side(emu, k):
        if k == 2: emu.w32(emu.arg32(0), c.rng.getrandbits(32))
    hook_rec(c, 0x610100, 1, ret=_r(c))
    hook_rec(c, 0x4e12e0, 2, ret=_r(c), this=True, deref={0: 1}, side=side)
    hook_rec(c, 0x4e14a0, 2, ret=_r(c), this=True)
    _eng(c, obj(c, 0x40, {0x58: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20))
    return [t, a]


def g5c4b70(c):
    clear_hooks(c)

    def side90(emu, k):
        v = c.rng.choice([0, 0, 1, 0xff])
        emu.wbytes(emu.arg32(1), bytes([v]))
        emu.calllog.append(('flag', v))

    def side88(emu, k):
        emu.w32(emu.arg32(1), c.rng.getrandbits(32))
    g = obj(c, 0x40, {0x90: pystub(c, 2, ret=_r(c), this=True, stackmark=(1,), side=side90)}, nslots=0x40)
    g2 = obj(c, 0x40, {0x88: pystub(c, 2, ret=_r(c), this=True, deref={1: 1}, side=side88)}, nslots=0x40)
    _eng(c, obj(c, 0x40, {0x134: pystub(c, 0, ret=g, this=True), 0x138: pystub(c, 0, ret=g2, this=True), 0x58: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x60))
    return [rnd(c, 0x80)]


def g604030(c):
    clear_hooks(c)
    t = rnd(c, 0x40)
    n = c.rng.choice([0, 1, 2, 3])
    c.emu.w32(t + 0x14, n); c.emu.w32(t + 0xc, rnd(c, 0x40))
    a = obj(c, 0x40, {0x2c: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20)
    hook_rec(c, 0x5fa590, 2, ret=_r(c), this=True)
    hook_rec(c, 0x605a10, 3, ret=_r(c), this=True)
    return [t, a, _r(c)]


S(0x630c50, 'clear_tables', 'cdecl', None, ret='eax', gen=g630c50, note='batch210021')
S(0x6363a0, 'dtor_free_records', 'thiscall', None, ret='eax', gen=g6363a0, note='batch210021')
S(0x439bd0, 'drain_slot64_loop', 'thiscall', None, ret=None, gen=g439bd0, note='batch210021')
S(0x5d5ae0, 'read_fields_then_lookup', 'thiscall', None, ret='eax', gen=g5d5ae0, note='batch210021')
S(0x5c4b70, 'flag_then_lookup_slots', 'thiscall', None, ret='eax', gen=g5c4b70, note='batch210021')
S(0x604030, 'member_loop_605a10', 'thiscall', None, ret='eax', gen=g604030, note='batch210021')
