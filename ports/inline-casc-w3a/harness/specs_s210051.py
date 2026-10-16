"""specs_s210051.py - Sonnet-w3a: 0x50bf60. Two cursor lookups (0x5003d0, hooked, return a distinct cell), manager slot 0x58, capability slot 0x1e0, toggle slot 0x210, error reports through the [0x700390] object (slot 0x2c is cdecl with 2 args or 3 args, so a custom stub logs by path)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g50bf60(c):
    clear_hooks(c)
    e = c.emu
    cells = [rnd(c, 0x10) for _ in range(3)]
    n = [0]

    def side3(emu, k):
        emu.calllog.append(('c3', k, emu.reg('ecx')))
    hook_rec(c, 0x5003d0, 1, ret=lambda emu, k: cells[min(k, 2)], this=True, side=side3)
    hook_rec(c, 0x5002f0, 1, ret=_r(c), this=True)

    def rep_fn(emu, res):
        a1 = emu.arg32(1)
        if a1 == 0x69d5dc:
            emu.calllog.append(('rep2', emu.arg32(0), a1))
        else:
            emu.calllog.append(('rep3', emu.arg32(0), a1, emu.arg32(2)))
        emu.ret(eax=0, argbytes=0)
    rep = obj(c, 0x40, {0x2c: e.stub_fn('rep', rep_fn)}, nslots=0x20)
    g = obj(c, 0x40, {0x20: pystub(c, 2, ret=rep, this=True)}, nslots=0x20)
    e.w32(0x700390, g)
    found = c.rng.choice([True, True, True, False])
    cap = c.rng.choice([0, 1, 0x1ff01, 0x80, 0x100, 0xff00])
    tgt = obj(c, 0x40, {0x1e0: pystub(c, 1, ret=cap, this=True), 0x210: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x90)
    mg = obj(c, 0x40, {0x58: pystub(c, 1, ret=tgt if found else 0, this=True)}, nslots=0x20)
    so = rnd(c, 0x200)
    e.w32(so + 0x9b, mg) if False else e.wbytes(so + 0x9b, mg.to_bytes(4, 'little'))
    e.w32(0x70039c, so)
    p = rnd(c, 0x20)
    e.w32(p + 4, rnd(c, 0x10)); e.w32(p + 8, rnd(c, 0x10))
    return [p]


S(0x50bf60, 'toggle_via_cells', 'stdcall', None, ret=None, gen=g50bf60, note='batch210051')
