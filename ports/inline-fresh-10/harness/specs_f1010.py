"""specs_f1010.py - fresh-10 batch 10: frees, autosave, library unload, data-block copy, loads (slice 10)."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from h10 import L, obj, rbuf, patch, iat, log_obj


def R(c): return c.rng.getrandbits(32)
def hook(c): c.emu.w32(0x7003b0, c.emu.stub_fn('assert', L('assert', 0, ret=R(c), ecx=False)))
def scene(c, slots, size=0x200):
    s = obj(c, 'scene', slots, size=size); rm = rbuf(c, 0x100); c.emu.w32(rm + 0x9b, s); c.emu.w32(0x70039c, rm)
    return s, rm


def g_403ee0(c):   # GUESS free struct with a 17x11 table
    iat(c, 0x6762ec, 'free', 1, pop=0)
    p = rbuf(c, 0x40)
    for off in (0x14, 0x18, 0x1c):
        if c.rng.random() < 0.3: c.emu.w32(p + off, 0)
    if c.rng.random() < 0.3: c.emu.w32(p + 8, 0)
    else:
        t = rbuf(c, 17 * 4)
        for r in range(17): c.emu.w32(t + 4 * r, rbuf(c, 11 * 4))
        c.emu.w32(p + 8, t)
    return [c.rng.choice([p, p, p, 0])]
S(0x403ee0, 'GUESS free struct with 17x11 table', 'cdecl', None, ret=None, gen=g_403ee0)


def g_575ee0(c):   # ZSubZoneMap::AutoSave()
    patch(c, 0x59cb60, L('SetNextScene', 1)); patch(c, 0x5ae710, L('SaveRaw', 1)); patch(c, 0x562bc0, L('LoadLevel', 0))
    patch(c, 0x561be0, L('AutoSaveEnabled', 0, ret=c.rng.choice([0, 1, 0x100, 0xffffff01])))
    o = rbuf(c, 0x100)
    if c.rng.random() < 0.5: c.emu.w32(o + 0x88, struct.unpack('<I', struct.pack('<f', c.rng.uniform(-1e4, 1e4)))[0])
    s, rm = scene(c, {0x60: L('scene60', 1, ret=c.rng.choice([0, o, o]))})
    c.emu.w32(rm + 0x40, c.rng.choice([R(c), c.rng.randint(0, 100000)]))
    w = obj(c, 'win', {0xd0: L('wind0', 1)}, size=0x240)
    return [w]
S(0x575ee0, 'ZSubZoneMap::AutoSave', 'thiscall', None, ret=None, gen=g_575ee0)


def g_427020(c):   # ZSysFileGC::FreeLib(long)
    patch(c, 0x634273, L('delete', 2, pop=0, ecx=False)); iat(c, 0x6760b0, 'FreeLibrary', 1, ret=R(c))
    hs = [R(c) for _ in range(3)]; n = c.rng.randint(0, 4); els = []
    for i in range(n):
        e = rbuf(c, 0x14); c.emu.w32(e + 4, c.rng.choice(hs)); c.emu.w32(e + 8, c.rng.choice([1, 1, 2, 0, R(c)]))
        for off in (0xc, 0x10):
            c.emu.w32(e + off, 0 if c.rng.random() < 0.3 else obj(c, 'o%x' % off, {0x14: L('o%x_14' % off, 1)}, size=0x10))
        els.append(e)
    st = {'k': 0}
    def h4c(e, r):
        p = e.arg32(0); e.calllog.append(('lst4c', e.reg('ecx'), ())); e.wbytes(p, b'\x22' * 12); st['k'] = 0; e.ret(eax=0, argbytes=4)
    def h64(e, r):
        p = e.arg32(0); k = st['k']; st['k'] += 1; e.calllog.append(('lst64', e.reg('ecx'), ())); e.w32(p, k)
        e.ret(eax=els[k] if k < n else 0, argbytes=4)
    def h44(e, r):
        p = e.arg32(0); e.calllog.append(('lst44', e.reg('ecx'), (e.r32(p),))); e.ret(eax=0, argbytes=4)
    s = rbuf(c, 0x120); c.emu.w32(s + 0x10c, 0 if c.rng.random() < 0.15 else obj(c, 'lst', {0x4c: h4c, 0x64: h64, 0x44: h44}, size=0x10))
    return [s, c.rng.choice(hs + [R(c)])]
S(0x427020, 'ZSysFileGC::FreeLib', 'thiscall', None, ret='al', gen=g_427020)


def g_4ff920(c):   # GUESS destructor body: three vectors
    patch(c, 0x54f870, L('f54f870', 2)); patch(c, 0x41e2c0, L('f41e2c0', 1, pop=0, ecx=False))
    s = rbuf(c, 0x50)
    for v in (0x38, 0x1c, 4):
        b = c.rng.choice([0, R(c), 0x1000]); c.emu.w32(s + v, b)
        c.emu.w32(s + v + 8, c.rng.choice([b, (b + c.rng.randint(1, 64)) & 0xffffffff, R(c)]))
    return [s]
S(0x4ff920, 'GUESS free three vectors', 'thiscall', None, ret=None, gen=g_4ff920)


def g_4f4160(c):   # ZWINPIC::CopyDataBlock(DBLK*)
    n = c.rng.randint(0, 3); m = c.rng.randint(0, 4)
    t = rbuf(c, 4 + n * 40 + 4 + m * 4 + m * 8 + 8)
    c.emu.w32(t, n); q = t + 4 + n * 40; c.emu.w32(q, m)
    for i in range(m): c.emu.w32(q + 4 + m * 4 + i * 8 + 4, c.rng.randint(0, 5))
    patch(c, 0x4ef660, L('ZWINOBJ::CopyDataBlock', 1)); patch(c, 0x4e1b30, L('NextBlock', 0))
    idv = R(c)
    def get(e, r):
        p = e.arg32(0); e.calllog.append(('Get', e.reg('ecx'), (e.r32(p), e.arg32(1)))); e.w32(p, idv); e.ret(eax=1, argbytes=8)
    patch(c, 0x4e12e0, get)
    tab = obj(c, 'tab', {0xc: L('tabc', 1, ret=t)}, size=0x10)
    x = rbuf(c, 0x20); c.emu.w32(x + 0x18, tab); rm = rbuf(c, 0x1b00); c.emu.w32(rm + 0x1aa3, x); c.emu.w32(0x70039c, rm)
    w = obj(c, 'pic', {0x228: L('pic228', 0), 0x244: L('pic244', 0)}, size=0xa0)
    return [w, rbuf(c, 0x10)]
S(0x4f4160, 'ZWINPIC::CopyDataBlock', 'thiscall', None, ret=None, gen=g_4f4160)


def g_5ff960(c):   # GUESS check 16-byte header and two dwords
    hook(c); s = rbuf(c, 0x30)
    hdr = c.emu.rbytes(s + 0x18, 16)
    if c.rng.random() < 0.5:
        k = c.rng.randint(0, 15); hdr = hdr[:k] + bytes([hdr[k] ^ 1]) + hdr[k + 1:]
    vals = [c.emu.r32(s + 8) if c.rng.random() < 0.5 else R(c), c.emu.r32(s + 0xc) if c.rng.random() < 0.5 else R(c)]; st = {'k': 0}
    def h70(e, r):
        p = e.arg32(0); e.calllog.append(('s70', e.reg('ecx'), (e.arg32(1),))); e.wbytes(p, hdr); e.ret(eax=0, argbytes=8)
    def h5c(e, r):
        p = e.arg32(0); k = st['k']; st['k'] += 1; e.calllog.append(('s5c', e.reg('ecx'), ())); e.w32(p, vals[k % 2]); e.ret(eax=0, argbytes=4)
    return [s, obj(c, 'strm', {0x70: h70, 0x5c: h5c}, size=0x10)]
S(0x5ff960, 'GUESS check header', 'thiscall', None, ret=None, gen=g_5ff960)


def g_4b23a0(c):
    scene(c, {0x34: L('scene34', 1)}); patch(c, 0x4690b0, L('lort', 2, pop=0, ecx=False)); patch(c, 0x4cbec0, L('~MYSTR', 0)); hook(c)
    return [rbuf(c, 0x100), c.rng.choice([0, 1, 4, 5, 3, 7, R(c)])]
S(0x4b23a0, 'CCutSequenceSoundStartStop::~CCutSequenceSoundStartStop', 'thiscall', None, ret='eax', gen=g_4b23a0)


def g_4b5be0(c):   # CCutSequenceSoundStartStop::Load(ZLoadGame*)
    hook(c)
    g = obj(c, 'lg', {k: L('g%x' % k, 1) for k in (0x40, 0x48, 0x50, 0x58)}, size=0x10)
    return [obj(c, 'ss', {0x98: L('ss98', 1)}, size=0xa0), g]
S(0x4b5be0, 'CCutSequenceSoundStartStop::Load', 'thiscall', None, ret='al', gen=g_4b5be0)


def g_4804e0(c):   # ZLightOverlay::InitFeedBackSprite()
    a = rbuf(c, 8); b = rbuf(c, 0x44); seq = [a, b]; st = {'k': 0}
    def nw(e, r):
        k = st['k']; st['k'] += 1; e.calllog.append(('new', 0, (e.arg32(0),))); e.ret(eax=seq[k % 2], argbytes=0)
    patch(c, 0x41e290, nw)
    s = rbuf(c, 0x90)
    c.emu.w32(s + 0x1c, c.rng.choice([R(c), struct.unpack('<I', struct.pack('<f', c.rng.uniform(-100, 100)))[0]]))
    return [s]
S(0x4804e0, 'ZLightOverlay::InitFeedBackSprite', 'thiscall', None, ret=None, gen=g_4804e0)


def g_447d20(c):   # GUESS fastcall create geom (vtable 0x67e790)
    o = rbuf(c, 0x30)
    rv = R(c)
    def f446(e, r):
        e.calllog.append(('f446f30', e.reg('ecx'), (e.reg('edx'), e.arg32(0), e.arg32(1)))); e.ret(eax=rv, argbytes=8)
    patch(c, 0x446f30, f446)
    patch(c, 0x45c4b0, L('alloc', 1, pop=0, ecx=False, ret=c.rng.choice([0, o, o])))
    patch(c, 0x45c3a0, L('ZGEOM', 3))
    s, rm = scene(c, {}, size=0xc00); c.emu.w8(s + 0xbad, c.rng.choice([0, 1]))
    return [R(c), R(c), R(c), c.rng.choice([0, 0, R(c)])]
S(0x447d20, 'GUESS fastcall create geom 0x67e790', 'fastcall', None, ret='eax', gen=g_447d20)
