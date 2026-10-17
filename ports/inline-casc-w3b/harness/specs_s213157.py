"""specs_s213157.py - batch 213157: aim controller (yaw/pitch following, wrap, limit object; real 0x4e0130 / 0x5cf820 / 0x4e09b0 with CRT math hooks), Sonnet-w3b."""
import math
import os
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


def g5d1530(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    crt(c, 0x634d70, math.cos, 'cos')
    crt(c, 0x634d76, math.sin, 'sin')
    crt(c, 0x634d7c, math.sqrt, 'sqrt')
    crt(c, 0x634dbe, math.acos, 'acos')
    atan_vals = []
    atan_i = [0]

    def atan_fn(x):
        if atan_vals:
            v = atan_vals[atan_i[0] % len(atan_vals)]
            atan_i[0] += 1
            return v
        return math.atan(x)
    crt(c, 0x634de2, atan_fn, 'atan')

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def wf(addr, v):
        e.wbytes(addr, struct.pack('<f', f32(v)))
    PI = math.pi
    kinds = [9, 9, 9, 9, 9, 9, 9, 8, 0, 10]
    hook_rec(c, 0x591b20, 0, pop=0, this=True, ret=r.choice(kinds))

    def ang():
        return r.choice([0.0, 0.1, -0.1, 1.0, -1.0, 3.0, -3.0, 3.14, -3.14, 3.1215, -3.1215, 3.2, -3.2, 6.0, -6.0, 0.3, 0.52, -0.52, r.uniform(-4, 4), r.uniform(-7, 7)])

    def vec():
        return [r.choice([0.0, 0.0, 1.0, -1.0, 0.5, r.uniform(-3, 3)]) for _ in range(3)]
    aimv = vec()

    def b80(emu, k):
        emu.calllog.append(('b80', emu.arg32(0)))
        emu.wbytes(emu.arg32(0), struct.pack('<3f', *[f32(x) for x in aimv]))
    B = obj(c, 0x860, {0x80: pystub(c, 2, this=True, stackmark=(1,), side=b80)}, nslots=0x40)
    w32u(B + 0x84a, rb())
    limit_obj = 0
    mode_lim = r.random()
    if mode_lim < 0.8:
        limit_obj = rnd(c, 0x60)
        wf(limit_obj + 0x48, r.choice([0.0, 0.1, 0.3496, 1.0, 3.1216, 3.1215, 3.2, -0.5, -3.2, -3.1215, 2.0]))
    Q = obj(c, 0x20, {0x100: pystub(c, 1, this=True, ret=limit_obj)}, nslots=0x50)
    T = obj(c, 0x20, {0x58: pystub(c, 1, this=True, ret=Q)}, nslots=0x20)
    E = rnd(c, 0x100)
    w32u(E + 0x9b, T)
    wf(E + 0x48, r.choice([0.0, 0.016, 0.1, 1.0, 0.5]))
    e.w32(0x70039c, E)

    def mh(em, res_):
        d = struct.unpack('<d', bytes(em.rbytes(em.reg('esp') + 12, 8)))[0]
        em.calllog.append(('mlog', em.reg('ecx'), em.arg32(0), em.arg32(1), d))
        em.ret(eax=0, argbytes=0)
    M = obj(c, 0x20, {0x2c: e.stub_fn('mlog', mh)}, nslots=0x20)
    L = obj(c, 0x20, {0x20: pystub(c, 2, ret=M, this=True)}, nslots=0x10)
    e.w32(0x700390, L)
    this = rnd(c, 0xd40)
    w32u(this + 0x44, B)
    wf(this + 0xa54, ang())
    wf(this + 0xa5c, ang())
    e.wbytes(this + 0xa72, struct.pack('<3f', *[f32(x) for x in vec()]))
    e.wbytes(this + 0xb1a, bytes([r.choice([0, 0, 0, 1, 1, 0xff])]))
    w32u(this + 0xbd1, r.choice([0, 0, limit_obj, limit_obj]))
    if r.random() < (1.1 if os.environ.get('WHICH') else 0.85):
        # exact-boundary scenario: aim (-1, 0, -1) -> after 0x4e09b0 (1, 0, 1): 0x5cf820 calls atan twice (yaw, then pitch): both come from atan_vals
        def rf(addr):
            return struct.unpack('<f', bytes(e.rbytes(addr, 4)))[0]

        def bits(x):
            return struct.unpack('<I', struct.pack('<f', x))[0]

        def fb(b):
            return struct.unpack('<f', struct.pack('<I', b & 0xffffffff))[0]

        def nxt(x, k):
            b = bits(x)
            return fb(b + k) if x >= 0 else fb(b - k)
        C = {n: rf(a) for n, a in (('two', 0x68aef8), ('pm', 0x6a0bd0), ('pp', 0x6b4fa4), ('c4', 0x67af28), ('pi', 0x67da18), ('mpi', 0x6ad238), ('c5', 0x6ad1fc), ('c6', 0x6ad234))}
        aimv[:] = [-1.0, 0.0, -1.0]
        yaw = f32(r.choice([k / 1048576.0 * 1.0 for k in (524288, 1048576, 2097152, -524288, -1048576, 1572864, 3145728, 262144, 100000 * 2)]))
        X = f32(r.choice([0.0, 0.25, -0.25, 0.5, -0.5, 0.125]))
        atan_vals[:] = [yaw, X]
        atan_i[0] = 0
        two = C['two']

        def e_of(yc):
            t = yc if yaw <= yc else f32(yc + two)
            return f32(t - yaw)
        wf(this + 0xa72, 0.0)
        e.wbytes(this + 0xb1a, bytes([0]))
        lo = limit_obj
        if not lo:
            lo = rnd(c, 0x60)
        wf(lo + 0x48, 0.3)
        w32u(this + 0xbd1, lo)
        which = r.choice(['pm', 'pp', 'yeq', 'yeq', 'c4', 'pi', 'mpi', 'mpi', 'lim_e', 'lim_ne', 'lim_c5', 'lim_c5', 'lim_c5', 'lim_c6', 'vA', 'vB', 'logE', 'logE'])
        if os.environ.get('WHICH'):
            which = os.environ['WHICH']
        yc = f32(r.uniform(-3, 3))
        pc = f32(X + r.choice([0.0, 0.1, -0.1]))
        if which in ('pm', 'pp'):
            X = f32(r.choice([0.1, 0.2, -0.3, 0.7]))
            atan_vals[:] = [yaw, X]
            base = f32(X + C[which])
            pc = nxt(base, r.choice([-1, 0, 1]))
            best = None
            for k in range(-24, 25):
                cand = nxt(base, k)
                if f32(cand - X) == C[which]:
                    if f32(X + C[which]) != cand:
                        best = cand
                        break
                    if best is None:
                        best = cand
            if best is not None and r.random() < 0.85:
                pc = best
        elif which == 'yeq':
            yaw = f32(r.choice([0.7, 0.1, 1.3, -0.7, 2.1, 0.3333, -1.1]))
            atan_vals[:] = [yaw, X]
            yc = nxt(yaw, r.choice([-1, 0, 0, 1]))
            wf(lo + 0x48, r.choice([0.0, 1e-7, 1.5e-7, 5e-8, 2.4e-7, 3e-7]))
        elif which == 'logE':
            yc = f32(yaw - two - r.choice([0.01, 0.5, 1.0, 2.0, 3.0]))
            wf(lo + 0x48, r.choice([0.3, 3.0, 1.0]))
        elif which in ('c4', 'pi', 'mpi'):
            if which in ('pi', 'mpi'):
                yaw = f32(r.choice([2.0, 2.5, 1.5, 3.0]) + 2.0 ** -22)
                atan_vals[:] = [yaw, X]
            tgt = {'c4': C['c4'], 'pi': C['pi'], 'mpi': C['mpi']}[which]
            guess = f32(yaw + tgt - two) if which == 'c4' else (f32(yaw + tgt) if which == 'pi' else f32(yaw + tgt + 0.0))
            if which == 'mpi':
                guess = f32(yaw + tgt - two)
            found = None
            for k in range(-3000, 3001):
                cand = nxt(guess, k)
                if e_of(cand) == tgt:
                    found = cand
                    break
            if found is None:
                for base2 in (f32(yaw + tgt), f32(yaw + tgt - two), f32(yaw + tgt + two)):
                    for k in range(-3000, 3001):
                        cand = nxt(base2, k)
                        if e_of(cand) == tgt:
                            found = cand
                            break
                    if found is not None:
                        break
            if found is not None:
                yc = found
        elif which in ('lim_e', 'lim_ne'):
            ee = e_of(yc)
            wf(lo + 0x48, ee if which == 'lim_e' else -ee)
        elif which in ('lim_c5', 'lim_c6'):
            tgt_e = r.choice([3.1405, -3.1405, 3.1405, -3.1405, 3.141])
            guess = f32(yaw + tgt_e) if tgt_e > 0 else f32(yaw + tgt_e - two)
            yc = guess
            for k in range(-40, 41):
                cand = nxt(guess, k)
                if abs(e_of(cand) - tgt_e) < 2e-4:
                    yc = cand
                    break
            wf(lo + 0x48, C['c5'] if which == 'lim_c5' else C['c6'])
        elif which == 'vA':
            lim0 = f32(yaw - C['pi'])
            for k in range(-6, 7):
                cand = nxt(lim0, k)
                if f32(yaw - cand) == C['pi']:
                    wf(lo + 0x48, cand)
                    break
            yc = f32(yaw + r.uniform(-0.2, 0.2))
        elif which == 'vB':
            lim0 = f32(C['pi'] - yaw)
            for k in range(-6, 7):
                cand = nxt(lim0, k)
                if f32(cand + yaw) == C['pi']:
                    wf(lo + 0x48, cand)
                    break
            yc = f32(yaw + r.uniform(2.9, 3.1))
        wf(this + 0xa54, yc)
        wf(this + 0xa5c, pc)
        if os.environ.get('DBGW'):
            import sys
            print('DBG', which, 'yaw', yaw, 'yc', yc, 'e', e_of(yc), 'lim', rf(lo + 0x48), 'pc', pc, 'X', X, 'obj', hex(lo), 'bd1', hex(struct.unpack('<I', bytes(e.rbytes(this + 0xbd1, 4)))[0]), file=sys.stderr)
    return [this]


S(0x5d1530, 'aim_controller', 'thiscall', None, ret=None, gen=g5d1530)
