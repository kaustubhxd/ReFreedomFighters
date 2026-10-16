"""specs_s210019.py - Sonnet-w3a: buffer read with clamp, flag lookup chain, grow-copy, state reset, bool-compare loop; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def g4d5310(c):
    clear_hooks(c)
    _assert_hook(c)
    t = rnd(c, 0x20)
    buf = rnd(c, 0x40)
    pos = c.rng.randrange(0, 8); end = pos + c.rng.randrange(0, 8)
    c.emu.w32(t + 4, buf); c.emu.w32(t + 8, pos); c.emu.w32(t + 0xc, end)
    hook_rec(c, 0x634d22, 3, ret=_r(c), pop=0)
    cc = t + 4 if c.rng.random() < 0.75 else rnd(c, 0x10)
    return [t, rnd(c, 0x20), c.rng.choice([0, 1, 2, 3, 5, 8, 20, _r(c)]), cc]


def g55ff50(c):
    clear_hooks(c)
    a = rnd(c, 0x10); c.emu.w32(a + 4, rnd(c, 0x20)); c.emu.w32(a + 8, rnd(c, 0x20))
    r1 = rnd(c, 8)
    if c.rng.random() < 0.3: c.emu.w32(r1, 0)
    o = 0 if c.rng.random() < 0.25 else obj(c, 0x40, {0x1e0: pystub(c, 1, ret=c.rng.choice([0, 1, 0x100, _r(c)]), this=True)}, nslots=0x80)
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, obj(c, 0x40, {0x58: pystub(c, 1, ret=o, this=True)}, nslots=0x20))
    c.emu.w32(0x70039c, eng)
    hook_rec(c, 0x5003d0, 1, ret=lambda e, k: r1 if k == 0 else rnd(c, 8), this=True)
    hook_rec(c, 0x5002f0, 1, ret=_r(c), this=True)
    return [a]


def g5ff0a0(c):
    clear_hooks(c)
    n = c.rng.choice([0, 1, 2, 3, 6])
    old = rnd(c, 0x20)
    t = rnd(c, 0x10); c.emu.w32(t, old); c.emu.w32(t + 4, n)
    hook_rec(c, 0x41e290, 1, ret=lambda e, k: rnd(c, 0x40), pop=0)
    hook_rec(c, 0x41e2c0, 1, ret=_r(c), pop=0)
    return [t]


def g47bf10(c):
    clear_hooks(c)

    def side(emu, k):
        emu.calllog.append(('st', emu.r32(t + 0x695) if False else emu.rbytes(t + 0x695, 4), emu.rbytes(t + 0x722, 4)))
    t = obj(c, 0x740, {0x628: pystub(c, 3, ret=_r(c), this=True), 0x5f4: pystub(c, 0, ret=_r(c), this=True), 0x5f8: pystub(c, 0, ret=_r(c), this=True)}, nslots=0x200)
    if c.rng.random() < 0.5: c.emu.wbytes(t + 0x695, bytes(4))
    hook_rec(c, 0x478ea0, 2, ret=_r(c), this=True, side=side)
    return [t, rnd(c, 0x20), c.rng.choice([0, 1, 0x100, 0x1ff, _r(c)])]


def g5c2f90(c):
    clear_hooks(c)
    t = rnd(c, 0x2d0)
    if c.rng.random() < 0.2: c.emu.w32(t + 4, 0)
    n = c.rng.choice([0, 1, 2, 3, 4, 0xffffffff])
    c.emu.w32(t + 0x2c0, n)
    for i in range(4):
        c.emu.wbytes(t + 0x14 + 0xe * i, bytes([c.rng.choice([0, 1]), c.rng.choice([0, 1])]))
    hook_rec(c, 0x5b0b70, 1, ret=lambda e, k: c.rng.choice([0, 0, 1, 5]), this=True)
    hook_rec(c, 0x5c2c10, 1, ret=_r(c), this=True)
    return [t]


S(0x4d5310, 'read_clamped_or_assert', 'thiscall', None, ret='eax', gen=g4d5310, note='batch210019')
S(0x55ff50, 'flag_lookup_chain', 'stdcall', None, ret='eax', gen=g55ff50, note='batch210019')
S(0x5ff0a0, 'double_word_buffer', 'thiscall', None, ret='eax', gen=g5ff0a0, note='batch210019')
S(0x47bf10, 'reset_state_slots', 'thiscall', None, ret='eax', gen=g47bf10, note='batch210019')
S(0x5c2f90, 'bool_compare_loop', 'thiscall', None, ret=None, gen=g5c2f90, note='batch210019')
