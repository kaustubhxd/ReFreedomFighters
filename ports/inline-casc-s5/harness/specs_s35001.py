"""specs_s35001.py - 0x5e9ce0. Object with vtable slot 0x90 (recorded), +0x1d0f (unaligned) -> state object (null in 1/6, byte +0x3c6 zero in half),
+0x1d0b -> object with slots 0x3dc (0 args) and 0x4dc (2 args). Hooked: 0x4f9680, 0x5ab1e0, 0x5ab2a0 (1 arg, this), 0x5e9b70 (0 args, zero in 1/3)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g5e9ce0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = obj(c, 0x1d40, {0x90: pystub(c, 0, this=True)})
    if r.random() < 1 / 6:
        st = 0
    else:
        st = rnd(c, 0x400)
        if r.random() < 0.5:
            e.wbytes(st + 0x3c6, b'\0')
    e.wbytes(me + 0x1d0f, st.to_bytes(4, 'little'))
    o2 = obj(c, 0x40, {0x3dc: pystub(c, 0, this=True), 0x4dc: pystub(c, 2, this=True)})
    e.wbytes(me + 0x1d0b, o2.to_bytes(4, 'little'))
    hook_rec(c, 0x4f9680, 1, this=True)
    hook_rec(c, 0x5ab1e0, 1, this=True)
    hook_rec(c, 0x5ab2a0, 1, this=True)
    hook_rec(c, 0x5e9b70, 0, this=True, ret=0 if r.random() < 1 / 3 else r.getrandbits(32))
    return [me, r.choice([0, 0, 1, 2, 0x100, 0x101, r.getrandbits(32)])]


S(0x5e9ce0, 'GUESS toggle state object mode', 'thiscall', None, ret=None, gen=_g5e9ce0, note='batch35001')
