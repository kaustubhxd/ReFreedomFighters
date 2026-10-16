"""specs_s210055.py - Sonnet-w3a: 0x4d7610. zlib wrappers hooked; side effects log only the z_stream words the function initialises (next_in, avail_in, next_out, avail_out, zalloc, zfree); inflate sets a random avail_out so the tail test is visible."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g4d7610(c):
    clear_hooks(c)
    e = c.emu

    def zlog(tag):
        def f(emu, k):
            z = emu.arg32(0)
            emu.calllog.append((tag, emu.r32(z), emu.r32(z + 4), emu.r32(z + 0xc), emu.r32(z + 0x10), emu.r32(z + 0x20), emu.r32(z + 0x24)))
        return f

    avo = c.rng.choice([0, 0, 1, 77])

    def zinf(emu, k):
        z = emu.arg32(0)
        emu.calllog.append(('inf', emu.r32(z), emu.r32(z + 4), emu.r32(z + 0xc), emu.r32(z + 0x10), emu.arg32(1)))
        emu.w32(z + 0x10, avo)
    hook_rec(c, 0x634d22, 3, ret=_r(c), pop=0)
    hook_rec(c, 0x62f9d0, 4, ret=c.rng.choice([0, 0, 0, 0xfffffffd]), pop=16, stackmark=(0,), side=zlog('init'))
    hook_rec(c, 0x62f5d0, 2, ret=c.rng.choice([1, 0xfffffffb, 0xfffffffb, 0, 2, 0xfffffffd]), pop=8, stackmark=(0,), side=zinf)
    hook_rec(c, 0x62f980, 1, ret=_r(c), pop=4, stackmark=(0,), side=zlog('end'))
    rep = obj(c, 0x40, {0x2c: pystub(c, 2, ret=_r(c), pop=0)}, nslots=0x20)
    g = obj(c, 0x40, {0x20: pystub(c, 2, ret=rep, this=True)}, nslots=0x20)
    e.w32(0x700390, g)
    s = rnd(c, 0x40)
    _ub(c, s + 1, rnd(c, 0x40)); _ub(c, s + 5, _r(c)); _ub(c, s + 9, c.rng.choice([0, 1, 5, 100, 0x7fffffff, 0x80000000, _r(c)]))
    _ub(c, s + 0x11, c.rng.choice([1, 1, 0, 2, 0x100000001]))
    b = c.rng.choice([0, 1, 5, 99, 100, 101, 0x7fffffff, 0x80000000, 0xffffffff, _r(c)])
    return [s, rnd(c, 0x20), b]


S(0x4d7610, 'copy_or_inflate_blob', 'thiscall', None, ret='al', gen=g4d7610, note='batch210055')
