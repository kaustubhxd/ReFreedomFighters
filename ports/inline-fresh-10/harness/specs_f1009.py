"""specs_f1009.py - fresh-10 batch 9: geom destructors and factories, loads, key lookup, zip EOCD (slice 10)."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from h10 import L, obj, rbuf, patch, iat, log_obj


def R(c): return c.rng.getrandbits(32)


def scene(c, slots, size=0x200):
    s = obj(c, 'scene', slots, size=size); rm = rbuf(c, 0x100); c.emu.w32(rm + 0x9b, s); c.emu.w32(0x70039c, rm)
    return s


def dtor_gen(mystr=False):
    def g(c):
        scene(c, {0x34: L('scene34', 1)})
        patch(c, 0x4690b0, L('lort', 2, pop=0, ecx=False))
        if mystr: patch(c, 0x4cbec0, L('~MYSTR', 0))
        c.emu.w32(0x7003b0, c.emu.stub_fn('assert', L('assert', 0, ret=R(c), ecx=False)))
        return [rbuf(c, 0x100), c.rng.choice([0, 1, 4, 5, 3, 7, R(c)])]
    return g
S(0x4a79a0, 'ZGeomSpawn::~ZGeomSpawn', 'thiscall', None, ret='eax', gen=dtor_gen())
S(0x4ca9a0, 'ZScrollTexture::~ZScrollTexture', 'thiscall', None, ret='eax', gen=dtor_gen())
S(0x4b1ae0, 'CExternCutSequenceCommand::~CExternCutSequenceCommand', 'thiscall', None, ret='eax', gen=dtor_gen(True))


def fac_gen(c):
    o = rbuf(c, 0x80)
    f = obj(c, 'fac', {0x44: L('fac44', 1, ret=c.rng.choice([0, o, o]))}, size=0x10)
    s = rbuf(c, 0x20); c.emu.w32(s + 8, f); rm = rbuf(c, 0x100); c.emu.w32(rm + 0x9b, s); c.emu.w32(0x70039c, rm)
    patch(c, 0x469870, L('base469870', 0))
    return [R(c)]
for a, vt in ((0x4ae520, 0x690cc0), (0x4be7e0, 0x693028), (0x4caae0, 0x69523c), (0x4c87e0, 0x694d40)):
    S(a, 'GUESS scene create vtable 0x%x' % vt, 'thiscall', None, ret='eax', gen=fac_gen)


def g_5eef20(c):   # CMessageBomb::Load(ZLoadGame*)
    vals = [R(c), R(c)]; st = {'k': 0}
    def h40(e, r):
        p = e.arg32(0); k = st['k']; st['k'] += 1; e.calllog.append(('g40', e.reg('ecx'), ()))
        e.w32(p, vals[k % 2]); e.ret(eax=R(c), argbytes=4)
    g = obj(c, 'lg', {0x68: L('g68', 1), 0x40: h40, 0x48: L('g48', 1)}, size=0x10)
    patch(c, 0x5eecd0, L('CreateSprites', 0))
    o = rbuf(c, 0x30)
    for i, off in enumerate((4, 8, 0xc)): c.emu.w32(o + off, obj(c, 'spr%d' % i, {0xc: L('spr%dc' % i, 1)}, size=0x10))
    return [o, g]
S(0x5eef20, 'CMessageBomb::Load', 'thiscall', None, ret=None, gen=g_5eef20)


NAMES = [b'jump', b'fire', b'Jump', b'crouch', b'fire2']
def g_432560(c):   # CConfiguration::GetKeyMapping(const char*, const SActionOverride*)
    n = c.rng.randint(0, 6); els = []
    for i in range(n):
        e = rbuf(c, 0x10); nm = c.rng.choice(NAMES); sp = c.emu.alloc(16, 4); c.emu.wbytes(sp, nm + b'\0'); c.emu.w32(e, sp); els.append(e)
    st = {'k': 0}
    def h4c(e, r):
        p = e.arg32(0); e.calllog.append(('lst4c', e.reg('ecx'), ())); e.wbytes(p, b'\x22' * 12); st['k'] = 0; e.ret(eax=0, argbytes=4)
    def h64(e, r):
        k = st['k']; st['k'] += 1; e.calllog.append(('lst64', e.reg('ecx'), ())); e.ret(eax=els[k] if k < n else 0, argbytes=4)
    def wcmp(e, _):
        a, b = e.reg('ecx'), e.reg('edx')
        sa = e.rbytes(a, 16); sa = sa[:sa.index(0)]; sb = e.rbytes(b, 16); sb = sb[:sb.index(0)]
        e.calllog.append(('striwcmp', 0, (sa, sb)))
        e.ret(eax=0 if sa.lower() == sb.lower() else c.rng.choice([1, 0xffffffff]), argbytes=0)
    patch(c, 0x4cc850, wcmp)
    self = rbuf(c, 0x100); vt = c.emu.fake_vtable('lst', 0x1a, {0x4c: h4c, 0x64: h64}); c.emu.w32(self + 0x84, vt)
    nm = c.emu.alloc(16, 4); c.emu.wbytes(nm, c.rng.choice(NAMES) + b'\0')
    ovr = c.rng.choice([0, R(c)] + els)
    return [self, nm, ovr]
S(0x432560, 'CConfiguration::GetKeyMapping', 'thiscall', None, ret='eax', gen=g_432560)


def g_5510e0(c):   # Signature_fff_EventTranslator_t::handleEventTranslation (stdcall)
    st = {'k': 0}
    def h3d0(e, r):
        e.calllog.append(('f5003d0', e.reg('ecx'), (e.arg32(0),))); e.ret(eax=0x30000000 + e.arg32(0) * 0x40, argbytes=4)
    patch(c, 0x5003d0, h3d0); patch(c, 0x500360, L('f500360', 1))
    a = rbuf(c, 0x10)
    ev = obj(c, 'ev', {0x4c: L('ev4c', 0, ret=a)}, size=0x10)
    f = obj(c, 'fac', {0x18: L('fac18', 1, ret=c.rng.choice([0, ev, ev]))}, size=0x10)
    d = rbuf(c, 0x10)
    return [f, R(c), d]
S(0x5510e0, 'Signature_fff_EventTranslator_t::handleEventTranslation', 'stdcall', None, ret='eax', gen=g_5510e0)


def g_5708a0(c):   # CSewerMenu::Init()
    patch(c, 0x562440, L('ZVideoSelector::Init', 0))
    o = obj(c, 'o', {0x60: L('o60', 2)}, size=0x10)
    scene(c, {0x138: L('scene138', 0, ret=o), 0x4c: L('scene4c', 2, ret=R(c))})
    s = rbuf(c, 0x1b0); c.emu.w8(s + 0x1a3, c.rng.choice([0, 1, 0x80]))
    return [s]
S(0x5708a0, 'CSewerMenu::Init', 'thiscall', None, ret=None, gen=g_5708a0)


def g_4d7ba0(c):   # FsZip_t::writeEOCD()
    rets = [c.rng.choice([4, 0x12, 0, 3, R(c)]) for _ in range(4)]; st = {'k': 0}
    def w18(e, r):
        p, n, h = e.arg32(0), e.arg32(1), e.arg32(2); k = st['k']; st['k'] += 1
        e.calllog.append(('write', e.reg('ecx'), (e.rbytes(p, n & 0xff).hex(), n, h)))
        e.ret(eax=(n if c.rng.random() < 0.6 else rets[k % 4]), argbytes=12)
    s = rbuf(c, 0x80); c.emu.w32(s + 0x15, obj(c, 'file', {0x18: w18}, size=0x10))
    return [s]
S(0x4d7ba0, 'FsZip_t::writeEOCD', 'thiscall', None, ret=None, gen=g_4d7ba0)


def g_4d8e60(c):   # GUESS: empty a list of entries, each with an item sublist
    patch(c, 0x634273, L('delete', 2, pop=0, ecx=False))
    n = c.rng.randint(0, 4); ents = []
    for i in range(n):
        e = rbuf(c, 0x20)
        if c.rng.random() < 0.25: c.emu.w32(e + 0x11, 0)
        else:
            items = [rbuf(c, 8) for _ in range(c.rng.randint(0, 3))]; st = {'k': 0}
            def h4c(em, r, st=st):
                p = em.arg32(0); em.calllog.append(('s4c', em.reg('ecx'), ())); em.wbytes(p, b'\x22' * 12); st['k'] = 0; em.ret(eax=0, argbytes=4)
            def h64(em, r, st=st, items=items):
                k = st['k']; st['k'] += 1; em.calllog.append(('s64', em.reg('ecx'), ())); em.ret(eax=items[k] if k < len(items) else 0, argbytes=4)
            c.emu.w32(e + 0x11, obj(c, 'sub%d' % i, {0x4c: h4c, 0x64: h64, 0: L('subdtor', 1)}, size=0x10))
        ents.append(e)
    end = c.rng.choice([0, R(c)])
    lst = c.emu.alloc(0x10, 4); seq = ents + [end]; st2 = {'k': 0}
    def rm4(e, r):
        st2['k'] += 1; e.calllog.append(('lst4', e.reg('ecx'), (e.arg32(0),)))
        e.w32(lst + 4, seq[min(st2['k'], len(seq) - 1)]); e.ret(eax=0, argbytes=4)
    c.emu.w32(lst, c.emu.fake_vtable('lst', 2, {4: rm4})); c.emu.w32(lst + 4, seq[0]); c.emu.w32(lst + 8, end)
    s = rbuf(c, 0x10); c.emu.w32(s, lst); c.emu.w8(s + 4, c.rng.choice([0, 0, 1]))
    return [s]
S(0x4d8e60, 'GUESS clear list with sublists', 'thiscall', None, ret=None, gen=g_4d8e60)


def g_490de0(c):   # ZEngineDataBase::GetSoundDataSize()
    sp = rbuf(c, 0x20)
    def calc(e, r):
        out, nm = e.arg32(0), e.arg32(1); e.calllog.append(('CalcCacheFileName', e.reg('ecx'), (nm,)))
        e.w32(out, sp); e.ret(eax=out, argbytes=8)
    patch(c, 0x48c4b0, calc); patch(c, 0x4cbec0, L('~MYSTR', 0))
    c.emu.w32(0x700394, obj(c, 'fs', {0x30: L('fs30', 2, ret=R(c))}, size=0x10))
    return [rbuf(c, 0x10)]
S(0x490de0, 'ZEngineDataBase::GetSoundDataSize', 'thiscall', None, ret='eax', gen=g_490de0)


def g_433d20(c):   # GUESS ctor vtable 0x67a2a4
    tag = R(c)
    def mctor(e, r):
        e.calllog.append(('MYSTR', 0, (e.arg32(0),))); e.w32(e.reg('ecx'), tag); e.ret(eax=e.reg('ecx'), argbytes=4)
    def massign(e, r):
        src = e.arg32(0); e.calllog.append(('MYSTR=', e.reg('ecx'), (e.r32(src),))); e.ret(eax=e.reg('ecx'), argbytes=4)
    def mdtor(e, r):
        e.calllog.append(('~MYSTR', 0, (e.r32(e.reg('ecx')),))); e.ret(eax=0, argbytes=0)
    patch(c, 0x431630, L('CConfiguration', 0)); patch(c, 0x4cbe80, mctor); patch(c, 0x4cbee0, massign); patch(c, 0x4cbec0, mdtor)
    return [rbuf(c, 0x100)]
S(0x433d20, 'GUESS CConfiguration-derived ctor 0x67a2a4', 'thiscall', None, ret='eax', gen=g_433d20)
