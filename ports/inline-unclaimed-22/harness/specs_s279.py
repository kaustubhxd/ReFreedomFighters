"""specs_s279.py - area 22, batch279 (src/batch279.cpp): ZMovementGuide::GetActiveAnim and ZMovementStand::GetAnims.
The base GetActiveAnim 0x4884b0 (verified in inline-unclaimed-65) is hooked by address and returns a per-case float in
st0; PSVECSubtract 0x43e920 (inline-batch45) runs as exe code; fmod goes through the exe thunk 0x634dc4 to an fprem
stub (helpers22._install_fmod, exact). Objects are Python vtables; name lookups log the name text."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt, _install_fmod


def _r(c):
    return c.rng.getrandbits(32)


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _slot(name, nargs, ret=0):
    def h(em, r):
        em.calllog.append((name, 0, None, tuple(em.arg32(i) for i in range(nargs))))
        em.ret(eax=ret, argbytes=4 * nargs)
    return h


def _g_488650(c):
    e = c.emu
    _install_fmod(c)
    bv = c.rng.uniform(-1, 2)

    def base(em, r):
        em.calllog.append(('base', 0x4884b0, em.reg('ecx'), tuple(em.arg32(i) for i in range(5))))
        em.ret(st0=bv, argbytes=0x14)
    e.hook(0x4884b0, base)
    act = _rnd(c, 0x450)
    e.w32(act, _pyvt(c, {0x3f8: _slot('act.3f8', 1)}))
    e.w32(act + 0x14b, c.rng.choice([0, _r(c)]))
    e.w32(act + 0x147, _r(c))
    lift = c.rng.choice([0.0, 50.0, c.rng.uniform(-100, 100)])
    e.w32(act + 0x43d, _fb(lift))
    self_ = _rnd(c, 0x3b0)
    e.w32(self_ + 4, act)
    e.w8(self_ + 0x3ad, c.rng.choice([0, 1, 1, 1, 1, 0x20]))
    e.w32(self_ + 0x391, _r(c))
    e.w32(self_ + 0xc, _r(c))
    gp = [c.rng.uniform(-300, 300) for _ in range(3)]
    for i in range(3):
        e.w32(self_ + 0x379 + 4 * i, _fb(gp[i]))
    mode = c.rng.choice(['near', 'near', 'far', 'rnd', 'mark'] + ['edge'] * 5)
    if mode == 'edge':
        # exact float32 solutions: y gives a blend exactly on a mark (0.45, 0.65 near; 0.25, 0.75 far), or a free y near
        # any mark; the old blend is then the mark itself or just either side of it
        lift = 0.0
        gp[1] = 0.0
        e.w32(act + 0x43d, 0)
        e.w32(self_ + 0x379 + 4, 0)
        pairs = [(92.95000457763672, 0.45), (59.14999771118164, 0.65), (244.0, 0.25), (344.0, 0.25), (194.0, 0.75),
                 (294.0, 0.75)]
        if c.rng.random() < 0.6:
            y, mk = c.rng.choice(pairs)
        else:
            mk = c.rng.choice([0.1, 0.1, 0.45, 0.65, 0.35, 0.05, 0.25, 0.75, 0.0])
            if mk == 0.0:
                y = 249.0 + c.rng.uniform(-8, 8)   # far branch, blend near 0.2: the old blend 0 is the lower bound
            else:
                y = ((1 - mk) * 169.0 if mk not in (0.25, 0.75) else 169 + (1 - mk) * 100) + c.rng.choice([-1, 1]) * c.rng.uniform(0, 8)
    if mode == 'near':
        y = c.rng.uniform(-20, 175)
    elif mode == 'far':
        y = c.rng.uniform(169, 600)
    elif mode == 'mark':
        y = c.rng.choice([169.0, 0.0, -1.0, 169.0 * 0.9, 169.0 * 0.55, 269.0, 194.0])
    elif mode == 'rnd':
        y = c.rng.uniform(-1000, 1000)
    pos = _rnd(c, 0x10)
    py = gp[1] - y + lift
    for i, v in enumerate((c.rng.uniform(-300, 300), py, c.rng.uniform(-300, 300))):
        e.w32(pos + 4 * i, _fb(v))
    # old blend: random, or close to the new one so the 0.5 window opens and the marks get crossed
    yy = max(0.0, y)
    nb = (1 - yy / 169.0) if y < 169 else 1 - ((y - 169) / 100.0) % 1.0
    if mode == 'edge':
        old = struct.unpack('<f', struct.pack('<f', mk))[0] + c.rng.choice([0.0, 0.0, 0.0, 0.0, -0.2, -0.04, 0.04, 0.2])
    else:
      old = c.rng.choice([c.rng.uniform(-0.5, 1.5), nb + c.rng.uniform(-0.45, 0.45), nb + c.rng.uniform(-0.45, 0.45),
                          c.rng.choice([0.1, 0.45, 0.65, 0.35, 0.05, 0.25, 0.75, 0.0, -0.0]), float('nan')])
    e.w32(self_ + 0x3a9, _fb(old))
    out = _rnd(c, 4)
    return [self_, out, _rnd(c, 0x10), _rnd(c, 0x10), _rnd(c, 0x10), pos]


S(0x488650, 'ZMovementGuide::GetActiveAnim', 'thiscall', None, ret='st0', gen=_g_488650, nan_heap=True,
  note='batch279; base GetActiveAnim 0x4884b0 hooked; PSVECSubtract as exe code; fmod through the exe thunk')


def _g_489190(c):
    e = c.emu
    rets = {}

    def find(em, r):
        a = em.arg32(0)
        name = em.rbytes(a, 32).split(b'\0')[0]
        em.calllog.append(('self.58', 0, None, (name,)))
        rets.setdefault(name, _r(c))
        em.ret(eax=rets[name], argbytes=4)
    self_ = _rnd(c, 0x130)
    e.w32(self_, _pyvt(c, {0x58: find, 0x54: _slot('self.54', 1)}))
    for off, n in ((0xdd, 'bl'), (0xf5, 'drag'), (0x10d, 'sneak')):
        e.w32(self_ + off, _pyvt(c, {8: _slot(n + '.8', 3)}))
    return [self_]


S(0x489190, 'ZMovementStand::GetAnims', 'thiscall', None, ret=None, gen=_g_489190,
  note='batch279; void; all calls through Python vtables')
