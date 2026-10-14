"""specs_s36019.py - cascade s4 batch 36019: 0x4c2040 (read fields A), 0x4d2a90 (find named item), 0x4f0d70 (write fields to stream), 0x536270 (log a table), 0x4f7620 (swap attached object)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger, HEAP_LO, HEAP_HI


def _assert(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def _w32(c, a, v):
    c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _stream(c, sizes):
    r = c.rng
    slots = {}
    for off, n in sizes.items():
        def side(em, k, n=n):
            em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(n)))
        slots[off] = pystub(c, 1, this=True, side=side)
    return obj(c, 0x20, slots)


def _g4c2040(c):
    clear_hooks(c)
    _assert(c)
    hook_rec(c, 0x4c0a90, 1, this=True)
    s = _stream(c, {0x68: 1, 0x50: 4, 0x40: 4, 0x44: 2})
    return [rnd(c, 0x200), s]


def _g4d2a90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def mi(em, rr):
        a, b, n = em.arg32(0), em.arg32(1), em.arg32(2)
        x, y = em.rbytes(a, n), em.rbytes(b, n)
        res = 0
        for p, q in zip(x.lower(), y.lower()):
            if p != q:
                res = -1 if p < q else 1
                break
        em.calllog.append(('memicmp', a, b, n))
        em.ret(eax=res & 0xffffffff, argbytes=0)
    e.stub_import('_memicmp', mi)
    nm = bytes(r.choice(b'abcXYZ_') for _ in range(r.randint(1, 8))) + b'\0'
    name = e.alloc(0x20, 4)
    e.wbytes(name, nm)
    items = []
    for i in range(r.choice([0, 1, 2, 3])):
        it = e.alloc(0x40, 4)
        e.wbytes(it, bytes(r.getrandbits(8) for _ in range(0x40)))
        L = len(nm) if r.random() < 0.6 else r.randint(1, 8)
        _w32(c, it, L)
        body = bytearray(nm[:L])
        if r.random() < 0.5:
            body = bytearray(bytes(ch ^ 0x20 if 65 <= (ch & 0xdf) <= 90 and r.random() < 0.5 else ch for ch in body))
        if r.random() < 0.3 and body:
            body[r.randrange(len(body))] ^= 0x01
        e.wbytes(it + 0xc, bytes(body))
        items.append(it)
    locs = [1] * len(items) + [0]

    def side(em, k):
        em.w32(em.arg32(0), locs[min(k, len(locs) - 1)])
    seq = items + [0]
    vt = e.r32(obj(c, 0x10, {0x4c: pystub(c, 1, this=True, stackmark=(0,)),
                             0x5c: pystub(c, 1, this=True, stackmark=(0,), ret=lambda em, k: seq[min(k, len(seq) - 1)], side=side)}))
    E = e.alloc(0x4100, 4)
    e.w32(E + 0x4008, vt)
    ln = r.choice([0, len(nm), len(nm), r.randint(1, 8)])
    return [E, name, ln]


def _g4f0d70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x45f960, 1, this=True)

    def h(em, rr):
        a0, a1 = em.arg32(0), em.arg32(1)
        em.calllog.append(('w10', a0 if HEAP_LO <= a0 < HEAP_HI else 0, a1, em.rbytes(a0, a1)))
        em.ret(eax=0, argbytes=8)
    s = obj(c, 0x20, {0x3c: pystub(c, 1, this=True), 0x10: e.stub_fn('w10', h)})
    E = obj(c, 0x100, {0x234: pystub(c, 1, this=True)})
    return [E, s]


def _g536270(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 2)
    vt = e.r32(obj(c, 0x10, {0x1b4: pystub(c, 3, this=True)}))
    E = e.alloc(0x5400, 4)
    e.w32(E, vt)
    base = rnd(c, 0x100)
    _w32(c, base, r.choice([4, 8, 0x10, 0x20, 0x40]))
    e.wbytes(E + 0x5302, base.to_bytes(4, 'little'))
    return [E]


def _g4f7620(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    x = obj(c, 0x20, {0x350: pystub(c, 3, this=True), 0x34c: pystub(c, 5, this=True)})
    ys = [r.getrandbits(32) for _ in range(4)]
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=lambda em, k: ys[min(k, 3)])})
    E = obj(c, 0x100, {0x2c4: pystub(c, 0, this=True, ret=x), 0x370: pystub(c, 0, this=True)})
    e.wbytes(E + 0x8f, (0 if r.random() < 0.4 else r.getrandbits(32) | 1).to_bytes(4, 'little'))
    a = 0 if r.random() < 0.3 else obj(c, 0x20, {0x2e8: pystub(c, 1, this=True)})
    return [E, a]


S(0x4c2040, 'GUESS read fields from stream (E)', 'thiscall', None, ret='al', gen=_g4c2040, note='batch36019')
S(0x4d2a90, 'GUESS find named item (case-insensitive)', 'thiscall', None, ret='al', gen=_g4d2a90, note='batch36019')
S(0x4f0d70, 'GUESS write fields to stream (F)', 'thiscall', None, ret='al', gen=_g4f0d70, note='batch36019')
S(0x536270, 'GUESS log a table of pairs', 'thiscall', None, ret=None, gen=_g536270, note='batch36019')
S(0x4f7620, 'GUESS swap attached object', 'thiscall', None, ret=None, gen=_g4f7620, note='batch36019')
