"""specs_s225.py - ladder thread batch 225: ZIKLNKOBJ ActivateRagdoll, ClassInit2, UpdateTargets, UpdateSpeech, MoveToMatPos."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from pe_emu import f32
import ladder_kit as K


def _self(c):
    e, r = c.emu, c.rng
    s = K.rnd(c, 0x200)
    sub = K.rnd(c, 0x10)
    rv = r.getrandbits(32)
    e.w32(sub, K.vt(c, 'sub', {0x7c: (2, lambda e2, a: (rv, None, None))}, nslots=0x40))
    slots = {0x220: (1, lambda e2, a: (0, None, None)), 0x408: (0, lambda e2, a: (0, None, None)),
             0x404: (0, lambda e2, a: (0, None, None)), 0x40c: (0, lambda e2, a: (rv ^ 5, None, None)),
             0x20: (0, lambda e2, a: (sub, None, None))}
    e.w32(s, K.vt(c, 'self', slots, nslots=0x110))
    ik = K.rnd(c, 0x10)
    ret = r.choice([0, 1, 0x100, r.getrandbits(32)])
    e.w32(ik, K.vt(c, 'ik', {0x30: (4, lambda e2, a: (ret, None, None))}, nslots=0x20))
    e.w32(s + 0x6c, ik)

    def hk(addr, name):
        def h(e2, res):
            e2.calllog.append((name, e2.reg('ecx')))
            e2.ret()
        e.hook(addr, h)
    hk(0x466ce0, 'KillAllSounds')
    hk(0x45d3a0, 'ZGEOM::ClassInit2')
    eng = K.engine(c)
    d = K.rnd(c, 0xb00)
    e.w32(eng + 0x9b, d)
    so = K.rnd(c, 0x80)
    e.wf32(so + 0x70, r.choice([0.0, 0.05, 0.1, 0.2, 1.0, float('nan'), f32(r.uniform(0, 0.3))]))
    sop = so if r.random() < 0.8 else 0
    e.w32(d, K.vt(c, 'database', {0x4c: (1, lambda e2, a: ((a[0] * 3 + 5) & 0xffffffff, None, None)),
                                  0x60: (1, lambda e2, a: (sop, None, None))}, nslots=0x40))
    lst = K.rnd(c, 0x10)
    e.w32(lst, K.vt(c, 'list', {0x228: (3, lambda e2, a: (0, None, None))}, nslots=0x100))
    lp = lst if r.random() < 0.85 else 0
    holder = K.rnd(c, 0x10)
    e.w32(holder, K.vt(c, 'lists', {0x25c: (2, lambda e2, a: (lp, None, None))}, nslots=0xb0))
    e.w32(d + 0xadc, holder)
    if r.random() < 0.5:
        def ah(e2, res):
            e2.calllog.append(('assert',))
            e2.ret()
        e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    if r.random() < 0.2:
        e.w32(s + 0x153, 0)
    return s


def g(n):
    return lambda c: [_self(c)] + [c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)]) for _ in range(n)]


S(0x465760, 'ZIKLNKOBJ::ActivateRagdoll', 'thiscall', None, ret='al', gen=g(2), note='batch225')
S(0x465fd0, 'ZIKLNKOBJ::ClassInit2', 'thiscall', None, ret=None, gen=g(0), note='batch225')
S(0x467f60, 'ZIKLNKOBJ::UpdateTargets', 'thiscall', None, ret='eax', gen=g(0), note='batch225')
S(0x467f20, 'ZIKLNKOBJ::UpdateSpeech', 'thiscall', None, ret=None, gen=g(0), note='batch225')
S(0x466f30, 'ZIKLNKOBJ::MoveToMatPos', 'thiscall', None, ret='eax', gen=g(2), note='batch225')
