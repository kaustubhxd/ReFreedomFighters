"""specs_s709.py - soldier AI batch 709: PStateQueue insert (0x5a2460), SetGoalData, UseTargetManager, PopGoal,
GetStateAddrFromName / GetStateNameFromAddr. Queues hold 0..16 records with small goal/data/priority values so
duplicates, ties and every insert position occur; new/delete and the VM name lookup are hooked."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s705 import _bool, nostk


def _log_world(c):
    e = c.emu
    logobj = _rnd(c, 16)

    def printf(em, r):
        fmt = em.arg32(1)
        raw = em.rbytes(fmt, 200)
        nargs = raw[:raw.index(0)].count(b'%') if 0 in raw else 0   # only the real arguments (all %s here)
        em.calllog.append(('log.printf', 0x2c, None, tuple(em.arg32(k) for k in range(2 + nargs))))
        em.ret(eax=0, argbytes=0)
    e.w32(logobj, e.fake_vtable('log', 16, {0x2c: printf}))
    lg = _rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (logobj, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    if True:   # wider-24: hook always set (a null hook means int3 = a fault on both sides)
        e.w32(0x7003b0, e.stub_fn('assert', lambda em, r: (em.calllog.append(('assert', 0, None, ())), em.ret(eax=0))))
    else:
        e.w32(0x7003b0, 0)
    e.hook(0x4cc1d0, lambda em, r: em.ret(eax=em.r32(em.reg('ecx')) + 8))
    e.hook(0x4cbec0, lambda em, r: em.ret())


def _actor(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, e.reg('ecx'), tuple(nostk(a) for a in args)))
    names = {}

    def name_into(em, r):
        log('geom', 0x1d8, (em.arg32(1),))
        em.w32(em.arg32(0), em.reg('ecx'))
        em.ret(eax=em.arg32(0), argbytes=8)

    def sname(em, r):
        g = em.arg32(0)
        log('geom', 0x70c, (g,))
        if g not in names:
            names[g] = em.cstr('state_%x' % g)
        em.ret(eax=names[g], argbytes=4)
    a = _rnd(c, 0x960)
    e.w32(a, e.fake_vtable('geom', 0x1d0, {0x1d8: name_into, 0x70c: sname}))
    e.wbytes(a + 8, b'actor\0')
    return a


def _small(c):
    return c.rng.choice([0, 1, 2, 3, 5])


def _fill_queue(c, q, n=None):
    e = c.emu
    n = c.rng.choice([0, 1, 2, 5, 15, 16, c.rng.randint(0, 16)]) if n is None else n
    e.w32(q, n)
    prios = sorted(c.rng.choice([1, 2, 3, 10, 100]) for _ in range(16))
    for i in range(16):
        e.wbytes(q + 4 + 16 * i, struct.pack('<4I', prios[i], _small(c), _small(c), c.rng.getrandbits(32)))
    return n


def _ins(c):
    _log_world(c)
    q = _rnd(c, 4 + 16 * 17)
    _fill_queue(c, q)
    g = c.emu.alloc(16, 4)
    c.emu.wbytes(g, struct.pack('<4I', c.rng.choice([0, 1, 2, 3, 10, 100, 101]), _small(c), _small(c),
                                c.rng.getrandbits(32)))
    return [q, g]


S(0x5a2460, 'PStateQueue insert (map: ZFFActor::AddGoal)', 'thiscall', None, ret='al', gen=_ins,
  note='b709; map name doubtful (signature is (queue, PState*))')


def _sgd(c):
    a = _actor(c)
    _fill_queue(c, a + 0x7ce)
    c.emu.w32(a + 0x8d6, c.rng.choice([0, _small(c)]))
    c.emu.w32(a + 0x8da, _small(c))
    return [a, _small(c), _small(c)]


S(0x5a2cb0, 'ZFFActor::SetGoalData', 'thiscall', None, ret=None, gen=_sgd, note='b709 [medium]')


def _utm(c):
    e = c.emu
    _log_world(c)
    a = _actor(c)
    e.w32(a + 0x92a, c.rng.choice([0, _rnd(c, 4)]))

    def new(em, r):
        em.calllog.append(('new', 0, None, (em.arg32(0),)))
        em.ret(eax=_rnd(c, 4))

    def delete(em, r):
        em.calllog.append(('delete', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret()
    e.hook(0x41e290, new)
    e.hook(0x634273, delete)
    return [a, _bool(c)]


S(0x5a30e0, 'ZFFActor::UseTargetManager', 'thiscall', None, ret=None, gen=_utm, note='b709 [high]; new/delete hooked')


def _pop(c):
    _log_world(c)
    a = _actor(c)
    n = _fill_queue(c, a + 0x7ce)
    goal = _small(c)
    if n and c.rng.random() < 0.3:
        goal = c.emu.r32(a + 0x7ce + 4 + 16 * (n - 1) + 4)
    c.emu.w32(a + 0x8d6, c.rng.choice([0, 0, goal, _small(c)]))
    return [a, goal, c.rng.getrandbits(32)]


S(0x5a20d0, 'ZFFActor::PopGoal', 'thiscall', None, ret=None, gen=_pop, note='b709 [high]')


def _chain(c):
    """+0x10 -> +0x1c -> +4 -> +4 -> +0x96 with a random null link (20%)."""
    e = c.emu
    a = _rnd(c, 0x40)
    img = _rnd(c, 16)

    def s0(em, r):
        em.calllog.append(('img', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0x6aeb20 + 1, argbytes=4)
    e.w32(img, e.fake_vtable('img', 4, {0: s0}))
    p4 = _rnd(c, 0xa0)
    e.wbytes(p4 + 0x96, struct.pack('<I', img))
    p3 = _rnd(c, 8); e.w32(p3 + 4, p4)
    p2 = _rnd(c, 8); e.w32(p2 + 4, p3)
    p1 = _rnd(c, 0x20); e.w32(p1 + 0x1c, p2)
    e.w32(a + 0x10, p1)
    if c.rng.random() < 0.2:
        e.w32(c.rng.choice([a + 0x10, p1 + 0x1c, p2 + 4, p3 + 4]), 0)

    def vm(em, r):
        em.calllog.append(('vm', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0x1234, argbytes=4)
    e.hook(0x5ffe80, vm)
    return [a, c.rng.getrandbits(32)]


S(0x59ffd0, 'ZFFActor::GetStateAddrFromName', 'thiscall', None, ret='eax', gen=_chain, note='b709 [high]')
S(0x5a0010, 'ZFFActor::GetStateNameFromAddr', 'thiscall', None, ret='eax', gen=_chain, note='b709 [high]')
