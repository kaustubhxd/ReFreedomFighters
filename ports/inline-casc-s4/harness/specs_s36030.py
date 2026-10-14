"""specs_s36030.py - cascade s4 batch 36030: 0x59e730 (select entries between bounds, inclusive), 0x6004a0 (unique-key tree insert with u16 keys), 0x606940 (MD5-style update), 0x63f6b0 (release a pool slot), 0x61fb10 (reserve a record and look it up)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w32(c, a, v):
    c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _g59e730(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5a3690, 2, this=True)
    E = e.alloc(0x900, 4)
    e.wbytes(E, bytes(r.getrandbits(8) for _ in range(0x900)))
    n = r.choice([0, 1, 2, 4, 7])
    _w32(c, E + 0x7ce, n)
    for i in range(n):
        _w32(c, E + 0x7d2 + 16 * i, r.randint(-6, 6) & 0xffffffff)
    return [E, r.randint(-5, 6) & 0xffffffff, r.randint(-6, 5) & 0xffffffff]


def _g6004a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    pool = [0, 1, 2, 3, 4, 5, 6, 7, 0x7fff, 0x8000, 0x8001, 0xffff, 0xfffe, 0x4000]
    keys = r.sample(pool, r.choice([0, 1, 2, 3, 4, 5]))
    head = e.alloc(0x40, 4)
    nodes = {}
    root = 0

    def mk(k):
        n = e.alloc(0x30, 4)
        e.wbytes(n + 5, bytes(8))
        e.wbytes(n + 0xd, bytes([k & 0xff, (k >> 8) & 0xff]) + bytes([r.getrandbits(8), r.getrandbits(8)]))
        nodes[n] = k
        return n
    for k in keys:
        n = mk(k)
        if not root:
            root = n
            continue
        cur = root
        while True:
            if k < nodes[cur]:
                l = int.from_bytes(e.rbytes(cur + 5, 4), 'little')
                if not l:
                    _w32(c, cur + 5, n)
                    break
                cur = l
            else:
                rr_ = int.from_bytes(e.rbytes(cur + 9, 4), 'little')
                if not rr_:
                    _w32(c, cur + 9, n)
                    break
                cur = rr_
    order = sorted(nodes, key=lambda p: nodes[p])
    _w32(c, head + 1, root)
    leftmost = order[0] if order else head
    _w32(c, head + 5, leftmost if r.random() > 0.1 else head)
    _w32(c, head + 9, order[-1] if order else head)
    R = e.alloc(0x10, 4)
    e.w32(R, e.alloc(0x30, 4))

    def pred(em, rr):
        slot = em.reg('ecx')
        cur = em.r32(slot)
        idx = order.index(cur) if cur in order else -1
        em.calllog.append(('42ffc0', cur))
        if idx > 0:
            em.w32(slot, order[idx - 1])
        em.ret(eax=0, argbytes=0)
    e.hook(0x42ffc0, pred)

    def ins(em, rr):
        kp = em.arg32(3)
        em.calllog.append(('5fe240', em.reg('ecx'), em.r32(em.arg32(0)), em.arg32(1), em.arg32(2), int.from_bytes(em.rbytes(kp, 2), 'little')))
        em.ret(eax=R, argbytes=16)
    e.hook(0x5fe240, ins)
    T = e.alloc(0x10, 4)
    e.w32(T, head)
    kv = r.choice(keys + [r.choice(pool)]) if keys and r.random() < 0.4 else r.choice(pool)
    kp = e.alloc(0x10, 4)
    e.wbytes(kp, bytes([kv & 0xff, (kv >> 8) & 0xff, r.getrandbits(8), r.getrandbits(8)]))
    out = e.alloc(0x10, 4)
    return [T, out, kp]


def _g606940(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def mc(em, rr):
        d, s_, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.wbytes(d, em.rbytes(s_, n))
        em.calllog.append(('memcpy', d, s_, n))
        em.ret(eax=d, argbytes=0)
    e.hook(0x634d22, mc)

    def tr(em, rr):
        blk = em.arg32(0)
        em.calllog.append(('606230', em.reg('ecx'), blk, em.rbytes(blk, 0x40)))
        em.ret(eax=0, argbytes=4)
    e.hook(0x606230, tr)
    E = e.alloc(0x100, 4)
    e.wbytes(E, bytes(r.getrandbits(8) for _ in range(0x100)))
    bits = r.choice([0, 8, 0x1f8, 0x200, 0xfffffff8, 0xffffffc0, r.getrandbits(32), 0x40 * 8, 0x3f * 8])
    _w32(c, E + 0x10, bits)
    _w32(c, E + 0x14, r.getrandbits(32))
    data = e.alloc(0x240, 4)
    e.wbytes(data, bytes(r.getrandbits(8) for _ in range(0x240)))
    ln = r.choice([0, 1, 5, 0x3f, 0x40, 0x41, 0x7f, 0x80, 0x81, 0xff, 0x100, r.randint(0, 0x200)])
    return [E, data, ln]


def _g63f6b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blocks = [rnd(c, 0x20) for _ in range(3)]
    p = rnd(c, 0x20)
    rnd(c, r.randint(0, 0x300))
    b = rnd(c, 0x20)
    if r.random() < 0.5:
        p, b = b, p
    e.wbytes(b, bytes([r.choice([1, 1, 2, 3, 0])]))
    other = blocks[0]
    a = b if r.random() < 0.2 else blocks[1]
    d = b if r.random() < 0.2 else blocks[2]
    e.w32(b + 8, a)
    e.w32(b + 0xc, d)
    head = b if r.random() < 0.3 else other
    e.w32(other + 0xc, blocks[1] if r.random() < 0.5 else blocks[2])
    E = obj(c, 0x20, {0x2c: pystub(c, 1, this=True, ret=b), 0x34: pystub(c, 1, this=True)})
    e.w32(E + 8, head)
    e.w32(E + 0xc, r.getrandbits(32))
    return [E, p]


def _g61fb10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x620180, 4, pop=0, ret=r.choice([0, 1, 1, 1]))
    hook_rec(c, 0x6206e0, 1, pop=0, ret=r.choice([0, 1, 1]))
    k = 0 if r.random() < 0.15 else rnd(c, 0x10)
    p = 0 if r.random() < 0.15 else rnd(c, 0x20)
    if p and k:
        e.w32(p, k if r.random() < 0.5 else r.getrandbits(32))
    hook_rec(c, 0x61fd60, 3, pop=0, ret=p)
    hook_rec(c, 0x6210c0, 2, pop=0, ret=r.choice([0, 1, 1]))
    A = e.alloc(0x1d0, 4)
    e.wbytes(A, bytes(r.getrandbits(8) for _ in range(0x1d0)))
    s = A + 0x1a8
    buf = e.alloc(0x20, 4)
    e.w32(s + 0xc, buf)
    e.w32(s + 8, buf if r.random() < 0.4 else buf + 8)
    e.w32(s + 0x10, k)
    return [A, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x59e730, 'GUESS select entries between bounds inclusive', 'thiscall', None, ret=None, gen=_g59e730, note='batch36030')
S(0x6004a0, 'GUESS unique-key tree insert with u16 keys', 'thiscall', None, ret=None, gen=_g6004a0, note='batch36030')
S(0x606940, 'GUESS MD5-style update', 'thiscall', None, ret=None, gen=_g606940, note='batch36030')
S(0x63f6b0, 'GUESS release a pool slot (B)', 'thiscall', None, ret=None, gen=_g63f6b0, note='batch36030')
S(0x61fb10, 'GUESS reserve a record and look it up', 'cdecl', None, ret='eax', gen=_g61fb10, note='batch36030')
