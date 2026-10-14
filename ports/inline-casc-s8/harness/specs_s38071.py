"""specs_s38071.py - cascade s8 batch 38071. stdcall(X, node, ids, vec) ret 0x10. ids = {u16 count 0..4, unaligned ptr to u16 ids}; node: base id +0xa0, count +0xa8 (0 or 2..4), table +0xac, addend +0xb0, child +0x9c
(mostly set). The first id is always in range (the original reads stale frame values on the error / null-child paths, which only exist after a successful iteration); later ids are in range, below the base (child path) or beyond
it (error 0x137 + assert). 0x602d30 / 0x602ff0 / 0x602d70 / 0x5ffb00 / 0x5f52f0 / 0x5f5250 / 0x42ab62 hooked; X has slots 0 and 0x30 returning objects with slots 0x24 / 0x28; the vector's entries are tagged 0 / 4 / other,
capacity sometimes <= size (0x42ab62 + assert); _stricmp is a Python stub comparing text; the logger and assert hook are always set."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _cstr(em, p):
    out = b''
    while len(out) < 80:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g5fed20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    st = obj(c, 0x20, {0x2c: e.stub_fn('printer', lambda em, res_: (em.calllog.append(('log', em.arg32(0) != 0, em.arg32(1), em.arg32(2))), em.ret(eax=0)))})

    def lg(em, res_):
        em.calllog.append(('logger', em.reg('ecx') != 0, em.arg32(0), em.arg32(1)))
        em.ret(eax=st, argbytes=8)
    e.w32(0x700390, obj(c, 0x40, {0x20: e.stub_fn('logger', lg)}))
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lslot(name, nargs, retf=lambda: 0):
        def h(em, res_):
            em.calllog.append((name, em.reg('ecx') != 0) + tuple(em.arg32(i) for i in range(nargs)))
            em.ret(eax=retf(), argbytes=4 * nargs)
        return e.stub_fn(name, h)

    def mkval():
        return obj(c, 0x20, {0x24: lslot('v24', 0, lambda: r.getrandbits(32)), 0x28: lslot('v28', 0)})
    X = obj(c, 0x40, {0x00: lslot('X0', 2, lambda: mkval()), 0x30: lslot('X30', 1, lambda: mkval())})
    vals = [mkval() for _ in range(3)]
    nm_ok = e.alloc(0x20, 1)
    e.wbytes(nm_ok, _cstr(e, 0x6b9044).swapcase() + b'\0')
    nm_bad = e.alloc(0x20, 1)
    e.wbytes(nm_bad, b'other\0')

    def sobj():
        o = rnd(c, 0x40)
        e.w32(o + 0x1c, r.choice([0, 0, 5]))
        return o
    pool = [sobj() for _ in range(3)]
    names = {}
    for o in pool:
        names[o] = r.choice([0, nm_ok, nm_ok, nm_bad])
    ec = {}

    def cmp_(em, res_):
        a, b = _cstr(em, em.arg32(0)).lower(), _cstr(em, em.arg32(1)).lower()
        em.calllog.append(('_stricmp', a, b))
        em.ret(eax=0 if a == b else 1, argbytes=0)
    e.w32(0x676414, e.stub_fn('_stricmp', cmp_))
    hook_rec(c, 0x5ffb00, 1, this=True, pop=4, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x602d30, 1, pop=4, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x602ff0, 0, this=True, pop=0, ret=lambda em, k: r.choice(pool + [0, 0]))
    hook_rec(c, 0x602d70, 0, this=True, pop=0, ret=lambda em, k: names[em.reg('ecx')])
    hook_rec(c, 0x5f52f0, 1, this=True, pop=4, deref={0: 1})
    hook_rec(c, 0x5f5250, 1, this=True, pop=4, deref={0: 1})
    hook_rec(c, 0x42ab62, 1, pop=0)
    node = rnd(c, 0xc0)
    base = r.randrange(0, 0x40)
    cnt = r.choice([0, 0, 2, 3, 4])
    if cnt:
        e.w32(node + 0xa8, cnt)
    else:
        e.w32(node + 0xa8, 0)
    e.w32(node + 0xa0, base)
    tab = rnd(c, 4 * 8)
    e.w32(node + 0xac, tab)
    e.w32(node + 0x9c, r.choice([0, rnd(c, 0x20), rnd(c, 0x20), rnd(c, 0x20)]))
    n = r.choice([0, 1, 2, 3, 4])
    idl = []
    for i in range(n):
        k = r.random()
        if i == 0 or cnt == 0 and False:
            wid = base + r.randrange(max(cnt, 1))
        elif k < 0.4:
            wid = base + r.randrange(max(cnt, 1))
        elif k < 0.6 and base:
            wid = r.randrange(0, base)
        else:
            wid = base + cnt + r.randrange(0, 4)
        idl.append(wid & 0xffff)
    if n and cnt == 0:
        # no local table: the first id would take the child path with stale values; give the node a table anyway
        e.w32(node + 0xa8, 2)
        cnt = 2
        idl[0] = base
    ids = e.alloc(6, 1)
    arr = e.alloc(2 * 8, 2)
    e.wbytes(arr, struct.pack('<%dH' % max(len(idl), 1), *(idl or [0])))
    e.wbytes(ids, struct.pack('<HI', n, arr))
    ecap = r.choice([0, 1, 2, 4, 8])
    entries = e.alloc(8 * 8, 4)
    raw = b''
    for i in range(8):
        tag = r.choice([0, 4, 4, 1, 2])
        v = mkval() if tag == 4 else r.getrandbits(32)
        raw += struct.pack('<IB3x', v, tag)
    e.wbytes(entries, raw)
    vec = e.alloc(0x10, 4)
    size = r.choice([0, 0, 1, 2])
    e.wbytes(vec, struct.pack('<IIII', entries, r.choice([8, 8, 3, 1, size]), size, 0))
    return [X, node, ids, vec]


S(0x5fed20, 'GUESS replay ids into tagged vector', 'stdcall', None, ret=None, gen=_g5fed20, note='batch38071')
