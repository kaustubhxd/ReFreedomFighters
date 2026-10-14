"""specs_s34139.py - 0x589980: count +0x38 in 0..16 (16 in a third), set at +0x3c with distinct random values; v present (any index) in a third; hooked 0x58a320 (plain; in half the cases it drops the count to 0xf); logger 0x700390 slot 0x20 -> printer with a cdecl slot 0x2c recorder.
0x5af3a0: this +0/+4/+8 (null in a fifth each), hooked 0x5af130 (returns null, a cell with zero, or a cell with a value) and 0x5af300; [this+8] slot 0x98 (2 args); table [0x70039c]+0x9b slot 0x58 (1 arg, null in a third)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _logger(c):
    pr = obj(c, 0x20, {0x2c: pystub(c, 2, pop=0)}, nslots=0x30 // 4)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=pr, this=True)}, nslots=0x24 // 4)
    c.emu.w32(0x700390, lg)


def _g589980(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _logger(c)
    n = r.choice([0, 1, 5, 15, 16, 16, 16])
    me = rnd(c, 0x80)
    vals = [r.getrandbits(32) | 1 for _ in range(16)]
    e.w32(me + 0x38, n)
    for i, v in enumerate(vals):
        e.w32(me + 0x3c + 4 * i, v)
    v = vals[r.randrange(16)] if r.random() < 0.35 else r.getrandbits(32) | 1
    if r.random() < 0.1 and n:
        v = vals[n - 1]

    def comp(em, k):
        if r.random() < 0.5:
            em.w32(em.reg('ecx') + 0x38, 0xf)
    hook_rec(c, 0x58a320, 0, this=True, pop=0, side=comp)
    return [me, v]


def _g5af3a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _logger(c)
    cell0 = rnd(c, 0x10)
    e.w32(cell0, 0)
    cell1 = rnd(c, 0x10)
    e.w32(cell1, r.getrandbits(32) | 1)
    hook_rec(c, 0x5af130, 1, this=True, ret=lambda em, k: r.choice([0, cell0, cell1, cell1]))
    hook_rec(c, 0x5af300, 1, this=True, ret=r.getrandbits(32))
    w = obj(c, 0x20, {0x98: pystub(c, 2, this=True, ret=lambda em, k: r.getrandbits(32))}, nslots=0x9c // 4)
    tbl = obj(c, 0x20, {0x58: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, r.getrandbits(32)]))}, nslots=0x5c // 4)
    so = rnd(c, 0xa0)
    e.w32(so + 0x9b, tbl)
    e.w32(0x70039c, so)
    me = rnd(c, 0x10)
    for off, v in ((0, 1), (4, rnd(c, 0x10)), (8, w)):
        e.w32(me + off, 0 if r.random() < 0.2 else v)
    return [me, r.getrandbits(32)]


S(0x589980, 'GUESS add to a 16-slot set', 'thiscall', None, ret=None, gen=_g589980, note='batch34139')
S(0x5af3a0, 'GUESS resolve a name to an object', 'thiscall', None, ret='eax', gen=_g5af3a0, note='batch34139')
