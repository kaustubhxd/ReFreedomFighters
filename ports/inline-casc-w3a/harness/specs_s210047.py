"""specs_s210047.py - Sonnet-w3a: /GS rows: code table builder (pure memory), object recreate and string format call with stack buffers tagged by the stubs."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _log(tag): return lambda emu, k: emu.calllog.append((tag,))


def g630bb0(c):
    clear_hooks(c)
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    tree = rnd(c, 0x80)
    for n in range(8):
        c.emu.wbytes(tree + 4 * n + 2, c.rng.choice([0, 0, 1, 2, 3, 4, 5, 7, 9, 15]).to_bytes(2, 'little'))
    bl = rnd(c, 0x20)
    for i in range(16): c.emu.wbytes(bl + 2 * i, c.rng.choice([0, 1, 2, 3, 0xffff, c.rng.getrandbits(16)]).to_bytes(2, 'little'))
    return [tree, c.rng.choice([-1, 0, 1, 3, 5, 7]) & 0xffffffff, bl]


def g5124d0(c):
    clear_hooks(c)
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    hook_rec(c, 0x513d10, 0, ret=_r(c), this=True)

    def tag34(emu, k):
        emu.w32(emu.reg('ecx'), 0xC0DE0000 | c.rng.getrandbits(16))
    hook_rec(c, 0x4de7a0, 0, ret=_r(c), stackmark=(), side=tag34)

    def s1bc(emu, k):
        emu.calllog.append(('b', emu.r32(emu.arg32(1)), emu.r32(emu.arg32(2)), emu.r32(emu.arg32(2) + 4), emu.r32(emu.arg32(2) + 8)))
    r = obj(c, 0x40, {0x28: pystub(c, 0, ret=_r(c), this=True)}, nslots=0x20)
    m = None if c.rng.random() < 0.3 else obj(c, 0x40, {0x28: pystub(c, 0, ret=_r(c), this=True),
                                                      0x1bc: pystub(c, 7, ret=r, this=True, stackmark=(1, 2), side=s1bc)}, nslots=0x70)
    mg = rnd(c, 0xb00); c.emu.w32(mg + 0xadc, _r(c))
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mg)
    c.emu.w32(0x70039c, eng)
    t = obj(c, 0x140, {0x110: pystub(c, 2, ret=_r(c), this=True), 0x2c8: pystub(c, 2, ret=_r(c), this=True),
                       0x2e4: pystub(c, 0, ret=_r(c), this=True)}, nslots=0xc0)
    _ub(c, t + 0xce, _r(c))
    c.emu.w32(t + 0x134, m or 0)
    return [t]


def g5ab230(c):
    clear_hooks(c)
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))

    def s198(emu, k):
        emu.w32(emu.arg32(1), 0xBEEF0000 | c.rng.getrandbits(16))

    def s940(emu, k):
        emu.calllog.append(('loc', emu.r32(emu.arg32(0))))
    hook_rec(c, 0x5ac940, 1, ret=_r(c), this=True, stackmark=(0,), side=s940)
    hook_rec(c, 0x5acac0, 1, ret=_r(c), this=True)
    o = obj(c, 0x40, {0x198: pystub(c, 4, ret=_r(c), pop=0, stackmark=(1,), side=s198)}, nslots=0x70)
    eng = obj(c, 0x200, {0x190: pystub(c, 0, ret=o, this=True)}, nslots=0x70)
    c.emu.w32(0x70039c, eng)
    t = rnd(c, 0x650); c.emu.w32(t + 0x648, rnd(c, 0x20))
    return [t, _r(c)]


S(0x630bb0, 'build_code_table', 'cdecl', None, ret=None, gen=g630bb0, note='batch210047')
S(0x5124d0, 'gs_recreate_object', 'thiscall', None, ret=None, gen=g5124d0, note='batch210047')
S(0x5ab230, 'gs_format_into_local', 'thiscall', None, ret=None, gen=g5ab230, note='batch210047')
