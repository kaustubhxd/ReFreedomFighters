"""specs_s244039.py - hand-written specs for batch 244039."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g64bb90(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda v: struct.pack('<f', v)
    FV = [0.0, 1.0, -1.0, 0.5, -0.5, 2.0, -2.0, 3.0, r.uniform(-4, 4), 0.25]
    if r.random() < 0.6:   # grid mode: axis-aligned planes / directions, dot products tie at exactly 0 or flip sign on single components
        FV = [0.0, 0.0, 1.0, -1.0]
    this = rnd(c, 0x40)
    out = rnd(c, 0x80)
    pl = rnd(c, 0x40)
    for i in range(12):
        em.wbytes(pl + 4 * i, pk(r.choice(FV)))
    vec = rnd(c, 0x40)   # four points (vec3 each, stride 0xc): a2[0], a2[0xc], a2[0x18], a2[0x24]
    for i in range(12):
        em.wbytes(vec + 4 * i, pk(r.choice(FV)))

    def h7f0(emu, k):
        d, a, b = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        isheap = lambda v: 0x20000000 <= v < 0x30000000
        emu.calllog.append(('a7f0', emu.reg('ecx'), d, bytes(emu.rbytes(a, 12)), bytes(emu.rbytes(b, 12))))
        emu.wbytes(d, b''.join(pk(r.choice(FV)) for _ in range(3)))
    hook_rec(c, 0x64a7f0, 3, ret=r.getrandbits(32), pop=12, this=True, stackmark=(1, 2), side=h7f0)
    return [this, out, pl, vec]


S(0x64bb90, 'GUESS box-vs-planes clipper: classifies 4 corner points by 4 plane dot products and emits clipped edges', 'thiscall', 3, ret='al', gen=g64bb90, note='batch244039')


def g4253e0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    isheap = lambda v: 0x20000000 <= v < 0x30000000

    def cs(emu, p, n=0x200):
        if not p:
            return b''
        out = b''
        while len(out) < n:
            ch = bytes(emu.rbytes(p + len(out), 1))
            if ch == b'\0':
                break
            out += ch
        return out

    def word(n):
        return bytes(r.randrange(97, 123) for _ in range(n)) + b'\0'

    def lg(nm, *idx, strs=()):
        def s(emu, k):
            row = []
            for i in idx:
                v = emu.arg32(i)
                row.append(cs(emu, v) if i in strs else v)
            emu.calllog.append((nm,) + tuple(row))
        return s
    # --- IAT stubs (stdcall: pop = 4 * nargs)
    em.w32(0x6761bc, pystub(c, 4, ret=lambda emu, k: r.choice([6, 6, 6, 7, 2]), pop=16, side=lg('msgbox', 1, 2, 3, strs=(1, 2))))

    def s676008(emu, k):
        emu.calllog.append(('imp008', emu.r32(emu.arg32(1))))
        if r.random() < 0.8:
            emu.wbytes(emu.arg32(0), word(r.choice([0, 3, 9])))
        st['r008'] = r.choice([0, 1])
    st = {'r008': 0}
    em.w32(0x676008, pystub(c, 2, ret=lambda emu, k: st['r008'], pop=8, stackmark=(0, 1), side=s676008))

    def s6a4(emu, k):
        emu.calllog.append(('imp6a4', emu.arg32(1), cs(emu, emu.arg32(0))))
        emu.wbytes(emu.arg32(0), word(r.choice([0, 2, 7])))
    em.w32(0x6762a4, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, stackmark=(0,), side=s6a4))
    em.w32(0x6762c0, pystub(c, 1, ret=lambda emu, k: r.getrandbits(16), pop=4, side=lg('htons', 0)))
    em.w32(0x6762a0, pystub(c, 1, ret=lambda emu, k: r.choice([0, 0, 0x0100007f, r.getrandbits(32)]), pop=4, side=lg('inet', 0, strs=(0,))))
    em.w32(0x6762b8, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, side=lg('host', 0, strs=(0,))))
    em.w32(0x6762b4, pystub(c, 3, ret=lambda emu, k: r.choice([0xffffffff, 100, 200]), pop=12, side=lg('socket', 0, 1, 2)))

    # 0x6762bc is both connect (stdcall 3) here and MessageBox slot differs: the exe uses 0x6761bc for MessageBox, 0x6762bc for connect
    def s_conn(emu, k):
        emu.calllog.append(('connect', emu.arg32(0), bytes(emu.rbytes(emu.arg32(1), 16)), emu.arg32(2)))
    em.w32(0x6762bc, pystub(c, 3, ret=lambda emu, k: r.choice([0xffffffff, 0, 0, 0]), pop=12, stackmark=(1,), side=s_conn))

    def s_send(emu, k):
        n = emu.arg32(2)
        emu.calllog.append(('send', emu.arg32(0), bytes(emu.rbytes(emu.arg32(1), min(n, 0x1100))), n, emu.arg32(3)))
    em.w32(0x67629c, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=16, stackmark=(1,), side=s_send))
    em.w32(0x6762b0, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, side=lg('close', 0)))
    # --- exe helpers
    def s_b10(emu, k):
        emu.calllog.append(('b10', emu.r32(emu.reg('edx')), emu.arg32(0) if isheap(emu.arg32(0)) else 'stk', emu.r32(emu.arg32(1)), emu.r32(emu.arg32(0)) if False else 0))
        emu.wbytes(emu.reg('ecx'), word(r.choice([0, 4, 12, 30])))
    hook_rec(c, 0x425b10, 2, ret=lambda emu, k: r.choice([0, 1, 1]), pop=8, this='mark', stackmark=(0, 1), side=s_b10)

    def s_sp(emu, k):
        fmtp = emu.arg32(1)
        emu.calllog.append(('sprintf', cs(emu, fmtp), cs(emu, emu.arg32(2))))
        t = word(r.choice([0, 5, 20]))
        emu.wbytes(emu.arg32(0), t)
        st['n'] = len(t) - 1
    hook_rec(c, 0x42ac56, 3, ret=lambda emu, k: st["n"], pop=0, stackmark=(0, 2), side=s_sp)
    # --- the optional global chain when the host argument is null
    leaf = em.alloc(8, 4)
    em.w32(leaf, r.getrandbits(32))
    p2 = em.alloc(8, 4)
    em.w32(p2, leaf)
    p1 = em.alloc(8, 4)
    em.w32(p1, p2)
    gl = rnd(c, 0x20)
    em.w32(gl + 0xc, p1)
    em.w32(0x6fd930, gl if r.random() < 0.8 else 0)
    # --- arguments: strings
    def sp(n, nul=0.0):
        if r.random() < nul:
            return 0
        a = em.alloc(0x40, 4)
        em.wbytes(a, word(n))
        return a
    host = sp(6, 0.3)
    a1 = sp(r.choice([0, 4, 10]), 0.3)
    a2 = r.choice([0, sp(5), sp(5)])
    a3 = sp(5)
    a4 = sp(7)
    thisobj = obj(c, 0x20, {0x8: pystub(c, 0, ret=r.getrandbits(32), pop=0, this=True, side=lambda emu, k: emu.calllog.append(('t8',)))})
    G = rnd(c, 0x2000)
    em.w32(G + 0x190f, thisobj if r.random() < 0.6 else 0)
    em.w32(0x70039c, G)
    em.w32(0x700390, 0)
    return [host, a1, a2, a3, a4]


S(0x4253e0, 'GUESS SMTP sender: connects to a host on port 25 and sends a bug-report mail', 'stdcall', 5, ret='al', gen=g4253e0, note='batch244039')
