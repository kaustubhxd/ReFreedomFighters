"""specs_s850.py - area 50, batch 850: ZActionControlMap::GenerateGameActionsPC (0x5b37e0), thiscall, no args.
Stand-ins (hooked, logged): the record fill 0x596710 (writes 0x74 bytes), the item-type query 0x591b20 (returns a value
in 0..9), the sound play 0x4f9680. The objects: the control map (+0x5b: vt +0x90; +0x1d0f: record owner), the item
(+0x5f: vt +0x3dc and +0x4dc; words +0x832, +0x836), the engine's manager (+0x1907: vt +0x2c answers true for at most one
of the ten ids, chosen at generation time). The cursor at +0x18a is generated in 0..9 (the game keeps it there)."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    ids = []
    while len(ids) < 10:
        v = r.getrandbits(32) | 1
        if v not in ids:
            ids.append(v)
    hit = r.choice([-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 9])

    def m2c(e, rr):
        a = e.arg32(0)
        e.calllog.append(('mgr.2c', a))
        e.ret(eax=1 if (hit >= 0 and a == ids[hit]) else 0, argbytes=8)

    rec = bytes(r.getrandbits(8) for _ in range(0x70))   # the exe frame keeps its cookie at +0x70 (ebp-4): the fill stops short of it
    ret591 = r.randint(0, 9)

    def fill(e, rr):
        p = e.arg32(0)
        e.wbytes(p, rec)
        e.calllog.append(('rec.596710', e.reg('ecx')))
        e.ret(eax=0, argbytes=4)

    def q591(e, rr):
        e.calllog.append(('item.591b20',))
        e.ret(eax=ret591, argbytes=0)

    def play(e, rr):
        e.calllog.append(('sound.4f9680', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def v90(e, rr):
        e.calllog.append(('cmap.90',))
        e.ret(eax=0, argbytes=0)

    def v3dc(e, rr):
        e.calllog.append(('item.3dc',))
        e.ret(eax=0, argbytes=0)

    def v4dc(e, rr):
        e.calllog.append(('item.4dc', e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8)

    only_hooks(c, {0x596710: fill, 0x591b20: q591, 0x4f9680: play})
    mgr = vt_object(c, 0x40, {0x2c: m2c}, nslots=0x20, name='mgr1907')
    g = rnd(c, 0x1b00)
    e.w32(g + 0x1907, mgr)
    e.w32(0x70039c, g)

    item = vt_object(c, 0x1000, {0x3dc: v3dc, 0x4dc: v4dc}, nslots=0x140, name='item')
    e.w32(item + 0x832, 0 if r.random() < 0.7 else r.getrandbits(32))
    e.w32(item + 0x836, 0 if r.random() < 0.8 else r.getrandbits(32))
    cmap_vt = vt_object(c, 0x40, {0x90: v90}, nslots=0x60, name='cmap_rec')
    rec_owner = rnd(c, 0x40)
    cmap = rnd(c, 0x2000)
    rb = vt_object(c, 0x2000, {0x90: v90}, nslots=0x60, name='cmap')
    e.w32(rb + 0x1d0f, rec_owner)
    e.w32(cmap + 0x5b, rb)
    e.w32(cmap + 0x5f, item)
    e.w32(cmap + 0x4d, 3 if r.random() < 0.3 else r.getrandbits(8))
    for off in (0x175, 0x17f, 0x180):
        e.w8(cmap + off, r.getrandbits(8) if r.random() < 0.5 else 0)
    e.w8(cmap + 0x1a3, 0 if r.random() < 0.8 else 1)
    e.w8(cmap + 0x18a, r.randint(0, 9))
    for i, off in enumerate((0xf3, 0xf7, 0xfb, 0xff, 0x103, 0x107, 0x10b, 0x10f, 0x113, 0x117)):
        e.w32(cmap + off, ids[i])
    return [cmap]


S(0x5b37e0, 'ZActionControlMap::GenerateGameActionsPC', 'thiscall', None, gen=_gen, note='area50 batch850')
