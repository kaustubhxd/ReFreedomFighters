"""specs_s32121.py - h2 (Sonnet) batch 32121: tier H functions. Callees/slots are recorders; order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g5cd5c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0xe00)
    for off in (0xb33, 0xb34, 0xb30, 0xb2f, 0xdd8):
        e.wbytes(me + off, bytes([r.choice([0, 0, 1, 7])]))
    for off in (0xb1f, 0xb23, 0xb27, 0xb2b):
        e.wbytes(me + off, struct.pack('<f', r.choice([r.uniform(-9, 9), 0.0, -0.0, _f(NAN), 1e30])))
    return [me]


def g5b7d40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5a5730, 2, this=True, pop=8, side=_log('rel'))
    hook_rec(c, 0x5a56d0, 3, this=True, pop=0xc, ret=r.getrandbits(32), side=_log('new'))
    so = sysobj(c)
    e.wbytes(so + 0x48, struct.pack('<f', r.uniform(0, 0.2)))
    me = rnd(c, 0x40)
    e.wbytes(me + 4, struct.pack('<f', r.choice([-1.0, -0.0, 0.0, 0.5, 5.0, _f(NAN)])))
    e.w32(me + 0x24, r.choice([0, rnd(c, 0x10)]))
    e.wbytes(me + 0x28, bytes([r.choice([0, 1, 1])]))
    return [me, rnd(c, 0x20)]


def g504c00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ra, rb, rc, rd = rnd(c, 0x10), rnd(c, 0x10), rnd(c, 0x10), rnd(c, 0x10)
    for p in (ra, rb):
        e.wbytes(p, struct.pack('<f', r.uniform(-9, 9)))
    e.w32(rc, r.getrandbits(32))
    seq = [ra, rb, rc, rd]
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=lambda emu, k: seq[min(k, 3)], side=_log('lk'))
    hook_rec(c, 0x5002f0, 1, this=True, pop=4, ret=r.getrandbits(32), side=_log('set'))
    so = sysobj(c)
    tbl = e.r32(so + 0x9b)
    e.w32(tbl + 0x44, r.getrandbits(32))
    me = obj(c, 0x20, {0x5c: pystub(c, 3, ret=r.getrandbits(32), this=True, side=_log('s5c'))}, nslots=0x5c // 4 + 1)
    p = rnd(c, 0x20)
    e.w32(p + 4, rnd(c, 0x20))
    e.w32(p + 8, rnd(c, 0x20))
    return [me, p]


S(0x5cd5c0, 'GUESS clear inactive input axes', 'thiscall', None, ret=None, gen=g5cd5c0, nan_heap=True, note='batch32121')
S(0x5b7d40, 'GUESS tick timed effect and (re)create handle', 'thiscall', None, ret='al', gen=g5b7d40, nan_heap=True, note='batch32121')
S(0x504c00, 'GUESS combine three vector components through slot 0x5c', 'thiscall', None, ret='eax', gen=g504c00, note='batch32121')
