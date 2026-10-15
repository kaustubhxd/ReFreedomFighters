"""specs_s37121.py - cascade s6 batch 37121 (0x4fd160, thiscall(stream) ret 4, returns 1). The stream's slots 0x40 (id / index reads through a stack out pointer, scripted ids then
-1), 0x68 and 0x50 (writes into the node, bytes / dwords written deterministically) are logged per call through calllog; table slot 0x58 returns objects with a name (or none); the
allocator 0x41e290 returns spec blocks (or null); 0x6352f0 / 0x4fd510 are recording hooks; the logger gets one line per id."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g4fd160(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x6352f0, 1, this=True, stackmark=(0,))
    hook_rec(c, 0x4fd510, 1, this=True, stackmark=(0,))

    def lg(em, res_):
        em.calllog.append(('log', em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    objs = []
    for _ in range(3):
        o = rnd(c, 0x20)
        _w(c, o + 4, r.choice([0, 0x5000, 0x5100]))
        objs.append(o)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: objs[k % 3])}, table_size=0x60)
    n = r.choice([0, 1, 2, 3, 4])
    ids = [r.randrange(0, 50) for _ in range(n)] + [0xffffffff]
    idx = r.choice([0, 1, 2, 3, 7, 0xffffffff])
    seq = ids + [idx]

    def mark(v):
        return v if 0x20000000 <= v < 0x30000000 else 1

    def s40(em, k):
        em.calllog.append(('s40', k))
        em.w32(em.arg32(0), seq[min(k, len(seq) - 1)])

    def s68(em, k):
        em.calllog.append(('s68', mark(em.arg32(0)) if em.arg32(0) > 0x100 else em.arg32(0)))
        if em.arg32(0) > 0x100:
            em.wbytes(em.arg32(0), bytes([0x30 + k]))

    def s50(em, k):
        em.calllog.append(('s50', mark(em.arg32(0)) if em.arg32(0) > 0x100 else em.arg32(0)))
        if em.arg32(0) > 0x100:
            em.w32(em.arg32(0), 0x1000 + k)
    stream = obj(c, 0x20, {0x40: pystub(c, 1, this=True, stackmark=(0,), side=s40), 0x68: pystub(c, 1, this=True, side=s68),
                           0x50: pystub(c, 1, this=True, side=s50)})
    pool = [e.alloc(0x20, 4) for _ in range(6)]
    for p in pool:
        e.wbytes(p, bytes(r.getrandbits(8) for _ in range(0x20)))
    nullalloc = r.random() < 0.1
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: 0 if (nullalloc and k == 1) else pool[k % 6])
    t = rnd(c, 0x60)
    if r.random() < 0.3:
        # pre-existing list
        a = rnd(c, 0x20)
        _w(c, a + 0xc, 0)
        _w(c, t + 0x48, a)
        _w(c, t + 0x4c, a)
    else:
        _w(c, t + 0x48, 0)
        _w(c, t + 0x4c, 0)
    return [t, stream]


S(0x4fd160, 'GUESS load_entry_list', 'thiscall', None, ret='al', gen=_g4fd160, note='batch37121')
