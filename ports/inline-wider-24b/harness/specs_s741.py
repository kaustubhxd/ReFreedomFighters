"""specs_s741.py - ZFFSearchLightGroup::Command. The command words at 0x714340 (A) and 0x714344 (B) are set to random words
per case; the command is A, B or a random word. The spot ref and group ref are random (the group ref is nonzero except in
a few cases). The ref tables GetRefTabToOperators (0x5c6c50) and GetRefTabToEngageGuards (0x5c6bf0) are hooked (log, return
a fake table or 0). The table's slot 4 logs. The group object (db 0x58 of the group ref) answers slot 0x1e0 with a random
bool and slot 0x50 (iterator) advances through a chain of 0..3 elements whose +0x54 objects answer slot 0x1e0. db 0x4c maps
an object to a random ref. The logger and printf come from _log_world."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s709 import _log_world
from specs_s705 import nostk


def _slg(c):
    e = c.emu
    _log_world(c)
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))

    wA = c.rng.getrandbits(16)
    wB = c.rng.getrandbits(16)
    e.wbytes(0x714340, struct.pack('<H', wA))
    e.wbytes(0x714344, struct.pack('<H', wB))

    tab_ok = c.rng.random() < 0.8
    tab = _rnd(c, 0x40)

    def tab4(em, r):
        log('tab', 0x4, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)
    e.w32(tab, e.fake_vtable('tab', 0x100, {0x4: tab4}))

    def h_ops(em, r):
        log('slg', 0x5c6c50, (em.arg32(0),))
        em.ret(eax=tab if tab_ok else 0, argbytes=4)

    def h_eng(em, r):
        log('slg', 0x5c6bf0, (em.arg32(0),))
        em.ret(eax=tab if tab_ok else 0, argbytes=4)
    e.hook(0x5c6c50, h_ops)
    e.hook(0x5c6bf0, h_eng)

    ref_group = c.rng.getrandbits(32) | 1
    gflag = c.rng.choice([0, 1, 1])
    eflag = c.rng.choice([0, 1])

    elems = []
    n = c.rng.randint(0, 3)
    for _ in range(n):
        el = _rnd(c, 0x80)
        eo = _rnd(c, 0x80)
        e.w32(el + 0x54, eo)
        elems.append(el)

    def ob1e0(em, r):
        log('obj', 0x1e0, (em.arg32(0),))
        em.ret(eax=c.rng.choice([0, 1]), argbytes=4)
    eobj_vt = e.fake_vtable('eobj', 0x200, {0x1e0: ob1e0})
    for el in elems:
        e.w32(el + 0x54, el + 0x54 + 0)     # placeholder replaced below
    for i, el in enumerate(elems):
        eo = _rnd(c, 0x80)
        e.w32(eo, eobj_vt)
        e.w32(el + 0x54, eo)

    def g1e0(em, r):
        log('group', 0x1e0, (em.arg32(0),))
        em.ret(eax=gflag if em.arg32(0) == 0x100001 else eflag, argbytes=4)

    def g50(em, r):
        cur_ptr = em.arg32(0)
        cur = em.r32(cur_ptr)
        idx = elems.index(cur) + 1 if cur in elems else 0
        nxt = elems[idx] if idx < len(elems) else 0
        log('group', 0x50, (nostk(cur),))
        em.w32(cur_ptr, nxt)
        em.ret(eax=0, argbytes=4)

    group = _rnd(c, 0x40)
    e.w32(group, e.fake_vtable('group', 0x200, {0x1e0: g1e0, 0x50: g50}))
    e.w32(group + 8, elems[0] if elems else 0)

    ref_of = {}

    def db58(em, r):
        arg = em.arg32(0)
        log('db', 0x58, (arg,))
        if arg == ref_group:
            em.ret(eax=group, argbytes=4)
        else:
            em.ret(eax=group, argbytes=4)

    def db4c(em, r):
        obj = em.arg32(0)
        log('db', 0x4c, (nostk(obj),))
        em.ret(eax=ref_of.setdefault(obj, c.rng.getrandbits(32)), argbytes=4)
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)
    db = _rnd(c, 0x100)
    e.w32(eng + 0x9b, db)
    e.w32(db, e.fake_vtable('db', 0x200, {0x58: db58, 0x4c: db4c}))

    data = _rnd(c, 0x10)
    spot = c.rng.getrandbits(32) | 1
    e.w32(data, spot if c.rng.random() < 0.9 else 0)
    e.w32(data + 4, ref_group if c.rng.random() < 0.9 else 0)
    cmd = c.rng.choice([wA, wB, wA, c.rng.getrandbits(16)])
    self_ = _rnd(c, 0x200)
    return [self_, cmd, data]


S(0x5c63f0, 'ZFFSearchLightGroup::Command', 'thiscall', None, ret='eax', gen=_slg,
  note='b741 residue 11 [high]; ref tables and group iterator fake; command words at 0x714340/0x714344 set per case')
