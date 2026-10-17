"""specs_s247.py - ladder thread batch 247: ZFFHERO::UpdateDefaultAction (NOT verified: exe 5-push imbalance).
Engine helpers (CCom, CSharedCom::SetVal, MYSTR) are logging hooks; the CRT _stricmp is an import stub; ConvPtr runs with the
fake global object of ops_kit.py. The check reports the calls and the clobber separately (see docs/20-ladder.md)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K
import ops_kit as O


def _lower(b):
    return b + 32 if 65 <= b <= 90 else b


def _rd(e, a):
    out = bytearray()
    while True:
        b = e.mu.mem_read(a + len(out), 1)[0]
        if b == 0:
            break
        out.append(b)
    return bytes(out)


def _stricmp(e, r):
    a, b = _rd(e, e.arg32(0)), _rd(e, e.arg32(1))
    n = max(len(a), len(b))
    a = a.ljust(n, b'\0')
    b = b.ljust(n, b'\0')
    res = 0
    for i in range(n):
        x, y = _lower(a[i]), _lower(b[i])
        if x != y or x == 0:
            res = (x - y) & 0xffffffff
            break
    e.ret(eax=res)


def _hook(c, addr, name, n, ab, ret=0):
    def h(e2, res):
        e2.calllog.append((name, K.nostack(e2.reg('ecx')), tuple(K.nostack(e2.arg32(i)) for i in range(n))))
        e2.ret(eax=ret, argbytes=ab)
    c.emu.hook(addr, h)


def _gen(c):
    e, r = c.emu, c.rng
    c.emu.stub_import('_stricmp', _stricmp)
    eng = K.engine(c)
    d = K.rnd(c, 0xb00)
    e.w32(eng + 0x9b, d)
    mgr = K.rnd(c, 0x20)
    e.w32(mgr, K.vt(c, 'listmgr', {0x88: (2, lambda e2, a: (e2.w32(a[1], r.getrandbits(32)) or 0, None,
                                                           (K.nostack(a[1]), e2.cstr_read(a[0]) if False else a[0])))},
                    nslots=0x100))
    name_cui = 0x68be98
    e.w32(d, K.vt(c, 'database', {0x138: (0, lambda e2, a: (mgr, None, None)),
                                  0x114: (4, lambda e2, a: (r.getrandbits(16), None, tuple(a))),
                                  0x4c: (2, lambda e2, a: (r.getrandbits(32), None, tuple(a)))}, nslots=0x100))
    hero = O.hero(c)
    e.w32(hero + 0x688, r.choice([0, 0, r.getrandbits(32)]))
    if r.random() < 0.6:
        s = e.cstr(r.choice(['Dragunov', 'Knife', 'FirstAid_Small', '']))
        e.w32(hero + 0x698, s)
    else:
        e.w32(hero + 0x698, 0)
    e.w16(hero + 0x165, r.getrandbits(16))
    act = 0
    if r.random() < 0.7:
        act = K.rnd(c, 0x80)
        e.w32(act + 0x7a, e.cstr(r.choice(['Dragunov', 'Knife', 'FirstAid_Small', 'WaterWalk'])))
        e.w32(act + 0x52, r.getrandbits(32))
        # the action is also the current default in some cases, so the early exit runs
        if r.random() < 0.2:
            e.w32(hero + 0x688, act)
    # hero slot 0x12c and the engine
    e.w32(hero, K.vt(c, 'hero', {0x12c: (2, lambda e2, a: (0, None, tuple(K.nostack(x) for x in a)))}, nslots=0x800))
    # engine helpers: logging hooks (the originals are verified elsewhere)
    _hook(c, 0x4d2280, 'CCom::ctor', 0, 0)
    _hook(c, 0x4d2330, 'CCom::teardown', 0, 0)
    _hook(c, 0x4d3a00, 'SetVal3a', 3, 0xc)
    _hook(c, 0x4d39a0, 'SetVal2', 2, 0x8)
    _hook(c, 0x4d3ad0, 'SetVal3b', 3, 0xc)
    _hook(c, 0x4cbe80, 'MYSTR::ctor', 1, 4)
    _hook(c, 0x4cbee0, 'MYSTR::op=', 1, 4)
    _hook(c, 0x4cbec0, 'MYSTR::dtor', 0, 0)
    _hook(c, 0x4cc5f0, 'MYSTR::Length', 0, 0, r.choice([0, 0, 5]))
    O.g2(c, hero)
    return [hero, act]


S(0x595570, 'ZFFHERO::UpdateDefaultAction', 'thiscall', None, ret=None, gen=_gen, note='batch247')
