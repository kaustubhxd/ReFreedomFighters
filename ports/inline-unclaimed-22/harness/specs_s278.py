"""specs_s278.py - area 22, batch278 (src/batch278.cpp): CRigidBody deleting destructor and CExplodeMolotov::FrameUpdate.
Every callee is hooked by address (both sides reach the hooks): 0x53cfa0, 0x584f90, 0x581c10, 0x582e20 are GUESS
(unported); 0x4690b0 (audit/inline-ladder), 0x584c30 (unclaimed-27), 0x44b610 (unclaimed-62), 0x44b740
(inline-soundtimers) are verified and hooked to keep the world small. Objects are Python vtables; the assert hook at
0x7003b0 logs its call (absent in some delete cases with flag 4 so the free path runs without it)."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt, _hk


def _r(c):
    return c.rng.getrandbits(32)


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _slot(name, nargs, ret=0):
    def h(em, r):
        em.calllog.append((name, 0, None, tuple(em.arg32(i) for i in range(nargs))))
        em.ret(eax=ret, argbytes=4 * nargs)
    return h


def _g_53d050(c):
    e = c.emu
    _hk(c, 0x53cfa0, 'dtor', 0, eax=lambda em: _r(c))
    _hk(c, 0x4690b0, 'free', 2, eax=lambda em: _r(c), pop=0)
    e.w32(0x7003b0, e.stub_fn('assert', lambda em, r: (em.calllog.append(('assert', 0, None, ())), em.ret(eax=_r(c)))))
    flags = c.rng.choice([0, 1, 4, 5, 3, 7, 2, _r(c)])
    self_ = _rnd(c, 0x20)
    e.mu.ctl_flush_tb()
    return [self_, flags]


S(0x53d050, 'CRigidBody::`scalar deleting destructor', 'thiscall', 1, ret='u32', gen=_g_53d050,
  note='batch278; dtor body 0x53cfa0 GUESS hook, free 0x4690b0 hooked; SEH frame not reproduced')


def _g_583a10(c):
    e = c.emu
    for a, n in ((0x584f90, 'inair'), (0x581c10, 'collide'), (0x582e20, 'flames')):
        _hk(c, a, n, 0, eax=lambda em: _r(c))
    _hk(c, 0x584c30, 'prel', 1, eax=lambda em: _r(c))
    _hk(c, 0x44b610, 'sndstop', 0, eax=lambda em: _r(c))
    _hk(c, 0x44b740, 'sndfree', 1, eax=lambda em: _r(c), pop=0)
    rm = _rnd(c, 0x100)
    db = _rnd(c, 0x10)
    clock = c.rng.randrange(0, 1 << 22)
    e.w32(rm + 0x40, clock)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    gl = _rnd(c, 0x2c60)
    e.w32(gl + 0x2c51, _r(c))
    e.w32(0x7003b8, gl)
    oid = _r(c)
    obj = 0
    if c.rng.random() < 0.7:
        obj = _rnd(c, 0x10)
        e.w32(obj, _pyvt(c, {0x28: _slot('obj.28', 0)}))

    def db58(em, r):
        a = em.arg32(0)
        em.calllog.append(('db.58', 0, None, (a,)))
        em.ret(eax=obj if a == oid else 0, argbytes=4)
    e.w32(db, _pyvt(c, {0x58: db58}))
    self_ = _rnd(c, 0x380)
    e.w32(self_, _pyvt(c, {0x68: _slot('self.68', 2)}))
    e.w8(self_ + 0x8c, c.rng.choice([0, 0, 0, 0, 1, 0x40]))
    mode = c.rng.choice(['rnd'] * 5 + ['e48', 'e48m', 'e50', 'e50m', 'old'])
    st = c.rng.uniform(clock / 1024.0 - 8, clock / 1024.0 + 1)
    if mode == 'old':
        st = clock / 1024.0 - 6
    elif mode != 'rnd':
        # put the clock exactly at, or one tick past, a limit
        base = (st + (5.0 if mode in ('e50', 'e50m') else 5.0 - 0.2)) * 1024.0
        e.w32(rm + 0x40, (int(base) + (1 if mode.endswith('m') else 0)) & 0xffffffff)
        clock = e.r32(rm + 0x40)
    e.w32(self_ + 0x5c, _fb(st))
    for i in range(5):
        e.w32(self_ + 0x24a + i * 0x44, _r(c))
    e.w32(self_ + 0x362, oid if c.rng.random() < 0.8 else _r(c))
    tgt = _rnd(c, 0x10)
    e.w32(tgt, _pyvt(c, {0x28: _slot('tgt.28', 0)}))
    e.w32(self_ + 0x44, tgt)
    l = 0
    if c.rng.random() < 0.8:
        l = _rnd(c, 0x90)
        e.w32(l + 0x84, _fb(c.rng.uniform(-3, 3)))
        e.w32(l + 0x10, c.rng.choice([0, 1, _r(c)]))
    e.w32(self_ + 0x36e, l)
    e.mu.ctl_flush_tb()
    return [self_]


S(0x583a10, 'CExplodeMolotov::FrameUpdate', 'thiscall', None, ret=None, gen=_g_583a10, nan_heap=True,
  note='batch278; void; callees hooked by address (4 GUESS, 4 verified)')
