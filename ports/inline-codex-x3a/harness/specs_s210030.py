"""specs_s210030.py - Sonnet-w3a: recursive table walk with callback, 13 field reads, out-param list loop, serializer; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _eng(c, mgr_obj):
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mgr_obj)
    c.emu.w32(0x70039c, eng)


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def g4e3dc0(c):
    clear_hooks(c)
    base = rnd(c, 0x80)
    n = 8
    for i in range(n):
        node = base + 6 * i
        cnt = c.rng.choice([0, 0, 1, 2])
        last = 0x8000 if (i == n - 1 or c.rng.random() < 0.35) else 0
        c.emu.wbytes(node, (((cnt << 3) | last | (_r(c) & 7))).to_bytes(2, 'little'))
        child = 0 if (i >= n - 2 or c.rng.random() < 0.5) else c.rng.randrange(i + 1, n)
        c.emu.wbytes(node + 2, child.to_bytes(2, 'little'))
        c.emu.wbytes(node + 4, c.rng.randrange(0, 3).to_bytes(2, 'little'))
    data = rnd(c, 0x400)
    ctx = rnd(c, 0x10)
    c.emu.w32(ctx, base); c.emu.w32(ctx + 4, data)
    c.emu.w32(ctx + 8, pystub(c, 0, ret=lambda e, k: c.rng.getrandbits(32), this=True))
    return [base + 6 * c.rng.choice([0, 0, 1]), ctx]


def g5d9810(c):
    clear_hooks(c)
    hook_rec(c, 0x4e5e60, 0, ret=lambda e, k: c.rng.getrandbits(32), this=True)
    return [rnd(c, 0x90), rnd(c, 0x20)]


def g603c80(c):
    clear_hooks(c)
    _assert_hook(c)
    cnt = c.rng.choice([0, 1, 2, 3])

    def side(emu, k):
        emu.w32(emu.arg32(0), cnt)
    a = obj(c, 0x40, {0x5c: pystub(c, 1, ret=_r(c), this=True, stackmark=(0,), side=side)}, nslots=0x30)
    t = rnd(c, 0x20)
    cap = c.rng.choice([1, 2, 3, 4, 8]); used = c.rng.choice([0, 1, 2, 3, 5])
    c.emu.w32(t + 0x10, cap); c.emu.w32(t + 0x14, used); c.emu.w32(t + 0xc, rnd(c, 0x80))
    hook_rec(c, 0x603c00, 1, ret=_r(c), this=True, deref={0: 1})
    hook_rec(c, 0x42ab62, 1, ret=_r(c), pop=0)
    hook_rec(c, 0x605940, 3, ret=_r(c), this=True)
    return [t, a, _r(c)]


def g5de430(c):
    clear_hooks(c)

    def side(emu, k):
        emu.w32(emu.arg32(0), c.rng.getrandbits(32))
    a = obj(c, 0x40, {0x18: pystub(c, 2, ret=_r(c), this=True), 0x40: pystub(c, 1, ret=_r(c), this=True, deref={0: 1}, side=side),
                      0x50: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20)
    _eng(c, obj(c, 0x40, {0x58: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20))
    return [rnd(c, 0x140), a]


S(0x4e3dc0, 'recursive_table_walk_callback', 'thiscall', None, ret=None, gen=g4e3dc0, note='batch210030')
S(0x5d9810, 'read_13_fields', 'thiscall', None, ret='eax', gen=g5d9810, note='batch210030')
S(0x603c80, 'outparam_count_loop_605940', 'thiscall', None, ret=None, gen=g603c80, note='batch210030')
S(0x5de430, 'serialize_with_local_lookup', 'thiscall', None, ret='eax', gen=g5de430, note='batch210030')
