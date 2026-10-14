"""specs_s36023.py - cascade s4 batch 36023: 0x57ad40 (apply a limit to flagged entries), 0x57e400 (set up a window), 0x5b9560 (next element in a list), 0x6006e0 (unique-key tree insert), 0x620cb0 (copy through callbacks)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w32(c, a, v):
    c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _g57ad40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x562440, 0, this=True)
    hook_rec(c, 0x563510, 1, this=True)
    digits = rnd(c, 0x10)
    e.wbytes(digits, r.choice([b'2\0', b'-1\0', b'0\0', b'7\0', b'x\0']))

    def at(em, rr):
        s = b''
        p = em.arg32(0)
        while True:
            ch = em.rbytes(p, 1)
            if ch == b'\0':
                break
            s += ch
            p += 1
        try:
            v = int(s)
        except ValueError:
            v = 0
        em.calllog.append(('atoi', s))
        em.ret(eax=v & 0xffffffff, argbytes=0)
    e.stub_import('atoi', at)
    okv = r.choice([0, 1, 0x100, 0x101])

    def s5c(em, rr):
        em.w32(em.arg32(1), digits)
        em.calllog.append(('s5c', em.reg('ecx'), em.arg32(0)))
        em.ret(eax=okv, argbytes=8)
    sysobj(c, slots={0x5c: e.stub_fn('s5c', s5c)})
    nodes = []
    prev = 0
    for i in range(r.choice([0, 1, 2, 4])):
        n = rnd(c, 0x70)
        if r.random() < 0.1:
            e.w32(n + 0x54, 0)
        else:
            t = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 0x100])),
                              0x310: pystub(c, 0, this=True, ret=r.randint(-2, 3) & 0xffffffff),
                              0x2dc: pystub(c, 0, this=True)})
            d = e.alloc(0x40, 4)
            f = r.getrandbits(32)
            f = (f | 0x100000) if r.random() < 0.85 else (f & ~0x100000)
            e.wbytes(d + 0x23, (f & 0xffffffff).to_bytes(4, 'little'))
            w = rnd(c, 0x20)
            e.w32(w + 0xc, d)
            e.w32(t + 0xc, d)
            e.w32(n + 0x54, t)
        nodes.append(n)
    for i in range(len(nodes) - 1):
        e.w32(nodes[i] + 0x60, nodes[i + 1])
    if nodes:
        e.w32(nodes[-1] + 0x60, 0)
    lst = rnd(c, 0x70)
    e.w32(lst + 0x50, nodes[0] if nodes else 0)
    cobj = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=lst)})
    E = rnd(c, 0x80)
    e.w32(E + 0x54, cobj)
    return [E]


def _g57e400(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x563110, 2, this=True)
    hook_rec(c, 0x57f130, 1, this=True)
    retx = [r.getrandbits(32), r.getrandbits(32)]
    x = obj(c, 0x20, {0x14: pystub(c, 1, this=True, ret=lambda em, k: retx[min(k, 1)])})
    o = obj(c, 0x20, {0xc: pystub(c, 3, this=True), 0x60: pystub(c, 1, this=True, ret=x)})
    so = sysobj(c)
    e.wbytes(so + 0x1907, o.to_bytes(4, 'little'))
    st = pystub(c, 1, this=True)
    w = obj(c, 0x20, {0x34c: pystub(c, 5, this=True)})
    vt = e.r32(obj(c, 0x10, {0x84: pystub(c, 0, this=True, ret=w)}))
    E = e.alloc(0x400, 4)
    e.wbytes(E, bytes(r.getrandbits(8) for _ in range(0x400)))
    e.w32(E, vt)
    for off in (0x314, 0x310, 0x18c):
        e.w32(E + off, obj(c, 0x10, {0xbc: st}))
    return [E, r.getrandbits(32), r.getrandbits(32)]


def _g5b9560(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 4])
    elems = [r.getrandbits(32) | 1 for _ in range(n)]
    st = {'pos': 0}

    def s4c(em, rr):
        st['pos'] = 0
        em.calllog.append(('s4c',))
        em.ret(eax=0, argbytes=4)

    def s5c(em, rr):
        k = st['pos']
        st['pos'] += 1
        em.w32(em.arg32(0), 1 if k < n else 0)
        em.calllog.append(('s5c', k))
        em.ret(eax=(elems[k] if k < n else r.getrandbits(32)), argbytes=4)
    a = obj(c, 0x20, {0x4c: e.stub_fn('s4c', s4c), 0x5c: e.stub_fn('s5c', s5c)})
    if r.random() < 0.15:
        a = 0
    m = r.random()
    if m < 0.2 or not elems:
        key = 0 if r.random() < 0.6 else r.getrandbits(32) | 1
    else:
        key = r.choice(elems) if m < 0.8 else r.getrandbits(32) | 1
    return [a, key]


def _g6006e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    keys = r.sample(range(0, 12), r.choice([0, 1, 2, 3, 4, 5]))
    head = e.alloc(0x40, 4)
    nodes = {}
    root = 0

    def mk(k):
        n = e.alloc(0x30, 4)
        e.wbytes(n + 5, bytes(8))
        _w32(c, n + 0xd, k)
        nodes[n] = k
        return n
    for k in keys:
        n = mk(k)
        if not root:
            root = n
            continue
        cur = root
        while True:
            ck = nodes[cur]
            if k < ck:
                l = e.r32(cur + 5) if False else int.from_bytes(e.rbytes(cur + 5, 4), 'little')
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
    rightmost = order[-1] if order else head
    _w32(c, head + 5, leftmost if r.random() > 0.1 else head)
    _w32(c, head + 9, rightmost)
    R = e.alloc(0x10, 4)
    newn = e.alloc(0x30, 4)
    e.w32(R, newn)

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
        em.calllog.append(('5fe300', em.reg('ecx'), em.r32(em.arg32(0)), em.arg32(1), em.arg32(2), em.r32(em.arg32(3))))
        em.ret(eax=R, argbytes=16)
    e.hook(0x5fe300, ins)
    T = e.alloc(0x10, 4)
    e.w32(T, head)
    kv = r.choice(keys + [r.randint(0, 12)]) if keys and r.random() < 0.4 else r.randint(-1, 12) & 0xffffffff
    kp = e.alloc(0x10, 4)
    e.w32(kp, kv)
    out = e.alloc(0x10, 4)
    return [T, out, kp]


def _g620cb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def cbA(em, rr):
        em.calllog.append(('A50', em.arg32(0), em.arg32(1), em.arg32(2), em.r32(A + 0x118), em.r32(em.r32(A + 0x124)), em.r32(A + 0x11c), em.r32(em.r32(A + 0x124) + 4)))
        em.ret(eax=0, argbytes=0)
    B = r.randint(0, 0x100)
    C = B + r.choice([0, 1, 5, 0x40])
    steps = [B + r.randint(0, 0x40) for _ in range(r.choice([0, 1, 2]))] + [C]
    st = {'k': 0}

    def cbO(em, rr):
        k = st['k']
        st['k'] += 1
        pb, pl = em.arg32(1), em.arg32(3)
        em.calllog.append(('O3c', em.arg32(0), em.r32(pb), em.arg32(2), em.r32(pl), em.arg32(4)))
        em.w32(pb, steps[min(k, len(steps) - 1)])
        em.w32(pl, em.r32(pl) + r.randint(0, 9))
        em.ret(eax=0, argbytes=0)
    A = e.alloc(0x200, 4)
    e.wbytes(A, bytes(r.getrandbits(8) for _ in range(0x200)))
    ob = e.alloc(0x80, 4)
    e.wbytes(ob, bytes(r.getrandbits(8) for _ in range(0x80)))
    e.wbytes(ob + 0x48, bytes([r.choice([0, 0, 0, 1])]))
    e.w32(ob + 0x3c, e.stub_fn('O3c', cbO))
    e.w32(A + 0x50, e.stub_fn('A50', cbA))
    e.w32(A + 0x124, e.alloc(0x20, 4))
    e.w32(A + 0x8c, ob if r.random() < 0.5 else r.getrandbits(32))
    return [A, ob, B, C]


S(0x57ad40, 'GUESS apply a numeric limit to flagged entries', 'thiscall', None, ret=None, gen=_g57ad40, note='batch36023')
S(0x57e400, 'GUESS set up a window and its children', 'thiscall', None, ret='al', gen=_g57e400, note='batch36023')
S(0x5b9560, 'GUESS next element in a circular list', 'stdcall', None, ret='eax', gen=_g5b9560, note='batch36023')
S(0x6006e0, 'GUESS unique-key tree insert', 'thiscall', None, ret=None, gen=_g6006e0, note='batch36023')
S(0x620cb0, 'GUESS copy a range through callbacks', 'cdecl', None, ret=None, gen=_g620cb0, note='batch36023')
