"""specs_s67520.py - cascade s6 batch 67520 (0x55aec0, thiscall(a) ret 4). Hooked 0x5003d0 (call order: result node, direction node, result node again) and 0x5002f0; the owner's
object list at [+0x1c]+0x921 (count + object pointers; the owner may be listed); each object has slots 0x438 (bool), 0x20 (record with +8 -> block whose +0x3c carries flag bit 10), 0x674 /
0x6a8 (scores around the owner's); the owner's own slots 0x674 / 0x6a8; table slot 0x4c."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g55aec0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0x60)
    base_val = r.choice([0, 1, 3, 5, 0xffffffff])

    def sc():
        return lambda em, k: r.choice([0xffffffff, 0, 1, 2, 3, 4, 5, 6, 7, 0x80000000])
    oflags = rnd(c, 0x50)
    _w(c, oflags + 0x3c, r.choice([0, 0x400]))
    oblk = rnd(c, 0x20)
    _w(c, oblk + 8, oflags)
    owner = obj(c, 0x940, {0x674: pystub(c, 0, this=True, ret=base_val), 0x6a8: pystub(c, 0, this=True, ret=base_val),
                           0x438: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0, 1])), 0x20: pystub(c, 0, this=True, ret=oblk)})
    objs = []
    for _ in range(r.choice([0, 1, 2, 3, 5])):
        flags = rnd(c, 0x50)
        _w(c, flags + 0x3c, r.choice([0, 0x400, 0xfffff, 0xfffffbff]))
        blk = rnd(c, 0x20)
        _w(c, blk + 8, flags)
        rec = blk
        o = obj(c, 0x20, {0x438: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0, 1, 0x100])),
                          0x20: pystub(c, 0, this=True, ret=rec), 0x674: pystub(c, 0, this=True, ret=sc()), 0x6a8: pystub(c, 0, this=True, ret=sc())})
        objs.append(o)
    if objs and r.random() < 0.3:
        objs[r.randrange(len(objs))] = owner
        # the owner appears in its own list: it needs the scoring slots, flags record etc.; use a fresh object instead of a bare owner
    lst = e.alloc(4 * (len(objs) + 2), 4)
    _w(c, lst, len(objs))
    for i, o in enumerate(objs):
        _w(c, lst + 4 + 4 * i, o)
    _w(c, owner + 0x921, lst if r.random() < 0.9 else 0)
    this = rnd(c, 0x40)
    _w(c, this + 0x1c, owner)
    res = rnd(c, 0x10)
    dn = rnd(c, 0x10)
    _w(c, dn, r.choice([0, 1, 1, 2, 0x100]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: dn if k == 1 else res)
    hook_rec(c, 0x5002f0, 1, this=True)
    a = rnd(c, 0x10)
    _w(c, a + 4, rnd(c, 0x10))
    _w(c, a + 8, rnd(c, 0x10))
    return [this, a]


S(0x55aec0, 'GUESS pick_neighbour', 'thiscall', None, ret=None, gen=_g55aec0, note='batch67520')
