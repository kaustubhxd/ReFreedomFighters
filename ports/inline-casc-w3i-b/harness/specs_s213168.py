"""specs_s213168.py - batch 213168: three-entity text panel layout (4 KB frame, two text buffers, line counting, entity chain, merge through the formatter), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def cstr(emu, p, n=0x400):
    return bytes(emu.rbytes(p, n)).split(b'\0')[0]


def g565360(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)

    def ms(emu, k):
        emu.wbytes(emu.arg32(0), bytes([emu.arg32(1) & 0xff]) * emu.arg32(2))
    hook_rec(c, 0x634d10, 3, pop=0, stackmark=(0,), side=ms, ret=lambda emu, k: 0)

    words = [b'', b'Hello', b'A\nB', b'one\ntwo\nthree', b'x\n\n\ny', b'\n', b'Panel text', b'a', b'line1\nline2']
    st = {'n': 0}

    def s190(emu, k):
        n = st['n']
        st['n'] += 1
        s = b'' if (n == 0 and r.random() < 0.12) or (n == 1 and r.random() < 0.45) else r.choice(words[1:])
        emu.wbytes(emu.arg32(0), s + b'\0')
        emu.calllog.append(('s190', n, s))
    hook_rec(c, 0x565190, 4, pop=0x10, this=True, stackmark=(0,), side=s190)
    hook_rec(c, 0x563710, 2, pop=8, this=True)
    hook_rec(c, 0x5618b0, 2, pop=8, this=True)

    def s240(emu, k):
        emu.calllog.append(('s240', cstr(emu, emu.arg32(0))))
    hook_rec(c, 0x565240, 3, pop=0xc, this=True, stackmark=(0,), side=s240)
    hook_rec(c, 0x565760, 1, pop=4, this=True)

    def zstr(emu, k):
        s = r.choice(words) + b'\0'
        a = emu.alloc(len(s) + 1, 4)
        emu.wbytes(a, s)
        emu.calllog.append(('z0', emu.arg32(0), emu.arg32(1), s))
        return a
    Z = obj(c, 0x20, {0x0: pystub(c, 2, this=True, ret=zstr)}, nslots=0x10)

    def n198(emu, k):
        a, b = cstr(emu, emu.arg32(3)), cstr(emu, emu.arg32(4))
        s = b'F:' + a + b'|' + b
        emu.wbytes(emu.arg32(1), s + b'\0')
        emu.calllog.append(('n198', emu.arg32(2), s))
    N = obj(c, 0x20, {0x198: pystub(c, 5, pop=0, this=True, stackmark=(1, 3, 4), side=n198)}, nslots=0x100)
    T = obj(c, 0xb00, {}, nslots=0x10)
    w32u(T + 0xae4, Z)
    eng = obj(c, 0x100, {0x190: pystub(c, 0, this=True, ret=N)}, nslots=0x100)
    w32u(eng + 0x9b, T)
    w32u(eng + 0x30, rb() >> r.choice([0, 12, 20]))
    e.w32(0x70039c, eng)

    def s70(emu, k):
        emu.calllog.append(('s70', bytes(emu.rbytes(emu.arg32(0), 12))))
    ents = []
    for _ in range(3):
        en = obj(c, 0x40, {0xbc: pystub(c, 1, this=True), 0x31c: pystub(c, 2, this=True),
                           0x70: pystub(c, 1, this=True, stackmark=(0,), side=s70)}, nslots=0x100)
        blk = rnd(c, 0x80)
        for off in range(0x30, 0x50, 4):
            e.wbytes(blk + off, struct.pack('<f', r.choice([0.0, 1.0, -2.5, r.uniform(-9, 9)])))
        w32u(en + 8, blk)
        ents.append(en)
    ObB = obj(c, 0x20, {0x2ec: pystub(c, 1, this=True)}, nslots=0x100)
    this = obj(c, 0xd00, {0xfc: pystub(c, 1, this=True), 0x84: pystub(c, 0, this=True, ret=ObB)}, nslots=0x100)
    w32u(this + 0x44, rb())
    for k, en in enumerate(ents):
        w32u(this + 0xc6a + 4 * k, en)
    arg = rnd(c, 0x40)
    for off in (0x8, 0xc, 0x10):
        w32u(arg + off, 0 if r.random() < 0.4 else rb() | 1)
    e.wbytes(arg + 0x24, struct.pack('<f', r.choice([0.0, 1.0, 2.5, r.uniform(-4, 40)])))
    e.wbytes(arg + 0x28, bytes([r.getrandbits(8)]))
    return [this, arg]


S(0x565360, 'text_panel', 'thiscall', None, ret=None, gen=g565360, stack_arg_bytes=4)
