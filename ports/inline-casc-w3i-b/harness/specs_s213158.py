"""specs_s213158.py - batch 213158: nearest-candidate search over an item iterator (vcall driven, real vector helpers), Sonnet-w3b."""
import math
import struct
from unicorn.x86_const import UC_X86_REG_XMM0
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')


def crt(c, addr, fn, name):
    def side(em, k):
        a = em.reg('xmm0') & ((1 << 64) - 1)
        x = struct.unpack('<d', struct.pack('<Q', a))[0]
        em.calllog.append((name, a))
        try:
            z = fn(x)
        except (ValueError, OverflowError):
            z = math.nan
        em.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', z))[0])
    hook_rec(c, addr, 0, side=side)


def f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def _tie_pair():
    """Two adjacent floats whose lengths differ but whose distances (len + 1e-9, float) coincide."""
    def bits(x):
        return struct.unpack('<I', struct.pack('<f', x))[0]

    def fb(b):
        return struct.unpack('<f', struct.pack('<I', b))[0]
    cc = struct.unpack('<f', struct.pack('<I', 0x3089705f))[0]

    def ln(x):
        return f32(math.sqrt(f32(x * x)))

    def dist(x):
        return f32(ln(x) + cc)
    x0 = bits(f32(1.39e-8))
    for k in range(-6000, 6000):
        xa, xb = fb(x0 + k), fb(x0 + k + 1)
        if ln(xa) != ln(xb) and dist(xa) == dist(xb):
            return xa, xb
    return None


TIE = _tie_pair()


