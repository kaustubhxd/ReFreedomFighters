"""specs_s52007.py - tier H. 0x5251c0: this[0xbc] zero half the time; engine block +0x40 (int) vs this[0x84] (both sides of the compare); [this+0x88] object with recorder slots 0x7c / 0x80; the refreshers 0x524ff0, 0x526cf0, 0x524de0, 0x526470, 0x526ac0, 0x526360, 0x525f30, 0x526880, 0x526c60 are recorder hooks (ECX); 0x4e0030 a custom hook (ECX and EDX recorded, random st0 float); 0x4de420 and 0x446ee0 (cross product) run for real; floats are explicit (zero, negative, NaN)."""
import struct
from pilot import S, EDGE_F, F
import recruits_util
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _fbits(r):
    k = r.random()
    if k < 0.2:
        v = r.choice(EDGE_F)
    elif k < 0.25:
        return r.getrandbits(32)
    else:
        v = r.uniform(-100, 100)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _fv(r):
    return struct.unpack('<f', struct.pack('<I', _fbits(r)))[0]


def _g5251c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    for a in (0x524ff0, 0x526cf0, 0x524de0, 0x526470, 0x526ac0, 0x526360, 0x525f30, 0x526880, 0x526c60):
        hook_rec(c, a, 0, this=True, pop=0)
    k = r.choice([0.0, 1.0, -1.0, 2.5, -7.0, _fv(r)])
    k = k if k == k else 0.0

    def h(em, rr):
        em.calllog.append(('4e0030', em.reg('ecx'), em.reg('edx')))
        em.ret(st0=k)
    e.hook(0x4e0030, h)
    recruits_util._HOOKED.add(0x4e0030)
    so = sysobj(c)
    n = r.choice([-1, 0, 1, 2, 5])
    e.w32(so + 0x40, n & 0xffffffff)
    e.w32(so + 0x48, _fbits(r))
    o = obj(c, 0x20, {0x7c: pystub(c, 2, this=True), 0x80: pystub(c, 2, this=True)}, nslots=0x84 // 4)
    me = rnd(c, 0x100)
    e.wbytes(me + 0xbc, bytes([0 if r.random() < 0.5 else r.getrandbits(8) | 1]))
    e.w32(me + 0x84, r.choice([-1, 0, 1, 2, 5, 6]) & 0xffffffff)
    e.w32(me + 0x88, o)
    for off in range(0, 0x80, 4):
        if r.random() < 0.5:
            e.w32(me + off, _fbits(r))
    A = rnd(c, 0x30)
    B = rnd(c, 0x10)
    C = rnd(c, 0x10)
    D = rnd(c, 0x10)
    for i in range(3):
        e.w32(C + 4 * i, _fbits(r))
        e.w32(D + 4 * i, _fbits(r))
    return [me, A, B, C, D, F(_fv(r)), F(_fv(r)), F(_fv(r)), F(_fv(r))]


S(0x5251c0, 'GUESS init moving point refresh', 'thiscall', None, ret=None, gen=_g5251c0, note='batch52007')
