"""specs_s32134.py - h2 () batch 32134: 0x5ddde0, 0x4609f0, 0x4945c0, 0x4c2610. Callees/slots are recorders."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _bits(f):
    try:
        return struct.unpack('<I', struct.pack('<f', f))[0]
    except OverflowError:
        return 0x7f800000


def _f32(f):
    return struct.unpack('<f', struct.pack('<f', f))[0]


def _fv(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def g5ddde0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0)
    hook_rec(c, 0x5de090, 1, this=True, pop=4, deref={0: 10})
    o44 = obj(c, 0x20, {0x84: pystub(c, 1, this=True, deref={0: 10})}, nslots=0x88 // 4)
    so = sysobj(c)
    blk = rnd(c, 0x2d00)
    e.w32(0x7003b8, blk)
    e.wbytes(blk + 0x2c4d, struct.pack('<I', r.choice([0, rnd(c, 0x20), rnd(c, 0x20)])))
    w = r.getrandbits(16)
    e.wbytes(0x71439c, struct.pack('<H', w))
    lo16 = r.choice([w, w, w, w ^ 0x100, w ^ 0x1, w ^ 0x8000, r.getrandbits(16)])
    a = (r.getrandbits(16) << 16) | lo16
    me = rnd(c, 0x80)
    e.w32(me + 0x44, o44)
    return [me, a, r.getrandbits(32)]


def g4609f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 1, 2, 3, 4])

    def side(emu, k):
        ecx = emu.reg('ecx')
        v = r.choice([NAN, _bits(r.uniform(-5, 5)), _bits(r.uniform(-5, 5)), _bits(1e30), 0x7f800000, 0xff800000, 0])
        emu.wbytes(ecx + 0x34, struct.pack('<I', v))
        emu.calllog.append(('w', k))
    hook_rec(c, 0x460100, 5, this=True, pop=20, side=side)
    me = rnd(c, 0x40)
    a = rnd(c, 0x38 * max(n, 1) + 0x40) if r.random() > 0.08 else 0
    b = rnd(c, 0x24 * max(n, 1) + 0x30) if r.random() > 0.08 else 0
    return [me, a, b, n, F(r.choice([0.0, 1.0, r.uniform(-3, 3)]))]


def g4945c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0)
    so = sysobj(c)
    cam = obj(c, 0x20, {0x184: pystub(c, 3, this=True)}, nslots=0x188 // 4)
    e.w32(so + 0x190f, r.choice([cam, cam, 0]))
    me = rnd(c, 0xc10)
    e.wbytes(me + 0xbc5, struct.pack('<I', r.choice([0, 0x80000000, NAN, _bits(r.uniform(-1, 1)), _bits(r.uniform(0, 1)), _bits(0.9), _bits(-0.1), _bits(0.0019), _bits(0.0021)])))
    idx = r.choice([0, 1, 2, 3, 4, 5, 6])
    f = r.choice([0.0, 1.0, 0.5, r.uniform(0, 1), r.uniform(0, 1), -1.0, 2.0, _fv(NAN), 0.01, 0.011, 0.009])
    if idx < 6 and r.random() < 0.5:
        # make x exactly equal to cur + 0.002f (boundary of the compare)
        T = [0.0, _f32(_fv(0x3e4ccccd)), _f32(_fv(0x3ecccccd)), _f32(_fv(0x3f4ccccd)), _fv(0x3f666666), _fv(0x3f733333), 1.0]
        cur = _fv(struct.unpack('<I', e.rbytes(me + 0xbc5, 4))[0])
        if cur == cur and abs(cur) < 1e6:
            lim = _f32(cur + _f32(0.002))
            lo, hi = T[idx], T[idx + 1]
            f0 = _f32((lim - lo) / (hi - lo))
            fb = _bits(f0)
            for d in range(-40, 41):
                cand = _fv((fb + d) & 0xffffffff)
                x = _f32(_f32(_f32(hi - lo) * cand) + lo)
                if x == lim:
                    f = cand
                    break
    return [me, idx, r.getrandbits(32), F(f)]


def g4c2610(c):
    clear_hooks(c)
    r = c.rng
    slots = {off: pystub(c, 1, this=True) for off in (0x60, 0x4c, 0x3c, 0x40)}
    o = obj(c, 0x20, slots, nslots=0x64 // 4)
    me = rnd(c, 0x1e0)
    return [me, o]


S(0x5ddde0, 'GUESS forward state on matching id', 'thiscall', None, ret='eax', gen=g5ddde0, nan_heap=True, note='batch32134')
S(0x4609f0, 'GUESS accumulate element values', 'thiscall', None, ret=None, gen=g4609f0, nan_heap=True, note='batch32134')
S(0x4945c0, 'GUESS interpolate and raise value', 'thiscall', None, ret='st0', gen=g4945c0, nan_heap=True, note='batch32134')
S(0x4c2610, 'GUESS apply state to object', 'thiscall', None, ret='al', gen=g4c2610, nan_heap=True, note='batch32134')
