"""specs_s213096.py - batch 213096: proximity scan over an embedded list with table lookups, Sonnet-w3b."""
import math
import struct
from unicorn.x86_const import UC_X86_REG_XMM0
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')


def g5bd0d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sl = lambda n, ret=None, **kw: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, **kw)
    thr = struct.unpack('<f', bytes(e.rbytes(0x67d164, 4)))[0]

    def fl():
        return r.choice([0.0, 1.0, -1.0, 2.0, thr, thr * 0.5, thr * 2, r.uniform(-3, 3), r.uniform(-thr, thr) if thr == thr else 0.0, NAN])

    def vec3():
        return struct.pack('<fff', fl(), fl(), fl())

    def sqrt_side(em, k):
        a = em.reg('xmm0') & ((1 << 64) - 1)
        x = struct.unpack('<d', struct.pack('<Q', a))[0]
        em.calllog.append(('sqrt', a))
        try:
            z = math.sqrt(x)
        except ValueError:
            z = math.nan
        em.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', z))[0])
    hook_rec(c, 0x634d7c, 0, side=sqrt_side)

    def out2(emu, k):
        emu.wbytes(emu.arg32(0), vec3())
        emu.wbytes(emu.arg32(1), vec3())

    def mkobj():
        O = obj(c, 0x20, {0x2f0: sl(3), 0x210: sl(1)}, nslots=0x100)
        second = [0 if r.random() < 0.3 else O]
        return obj(c, 0x20, {0x80: sl(2, nullflag=(0, 1), side=out2), 0x20: sl(0, lambda emu, k, O=O, second=second: O if k % 2 == 0 else second[0])}, nslots=0x100)
    pool = [mkobj() for _ in range(3)]

    def t58(emu, rr):
        i = emu.arg32(0)
        emu.calllog.append(('t58', i))
        emu.ret(eax=pool[i % 3], argbytes=4)
    want = r.getrandbits(16)

    def t114(emu, rr):
        a = tuple(emu.arg32(i) for i in range(4))
        emu.calllog.append(('t114', a))
        emu.ret(eax=want if a[3] == 0x2c and r.random() < 0.8 else r.getrandbits(32), argbytes=16)
    T = obj(c, 0x20, {0x58: e.stub_fn('t58', t58), 0x114: e.stub_fn('t114', t114)}, nslots=0x120)
    eng = rnd(c, 0x100)
    e.w32(eng + 0x9b, T)
    e.w32(0x70039c, eng)
    M = obj(c, 0x20, {0x2c: pystub(c, 3, ret=r.getrandbits(32), this=True, pop=0)}, nslots=0x14)
    Lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=M, this=True)}, nslots=0x10)
    e.w32(0x700390, Lg)
    items = [r.choice([0, 0x10, 0x11, 0x12, 0x20]) for _ in range(r.choice([0, 1, 2, 3, 4]))]
    state = {'i': 0}

    def l4c(emu, rr):
        state['i'] = 0
        emu.calllog.append(('l4c',))
        emu.ret(eax=r.getrandbits(32), argbytes=4)

    def l5c(emu, rr):
        i = state['i']
        state['i'] += 1
        if i < len(items):
            it, flag = items[i], 1
        else:
            it, flag = 0, 0
        emu.w32(emu.arg32(0), flag)
        emu.calllog.append(('l5c', it))
        emu.ret(eax=it, argbytes=4)
    lv = obj(c, 0x20, {0x4c: e.stub_fn('l4c', l4c), 0x5c: e.stub_fn('l5c', l5c)}, nslots=0x40)
    W = obj(c, 0x20, {0x12c: sl(3)}, nslots=0x100)
    this = rnd(c, 0x90)
    e.w32(this + 0x4c, e.r32(lv))
    e.w32(this + 0x44, W)
    e.w32(this + 0x48, pool[0])
    b = rnd(c, 0x10)
    e.w32(b + 4, r.getrandbits(32))

    def sub_side(emu, k):
        emu.calllog.append(('sub', bytes(emu.rbytes(emu.reg('edx'), 12)), bytes(emu.rbytes(emu.arg32(0), 12))))
        emu.wbytes(emu.reg('ecx'), vec3())
    hook_rec(c, 0x43e920, 1, pop=4, nullflag=(0,), side=sub_side)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    code = want if r.random() < 0.85 else r.getrandbits(16)
    code |= r.choice([0, 0, 0x10000])
    return [this, code, b]


S(0x5bd0d0, 'proximity_scan', 'thiscall', None, ret=None, gen=g5bd0d0)
