"""specs_s990.py - area 56 claim A56 (0x465a80, CanPlayAnimSegment). GUESS helpers and vtable slots.

Per case, gen draws a table T of 2048 floats in [-6, 6]. Every stub consumes the next value(s) of T, in call order, so the exe run and
the port run see the same values (both run gen first). Stubs write three floats (from T) into the pointer arguments named in their
comment, and return a bool / int / pointer derived from T. The object graph: global 0x70039c -> G (+0x1aa3 -> A, A +0x1c -> B2, B2 vt:
0x44 bool, 0x48 returns E, 0x4c void); this (+0x5c -> obj2, obj2 vt: 0x2c returns X, 0xc writes La4 and L108). P holds floats at +0x70..
+0x78. vec is three floats. f6 and f7 are unread. ret='al'."""
import struct
from pilot import S
from pe_emu import F as FP


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fl(c, lo=-6.0, hi=6.0):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _gen(c):
    e = c.emu
    rng = c.rng
    T = [rng.uniform(-6.0, 6.0) for _ in range(2048)]
    k = [0]

    def nf():
        v = T[k[0] % len(T)]
        k[0] += 1
        return v

    def write3(addr):
        e.wbytes(addr, struct.pack('<fff', nf(), nf(), nf()))

    def write3dep(e2, addr):
        cur = struct.unpack('<fff', e2.rbytes(addr, 12))
        vals = [0.5 * cur[i] + nf() for i in range(3)]
        e2.wbytes(addr, struct.pack('<fff', *vals))

    def nb_dep(e2, addr, center):
        # Centred on the expected sum of the three floats (the 0x685270 and 0x686094 constants make the sums about 25 and 140).
        cur = struct.unpack('<fff', e2.rbytes(addr, 12))
        v = 0.2 * nf() + (cur[0] + cur[1] + cur[2]) - center
        return 1 if v > 0.0 else 0

    def nb(threshold):
        return 1 if nf() > threshold else 0

    # Object graph.
    E = e.alloc(0x200, 4)
    e.wbytes(E, bytes(0x200))
    X = e.alloc(0x200, 4)
    e.wbytes(X, bytes(0x200))

    def h44(e2, r):
        e2.calllog.append(('V44',))
        e2.ret(eax=nb(4.0), argbytes=0)

    def h48(e2, r):
        e2.calllog.append(('V48',))
        e2.ret(eax=E, argbytes=0)

    def h4c(e2, r):
        e2.calllog.append(('V4c', e2.arg32(0)))
        e2.ret(argbytes=4)

    vtB2 = e.fake_vtable('vtA56b2', 0x200, {0x44: h44, 0x48: h48, 0x4c: h4c})
    B2 = _rnd(c, 0x100)
    e.w32(B2, vtB2)
    A = _rnd(c, 0x100)
    e.w32(A + 0x1c, B2)
    G = _rnd(c, 0x2000)
    e.w32(G + 0x1aa3, A)
    e.w32(0x70039c, G)

    def h2c(e2, r):
        e2.calllog.append(('V2c',))
        e2.ret(eax=X, argbytes=8)

    def hc(e2, r):
        # args: X, 0, La4 (arg2), L108 (arg3), t (arg4)
        pLa4 = e2.arg32(2)
        pL108 = e2.arg32(3)
        e2.calllog.append(('Vc',))
        write3(pLa4)
        write3(pL108)
        e2.ret(argbytes=20)

    vtO = e.fake_vtable('vtA56o', 0x200, {0x2c: h2c, 0xc: hc})
    obj2 = _rnd(c, 0x100)
    e.w32(obj2, vtO)
    this = _rnd(c, 0x800)
    e.w32(this + 0x5c, obj2)

    P = _rnd(c, 0x100)
    for off in (0x70, 0x74, 0x78):
        e.w32(P + off, _fl(c))
    vec = _rnd(c, 0x20)
    for i in range(3):
        e.w32(vec + 4 * i, _fl(c))

    # Helper stubs (GUESS). Output pointers are the arguments named in the comments.
    def stub_fastcall2(addr, out_first=True):
        def h(e2, r):
            e2.calllog.append(('H%x' % addr,))
            write3(e2.reg('ecx'))
            e2.ret(argbytes=0)
        e.hook(addr, h)

    def stub_fastcall_s(addr, outs=('ecx',), log_arg=True):
        def h(e2, r):
            if log_arg:
                e2.calllog.append(('H%x' % addr, e2.arg32(0)))
            else:
                e2.calllog.append(('H%x' % addr,))
            for o in outs:
                write3(e2.reg(o))
            e2.ret(argbytes=4)
        e.hook(addr, h)

    def h4419f0(e2, r):                               # FASTCALL(ecx, edx): reads and writes ecx
        e2.calllog.append(('H4419f0',))
        write3dep(e2, e2.reg('ecx'))
        e2.ret(argbytes=0)
    e.hook(0x4419f0, h4419f0)
    stub_fastcall2(0x441940)                          # FASTCALL(ecx, edx): writes ecx

    def h4e0d80(e2, r):                               # THISCALL(ecx, s): reads and writes ecx
        e2.calllog.append(('H4e0d80', e2.arg32(0)))
        write3dep(e2, e2.reg('ecx'))
        e2.ret(argbytes=4)
    e.hook(0x4e0d80, h4e0d80)

    stub_fastcall_s(0x4e0d40, outs=('ecx',))          # FASTCALL(ecx, edx, s): writes ecx
    stub_fastcall_s(0x4de040, outs=('ecx',))          # FASTCALL(ecx, edx, s): writes ecx
    stub_fastcall_s(0x43e8e0, outs=('ecx',), log_arg=False)          # FASTCALL(ecx, edx, s): writes ecx
    stub_fastcall_s(0x43e920, outs=('ecx',), log_arg=False)           # FASTCALL(ecx, edx, s): writes ecx (edx is read-only here)

    def h4e8c00(e2, r):                               # THISCALL(this, p1, p2, p3, p4): writes p1, returns al
        e2.calllog.append(('H4e8c00',))
        write3(e2.arg32(0))
        e2.ret(eax=nb_dep(e2, e2.arg32(1), 25.0), argbytes=16)
    e.hook(0x4e8c00, h4e8c00)

    def h4e9200(e2, r):                               # THISCALL(this, p1, p2, p3): writes p1, returns al
        e2.calllog.append(('H4e9200',))
        write3(e2.arg32(0))
        e2.ret(eax=nb_dep(e2, e2.arg32(1), 140.0), argbytes=12)
    e.hook(0x4e9200, h4e9200)

    def h4eb020(e2, r):                               # THISCALL(this, p1..p5): writes p1, p2, p3
        e2.calllog.append(('H4eb020',))
        for i in range(3):
            write3(e2.arg32(i))
        e2.ret(argbytes=20)
    e.hook(0x4eb020, h4eb020)

    def h4ea300(e2, r):                               # THISCALL(this, n): void
        e2.calllog.append(('H4ea300', e2.arg32(0)))
        e2.ret(argbytes=4)
    e.hook(0x4ea300, h4ea300)

    def h634d7c(e2, r):                               # VECTORCALL(double): identity (xmm0 unchanged)
        e2.calllog.append(('H634d7c',))
        e2.ret(argbytes=0)
    e.hook(0x634d7c, h634d7c)

    def h633910(e2, r):                               # VECTORCALL(float): returns an int 0..2
        v = int(abs(nf())) % 3
        e2.calllog.append(('H633910', v))
        e2.ret(eax=v, argbytes=0)
    e.hook(0x633910, h633910)

    # Arguments.
    f1 = _fl(c)
    f2 = _fl(c)
    f6 = _fl(c)
    f7 = _fl(c)
    return [this, P, FP(f1), FP(f2), rng.getrandbits(32), vec, FP(f6), FP(f7)]


S(0x465a80, 'CanPlayAnimSegment (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-56 A56; area 09 hit-reaction leaf; helpers and vt slots are GUESS stubs')
