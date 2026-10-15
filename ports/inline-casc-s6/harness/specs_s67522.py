"""specs_s67522.py - cascade s6 batch 67522 (0x4b4040, thiscall(list, flag) ret 8). The iterator at list+0x18 yields scripted keys (slot 0x5c with an out count); map 1 (embedded at
+0x10e, lookup slot 0x2c, erase 0x3c) returns reference-counted entries for some keys; map 2 (embedded at +0xf2, slots 0x4c / 0x64 / 0x3c) is walked as a node chain whose +0xc is the key;
reference counts are 1 or 2; the table object's slot 0x54 gives a handle (or 0); 0x4b6b90 / 0x4b6e00 are recording hooks. Every slot call is logged through calllog."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g4b4040(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 4])
    keys = [r.randrange(1, 6) for _ in range(n)]
    st = {'i': 0}

    def s5c(em, k):
        i = st['i']
        st['i'] += 1
        em.calllog.append(('it5c', i))
        em.w32(em.arg32(0), 1 if i < n else 0)
        return keys[i] if i < n else 0
    itvt = e.alloc(0x80, 4)
    e.w32(itvt + 0x4c, pystub(c, 1, this=True, stackmark=(0,)))
    e.w32(itvt + 0x5c, pystub(c, 1, this=True, stackmark=(0,), side=lambda em, k: s5c(em, k) and None, ret=lambda em, k: keys[k] if k < n else 0))
    itobj = rnd(c, 0x20)
    _w(c, itobj, itvt)
    ent = {}
    for kk in range(1, 6):
        if r.random() < 0.5:
            en = rnd(c, 0x20)
            _w(c, en, kk * 100)
            _w(c, en + 8, r.choice([1, 1, 2]))
            ent[kk] = en
    nodes = []
    for kk in range(1, 6):
        if r.random() < 0.5:
            nd = rnd(c, 0x20)
            _w(c, nd, kk * 1000)
            _w(c, nd + 8, r.choice([1, 1, 2]))
            _w(c, nd + 0xc, kk)
            nodes.append(nd)
    r.shuffle(nodes)
    pos = {'i': 0}

    def m1_2c(em, k):
        return ent.get(em.arg32(0), 0)

    def m2_4c(em, k):
        pos['i'] = 0

    def m2_64(em, k):
        i = pos['i']
        pos['i'] += 1
        return nodes[i] if i < len(nodes) else 0
    vt1 = e.alloc(0x80, 4)
    e.w32(vt1 + 0x2c, pystub(c, 1, this=True, ret=m1_2c))
    e.w32(vt1 + 0x3c, pystub(c, 1, this=True))
    vt2 = e.alloc(0x80, 4)
    e.w32(vt2 + 0x4c, pystub(c, 1, this=True, stackmark=(0,), side=m2_4c))
    e.w32(vt2 + 0x64, pystub(c, 1, this=True, stackmark=(0,), ret=m2_64))
    e.w32(vt2 + 0x3c, pystub(c, 1, this=True))
    sysobj(c, table_slots={0x54: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 0x1234]))}, table_size=0x60)
    hook_rec(c, 0x4b6b90, 1, this=True)
    hook_rec(c, 0x4b6e00, 2, this=True)
    t = rnd(c, 0x120)
    _w(c, t + 0x10e, vt1)
    _w(c, t + 0xf2, vt2)
    lst = rnd(c, 0x30)
    _w(c, lst + 0x18, itobj if r.random() < 0.93 else 0)
    return [t, lst, r.choice([0, 1, 1, 0x100, 0xff])]


S(0x4b4040, 'GUESS release_keys', 'thiscall', None, ret=None, gen=_g4b4040, note='batch67522')
