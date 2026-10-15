"""specs_s51000.py - u4 (Sonnet) batch 51000. 0x5c88c0: object floats at +0x50..+0x64 (limits), vector of three floats with zero / NaN / negative cases, real 0x4e0d00 runs."""
import struct
from pilot import S
from unicorn.x86_const import UC_X86_REG_EDX
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fb(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


def _fl(r, zero=0.2):
    k = r.random()
    if k < zero:
        return r.choice([0.0, -0.0])
    if k < zero + 0.03:
        return r.choice([float('nan'), float('inf'), float('-inf')])
    if k < 0.5:
        return r.uniform(-3, 3)
    if k < 0.8:
        return r.uniform(-50, 50)
    return r.uniform(-1e-3, 1e-3)


def _g5c88c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x80)
    for off in range(0x50, 0x68, 4):
        k = r.random()
        if k < 0.04:
            f = r.choice([0.0, -0.0, float('nan')])
        elif k < 0.5:
            f = r.uniform(-2, 2)
        else:
            f = r.uniform(-30, 30)
        e.w32(me + off, _fb(f))
    v = rnd(c, 0x10)
    for i in range(3):
        e.w32(v + 4 * i, _fb(_fl(r)))
    return [me, v, r.choice([0, 1, 2, 0x100, 0xff]) & 0xff]


