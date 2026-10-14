"""specs_s36077.py - cascade s4 batch 36077: 0x5da470 (find a same-named object in a list), 0x5f5520 (remove a range of tagged entries)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, stub_memmove


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True


def _g5da470(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5])
    found = r.choice([-1, -1, 0, 1, 2, 4])
    cn = [0]

    def sc(em, res):
        k = cn[0]
        cn[0] += 1
        em.calllog.append(('cmp', em.arg32(0), em.arg32(1)))
        em.ret(eax=(0 if k == found else r.choice([-1, 1, 0x100])), argbytes=0)
    e.stub_import('_stricmp', sc)
    objs = {}

    def mkobj():
        o = rnd(c, 0x10)
        e.w32(o + 4, 0 if r.random() < 0.3 else rnd(c, 8))
        return o

    ids = [r.getrandbits(32) | 1 for _ in range(n)]
    sid = r.getrandbits(32) | 1
    objs[sid] = mkobj() if r.random() < 0.9 else 0
    for i in ids:
        objs[i] = mkobj()

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(objs.get(v, 0), 4)

    cnt_calls = [0]

    def count(em, rr):
        em.calllog.append(('count',))
        em.ret(n, 0)

    def at(em, rr):
        i = em.arg32(0)
        em.calllog.append(('at', i))
        em.ret(ids[i] if i < len(ids) else 0, 4)
    L = obj(c, 0x40, {0x14: e.stub_fn('count', count), 0x30: e.stub_fn('at', at)})
    mgr = obj(c, 0x20, {0x98: pystub(c, 0, this=True, ret=L)})
    so = sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    e.wbytes(so + 0x190f, mgr.to_bytes(4, 'little'))
    s = rnd(c, 0x70)
    e.w32(s + 0x56, sid)
    e.w32(s + 0x5e, r.choice([0, 1, 1, 1]))
    return [s]


def _g5f5520(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stub_memmove(c)
    _assert_hook(c)
    total = r.choice([0, 1, 2, 4, 6, 8])
    arr = e.alloc(8 * 10, 4)
    for i in range(10):
        tag = r.choice([0, 1, 4, 4, 4, 0xff])
        if tag == 4:
            tgt = obj(c, 0x30, {0x28: pystub(c, 0, this=True)})
        else:
            tgt = rnd(c, 8)
        e.w32(arr + 8 * i, tgt)
        e.wbytes(arr + 8 * i + 4, bytes([tag]) + bytes(r.getrandbits(8) for _ in range(3)))
    t = rnd(c, 0x20)
    e.w32(t, arr)
    e.w32(t + 8, total)
    start = r.choice([0, 0, 1, 2, 3, total, total + 1, 0x7fffffff])
    cnt = r.choice([0, 1, 1, 2, 3, total, total + 1, max(total - start, 0) if start <= total else 1])
    a = e.alloc(4, 4)
    b = e.alloc(4, 4)
    e.w32(a, start & 0xffffffff)
    e.w32(b, cnt & 0xffffffff)
    return [t, a, b]


S(0x5da470, 'GUESS find same-named object in a list', 'thiscall', None, ret='eax', gen=_g5da470, note='batch36077')
S(0x5f5520, 'GUESS remove a range of tagged entries', 'thiscall', None, ret=None, gen=_g5f5520, note='batch36077')
