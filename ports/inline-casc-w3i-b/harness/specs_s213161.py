"""specs_s213161.py - batch 213161: ray/segment record queue add-or-refresh (ring buffer of 0x32 byte entries, trace hit -> owner vcall), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def g52c270(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def fv():
        return r.choice([0.0, 1.0, -1.0, 0.5, 2.0, 100.0, r.uniform(-50, 50)])

    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    e.wbytes(0x701b58, bytes([1 if r.random() < 0.5 else 0]))

    def mh(em, res_):
        em.calllog.append(('mlog', em.reg('ecx'), em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=0)
    M = obj(c, 0x20, {0x2c: e.stub_fn('mlog', mh)}, nslots=0x20)
    Lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=M, this=True)}, nslots=0x10)
    e.w32(0x700390, Lg)
    e.w32(0x7003b0, pystub(c, 0, this=True))

    # ring
    cap = r.choice([2, 3, 4, 5, 8])
    ids = [r.choice([1, 2, 3, 0x1234, rb()]) for _ in range(cap)]
    base = rnd(c, cap * 0x32 + 8)
    for i in range(cap):
        w32u(base + i * 0x32 + 4, ids[i])
    head = r.randrange(cap)
    tail = r.choice([head, head, (head + 1) % cap, r.randrange(cap), (head + 2) % cap])
    Q = rnd(c, 0x30)
    w32u(Q, base)
    w32u(Q + 4, cap)
    w32u(Q + 8, head)
    w32u(Q + 0xc, tail)
    w32u(Q + 0x10, rb())

    # hooks
    def t531(emu, k):
        emu.calllog.append(('p531', bytes(emu.rbytes(emu.arg32(0), 12)), bytes(emu.rbytes(emu.arg32(1), 12))))
    hit_p = r.choice([0.0, 0.5, 1.0])
    hook_rec(c, 0x531a50, 3, pop=12, this=True, stackmark=(0, 1), side=t531,
             ret=lambda emu, k: (rb() | 1) if r.random() < hit_p else 0)
    hook_rec(c, 0x52b4e0, 1, pop=4, this=True, ret=lambda emu, k: rb())

    def alloc20(emu, k):
        return emu.alloc(0x20, 4)
    hook_rec(c, 0x41e290, 1, pop=0, ret=alloc20)

    def t52a(emu, k):
        emu.calllog.append(('e52a', bytes(emu.rbytes(emu.arg32(0), 0x32))))
    ok_p = r.choice([0.0, 0.5, 1.0, 1.0])
    hook_rec(c, 0x52a700, 1, pop=4, this=True, stackmark=(0,), side=t52a,
             ret=lambda emu, k: (rb() & ~0xff) | (1 if r.random() < ok_p else 0))
    hook_rec(c, 0x52c000, 1, pop=4, this=True)

    # owner of an id
    def t128(emu, k):
        emu.calllog.append(('o128', emu.arg32(0), bytes(emu.rbytes(emu.arg32(1), 0x20)), emu.arg32(2)))
    item = obj(c, 0x20, {0x128: pystub(c, 3, this=True, side=t128)}, nslots=0x60)
    ent = rnd(c, 0x80)
    w32u(ent + 0x54, item if r.random() < 0.8 else 0)
    T = obj(c, 0x20, {0x54: pystub(c, 1, this=True, ret=lambda emu, k: ent if r.random() < 0.8 else 0,
                                   side=lambda emu, k: emu.calllog.append(('t54', emu.arg32(0))))}, nslots=0x60)
    eng = rnd(c, 0x200)
    w32u(eng + 0x9b, T)
    e.w32(0x70039c, eng)

    this = rnd(c, 0x200)
    w32u(this + 0x79, Q if r.random() < 0.93 else 0)
    e.wbytes(this + 0x31, bytes([r.choice([0, 1, 1, 0x80])]))
    e.wbytes(this + 0x20, struct.pack('<f', f32(fv())))
    w32u(this + 0x49, rb())
    w32u(this + 0x65, rb())
    w32u(this + 0x75, r.choice([0, 5, 0xffffffff, rb()]))
    e.wbytes(this + 0x95, struct.pack('<H', r.getrandbits(16)))
    A = rnd(c, 12)
    B = rnd(c, 12)
    e.wbytes(A, struct.pack('<3f', f32(fv()), f32(fv()), f32(fv())))
    e.wbytes(B, struct.pack('<3f', f32(fv()), f32(fv()), f32(fv())))
    idv = r.choice([ids[r.randrange(cap)], ids[r.randrange(cap)], 0xffffffff, rb(), 0])
    fl = f32(fv())
    ub = lambda: r.choice([0, 1, 0x80, rb()])
    return [this, idv, A, B, rb(), struct.unpack('<I', struct.pack('<f', fl))[0], ub(), ub()]


S(0x52c270, 'seg_queue_add', 'thiscall', None, ret='eax', gen=g52c270, stack_arg_bytes=28)