def _g429bc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    glob = rnd(c, 0x80)
    e.w32(0x7003a0, glob)
    me = rnd(c, 0x100)
    me_b = e.rbytes(me, 0x100)
    e.wbytes(me + 0xc, bytes([r.choice([0, 1, 1, 1, 7])]))
    e.wbytes(me + 0xb1, bytes([r.choice([0, 1, 1, 1, 5])]))
    cnt = r.choice([0, 1, 2, 5, 12, 17, -1, -5, r.randrange(0, 18)])
    e.w32(me + 0x61, cnt & 0xffffffff)
    if r.random() < 0.4:
        e.w32(me + 0x45, e.r32(0x6785d0))
    hook_rec(c, 0x4362e0, 0, this=True)
    hook_rec(c, 0x4297a0, 2, this=True, deref={0: 1, 1: 1})
    codes = [0x8007001e, 0x8007000c]
    poll = r.choice([0, 0, 0, 1, 0x7fffffff, 0x8007001e, 0x8007000c, 0x80004005, 0xffffffff])
    seq = [r.choice(codes) for _ in range(r.choice([0, 0, 1, 2, 4]))]
    seq.append(r.choice([0, 0, 0x80004005, 1]))
    nullat = r.choice([None, None, None, 0, 1, 2])

    def acq_side(em, k):
        if nullat is not None and k == nullat:
            em.wbytes(me + 0x71, bytes(4))

    def acq_ret(em, k):
        return seq[k] if k < len(seq) else 0

    def fill(em, k):
        p = em.arg32(2)
        b = bytearray()
        for i in range(0x110 // 4):
            v = r.choice([0, r.randrange(-1000, 1000), r.randrange(-65536, 65536), r.getrandbits(32), 0x80])
            b += (v & 0xffffffff).to_bytes(4, 'little')
        for i in range(0x30, 0x30 + 40):
            b[i] = r.choice([0, 0, 0x80, 1, r.getrandbits(8)])
        em.wbytes(p, bytes(b))
    ds = r.choice([0, 0, 0, 0, 1, 0x80004005])
    dev = obj(c, 0x40, {0x64: pystub(c, 1, ret=poll & 0xffffffff),
                        0x1c: pystub(c, 1, ret=acq_ret, side=acq_side),
                        0x24: pystub(c, 3, ret=ds, side=fill, nullflag=(2,))})
    e.wbytes(me + 0x71, (0 if r.random() < 0.1 else dev).to_bytes(4, 'little'))
    return [me]


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _g4b46c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    K = struct.unpack('<f', e.r32(0x6785e4).to_bytes(4, 'little'))[0]
    C1 = struct.unpack('<f', e.r32(0x678858).to_bytes(4, 'little'))[0]
    K2 = struct.unpack('<f', e.r32(0x685270).to_bytes(4, 'little'))[0]
    objs = []
    same = r.random() < 0.5
    for _ in range(6):
        o = rnd(c, 0x100)
        e.w32(o + 0x70, _fb(r.choice([0.0, -0.0, -1.0, 1.0, 0.5, r.uniform(-2, 2), float('nan')])))
        objs.append(0 if r.random() < 0.12 else o)
    if same:
        objs = [objs[0]] * 6
    tbl_slot = pystub(c, 1, this=True, ret=lambda em, k: objs[k % len(objs)])
    so = sysobj(c, table_slots={0x60: tbl_slot})
    vs = [pystub(c, 0, this=True), None]
    me = obj(c, 0x100, {0xa0: pystub(c, 0, this=True), 0x68: pystub(c, 2, this=True)})
    me_blk = rnd(c, 0x100)
    e.wbytes(me + 4, e.rbytes(me_blk, 0xfc))
    s50 = r.getrandbits(32)
    e.w32(me + 0x50, s50)
    tf_t = r.choice([r.uniform(-3, 40), r.uniform(0, 400), r.uniform(0, 5), 0.0])
    d = int(tf_t / (25 * K)) if K else r.randrange(-1000, 1000)
    if r.random() < 0.05:
        d = r.getrandbits(32) - 2**31
    e.w32(so + 0x40, (s50 + d) & 0xffffffff)
    tf = _f32(_f32(float(((d * 25 + 2**31) % 2**32) - 2**31)) * K)

    def near():
        k = r.random()
        if k < 0.6:
            return int(tf) + r.randrange(-3, 4)
        if k < 0.8:
            return r.randrange(-50, 500)
        return r.getrandbits(32) - 2**31
    e.w32(me + 0x68, near() & 0xffffffff)
    e.w32(me + 0x64, r.choice([0, near(), near(), int(tf) - r.randrange(0, 3)]) & 0xffffffff)
    e.w32(me + 0x6c, r.choice([0, 1, 2, near(), r.randrange(-5, 30)]) & 0xffffffff)
    e.w32(me + 0x70, r.choice([0, near(), near(), r.randrange(-5, 300)]) & 0xffffffff)
    e.w32(me + 0x74, r.choice([0, 1, 7, r.randrange(-100, 100)]) & 0xffffffff)
    e.w32(me + 0x58, _fb(r.uniform(-3, 3)))
    e.w32(me + 0x5c, _fb(r.choice([0.0, r.uniform(0, 1), r.uniform(0, 0.05), r.uniform(-1, 3)])))
    e.w32(me + 0x60, _fb(r.choice([0.0, tf / K2 * r.uniform(0.3, 1.1) if K2 else 1.0, r.uniform(-1, 4), float('nan')])))
    e.wbytes(me + 0x8d, (0 if r.random() < 0.2 else r.getrandbits(32)).to_bytes(4, 'little'))
    if r.random() < 0.25 and K:
        # exact tie: (float)e + m == tf with m = j * K2 integral
        for dd in range(max(d, 1), max(d, 1) + 4000):
            t2 = _f32(_f32(float(dd * 25)) * K)
            if t2 == int(t2) and t2 >= 1:
                break
        else:
            dd = None
        if dd is not None:
            tf = t2
            e.w32(so + 0x40, (s50 + dd) & 0xffffffff)
            jmax = int(tf / K2) if K2 else 0
            j = r.randrange(0, max(jmax, 0) + 1) if jmax >= 0 else 0
            m = _f32(j * K2)
            if m == int(m):
                e.w32(me + 0x60, _fb(float(j)))
                e.w32(me + 0x70, (int(tf) - int(m)) & 0xffffffff)
    hook_rec(c, 0x44b610, 0, this=True)
    hook_rec(c, 0x44b740, 1, pop=0)
    return [me]


_NAN = 0x7fc00000


def _g491ee0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    FL = [0x800000, 0x100000, 0x900000, 0, 0x200002, r.getrandbits(32), 0x800000 | 0x100000 | 0x400000, 0x1100000]

    def flagblk():
        b = rnd(c, 0x40)
        e.wbytes(b + 0x23, r.choice(FL).to_bytes(4, 'little'))
        return b

    def leaf():
        o = rnd(c, 0x80)
        e.w32(o + 0x3c, r.choice([0, 0, 0x400, 0x800, 0x3000000, 0x1000000, 0x2000000, r.getrandbits(32), 0x3000000 | 0xc00]))
        e.w32(o + 0x68, r.choice([0, 1, 1, r.getrandbits(32)]))
        return o

    def withblk(o, st):
        e.w32(o + 0x54, st)
        return o

    def stateobj():
        # s: [+8] chain head, [+0xc] -> flag block, vtable slot 0x2a0 advances the chain
        chain = []
        for _ in range(r.choice([0, 1, 2, 3, 5])):
            ch = leaf()
            if r.random() < 0.85:
                so = obj(c, 0x20, {})
                e.w32(so + 0xc, flagblk())
                e.w32(ch + 0x54, so)
            else:
                e.w32(ch + 0x54, 0)
            chain.append(ch)

        def adv(em, k):
            j = k % max(len(chain), 1)
            em.w32(em.arg32(0), chain[j + 1] if j + 1 < len(chain) else 0)
        st = obj(c, 0x20, {0x2a0: pystub(c, 1, this=True, nullflag=(0,), side=adv)})
        e.w32(st + 8, chain[0] if chain else 0)
        e.w32(st + 0xc, flagblk())
        return st

    def arrrec(em, k):
        p, n = em.arg32(0), em.arg32(1)
        em.calllog.append(('arr', n, tuple(em.r32(p + 4 * i) for i in range(n))))
    me = obj(c, 0x100, {0x10: pystub(c, 2, this=True, nullflag=(0,), side=arrrec)})
    n = r.choice([0, 1, 2, 5, 12, r.randrange(1, 21)])
    e.w32(me + 0xcc, n)
    shared = stateobj() if r.random() < 0.3 else None
    for i in range(n):
        o = leaf()
        k = r.random()
        if k < 0.1:
            e.w32(o + 0x54, 0)
        else:
            e.w32(o + 0x54, shared if (shared and r.random() < 0.5) else stateobj())
        e.w32(me + 4 + 4 * i, o)

    def edx_set(emu, k):
        emu.mu.reg_write(UC_X86_REG_EDX, r.getrandbits(32))
        emu.calllog.append(('p1c8', emu.arg32(0), emu.arg32(1)))
    hook_rec(c, 0x4dc630, 2, this=True)
    so = sysobj(c, slots={0x1c8: pystub(c, 2, this=True, ret=lambda emu, k: 0x100 + k, side=edx_set),
                          0x178: pystub(c, 3, this=True), 0x17c: pystub(c, 3, this=True)}, table_slots={})
    fl = lambda: r.choice([0, 0x80000000, _NAN, _fb(1.0), _fb(r.uniform(-5, 5)), r.getrandbits(32)])
    e.wbytes(so + 0x9c7, fl().to_bytes(4, 'little'))
    e.wbytes(so + 0x9c3, fl().to_bytes(4, 'little'))
    if r.random() < 0.4:
        def flip(emu, k):
            emu.wbytes(so + 0x9c7, fl().to_bytes(4, 'little'))
            emu.wbytes(so + 0x9c3, fl().to_bytes(4, 'little'))
        e.hook  # placeholder to keep reference
        # second hook on the array slot happens through arrrec: wrap it
        vt = e.r32(me)
        old = e.r32(vt + 0x10)
        e.w32(vt + 0x10, pystub(c, 2, this=True, nullflag=(0,), side=lambda em, k: (arrrec(em, k), flip(em, k))))
    return [me]


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def _g5010f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    # logger: slot 0x20 -> log object whose slot 0x2c is a cdecl print recorded with 3 stack args
    lo = obj(c, 0x20, {0x2c: pystub(c, 3, pop=0)})
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lo)})
    e.w32(0x700390, lg)
    cells = []
    for _ in range(4):
        cl = rnd(c, 0x10)
        t = r.choice([0, 2, 2, 0, 0, 1, 3, 0xff, r.getrandbits(8)]) if r.random() < 0.4 else r.choice([0, 2])
        e.wbytes(cl + 4, bytes([t]))
        if r.random() < 0.1:
            e.w32(cl, 0x7fc00000)
        cells.append(cl)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: cells[k % 4])
    fv = r.choice([0.0, -0.0, float('nan'), r.uniform(-100, 100), r.uniform(-1, 1), float('inf')])
    vt = pystub(c, 1, this=True, deref={0: 3}, st0=lambda em, k: fv)
    ob = obj(c, 0x40, {0x198: vt})
    me = rnd(c, 0x40)
    e.w32(me + 0xc, ob)
    a = rnd(c, 0x20)
    e.w32(a + 4, rnd(c, 0x20))
    e.w32(a + 8, rnd(c, 0x20))
    return [me, a]


