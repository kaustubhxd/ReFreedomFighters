"""specs_s716.py - soldier AI batch 716: ZFFActor::OnSound. The event list is a fake REFTAB (slot 0x4c starts an
iterator in the caller's stack slot, slot 0x64 returns events 0..n-1 then null). Sources are fake geoms with a
team record and a random IsDerivedFrom; the 'self' object logs SendCommand (id and the sound block by content).
RegisterZMsg (db slot 0x114) logs its name and returns a random 16-bit id with random high bits."""
import math
import struct
from pilot import S, f32
from specs_s701 import _rnd
from specs_s705 import _bool, nostk
from specs_s709 import _log_world


def _team(c, e, idx=None, mask=None):
    t = _rnd(c, 16)
    e.w32(t + 4, idx if idx is not None else c.rng.choice([0, 1, 1, 2, 3]))
    e.w32(t + 0xc, mask if mask is not None else c.rng.getrandbits(32) & c.rng.choice([0xffffffff, 0xf, 0x2, 0x6]))
    return t


def _os(c):
    e = c.emu
    _log_world(c)
    # the assert hook is always present: unhandled sound types call it (no int3 trap in the spec)
    e.w32(0x7003b0, e.stub_fn('assert', lambda em, r: (em.calllog.append(('assert', 0, None, ())), em.ret(eax=0))))
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)

    # geoms: each with a team record; sourced by ref
    selfteam = _team(c, e, idx=c.rng.choice([0, 1, 1]))
    self_ = _rnd(c, 0x100)
    e.w32(self_ + 0x54, selfteam)

    def sendcmd(em, r):
        # wire-ai run 11: the block's 0x18 bytes are compared too (before only the pointer, as 'stk', so a zeroed block passed)
        p = em.arg32(1)
        log('self', 0x128, (em.arg32(0), nostk(p), em.arg32(2)) + (tuple(em.rbytes(p, 0x18)) if p else ()))
        em.ret(eax=0, argbytes=12)
    def self_isd(em, r):
        log('self', 0x1e0, (em.arg32(0),))
        em.ret(eax=1, argbytes=4)
    self_vt = e.fake_vtable('self', 0x200, {0x128: sendcmd, 0x1e0: self_isd})
    e.w32(self_, self_vt)

    selfref = c.rng.getrandbits(32)
    geoms = {}

    def geom(ref):
        if ref in geoms:
            return geoms[ref]
        g = _rnd(c, 0x100)
        def isd(em, r):
            log('geom', 0x1e0, (em.arg32(0),))
            em.ret(eax=_bool(c) if c.rng.random() < 0.8 else 1, argbytes=4)
        gvt = e.fake_vtable('geom', 0x1f0, {0x1e0: isd})
        e.w32(g, gvt)
        e.w32(g + 0x54, _team(c, e))
        geoms[ref] = g
        return g

    def dblookup(em, r):
        ref = em.arg32(0)
        log('db', 0x58, (ref,))
        if ref == selfref:
            em.ret(eax=self_, argbytes=4)
        elif ref == 0:
            em.ret(eax=0, argbytes=4)
        else:
            em.ret(eax=geom(ref), argbytes=4)

    def regmsg(em, r):
        name = em.arg32(0)
        log('db', 0x114, (name, em.arg32(1), em.arg32(2), em.arg32(3)))
        em.ret(eax=c.rng.getrandbits(32), argbytes=16)
    db = _rnd(c, 0x100)
    e.w32(db, e.fake_vtable('db', 0x120, {0x58: dblookup, 0x114: regmsg}))
    e.wbytes(eng + 0x9b, struct.pack('<I', db))

    # events
    n = c.rng.choice([0, 1, 2, 4, 6])
    evs = []
    for _ in range(n):
        ev = _rnd(c, 0x20)
        e.wbytes(ev, struct.pack('<3f', *[f32(c.rng.uniform(-300, 300)) for _ in range(3)]))
        e.wbytes(ev + 0xc, struct.pack('<I', c.rng.choice([1, 2, 3, 4, 5, 6, 7, 0, 8, 9])))
        e.wbytes(ev + 0x10, struct.pack('<f', f32(c.rng.choice([c.rng.uniform(0, 2000), 999.0, 1000.0, 1500.0, 1500.001, 1000.5]))))
        e.wbytes(ev + 0x14, struct.pack('<I', c.rng.choice([selfref, 0, c.rng.getrandbits(32), 77, 78])))
        e.wbytes(ev + 0x1c, struct.pack('<I', c.rng.getrandbits(32)))
        evs.append(ev)

    def lst_begin(em, r):
        it = em.arg32(0)
        em.w32(it, 0)
        em.ret(eax=0, argbytes=4)

    def lst_next(em, r):
        it = em.arg32(0)
        i = em.r32(it)
        if i < len(evs):
            em.w32(it, i + 1)
            em.ret(eax=evs[i], argbytes=4)
        else:
            em.ret(eax=0, argbytes=4)
    lst = _rnd(c, 16)
    e.w32(lst, e.fake_vtable('list', 0x80, {0x4c: lst_begin, 0x64: lst_next}))
    return [self_, lst]


S(0x5a1830, 'ZFFActor::OnSound', 'thiscall', None, ret=None, gen=_os, note='b716 [medium]; sound block by content')
