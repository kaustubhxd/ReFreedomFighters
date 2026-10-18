"""specs_s244038.py - hand-written specs for batch 244038."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g534570(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda v: struct.pack('<f', v)
    FV = [0.0, 1.0, -1.0, 0.5, 2.0, 100.0, r.uniform(-9, 9), float('nan')]

    def lg(nm, n):
        return lambda emu, k: emu.calllog.append((nm,) + tuple(emu.arg32(i) for i in range(n)))
    slots = {0x3c: 1, 0x44: 1, 0x68: 1, 0x4c: 1, 0x54: 1, 0x6c: 1}
    ring = {0x10: 2}
    dev_slots = {s: pystub(c, n, ret=lambda emu, k: r.getrandbits(32), pop=4 * n, this=True, side=lg('d%x' % s, n)) for s, n in slots.items()}

    def s10(emu, k):
        n = emu.arg32(1)
        p = emu.arg32(0)
        emu.calllog.append(('d10', n, p if (0x20000000 <= p < 0x30000000 and n > 0x1000) else bytes(emu.rbytes(p, min(n, 0x1004))), 'h' if 0x20000000 <= p < 0x30000000 else 's'))
    dev_slots[0x10] = pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, stackmark=(0,), side=s10)
    ebx = obj(c, 0x80, dev_slots)
    # engine: +0x1c dword, +0x1a9f -> Q (slots 0x40, 0x1dc, 0x1e0 with st0 result)
    Q = obj(c, 0x200, {0x40: pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=lg('q40', 1)),
                       0x1dc: pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=lg('q1dc', 1)),
                       0x1e0: pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, st0=lambda emu, k: r.choice(FV), side=lg('q1e0', 1))})
    G = rnd(c, 0x2000)
    em.w32(G + 0x1c, r.getrandbits(32))
    em.w32(G + 0x1a9f, Q)
    em.w32(0x70039c, G)
    # this: [this] = U, this+8 = records, this+0x100c
    U = rnd(c, 0x40)
    em.w32(U + 0x10, r.choice([0, 3, 7, 0xff, 1023, 0xffffffff & 1023]))
    for o in (8, 0xc, 0x14):
        em.w32(U + o, r.getrandbits(32))
    em.w32(U + 4, rnd(c, 0x1100))   # vertex/index data pointer handed to slot 0x10
    R = em.alloc(0x3f400 + 0x100, 4)
    nact = r.choice([0, 1, 1, 2, 3])
    idxs = r.sample([0, 1, 2, 5, 100, 1000, 1022, 1023, 1024], nact)   # 1024 = one past the loop bound (jl vs jle)
    for i in idxs:
        rec = R + 0xfd * i
        em.wbytes(rec, bytes(r.getrandbits(8) for _ in range(0xfd)))
        em.w32(rec + 0x10, r.choice([1, 0xff, 0x3ff, 0x1, 0x80, 0x100, 5]))
        for fo in (0x44, 0x48, 0x4c, 0x50, 0x54, 0x5c, 0x78, 0x84, 0x88):
            em.wbytes(rec + fo, pk(r.choice(FV)))
    this = rnd(c, 0x1100)
    em.w32(this, U)
    em.w32(this + 8, R)
    em.w32(this + 0x100c, r.getrandbits(32))

    def ms(emu, k):
        emu.calllog.append(('memset', emu.arg32(1), emu.arg32(2)))
        emu.wbytes(emu.arg32(0), bytes(emu.arg32(2)))
    hook_rec(c, 0x634d10, 3, ret=r.getrandbits(32), pop=0, stackmark=(0,), side=ms)
    hook_rec(c, 0x5348e0, 2, ret=r.getrandbits(32), pop=8, this=True, side=lambda emu, k: emu.calllog.append(('e0', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))
    return [this, ebx]


S(0x534570, 'GUESS draw-state replay: walks 1024 render records and replays them into a device', 'thiscall', 1, ret='eax', gen=g534570, note='batch244038')


def g4ef880(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu

    def lg(nm, n):
        return lambda emu, k: emu.calllog.append((nm,) + tuple(emu.arg32(i) for i in range(n)))
    # glyph structs (bytes read at +4.. +0x11), one per distinct character code
    glyphs = {}

    def glyph(ch):
        if ch not in glyphs:
            g = rnd(c, 0x40)
            em.wbytes(g + 8, bytes(r.choice([0, 1, 2, 5, 0x7f, 0x80, 0xf0, 0xff, r.getrandbits(8)]) for _ in range(0x0a)))
            glyphs[ch] = g
        return glyphs[ch]

    def s280(emu, k):
        emu.calllog.append(('f280', emu.arg32(0)))
        st['g'] = glyph(emu.arg32(0))
    st = {'g': 0}
    F = obj(c, 0x400, {0x274: pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=lg('f274', 0)),
                       0x280: pystub(c, 1, ret=lambda emu, k: st['g'], pop=4, this=True, side=s280),
                       0x28c: pystub(c, 2, ret=lambda emu, k: r.choice([0, 1, 2, 5, -3 & 0xffffffff]), pop=8, this=True, side=lg('f28c', 2))})
    # engine: [0x70039c] + 0x1aa3 -> X -> +0x18 -> Y (slot 0x2c: quad buffer, 0x12c: submit)
    nch = r.choice([0, 1, 2, 3, 5, 8, 12, 14])
    alphabet = [ord(ch) for ch in 'abcdeXYZ019'] + [0x20, 0x20, 0x0a, 0x0d, 0x09, 0x0b, 0x0c, 0x10, 0x1f, 0x21, 0x7e, 0xe9]
    text = bytes(r.choice(alphabet) for _ in range(nch)) + b'\0'
    buf = rnd(c, 0x28 * 20 + 0x40)   # stale bytes in the quad buffer: a store of 0 must be visible
    failalloc = r.random() < 0.1
    Y = obj(c, 0x40, {0x2c: pystub(c, 1, ret=lambda emu, k: 0 if failalloc else buf, pop=4, this=True, side=lg('y2c', 1)),
                      0x12c: pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=lambda emu, k: emu.calllog.append(('y12c', emu.arg32(0), emu.arg32(1), bytes(emu.rbytes(emu.arg32(0) - 0x24, 0x28)))))})
    X = rnd(c, 0x40)
    em.w32(X + 0x18, Y)
    G = rnd(c, 0x2000)
    em.w32(G + 0x1aa3, X)
    em.w32(0x70039c, G)
    LO = obj(c, 0x40, {0x2c: pystub(c, 2, ret=r.getrandbits(32), pop=0, side=lambda emu, k: emu.calllog.append(('log2c', emu.arg32(1))))})
    MG = obj(c, 0x40, {0x20: pystub(c, 2, ret=LO, pop=8, this=True, side=lg('mg20', 2))})
    em.w32(0x700390, MG)
    me = obj(c, 0x400, {0x230: pystub(c, 0, ret=r.getrandbits(32), pop=0, this=True, side=lg('t230', 0)),
                        0x228: pystub(c, 0, ret=r.getrandbits(32), pop=0, this=True, side=lg('t228', 0))})
    sp = em.alloc(0x40, 4)
    em.wbytes(sp, text)
    em.w32(me + 0x97, sp)
    em.w32(me + 0x9f, 0 if r.random() < 0.08 else F)
    em.w32(me + 0x93, r.choice([0, 5, 100, -7 & 0xffffffff]))
    em.w32(me + 0xa3, r.choice([1, 2, 3, 4, 8, 16, 32]))

    def h4cc500(emu, k):
        sc = emu.reg('ecx')
        p = emu.r32(sc)
        ch = emu.rbytes(p, 1)[0]
        if ch:
            emu.w32(sc, p + 1)
        emu.calllog.append(('next', ch))
        st['ch'] = ch
    hook_rec(c, 0x4cc500, 0, ret=lambda emu, k: st['ch'], pop=0, this='mark', side=h4cc500)
    hook_rec(c, 0x4ee640, 3, ret=r.getrandbits(32), pop=12, this=True, side=lambda emu, k: emu.calllog.append(('e640', emu.arg32(0), emu.arg32(1), emu.arg32(2))))

    def h9350(emu, k):
        n = emu.arg32(2)
        emu.calllog.append(('f9350', emu.reg('edx'), bytes(emu.rbytes(emu.reg('ecx'), 8 * min(n, 20))), tuple(emu.arg32(i) for i in range(5))))
    hook_rec(c, 0x4f9350, 5, ret=r.getrandbits(32), pop=20, this='mark', side=h9350)
    return [me]


S(0x4ef880, 'GUESS text layout: counts glyphs, allocates quads, lays out characters with tabs and kerning', 'thiscall', 0, ret='al', gen=g4ef880, note='batch244038')
