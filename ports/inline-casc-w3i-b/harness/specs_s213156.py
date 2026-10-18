"""specs_s213156.py - batch 213156: two-body overlap push-out (frame transliteration, real vector helpers, x87 normalise), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def g4ae5a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def wf(addr, v):
        e.wbytes(addr, struct.pack('<f', f32(v)))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)

    def fv(lim=3.0):
        return r.choice([0.0, 0.5, -0.5, 1.0, -1.0, r.uniform(-lim, lim), r.uniform(-lim, lim)])
    # engine object: slot 0x1c4 returns a float, +0x48 float step
    E = obj(c, 0x80, {0x1c4: pystub(c, 2, this=True, st0=lambda emu, k: r.choice([0.0, 0.5, -0.25, 1.0, 0.75]))}, nslots=0x80)
    wf(E + 0x48, r.choice([0.0, 0.016, 0.1, 1.0]))
    e.w32(0x70039c, E)
    prio = {}

    def lg578(emu, k):
        emu.calllog.append(('s578', bytes(emu.rbytes(emu.arg32(0), 12)), bytes(emu.rbytes(emu.arg32(1), 12))))

    def mk_shape():
        sh = obj(c, 0x740, {0x578: pystub(c, 2, this=True, stackmark=(1,), side=lg578)}, nslots=0x160)
        wf(sh + 0x624, r.choice([0.5, 1.0, 2.0, 3.0, 0.1, 0.0]))
        e.wbytes(sh + 0x726, bytes([r.choice([0, 0, 1])]))
        prio[sh] = r.choice([0.0, 1.0, 2.0])
        return sh

    def mk_body(pos):
        b = rnd(c, 0x50)
        for i, v in enumerate(pos):
            wf(b + 4 * i, v)
        for off in (0xc, 0x10, 0x14):
            wf(b + off, fv(2.0))
        sh = mk_shape()
        w32u(b + 0x30, sh)
        e.wbytes(b + 0x34, bytes([0]))
        return b
    pa = [fv(), r.choice([0.0, 0.0, 0.0, 1.0, fv(1.0)]), fv()]
    if r.random() < 0.25:
        pb = list(pa)
    else:
        pb = [pa[0] + fv(2.0), pa[1] + r.choice([0.0, 0.0, 0.5, 250.0, -250.0, 199.0, 201.0, 200.0, 200.0, -200.0, -200.0]), pa[2] + fv(2.0)]
    a = mk_body(pa)
    b = mk_body(pb)
    if r.random() < 0.3:      # same priority for both shapes
        shb = struct.unpack('<I', bytes(e.rbytes(b + 0x30, 4)))[0]
        sha = struct.unpack('<I', bytes(e.rbytes(a + 0x30, 4)))[0]
        prio[shb] = prio[sha]
    hook_rec(c, 0x4af0d0, 0, pop=0, this=True, st0=lambda emu, k: prio[emu.reg('ecx')])

    def lg84(emu, k):
        emu.calllog.append(('t84', bytes(emu.rbytes(emu.arg32(2), 12))))
    this = obj(c, 0x40, {0x84: pystub(c, 3, this=True, stackmark=(2,), side=lg84,
                                      ret=lambda emu, k: (rb() & ~0xff) | (1 if r.random() < 0.75 else 0))}, nslots=0x60)
    return [this, a, b]


S(0x4ae5a0, 'two_body_pushout', 'thiscall', None, ret='al', gen=g4ae5a0, stack_arg_bytes=12)
