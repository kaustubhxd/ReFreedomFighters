"""specs_s264.py - area 22, batch264 (src/batch264.cpp): ZFFSimpleTrain2::Stop and ZFFItemBomb::ZFFItemBomb. Engine db
slots 0x114 (RegisterZMsg, four words, returns a per-call value) and 0x58 (id to geom) are logged; geoms log SendCommand
slot 0x128 with three words. The wagon list is a Python start/next pair. The base constructor 0x469870 runs as exe code
(it reads/updates the float at db +0xae0 and calls db vt[0x30])."""
import struct
from pilot import S
from helpers22 import _rnd, _multi_vt, _pyvt


def _r(c):
    return c.rng.getrandbits(32)


def _z(em, a):
    return (0, None)


def _db(c, extra=None):
    e = c.emu
    gm = {}
    db = _rnd(c, 0xb00)
    sl = {0x114: (lambda em, a: (_r(c), None), 4), 0x58: (lambda em, a: (gm.get(a[0], 0), None), 1),
          0x30: (_z, 1)}
    e.w32(db, _multi_vt(c, sl))
    e.w32(db + 0xae0, struct.unpack('<I', struct.pack('<f', c.rng.uniform(0.0, 1.2)))[0])
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    return gm


def _geom(c):
    g = _rnd(c, 0x10)
    c.emu.w32(g, _multi_vt(c, {0x128: (_z, 3)}))
    return g


def _g_5b9250(c):
    e = c.emu
    gm = _db(c)
    self_ = _rnd(c, 0x100)
    e.w32(self_ + 0xe2, c.rng.choice([_geom(c), 0]))
    ids = [_r(c) for _ in range(c.rng.choice([0, 1, 2, 4]))]
    for i in ids:
        gm[i] = _geom(c)
    eng = _r(c)
    gm[eng] = _geom(c)
    e.w32(self_ + 0x48, eng)
    st = {'k': 0}

    def start(em, r):
        em.calllog.append(('list.4c', 0x4c, None, ()))
        st['k'] = 0
        em.w32(em.arg32(0), 0x66000000)
        em.ret(eax=0x2468ace0, argbytes=4)

    def nxt(em, r):
        k = st['k']
        em.calllog.append(('list.5c', 0x5c, None, (em.r32(em.arg32(0)),)))
        if k < len(ids):
            em.w32(em.arg32(0), 0x66000001 + k)
            v = ids[k]
        else:
            em.w32(em.arg32(0), 0)
            v = 0x7777aaaa
        st['k'] = k + 1
        em.ret(eax=v, argbytes=4)
    lst = 0
    if c.rng.random() < 0.8:
        lst = _rnd(c, 0x10)
        e.w32(lst, _pyvt(c, {0x4c: start, 0x5c: nxt}))
    e.w32(self_ + 0x4c, lst)
    e.mu.ctl_flush_tb()
    return [self_]


def _g_5d4090(c):
    _db(c)
    c.emu.mu.ctl_flush_tb()
    return [_rnd(c, 0x80)]


S(0x5b9250, 'ZFFSimpleTrain2::Stop', 'thiscall', None, ret=None, gen=_g_5b9250, note='batch264; void')
S(0x5d4090, 'ZFFItemBomb::ZFFItemBomb', 'thiscall', None, ret='eax', gen=_g_5d4090,
  note='batch264; base ctor 0x469870 as exe code; SEH frame and cookie not reproduced')
