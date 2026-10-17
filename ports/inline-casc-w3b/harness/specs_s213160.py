"""specs_s213160.py - batch 213160: named-node placement (string copies, node list scan, matrix building with real helpers), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def g576a30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def wf(addr, v):
        e.wbytes(addr, struct.pack('<f', f32(v)))

    def fv():
        return r.choice([0.0, 1.0, -1.0, 0.5, 2.0, r.uniform(-3, 3)])

    def mkstr(b):
        a = e.alloc(16, 4)
        e.wbytes(a, b + b'\0' * 8)
        return a
    names = [b'Hero', b'C06A', b'C09A', b'Ab', b'Hero', b'Car', b'X', b'']
    nm = r.choice(names)
    name_ptr = mkstr(nm)
    # hooks
    hook_rec(c, 0x5b1000, 1, pop=4, this=True, ret=lambda emu, k: (rb() & ~0xff) | (1 if r.random() < 0.3 else 0))

    def h5b15d0(emu, k):
        emu.w32(emu.arg32(1), r.choice([0xfffffffd, 0xfffffffe, 0xffffffff, 0, 1, 5]))
        emu.wbytes(emu.arg32(2), struct.pack('<3f', fv(), fv(), fv()))
        emu.wbytes(emu.arg32(3), struct.pack('<12f', *[f32(fv()) for _ in range(12)]))
        emu.calllog.append(('m5b15d0', emu.arg32(0)))
    hook_rec(c, 0x5b15d0, 4, pop=0x10, this=True, stackmark=(1, 2, 3), side=h5b15d0)
    hook_rec(c, 0x574680, 5, pop=0x14, this=True, stackmark=(3,))
    # [this+0x94] block
    g94 = rnd(c, 0x1100)
    same = r.random() < 0.3
    e.wbytes(g94 + 0x48, nm + b'\0' * 8 if same else r.choice(names) + b'\0' * 8)
    e.wbytes(g94 + 0x103e, bytes([r.choice([0, 0, 0, 1])]))
    # engine / table / object-id source
    Xo = obj(c, 0x20, {0x0: pystub(c, 2, this=True, stackmark=(1,), side=lambda emu, k: emu.calllog.append(('x0', emu.arg32(0), bytes(emu.rbytes(emu.arg32(1), 8)).split(b'\0')[0])), ret=lambda emu, k: rb())}, nslots=0x10)
    L2 = None
    tbl_slots = {}
    # entity chain
    def mk_prop():
        prop = obj(c, 0x40, {0x70: pystub(c, 1, this=True, stackmark=(0,), side=lambda emu, k: emu.calllog.append(('p70', bytes(emu.rbytes(emu.arg32(0), 12))))),
                             0x6c: pystub(c, 1, this=True, stackmark=(0,), side=lambda emu, k: emu.calllog.append(('p6c', bytes(emu.rbytes(emu.arg32(0), 48))))),
                             0xbc: pystub(c, 1, this=True)}, nslots=0x40)
        pn = r.choice([b'Hero', b'Hero', b'hero', b'Wheel', b''])
        w32u(prop + 4, mkstr(pn) if pn else 0)
        return prop
    nodes = []
    for i in range(r.choice([0, 1, 2, 3, 4])):
        nd = rnd(c, 0x80)
        w32u(nd + 0x54, mk_prop())
        nodes.append(nd)
    st = {'i': 1}

    def nxt(emu, k):
        i = st['i']
        st['i'] += 1
        emu.w32(emu.arg32(0), nodes[i] if i < len(nodes) else 0)
    Lst = obj(c, 0x40, {0x50: pystub(c, 1, this=True, stackmark=(0,), side=nxt)}, nslots=0x30)
    w32u(Lst + 8, nodes[0] if nodes else 0)
    par = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=Lst)}, nslots=0x80)
    ent = obj(c, 0x20, {0x20: pystub(c, 0, this=True, ret=par)}, nslots=0x20)
    Tb = obj(c, 0x20 + 0xae4 + 8, {0x58: pystub(c, 1, this=True, ret=ent),
                                   0x114: pystub(c, 5, this=True, ret=lambda emu, k: (rb() & ~0xffff) | r.choice([0, 1, 0x1234, 0xffff]))}, nslots=0x80)
    w32u(Tb + 0xae4, Xo)
    O = obj(c, 0x20, {0xdc: pystub(c, 0, this=True, ret=lambda emu, k: (rb() & ~0xff) | (1 if r.random() < 0.5 else 0))}, nslots=0x40)
    E = obj(c, 0x100, {0xbc: pystub(c, 0, this=True, ret=O)}, nslots=0x40)
    w32u(E + 0x9b, Tb)
    e.w32(0x70039c, E)

    def mh(em, res_):
        em.calllog.append(('mlog', em.reg('ecx'), em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)
    M = obj(c, 0x20, {0x2c: e.stub_fn('mlog', mh)}, nslots=0x20)
    Lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=M, this=True)}, nslots=0x10)
    e.w32(0x700390, Lg)
    # this
    me = obj(c, 0x40, {0x130: pystub(c, 2, this=True)}, nslots=0x50)
    po = rnd(c, 0x100)
    for off in range(0, 0x60, 4):
        wf(po + off, fv())
    o2 = obj(c, 0x40, {0x20: pystub(c, 0, this=True, ret=rnd(c, 0x40))}, nslots=0x30)
    # o2.vt20 returns an object whose [+8] points to the float block
    holder = rnd(c, 0x40)
    w32u(holder + 8, po)
    o90 = obj(c, 0x40, {0x20: pystub(c, 0, this=True, ret=holder)}, nslots=0x30)
    this = rnd(c, 0x400)
    w32u(this + 0x94, g94)
    w32u(this + 0x90, o90)
    w32u(this + 0x44, me)
    w32u(this + 0x1b8, rb())
    e.wbytes(this + 0x20b, bytes([1]))
    e.wbytes(this + 0x20c, bytes([2]))
    return [this, name_ptr]


S(0x576a30, 'node_placement', 'thiscall', None, ret=None, gen=g576a30, stack_arg_bytes=48)
