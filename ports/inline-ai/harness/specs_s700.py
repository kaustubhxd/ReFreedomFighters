"""specs_s700.py - soldier AI batch 700: CCheckVisible leaves, CReservable, CCoverSpot::Reserve, ZFFActor::CanSee.
Engine global 0x70039c and logger 0x700390 are set per case to heap fakes (the image is restored between runs)."""
import math
import struct
from pilot import S, F, f32

CV_SIZE = 0x16000


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, c.rng.randbytes(n))
    return a


def _engine(c, tick=None):
    eng = _rnd(c, 0x200)
    if tick is None:
        tick = c.rng.choice([0, 1, 1024, -1, 0x7fffffff, -0x80000000, c.rng.randint(-2**31, 2**31 - 1),
                             c.rng.randint(0, 100000)])
    c.emu.w32(eng + 0x40, tick & 0xffffffff)
    c.emu.w32(0x70039c, eng)
    return eng


def _cv(c):
    return _rnd(c, CV_SIZE)


def _seer_ref(c, cv):
    """A ref that matches some seer slot (70%) or a random value."""
    ref = c.rng.getrandbits(32)
    if c.rng.random() < 0.7:
        i = c.rng.randrange(200)
        if c.rng.random() < 0.2:
            ref = 0
        c.emu.w32(cv + 0x694 + i * 0x1b8, ref)
        if c.rng.random() < 0.3:        # a duplicate later: the first one must win
            j = c.rng.randrange(i, 200)
            c.emu.w32(cv + 0x694 + j * 0x1b8, ref)
    return ref


def _idx(c):
    return c.rng.choice([0, 1, 199, 200, c.rng.randrange(200), c.rng.getrandbits(32)])


S(0x4aaa30, 'CCheckVisible::GetObjectData', 'thiscall', None, ret='eax',
  gen=lambda c: [_rnd(c, 16), _idx(c)], note='b700 [high]')
S(0x4aab90, 'CCheckVisible::GetSeerData', 'thiscall', None, ret='eax',
  gen=lambda c: [_rnd(c, 16), _idx(c)], note='b700 [high]')


def _gsi(c):
    cv = _cv(c)
    return [cv, _seer_ref(c, cv)]


S(0x4aabb0, 'CCheckVisible::GetSeerIndex', 'thiscall', None, ret='eax', gen=_gsi, n=None, note='b700 [high]')


def _dist(c):
    cv = _cv(c)
    ev = _rnd(c, 8)
    return [cv, ev]


S(0x4ab410, 'CCheckVisible::OnSetVisDistMultiplier', 'thiscall', None, ret='eax', gen=_dist, note='b700 [high]')
S(0x4ab180, 'CCheckVisible::OnResetTimers', 'thiscall', None, ret='eax',
  gen=lambda c: [_cv(c), c.rng.getrandbits(32)], note='b700 [high]')
S(0x4ab280, 'CCheckVisible::OnSeerDel', 'thiscall', None, ret='eax', gen=_gsi, note='b700 [medium]')

S(0x5de9c0, 'CReservable::Release', 'thiscall', None, ret=None, gen=lambda c: [_rnd(c, 16)], note='b700 [medium]')


def _fexp(c):
    r = c.rng.random()
    if r < 0.15:
        return f32(c.rng.choice([0.0, -0.0, math.nan, math.inf, -math.inf, 3e9, -3e9, 2097152.0]))
    return f32(c.rng.uniform(-1e6, 1e6) if r < 0.4 else c.rng.uniform(0, 200))


def _nogood(c):
    eng = _engine(c)
    o = _rnd(c, 16)
    if c.rng.random() < 0.3:
        c.emu.w32(o + 4, 0)
    exp = _fexp(c)
    c.emu.wf32(o, exp)
    if c.rng.random() < 0.4 and math.isfinite(exp) and abs(exp) < 2e6:   # tick right at the boundary
        t = int(exp * 1024.0) + c.rng.choice([-1, 0, 1])
        c.emu.w32(eng + 0x40, t & 0xffffffff)
    return [o]


