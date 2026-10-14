"""specs_s34012.py - cascade tier E, batch 34012: 0x42d2e0 / 0x42d360 (flag-vector append). The object's vtable slot 0x8c is a recorder returning 0 or 1 (random
high bytes); the vector header {begin, end, cap} sits behind the unaligned pointer at +0x1b61. Cases: end == cap (grow through the hooked 0x4301c0,
which records ecx, the position and the value), end != cap, end == 0 (only when the predicate makes the original skip the read of [end-4]);
the previous element is zero in half the cases."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _gen(invert):
    def g(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, 0x4301c0, 2, ret=r.getrandbits(32), this=True, deref={1: 1})
        vec = rnd(c, 0x20)
        buf = rnd(c, 0x40)
        k = r.random()
        if k < 0.1:
            end = 0
            cap = buf + 0x30
        elif k < 0.4:
            end = buf + 8
            cap = end
        else:
            end = buf + 8
            cap = buf + 0x30
        c.emu.w32(vec + 4, end)
        c.emu.w32(vec + 8, cap)
        if end:
            c.emu.w32(end - 4, 0 if r.random() < 0.5 else r.getrandbits(32) or 1)
            al = r.choice([0, 1])
        else:
            al = 0 if not invert else 1
        ret = al | (r.getrandbits(24) << 8)
        me = obj(c, 0x1c00, {0x8c: pystub(c, 1, ret=ret, this=True)})
        c.emu.wbytes(me + 0x1b61, vec.to_bytes(4, 'little'))
        return [me, r.getrandbits(32)]
    return g


S(0x42d2e0, 'GUESS flag vector append (pred && prev)', 'thiscall', None, ret='eax', gen=_gen(False), note='batch34012')
S(0x42d360, 'GUESS flag vector append (!pred && prev)', 'thiscall', None, ret='eax', gen=_gen(True), note='batch34012')
