"""specs_s701.py - soldier AI batch 701: CCheckVisible AddObject/AddSeer/DelObject and their event handlers.
Engine 0x70039c (+0x9b geom db, +0x40 tick), logger 0x700390 and assert hook 0x7003b0 are heap fakes per case.
Geom IsKindOf (slot 0x1e0) answers a random bool with random upper bits, so only AL may be read."""
import struct
from pilot import S

CV_SIZE = 0x16000


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, c.rng.randbytes(n))
    return a


def _world(c):
    e = c.emu
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)

    def kind(em, args):
        return ((c.rng.getrandbits(24) << 8) | c.rng.choice([0, 1])), None

    def name_into(em, r):     # slot 0x1d8(MYSTR* out, int): returns out; the out pointer is a stack address (not logged)
        em.calllog.append(('geom.GetName', 0x1d8, None, (em.arg32(1),)))
        em.w32(em.arg32(0), em.reg('ecx'))      # the fake MYSTR holds the geom; c_str returns the name stored at geom+8
        em.ret(eax=em.arg32(0), argbytes=8)

    def lookup(em, args):
        vt = e.fake_vtable('geom', 0x80, {0x1e0: lambda em2, r2: (em2.calllog.append(('geom.IsKindOf', 0x1e0, em2.reg('ecx'), (em2.arg32(0),))),
                                                                    em2.ret(eax=kind(em2, None)[0], argbytes=4)),
                                           0x1d8: name_into})
        g = _rnd(c, 32)
        e.w32(g, vt)
        e.wbytes(g + 8, b'g%07x\0' % (g & 0xfffffff))
        return g, None
    vt = e.logging_vtable('geomdb', 32, impl={0x58: lookup}, argwords={0x58: 1})
    db = _rnd(c, 32)
    e.w32(db, vt)
    e.wbytes(eng + 0x9b, struct.pack('<I', db))
    # debug logger: slot 0x20(file, line) -> log object; log slot 0x2c is cdecl printf (log, fmt, ...)
    logobj = _rnd(c, 16)

    def printf(em, r):
        em.calllog.append(('log.printf', 0x2c, None, tuple(em.arg32(k) for k in range(3))))
        em.ret(eax=0, argbytes=0)
    e.w32(logobj, e.fake_vtable('log', 16, {0x2c: printf}))
    lg = _rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (logobj, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    # assert hook: always a logging stub (inline-wireai 2026-10-13; the original spec left it null 30% of the time, which
    # makes both builds stop at int3 and counts as faulting cases). The draw is kept so the case stream is unchanged.
    c.rng.random()
    e.w32(0x7003b0, e.stub_fn('assert', lambda em, r: (em.calllog.append(('assert', 0, None, ())), em.ret(eax=0))))
    # MYSTR helpers used by DelObject's warning: c_str returns a fixed name, the destructor does nothing
    e.hook(0x4cc1d0, lambda em, r: em.ret(eax=em.r32(em.reg('ecx')) + 8))
    e.hook(0x4cbec0, lambda em, r: em.ret())
    return eng


def _cv(c):
    cv = _rnd(c, CV_SIZE)
    disp = _rnd(c, 16)
    c.emu.w32(disp, c.emu.logging_vtable('dispatch', 0x50, argwords={0x12c: 3}))
    c.emu.w32(cv + 0x44, disp)
    return cv


def _plant(c, base, stride, ref, p_hit=0.4, p_free=0.8):
    e = c.emu
    if c.rng.random() < p_free:
        for _ in range(c.rng.choice([1, 1, 2, 5])):
            e.w32(base + stride * c.rng.randrange(200), 0)
    if c.rng.random() < p_hit:
        e.w32(base + stride * c.rng.randrange(200), ref)


def _ref(c):
    return c.rng.choice([0, c.rng.getrandbits(32), c.rng.getrandbits(32), 7])


def _addobj(c):
    _world(c)
    cv = _cv(c)
    ref = _ref(c)
    _plant(c, cv + 0x54, 8, ref)
    return [cv, ref]


def _addseer(c):
    _world(c)
    cv = _cv(c)
    ref = _ref(c)
    _plant(c, cv + 0x694, 0x1b8, ref)
    return [cv, ref]


S(0x4a9a10, 'CCheckVisible::AddObject', 'thiscall', None, ret='eax', gen=_addobj, note='b701 [medium]')
S(0x4a9ad0, 'CCheckVisible::AddSeer', 'thiscall', None, ret='eax', gen=_addseer,
  note='b701 [medium]; CRT cos at 0x634d70 runs as exe code')


def _objadd(c):
    _world(c)
    cv = _cv(c)
    ref = _ref(c)
    _plant(c, cv + 0x54, 8, ref)
    for _ in range(c.rng.choice([0, 3, 30])):     # some empty seer slots
        c.emu.w32(cv + 0x694 + 0x1b8 * c.rng.randrange(200), 0)
    return [cv, ref]


S(0x4ab100, 'CCheckVisible::OnObjectAdd', 'thiscall', None, ret='eax', gen=_objadd,
  note='b701 [high]; AddObject runs as exe code')


def _seerobj(c):
    _world(c)
    cv = _cv(c)
    s, o = _ref(c), _ref(c)
    _plant(c, cv + 0x694, 0x1b8, s)
    _plant(c, cv + 0x54, 8, o)
    ev = c.emu.alloc(8, 4)
    c.emu.w32(ev, s)
    c.emu.w32(ev + 4, o)
    return [cv, ev]


S(0x4ab2d0, 'CCheckVisible::OnSeerObjectAdd', 'thiscall', None, ret='eax', gen=_seerobj,
  note='b701 [high]; AddSeer/AddObject run as exe code')


def _del(c):
    _world(c)
    cv = _cv(c)
    ref = _ref(c)
    _plant(c, cv + 0x54, 8, ref, p_hit=0.75, p_free=0.0)
    return [cv, ref]


S(0x4a9e70, 'CCheckVisible::DelObject', 'thiscall', None, ret=None, gen=_del,
  note='b701 [high]; MYSTR c_str/dtor hooked')
S(0x4ab160, 'CCheckVisible::OnObjectDel', 'thiscall', None, ret='eax', gen=_del,
  note='b701 [high]; DelObject runs as exe code')
