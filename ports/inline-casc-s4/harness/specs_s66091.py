"""specs_s66091.py - cascade s4 batch 66091: 0x4a0440 (unregister an object from its owner lists, rewrite the follow-up chain, release two handles)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, reftab_vt


def _g4a0440(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4a1630, 1, this=True, pop=4)
    hook_rec(c, 0x49f8a0, 1, this=True, pop=4)
    hook_rec(c, 0x4dc630, 2, this=True, pop=8)
    ok = lambda p: 1 if r.random() < p else 0
    # --- the owner object T and the things it points to
    T = rnd(c, 0x140)
    path = r.choice([1, 1, 2, 3])        # 1: T[0x5e] set and list2 non-empty, 2: set but list2 empty, 3: T[0x5e] clear
    e.wbytes(T + 0x5e, bytes([1 if path < 3 else 0]))
    e.wbytes(T + 0x65, bytes([r.choice([0, 0, 1])]))
    # list1 at T+0x6a: count and up to two items (the next fields at 0x76/0x7a are the handles)
    n1 = r.choice([0, 1, 2])
    e.w32(T + 0x6a, n1)
    for i in range(n1):
        e.w32(T + 0x6e + 4 * i, r.getrandbits(32))
    # list2 at T+0x7e: count, items from T+0x82 (the first item is the copy object U)
    U = rnd(c, 0x120)
    n2 = r.choice([1, 2, 3]) if path == 1 else 0
    e.w32(T + 0x7e, n2)
    e.w32(T + 0x82, U)
    for i in range(1, n2):
        e.w32(T + 0x82 + 4 * i, r.getrandbits(32))
    # handles
    e.w32(T + 0x76, 0 if r.random() < 0.4 else r.getrandbits(32) | 1)
    e.w32(T + 0x7a, 0 if r.random() < 0.4 else r.getrandbits(32) | 1)
    # the list L at T+0x102 (count, items); T may be in it
    others = [rnd(c, 0x80) for _ in range(r.choice([0, 1, 2, 3]))]
    for o in others:
        e.wbytes(o + 0x5e, bytes([r.choice([0, 1, 1])]))
    items = list(others)
    if r.random() < 0.7:
        items.insert(r.randrange(len(items) + 1), T)
    if r.random() < 0.88:
        L = e.alloc(4 * (len(items) + 2), 4)
        e.w32(L, len(items))
        for i, it in enumerate(items):
            e.w32(L + 4 + 4 * i, it)
        e.w32(T + 0x102, L)
    else:
        e.w32(T + 0x102, 0)              # logs through the 0x700390 object
    # --- engine objects
    logobj = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=8)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, ret=logobj, this=True, pop=8)}))
    # object Z at 0x70038c: slot 0xcc(id) -> objects
    strs = []
    ref = bytes(e.rbytes(0x67a110, 16)).split(b'\0')[0]
    for variant in range(3):
        s = e.alloc(0x20, 4)
        txt = ref if variant == 0 else (ref[:1] + b'x' + ref[2:] if variant == 1 else b'q' + ref[1:])
        e.wbytes(s, txt + b'\0')
        strs.append(s)
    elems = [r.getrandbits(32) | 1 for _ in range(r.choice([0, 1, 2, 3]))]
    named = {}
    for el in elems:
        if r.random() < 0.8:
            v = r.choice(strs)
            named[el] = obj(c, 0x120, {0x14: pystub(c, 0, ret=(0 if r.random() < 0.1 else v), this=True, pop=0)})
    wid = r.getrandbits(32) | 1
    W = rnd(c, 0x40) if r.random() < 0.75 else 0
    objs = dict(named)
    objs[wid] = W

    def h_z(em, rr):
        k = em.arg32(0)
        em.calllog.append(('Z.cc', k))
        em.ret(objs.get(k, 0), 4)
    Z = obj(c, 0x20, {0xcc: e.stub_fn('Zcc', h_z)})
    e.w32(0x70038c, Z)
    # the name service chain: sys[0x9b] slot 0x138 -> Y, Y slot 0x88(name, &out)
    outv = wid if r.random() < 0.8 else 0

    def h_y(em, rr):
        em.calllog.append(('Y.88', em.arg32(0)))
        em.w32(em.arg32(1), outv)
        em.ret(0, 8)
    Y = obj(c, 0x20, {0x88: e.stub_fn('Y88', h_y)})
    # the owner/controller objects
    I = e.alloc(0x20, 4)
    e.w32(I, reftab_vt(c, list(elems)))
    P = rnd(c, 0x20)
    e.w32(P + 8, I if r.random() < 0.9 else 0)
    Oobj = obj(c, 0x20, {0x12c: pystub(c, 3, this=True, pop=12)})
    e.w32(Oobj + 0x10, P)
    e.w32(Oobj + 8, rnd(c, 0x20))
    e.w32(T + 0x44, Oobj)
    # tab2 at tab+0xadc: slot 0x25c(name, 0) -> E; E[0x18] slot 0x28(x); E slot 0x224(x)
    sub = obj(c, 0x20, {0x28: pystub(c, 1, ret=ok(0.6), this=True, pop=4)})
    E = obj(c, 0x40, {0x224: pystub(c, 1, this=True, pop=4)})
    e.w32(E + 0x18, sub)
    tab2 = obj(c, 0x20, {0x25c: pystub(c, 2, ret=(E if r.random() < 0.75 else 0), this=True, pop=8)})
    so = sysobj(c, slots={0xfc: pystub(c, 1, this=True, pop=4)},
                table_slots={0x138: pystub(c, 0, ret=Y, this=True, pop=0), 0x4c: pystub(c, 1, ret=r.getrandbits(32), this=True, pop=4)},
                table_size=0xb00)
    tab = e.r32(so + 0x9b)
    e.w32(tab + 0xadc, tab2 if r.random() < 0.8 else 0)
    e.w16(0x7002c4, r.getrandbits(16))
    e._image_dirty = True
    return [T]


S(0x4a0440, 'GUESS unregister object from its owner lists and release handles', 'thiscall', None, ret=None, gen=_g4a0440, note='batch66091')
