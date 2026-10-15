"""specs_s66011.py - cascade s4 batch 66011: 0x49f9b0 (find a component by name and run its handler with the engine bracket)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g49f9b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    buf = e.alloc(0x40, 8)
    n = buf + 8
    e.w32(n - 4, r.choice([0, 0, 0x77, r.getrandbits(32)]))
    n_obj_vt = {0x5c: pystub(c, 3, this=True), 0xb0: pystub(c, 8, this=True)}
    vt = e.alloc(0x200, 4)
    for off, code in n_obj_vt.items():
        e.w32(vt + off, code)
    e.w32(n, vt)
    n2 = rnd(c, 0x10)       # object found by the second lookup
    e.w32(n2, vt)
    n2 = n2   # shares the vtable
    first = r.choice([n, n, 0])
    second = r.choice([n2, 0])
    this = obj(c, 0x20, {0x100: pystub(c, 1, this=True, ret=first), 0x10c: pystub(c, 2, this=True, ret=second)})
    used = first or second
    inrange = r.random() < 0.5
    gfp = pystub(c, 0, this=True, ret=r.getrandbits(32)) if r.random() < 0.8 else 0
    g = obj(c, 0x40, {0x20: pystub(c, 1, this=True, ret=r.choice([0, 0, 1, 0x100])),
                      0xac: pystub(c, 1, this=True), 0xcc: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    e.w32(g + 8, gfp)
    lo = used - r.choice([0, 0, 4]) if inrange else used + r.choice([1, 8])
    hi = used + r.choice([0, 1, 4, 0x100]) if inrange else used + r.choice([0, 4])
    e.w32(g + 0xc, lo & 0xffffffff)
    e.w32(g + 0x10, hi & 0xffffffff)
    e.w32(0x70038c, g)
    e._image_dirty = True
    return [this, r.getrandbits(32)] + [r.getrandbits(32) for _ in range(6)]


S(0x49f9b0, 'GUESS find a component and run its handler in an engine bracket', 'fastcall', None, ret=None, gen=_g49f9b0, note='batch66011')
