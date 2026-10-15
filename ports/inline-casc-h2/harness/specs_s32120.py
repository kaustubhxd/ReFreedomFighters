"""specs_s32120.py - h2 (Sonnet) batch 32120: tier H functions. The x87 vector subtract 0x43e920 runs as exe code; callees/slots are recorders; order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g59a8f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))

    def fill(emu, k):
        base = emu.arg32(0)
        for i in range(4):
            emu.w32(base + 4 * i, struct.unpack('<I', struct.pack('<f', r.uniform(-9, 9)))[0])
    o = obj(c, 0x20, {0x240: pystub(c, 1, this=True, nullflag=(0,), side=fill)}, nslots=0x240 // 4 + 1)
    so = sysobj(c)
    e.wbytes(so + 0x6f, r.choice([0, 1, 640, 0xffffff00, r.getrandbits(32), r.randrange(0, 2000)]).to_bytes(4, 'little'))
    e.wbytes(so + 0x73, r.choice([0, 1, 480, 0xffffff00, r.getrandbits(32), r.randrange(0, 2000)]).to_bytes(4, 'little'))
    me = rnd(c, 0x1d40)
    e.wbytes(me + 0x1d07, (o if r.random() < 0.75 else 0).to_bytes(4, 'little'))
    return [me]


def g5510e0(c):
    clear_hooks(c)
    r = c.rng
    q = rnd(c, 0x20)
    seq = [rnd(c, 0x10) for _ in range(3)]
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=lambda emu, k: seq[min(k, 2)], side=_log('lk'))
    hook_rec(c, 0x500360, 1, this=True, pop=4, side=_log('f'))
    b = obj(c, 0x20, {0x4c: pystub(c, 0, ret=q, this=True, side=_log('q'))}, nslots=0x4c // 4 + 1)
    p = obj(c, 0x20, {0x18: pystub(c, 1, ret=(b if r.random() < 0.8 else 0), this=True, side=_log('b'))}, nslots=0x18 // 4 + 1)
    return [p, r.getrandbits(32), rnd(c, 0x10)]


def g4cb030(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sbuf = rnd(c, 0x40)
    ln = r.choice([0, 1, 5, 0x1d, 0x1f])
    e.wbytes(sbuf, bytes(r.randrange(1, 256) for _ in range(ln)) + b'\0')
    fl = [struct.unpack('<f', struct.pack('<f', r.uniform(-50, 50)))[0] for _ in range(6)]
    hook_rec(c, 0x4e5ea0, 0, this=True, pop=0, ret=sbuf, side=_log('s'))
    hook_rec(c, 0x4e5e80, 0, this=True, pop=0, st0=lambda emu, k: fl[min(k, 5)], side=_log('f'))
    return [rnd(c, 0x90), rnd(c, 0x20)]


def g478c10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k4 = r.uniform(0.5, 5)
    hook_rec(c, 0x478f90, 1, this=True, pop=4, ret=r.randrange(0, 3), side=_log('idx'))
    blk = rnd(c, 0x200)
    for i in range(0x200 // 4):
        e.wbytes(blk + 4 * i, struct.pack('<f', r.uniform(-9, 9)))
    me = rnd(c, 0x20)
    e.w32(me + 0xc, blk + 0x80)
    e.wbytes(me + 4, struct.pack('<f', k4))
    e.w32(me + 8, r.randrange(0, 3))
    t = r.choice([-1.0, -0.0, 0.0, k4 * 0.5, k4, k4 + 1.0, r.uniform(0, k4), _f(NAN)])
    return [me, rnd(c, 0x20), F(t)]


S(0x59a8f0, 'GUESS read scale from member and scale screen size (GS frame)', 'thiscall', None, ret=None, gen=g59a8f0, nan_heap=True, note='batch32120')
S(0x5510e0, 'GUESS look up object and set three float components', 'stdcall', None, ret='eax', gen=g5510e0, note='batch32120')
S(0x4cb030, 'GUESS read name and six floats from source', 'thiscall', None, ret='al', gen=g4cb030, nan_heap=True, note='batch32120')
S(0x478c10, 'GUESS interpolation segment difference', 'thiscall', None, ret=None, gen=g478c10, nan_heap=True, note='batch32120')
