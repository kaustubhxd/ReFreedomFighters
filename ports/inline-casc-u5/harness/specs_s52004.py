"""specs_s52004.py - tier H. 0x50eb20: hooked 0x5003d0 returns a different entry per call (kind byte 0, 2 or other, random key dword); engine table slot 0x58 returns an object (slot 0x84 writes 0-3 random floats through its pointer) or 0 (logger path); logger object at 0x700390 and assert hook set."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _fbits(r):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    else:
        v = r.uniform(-100, 100)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g50eb20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    ents = []
    for i in range(6):
        en = rnd(c, 0x20)
        e.wbytes(en + 4, bytes([r.choice([0, 2, 0, 2, 1, 3, 0x80, r.getrandbits(8)])]))
        ents.append(en)
    hook_rec(c, 0x5003d0, 1, ret=lambda em, k: ents[min(k, 5)], this=True)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 3, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    vals = [_fbits(r) for _ in range(3)]
    cnt = r.choice([0, 1, 2, 3, 3, 3])

    def w(em, k):
        v = em.arg32(0)
        for i in range(cnt):
            em.w32(v + 4 * i, vals[i])
    ob = obj(c, 0x20, {0x84: pystub(c, 1, this=True, side=w)}, nslots=0x90 // 4)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=(ob if r.random() < 0.7 else 0), this=True)})
    for a in (0x701468, 0x70146c, 0x701470):
        e.w32(a, r.getrandbits(32))
    me = rnd(c, 0x20)
    e.w32(me + 4, rnd(c, 0x20))
    e.w32(me + 8, rnd(c, 0x20))
    return [me]


S(0x50eb20, 'GUESS copy vector into three entries', 'stdcall', None, ret=None, gen=_g50eb20, note='batch52004')