def _g466040(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def r32():
        return r.getrandbits(32)

    def zobj():
        z = obj(c, 0x40, {0x10c: pystub(c, 2, this=True), 0x154: pystub(c, 0, this=True), 0x124: pystub(c, 4, this=True),
                          0x218: pystub(c, 1, this=True)})
        e.w32(z + 8, rnd(c, 0x20))
        return z
    chain = [rnd(c, 0x20) for _ in range(r.choice([0, 0, 1, 2, 4]))]

    def adv(em, k):
        j = k % max(len(chain), 1)
        em.w32(em.arg32(0), chain[j + 1] if j + 1 < len(chain) else 0)
    A = obj(c, 0x20, {0x50: pystub(c, 1, this=True, nullflag=(0,), side=adv)})
    e.w32(A + 8, chain[0] if chain else 0)
    hook_rec(c, 0x4dc630, 2, this=True)
    hook_rec(c, 0x461d60, 0, this=True)
    z1 = zobj() if r.random() < 0.7 else 0
    z2 = zobj()
    Y = obj(c, 0x40, {0x25c: pystub(c, 2, this=True, ret=z1), 0x294: pystub(c, 4, this=True, ret=z2)})
    X = obj(c, 0x40, {0x5c: pystub(c, 1, this=True, ret=lambda em, k: r32())})
    so = sysobj(c, table_size=0xb00)
    T = e.r32(so + 0x9b)
    e.w32(T + 0xadc, Y)
    e.wbytes(so + 0x1a9f, (0 if r.random() < 0.3 else X).to_bytes(4, 'little'))
    glob = rnd(c, 0x600)
    e.w32(0x7003b8, glob)

    def fillbuf(em, k):
        p = em.arg32(0)
        for i in range(3):
            em.w32(p + 4 * i, r32() if r.random() < 0.1 else _fb(r.uniform(-50, 50)))
    ret398 = r32()
    me = obj(c, 0x200, {0x20: pystub(c, 0, this=True, ret=A), 0x358: pystub(c, 0, this=True),
                        0x3a0: pystub(c, 1, this=True, nullflag=(0,), ret=ret398, side=fillbuf),
                        0x398: pystub(c, 1, this=True), 0x3d4: pystub(c, 0, this=True)})
    return [me]


S(0x5c88c0, 'GUESS normalise and clamp direction vector against limits', 'thiscall', None, ret='al', gen=_g5c88c0, note='batch51000')
S(0x429bc0, 'GUESS joystick poll and read axes and buttons', 'thiscall', None, ret=None, gen=_g429bc0, note='batch51000')
S(0x4b46c0, 'GUESS timed fade of a sound object', 'thiscall', None, ret=None, gen=_g4b46c0, note='batch51000')
S(0x491ee0, 'GUESS collect drawable objects and dispatch', 'thiscall', None, ret=None, gen=_g491ee0, nan_heap=True, note='batch51000')
S(0x5010f0, 'GUESS evaluate three script floats through an object slot', 'thiscall', None, ret=None, gen=_g5010f0, nan_heap=True, note='batch51000')
S(0x466040, 'GUESS init object: lookup or create a named entry and bind', 'thiscall', None, ret=None, gen=_g466040, nan_heap=True, note='batch51000')
