"""specs_s210049.py - Sonnet-w3a: /GS formatter with failure report; slot 0 of the string table is called twice with two args (callee pops 8) leaving extra dwords as args of the cdecl format call."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _log(tag): return lambda emu, k: emu.calllog.append((tag,))


def g56d750(c):
    clear_hooks(c)
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))

    def sbuf(emu, k):
        emu.w32(emu.arg32(1), 0xFEED0000 | c.rng.getrandbits(16))

    def s563(emu, k):
        emu.calllog.append(('buf', emu.r32(emu.arg32(1))))
    hook_rec(c, 0x563710, 2, ret=_r(c), this=True, stackmark=(1,), side=s563)
    f = c.rng.choice([0, 1, 0xfffffffe, 0x80000000, 0x7fffffff])
    o = obj(c, 0x40, {0x198: pystub(c, 6, ret=f, pop=0, stackmark=(1,), side=sbuf), 0x20: pystub(c, 0, ret=0, this=True)}, nslots=0x70)
    rep = obj(c, 0x40, {0x2c: pystub(c, 2, ret=_r(c), pop=0)}, nslots=0x20)
    g = obj(c, 0x40, {0x20: pystub(c, 2, ret=rep, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, g)
    st = obj(c, 0x40, {0: pystub(c, 2, ret=lambda e, k: c.rng.getrandbits(32), this=True)}, nslots=4)
    mg = rnd(c, 0xb00); c.emu.w32(mg + 0xae4, st)
    eng = obj(c, 0x200, {0x190: pystub(c, 0, ret=o, this=True)}, nslots=0x70)
    _ub(c, eng + 0x9b, mg)
    c.emu.w32(0x70039c, eng)
    t = rnd(c, 0x1c0); _ub(c, t + 0x1b6, c.rng.choice([0, 1, 5, _r(c)]))
    return [t]


S(0x56d750, 'gs_format_with_report', 'thiscall', None, ret=None, gen=g56d750, note='batch210049')
