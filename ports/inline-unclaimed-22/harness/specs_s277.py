"""specs_s277.py - area 22, batch277 (src/batch277.cpp): ZParamAnim::FrameUpdate. No direct callees. The curve object
embedded at +0x59 is a Python vtable: vt 0x0c logs t and returns a per-case float in st0, vt 0x10 logs the channel id,
writes a per-case float into the output and returns a per-case bool. The target's slots log their arguments."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt


def _r(c):
    return c.rng.getrandbits(32)


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _slot(name, nargs, ret=0):
    def h(em, r):
        em.calllog.append((name, 0, None, tuple(em.arg32(i) for i in range(nargs))))
        em.ret(eax=ret, argbytes=4 * nargs)
    return h


def _g_4a27d0(c):
    e = c.emu
    rm = _rnd(c, 0x80)
    clock = c.rng.choice([c.rng.randrange(0, 1 << 20), c.rng.randrange(0, 1 << 31), _r(c)])
    e.w32(rm + 0x40, clock)
    e.w32(0x70039c, rm)
    self_ = _rnd(c, 0x80)
    mode = c.rng.choice(['rnd'] * 6 + ['edge', 'edge1', 'zero'])
    start = c.rng.choice([0, 0, clock - c.rng.randrange(0, 20000), _r(c)]) & 0xffffffff
    delay = c.rng.choice([0.0, 0.0, c.rng.uniform(-3, 3), 1.5])
    length = c.rng.choice([0.0, -1.0, c.rng.uniform(0, 20), 2.0, 5.0])
    v = c.rng.choice([0.5, -0.5, 0.0, -0.0, c.rng.uniform(-1, 2), float('nan')])
    if mode in ('edge', 'edge1'):
        start = (clock - 1000) & 0xffffffff
        delay = 0.0
        length = c.rng.choice([1000 / 1024.0, 999 / 1024.0, 1001 / 1024.0])
        v = 1.0
        if mode == 'edge1':
            length = 1.0
            start = (clock - 1024 - c.rng.choice([0, 1])) & 0xffffffff
    elif mode == 'zero':
        start = 0
        delay = 0.0
        length = 0.0
    e.w32(self_ + 0x4d, start)
    e.w32(self_ + 0x51, _fb(delay))
    e.w32(self_ + 0x55, _fb(length))
    e.w8(self_ + 0x48, c.rng.choice([0, 0, 1, 0x80]))
    has = {0x100001: c.rng.choice([0, 1, 1, 0x100]), 0x100002: c.rng.choice([0, 1, 1, 0x7f00])}
    vals = {k: _fb(c.rng.uniform(-7, 7)) for k in has}

    def c0c(em, r):
        em.calllog.append(('curve.0c', 0, None, (em.arg32(0),)))
        em.ret(st0=v, argbytes=4)

    def c10(em, r):
        k = em.arg32(0)
        em.calllog.append(('curve.10', 0, None, (k,)))
        if k in vals:
            em.w32(em.arg32(1), vals[k])
        em.ret(eax=(_r(c) & 0xffffff00) | (has.get(k, 0) & 0xff), argbytes=8)
    e.w32(self_ + 0x59, _pyvt(c, {0x0c: c0c, 0x10: c10}))
    tgt = 0
    if not (v < 0 and e.r8(self_ + 0x48) and c.rng.random() < 0.3):
        tgt = _rnd(c, 0x10)
        e.w32(tgt, _pyvt(c, {0x28: _slot('tgt.28', 0), 0x210: _slot('tgt.210', 1),
                             0x224: _slot('tgt.224', 1), 0x230: _slot('tgt.230', 1)}))
    e.w32(self_ + 0x44, tgt)
    e.mu.ctl_flush_tb()
    return [self_]


S(0x4a27d0, 'ZParamAnim::FrameUpdate', 'thiscall', None, ret=None, gen=_g_4a27d0, nan_heap=True,
  note='batch277; void; curve and target are Python vtables')
