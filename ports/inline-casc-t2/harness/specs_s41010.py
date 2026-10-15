"""specs_s41010.py - t2 (Sonnet) batch 41010: 0x45aa90, 0x520c50. 0x523330 and slots are recorders; 0x4e09b0 (negate) runs as exe code."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _bits(f):
    try:
        return struct.unpack('<I', struct.pack('<f', f))[0]
    except OverflowError:
        return 0x7f800000


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g45aa90(c):
    clear_hooks(c)
    r = c.rng
    t = r.choice([r.uniform(0, 1), r.uniform(0, 1), 0.0, 1.0, 0.5, r.uniform(-2, 3), r.uniform(-300, 300), 1e9, -1e9, float('nan')])
    return [r.getrandbits(32), r.getrandbits(32), F(t)]


def g520c50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    vals = [_bits(r.choice([r.uniform(-3, 3), 0.0, 1.0, -1.0, 0.5])) if r.random() < 0.95 else NAN for _ in range(3)]

    def fill(emu, k):
        b = emu.arg32(0)
        for i in range(3):
            emu.w32(b + 4 * i, vals[i])
        emu.calllog.append(('fill',))
    hook_rec(c, 0x523330, 1, this=True, pop=4, nullflag=(0,), side=fill)
    f1 = r.choice([r.uniform(-5, 5), 0.0, 1.0, r.uniform(-1, 1)])
    cur = r.choice([f1, f1 + 1.0, f1 - 1.0, r.uniform(-5, 5), 0.0])
    A = obj(c, 0x40, {0xc: pystub(c, 0, this=True, st0=cur), 0x14: pystub(c, 0, this=True, st0=r.choice([r.uniform(-3, 3), 0.0, 1.0, -1.0, 2.5]))}, nslots=0x18 // 4)
    me = obj(c, 0x80, {0x360: pystub(c, 2, this=True, side=_log('s360')), 0x364: pystub(c, 2, this=True, side=_log('s364'))}, nslots=0x368 // 4)
    e.w32(me + 0x5c, A)
    for off in (0x6c, 0x74):
        e.wbytes(me + off, struct.pack('<I', _bits(r.choice([r.uniform(-3, 3), 0.0, 1.0, -1.0]))))
    return [me, F(f1), r.getrandbits(32)]


S(0x45aa90, 'GUESS lerp ARGB colours', 'stdcall', None, ret='eax', gen=g45aa90, note='batch41010')
S(0x520c50, 'GUESS pick side by facing', 'thiscall', None, ret=None, gen=g520c50, nan_heap=True, note='batch41010')
