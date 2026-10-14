"""specs_s863.py - area 50, batch 863: 0x5cfd90 (name GUESS), thiscall, one stack arg (the output), ret 4, bool.
The distance helper 0x4e0830 runs as exe code (vector differences and a sqrt). Stood in: 0x5cf5d0 (a per-record value, returned
in ST0 from a generation-time list keyed by the record's address). The record count at +0x48 is 0..6; the records are 0x14 bytes
from +0x4c; the point at +0xc71 is generated so that some distances fall in the accepted range."""
import struct
from pilot import S
from anim_common import only_hooks, rnd


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _gen(c):
    e, r = c.emu, c.rng
    fin = lambda x: x if x == x and abs(x) < 1e6 else 0.0
    vals = {}

    def f5cf(e, rr):
        obj = e.arg32(0)
        e.calllog.append(('cand.5cf5d0',))
        e.ret(eax=0, argbytes=4, st0=vals.get(obj, 0.0))

    only_hooks(c, {0x5cf5d0: f5cf})                   # 0x4e0830 returns the squared distance (no sqrt)
    self = rnd(c, 0x1000)
    n = r.randint(0, 6)
    mode = r.choice(['rand', 'rand', 'rand', 'eqK1', 'eqK3', 'eqE', 'dup'])
    if mode in ('eqK1', 'eqK3'):
        n = 1                                 # the boundary record must be the only candidate
    elif mode == 'dup':
        n = 2
    e.w32(self + 0x48, n)
    pt = [fin(c.fv(-200, 200)), fin(c.fv(-200, 200)), fin(c.fv(-200, 200))]
    if mode in ('eqK1', 'eqK3', 'eqE', 'dup'):
        pt = [0.0, 0.0, 0.0]                  # the point is the origin: distances are the record's own length
    for i, off in enumerate((0xc71, 0xc75, 0xc79)):
        e.wf32(self + off, pt[i])
    for k in range(n):
        rec = self + 0x4c + 0x14 * k
        # the object part of a record is a vector (+4..+0xc) somewhere near the point, sometimes far away
        base = [pt[i] + r.uniform(-900, 900) * (0.01 if r.random() < 0.5 else 1.0) for i in range(3)]
        for i in range(3):
            e.wf32(rec + 4 + 4 * i, _f32(base[i]))
        vals[rec + 4] = _f32(r.uniform(-0.1, 0.5))
        if mode == 'eqK1' and k == 0:
            for i, v in enumerate((_f32(800.0), 0.0, 0.0)):
                e.wf32(rec + 4 + 4 * i, v)              # squared distance == 640000 exactly
        if mode == 'eqK3' and k == 0:
            for i, v in enumerate((_f32(3500.0), 0.0, 0.0)):
                e.wf32(rec + 4 + 4 * i, v)              # squared distance == 12250000 exactly
        if mode == 'eqE' and k == 0:
            vals[rec + 4] = _f32(0.2617993950843811)   # the candidate value equals the bound exactly
        if mode == 'dup' and k == 1:
            src = self + 0x4c + 4
            e.wf32(rec + 4, -e.rf32(src))                   # the same length, another direction: equal distance
            e.wf32(rec + 8, e.rf32(src + 4))
            e.wf32(rec + 12, e.rf32(src + 8))
            vals[rec + 4] = vals[src]
    return [self, rnd(c, 16)]


S(0x5cfd90, 'Nearest5cfd90 (GUESS name)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch863')
