"""specs_s34165.py - tier H. 0x4616c0: hooked 0x43df70, 0x4db7c0 (writes three random floats through its stack pointer), 0x4dce50, 0x4dd060 (vector logged), /GS check keeping eax. 0x5157d0: object [this+0x5c] with float getters slots 0x10/0x14/0xc (st0), hooked 0x523470 (writes a vector through its stack pointer argument, float bits logged) and 0x4de040 (ecx, edx and the vector logged). 0x561f70: state +0xdc in {3, 5, others}, hooked 0x4f9680 / 0x563750, child objects with slot 0xbc, slot 0xd4. 0x478f90: array of up to 8 16-byte entries with floats, index and size, argument around the entries."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def _fval(r):
    k = r.random()
    if k < 0.2:
        v = r.choice([x for x in EDGE_F if x == x])
    else:
        v = r.uniform(-100, 100)
    return _f32(v) if abs(v) < 3e38 or v != v else v


def _fbits(r):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    else:
        v = r.uniform(-100, 100)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g4616c0(c):
    clear_hooks(c)
    r = c.rng

    def vec(em, k):
        p = em.arg32(0)
        em.wbytes(p, b''.join(_fbits(r).to_bytes(4, 'little') for _ in range(3)))
    hook_rec(c, 0x43df70, 0, this=True, pop=0)
    hook_rec(c, 0x4db7c0, 1, this=True, stackmark=(0,), side=vec)
    hook_rec(c, 0x4dce50, 1, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x4dd060, 1, this=True, deref={0: 3}, ret=r.getrandbits(32))
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, rnd(c, 0x20))
    return [me]


def _g5157d0(c):
    clear_hooks(c)
    r = c.rng

    def fill(em, k):
        p = em.arg32(1)
        em.wbytes(p, b''.join(_fbits(r).to_bytes(4, 'little') for _ in range(3)))

    def log4de(em, k):
        em.calllog.append(('edx', em.reg('edx'), bytes(em.rbytes(em.reg('edx'), 12))))
    hook_rec(c, 0x523470, 3, this=True, pop=12, stackmark=(1,), side=fill)
    hook_rec(c, 0x4de040, 1, this=True, pop=4, side=log4de)
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))
    o = obj(c, 0x20, {0x10: pystub(c, 0, this=True, pop=0, st0=lambda em, k: _fval(r)),
                      0x14: pystub(c, 0, this=True, pop=0, st0=lambda em, k: _fval(r)),
                      0xc: pystub(c, 0, this=True, pop=0, st0=lambda em, k: _fval(r))}, nslots=0x18 // 4)
    me = rnd(c, 0x2a0)
    c.emu.w32(me + 0x5c, o)
    return [me]


def _g561f70(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4f9680, 1, this=True)
    hook_rec(c, 0x563750, 2, this=True, pop=8)
    so = rnd(c, 0x60)
    c.emu.w32(so + 0x30, r.choice([0, 1, -1, 1000, r.getrandbits(32)]) & 0xffffffff)
    c.emu.w32(0x70039c, so)
    ch1 = obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}, nslots=0xc0 // 4)
    ch2 = obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}, nslots=0xc0 // 4)
    me = obj(c, 0xf0, {0xd4: pystub(c, 1, this=True)}, nslots=0xd8 // 4)
    c.emu.w32(me + 0x4c, 0 if r.random() < 0.3 else ch1)
    c.emu.w32(me + 0x50, 0 if r.random() < 0.3 else ch2)
    c.emu.w32(me + 0xdc, r.choice([3, 5, 5, 3, 0, 1, 2, 4, 6, 0xffffffff]))
    return [me]


def _g478f90(c):
    clear_hooks(c)
    r = c.rng
    size = r.choice([1, 2, 3, 5, 8])
    arr = rnd(c, 16 * (size + 2))
    vals = sorted(r.choice([x for x in EDGE_F if x == x]) if r.random() < 0.1 else float(r.randint(-5, 15)) for _ in range(size))
    if r.random() < 0.3:
        r.shuffle(vals)
    fi = float(r.randint(-6, 16))
    if r.random() < 0.4:   # an entry equal to the argument (unsorted arrays make the >= / > boundary visible)
        vals[r.randrange(size)] = fi
    for i, v in enumerate(vals):
        c.emu.w32(arr + 16 * i, struct.unpack('<I', struct.pack('<f', v))[0])
        c.emu.w32(arr + 16 * i + 4, r.getrandbits(32))
    me = rnd(c, 0x20)
    idx = r.randrange(0, size + 2) if r.random() < 0.9 else 0
    c.emu.w32(me, idx)
    c.emu.w32(me + 8, size)
    c.emu.w32(me + 0xc, arr)
    f = fi + r.choice([0.0, 0.0, 0.0, 0.5, -0.5])
    fb = struct.unpack('<I', struct.pack('<f', f))[0] if r.random() < 0.93 else _fbits(r)
    return [me, fb]


S(0x4616c0, 'GUESS set radius from max', 'thiscall', None, ret=None, gen=_g4616c0, note='batch34165')
S(0x5157d0, 'GUESS position from three float getters', 'thiscall', None, ret=None, gen=_g5157d0, note='batch34165')
S(0x561f70, 'GUESS finish a state', 'thiscall', None, ret=None, gen=_g561f70, note='batch34165')
S(0x478f90, 'GUESS move index in sorted array', 'thiscall', None, ret='eax', gen=_g478f90, note='batch34165')
