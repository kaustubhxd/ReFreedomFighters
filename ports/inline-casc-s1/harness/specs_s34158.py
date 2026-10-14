"""specs_s34158.py - tier H. 0x4658d0: record {fn, adj, junk, junk} at the unaligned +0x3d, fn a recorder stub (ecx logged) that re-arms the record up to twice. 0x476300: word compare, engine int [0x70039c]+0x40, float +0x48, slot 0x64. 0x51ebe0: hooked 0x5003d0 (cells), the embedded object at [this+0x18]+0x34e with a 3-arg slot 0. 0x562b50: hooked 0x59cb60 / 0x4f21f0, slot 0x84 (0 args) returns an object; state bytes +0x84/+0x85 and +0xdc around 2. 0x438050: slots 0x38 (2 args, low byte) and 0xa4 (1 arg, signed byte results). 0x484ed0: flag byte +0x417, slots 0x5fc and 0x244 (5 args)."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _fbits(r):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g4658d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x60)
    left = {'n': r.choice([0, 1, 2])}

    def rearm(em, k):
        if left['n'] > 0 and r.random() < 0.7:
            left['n'] -= 1
            em.wbytes(me + 0x3d, stubs[r.randrange(len(stubs))].to_bytes(4, 'little') + r.getrandbits(32).to_bytes(4, 'little') + r.getrandbits(64).to_bytes(8, 'little'))
    stubs = [pystub(c, 0, this=True, pop=0, side=rearm) for _ in range(3)]
    fn = 0 if r.random() < 0.15 else stubs[0]
    e.wbytes(me + 0x3d, fn.to_bytes(4, 'little') + r.getrandbits(32).to_bytes(4, 'little') + r.getrandbits(64).to_bytes(8, 'little'))
    return [me, r.getrandbits(32)]


def _g476300(c):
    clear_hooks(c)
    r = c.rng
    so = rnd(c, 0x60)
    c.emu.w32(so + 0x40, r.choice([0, 1000, -5, r.getrandbits(32)]) & 0xffffffff)
    c.emu.w32(0x70039c, so)
    me = obj(c, 0x60, {0x64: pystub(c, 1, this=True)}, nslots=0x68 // 4)
    w = r.getrandbits(16)
    c.emu.wbytes(me + 0x4c, w.to_bytes(2, 'little'))
    c.emu.w32(me + 0x48, _fbits(r))
    c.emu.wbytes(me + 0x52, r.getrandbits(32).to_bytes(4, 'little'))
    k = r.random()
    arg = w if k < 0.5 else (w ^ (1 << r.randrange(16)))
    if r.random() < 0.3:
        arg |= r.getrandbits(16) << 16
    return [me, arg & 0xffffffff, r.getrandbits(32)]


def _g51ebe0(c):
    clear_hooks(c)
    r = c.rng
    cell0, cell1 = rnd(c, 0x10), rnd(c, 0x10)
    c.emu.w32(cell0, _fbits(r))
    c.emu.w32(cell1, r.getrandbits(32))
    seq = [cell0, cell1]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: seq[min(k, 1)])
    blk = rnd(c, 0x400)
    vt = c.emu.alloc(0x20, 4)
    c.emu.w32(vt, pystub(c, 3, this=True))
    c.emu.w32(blk + 0x34e, vt)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x18, blk)
    p = rnd(c, 0x10)
    c.emu.w32(p + 4, rnd(c, 0x10))
    return [me, p]


def _g562b50(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x59cb60, 1, this=True)
    hook_rec(c, 0x4f21f0, 1, this=True, ret=r.getrandbits(32))
    so = rnd(c, 0x60)
    c.emu.w32(so + 0x30, r.choice([0, 1, -1, 1000, r.getrandbits(32)]) & 0xffffffff)
    c.emu.w32(0x70039c, so)
    o = obj(c, 0x20, {}, nslots=1)
    me = obj(c, 0xe8, {0x84: pystub(c, 0, this=True, pop=0, ret=o)}, nslots=0x88 // 4)
    c.emu.w32(me + 0x94, rnd(c, 0x20))
    c.emu.wbytes(me + 0x84, bytes([r.choice([0, 1])]))
    c.emu.wbytes(me + 0x85, bytes([0 if r.random() < 0.6 else r.choice([1, 2])]))
    c.emu.w32(me + 0xdc, r.choice([2, 2, 2, 0, 1, 3, 4]))
    return [me, r.getrandbits(32)]


def _g438050(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x20, {0x38: pystub(c, 2, this=True, ret=lambda em, k: r.choice([0, 0, 1, 0x100, 0x101])),
                       0xa4: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x7f, 0x80, 0xff, 0x1ff, r.getrandbits(32)]))}, nslots=0xa8 // 4)
    return [me, r.getrandbits(32), r.getrandbits(32)]


def _g484ed0(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x430, {0x5fc: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0, 5, r.getrandbits(32)])),
                        0x244: pystub(c, 5, this=True, ret=r.getrandbits(32))}, nslots=0x248 // 4)
    c.emu.wbytes(me + 0x417, bytes([r.choice([0, 1, 2, 3, 4, 0x80, 0xff])]))
    return [me, _fbits(r)]


S(0x4658d0, 'GUESS run pending callback', 'thiscall', None, ret=None, gen=_g4658d0, note='batch34158')
S(0x476300, 'GUESS stamp time and reset', 'thiscall', None, ret='eax', gen=_g476300, note='batch34158')
S(0x51ebe0, 'GUESS forward two cells', 'thiscall', None, ret=None, gen=_g51ebe0, note='batch34158')
S(0x562b50, 'GUESS arm a state', 'thiscall', None, ret=None, gen=_g562b50, note='batch34158')
S(0x438050, 'GUESS signed byte as float', 'thiscall', None, ret='st0', gen=_g438050, note='batch34158')
S(0x484ed0, 'GUESS forward float to slot', 'thiscall', None, ret=None, gen=_g484ed0, note='batch34158')
