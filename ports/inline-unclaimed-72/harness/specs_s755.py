"""specs_s755.py - area 72 round 4 skipped rows, batch 755. Exe callees are hooked by address and log their arguments:
0x4bb550, 0x4c24b0 and 0x5491a0 take none (plain ret); 0x4c0a90 and 0x4c0b00 take one (ret 4) and return a random eax.
Virtual tail jumps go to logging stubs with no arguments (GUESS arity 0)."""
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _log(e, name):
    def f(em, r, name=name):
        e.calllog.append((name, 0, nostk(e.reg('ecx')), ()))
        em.ret(eax=0, argbytes=0)
    return f


def _hook0(e, tgt, name):
    e.hook(tgt, _log(e, name))


def _hook1(c, e, tgt):
    rv = c.rng.getrandbits(32)

    def h(em, r):
        e.calllog.append(('cal1', tgt, nostk(e.reg('ecx')), (em.arg32(0),)))
        em.ret(eax=rv, argbytes=4)
    e.hook(tgt, h)


def _vobj(c, e, slots):
    o = _rnd(c, 0x400)
    e.w32(o, e.fake_vtable('obj', 0x200, slots))
    return o


def _vslot(e, off, rv):
    def f(em, r):
        e.calllog.append(('vobj', off, nostk(e.reg('ecx')), ()))
        em.ret(eax=rv, argbytes=0)
    return f


def _g_plainbool(tgt, name):
    def g(c):
        e = c.emu
        _hook0(e, tgt, name)
        s = _rnd(c, 0x200)
        e.wbytes(s + 4, bytes([c.rng.getrandbits(8)]))
        return [s, c.rng.getrandbits(32)]
    return g


def _g_5490f0(c):
    e = c.emu
    _hook0(e, 0x5491a0, 'shatter')
    s = _rnd(c, 0x200)
    e.wbytes(s + 4, bytes([c.rng.getrandbits(8)]))
    return [s]


def _g_1arg(tgt):
    def g(c):
        e = c.emu
        _hook1(c, e, tgt)
        return [_rnd(c, 0x200), c.rng.getrandbits(32), c.rng.getrandbits(32)]
    return g


def _g_4c1f70(c):
    e = c.emu
    rv = c.rng.getrandbits(32)
    db = _vobj(c, e, {0x2c: _vslot(e, 0x2c, rv)})
    eng = _rnd(c, 0x100)
    e.w32(0x70039c, eng)
    e.w32(eng + 0x9b, db)
    return [_rnd(c, 0x100)]


def _g_4d4040(c):
    e = c.emu
    rv = c.rng.getrandbits(32)
    s = _rnd(c, 0x10e0)
    vt = e.fake_vtable('sub', 0x200, {0x0: _vslot(e, 0x0, rv)})
    e.w32(s + 0x10db, vt)   # the sub-object is inline: its first dword is the vtable
    return [s]


def _g_dbbc(off):
    def g(c):
        e = c.emu
        s = _rnd(c, 0x200)
        if c.rng.random() < 0.7:
            o = _vobj(c, e, {off: _vslot(e, off, 0)})
            e.w32(s + 0x54, o)
        else:
            e.w32(s + 0x54, 0)
        return [s]
    return g


S(0x4bb600, 'f_4bb600', 'thiscall', None, ret='al', gen=_g_plainbool(0x4bb550, 'bb550'), note='b755 area 72 round 4')
S(0x4bb9d0, 'f_4bb9d0', 'thiscall', None, ret='al', gen=_g_plainbool(0x4c24b0, 'c24b0'), note='b755 area 72 round 4')
S(0x5490f0, 'f_5490f0', 'thiscall', None, ret=None, gen=_g_5490f0, note='b755 area 72 round 4')
S(0x4c1e20, 'f_4c1e20', 'thiscall', None, ret='eax', gen=_g_1arg(0x4c0a90), note='b755 area 72 round 4')
S(0x4c1ed0, 'f_4c1ed0', 'thiscall', None, ret='eax', gen=_g_1arg(0x4c0b00), note='b755 area 72 round 4')
S(0x4c1f70, 'f_4c1f70', 'thiscall', None, ret='eax', gen=_g_4c1f70, note='b755 area 72 round 4; GUESS arity 0')
S(0x4d4040, 'f_4d4040', 'thiscall', None, ret='eax', gen=_g_4d4040, note='b755 area 72 round 4; GUESS arity 0')
S(0x4dbbc0, 'f_4dbbc0', 'thiscall', None, ret=None, gen=_g_dbbc(0x18), note='b755 area 72 round 4; GUESS arity 0')
S(0x4dbbd0, 'f_4dbbd0', 'thiscall', None, ret=None, gen=_g_dbbc(0x1c), note='b755 area 72 round 4; GUESS arity 0')
