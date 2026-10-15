"""specs_s820.py - animation layer thread, batch 820: ZAnimDefsList (GetAnim, GetAnim(float), GetFramePrc, UpdateEnd)."""
from pilot import S, F
from anim_common import only_hooks, rnd, vt_object, vslot, install_fmod


def _engine(c, clock):
    e, r = c.emu, c.rng
    g = rnd(c, 0x80)
    e.w32(g + 0x40, clock & 0xffffffff)
    e.wf32(g + 0x48, r.choice([1.0, 0.5, c.fv(0.1, 2)]))
    fired = [0]

    def assert_(e, res):
        e.calllog.append(('assert', e.arg32(0), e.arg32(1)))
        e.ret(st0=r.choice([0.25, 1.0, 0.0]), argbytes=8)
    vt = e.fake_vtable('engine', 0x72, {0x1c0: assert_})
    e.w32(g, vt)
    e.w32(0x70039c, g)
    return g


class Nodes:
    def __init__(self, c, items):
        self.c, self.items, self.pos = c, items, 0
        self.obj = c.emu.fake_object('nodelist', 0x20, nslots=0x2a, slots={
            0x14: self.count, 0x4c: self.begin, 0x64: self.next})

    def count(self, e, r):
        e.calllog.append(('list.count', len(self.items)))
        e.ret(eax=len(self.items), argbytes=0)

    def begin(self, e, r):
        self.pos = 0
        e.ret(eax=0, argbytes=4)

    def next(self, e, r):
        n = self.items[self.pos][0] if self.pos < len(self.items) else 0
        self.pos += 1
        e.ret(eax=n, argbytes=4)


def _nodes(c, n):
    r, e = c.rng, c.emu
    items = []
    for i in range(n):
        node = rnd(c, 0x10)
        e.w32(node, r.getrandbits(32) | 0x100)
        e.w32(node + 4, r.choice([0, 1, 2, 3, r.randint(0, 8)]))
        e.wf32(node + 8, r.choice([0.0, 0.3, 1.0, c.fv(0, 2)]))
        items.append((node,))
    return items


def _setup(c, slots=None):
    only_hooks(c, {})
    e, r = c.emu, c.rng
    clock = r.randint(0, 1 << 20)
    _engine(c, clock)
    items = _nodes(c, r.randint(0, 5))
    nl = Nodes(c, items)
    o = vt_object(c, 0x20, slots or {}, name='defs') if slots else rnd(c, 0x20)
    e.w32(o + 4, 0 if r.random() < 0.3 else (r.getrandbits(32) | 1))
    e.wf32(o + 0xc, r.choice([clock / 1024.0, clock / 1024.0 + 0.5, c.fv(0, 100)]))
    e.wf32(o + 0x10, r.choice([(clock + r.randint(-2000, 4000)) / 1024.0, c.fv(0, 100)]))
    e.w32(o + 0x14, nl.obj)
    return o, clock, items


def _getanim(c):
    o, clock, items = _setup(c)
    c.emu.w32(c.emu.r32(0x70039c) + 0x40, clock)
    return [o, c.rng.choice([0, 1, 2, 3, 4, c.rng.randint(0, 8)])]


def _getrand(c):
    r = c.rng
    o, clock, items = _setup(c, {0xc: vslot('defs.sel', 1, st0=r.choice([0.0, 0.2, 1.5, c.fv(0, 3)]))})
    return [o, F(c.fv(0, 2))]


def _framep(c):
    o, clock, items = _setup(c)
    install_fmod(c)
    e, r = c.emu, c.rng
    clip = rnd(c, 0x80)
    e.w32(clip + 0x6c, r.randint(0, 120))
    s = r.randint(0, 60)
    e.w32(clip + 0x60, s)
    e.w32(clip + 0x64, s + r.choice([0, 1, r.randint(1, 200)]))
    ref = rnd(c, 0x10)
    e.w32(ref, clip)
    e.w32(o + 4, 0 if r.random() < 0.2 else ref)
    return [o, F(c.fv(-2, 4))]


def _updend(c):
    o, clock, items = _setup(c)
    return [o]


S(0x4837e0, 'ZAnimDefsList::GetAnim(type)', 'thiscall', None, ret='eax', gen=_getanim, note='batch820')
S(0x483860, 'ZAnimDefsListRandom::GetAnim(float)', 'thiscall', None, ret='eax', gen=_getrand, note='batch820')
S(0x483aa0, 'ZAnimDefsList::GetFramePrc', 'thiscall', None, ret='st0', gen=_framep, note='batch820')
S(0x4850c0, 'ZAnimDefsList::UpdateEnd', 'thiscall', None, gen=_updend, note='batch820')
