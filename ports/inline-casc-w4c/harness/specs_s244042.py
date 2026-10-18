"""specs_s244042.py - hand-written specs for batch 244042."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g5ec8b0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda v: struct.pack('<f', v)
    FV = [0.0, 1.0, 2.0, 0.5, -1.0, 4.0, 100.0, 0.25, 3.0, r.uniform(0.1, 9)]
    NZ = [1.0, 2.0, 0.5, 4.0, -2.0, 8.0, 0.25]
    nidx = 4
    idx = r.randrange(0, nidx)
    # records A (u16 x4 at +0..+6, floats at +8 / +0xc) and K (u16 at +0 / +2 / +0xc, s16 at +0xe, u32 type at +4 and +8)
    Aptr = em.alloc(4 * nidx + 4, 4)
    Kptr = em.alloc(4 * nidx + 4, 4)
    for i in range(nidx):
        a = rnd(c, 0x20)
        for o in (0, 2, 4, 6):
            em.wbytes(a + o, struct.pack('<H', r.choice([0, 1, 5, 0x7fff, 0x8000, 0xffff, r.getrandbits(16)])))
        em.wbytes(a + 8, pk(r.choice(FV)))
        em.wbytes(a + 0xc, pk(r.choice(FV)))
        k = rnd(c, 0x20)
        for o in (0, 2, 0xc):
            em.wbytes(k + o, struct.pack('<h', r.choice([0, 1, -1, 7, -300, 32767, -32768])))
        em.wbytes(k + 0xe, struct.pack('<h', r.choice([0, 1, -1, 5, -400, 32767])))
        em.w32(k + 4, r.choice([0, 1, 2, 3, 3, 4, 7]))
        em.w32(k + 8, r.choice([0, 1, 2, 3, 3, 4, 9]))
        em.w32(Aptr + 4 * i, a)
        em.w32(Kptr + 4 * i, k)
    T = rnd(c, 0x20)
    out = rnd(c, 40 * nidx + 64)
    em.w32(T + 4, out)
    me = rnd(c, 0x100)
    em.w32(me + 0x62, Aptr)
    em.w32(me + 0xcb, Kptr)
    em.w32(me + 0x3a, T)
    em.w32(me + 0x52, r.choice([0, 1, 100, 640, 0x7fffffff, 0x80000000, 0xffffff00]))
    em.w32(me + 0x56, r.choice([0, 1, 100, 480, 0x7fffffff, 0x80000000, 0xffffff00]))
    em.wbytes(me + 0xb3, pk(r.choice(FV)))
    em.wbytes(me + 0xb7, pk(r.choice(FV)))

    def lg(nm):
        return lambda emu, k: emu.calllog.append((nm, emu.reg('ecx')))
    s8 = pystub(c, 0, ret=r.getrandbits(32), pop=0, this=True, st0=lambda emu, k: r.choice(NZ), side=lg('v8'))
    sc = pystub(c, 0, ret=r.getrandbits(32), pop=0, this=True, st0=lambda emu, k: r.choice(NZ), side=lg('vc'))
    ao = obj(c, 0x40, {0x8: s8, 0xc: sc})
    return [me, ao, 0, idx]


S(0x5ec8b0, 'GUESS UI quad layout: positions a textured quad from two 16-bit rectangles, 4 x 4 anchor modes', 'thiscall', 3, ret=None, gen=g5ec8b0, note='batch244042')
