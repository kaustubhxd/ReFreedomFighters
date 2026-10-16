"""specs_s210044.py - Sonnet-w3a: forward then iterate a stack cursor filled by slots; the stack-buffer stubs log the values they write."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g44a710(c):
    clear_hooks(c)
    cnt = c.rng.choice([0, 1, 2, 3])
    hook_rec(c, 0x45faf0, 3, ret=_r(c), this=True)

    def side4c(emu, k):
        p = emu.arg32(0)
        vals = [c.rng.getrandbits(32) for _ in range(3)]
        for i, v in enumerate(vals): emu.w32(p + 4 * i, v)
        emu.calllog.append(('buf', tuple(vals)))

    def side5c(emu, k):
        p = emu.arg32(0)
        emu.w32(p, (c.rng.getrandbits(32) | 1) if k + 1 < cnt else 0)
        emu.calllog.append(('buf0', emu.r32(p)))
    m = obj(c, 0x40, {0x4c: pystub(c, 1, ret=_r(c), this=True, stackmark=(0,), side=side4c),
                      0x5c: pystub(c, 1, ret=lambda e, k: c.rng.getrandbits(32), this=True, stackmark=(0,), side=side5c)}, nslots=0x20)
    objs = [0 if c.rng.random() < 0.3 else obj(c, 0x40, {0x138: pystub(c, 3, ret=_r(c), this=True)}, nslots=0x50) for _ in range(4)]
    mg = obj(c, 0x40, {0x58: pystub(c, 1, ret=lambda e, k: objs[k % 4], this=True)}, nslots=0x20)
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mg)
    c.emu.w32(0x70039c, eng)
    t = rnd(c, 0x40); c.emu.w32(t + 0x18, 0 if c.rng.random() < 0.15 else m)
    return [t, _r(c), _r(c), _r(c)]


S(0x44a710, 'forward_then_iterate_cursor', 'thiscall', None, ret=None, gen=g44a710, note='batch210044')
