"""specs_s38004.py - cascade s8 batch 38004: 0x651380 (per-frame step). Engine object (0x70039c) with slot 0x1b0 returning either 0 or a helper object (slots 0xc,
0x2c, 0x0 recorded); the object's own slots are recording stubs returning random values (low byte sometimes 0 with high bits set); 0x6511d0 / 0x6500b0 / 0x651180
and the memset thunk 0x634d10 are hooked; loop bounds at +0x78/+0x7c are small."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g651380(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def rb(em, k):
        return r.choice([0, 1, 0x100, 0x101, 0xff00, r.getrandbits(32)])

    def rs(em, k):
        return r.randrange(0, 6)
    helper = obj(c, 0x20, {0xc: pystub(c, 0, this=True, ret=rb), 0x2c: pystub(c, 0, this=True), 0: pystub(c, 0, this=True)})
    pick = r.choice([0.0, 0.5, 1.0])
    so = sysobj(c, {0x1b0: pystub(c, 0, this=True, ret=lambda em, k: helper if r.random() < pick else 0)})
    if r.random() < 0.85:
        e.wbytes(so + 0x1a9a, bytes([r.choice([1, 2, 0xff])]))
    else:
        e.wbytes(so + 0x1a9a, bytes([0]))
    slots = {0x24: pystub(c, 0, this=True, ret=rb), 0xd0: pystub(c, 0, this=True), 0x84: pystub(c, 0, this=True),
             0x10c: pystub(c, 1, this=True), 0x110: pystub(c, 0, this=True), 0x70: pystub(c, 0, this=True),
             0x128: pystub(c, 2, pop=0), 0xf0: pystub(c, 0, this=True, ret=rs), 0xec: pystub(c, 0, this=True, ret=rs),
             0x6c: pystub(c, 3, this=True), 0x1a4: pystub(c, 0, this=True, ret=rb), 0x120: pystub(c, 1, this=True),
             0x1b8: pystub(c, 0, this=True), 0x28: pystub(c, 0, this=True), 0x50: pystub(c, 0, this=True)}
    me = obj(c, 0x100, slots)
    e.wbytes(me + 0x33, bytes([r.choice([1, 1, 1, 0, 7])]))
    e.wbytes(me + 0x80, bytes([r.choice([0, 1, 2])]))
    e.w32(me + 0x78, r.randrange(0, 5))
    e.w32(me + 0x7c, r.randrange(0, 7))
    e.w32(me + 0x74, rnd(c, 0x40))
    for a in (0x6511d0, 0x6500b0, 0x651180):
        hook_rec(c, a, 0, this=True, ret=rb)
    hook_rec(c, 0x634d10, 3, pop=0)
    return [me]


S(0x651380, 'GUESS per-frame step', 'thiscall', None, ret=None, gen=_g651380, note='batch38004')
