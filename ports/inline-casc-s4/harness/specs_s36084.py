"""specs_s36084.py - cascade s4 batch 36084: 0x456ab0 (find an id by name through an iterator), 0x4a7b50 (key down / up handler)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, reftab


def _g456ab0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5])
    ids = [r.getrandbits(32) | 1 for _ in range(n)]
    strs = []
    for _ in range(4):
        a = e.alloc(0x10, 4)
        e.wbytes(a, bytes(r.randrange(1, 4) for _ in range(r.choice([0, 1, 2, 3]))) + b'\0')
        strs.append(a)
    # the searched string, and the registry objects' names
    if r.random() < 0.5:
        dflt = bytes(e.rbytes(0x67c8e8, 24)).split(b'\0')[0]
        e.wbytes(strs[0], dflt + b'\0')
    target = strs[0]
    objs = {}
    for i in ids:
        if r.random() < 0.15:
            objs[i] = 0
        else:
            o = rnd(c, 8)
            e.w32(o + 4, 0 if r.random() < 0.15 else r.choice(strs))
            objs[i] = o
    holder = e.alloc(8, 4)
    e.w32(holder, target)
    o = reftab(c, ids)
    hook_rec(c, 0x456bf0, 0, this=True, ret=(0 if r.random() < 0.1 else o))

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(objs.get(v, 0), 4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    return [holder]


def _g4a7b50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    s = obj(c, 0x90, {0x84: pystub(c, 0, this=True, ret=r.choice([0, 1, 0x100, 0x2ff])),
                      0x64: pystub(c, 1, this=True), 0x68: pystub(c, 2, this=True)})
    e.wbytes(s + 0x7a, bytes([r.choice([0, 1, 1, 1]), r.choice([0, 1, 1, 0]), r.choice([0, 1, 0, 5])]))
    cid = r.choice([0, 0x123, 0x401, 0x5, 0xffff])
    e.wbytes(s + 0x50, cid.to_bytes(2, 'little'))
    code = r.choice([0x401, 0x400, cid, cid, 0x77, 0x10401, 0x10400, 0xf0000 | cid])
    return [s, code, r.getrandbits(32)]


S(0x456ab0, 'GUESS find an id by name through an iterator', 'thiscall', None, ret='eax', gen=_g456ab0, note='batch36084')
S(0x4a7b50, 'GUESS key down / up handler', 'thiscall', None, ret='eax', gen=_g4a7b50, note='batch36084')
