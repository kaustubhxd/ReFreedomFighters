"""specs_s280.py - area 22, batch280 (src/batch280.cpp): CRigidBody::SetVelocity. GetParticlePos 0x545c80 (GUESS) writes
per-case floats; SetParticleOldPos 0x547730 (verified in unclaimed-62) and ZEventBase::Activate 0x634e90 (GUESS) are
hooked by address and log their arguments (the position by its three float words, not its stack address). The vector
helpers 0x43e960, 0x459fc0, 0x4419f0, 0x441940 and 0x43e920 (inline-batch45, inline-collision) run as exe code."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt


def _r(c):
    return c.rng.getrandbits(32)


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g_5409d0(c):
    e = c.emu
    pos = {i: [_fb(c.rng.uniform(-500, 500)) for _ in range(3)] for i in range(1, 5)}

    def get(em, r):
        i = em.arg32(0)
        em.calllog.append(('getpos', 0x545c80, em.reg('ecx'), (i,)))
        o = em.arg32(1)
        for k, w in enumerate(pos.get(i, [_r(c)] * 3)):
            em.w32(o + 4 * k, w)
        em.ret(eax=_r(c), argbytes=8)

    def setp(em, r):
        p = em.arg32(1)
        em.calllog.append(('setold', 0x547730, em.reg('ecx'), (em.arg32(0), em.r32(p), em.r32(p + 4), em.r32(p + 8))))
        em.ret(eax=_r(c), argbytes=8)

    def act(em, r):
        em.calllog.append(('activate', 0x634e90, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=_r(c), argbytes=4)
    e.hook(0x545c80, get)
    e.hook(0x547730, setp)
    e.hook(0x634e90, act)
    self_ = _rnd(c, 0x150)
    e.w32(self_ + 0xcf, _rnd(c, 0x20))
    for k in range(3):
        e.w32(self_ + 0x111 + 4 * k, _fb(c.rng.uniform(-500, 500)))
    e.w32(self_ + 0x141, _r(c))
    e.w32(self_ + 0x13d, _r(c))
    e.w8(self_ + 0x10f, c.rng.choice([0, 2]))
    t = _rnd(c, 0x70)
    for k in range(0x18):
        e.w32(t + 4 * k, _fb(c.rng.uniform(-2, 2) if k < 0x12 else c.rng.uniform(-300, 300)))
    return [self_, t]


S(0x5409d0, 'CRigidBody::SetVelocity', 'thiscall', 1, ret=None, gen=_g_5409d0, nan_heap=True,
  note='batch280; void; particle get/set and event activate hooked; vector helpers as exe code; cookie not reproduced')


def _g_4c4c90(c):
    e = c.emu
    src = _rnd(c, 0x80)
    dst = _rnd(c, 0x80)
    for k in range(0x48, 0x70, 4):
        e.w32(src + k, _r(c))
        e.w32(dst + k, _r(c))
    for off in (0x4c, 0x50, 0x54, 0x6a):
        n = c.rng.choice([0, 1, 2, 3, 5])
        items = [_r(c) for _ in range(n)]
        st = {'i': 0}

        def start(em, r, st=st, off=off):
            st['i'] = 0
            em.calllog.append(('src%x.4c' % off, 0, None, ()))
            em.w32(em.arg32(0), 0x11 if items else 0)
            em.ret(eax=_r(c), argbytes=4)

        def nxt(em, r, st=st, off=off, items=items):
            p = em.arg32(0)
            i = st['i']
            st['i'] += 1
            em.calllog.append(('src%x.5c' % off, 0, None, (i,)))
            if i < len(items):
                em.w32(p, c.rng.choice([1, 2, 0x80000000, _r(c) | 1]))
                em.ret(eax=items[i], argbytes=4)
            else:
                em.w32(p, 0)
                em.ret(eax=_r(c), argbytes=4)
        sl = 0
        if c.rng.random() < 0.85:
            sl = _rnd(c, 0x10)
            e.w32(sl, _pyvt(c, {0x4c: start, 0x5c: nxt}))
        e.w32(src + off, sl)
        dl = _rnd(c, 0x10)

        def add(em, r, off=off):
            em.calllog.append(('dst%x.4' % off, 0, None, (em.arg32(0),)))
            em.ret(eax=_r(c), argbytes=4)
        e.w32(dl, _pyvt(c, {4: add}))
        e.w32(dst + off, dl)
    return [dst, src]


S(0x4c4c90, 'ZAnimSequence::CopyData', 'thiscall', 1, ret=None, gen=_g_4c4c90,
  note='batch280; void; lists are Python vtables (iterator words mixed so the it != 0 test is exercised)')
