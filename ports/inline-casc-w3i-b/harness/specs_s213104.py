"""specs_s213104.py - batch 213104: ray query from a randomised probe vector and basis build, Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')


def g591480(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    small = [0.0, 0.0, 1.0, -1.0, 0.5, 200.0, -50.0, 3.0]

    def fv():
        return f32(r.choice(small + [r.uniform(-300, 300)]))

    def vec3():
        return struct.pack('<fff', fv(), fv(), fv())

    def mat9():
        return struct.pack('<9f', *[fv() for _ in range(9)])
    state = {'ok': True}

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))

    # this
    this = obj(c, 0x440, {}, nslots=0x40)
    flagmode = r.random()
    if flagmode < 0.15:
        fl = r.getrandbits(32) & ~0x0c000000
    else:
        fl = (r.getrandbits(32) & ~0x0c000000) | r.choice([0x04000000, 0x08000000, 0x0c000000])
    if r.random() < 0.5:
        fl &= ~3
    e.w32(this + 0x417, fl)
    X = None

    def s84(emu, k):
        lg(emu, 'v10', emu.arg32(0), 12)
    e.w32(e.r32(this) + 0x84, pystub(c, 1, this=True, nullflag=(0,), side=s84))
    e.w32(this + 8, rnd(c, 0x20))
    # engine
    thr = [0.0, 0.5, 1.0, NAN, 1e9, -2.0]

    def rand_st0(emu, k):
        return r.choice([r.random(), r.random(), 0.0, 1.0, 0.25, r.choice(thr)])
    eng = obj(c, 0x1b10, {0x1c0: pystub(c, 2, this=True, st0=rand_st0)}, nslots=0x80)
    A = rnd(c, 0x40)
    Bc = rnd(c, 0x40)
    e.w32(Bc + 0x23, (r.getrandbits(32) | 0x100000) if r.random() < 0.7 else (r.getrandbits(32) & ~0x100000))

    def s1bc(emu, k):
        lg(emu, 'n1bc', emu.arg32(1), 36)
        lg(emu, 'l1bc', emu.arg32(2), 12)
    B = obj(c, 0x40, {0x1bc: pystub(c, 7, this=True, nullflag=(1, 2), side=s1bc)}, nslots=0x80)
    e.w32(B + 0xc, Bc)

    def s94(emu, k):
        lg(emu, 'n94', emu.arg32(0), 36)
        lg(emu, 'l94', emu.arg32(1), 12)
    X = obj(c, 0x20, {0x94: pystub(c, 2, this=True, nullflag=(0, 1), side=s94)}, nslots=0x80)

    def s88(emu, k):
        lg(emu, 'm88', emu.arg32(0), 36)
        if r.random() < 0.5:
            emu.wbytes(emu.arg32(0), mat9())
    Hq = obj(c, 0x20, {0x88: pystub(c, 1, this=True, nullflag=(0,), side=s88)}, nslots=0x40)
    H = rnd(c, 0x80)
    e.w32(H + 0x54, Hq)
    # table
    T = obj(c, 0x20, {0x160: pystub(c, 1, this=True, ret=lambda emu, k: A if r.random() < 0.85 else 0),
                      0x58: pystub(c, 1, this=True, ret=lambda emu, k: B if r.random() < 0.85 else 0)}, nslots=0x80)
    e.w32(eng + 0x9b, T)
    # ray query object
    def s30(emu, k):
        R = emu.arg32(0)
        lg(emu, 'r30', R, 4)
        lg(emu, 'v30', emu.arg32(2), 12)
        lg(emu, 'p30', emu.arg32(3), 12)
        state['ok'] = r.random() < 0.8
        buf = bytearray(struct.pack('<f', fv()) + vec3())
        buf += struct.pack('<I', H)
        buf += bytes(r.getrandbits(8) for _ in range(0x28 - len(buf)))
        emu.wbytes(R, bytes(buf))
    Oo = obj(c, 0x20, {0x30: pystub(c, 8, this=True, nullflag=(0, 2, 3), side=s30,
                                    ret=lambda emu, k: (r.getrandbits(32) & ~0xff) | (1 if state['ok'] else 0))}, nslots=0x40)
    G1 = rnd(c, 0x40)
    e.w32(G1 + 0x1c, Oo)
    e.w32(eng + 0x1aa3, G1)
    e.w32(0x70039c, eng)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))

    def s1940(emu, k):
        lg(emu, 'w', emu.reg('edx'), 12)
        lg(emu, 'v1940', emu.reg('ecx'), 12)
        if r.random() < 0.7:
            emu.wbytes(emu.reg('ecx'), vec3())
    hook_rec(c, 0x441940, 0, pop=0, this='mark', side=s1940)
    hook_rec(c, 0x4664a0, 1, pop=4, this=True)
    hook_rec(c, 0x4db3b0, 0, pop=0, this=True, ret=lambda emu, k: X if r.random() > 0.2 else 0)

    def s581(emu, k):
        lg(emu, 'r581', emu.reg('ecx'), 0x28)
        emu.wbytes(emu.arg32(0), mat9())
    hook_rec(c, 0x581b60, 1, pop=4, this='mark', nullflag=(0,), side=s581)

    def sde(emu, k):
        lg(emu, 'mde', emu.reg('edx'), 36)
        emu.wbytes(emu.reg('ecx'), mat9())
    hook_rec(c, 0x4de040, 1, pop=4, this='mark', side=sde)

    def s09b0(emu, k):
        lg(emu, 'n09b0', emu.reg('ecx'), 36)
        if r.random() < 0.5:
            emu.wbytes(emu.reg('ecx'), mat9())
    hook_rec(c, 0x4e09b0, 0, pop=0, this='mark', side=s09b0)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this, F(fv())]


S(0x591480, 'ray_basis_attach', 'thiscall', None, ret=None, gen=g591480)
