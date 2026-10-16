"""specs_s1805.py - fresh-18 batch 5 (src/batch1805.cpp). 0x7003b0 is always a logging stub."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
import h18 as h

R = lambda c: c.rng.getrandbits(32)


def logger(c, nargs):
    lg = h.obj(c, {0x2c: h.L(c, 'log2c', nargs, regs=(), pops=0)})
    c.emu.w32(0x700390, h.obj(c, {0x20: h.L(c, 'log20', 2, ret=lg)}))


def ealloc(c):
    """engine(+0x9b)+8 allocator; returns the new object or 0."""
    o = h.rnd(c, 0x200)
    blk8 = h.obj(c, {0x44: h.L(c, 'alloc', 1, ret=c.rng.choice([0, o, o]))})
    e9b = h.rnd(c, 0x20)
    c.emu.w32(e9b + 8, blk8)
    h.engine(c, 0x9b, e9b)


def factory(base):
    def g(c):
        ealloc(c)
        h.hk(c, base, 'ctor%x' % base, 0)
        return [R(c)]
    return g

for a, base, nm in ((0x4baee0, 0x469870, 'GUESS geom factory'), (0x4be860, 0x469870, 'GUESS geom factory'),
                    (0x4cab60, 0x469870, 'GUESS geom factory'), (0x5bc5a0, 0x469870, 'GUESS geom factory'),
                    (0x5d55a0, 0x469870, 'GUESS geom factory'), (0x548e20, 0x548ca0, 'GUESS factory'),
                    (0x5be120, 0x5bde30, 'GUESS factory (CCivilianPathList)'), (0x5693a0, 0x561020, 'GUESS window factory')):
    S(a, nm, 'thiscall', None, ret='eax', gen=factory(base))

FL = lambda c: c.rng.choice([0, 1, 1, R(c)])


def g608220(c):
    h.hk(c, 0x634273, 'delete', 2, pops=0, regs=())
    s = h.rnd(c, 0x20)
    c.emu.w32(s + 0x14, h.obj(c, {8: h.L(c, 'Release', 1, regs=())}))
    return [s, FL(c)]
S(0x608220, 'GUESS deleting dtor (COM release)', 'thiscall', None, ret='eax', gen=g608220)


def g616aa0(c):
    h.hk(c, 0x634273, 'delete', 2, pops=0, regs=())
    h.hk(c, 0x659c00, 'f659c00', 0)
    h.hk(c, 0x659bb0, 'f659bb0', 0)
    return [h.rnd(c, 0x40), FL(c)]
S(0x616aa0, 'ZRObjectBonesVSGC deleting dtor', 'thiscall', None, ret='eax', gen=g616aa0)


def g616be0(c):
    h.hk(c, 0x634273, 'delete', 2, pops=0, regs=())
    h.hk(c, 0x659c00, 'f659c00', 0)
    sh = h.rnd(c, 0x40)
    c.emu.w32(sh + 0x30, c.rng.choice([1, 1, 2, 7, 0]))
    s = h.rnd(c, 0x10)
    c.emu.w32(s + 4, sh)
    return [s, FL(c)]
S(0x616be0, 'GUESS deleting dtor (shared block ref)', 'thiscall', None, ret='eax', gen=g616be0)


S(0x54a0e0, 'GUESS record field copy', 'thiscall', None, gen=lambda c: [R(c), h.rnd(c, 0x70), h.rnd(c, 0x70)])


def g4fa720(c):
    h.engine(c, 0x9b, h.obj(c, {0x4c: h.L(c, 'e4c', 1, ret=R(c))}))
    return [h.rnd(c, 0x90), R(c), c.rng.choice([0, 1, 2, 3, 4, 5, 6, R(c)])]
S(0x4fa720, 'ZCONTROL::SetNextFocus', 'thiscall', None, gen=g4fa720)


def g4a7f20(c):
    c.emu.w32(0x7003b0, h.L(c, 'assert', 0, regs=()))
    h.hk(c, 0x4a7fb0, 'ReadInput', 1)
    lg = h.obj(c, {0x58: h.L(c, 'l58', 1), 0x68: h.L(c, 'l68', 1)})
    return [h.rnd(c, 0x90), lg]
S(0x4a7f20, 'ZGeomSpawn::Load', 'thiscall', None, ret='al', gen=g4a7f20)


def g4c48a0(c):
    r = h.obj(c, {0x3c: h.L(c, 'r3c', 1, ret=R(c))})
    sg = h.obj(c, {0x3c: h.L(c, 's3c', 1, ret=r), 0x54: h.L(c, 's54', 1), 0x4c: h.L(c, 's4c', 1),
                   0x68: h.L(c, 's68', 1)})
    return [h.rnd(c, 0xb0), sg]
S(0x4c48a0, 'ZParticleEmitter::Save', 'thiscall', None, ret='al', gen=g4c48a0)


def evfactory(c, extra=None):
    prm = h.rnd(c, 0x20)
    ev = h.obj(c, {0x4c: h.L(c, 'ev4c', 0, ret=prm)})
    slots = {0x18: h.L(c, 'f18', 1, ret=c.rng.choice([0, ev, ev, ev]))}
    if extra:
        slots.update(extra)
    return h.obj(c, slots), prm


def g5517a0(c):
    f, prm = evfactory(c)
    h.hk(c, 0x5003d0, 'param', 1, ret=lambda e, rv, a: R(c))
    h.hk(c, 0x5002f0, 'setint', 1)
    h.hk(c, 0x500360, 'setfloat', 1)
    args = h.rnd(c, 0x10)
    return [R(c), f, R(c), args]
S(0x5517a0, 'Signature_ifff_EventTranslator_t::handleEventTranslation', 'thiscall', None, ret='eax', gen=g5517a0)


def strobj(c):
    return h.obj(c, {0x30: h.L(c, 's30', 1), 0x24: h.L(c, 's24', 0, ret=R(c)), 0x28: h.L(c, 's28', 0)})


def pslot(c):
    slot = h.rnd(c, 0x10)
    c.emu.w8(slot + 4, c.rng.choice([0, 4, 4, c.rng.randint(1, 255)]))
    c.emu.w32(slot, h.obj(c, {0x28: h.L(c, 'old28', 0)}))
    h.hk(c, 0x5003d0, 'param', 1, ret=slot)


def g500760(c):
    s = strobj(c)
    f, prm = evfactory(c, {0: h.L(c, 'f0', 2, ret=s)})
    pslot(c)
    return [R(c), f, R(c), R(c)]
S(0x500760, 'StringEventTranslator_t::handleEventTranslation', 'thiscall', None, ret='eax', gen=g500760)


def g553fa0(c):
    s = strobj(c)
    f = h.obj(c, {0: h.L(c, 'f0', 2, ret=s)})
    pslot(c)
    ld = h.rnd(c, 0x2c40)
    c.emu.w32(ld + 0x2c15, c.rng.choice([0, R(c), R(c)]))
    c.emu.w32(0x7003b8, ld)
    prm = h.rnd(c, 0x10)
    c.emu.w32(prm + 0xc, f)
    c.emu.w32(prm + 8, R(c))
    return [R(c), prm]
S(0x553fa0, 'CFFTools_if::GetLevelName', 'thiscall', None, gen=g553fa0)


def iterobj(c, extra=None):
    cnt = c.rng.randint(0, 5)
    def start(e, rv, a):
        e.w32(a[0], cnt); e.w32(a[0] + 4, 0x1234); e.w32(a[0] + 8, R(c))
    def step(e, rv, a):
        e.w32(a[0], max(e.r32(a[0]) - 1, 0))
    slots = {0x4c: h.L(c, 'start', 1, wr=start), 0x5c: h.L(c, 'step', 1, wr=step, ret=lambda e, rv, a: R(c))}
    if extra:
        slots.update(extra)
    return h.obj(c, slots)


def g4b5620(c):
    h.engine(c, 0x9b, h.obj(c, {0x58: h.L(c, 'e58', 1, ret=R(c))}))
    t = h.rnd(c, 0x20)
    c.emu.w32(t + 0x18, c.rng.choice([0, iterobj(c), iterobj(c)]))
    s = h.rnd(c, 0x50)
    c.emu.w32(s + 0x44, t)
    return [s, c.rng.choice([0, 1, 2, 3, 6, R(c)])]
S(0x4b5620, 'GUESS table entry handle', 'thiscall', None, ret='eax', gen=g4b5620, stack_arg_bytes=12)


def g45bda0(c):
    o = h.obj(c, {0x44: h.L(c, 'o44', 2)})
    wm = h.obj(c, {0x20: h.L(c, 'wm20', 0, ret=o)})
    blk = h.rnd(c, 0x1920)
    c.emu.w32(blk + 0x190f, wm)
    c.emu.w32(0x70039c, blk)
    i = c.rng.randint(0, 7)
    s = h.rnd(c, 0x280)
    c.emu.wf32(s + 0x258 + 4 * i, c.rng.choice([0.0, 60.0, 61.0, 100.0, 140.0, 300.0, c.fv(0, 200)]))
    c.emu.w32(s + 0x40, h.rnd(c, 0x20))
    return [s, i, F(c.rng.choice([0.0, 0.5, 1.0, 2.0, c.fv(-2, 2)]))]
S(0x45bda0, 'ZBloodSplatters::FadeMark', 'thiscall', None, gen=g45bda0)


def g5496e0(c):
    b = h.rnd(c, 0x10)
    c.emu.w32(b + 0xc, c.rng.choice([0, 1, 100, 0x7fffffff, 0x80000000, R(c), c.rng.randint(0, 5000)]))
    s = h.rnd(c, 0x70)
    c.emu.w32(s + 0x5d, b)
    d = c.rng.choice([0, 1, -1, 1200, -1200, -1199, c.rng.randint(-5000, 5000), R(c)]) & 0xffffffff
    return [s, d]
S(0x5496e0, 'GUESS count scale by d/1200', 'thiscall', None, ret='eax', gen=g5496e0)


def g64a120(c):
    h.engine(c, 0x3c, R(c))
    blk = h.rnd(c, 0x8300)
    q = blk + 0x268
    c.emu.w32(q, q + 8 + 4 * c.rng.choice([0, 1, 0x1fff, 0x1ffe, c.rng.randint(0, 0x1fff)]))
    s = h.rnd(c, 0x10061)
    c.emu.w32(s + 0x1005d, blk)
    m = h.rnd(c, 0x10)
    c.emu.w8(m + 8, c.rng.choice([1, 1, 2, 0, c.rng.randint(0, 255)]))
    ent = h.rnd(c, 0x20)
    c.emu.w32(ent + 0xc, m)
    h.hk(c, 0x63f600, 'PrimInstanceLeave', 1)
    return [s, ent]
S(0x64a120, 'GUESS prim instance entry release', 'thiscall', None, gen=g64a120)


def g496fe0(c):
    m = h.obj(c, {0xd4: h.L(c, 'md4', 1), 0x30: h.L(c, 'm30', 3), 0x50: h.L(c, 'm50', 3)})
    c.emu.w32(0x70038c, m)
    h.hk(c, 0x4ce1c0, 'f4ce1c0', 2)
    sz = c.rng.choice([0x34, 0x38, 0x40, 0x41, 0x5c, 0x80])
    ev = h.rnd(c, 0x90)
    c.emu.w32(ev + 0x2c, sz)
    c.emu.w32(ev + sz - 4, c.rng.choice([0, R(c)]))
    s = h.rnd(c, 0x50)
    c.emu.w32(s + 0x30, c.rng.choice([ev - c.rng.randint(0, 0x1000), R(c)]))
    return [s, ev]
S(0x496fe0, 'ZGeomBuffer::FreeEventRam', 'thiscall', None, gen=g496fe0)


def g4ceda0(c):
    logger(c, 3)
    c.emu.w32(0x676414, h.L(c, '_stricmp', 2, regs=(), pops=0, ret=lambda e, rv, a: c.rng.choice([0, 1, 1, 1, -1 & 0xffffffff])))
    s = iterobj(c, {0x44: h.L(c, 'remove', 1)})
    return [c.rng.choice([s, s, s, 0]), R(c)]
S(0x4ceda0, 'STRREFTAB::RemoveStr', 'thiscall', None, gen=g4ceda0, stack_arg_bytes=12)


def g4fbb20(c):
    nb = h.rnd(c, 0x20)
    h.hk(c, 0x41e290, 'new', 1, pops=0, regs=(), ret=c.rng.choice([0, nb, nb, nb]))
    h.hk(c, 0x4fdb70, 'f4fdb70', 0)
    t = h.rnd(c, 0x20)
    c.emu.w32(t + 0x18, h.obj(c, {4: h.L(c, 't4', 1)}))
    s = h.rnd(c, 0x60)
    c.emu.w32(s + 0x44, t)
    c.emu.w32(s + 0x4c, c.rng.choice([0, h.rnd(c, 0x20)]))
    kv = h.rnd(c, 8)
    if c.rng.random() < 0.3:
        c.emu.w32(kv + 4, c.emu.r32(nb + 4))
    return [s, kv]
S(0x4fbb20, 'GUESS list append node', 'thiscall', None, ret='eax', gen=g4fbb20)


def g5fd0a0(c):
    node = h.rnd(c, 0x20)
    h.hk(c, 0x6014a0, 'alloc', 1, ret=node)
    h.hk(c, 0x5f10c0, 'f5f10c0', 1)
    head = h.rnd(c, 0x10)
    prev = h.rnd(c, 0x10)
    c.emu.w32(head + 4, c.rng.choice([prev, head]))
    p = h.rnd(c, 8)
    c.emu.w32(p, head)
    s = h.rnd(c, 8)
    c.emu.w32(s, p)
    return [s, R(c)]
S(0x5fd0a0, 'GUESS list push_back', 'thiscall', None, gen=g5fd0a0)


def g42ba60(c):
    h.hk(c, 0x54f870, 'f54f870', 2)
    s = h.rnd(c, 0x20)
    for o in (0, 0xc):
        b = c.rng.choice([0, R(c)])
        c.emu.w32(s + o, b)
        c.emu.w32(s + o + 8, (b + c.rng.choice([0, 0, 4, 0x40])) & 0xffffffff)
    return [s]
S(0x42ba60, 'GUESS destructor body (two arrays)', 'thiscall', None, gen=g42ba60)
