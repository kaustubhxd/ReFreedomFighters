"""specs_s35051.py - 0x4f2cf0 (thiscall(a, b, c) ret 0xc). Embedded list object at this+0x9f (unaligned vtable pointer; slots 0x4c, 0x44 (1 arg, out param flag-recorded), 0x64 (hands out 0..3 entry blocks then 0));
entries: [4] equals x in 3/5, [8] flag words (0, a, a | extra, random), byte [0x10] zero in half, [0xc] equals b in half; engine table slot 0x4c (1 arg) returns x."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g4f2cf0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    a = r.choice([1, 2, 4, 0x10, 0xff, r.getrandbits(32)])
    b = r.getrandbits(32)
    x = r.getrandbits(32)
    ents = []
    for _ in range(r.choice([0, 1, 2, 3])):
        p = rnd(c, 0x20)
        e.w32(p + 4, x if r.random() < 0.6 else r.getrandbits(32))
        e.w32(p + 8, r.choice([0, a, a, a | 0x100, a | (a << 1), r.getrandbits(32)]))
        if r.random() < 0.5:
            e.wbytes(p + 0x10, b'\0')
        e.w32(p + 0xc, b if r.random() < 0.5 else r.getrandbits(32))
        ents.append(p)
    lst = obj(c, 4, {0x4c: pystub(c, 1, nullflag=(0,), this=True), 0x44: pystub(c, 1, nullflag=(0,), this=True),
                     0x64: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: ents[k] if k < len(ents) else 0)}, nslots=0x1a)
    me = rnd(c, 0xa8)
    e.wbytes(me + 0x9f, e.r32(lst).to_bytes(4, 'little'))
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=x)})
    return [me, a, b, r.getrandbits(32)]


S(0x4f2cf0, 'GUESS clear flag mask on matching list entries', 'thiscall', None, ret=None, gen=_g4f2cf0, note='batch35051')
