"""specs_s213089.py - batch 213090: best actor in front search over an iterated list, Sonnet-w3b."""
import math
import struct
from unicorn.x86_const import UC_X86_REG_XMM0
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')


def g5dfea0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    thr = struct.unpack('<f', bytes(e.rbytes(0x6aef84, 4)))[0]
    sl = lambda n, ret=None, **kw: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, **kw)

    def fl():
        return r.choice([0.0, -0.0, 1.0, -1.0, 0.5, 2.0, r.uniform(-3, 3), r.uniform(-1, 1), r.uniform(-1, 1), NAN])

    def vec3():
        return struct.pack('<fff', fl(), fl(), fl())

    def cos_side(em, k):
        a = em.reg('xmm0') & ((1 << 64) - 1)
        x = struct.unpack('<d', struct.pack('<Q', a))[0]
        em.calllog.append(('cos', a))
        try:
            z = math.cos(x)
        except (ValueError, OverflowError):
            z = math.nan
        em.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', z))[0])
    hook_rec(c, 0x634d70, 0, side=cos_side)

    # candidate objects
    nobj = r.choice([1, 2, 3, 4])
    ids = [0x100 + i for i in range(nobj)] + [0x110]
    special = r.random() < 0.3
    kf = struct.unpack('<f', struct.pack('<f', math.cos(struct.unpack('<d', bytes(e.rbytes(0x6b7518, 8)))[0])))[0]

    def c_side(emu, k):
        if r.random() < 0.8:
            emu.wbytes(emu.arg32(0), vec3())
    Ys = []
    for i in range(nobj):
        Ys.append(obj(c, 0x20, {0x1e0: sl(1, lambda emu, k: r.choice([0, 1, 1, 1, 0x100, 0xff])), 0x84: sl(1, nullflag=(0,), side=c_side), 0x128: sl(1)}, nslots=0x100))

    def b_a(emu, k):
        emu.wbytes(emu.arg32(0), struct.pack('<fff', kf, 0.0, 0.0) if special else vec3())
        emu.wbytes(emu.arg32(1), vec3())
    O = obj(c, 0x20, {0x80: sl(2, nullflag=(0, 1), side=b_a), 0x1e0: sl(1, lambda emu, k: r.choice([0, 1, 1, 0x100, 0xff])), 0x84: sl(1, nullflag=(0,))}, nslots=0x100)
    this = rnd(c, 0x20)
    e.w32(this + 8, O)
    state = {'idx': 0, 'items': [r.choice(ids) if r.random() < 0.9 else r.choice(ids) for _ in range(r.choice([0, 1, 2, 3, 4]))]}

    def t58(emu, rr):
        i = emu.arg32(0)
        emu.calllog.append(('t58', emu.reg('ecx'), i))
        emu.ret(eax=O if i == 0x110 else Ys[(i - 0x100) % nobj] if 0x100 <= i < 0x100 + nobj else Ys[0], argbytes=4)

    def t4c(emu, rr):
        emu.calllog.append(('t4c', emu.reg('ecx'), emu.arg32(0)))
        emu.ret(eax=r.getrandbits(32), argbytes=4)

    def t114(emu, rr):
        p = emu.arg32(4)
        f = bytes(emu.rbytes(p, 44))
        emu.calllog.append(('t114', emu.reg('ecx'), tuple(emu.arg32(i) for i in (0, 1, 2, 3, 5)), f[0:8] + f[16:44]))
        emu.ret(eax=r.choice([r.getrandbits(32), 0x1ffff, 5]), argbytes=24)
    Kobj = obj(c, 0x20, {0x25c: None}, nslots=0x100) if False else None
    Sobj = rnd(c, 0x40)
    Lobj = obj(c, 0x20, {}, nslots=0x100)
    Kobj = obj(c, 0x20, {0x25c: sl(2, Sobj)}, nslots=0x100)
    T = obj(c, 0xb00, {0x58: e.stub_fn('t58', t58), 0x4c: e.stub_fn('t4c', t4c), 0x114: e.stub_fn('t114', t114)}, nslots=0x120)
    e.w32(T + 0xadc, Kobj)
    eng = rnd(c, 0x100)
    e.w32(eng + 0x9b, T)
    e.w32(0x70039c, eng)

    def l4c(emu, rr):
        state['idx'] = 0
        emu.calllog.append(('l4c',))
        emu.w32(emu.arg32(0), len(state['items']))
        emu.ret(eax=r.getrandbits(32), argbytes=4)

    def l5c(emu, rr):
        i = state['idx']
        items = state['items']
        if i < len(items):
            it = items[i]
            state['idx'] += 1
            emu.w32(emu.arg32(0), 1)
        else:
            it = 0
            emu.w32(emu.arg32(0), 0)
        emu.calllog.append(('l5c', it))
        emu.ret(eax=it, argbytes=4)
    lv = obj(c, 0x20, {0x4c: e.stub_fn('l4c', l4c), 0x5c: e.stub_fn('l5c', l5c)}, nslots=0x100)
    e.w32(Sobj + 0x18, lv)

    def b_side(emu, k):
        emu.calllog.append(('b', bytes(emu.rbytes(emu.reg('ecx'), 12))))
        if r.random() < 0.5 and not special:
            emu.wbytes(emu.reg('ecx'), vec3())
    hook_rec(c, 0x4e09b0, 0, this='mark', side=b_side)

    def dval(emu, k):
        emu.calllog.append(('dist', bytes(emu.rbytes(emu.reg('ecx'), 12)), bytes(emu.rbytes(emu.reg('edx'), 12))))
        return r.choice([thr * 0.5, thr * 2, thr, 0.0, -1.0, NAN, r.uniform(0, thr * 2)])
    hook_rec(c, 0x4e0830, 0, pop=0, st0=dval)

    def sub_side(emu, k):
        emu.calllog.append(('sub', bytes(emu.rbytes(emu.reg('edx'), 12)), bytes(emu.rbytes(emu.arg32(0), 12))))
        emu.wbytes(emu.reg('ecx'), struct.pack('<fff', 1.0, 0.0, 0.0) if special else (vec3() if r.random() < 0.9 else struct.pack('<fff', 1.0, 0.0, 0.0)))
    hook_rec(c, 0x43e920, 1, pop=4, nullflag=(0,), side=sub_side)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this]


S(0x5dfea0, 'best_actor_in_front_b', 'thiscall', None, ret='al', gen=g5dfea0)
