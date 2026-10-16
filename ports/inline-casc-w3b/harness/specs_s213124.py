"""specs_s213124.py - batch 213124: archive reader for a record (id switch, floats, flag group by archive type), Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g44bdb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    flag = lambda p: (lambda emu, k: (rb() & ~0xff) | (1 if r.random() < p else 0))
    f32 = lambda v: struct.pack('<f', v)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=rb())
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    # engine object
    T = obj(c, 0x40, {0x2c: pystub(c, 0, this=True, ret=flag(0.15))}, nslots=0x40)
    eng = rnd(c, 0x2000)
    e.wbytes(eng + 0x1a9f, struct.pack('<I', 0 if r.random() < 0.12 else rb() | 1))
    e.w32(eng + 0x9b, T)
    e.w32(0x70039c, eng)
    # error path objects: [0x700390] -> slot 0x20 returns R, R's vtable slot 0x2c is a cdecl (obj, str) recorder with ecx = R's vtable
    R = obj(c, 0x40, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x40)
    L = obj(c, 0x40, {0x20: pystub(c, 2, this=True, ret=R)}, nslots=0x40)
    e.w32(0x700390, L)
    X = rnd(c, 0x200)
    self_ = rnd(c, 0x40)
    e.w32(self_ + 0x18, 0 if r.random() < 0.1 else X)
    ar = rnd(c, 0x20)
    ids = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0xffffffff, rb()]

    def dw():
        return r.choice([0, 1, 0, 1, 2, rb()] if r.random() < 0.5 else ids)
    first = [True]

    def fl():
        return f32(r.choice([0.0, -0.0, 1.5, -2.5, float('nan'), r.uniform(-9, 9)]))

    def s11(emu, k):
        p = emu.arg32(0)
        if first[0]:
            first[0] = False
            emu.wbytes(p, struct.pack('<I', r.choice(ids[:10] * 2 + [10, 11, 0xffffffff, rb()])))
        else:
            emu.wbytes(p, struct.pack('<I', dw()))

    def s12f0(emu, k):
        emu.wbytes(emu.arg32(0), fl())
    hook_rec(c, 0x4e11e0, 2, pop=8, this=True, stackmark=(0,), side=s11)
    hook_rec(c, 0x4e12e0, 2, pop=8, this=True, stackmark=(0,), side=s11)
    hook_rec(c, 0x4e12f0, 2, pop=8, this=True, stackmark=(0,), side=s12f0)
    types = [3, 3, 3, 2, 2, 1, 0xff, 0]
    hook_rec(c, 0x4e1600, 0, pop=0, this=True, ret=lambda emu, k: (rb() & ~0xff) | r.choice(types))
    hook_rec(c, 0x4e1b30, 0, pop=0, this=True)
    hook_rec(c, 0x441890, 1, pop=4, this=True)
    return [self_, ar]


S(0x44bdb0, 'archive_read_record', 'thiscall', None, ret=None, gen=g44bdb0)
