"""specs_s35187.py - 0x45e930 (thiscall(a) ret 4, ret='st0'). Engine table slot 0x54 (1 arg) returns an entity e (null in 1/6; floats at +0x30..0x38); this: [+8] -> block with floats at +0x30..0x38, slot 0x84 (1 arg; the position vector is rewritten with random floats), slot 0x80 (2 args; P (9 dwords) is written on the caller's stack
as an orthonormal-ish frame or random floats, and A is recorded). 0x4db670 hooked (thiscall, 1 arg; writes the vector A + a delta in which each component is zero in a third of the cases, so B - A can have x or z zero). The normalisation, 0x43e960, 0x4e09b0 and acos run as real code."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _f(b):
    return struct.unpack('<f', struct.pack('<I', b))[0]


def _g45e930(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    st = {}

    def fl(lo=-30, hi=30):
        return r.choice([c.fv(lo, hi), c.fv(lo, hi), c.fv(-1, 1), 0.0, 1.0, -1.0])

    def s84(em, k):
        a = em.arg32(0)
        em.calllog.append(('84in', tuple(em.r32(a + 4 * i) for i in range(3))))
        v = [fl() for _ in range(3)]
        st['A'] = v
        for i in range(3):
            em.w32(a + 4 * i, _fb(v[i]))

    def s80(em, k):
        p, a = em.arg32(0), em.arg32(1)
        em.calllog.append(('80in', tuple(em.r32(a + 4 * i) for i in range(3))))
        t = r.random()
        if t < 0.5:
            vals = [fl(-2, 2) for _ in range(9)]
        else:
            ax = r.choice([(1, 0, 0), (-1, 0, 0), (0, 0, 1), (0, 0, -1), (0.6, 0, 0.8), (0, 1, 0)])
            vals = [ax[0], ax[1], ax[2]] + [fl(-1, 1) for _ in range(3)] + [fl(-1, 1) for _ in range(3)]
        for i in range(9):
            em.w32(p + 4 * i, _fb(vals[i]))

    def s670(em, k):
        b = em.arg32(0)
        A = st.get('A', [0.0, 0.0, 0.0])
        for i in range(3):
            binp = _f(em.r32(b + 4 * i))
            m = r.random()
            if m < 1 / 3:
                nv = binp
            elif m < 2 / 3:
                nv = A[i]
            else:
                nv = struct.unpack('<f', struct.pack('<f', binp + c.fv(-5, 5)))[0]
            em.w32(b + 4 * i, _fb(nv))
    me = obj(c, 0x40, {0x84: pystub(c, 1, this=True, nullflag=(0,), side=s84), 0x80: pystub(c, 2, this=True, nullflag=(0, 1), side=s80)}, nslots=0x24)
    blk = rnd(c, 0x50)
    for i in range(3):
        e.w32(blk + 0x30 + 4 * i, _fb(fl()))
    e.w32(me + 8, blk)
    ent = 0 if r.random() < 1 / 6 else rnd(c, 0x80)
    if ent:
        for i in range(3):
            e.w32(ent + 0x30 + 4 * i, _fb(fl()))
    sysobj(c, table_slots={0x54: pystub(c, 1, this=True, ret=ent)}, table_size=0x60)
    hook_rec(c, 0x4db670, 1, this=True, pop=4, nullflag=(0,), side=s670)
    return [me, r.getrandbits(32)]


S(0x45e930, 'GUESS signed angle between entity direction and direction to another', 'thiscall', None, ret='st0', gen=_g45e930, nan_heap=True, note='batch35187')
