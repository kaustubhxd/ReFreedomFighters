"""specs_s213170.py - batch 213170: swept ray query for a projectile (51 KB frame, real matrix / vector helpers, hooks for the engine query and the effect messages), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def g4748b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)

    def rvec(scale=10.0):
        return struct.pack('<3f', *[f32(r.choice([0.0, 1.0, -1.0, r.uniform(-scale, scale)])) for _ in range(3)])

    def rmat():
        k = r.random()
        if k < 0.4:
            m = [1, 0, 0, 0, 1, 0, 0, 0, 1]
        elif k < 0.6:
            m = [0, 1, 0, 0, 0, 1, 1, 0, 0]
        else:
            m = [r.uniform(-1, 1) for _ in range(9)]
        return struct.pack('<9f', *[f32(x) for x in m])

    def lg(emu, k):
        pass
    M = obj(c, 0x20, {0x2c: pystub(c, 4, pop=0, this=True)}, nslots=0x20)
    Lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=M, this=True)}, nslots=0x10)
    e.w32(0x700390, Lg)
    e.w32(0x7003b0, pystub(c, 0, this=True))

    calls = {'q': 0}
    hit_at = r.choice([1, 1, 2, 3, 5, 100])

    def s4ea300(emu, k):
        calls['q'] += 1
        q = emu.reg('ecx')
        emu.w32(q + 8, rb() | 1 if calls['q'] >= hit_at else 0)
        emu.calllog.append(('q300', emu.arg32(0), bytes(emu.rbytes(q + 0x18, 0x24)), bytes(emu.rbytes(q + 0x3c, 0x18))))
    hook_rec(c, 0x4ea300, 1, pop=4, this=True, side=s4ea300)
    hook_rec(c, 0x4db2f0, 1, pop=4, this=True, ret=lambda emu, k: rb())

    def s4e0a10(emu, k):
        v = rvec(1.0)
        emu.wbytes(emu.reg('ecx'), v)
        emu.calllog.append(('rv', v))
    hook_rec(c, 0x4e0a10, 0, pop=0, this=False, side=s4e0a10)

    query = rnd(c, 0x80)
    qm = obj(c, 0x40, {0x48: pystub(c, 2, this=True, stackmark=(0,), ret=query),
                       0x4c: pystub(c, 1, this=True)}, nslots=0x60)
    A = rnd(c, 0x40)
    w32u(A + 0x1c, qm)

    def t114(emu, k):
        return (rb() & ~0xffff) | r.getrandbits(16)
    T = obj(c, 0x20, {0x114: pystub(c, 4, this=True, ret=t114)}, nslots=0x140)
    eng = rnd(c, 0x2000)
    w32u(eng + 0x9b, T)
    w32u(eng + 0x1aa3, A)
    e.w32(0x70039c, eng)

    st = {'n': 0}

    def s5c(emu, k):
        n = st['n']
        st['n'] += 1
        a1 = emu.arg32(1)
        if n == 3 and a1 != 0:
            emu.calllog.append(('f5c', n, bytes(emu.rbytes(a1, 4))))
        elif n == 4 and a1 != 0:
            emu.calllog.append(('f5c', n, bytes(emu.rbytes(a1, 0x88))))
    fx = obj(c, 0x40, {0x5c: pystub(c, 3, this=True, stackmark=(1,), side=s5c)}, nslots=0x60)
    objX = obj(c, 0x20, {0x318: pystub(c, 0, this=True, ret=lambda emu, k: rb())}, nslots=0x140)

    def s2c4(emu, k):
        emu.wbytes(emu.arg32(0), rmat())
        emu.wbytes(emu.arg32(1), rvec())
        emu.calllog.append(('s2c4', bytes(emu.rbytes(emu.arg32(0), 36))))

    def s80(emu, k):
        emu.wbytes(emu.arg32(0), rmat())
        emu.wbytes(emu.arg32(1), rvec())
        emu.calllog.append(('s80', bytes(emu.rbytes(emu.arg32(0), 36))))

    def s7c(emu, k):
        emu.calllog.append(('s7c', bytes(emu.rbytes(emu.arg32(0), 36)), bytes(emu.rbytes(emu.arg32(1), 12))))
    fx_ret = fx if r.random() < 0.85 else 0
    blk = rnd(c, 0x80)
    for off in (0x30, 0x40):
        e.wbytes(blk + off, rvec(5.0))
    proj = obj(c, 0x40, {0x2d0: pystub(c, 2, this=True), 0x2c4: pystub(c, 2, this=True, stackmark=(0, 1), side=s2c4),
                         0x2f0: pystub(c, 3, this=True), 0x7c: pystub(c, 2, this=True, stackmark=(0, 1), side=s7c),
                         0x2e8: pystub(c, 0, this=True, ret=objX), 0x10c: pystub(c, 2, this=True, ret=fx_ret),
                         0x80: pystub(c, 2, this=True, stackmark=(0, 1), side=s80)}, nslots=0x320)
    w32u(proj + 8, blk)

    def s384(emu, k):
        emu.wbytes(emu.arg32(0), rmat())
        emu.calllog.append(('s384', bytes(emu.rbytes(emu.arg32(1), 12))))
    this = obj(c, 0x40, {0x384: pystub(c, 2, this=True, stackmark=(0, 1), side=s384)}, nslots=0x100)
    w32u(this + 8, rnd(c, 0x80))
    return [this, proj]


S(0x4748b0, 'ray_query', 'thiscall', None, ret=None, gen=g4748b0, stack_arg_bytes=4)
