"""specs_s35183.py - 0x597720 (thiscall(out) ret 4, ret='eax', nan_heap). this: 0x2100 random bytes; unaligned [+0x4f7] = O (zero in 1/8), [+0x1d0b] = P, count [+0x4ef] in -1..4 and ids at +0x2ef.
P: slot 0x84 (1 arg flag-recorded; writes random floats into A), [P+0x54] -> block with [+0x10] = T. O: slot 0x84 (4 args; &A recorded as 3 dwords, the 1500.0 constant raw, &state flag, T) returns candidates 0..5 in turn, then 0.
Candidates: [+0x54] -> block with dword +8 equal to 4 in 1/6; slot 0x438 (al true in 1/6); slot 0x84 (1 arg flag, writes random floats into B); one of them may be P itself. Engine table slot 0x4c returns ids from a small set (some in the array). 0x597a20 / 0x597b10 hooked (thiscall, 1 arg, al true in 1/6),
0x59ffc0 hooked (returns 5 in 1/5), 0x4e0830 replaced by a Python handler returning a squared-distance value from a list around the thresholds (0x67cd44 start value and 0x6ad31c limit), logging both vectors. out: heap pointer (null in 1/4)."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj, _HOOKED


def _f(b):
    return struct.unpack('<f', struct.pack('<I', b))[0]


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g597720(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    K0 = _f(e.r32(0x67cd44))
    TH = _f(e.r32(0x6ad31c))
    me = rnd(c, 0x2100)
    e.wbytes(me + 0x4f7, (0 if r.random() < 1 / 8 else 1).to_bytes(4, 'little'))  # patched below
    P = obj(c, 0x80, {0x84: pystub(c, 1, this=True, nullflag=(0,), side=lambda em, k: [em.w32(em.arg32(0) + 4 * i, _fb(c.fv(-50, 50))) for i in range(3)])}, nslots=0x24)
    e.w32(P + 0x54, rnd(c, 0x30))
    e.w32(e.r32(P + 0x54) + 0x10, r.getrandbits(32))
    e.wbytes(me + 0x1d0b, P.to_bytes(4, 'little'))
    ncand = r.choice([0, 1, 2, 3, 4, 5])
    cands = []
    ids = [r.choice([1, 2, 3, 4, 5, 6, 7, 8]) for _ in range(ncand)]
    for i in range(ncand):
        blk = rnd(c, 0x20)
        e.w32(blk + 8, 4 if r.random() < 1 / 6 else r.choice([0, 1, 2, 3, 5]))
        cand = obj(c, 0x80, {0x438: pystub(c, 0, this=True, ret=(r.getrandbits(32) | 1) if r.random() < 1 / 6 else (r.getrandbits(24) << 8)),
                             0x84: pystub(c, 1, this=True, nullflag=(0,), side=lambda em, k: [em.w32(em.arg32(0) + 4 * i, _fb(c.fv(-50, 50))) for i in range(3)])}, nslots=0x120)
        e.w32(cand + 0x54, blk)
        e.wbytes(cand + 0x77f, (5 if r.random() < 1 / 5 else r.choice([0, 1, 4, 6, r.getrandbits(32)])).to_bytes(4, 'little'))
        cands.append(cand)
    if cands and r.random() < 1 / 6:
        cands[r.randrange(len(cands))] = P
    seq = cands + [0]
    O = obj(c, 0x20, {0x84: pystub(c, 4, this=True, deref={0: 3}, nullflag=(2,), ret=lambda em, k: seq[min(k, len(seq) - 1)], side=lambda em, k: em.calllog.append(('state', em.r32(em.arg32(2)))))}, nslots=0x24)
    if r.random() < 1 / 8:
        e.wbytes(me + 0x4f7, bytes(4))
    else:
        e.wbytes(me + 0x4f7, O.to_bytes(4, 'little'))
    cnt = r.choice([-1, 0, 1, 2, 3, 4])
    e.w32(me + 0x4ef, cnt & 0xffffffff)
    for i in range(4):
        e.w32(me + 0x2ef + 4 * i, r.choice([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=lambda em, k: ids[min(k, max(len(ids) - 1, 0))] if ids else 0)}, table_size=0x60)
    hook_rec(c, 0x597a20, 1, this=True, pop=4, ret=lambda em, k: 1 if r.random() < 1 / 6 else 0)
    hook_rec(c, 0x597b10, 1, this=True, pop=4, ret=lambda em, k: 1 if r.random() < 1 / 6 else 0)
    hook_rec(c, 0x59ffc0, 0, this=True, pop=0, ret=lambda em, k: 5 if r.random() < 1 / 5 else r.choice([0, 1, 4]))
    dvals = [0.0, 1.0, TH, TH * 0.5, TH * 1.001, TH * 0.999, K0, K0 * 0.5, K0 * 0.999, K0 * 1.001, float('inf'), float('nan'), 1e-3, 10.0, 100.0, -0.0]
    seqd = [r.choice(dvals) for _ in range(8)]
    if r.random() < 1 / 3:
        seqd = [r.choice([TH * 0.5, 1.0, 10.0, 0.0, TH])] * 8   # equal distances: a candidate must not replace an equal best
    cnt4 = [0]

    def h4e(em, res_):
        b = em.reg('ecx')
        a = em.reg('edx')
        vb = tuple(em.r32(b + 4 * i) for i in range(3))
        va = tuple(em.r32(a + 4 * i) for i in range(3))
        em.calllog.append(('4e0830', vb, va))
        d = seqd[min(cnt4[0], 7)]
        cnt4[0] += 1
        em.ret(st0=d)
    e.hook(0x4e0830, h4e)
    _HOOKED.add(0x4e0830)
    out = 0 if r.random() < 1 / 4 else rnd(c, 8)
    return [me, out]


S(0x597720, 'GUESS nearest valid candidate around the player with distance', 'thiscall', None, ret='eax', gen=_g597720, nan_heap=True, note='batch35183')
