"""specs_s66089.py - cascade s4 batch 66089: 0x659000 (nested resource lookup through two engine services and the handle map; 0x63eab0 runs for real)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g659000(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    idv = r.choice([1, 5, 0xfff, 0x1005, 0xffff, r.getrandbits(16)])
    out = rnd(c, 0x20)
    mt = rnd(c, 0x4000)
    e.w32(mt + (idv & 0xfff) * 4, out)
    handle = rnd(c, 0x100)
    e.w32(handle + 0x68, mt)
    service = obj(c, 0x30, {0x20: pystub(c, 1, this=True, pop=0, ret=handle)})   # leaves its argument for 0x63eab0 (ret 4)
    manager = obj(c, 0x30, {0x80: pystub(c, 1, this=True, pop=4, ret=0)})
    sy = rnd(c, 0x2000)
    e.w32(sy + 0x190f, service)
    e.w32(sy + 0x1aa3, manager)
    e.w32(0x70039c, sy)
    e._image_dirty = True
    me = rnd(c, 0x40)
    outer = rnd(c, 0x30)
    e.w32(me + 0x10, outer)
    mode = r.randrange(5)
    if mode == 0:                                   # index 0: direct pointer chain
        e.w16(me + 0xa, 0)
        direct = rnd(c, 0x20)
        e.w32(outer + 0x10, direct)
        e.w32(direct + 0x10, out)
    elif mode == 1:                                 # no inner object
        e.w16(me + 0xa, r.choice([0, 1, 3]) or 1)
        e.w32(outer + 0x10, 0)
    else:
        index = r.choice([0x1, 0x1, 2, 5, 0x7fff, 0xffff]) if mode == 3 else r.choice([1, 2, 3, 7])
        e.w16(me + 0xa, index)
        inner = rnd(c, 0x40)
        data = rnd(c, 0x80)
        e.w32(outer + 0x10, inner)
        e.w32(inner + 0xc, data)
        e.w16(data + 0x40, idv)                      # used when no resolve step is needed (not reached with index != 0)
        arr = rnd(c, 4 * (index + 3)) if index < 0x100 else None
        if arr is None:
            arr = e.alloc(4 * index + 16, 4)
        e.w32(data + 0x3c, arr)
        resolved = rnd(c, 0x80)
        e.w16(resolved + 0x40, idv)
        e.w32(arr + 4 * index + 4, rnd(c, 0x20))
        e.w32(e.r32(manager) + 0x80, pystub(c, 1, this=True, pop=4, ret=(0 if r.random() < 0.2 else resolved)))
        if mode == 4 and r.random() < 0.5:
            e.w32(inner + 0xc, 0)                   # null data pointer: faults on both sides if reached
    return [me]


S(0x659000, 'GUESS resolve nested resource and handle map', 'thiscall', None, ret='eax', gen=_g659000, note='batch66089')
