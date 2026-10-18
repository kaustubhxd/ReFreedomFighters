"""specs_s213121.py - batch 213121: debug line lists over two object arrays with handle bookkeeping and compaction, Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')


def g58a680(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]

    def fv():
        return f32(r.choice([0.0, -0.0, 1.0, -1.0, 2.0, 0.5, r.uniform(-5, 5)]))

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))
    this = rnd(c, 0x200)
    n1 = r.choice([0, 1, 2, 3, 5, 8])
    n2 = r.choice([0, 1, 2, 3, 5, 8])
    e.w32(this, n1)
    e.w32(this + 0x38, n2)

    def s84(emu, k):
        emu.wbytes(emu.arg32(0), struct.pack('<fff', fv(), fv(), fv()))
    A1 = [obj(c, 0x20, {0x84: pystub(c, 1, this=True, nullflag=(0,), side=s84)}, nslots=0x40) for _ in range(n1)]
    for i, o in enumerate(A1):
        e.w32(this + 4 + 4 * i, o)

    def s80(emu, k):
        emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(36)))
        emu.wbytes(emu.arg32(1), struct.pack('<fff', fv(), fv(), fv()))
    A2objs = [obj(c, 0x20, {0x80: pystub(c, 2, this=True, nullflag=(0, 1), side=s80)}, nslots=0x60) for _ in range(n2)]
    for j, o in enumerate(A2objs):
        entry = rnd(c, 0x10)
        e.w32(entry, o)
        e.w32(this + 0x3c + 4 * j, entry)
    for i in range(n1):
        e.w32(this + 0x80 + 4 * i, r.choice([0, 0, r.getrandbits(32) | 1]))
    for j in range(n2):
        e.w32(this + 0xb4 + 4 * j, r.choice([0, 0, r.getrandbits(32) | 1]))
    # draw object K at [[0x70039c]+0x9b]+0xadc
    def s218(emu, k):
        lg(emu, 'p218', emu.arg32(0), 12)
        lg(emu, 'c218', emu.arg32(1), 12)

    def s21c(emu, k):
        lg(emu, 'p21c', emu.arg32(1), 12)
        lg(emu, 'c21c', emu.arg32(2), 12)
    K = obj(c, 0x20, {0x218: pystub(c, 3, this=True, nullflag=(0, 1), side=s218, ret=lambda emu, k: r.getrandbits(32) | 1),
                      0x21c: pystub(c, 4, this=True, nullflag=(1, 2), side=s21c),
                      0x220: pystub(c, 1, this=True)}, nslots=0x100)
    tab = obj(c, 0xb00, {}, nslots=4)
    e.w32(tab + 0xadc, K)
    eng = obj(c, 0x100, {}, nslots=4)
    e.w32(eng + 0x9b, tab)
    e.w32(0x70039c, eng)
    hook_rec(c, 0x59d370, 0, pop=0, this=True, ret=lambda emu, k: (r.getrandbits(32) & ~0xff) | (1 if r.random() < 0.35 else 0))

    def s9b50(emu, k):
        emu.wbytes(emu.arg32(0), struct.pack('<fff', fv(), fv(), fv()))
    hook_rec(c, 0x589b50, 1, pop=4, this=True, nullflag=(0,), side=s9b50)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    dt = f32(r.choice([0.0, 0.0, 0.016, 0.5, -0.5, NAN, 1.0, -0.0]))
    return [this, F(dt)]


S(0x58a680, 'debug_lines_update', 'thiscall', None, ret=None, gen=g58a680)
