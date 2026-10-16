"""specs_s210046.py - Sonnet-w3a: /GS-protected rows with small stack buffers. The cookie check 0x633654 is hooked (log only); stack buffer args use stackmark; stubs that fill a buffer log the values."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _log(tag): return lambda emu, k: emu.calllog.append((tag,))


def g508560(c):
    clear_hooks(c)
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    x = rnd(c, 8); c.emu.w32(x, c.rng.choice([0, 1, 5]))
    hook_rec(c, 0x5003d0, 1, ret=x, this=True)
    def s57c(emu, k):
        emu.w32(emu.arg32(0), 0xAAAA0000 | c.rng.getrandbits(16)); emu.w32(emu.arg32(1), 0xBBBB0000 | c.rng.getrandbits(16))

    def s620(emu, k):
        emu.calllog.append(('b10', emu.r32(emu.arg32(0))))

    def s578(emu, k):
        emu.calllog.append(('b', emu.r32(emu.arg32(0)), emu.r32(emu.arg32(1))))
    m = obj(c, 0x720, {0x57c: pystub(c, 2, ret=_r(c), this=True, stackmark=(0, 1), side=s57c),
                       0x620: pystub(c, 3, ret=_r(c), this=True, stackmark=(0,), side=s620),
                       0x578: pystub(c, 2, ret=_r(c), this=True, stackmark=(0, 1), side=s578)}, nslots=0x190)
    t = rnd(c, 0x40); c.emu.w32(t + 0x18, m)
    a = rnd(c, 0x10); c.emu.w32(a + 4, rnd(c, 0x20))
    return [t, a]


def g4af500(c):
    clear_hooks(c)
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))

    def fill(emu, k):
        p = emu.arg32(0)
        vals = [c.rng.getrandbits(32) for _ in range(4)]
        for i, v in enumerate(vals): emu.w32(p + 4 * i, v)
        emu.calllog.append(('loc', tuple(vals)))
    hook_rec(c, 0x4daf90, 1, ret=_r(c), this=True, stackmark=(0,), side=fill)
    a = obj(c, 0x40, {0x84: pystub(c, 1, ret=_r(c), this=True, stackmark=(0,))}, nslots=0x30)
    c.emu.w32(a + 8, rnd(c, 0x20))
    mm = obj(c, 0x40, {0x8c: pystub(c, 1, ret=_r(c), this=True, stackmark=(0,)),
                       0x180: pystub(c, 2, ret=c.rng.choice([0, 1, 0x100]), this=True, stackmark=(0,))}, nslots=0x62)
    t = obj(c, 0x80, {0x84: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x30)
    c.emu.w32(t + 0x44, mm)
    c.emu.wbytes(t + 0x5e, bytes([c.rng.choice([0, 1]), c.rng.choice([0, 1])]))
    c.emu.wbytes(t + 0x50, (c.rng.choice([0, 0, 5, 0x1234, 0xffff])).to_bytes(2, 'little'))
    c.emu.wbytes(t + 0x52, (c.rng.choice([0, 0, 7, 0x4321, 0xffff])).to_bytes(2, 'little'))
    return [t, a]


S(0x508560, 'gs_flag_and_three_slots', 'thiscall', None, ret=None, gen=g508560, note='batch210046')
S(0x4af500, 'gs_toggle_state_by_slot', 'thiscall', None, ret=None, gen=g4af500, note='batch210046')
