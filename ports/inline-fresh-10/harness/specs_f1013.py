"""specs_f1013.py - fresh-10 batch 13 (slice 10)."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from h10 import L, obj, rbuf, patch, iat, log_obj


def R(c): return c.rng.getrandbits(32)
def fb(x): return struct.unpack('<I', struct.pack('<f', x))[0]
def scene(c, slots, size=0x200):
    s = obj(c, 'scene', slots, size=size); rm = rbuf(c, 0x1b00); c.emu.w32(rm + 0x9b, s); c.emu.w32(0x70039c, rm)
    return s, rm
def mystr_stubs(c):
    def ctor(e, r):
        e.calllog.append(('MYSTR', 0, (e.arg32(0),))); e.w32(e.reg('ecx'), e.arg32(0)); e.ret(eax=e.reg('ecx'), argbytes=4)
    def assign(e, r):
        e.calllog.append(('MYSTR=', 0, (e.r32(e.arg32(0)),))); e.w32(e.reg('ecx'), e.r32(e.arg32(0))); e.ret(eax=e.reg('ecx'), argbytes=4)
    def dtor(e, r):
        e.calllog.append(('~MYSTR', 0, (e.r32(e.reg('ecx')),))); e.ret(eax=0, argbytes=0)
    patch(c, 0x4cbe80, ctor); patch(c, 0x4cbee0, assign); patch(c, 0x4cbec0, dtor)


def g_50d8e0(c):   # GUESS opaque type singleton
    flag = c.rng.choice([0, 0, 1]); c.emu.w32(0x7012c8, flag)
    old = obj(c, 'old', {4: L('old4', 1)}, size=0x10); c.emu.w32(0x7012cc, c.rng.choice([0, old]))
    o = rbuf(c, 0x10)
    def h1c(e, r):
        p = e.arg32(0); e.calllog.append(('ot1c', e.reg('ecx'), (e.rbytes(p, 13).hex(),))); e.w32(p + 4, 0x77); e.ret(eax=0, argbytes=4)
    def octor(e, r):
        e.calllog.append(('OpaqueType_t', e.reg('ecx'), (e.arg32(0), e.arg32(1))))
        e.w32(e.reg('ecx'), c.emu.fake_vtable('ot2', 8, {0x1c: h1c})); e.ret(eax=e.reg('ecx'), argbytes=8)
    patch(c, 0x5f9700, octor)
    def nw(e, r):
        e.calllog.append(('new', 0, (e.arg32(0),))); e.ret(eax=(0 if (flag and c.rng.random() < 0.3) else o), argbytes=0)
    patch(c, 0x41e290, nw)
    def res(e, r):
        p = e.reg('ecx'); e.calllog.append(('reserve', 0, (e.rbytes(p, 13).hex(), e.arg32(0)))); e.w32(p, 0x1234); e.ret(eax=0, argbytes=4)
    def fr(e, r):
        p = e.reg('ecx'); e.calllog.append(('vecfree', 0, (e.rbytes(p, 13).hex(),))); e.ret(eax=0, argbytes=0)
    patch(c, 0x59a9b0, res); patch(c, 0x4ff9d0, fr)
    return [R(c), R(c)]
S(0x50d8e0, 'GUESS opaque type singleton', 'fastcall', None, ret='eax', gen=g_50d8e0)


def g_442d20(c):   # ZTreeGroup::CreateDynamicTrees()
    q = rbuf(c, 0x30)
    patch(c, 0x41e290, L('new', 1, pop=0, ecx=False, ret=c.rng.choice([0, q, q])))
    patch(c, 0x4e3e70, L('CQuadtree', 1, ret=c.rng.choice([q, R(c)])))
    sz = c.rng.choice([c.rng.uniform(0, 5000), 1000.0, 999.9, float('nan'), -1.0])
    org = bytes(c.rng.getrandbits(8) for _ in range(12))
    def gos(e, r):
        e.calllog.append(('GetOriginAndSize', e.reg('ecx'), ())); e.wbytes(e.arg32(0), org); e.ret(eax=0, argbytes=4, st0=sz)
    def fc0(e, r):
        e.calllog.append(('qt_fc0', e.reg('ecx'), (e.rbytes(e.arg32(0), 12).hex(),))); e.ret(eax=0, argbytes=4)
    patch(c, 0x443080, gos); patch(c, 0x4e4fc0, fc0); patch(c, 0x4e4fe0, L('qt_fe0', 1))
    t = rbuf(c, 0x80); c.emu.w32(t, c.emu.fake_vtable('tg', 0xbd, {0x2f0: L('tg2f0', 1)}))
    n = c.rng.choice([0, 1, 3]); lst = rbuf(c, 0x404 + 4 * n + 4); c.emu.wbytes(lst + 2, struct.pack('<H', n))
    for i in range(n): c.emu.w32(lst + 0x404 + 4 * i, obj(c, 'tree%d' % i, {0x324: L('tree324', 0)}, size=0x10))
    c.emu.w32(t + 0x7b, c.rng.choice([0, lst, lst]))
    return [t]
S(0x442d20, 'ZTreeGroup::CreateDynamicTrees', 'thiscall', None, ret=None, gen=g_442d20)


def g_4c90a0(c):   # CRegisterSceneValName::Init
    mystr_stubs(c)
    patch(c, 0x4e5ea0, L('DBREAD char*', 0, ret=R(c)))
    o = obj(c, 'o', {0x60: L('o60', 2)}, size=0x10)
    scene(c, {0x138: L('scene138', 0, ret=o), 0x4c: L('scene4c', 2, ret=R(c))})
    blk = rbuf(c, 0x10); c.emu.w8(blk, c.rng.choice([4, 0x44, 0xc4, 0x24, 0xff, 5, c.rng.getrandbits(8)]))
    db = rbuf(c, 0x10); c.emu.w32(db, blk)
    g = rbuf(c, 0x10)
    s = obj(c, 'svn', {0x58: L('svn58', 0)}, size=0x60); c.emu.w32(s + 0x44, g)
    return [s, R(c), db]
S(0x4c90a0, 'CRegisterSceneValName::Init', 'thiscall', None, ret=None, gen=g_4c90a0)


NAMES = [b'sewer1', b'sewer2', b'Sewer1', b'', b'sewer10', b'x']
def g_5b1760(c):   # ZSewerControl::SetSewerInfo
    s = rbuf(c, 8 + 0x12 * 19 + 8)
    for i in range(19):
        p = c.emu.alloc(12, 4); c.emu.wbytes(p, c.rng.choice(NAMES) + b'\0'); c.emu.w32(s + 8 + 0x12 * i, p)
    nm = c.emu.alloc(12, 4); c.emu.wbytes(nm, c.rng.choice(NAMES) + b'\0')
    d = rbuf(c, 0x30)
    for o in (0x18, 0x20):
        c.emu.w32(d + o, c.rng.choice([fb(c.rng.uniform(-5, 5)), 0, 0x80000000, fb(1e-30), R(c)]))
    return [s, nm, R(c), rbuf(c, 12), d]
S(0x5b1760, 'ZSewerControl::SetSewerInfo', 'thiscall', None, ret=None, gen=g_5b1760)


def kind_geom(c, f):
    g = rbuf(c, 0x60)
    if f is None: c.emu.w32(g + 0x54, 0)
    else:
        k = rbuf(c, 0x30); c.emu.w32(k + 0x23, f); r = rbuf(c, 0x20); c.emu.w32(r + 0xc, k); c.emu.w32(g + 0x54, r)
    return g
FLAGS = [None, 0x800000, 0x100000, 0x900000, 0x200002, 0]
def g_4449e0(c):   # ZROOM::GetDynamicLightsInRoom
    n = c.rng.randint(0, 5); gs = []
    for i in range(n):
        f = c.rng.choice(FLAGS); g = kind_geom(c, f)
        if f is not None and f & 0x100000:
            r = c.emu.r32(g + 0x54)
            kids = [kind_geom(c, c.rng.choice(FLAGS)) for _ in range(c.rng.randint(0, 3))]; st = {'k': 0}
            def h50(e, rr, kids=kids, st=st):
                p = e.arg32(0); st['k'] += 1; e.calllog.append(('r50', e.reg('ecx'), ()))
                e.w32(p, kids[st['k']] if st['k'] < len(kids) else 0); e.ret(eax=0, argbytes=4)
            c.emu.w32(r, c.emu.fake_vtable('r%d' % i, 0xab, {0x2a8: L('r2a8', 0, ret=c.rng.choice([0x10000, 0, 0x30001])), 0x50: h50}))
            c.emu.w32(r + 8, kids[0] if kids else 0)
        gs.append(g)
    st = {'k': 0}
    def h4c(e, r):
        p = e.arg32(0); e.calllog.append(('t4c', e.reg('ecx'), ())); e.wbytes(p, b'\x22' * 12); st['k'] = 0; e.ret(eax=0, argbytes=4)
    def h5c(e, r):
        p = e.arg32(0); k = st['k']; st['k'] += 1; e.calllog.append(('t5c', e.reg('ecx'), ()))
        e.w32(p, 1 if k < n else 0); e.ret(eax=gs[k] if k < n else R(c), argbytes=4)
    room = rbuf(c, 0xb0); c.emu.w32(room + 0xa8, c.rng.choice([0, obj(c, 'tab', {0x4c: h4c, 0x5c: h5c}, size=0x10)]))
    out = rbuf(c, 0x40); m = c.rng.choice([0, 1, 2, 4, 16])
    return [room, out, c.rng.choice([out + 4 * m, out - 4])]
S(0x4449e0, 'ZROOM::GetDynamicLightsInRoom', 'thiscall', None, ret='eax', gen=g_4449e0)
