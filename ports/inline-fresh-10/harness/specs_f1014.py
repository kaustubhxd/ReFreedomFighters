"""specs_f1014.py - fresh-10 batch 14 (slice 10)."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from h10 import L, obj, rbuf, patch, iat, log_obj


def R(c): return c.rng.getrandbits(32)
def fb(x): return struct.unpack('<I', struct.pack('<f', x))[0]
def hook(c): c.emu.w32(0x7003b0, c.emu.stub_fn('assert', L('assert', 0, ret=R(c), ecx=False)))


def g_578aa0(c):   # ZControllerA::CheckConsoleCommands
    def setter(name):
        def h(e, r):
            e.calllog.append((name, e.reg('ecx'), (e.arg32(0), e.r32(e.reg('ecx') + 0x194)))); e.ret(eax=0, argbytes=4)
        return h
    patch(c, 0x579bd0, setter('SetIV')); patch(c, 0x579b20, setter('SetIH')); patch(c, 0x579a60, setter('SetA'))
    def ub(e, r):
        e.calllog.append(('UpdateButtons', e.reg('ecx'), (e.r32(e.reg('ecx') + 0x194),))); e.ret(eax=0, argbytes=0)
    patch(c, 0x579d20, ub)
    s = rbuf(c, 0x1c0)
    for o in (0x1a8, 0x1ac, 0x1b0):
        c.emu.w32(s + o, c.rng.choice([0xbf800000, 0xbf800000, fb(0.0), fb(1.0), fb(0.5), fb(-0.9), 0x7fc00000, fb(3e9)]))
    return [s]
S(0x578aa0, 'ZControllerA::CheckConsoleCommands', 'thiscall', None, ret=None, gen=g_578aa0)


def g_6041e0(c):   # GUESS OpaqueUserType constructor
    hook(c)
    patch(c, 0x603430, L('OpaqueUserType_t', 2))
    p = rbuf(c, 0x40)
    def alloc(e, r):
        e.calllog.append(('alloc', 0, (e.arg32(0),))); e.ret(eax=p, argbytes=4)
    patch(c, 0x6014a0, alloc)
    grow = c.rng.choice([0, 3, 8, 0x20, 0x21, 0x30])
    def h6c(e, r):
        v = e.arg32(0); b0 = e.r32(v); e.calllog.append(('info6c', e.reg('ecx'), (e.rbytes(v, 12).hex() if False else (e.r32(v) - p, e.r32(v + 4) - p, e.r32(v + 8) - p),)))
        e.w32(v + 4, b0 + grow); e.w32(v + 8, b0 + max(grow, 8)); e.ret(eax=0, argbytes=4)
    info = obj(c, 'info', {0x6c: h6c}, size=0x10)
    t = obj(c, 'tx', {0: L('tx0', 1, ret=R(c))}, size=0x10)
    g = rbuf(c, 0x40); c.emu.w32(g + 0x3c, t); c.emu.w32(0x724278, g)
    def fr(e, r):
        e.calllog.append(('f54f870', 0, (e.arg32(0) - p, e.arg32(1)))); e.ret(eax=0, argbytes=8)
    patch(c, 0x54f870, fr)
    return [rbuf(c, 0x30), info, R(c)]
S(0x6041e0, 'GUESS OpaqueUserType ctor 0x6b97b4', 'thiscall', None, ret='eax', gen=g_6041e0)


WORDS = ['lt', 'gt', 'amp', 'apos', 'quot', 'lT', 'qu', 'aps', 'quox', 'ap', 'xt', 'ampx', 'ag']
def g_6252a0(c):   # expat little2_predefinedEntityName
    w = c.rng.choice(WORDS)
    b = bytearray(w.encode('utf-16-le'))
    if c.rng.random() < 0.15: b[c.rng.randrange(len(b))] ^= c.rng.choice([1, 0x40, 0x80])
    p = c.emu.alloc(len(b) + 8, 4); c.emu.wbytes(p, bytes(b) + b'\0' * 4)
    n = len(b) + c.rng.choice([0, 0, 0, 1, -1])
    return [R(c), p, p + n]
S(0x6252a0, 'expat little2_predefinedEntityName (GUESS)', 'cdecl', None, ret='eax', gen=g_6252a0)


def g_65c3e0(c):   # GUESS state-sorted batch walk
    def lb(name, nargs):
        def h(e, r):
            a = [e.arg32(k) for k in range(nargs)]; a[-1] &= 0xff
            e.calllog.append((name, e.reg('ecx'), tuple(a))); e.ret(eax=R(c), argbytes=4 * nargs)
        return h
    s = rbuf(c, 0x28 + 8 * 12)
    c.emu.w32(s, c.emu.fake_vtable('bw', 0x21, {0x44: L('bw44', 1), 0x7c: lb('bw7c', 1), 0x78: lb('bw78', 1), 0x74: lb('bw74', 2), 0x80: lb('bw80', 2)}))
    n = c.rng.randint(0, 12); c.emu.w32(s + 0x20, n)
    keys = []
    for i in range(n):
        if keys and c.rng.random() < 0.3: k = keys[-1]
        else: k = (c.rng.choice([0, 0x78000000, 0x08000000, 0x10000000]) | c.rng.choice([0, 0x10, 0x7f0]) | c.rng.choice([0, 1, 2, 9, 0xf]))
        if c.rng.random() < 0.05: k = 0xffffffff
        keys.append(k)
        it = rbuf(c, 0x20); x = rbuf(c, 0x30); c.emu.w32(it + 0x14, x); c.emu.w32(it + 8, c.rng.choice([0, R(c)]))
        c.emu.w32(s + 0x28 + 8 * i, k); c.emu.w32(s + 0x2c + 8 * i, it)
    c.emu.w32(s + 0x24, s + 0x28 + 8 * c.rng.randint(0, n))
    return [s, R(c)]
S(0x65c3e0, 'GUESS state-sorted batch walk', 'thiscall', None, ret='al', gen=g_65c3e0)


def g_4f8120(c):   # ZSlider::OnStateChanged
    tv = bytes(c.rng.getrandbits(8) for _ in range(8))
    def h308(e, r):
        e.calllog.append(('sys308', e.reg('ecx'), ())); e.wbytes(e.arg32(0), tv); e.ret(eax=0, argbytes=4)
    sysw = obj(c, 'sys', {0x308: h308, 0x34c: L('sys34c', 5), 0x350: L('sys350', 3)}, size=0x10)
    s = rbuf(c, 0xe0); c.emu.w32(s, c.emu.fake_vtable('sl', 0xd7, {0x2c4: L('GetSystem', 0, ret=sysw), 0x358: L('sl358', 0)}))
    c.emu.w8(s + 0xd3, c.rng.choice([0, 1]))
    myid = c.emu.r32(s + 0xab)
    return [s, c.rng.choice([myid, myid, R(c)]), c.rng.choice([1, 2, 8, 0, 3, R(c)])]
S(0x4f8120, 'ZSlider::OnStateChanged', 'thiscall', None, ret='al', gen=g_4f8120)
