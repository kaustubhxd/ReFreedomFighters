"""specs_s213141.py - batch 213141: segment query against a node tree (box test, group recursion, leaf owner / engine slots), Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g442420(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def wf(addr, v):
        e.wbytes(addr, struct.pack('<f', f32(v)))

    def fv():
        return f32(r.choice([0.0, 1.0, -1.0, 0.5, 2.0, r.uniform(-5, 5), r.uniform(-5, 5)]))
    R0 = f32(r.choice([0.0, 1.0, 5.0, 10.0, r.uniform(0, 10)]))
    R = rnd(c, 0x80)
    wf(R, R0)
    def lgv(emu, k):
        emu.calllog.append(('o64a', bytes(emu.rbytes(emu.arg32(2), 12)), bytes(emu.rbytes(emu.arg32(3), 12))))
    O = obj(c, 0x40, {0x64: pystub(c, 6, this=True, stackmark=(2, 3), side=lgv, ret=lambda emu, k: (rb() & ~0xff) | (1 if r.random() < 0.6 else 0))}, nslots=0x40)
    mid = rnd(c, 0x40)
    w32u(mid + 0x1c, O)
    eng = rnd(c, 0x2000)
    w32u(eng + 0x1aa3, mid)
    e.w32(0x70039c, eng)
    flagsets = [0x100000, 0x200006, 0x200002, 0x200000, 0x100006, 0x6, 0x2, 0]

    def mk_x(tree_ok):
        def lgx(emu, k):
            emu.calllog.append(('x27c', bytes(emu.rbytes(emu.arg32(1), 12)), bytes(emu.rbytes(emu.arg32(2), 12))))
        X = obj(c, 0x80, {0x27c: pystub(c, 3, this=True, stackmark=(1, 2), side=lgx, ret=lambda emu, k: r.choice([0, 0, rb() | 1]))}, nslots=0x180)
        # chain of property records Y -> Y -> ...
        prev = 0
        n = r.choice([1, 1, 2, 3])
        for i in range(n):
            Y = rnd(c, 0x40)
            fl = r.choice(flagsets) if i == 0 else r.choice([0x200006, 0x200002, 0x5, 0])
            if i == 0 and not tree_ok:
                fl &= ~0x100000
            w32u(Y + 0x23, fl)
            w32u(Y + 0xc, prev)
            prev = Y
        w32u(X + 0xc, prev)
        w32u(X + 0x50, 0)
        return X

    def mk_node(depth):
        N = rnd(c, 0x80)
        w32u(N + 0x3c, r.choice([0x1, 0x2, 0x401, 0x800, 0xfff, 0, 0x3, 0x100, 0x801, 0x1c01]))
        for off in (0x30, 0x34, 0x38):
            wf(N + off, fv())
        for off in (0x40, 0x44, 0x48):
            wf(N + off, r.choice([0.0, 0.5, 1.0, 2.0, r.uniform(0, 3)]))
        w32u(N + 0x6c, rb())
        w32u(N + 0x60, 0)
        if r.random() < 0.25:
            w32u(N + 0x54, 0)
        else:
            X = mk_x(depth > 0)
            w32u(N + 0x54, X)
            if depth > 0 and r.random() < 0.8:
                # children list
                head = 0
                for _ in range(r.choice([1, 2, 3])):
                    ch = mk_node(depth - 1)
                    w32u(ch + 0x60, head)
                    head = ch
                w32u(X + 0x50, head)
        return N
    N0 = mk_node(r.choice([1, 2]))
    A = e.alloc(16, 4)
    e.wbytes(A, struct.pack('<3f', fv(), fv(), fv()))
    B = e.alloc(16, 4)
    e.wbytes(B, struct.pack('<3f', fv(), fv(), fv()))

    def vecmod(emu, k):
        p = emu.arg32(0)
        old = struct.unpack('<3f', bytes(emu.rbytes(p, 12)))
        emu.wbytes(p, struct.pack('<3f', *[f32(o + r.choice([0.0, 0.0, 1.0, -1.0, 0.25])) for o in old]))
    hook_rec(c, 0x4db1f0, 1, pop=4, this=True, stackmark=(0,), side=vecmod)
    hook_rec(c, 0x4db270, 1, pop=4, this=True, stackmark=(0,), side=vecmod)

    def s2800(emu, k):
        emu.wbytes(emu.reg('ecx'), struct.pack('<f', f32(r.choice([R0 - 1.0, R0, R0 + 1.0, R0 * 0.5, 0.0]))))
    hook_rec(c, 0x4e2800, 12, pop=0x30, this='mark', side=s2800, ret=lambda emu, k: (rb() & ~0xff) | (1 if r.random() < 0.8 else 0))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    m1set = [0xffffffff, 1, 2, 3, 0x100, 0x401, 0x801, 1, 2]
    m2set = [0xffffffff, 0x200000, 0x6, 0x200006, 0x2, 0x4, 0x200004, 0x6, 0x200006]
    m3set = [0xffffffff, 1, 2, 0x200000, 0x100000, 0x6, 0x200006, 0x401, 0x8]
    return [R, N0, A, B, r.choice(m1set), r.choice(m2set), r.choice(m3set)]


S(0x442420, 'segment_query', 'fastcall', None, ret='al', gen=g442420, stack_arg_bytes=20)
