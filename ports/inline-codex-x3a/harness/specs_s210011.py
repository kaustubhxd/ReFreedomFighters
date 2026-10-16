"""specs_s210011.py - Sonnet-w3a: engine-table chain family, global release, out-param call; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _chain(callee, off):
    def g(c):
        clear_hooks(c)
        t = rnd(c, 0x40)
        s = obj(c, 0x40, {0x3c: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20)
        a = rnd(c, 0x40); _ub(c, a + 0x15, s)
        m = obj(c, 0x40, {0x4c: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x30)
        eng = rnd(c, 0x100); _ub(c, eng + 0x9b, m)
        c.emu.w32(0x70039c, eng)
        hook_rec(c, callee, 2, ret=_r(c), this=True)
        return [t, a, _r(c)]
    return g


def g61fd10(c):
    clear_hooks(c)
    a = rnd(c, 0x120)

    def side(emu, k):
        emu.w32(emu.arg32(2), 0 if c.rng.random() < 0.4 else c.rng.getrandbits(32))
    hook_rec(c, 0x61dba0, 5, ret=_r(c), pop=0, deref={2: 1}, side=side)
    hook_rec(c, 0x620bc0, 4, ret=_r(c), pop=0)
    return [a, _r(c), _r(c), _r(c)]


def g545350(c):
    clear_hooks(c)
    c.emu.w32(0x711b8c, c.rng.choice([1, 1, 1, 2, 0, _r(c)]))
    dt = pystub(c, 1, ret=_r(c), this=True)
    for g in (0x711b84, 0x711b88):
        c.emu.w32(g, 0 if c.rng.random() < 0.3 else obj(c, 0x40, {0: dt}, nslots=4))
    eng = obj(c, 0x200, {0x1a8: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x80)
    c.emu.w32(0x70039c, eng)
    return []


for a, cl, off in [(0x50a600, 0x5fa590, 0xc), (0x506220, 0x50a600, 0x14), (0x55fb90, 0x506220, 0x18), (0x55edc0, 0x55fb90, 0x1c)]:
    S(a, 'chain_%x' % a, 'thiscall', None, ret='eax', gen=_chain(cl, off), note='batch210011')
S(0x61fd10, 'outparam_61dba0_then_620bc0', 'cdecl', None, ret='eax', gen=g61fd10, note='batch210011')
S(0x545350, 'release_two_globals', 'cdecl', None, ret=None, gen=g545350, note='batch210011')