def g591f60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    crt(c, 0x634d7c, math.sqrt, 'sqrt')

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def wf(addr, v):
        e.wbytes(addr, struct.pack('<f', f32(v)))

    def fv():
        return r.choice([0.0, 1.0, -1.0, 0.5, 2.0, r.uniform(-4, 4), r.uniform(-4, 4), 3.0])

    def log_bufs(tag):
        def side(emu, k):
            emu.calllog.append((tag, bytes(emu.rbytes(emu.arg32(0), 12)), bytes(emu.rbytes(emu.arg32(1), 12))))
        return side

    def fill(emu, k):
        # vt 0x2e0: write random floats into the first buffer (arg0) and second (arg1)
        for i in (0, 1):
            emu.wbytes(emu.arg32(i), struct.pack('<3f', fv(), fv(), fv()))
        emu.calllog.append(('m2e0', bytes(emu.rbytes(emu.arg32(0), 12)), bytes(emu.rbytes(emu.arg32(1), 12))))
    best_cands = []
    zero_b = [False]

    def mk_cands(accept=False):
        n = 1 if accept else r.choice([0, 1, 2, 3, 5])
        arr = rnd(c, 0x40)
        w32u(arr, n)
        for i in range(n):
            if (not accept) and r.random() < 0.15:
                w32u(arr + 4 + 4 * i, 0)
            else:
                cand = rnd(c, 0x80)
                e.wbytes(cand + 0x5a, bytes([0 if accept else r.choice([0, 0, 0, 1, 4, 5, 2])]))
                w32u(arr + 4 + 4 * i, cand)
        return arr
    own1 = rnd(c, 0x20)
    own2 = rnd(c, 0x20)

    def mk_parent():
        return obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=lambda emu, k: (rb() & ~0xff) | (1 if r.random() < 0.6 else 0)),
                             0x2e0: pystub(c, 2, this=True, stackmark=(0, 1), side=fill),
                             0x98: pystub(c, 2, this=True, stackmark=(0, 1), side=log_bufs('m98'))}, nslots=0x80)

    def mk_entity(parent_none=False, accept=False, shape_x=None):
        parent = 0 if parent_none else (mk_parent() if r.random() < 0.7 else 0)

        def s128(emu, k):
            emu.calllog.append(('s128', emu.arg32(0) & 0xffff, emu.arg32(2)))
            emu.w32(emu.arg32(1), mk_cands(accept))
        shape = rnd(c, 0x50)
        w32u(shape + 0x3c, r.choice([0, 0, 0x800, 0x1, 0x801]))
        for i, v in enumerate((fv(), fv(), fv()) if shape_x is None else (shape_x, 0.0, 0.0)):
            wf(shape + 0x30 + 4 * i, v)
        ent = obj(c, 0x40, {0x128: pystub(c, 3, this=True, stackmark=(1,), side=s128),
                            0x84: pystub(c, 1, this=True, stackmark=(0,), side=lambda emu, k: emu.calllog.append(('s84', bytes(emu.rbytes(emu.arg32(0), 12))))),
                            0x1e0: pystub(c, 1, this=True, ret=lambda emu, k: (rb() & ~0xff) | (0 if accept else (1 if r.random() < 0.5 else 0))),
                            0x20: pystub(c, 0, this=True, ret=parent),
                            0x2e0: pystub(c, 2, this=True, stackmark=(0, 1), side=fill),
                            0x98: pystub(c, 2, this=True, stackmark=(0, 1), side=log_bufs('s98'))}, nslots=0x80)
        w32u(ent + 8, shape)
        return ent
    ents = {}
    ids = []
    for i in range(r.choice([0, 1, 2, 3, 4])):
        eid = rb() | 1
        ids.append(eid)
        t = r.random()
        if t < 0.1:
            ents[eid] = 0
        elif t < 0.17:
            ents[eid] = own1
        elif t < 0.24:
            ents[eid] = own2
        else:
            ents[eid] = mk_entity()
    tie = TIE is not None and r.random() < 0.25
    if tie:
        ents.clear()
        ids[:] = []
        zero_b[0] = True
        for xv in (TIE[1], TIE[0]):
            eid = rb() | 1
            ids.append(eid)
            ent = mk_entity(parent_none=True, accept=True, shape_x=xv)
            ents[eid] = ent
    T = obj(c, 0x20, {0x58: pystub(c, 1, this=True, ret=lambda emu, k: ents.get(emu.arg32(0), 0))}, nslots=0x60)
    E = rnd(c, 0x100)
    w32u(E + 0x9b, T)
    e.w32(0x70039c, E)
    st = {'i': 0}

    def l4c(emu, k):
        st['i'] = 0
        emu.w32(emu.arg32(0), 1)

    def l5c(emu, k):
        i = st['i']
        if i < len(ids):
            emu.w32(emu.arg32(0), 1)
            st['i'] = i + 1
            return ids[i]
        emu.w32(emu.arg32(0), 0)
        return 0
    L = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, stackmark=(0,), side=l4c),
                      0x5c: pystub(c, 1, this=True, stackmark=(0,), ret=l5c),
                      0x44: pystub(c, 1, this=True, stackmark=(0,))}, nslots=0x30)

    def b384(emu, k):
        emu.wbytes(emu.arg32(1), struct.pack('<3f', *([0.0, 0.0, 0.0] if zero_b[0] else [fv(), fv(), fv()])))
        emu.calllog.append(('t384', bytes(emu.rbytes(emu.arg32(0), 32)), bytes(emu.rbytes(emu.arg32(1), 12))))

    def t654(emu, k):
        emu.calllog.append(('t654', emu.arg32(0), bytes(emu.rbytes(emu.arg32(1), 12)), bytes(emu.rbytes(emu.arg32(2), 12)), emu.arg32(3)))
    this = obj(c, 0x800, {0x384: pystub(c, 2, this=True, stackmark=(0, 1), side=b384),
                          0x528: pystub(c, 0, this=True, ret=L if r.random() < 0.9 else 0),
                          0x504: pystub(c, 0, this=True, ret=own1),
                          0x500: pystub(c, 0, this=True, ret=own2),
                          0x654: pystub(c, 4, this=True, stackmark=(1, 2), side=t654, ret=lambda emu, k: (rb() & ~0xff) | (1 if (zero_b[0] or r.random() < 0.7) else 0))}, nslots=0x1a0)
    e.wbytes(this + 0x7c6, struct.pack('<H', r.choice([0, 1, 0x1234])))
    return [this]


S(0x591f60, 'nearest_candidate', 'thiscall', None, ret='eax', gen=g591f60)
