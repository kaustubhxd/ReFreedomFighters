"""specs_s1114.py - collision thread batch 1114: ZBaseGeom::SetControl and LightNotifyPotentialDetachment.
The world comes from the batch 1113 generator (draw lists, rooms, class chains; Attach/Detach run as exe code); the
render manager gets a vtable with slots 0x178 (busy) and 0x40 (lighting on), and a light manager at +0x5d35 with
slots 0x24 (register, returns a handle), 0x28 (unregister) and 8 (list lights: writes a count through its first
arg and returns an array of light geoms)."""
from pilot import S, F
from specs_s1110 import _vt
from specs_s1113 import _att, _bound


def _lights(c):
    e, r = c.emu, c.rng
    n = r.choice([0, 1, 3])
    arr = e.alloc(4 * n + 4, 4)
    for i in range(n):
        lg = e.alloc(0x70, 4)
        e.w32(lg + 0x3c, r.getrandbits(32))
        e.w8(lg + 0x58, r.choice([0, 1, 5, 0xff]))
        e.w32(arr + 4 * i, lg)

    def lst(em, a):
        em.w32(a[0], n)
        return arr, a[1]
    return lst


def _world_lights(c):
    e, r = c.emu, c.rng
    rm = e.r32(e.r32(0x70039c) + 0x9b)
    c.vars['busy'] = r.choice([0, 0, 0, 1, 0x100])
    c.vars['lit'] = r.choice([1, 1, 1, 0, 0x100])
    e.w32(rm, _vt(c, 'rm', {0x178: (0, lambda em, a: (c.vars['busy'], ())),
                           0x40: (0, lambda em, a: (c.vars['lit'], ()))}, 0x17c // 4))
    L = 0
    if r.random() < 0.85:
        L = e.alloc(0x10, 4)
        c.vars['h'] = r.getrandbits(32)
        e.w32(L, _vt(c, 'lights', {0x24: (1, lambda em, a: (c.vars['h'], a[0])), 0x28: (1, lambda em, a: (0, a[0])),
                                    8: (2, _lights(c))}, 0x2c // 4))
    e.w32(rm + 0x5d35, L)


def _sc(c):
    e, r = c.emu, c.rng
    g, room = _att(c)
    _world_lights(c)
    f = e.r32(g + 0x3c)
    f ^= r.choice([0, 0x2000, 0x8000, 0x8000000, 0x8008000])
    e.w32(g + 0x3c, f)
    e.w32(g + 0x6c, r.choice([0, 1, r.getrandbits(32)]))
    e.w8(g + 0x58, r.choice([0, 1]))
    if r.random() < 0.6:   # a light-receiving class
        e.w32(g + 0x54, _bound(c, [r.choice([0x200000, 0x800000, 0xa00000, 0x800002])]))
    bits = [0x2000, 0x8000, 0xff, 0x1, 0x80, 0x100, 0x10000]
    st = 0
    mk = 0
    for b in bits:
        if r.random() < 0.3:
            st |= b
        if r.random() < 0.3:
            mk |= b
    if r.random() < 0.2:
        st = r.getrandbits(32)
    return [g, st, mk]


def _ln(c):
    e, r = c.emu, c.rng
    sysobj = e.alloc(0x200, 4)
    e.w32(0x70039c, sysobj)
    e._image_dirty = True
    rm = e.alloc(0x5e00, 4)
    e.w32(sysobj + 0x9b, rm)
    _world_lights(c)
    g = e.alloc(0x70, 4)
    e.wbytes(g, bytes(r.getrandbits(8) for _ in range(0x70)))
    e.w8(g + 0x58, r.choice([0, 1, 2]))
    return [g, r.getrandbits(32) & r.choice([0xff, 0xffffff00, 1, 0])]


S(0x4dbb00, 'ZBaseGeom::LightNotifyPotentialDetachment', 'thiscall', None, gen=_ln, note='batch1114')
S(0x4dc630, 'ZBaseGeom::SetControl', 'thiscall', None, gen=_sc, note='batch1114')
