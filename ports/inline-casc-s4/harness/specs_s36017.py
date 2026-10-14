"""specs_s36017.py - cascade s4 batch 36017: 0x5fa4f0 (write lists to a stream), 0x5a3000 (flag a selection), 0x597c40 (drain pending entries), 0x6279e0 (scan opcode pairs)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w32(c, a, v):
    c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _g5fa4f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = obj(c, 0x20, {0x2c: pystub(c, 1, this=True), 0x3c: pystub(c, 1, this=True)})
    st = pystub(c, 2, this=True)
    na, nb = r.choice([0, 1, 2, 3]), r.choice([0, 1, 2, 3])
    arr1 = e.alloc(0x20, 4)
    for i in range(4):
        e.w32(arr1 + 4 * i, r.getrandbits(32))
    arr2 = e.alloc(0x20, 4)
    for i in range(4):
        e.w32(arr2 + 4 * i, obj(c, 0x10, {0xc: st}))
    D = rnd(c, 0x30)
    e.w32(D + 0x14, na)
    e.w32(D + 0xc, arr1)
    e.w32(D + 8, nb)
    e.w32(D, arr2)
    me = rnd(c, 0x10)
    e.w32(me + 4, D)
    return [me, s]


def _g5a3000(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x598e10, 3, this=True)
    seq = [r.choice([0, 1, 0x100, 0x101]), r.choice([0, 1, 1, 0x100, 0x101])]
    vt = e.r32(obj(c, 0x10, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: seq[min(k, 1)])}))
    x = e.alloc(0x800, 4)
    e.w32(x, vt)
    e.wbytes(x + 0x780, bytes(r.getrandbits(8) for _ in range(8)))
    n = rnd(c, 0x40)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=x), 0x154: pystub(c, 2, this=True, ret=n)})
    hobj = rnd(c, 0x20)
    hcont = e.alloc(0x900, 4)
    _w32(c, hcont + 0x852, hobj)
    E = e.alloc(0x940, 4)
    e.wbytes(E + 0x784, (0 if r.random() < 0.1 else r.getrandbits(32) | 1).to_bytes(4, 'little'))
    e.wbytes(E + 0x92e, (0 if r.random() < 0.1 else hcont).to_bytes(4, 'little'))
    return [E]


def _g597c40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    hook_rec(c, 0x594040, 2, this=True, ret=r.getrandbits(32))
    ps = [rnd(c, 0x10) for _ in range(r.choice([0, 1, 2, 3]))] + [0]

    def side(em, k):
        em.w32(em.arg32(0), r.getrandbits(32))
    hook_rec(c, 0x597720, 1, this=True, ret=lambda em, k: ps[min(k, len(ps) - 1)], side=side, stackmark=(0,))
    hook_rec(c, 0x5967b0, 1, this=True)
    cc = obj(c, 0x20, {0x84: pystub(c, 1, this=True, deref={0: 3}), 0x12c: pystub(c, 3, this=True, deref={2: 5})})
    E = e.alloc(0x2100, 4)
    _w32(c, E + 0x1d0b, cc)
    _w32(c, E + 0x4f7, r.choice([0, 1, 5]))
    a = r.getrandbits(32)
    _w32(c, E + 0x1fba, a)
    _w32(c, E + 0x1fae, a if r.random() < 0.25 else r.getrandbits(32))
    e.wbytes(E + 0x1d2d, r.getrandbits(16).to_bytes(2, 'little'))
    return [E]


def _g6279e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vals = [0x18, 0x19, 0x12, 0x17, 0x1a, 0x00, 0xff]
    A = e.alloc(0x200, 4)
    e.wbytes(A, bytes(r.getrandbits(8) for _ in range(0x200)))
    for i in range(8):
        e.wbytes(A + 0x4c + i, bytes([r.choice(vals)]))
    rets = [r.choice(vals) for _ in range(8)]
    hook_rec(c, 0x62c640, 2, pop=0, ret=lambda em, k: rets[min(k, 7)])
    n = r.choice([0, 1, 2, 3, 5])
    buf = e.alloc(0x20, 4)
    for i in range(n):
        e.wbytes(buf + 2 * i, bytes([r.choice([0, 0, 1, 2, 5]), r.randint(0, 7)]))
    out = e.alloc(0x10, 4)
    return [A, buf, buf + 2 * n, out]


S(0x5fa4f0, 'GUESS write lists to stream and visit children', 'thiscall', None, ret=None, gen=_g5fa4f0, note='batch36017')
S(0x5a3000, 'GUESS flag selection and request update', 'thiscall', None, ret=None, gen=_g5a3000, note='batch36017')
S(0x597c40, 'GUESS drain pending entries', 'thiscall', None, ret=None, gen=_g597c40, note='batch36017')
S(0x6279e0, 'GUESS scan opcode pairs for terminator', 'cdecl', None, ret='eax', gen=_g6279e0, note='batch36017')
