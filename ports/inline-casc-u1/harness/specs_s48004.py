"""specs_s48004.py - tier H. 0x522520: this block (unaligned fields +0x25d1 pointer, +0x26ee/+0x26f2/+0x26f6/+0x26fa ids, +0x26fe/+0x2702 float timers), vtable slots 0x308 / 0x2e8 / 0x2ec, embedded objects at +0x263c (slots 4, 8, 0xc) and +0x2664 (slot 0x18, st0), engine object with float at +0x20 and table slot 0x60,
hooked 0x5216a0, 0x4de040 (fastcall, fills a block) and 0x4dcb90, /GS check keeping eax."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _fv(r, lo=-3, hi=3):
    k = r.random()
    if k < 0.1:
        return r.choice(EDGE_F)
    return r.uniform(lo, hi)


def _fb(x):
    return struct.pack('<f', x)


def _g522520(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda e, k: e.reg("eax"))
    hook_rec(c, 0x5216a0, 0, this=True, pop=0)
    state = {}

    def fill(e, k):
        d = e.reg('ecx')
        for i in range(9):
            e.w32(d + 4 * i, r.getrandbits(32))
    # 0x4de040: fastcall(ecx = out, edx = src, stack 0) ret 4; only stack and edx recorded through hook_rec args
    hook_rec(c, 0x4de040, 1, pop=4, side=lambda e, k: (fill(e, k), e.w32(state['rec'] + 4 * min(k, 7), e.reg('edx'))))
    state['rec'] = em.alloc(40, 4)
    hook_rec(c, 0x4dcb90, 1, this=True, pop=4, deref={0: 9})
    # objects reached through [this+0x25d1]+8
    inner = rnd(c, 0x20)
    outer = rnd(c, 0x20)
    em.w32(outer + 8, inner)
    # slot objects
    idsrc = [r.getrandbits(32) for _ in range(6)]
    me = obj(c, 0x2800, {0x308: pystub(c, 2, this=True), 0x2e8: pystub(c, 1, this=True, ret=lambda e, k: r.choice([0, 1, 7, r.getrandbits(32)])), 0x2ec: pystub(c, 1, this=True)}, nslots=0x30c // 4)
    # embedded e at +0x263c: vtable slots 4 (2 args), 8 (1 arg), 0xc (bool)
    evt = em.alloc(0x20, 4)
    em.w32(evt + 4, pystub(c, 2, this=True))
    em.w32(evt + 8, pystub(c, 1, this=True))
    em.w32(evt + 0xc, pystub(c, 0, ret=r.choice([0, 1, 1, 0x100, 0xff00]), this=True))
    em.w32(me + 0x263c, evt)
    tvt = em.alloc(0x20, 4)
    em.w32(tvt + 0x18, pystub(c, 0, this=True, st0=lambda e, k: _fv(r, -2, 2)))
    em.w32(me + 0x2664, tvt)
    em.w32(me + 0x2610, r.choice([0, 0, 1, r.getrandbits(32)]))
    em.wbytes(me + 0x25d1, outer.to_bytes(4, 'little'))
    o1 = rnd(c, 0x90)
    o2 = rnd(c, 0x90)
    objs = [o1, o2, 0]
    em.wbytes(o1 + 0x70, _fb(_fv(r, -5, 5)))
    thr = struct.unpack('<f', struct.pack('<f', 0.0))[0]
    sys_ = sysobj(c, table_slots={0x60: pystub(c, 1, ret=lambda e, k: r.choice([o1, o2, o2, 0]), this=True)})
    em.wbytes(sys_ + 0x20, _fb(_fv(r, 0, 2) if r.random() < 0.9 else _fv(r, -3, 3)))
    em.wbytes(me + 0x26fa, r.choice([0, 0, r.getrandbits(32), 5]).to_bytes(4, 'little'))
    em.wbytes(me + 0x26fe, _fb(_fv(r, 0, 3)))
    em.wbytes(me + 0x2702, _fb(_fv(r, 0, 3)))
    for off in (0x26ee, 0x26f2, 0x26f6):
        em.wbytes(me + off, r.getrandbits(32).to_bytes(4, 'little'))
    return [me]


S(0x522520, 'GUESS per-frame update of actor timed object', 'thiscall', None, ret=None, gen=_g522520, nan_heap=True, note='batch48004')
