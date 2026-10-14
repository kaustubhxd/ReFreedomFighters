"""specs_s1611.py - soundtimers batch 1611: ZGROUP::AddSound3d / AddSound2d and the distance setter 0x441890.
The profiler marks run as exe code with profiling off (sys +0x9c3/+0x9c7 = 0). The DLL's +0xd8 gets a pointer to a
stack copy of the group position, so it is a Python stub that logs the vector's contents."""
import struct
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks, sound_obj
from specs_s1606 import _vecstub


def _f(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _dist(c):
    r = c.rng
    o = rnd(c, 0x100)
    c.emu.wf32(o + 0x88, r.choice([0.0, -0.0, 100.0, 50.0, float('nan'), r.uniform(0, 100)]))
    return [o, _f(r.choice([1.0, 18.0, 0.0, r.uniform(0, 3000)]))]


S(0x441890, 'ZSoundObject::SetDistances (guessed name)', 'thiscall', None, ret=None, gen=_dist, note='batch1611')


def _add2d(c):
    seq = Seq(c)
    r = c.rng
    dll = obj(c, 0x200, {0x120: stub(c, seq, 2, ret=r.getrandbits(32))})
    sysobj(c, extra={0x1a9f: dll if r.random() < 0.85 else 0})
    return [rnd(c, 0x20), r.getrandbits(32)]


S(0x43eb80, 'ZGROUP::AddSound2d', 'thiscall', None, ret='eax', gen=_add2d, note='batch1611')


def _logd8(c, seq):
    log = c.emu.alloc(0x30, 4)

    def h(e, rr):
        sp = e.reg('esp')
        e.w32(log, e.r32(sp + 4))
        e.wbytes(log + 4, e.rbytes(e.r32(sp + 8), 12))
        for i in range(4):
            e.w32(log + 0x10 + 4 * i, e.r32(sp + 12 + 4 * i))
        e.w32(log + 0x20, e.r32(log + 0x20) + 1)
        e.w32(seq.addr, e.r32(seq.addr) + 1)
        e.ret(argbytes=0x18)
    return c.emu.stub_fn('DLL_d8', h)


def _add3d(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    h = r.getrandbits(32) | 1
    so = sound_obj(c) if r.random() < 0.85 else 0
    if so:
        c.emu.wf32(so + 0x88, r.choice([0.0, 100.0, r.uniform(0, 100)]))
    rec = rnd(c, 0x20)
    c.emu.w32(rec, r.choice([2, 2, 1, 0, 3]))
    c.emu.w8(rec + 0x17, r.choice([0, 4, 0xc, 0x80, 0xff, r.getrandbits(8)]))
    c.emu.wf32(rec + 0xc, r.uniform(0, 30))
    dll = obj(c, 0x200, {0x11c: stub(c, seq, 4, ret=h if r.random() < 0.9 else 0), 0x54: stub(c, seq, 1, ret=rec),
                         0xd8: _logd8(c, seq)})
    db = obj(c, 0x40, {0x60: stub(c, seq, 1, ret=0, retfn=[(0, h, so)])})
    s = sysobj(c, db=db, extra={0x1a9f: dll if r.random() < 0.9 else 0, 0x9c3: 0, 0x9c7: 0})
    grp = obj(c, 0x100, {0x84: _vecstub(c, seq, [r.uniform(-1e3, 1e3) for _ in range(3)])})
    mat, pos = rnd(c, 0x24), rnd(c, 12)
    kind = r.choice([0, 0, 4, 0xc, 1, r.getrandbits(32)])
    return [grp, mat, pos, r.getrandbits(32) if r.random() < 0.9 else 0, kind, r.getrandbits(32), r.getrandbits(32)]


S(0x43ec00, 'ZGROUP::AddSound3d', 'thiscall', None, ret='eax', gen=_add3d, note='batch1611')
