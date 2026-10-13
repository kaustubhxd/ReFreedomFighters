"""specs_s281.py - area 22, batch281 (src/batch281.cpp): ZActionControlMap::FrameUpdate. Every direct callee is hooked by
address (both sides reach the hooks); GUESS: 0x591ae0, 0x5f0450, 0x53c590, 0x5b4b40, 0x5b4160, 0x5b2e90; verified
elsewhere and hooked to keep the world small: 0x589c20, 0x41e290, 0x5f0340, 0x5b3780, 0x5b2d00. Constructors return
their ecx; the allocator returns a fresh block or 0. Objects are Python vtables."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt, _hk


def _r(c):
    return c.rng.getrandbits(32)


def _slot(name, nargs, ret=0):
    def h(em, r):
        em.calllog.append((name, 0, None, tuple(em.arg32(i) for i in range(nargs))))
        em.ret(eax=ret() if callable(ret) else ret, argbytes=4 * nargs)
    return h


def _g_5b3350(c):
    e = c.emu
    osd = c.rng.choice([0, _r(c) | 1, _r(c) | 1])
    _hk(c, 0x591ae0, 'camptr', 0, eax=lambda em: _r(c))
    _hk(c, 0x589c20, 'osd', 1, eax=osd)
    blocks = []

    def alloc(em, r):
        n = em.arg32(0)
        em.calllog.append(('new', 0, None, (n,)))
        b = 0 if c.rng.random() < 0.1 else e.alloc(n, 4)
        blocks.append(b)
        em.ret(eax=b, argbytes=0)
    e.hook(0x41e290, alloc)
    for a, n in ((0x5f0340, 'ctor10'), (0x5f0450, 'ctor14')):
        _hk(c, a, n, 1, eax=lambda em: em.reg('ecx'))
    _hk(c, 0x53c590, 'init', 2, eax=lambda em: _r(c))
    for a in (0x5b4b40, 0x5b4160, 0x5b3780, 0x5b2e90, 0x5b2d00):
        _hk(c, a, 'step%x' % a, 0, eax=lambda em: _r(c))
    dev = _rnd(c, 0x10)
    e.w32(dev, _pyvt(c, {0xb8: _slot('dev.b8', 0, lambda: _r(c)), 0xc0: _slot('dev.c0', 0, lambda: _r(c))}))
    rm = _rnd(c, 0x80)
    e.w32(rm, _pyvt(c, {0xbc: _slot('rm.bc', 0, dev)}))
    e.w8(rm + 0x6c, c.rng.choice([0, 0, 1, 0x80]))
    e.w32(0x70039c, rm)
    e.w32(0x7003b8, _rnd(c, 0x10))
    helper = _rnd(c, 0xe20)
    hero = _rnd(c, 0x870)
    e.w32(hero, _pyvt(c, {0x100: _slot('hero.100', 1, helper)}))
    e.w32(hero + 0x85a, c.rng.choice([0, 0, helper]))
    e.w32(hero + 0x684, c.rng.choice([0, 1, 2, 0x101, _r(c)]))
    self_ = _rnd(c, 0x260)
    e.w32(self_ + 0x5f, hero)
    e.w32(self_ + 0x57, _r(c))
    mode = c.rng.choice([0, 1, 2, 3, 4, 4, 3, 5, _r(c)])
    e.w32(self_ + 0x250, mode)
    for off, n in ((0x254, 'mc254'), (0x258, 'mc258')):
        mc = 0
        if c.rng.random() < 0.6 or mode in (3, 4):
            mc = _rnd(c, 0x10)
            e.w32(mc, _pyvt(c, {0: _slot(n + '.0', 0)}))
        e.w32(self_ + off, mc)
    # modes 3 and 4 call a control without a null check, so those cases always have both controls (the first-use
    # path, which can leave a null from the allocator, is exercised by the other modes)
    for k in (0x51, 0x5b, 0x63):
        e.w32(self_ + k, _r(c))
    e.w16(self_ + 0x55, _r(c) & 0xffff)
    for k in (0xe0f, 0xe13):
        e.w32(helper + k, _r(c))
    return [self_]


S(0x5b3350, 'ZActionControlMap::FrameUpdate', 'thiscall', None, ret=None, gen=_g_5b3350,
  note='batch281; void; all direct callees hooked by address; SEH frame not reproduced')
