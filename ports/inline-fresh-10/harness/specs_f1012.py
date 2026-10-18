"""specs_f1012.py - fresh-10 batch 12 (slice 10)."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from h10 import L, obj, rbuf, patch, iat, log_obj


def R(c): return c.rng.getrandbits(32)
def fb(x): return struct.unpack('<I', struct.pack('<f', x))[0]
def scene(c, slots, size=0x200):
    s = obj(c, 'scene', slots, size=size); rm = rbuf(c, 0x1b00); c.emu.w32(rm + 0x9b, s); c.emu.w32(0x70039c, rm)
    return s, rm


def g_526f20(c):   # CPullToValueAccel::CalcDistance
    log_obj(c, 1)
    d = c.rng.choice([c.rng.uniform(-10, 1e5), 1e38, float('inf')])
    def h2c(e, r):
        e.calllog.append(('s2c', e.reg('ecx'), ())); e.ret(eax=R(c), argbytes=0, st0=d)
    s = rbuf(c, 0x30); c.emu.w32(s, c.emu.fake_vtable('pull', 0xc, {0x2c: h2c}))
    c.emu.w32(s + 0x19, c.rng.choice([0, 0, 1, R(c)]))
    c.emu.w32(s + 0x25, c.rng.choice([fb(c.rng.uniform(-10, 10)), fb(c.rng.uniform(-1e-4, 1e-4)), fb(0.0001220703125), R(c), 0x7fc00000]))
    c.emu.w32(s + 0x10, c.rng.choice([fb(c.rng.uniform(-300, 300)), R(c), 0x80000000]))
    return [s, R(c), R(c)]
S(0x526f20, 'CPullToValueAccel::CalcDistance', 'thiscall', None, ret=None, gen=g_526f20, abi_mine=None)


def g_49a160(c):   # ZSaveGame::AddRefTabRaw(REFTAB*)
    b1 = rbuf(c, 0x80) + 8; b2 = rbuf(c, 0x80) + 8
    c.emu.w32(b1 - 8, c.rng.choice([0x40, 0xe0000040, 0x10])); c.emu.w32(b2 - 8, c.rng.choice([0x40, 0x20000040, 0x8]))
    s, rm = scene(c, {0x17c: L('s17c', 0, ret=c.rng.choice([b1, b1 - 4, R(c)])), 0x180: L('s180', 0, ret=c.rng.choice([b2, R(c)]))}, size=0x1d00)
    c.emu.w32(s + 0x1c5d, c.rng.choice([b1, 0])); c.emu.w32(s + 0x44, c.rng.choice([b2, 0]))
    t = obj(c, 'tab', {0x14: L('t14', 1, ret=c.rng.choice([0, 1, 0x100, 0xffffff01])), 0x10: L('t10', 1, ret=R(c))}, size=0x10)
    x = rbuf(c, 0x20); c.emu.w32(x + 0x18, t); c.emu.w32(rm + 0x1aa3, x)
    p = c.rng.choice([0, b1, b1 + c.rng.randint(0, 0x50), b1 - 1, b2 + c.rng.randint(0, 0x50), b2 + 0x40, R(c)])
    return [obj(c, 'sg', {0xc: L('sgc', 1)}, size=0x10), p]
S(0x49a160, 'ZSaveGame::AddRefTabRaw', 'thiscall', None, ret=None, gen=g_49a160)


def g_600860(c):   # GUESS serialise opaque refs
    patch(c, 0x5fa220, L('getOpaqueObjectIndex', 1, retf=lambda e, a: (a[0] * 3 + 1) & 0xffffffff))
    x = rbuf(c, 0xa4); off = c.rng.randint(0, 3) * 4; c.emu.w32(x + 0x9e, off)
    def mk(depth):
        o = rbuf(c, 0xa0)
        base = 0x10 * c.rng.randint(0, 3); c.emu.w32(o + 0x98, base)
        for f in (0x84, 0x80):
            n = c.rng.randint(0, 4); l = rbuf(c, base + 4 + 6 * n + 4)
            c.emu.w32(l + base, n)
            for i in range(n): c.emu.w32(l + base + 4 + 6 * i, rbuf(c, 0x10))
            c.emu.w32(o + f, l)
        c.emu.w32(o + 0x9c, mk(depth - 1) if depth > 0 and c.rng.random() < 0.6 else 0)
        return o
    return [mk(2), obj(c, 'w', {0x2c: L('w2c', 1)}, size=0x10), x, rbuf(c, 0x10)]
S(0x600860, 'GUESS serialise opaque refs', 'thiscall', None, ret=None, gen=g_600860)


def g_4f9520(c):   # GUESS xor-swap n bytes
    buf = rbuf(c, 0x400)
    n = c.rng.choice([0, 1, 3, 4, 7, 31, 32, 33, 64, 100, 131, c.rng.randint(0, 300)])
    a = buf + 0x40 + c.rng.randint(0, 0x100)
    b = c.rng.choice([buf + c.rng.randint(0, 0x100), a + c.rng.randint(-40, 40), a + n * 4 // 4 - c.rng.randint(1, 6), rbuf(c, 0x200)])
    return [a, b, n]
S(0x4f9520, 'GUESS xor-swap memory', 'fastcall', None, ret=None, gen=g_4f9520)


def g_56fea0(c):   # CSewerMenu::CSewerMenu()
    patch(c, 0x561020, L('CBaseWindow', 0))
    scene(c, {0x114: L('RegisterZMsg', 4, retf=lambda e, a: (a[3] * 0x10001 + 0xabcd0000) & 0xffffffff)})
    return [rbuf(c, 0x240)]
S(0x56fea0, 'CSewerMenu::CSewerMenu', 'thiscall', None, ret='eax', gen=g_56fea0)


def g_4f3b20(c):   # ZWINDOWS::UpdateMouse()
    def v2s(e, r):
        p, f = e.reg('ecx'), e.arg32(0); e.calllog.append(('v2scalar', 0, (e.rbytes(p, 8).hex(), f)))
        e.wbytes(p, bytes(x ^ (f & 0xff) for x in e.rbytes(p, 8))); e.ret(eax=0, argbytes=4)
    def v2a(e, r):
        p, q = e.reg('ecx'), e.reg('edx'); e.calllog.append(('v2add', 0, (e.rbytes(p, 8).hex(), e.rbytes(q, 8).hex())))
        e.wbytes(p, bytes(x ^ y for x, y in zip(e.rbytes(p, 8), e.rbytes(q, 8)))); e.ret(eax=0, argbytes=0)
    ln = c.rng.choice([0.0, -0.0, 1.5, float('nan')])
    def v2l(e, r):
        e.calllog.append(('v2len', 0, (e.rbytes(e.reg('ecx'), 8).hex(),))); e.ret(eax=R(c), argbytes=0, st0=ln)
    patch(c, 0x4dffb0, v2s); patch(c, 0x4dfd80, v2a); patch(c, 0x4dfda0, v2l)
    tv = bytes(c.rng.getrandbits(8) for _ in range(8))
    def h308(e, r):
        e.calllog.append(('w308', e.reg('ecx'), ())); e.wbytes(e.arg32(0), tv); e.ret(eax=0, argbytes=4)
    def h304(e, r):
        e.calllog.append(('w304', e.reg('ecx'), (e.rbytes(e.arg32(0), 8).hex(),))); e.ret(eax=0x5a5a0304, argbytes=4)
    rm = rbuf(c, 0xa00); c.emu.w32(0x70039c, rm)
    for o in (0x9e7, 0x9eb): c.emu.w32(rm + o, fb(c.rng.uniform(0, 640)))
    w = rbuf(c, 0x640); c.emu.w32(w, c.emu.fake_vtable('win', 0xc4, {0x308: h308, 0x304: h304}))
    for o in (0x7f, 0x83): c.emu.w32(w + o, c.rng.choice([fb(c.rng.uniform(0, 640)), c.emu.r32(rm + 0x9e7 + (o - 0x7f))]))
    c.emu.w8(w + 0x63b, c.rng.choice([0, 1]))
    return [w]
S(0x4f3b20, 'ZWINDOWS::UpdateMouse', 'thiscall', None, ret='eax', gen=g_4f3b20)


def g_656c60(c):   # GUESS spot light cone
    i = rbuf(c, 0x40)
    a24 = c.rng.uniform(-2, 2); a28 = c.rng.choice([a24, c.rng.uniform(-2, 2)])
    c.emu.w32(i + 0x24, fb(a24)); c.emu.w32(i + 0x28, fb(a28))
    c.emu.w32(i + 0x18, fb(c.rng.uniform(0, 50))); c.emu.w32(i + 0x1c, fb(c.rng.uniform(0, 50)))
    return [rbuf(c, 0x40), i]
S(0x656c60, 'GUESS spot light cone setup', 'stdcall', None, ret=None, gen=g_656c60)


def g_630ce0(c):   # zlib pqdownheap
    s = rbuf(c, 0x1450 + 0x240)
    n = c.rng.randint(1, 20); syms = c.rng.sample(range(0x100), n + 1)
    for i, v in enumerate(syms): c.emu.w32(s + 0xb54 + 4 * i, v)
    c.emu.w32(s + 0x1448, n)
    tree = rbuf(c, 0x400)
    for k in range(0x100):
        c.emu.wbytes(tree + 4 * k, struct.pack('<H', c.rng.choice([c.rng.randint(0, 5), c.rng.getrandbits(16)])))
        c.emu.w8(s + 0x1450 + k, c.rng.randint(0, 3))
    return [s, tree, c.rng.randint(1, n)]
S(0x630ce0, 'zlib pqdownheap', 'cdecl', None, ret=None, gen=g_630ce0)


def g_4269e0(c):   # ZSysFileGC::GetFreeDiskSpace
    patch(c, 0x4cc5f0, L('Length', 0, ret=c.rng.choice([0, 5])))
    def s140(e, r):
        p = e.arg32(0); e.calllog.append(('sys140', e.reg('ecx'), ())); e.w32(p, 0x11223344); e.ret(eax=p, argbytes=4)
    def assign(e, r):
        e.calllog.append(('MYSTR=', e.reg('ecx'), (e.r32(e.arg32(0)),))); e.w32(e.reg('ecx'), 0x5500aa00); e.ret(eax=e.reg('ecx'), argbytes=4)
    def dtor(e, r):
        e.calllog.append(('~MYSTR', 0, (e.r32(e.reg('ecx')),))); e.ret(eax=0, argbytes=0)
    patch(c, 0x4cbee0, assign); patch(c, 0x4cbec0, dtor)
    o = obj(c, 'o', {0x198: L('fmt198', 7, pop=0, ecx=False)}, size=0x10)
    rm = rbuf(c, 0x100); c.emu.w32(rm, c.emu.fake_vtable('sys', 0x66, {0x140: s140, 0x190: L('sys190', 0, ret=o)})); c.emu.w32(0x70039c, rm)
    return [rbuf(c, 0x90), R(c), R(c), R(c)]
S(0x4269e0, 'ZSysFileGC::GetFreeDiskSpace', 'thiscall', None, ret=None, gen=g_4269e0)


def g_56df60(c):   # CMultiplayerStat::OnWindowOpen
    for a, n in ((0x563a50, 'SetupScanLines'), (0x56e050, 'UpdateCharObjs')): patch(c, a, L(n, 0))
    patch(c, 0x563110, L('VS::OnWindowOpen', 2)); patch(c, 0x4f2f60, L('SetActionMap', 1))
    osd = obj(c, 'osd', {0x88: L('osd88', 1)}, size=0x10)
    patch(c, 0x589c20, L('GetGameOSD', 1, retf=lambda e, a: osd if (a[0] * 7 + 3) % 3 else 0))
    gd = rbuf(c, 0x2c60)
    for i in range(4): c.emu.w32(gd + 0x2c3d + 4 * i, c.rng.choice([0, R(c)]))
    c.emu.w32(0x7003b8, gd)
    scene(c, {0x114: L('RegisterZMsg', 4, ret=R(c))})
    g = obj(c, 'g44', {0x130: L('SendCommand', 3)}, size=0x10)
    p = rbuf(c, 0x13300)
    w = rbuf(c, 0x100); c.emu.w32(w, c.emu.fake_vtable('mps', 0x22, {0x84: L('GetSystem', 0, ret=R(c))}))
    c.emu.w32(w + 0x44, g); c.emu.w32(w + 0x94, c.rng.choice([0, p]))
    return [w, R(c), c.rng.choice([0, 1, 0x100, R(c)])]
S(0x56df60, 'CMultiplayerStat::OnWindowOpen', 'thiscall', None, ret='al', gen=g_56df60)