S(0x5de970, 'CFFCoverList::SendCoverNoGood (CReservable expired?)', 'thiscall', None, ret='al', gen=_nogood,
  note='b700 [medium]')


def _geomdb(c, eng):
    """Engine +0x9b: geom database whose slot 0x58 maps a ref to a fake geom; each geom's slot 0x20 returns a
    class-info record whose +4 is a name pointer (or 0 for "<NONAME>")."""
    e = c.emu
    geoms = {}

    def lookup(em, args):
        ref = args[0]
        if ref not in geoms:
            ci = _rnd(c, 16)
            if c.rng.random() < 0.3:
                e.w32(ci + 4, 0)
            else:
                e.w32(ci + 4, e.cstr('actor_%08x' % ref))
            vt = e.logging_vtable('geom%x' % ref, 12, impl={0x20: lambda em2, a2, ci=ci: (ci, None)})
            g = _rnd(c, 32)
            e.w32(g, vt)
            geoms[ref] = g
        return geoms[ref], None
    vt = e.logging_vtable('geomdb', 32, impl={0x58: lookup}, argwords={0x58: 1})
    db = _rnd(c, 32)
    e.w32(db, vt)
    e.wbytes(eng + 0x9b, struct.pack('<I', db))


def _logger(c):
    e = c.emu
    logobj = _rnd(c, 16)

    def printf(em, r):   # cdecl: (log, fmt, s1, s2, double, double); caller pops
        args = tuple(em.arg32(k) for k in range(8))
        em.calllog.append(('log.printf', 0x2c, None, args))
        em.ret(eax=0, argbytes=0)
    lvt = e.fake_vtable('log', 16, {0x2c: printf})
    e.w32(logobj, lvt)
    vt = e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (logobj, None)}, argwords={0x20: 2})
    lg = _rnd(c, 16)
    e.w32(lg, vt)
    e.w32(0x700390, lg)


def _reserve_args(c):
    eng = _engine(c)
    _geomdb(c, eng)
    _logger(c)
    o = _rnd(c, 0x40)
    cur = c.rng.choice([0, 0, c.rng.getrandbits(32), 5])
    c.emu.w32(o + 4, cur)
    c.emu.wf32(o, _fexp(c))
    who = c.rng.choice([cur, cur, 0, 5, c.rng.getrandbits(32)])
    return o, who


def _res(c):
    o, who = _reserve_args(c)
    return [o, who, F(_fexp(c))]


S(0x5de9d0, 'CReservable::Reserve', 'thiscall', None, ret=None, gen=_res, note='b700 [high]')


def _spot(c):
    o, who = _reserve_args(c)
    return [o, who, F(_fexp(c)), c.rng.getrandbits(32), c.rng.choice([0, 1, 0x100, 0xffffff00, 0xff])]


S(0x5df400, 'CCoverSpot::Reserve', 'thiscall', None, ret=None, gen=_spot,
  note='b700 [high]; CReservable::Reserve runs as exe code')


def _cansee_stub(em, r):
    args = (em.reg('ecx'), em.arg32(0), em.arg32(1))
    em.calllog.append(('CCheckVisible::CanSee', 0, None, args))
    em.ret(eax=em._cansee_ret, argbytes=8)


def _cansee(c):
    e = c.emu
    e.hook(0x4a9cb0, _cansee_stub)
    e._cansee_ret = c.rng.choice([0, 1])
    a = _rnd(c, 0x960)
    if c.rng.random() < 0.3:
        e.w32(a + 0x8f2, 0xffffffff)
    return [a, c.rng.getrandbits(32)]


S(0x59e050, 'ZFFActor::CanSee', 'thiscall', None, ret='al', gen=_cansee,
  note='b700 [medium]; CCheckVisible::CanSee stubbed (logged)')
