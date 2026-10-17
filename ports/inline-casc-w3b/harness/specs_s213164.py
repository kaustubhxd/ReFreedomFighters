"""specs_s213164.py - batch 213164: area effect emitter (iterator query + id list, per entity hit record with direction/falloff, x87 normalise), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def g5833e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def fl(lo=-5.0, hi=5.0):
        return r.choice([0.0, 0.0, 1.0, -1.0, 2.5, r.uniform(lo, hi)])

    def vb(vals):
        return struct.pack('<3f', *[f32(x) for x in vals])

    def rvec():
        return [fl() for _ in range(3)]

    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    e.w32(0x7003b0, pystub(c, 0, this=True))
    e.wbytes(0x714288, struct.pack('<H', r.getrandbits(16)))

    # hooks
    hook_rec(c, 0x584aa0, 3, pop=12, this=True)

    def t5db(emu, k):
        emu.calllog.append(('p5db', bytes(emu.rbytes(emu.arg32(0), 12))))
    hook_rec(c, 0x5dbed0, 1, pop=4, this=True, stackmark=(0,), side=t5db,
             ret=lambda emu, k: (rb() & ~0xff) | (1 if r.random() < 0.6 else 0))

    def t4e0a(emu, k):
        d = emu.reg('ecx')
        v = vb(rvec())
        emu.wbytes(d, v)
        emu.calllog.append(('rv', v))
    hook_rec(c, 0x4e0a10, 0, pop=0, side=t4e0a)

    big = r.random() < 0.6
    eq = r.choice([None, None, None, 'A', 'B'])
    hy_P = r.choice([1.0, 2.0, 3.5])
    # entity objects
    def mk_blk():
        b = rnd(c, 0x80)
        for off in range(0x30, 0x50, 4):
            e.wbytes(b + off, struct.pack('<f', f32(fl(-3, 3))))
        if eq:
            for off in range(0x30, 0x3c, 4):
                e.wbytes(b + off, struct.pack('<f', 0.0))
            for off in range(0x40, 0x4c, 4):
                e.wbytes(b + off, struct.pack('<f', f32(r.choice([1.0, 2.0, 3.5]))))
        elif big:
            for off in range(0x30, 0x3c, 4):
                e.wbytes(b + off, struct.pack('<f', f32(r.uniform(-0.3, 0.3))))
            for off in range(0x40, 0x4c, 4):
                e.wbytes(b + off, struct.pack('<f', f32(r.uniform(2.0, 7.0))))
        return b

    def hit128(emu, k):
        emu.calllog.append(('h128', emu.arg32(0), bytes(emu.rbytes(emu.arg32(1), 0x2c)), emu.arg32(2)))

    def s384(emu, k):
        v = vb(rvec())
        emu.wbytes(emu.arg32(1), v)
        emu.wbytes(emu.arg32(0), vb(rvec()))
        emu.calllog.append(('s384', v))

    def s8c(emu, k):
        v = vb([0.0, 0.0, 0.0] if eq else rvec())
        emu.wbytes(emu.arg32(0), v)
        emu.calllog.append(('s8c', v))

    def s84(emu, k):
        v = vb(rvec())
        emu.wbytes(emu.arg32(0), v)
        emu.calllog.append(('s84', v))

    def mk_ent():
        return obj(c, 0x40, {0x384: pystub(c, 2, this=True, stackmark=(0, 1), side=s384),
                             0x128: pystub(c, 3, this=True, stackmark=(1,), side=hit128),
                             0x8c: pystub(c, 1, this=True, stackmark=(0,), side=s8c),
                             0x84: pystub(c, 1, this=True, stackmark=(0,), side=s84)}, nslots=0x100)
    ents = []
    for _ in range(r.choice([0, 1, 2, 3])):
        en = mk_ent()
        w32u(en + 8, mk_blk())
        ents.append(en)
    ids = {}
    idl = []
    for _ in range(r.choice([0, 1, 2, 3])):
        i = rb() | 1
        idl.append(i)
        if r.random() < 0.75:
            en = mk_ent()
            w32u(en + 8, mk_blk())
            ids[i] = en
    st = {'i': 0}

    def s84it(emu, k):
        i = st['i']
        st['i'] += 1
        emu.calllog.append(('it84', bytes(emu.rbytes(emu.arg32(0), 12)), emu.arg32(2)))
        return ents[i] if i < len(ents) else 0
    It = obj(c, 0x20, {0x84: pystub(c, 4, this=True, stackmark=(0, 2), side=lambda emu, k: None, ret=s84it)}, nslots=0x100)
    # the stub above logs through the recorder; log -0x28 content explicitly in a wrapper
    st2 = {}

    def t58(emu, k):
        emu.calllog.append(('t58', emu.arg32(0)))
        return ids.get(emu.arg32(0), 0)
    own_id = rb() | 1
    kind = r.choice([0, 0, 1, 1, 1, 2, 2, 3])
    Tab = obj(c, 0x20, {0x58: pystub(c, 1, this=True, ret=t58),
                        0x4c: pystub(c, 1, this=True, ret=lambda emu, k: rb())}, nslots=0x60)
    eng = rnd(c, 0x200)
    w32u(eng + 0x9b, Tab)
    e.w32(0x70039c, eng)
    ng = rnd(c, 0x2c40)
    w32u(ng + 0x4ac, rb() if r.random() < 0.5 else 0)
    arr = e.alloc(0x40, 4)
    for j, i in enumerate(idl):
        w32u(arr + 4 * j, i)
    w32u(ng + 0x4a0, arr)
    w32u(ng + 0x4a4, arr + 4 * len(idl))
    w32u(ng + 0x2c11, It)
    e.w32(0x7003b8, ng)

    def sP80(emu, k):
        v = vb(rvec())
        emu.wbytes(emu.arg32(1), v)
        emu.calllog.append(('sP80', v))
    Pobj = obj(c, 0x40, {0x1e0: pystub(c, 1, this=True, ret=lambda emu, k: (rb() & ~0xff) | (1 if r.random() < 0.7 else 0)),
                         0x80: pystub(c, 2, this=True, stackmark=(0, 1), side=sP80),
                         0x20: pystub(c, 0, this=True, ret=lambda emu, k: rb()),
                         0x8c: pystub(c, 1, this=True, stackmark=(0,), side=s8c)}, nslots=0x100)
    Pblk = rnd(c, 0x80)
    for off in range(0x30, 0x4c, 4):
        e.wbytes(Pblk + off, struct.pack('<f', f32(fl(-3, 3) if not big else (r.uniform(-0.3, 0.3) if off < 0x3c else r.uniform(2.0, 7.0)))))
    if eq:
        for off in range(0x30, 0x3c, 4):
            e.wbytes(Pblk + off, struct.pack('<f', 0.0))
        for off in range(0x40, 0x4c, 4):
            e.wbytes(Pblk + off, struct.pack('<f', f32(hy_P)))
    w32u(Pobj + 8, Pblk)
    this = rnd(c, 0x100)
    w32u(this + 0x44, Pobj)
    rad = r.choice([0.5, 2.0, 4.0, 10.0, 50.0, r.uniform(0.1, 20)])
    if eq == 'A':
        rad = -hy_P
    elif eq == 'B':
        rad = 0.0
    w32u(this + 0x51, struct.unpack('<I', struct.pack('<f', f32(rad)))[0])
    w32u(this + 0x55, struct.unpack('<I', struct.pack('<f', f32(r.choice([0.0, 0.25, 1.0, r.uniform(0, 3)]))))[0])
    w32u(this + 0x59, struct.unpack('<I', struct.pack('<f', f32(fl(0, 5))))[0])
    arg = rnd(c, 0x40)
    if kind == 1:
        sub = rnd(c, 0x40)
        w32u(sub + 0x24, rb())
        w32u(arg, rb() if r.random() < 0.5 else 0)
        w32u(arg + 4, sub if r.random() < 0.7 else 0)
        if r.random() < 0.12:
            arg = 0
    elif kind == 2:
        w32u(arg + 4, rb() if r.random() < 0.6 else 0)
    return [this, kind, arg]


S(0x5833e0, 'area_emit', 'thiscall', None, ret=None, gen=g5833e0, stack_arg_bytes=8)
