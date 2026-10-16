"""specs_s210013.py - Sonnet-w3a: table tail-dispatchers with assert fallback, field copy, slot loops; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _edx(emu, k): emu.calllog.append(('edx', emu.reg('edx')))


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def _disp(N, TAB):
    def g(c):
        clear_hooks(c)
        n = c.rng.choice([0, 1, 2, 3, 5])
        c.emu.w32(N, n)
        for i in range(n):
            c.emu.w32(TAB + 4 * i, pystub(c, 1, ret=_r(c), this=True))
        o = obj(c, 0x40, {0x2c: pystub(c, 3, ret=_r(c), pop=0)}, nslots=0x20)
        gg = obj(c, 0x40, {0x20: pystub(c, 2, ret=o, this=True)}, nslots=0x20)
        c.emu.w32(0x700390, gg)
        _assert_hook(c)
        a = rnd(c, 0x40)
        c.emu.wbytes(a + 0x10, (c.rng.randrange(0, n + 4)).to_bytes(2, 'little'))
        return [rnd(c, 0x40), a]
    return g


def g565020(c):
    clear_hooks(c)
    m = obj(c, 0x40, {0x2c: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20)
    o = obj(c, 0xd00, {0xf8: pystub(c, 0, ret=_r(c), this=True), 0xfc: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x50)
    _ub(c, o + 0xc5e, m)
    hook_rec(c, 0x563110, 2, ret=_r(c), this=True)
    return [o, _r(c), c.rng.choice([0, 1, 0x100, 0x1ff, _r(c)])]


def g56f190(c):
    clear_hooks(c); return [rnd(c, 0x1d0), rnd(c, 0x1d0)]


def g640400(c):
    clear_hooks(c)
    n = c.rng.choice([0, 1, 2, 3, 4])
    slots = {0xb4: pystub(c, 0, ret=_r(c), this=True), 0xbc: pystub(c, 0, ret=_r(c), this=True), 0xc8: pystub(c, 0, ret=_r(c), this=True)}
    o = obj(c, 0x120, slots, nslots=0x40)
    c.emu.w32(o + 0xec, n)
    for i in range(n):
        c.emu.w32(o + 0xf0 + 4 * i, obj(c, 0x40, {0x40: pystub(c, 0, ret=_r(c), this=True)}, nslots=0x20))
    return [o]


def g4d1100(c):
    clear_hooks(c)
    o = rnd(c, 0x40)
    r = _r(c)
    hook_rec(c, 0x4d1220, 0, ret=r, this=True, side=_edx)
    if c.rng.random() < 0.4: c.emu.w32(o + 0xc, r)
    oo = obj(c, 0x40, {0x2c: pystub(c, 3, ret=_r(c), pop=0)}, nslots=0x20)
    gg = obj(c, 0x40, {0x20: pystub(c, 2, ret=oo, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, gg)
    return [o, _r(c)]


for a, N, TAB in [(0x50a440, 0x701128, 0x701130), (0x50b5c0, 0x7011f8, 0x701200), (0x50d820, 0x7012c8, 0x7012d0), (0x510ed0, 0x701398, 0x7013a0)]:
    S(a, 'table_tail_dispatch_%x' % a, 'thiscall', None, ret='eax', gen=_disp(N, TAB), note='batch210013')
S(0x565020, 'slots_then_563110_reset', 'thiscall', None, ret='eax', gen=g565020, note='batch210013')
S(0x56f190, 'copy_unaligned_fields', 'thiscall', None, ret='eax', gen=g56f190, note='batch210013')
S(0x640400, 'three_slots_then_member_loop', 'thiscall', None, ret='eax', gen=g640400, note='batch210013')
S(0x4d1100, 'check_4d1220_else_report', 'fastcall', None, ret='eax', gen=g4d1100, note='batch210013')
