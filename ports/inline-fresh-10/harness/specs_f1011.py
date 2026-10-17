"""specs_f1011.py - fresh-10 batch 11 (slice 10)."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from h10 import L, obj, rbuf, patch, iat, log_obj


def R(c): return c.rng.getrandbits(32)
def fb(x): return struct.unpack('<I', struct.pack('<f', x))[0]
def scene(c, slots, size=0x200):
    s = obj(c, 'scene', slots, size=size); rm = rbuf(c, 0x1b00); c.emu.w32(rm + 0x9b, s); c.emu.w32(0x70039c, rm)
    return s, rm


def g_448220(c):   # GUESS fastcall create geom (vtable 0x67e0c0)
    o = rbuf(c, 0x30); rv = R(c)
    def f(e, r):
        e.calllog.append(('f4472a0', e.reg('ecx'), (e.reg('edx'), e.arg32(0), e.arg32(1)))); e.ret(eax=rv, argbytes=8)
    patch(c, 0x4472a0, f)
    patch(c, 0x45c4b0, L('alloc', 1, pop=0, ecx=False, ret=c.rng.choice([0, o, o])))
    patch(c, 0x45c3a0, L('ZGEOM', 3))
    s, rm = scene(c, {}, size=0xc00); c.emu.w8(s + 0xbad, c.rng.choice([0, 1]))
    return [R(c), R(c), R(c), c.rng.choice([0, 0, R(c)])]
S(0x448220, 'GUESS fastcall create geom 0x67e0c0', 'fastcall', None, ret='eax', gen=g_448220)


def g_4c28e0(c):   # ZSoundSegmentPitch::Save(ZSaveGame*)
    g = obj(c, 'sg', {k: L('g%x' % k, 1) for k in (0x40, 0x44, 0x4c, 0x60)}, size=0x10)
    return [rbuf(c, 0x70), g]
S(0x4c28e0, 'ZSoundSegmentPitch::Save', 'thiscall', None, ret='al', gen=g_4c28e0)


def g_4c95a0(c):   # ZSpin::FrameUpdate()
    s, rm = scene(c, {})
    c.emu.w32(rm + 0x48, fb(c.uniform(0, 0.1)) if hasattr(c, 'uniform') else fb(c.rng.uniform(0, 0.1)))
    clk = R(c); c.emu.w32(rm + 0x40, clk)
    o = rbuf(c, 0x70)
    c.emu.w32(o + 0x5b, (clk - c.rng.choice([0, 0x3ff, 0x400, 0x401, 0x7ff, 0x800, 0x801, R(c)])) & 0xffffffff)
    c.emu.w8(o + 0x58, c.rng.choice([0, 1])); c.emu.w8(o + 0x59, c.rng.choice([0, 1]))
    def vsc(e, r):
        out, src, f = e.reg('ecx'), e.reg('edx'), e.arg32(0)
        b = e.rbytes(src, 12); e.calllog.append(('vscalar', 0, (b.hex(), f)))
        e.wbytes(out, bytes(x ^ (f & 0xff) for x in b)); e.ret(eax=0, argbytes=4)
    mat = bytes(c.rng.getrandbits(8) for _ in range(36))
    def gm(e, r):
        p = e.arg32(0); e.calllog.append(('GetMat', e.reg('ecx'), ())); e.wbytes(p, mat); e.ret(eax=0, argbytes=4)
    def rot(e, r):
        m, v = e.reg('ecx'), e.reg('edx'); mb = e.rbytes(m, 36); vb = e.rbytes(v, 12)
        e.calllog.append(('rot', 0, (mb.hex(), vb.hex()))); e.wbytes(m, bytes(a ^ vb[i % 12] for i, a in enumerate(mb))); e.ret(eax=0, argbytes=0)
    def mlog(name):
        def h(e, r):
            e.calllog.append((name, e.reg('ecx'), (e.rbytes(e.arg32(0), 36).hex(),))); e.ret(eax=0, argbytes=4)
        return h
    patch(c, 0x4e0d40, vsc); patch(c, 0x4db2a0, gm); patch(c, 0x4de7e0, rot)
    geom = obj(c, 'g44', {0x6c: mlog('g6c')}, size=0x10); c.emu.w32(geom + 8, rbuf(c, 0x10)); c.emu.w32(o + 0x44, geom)
    vt = c.emu.fake_vtable('spin', 0x22, {0x68: L('s68', 2), 0x84: mlog('s84')}); c.emu.w32(o, vt)
    return [o]
S(0x4c95a0, 'ZSpin::FrameUpdate', 'thiscall', None, ret=None, gen=g_4c95a0)


def g_5799a0(c):   # ZControllerA::OnWindowOpen(unsigned, bool)
    patch(c, 0x563110, L('VS::OnWindowOpen', 2)); patch(c, 0x579d20, L('UpdateButtons', 0))
    def h198(e, r):
        o, buf, f, n = (e.arg32(k) for k in range(4)); e.calllog.append(('fmt198', 0, (o, f, n)))
        e.wbytes(buf, b'menu %08x\0' % n); e.ret(eax=0, argbytes=0)
    def h284(e, r):
        e.calllog.append(('w284', e.reg('ecx'), (e.rbytes(e.arg32(0), 16).hex(),))); e.ret(eax=R(c), argbytes=4)
    w = obj(c, 'w', {0x284: h284}, size=0x10)
    p = obj(c, 'p', {0x25c: L('p25c', 2, ret=c.rng.choice([0, w, w]))}, size=0x10)
    o = obj(c, 'o', {0x198: h198}, size=0x10)
    f = obj(c, 'f', {0: L('fmt0', 2, ret=R(c))}, size=0x10)
    sysv = c.emu.fake_vtable('sys', 0x66, {0x190: L('sys190', 0, ret=o)})
    s = rbuf(c, 0xb00); c.emu.w32(s + 0xae4, f); rm = rbuf(c, 0x100); c.emu.w32(rm, sysv); c.emu.w32(rm + 0x9b, s); c.emu.w32(0x70039c, rm)
    t = rbuf(c, 0x1a0); c.emu.w32(t + 0x54, p)
    return [t, R(c), R(c)]
S(0x5799a0, 'ZControllerA::OnWindowOpen', 'thiscall', None, ret='al', gen=g_5799a0)


def g_4317a0(c):   # CConfiguration::~CConfiguration()
    patch(c, 0x634273, L('delete', 2, pop=0, ecx=False)); patch(c, 0x4cbec0, L('~MYSTR', 0))
    patch(c, 0x432be0, L('RemoveAllKeyMappings', 0)); patch(c, 0x4cd0e0, L('~STRREFTAB', 0)); patch(c, 0x4cce40, L('f4cce40', 0))
    n = c.rng.randint(0, 4); els = []
    for i in range(n):
        e = rbuf(c, 8)
        if c.rng.random() < 0.3: c.emu.w32(e + 4, 0)
        els.append(e)
    st = {'k': 0}
    def h4c(e, r):
        p = e.arg32(0); e.calllog.append(('lst4c', e.reg('ecx'), ())); e.wbytes(p, b'\x22' * 12); st['k'] = 0; e.ret(eax=0, argbytes=4)
    def h64(e, r):
        k = st['k']; st['k'] += 1; e.calllog.append(('lst64', e.reg('ecx'), ())); e.ret(eax=els[k] if k < n else 0, argbytes=4)
    s = rbuf(c, 0xd0); c.emu.w32(s + 0xac, c.emu.fake_vtable('tab', 0x1a, {0x4c: h4c, 0x64: h64}))
    return [s]
S(0x4317a0, 'CConfiguration::~CConfiguration', 'thiscall', None, ret=None, gen=g_4317a0)


def g_4bcc60(c):   # ZSoundVolumetricSource::Plot()
    def h184(e, r):
        a = [e.arg32(k) for k in range(4)]
        if a[3] in (0x693cc4, 0x693ccc): a += [e.arg32(4), e.arg32(5)]
        e.calllog.append(('plot', 0, tuple(a))); e.ret(eax=0, argbytes=0)
    o = obj(c, 'pr', {0x184: h184}, size=0x10)
    sysv = c.emu.fake_vtable('sys', 0x66, {0x190: L('sys190', 0, ret=o)})
    rm = rbuf(c, 0x100); c.emu.w32(rm, sysv); c.emu.w32(0x70039c, rm)
    s = rbuf(c, 0xe0); c.emu.w32(s + 0x60, c.rng.choice([0, 1, 2, R(c)]))
    for off in (0xd1, 0xd5):
        c.emu.w32(s + off, c.rng.choice([R(c), fb(c.rng.uniform(-50, 50)), 0x7f800001, 0xff800000]))
    return [s]
S(0x4bcc60, 'ZSoundVolumetricSource::Plot', 'thiscall', None, ret=None, gen=g_4bcc60)


def g_606120(c):   # MD5Engine_t::final(MD5_t&)
    def upd(e, r):
        p, n = e.arg32(0), e.arg32(1); me = e.reg('ecx')
        e.calllog.append(('update', me, (p, n, e.rbytes(p, min(n, 8)).hex())))
        e.wbytes(me, bytes((x * 7 + n) & 0xff for x in e.rbytes(me, 16))); e.ret(eax=0, argbytes=8)
    patch(c, 0x606940, upd)
    return [rbuf(c, 0x60), rbuf(c, 0x10)]
S(0x606120, 'MD5Engine_t::final', 'thiscall', None, ret=None, gen=g_606120)


def g_621f60(c):   # expat normal_charRefNumber
    k = c.rng.random()
    if k < 0.4:
        digs = ''.join(c.rng.choice('0123456789abcdefABCDEFxyz!G') for _ in range(c.rng.randint(0, 7)))
        s = b'&#x' + digs.encode() + b';'
    elif k < 0.8:
        s = b'&#' + ''.join(c.rng.choice('0123456789') for _ in range(c.rng.randint(0, 8))).encode() + b';'
    else:
        s = b'&#' + c.rng.choice([b'xd800', b'xDFFF', b'xfffe', b'xffff', b'xFFFD', b'55296', b'x10ffff', b'x110000', b'9', b'10', b'13',
                                  b'x80', b'0', b'x', b'12a', b'\xff\x01', b'-5']) + b';'
    p = c.emu.alloc(len(s) + 4, 4); c.emu.wbytes(p, s + b'\0')
    return [R(c), p]
S(0x621f60, 'expat normal_charRefNumber (GUESS)', 'cdecl', None, ret='eax', gen=g_621f60)


def g_54eca0(c):   # GUESS EAX listener reset
    log_obj(c, 1)
    def kset(e, r):
        a = [e.arg32(k) for k in range(7)]
        e.calllog.append(('KsSet', 0, tuple(a[:5]) + (e.rbytes(a[5], 0x48).hex(), a[6]))); e.ret(eax=c.rng.choice([0, 1, 0x80004005]), argbytes=0x1c)
    s = rbuf(c, 0x60); c.emu.w32(s + 4, 0 if c.rng.random() < 0.2 else obj(c, 'ks', {0x10: kset}, size=0x10))
    return [s]
S(0x54eca0, 'GUESS EAX listener reset', 'thiscall', None, ret=None, gen=g_54eca0)


def g_4a48e0(c):   # ZVertAnim::Command(unsigned short, void*)
    t = obj(c, 'anim', {0xd8: L('animd8', 2)}, size=0x10)
    x = rbuf(c, 0x20); c.emu.w32(x + 0x18, t); rm = rbuf(c, 0x1b00); c.emu.w32(rm + 0x1aa3, x); c.emu.w32(0x70039c, rm)
    g = obj(c, 'g', {0x2c: L('g2c', 0)}, size=0x10)
    v = rbuf(c, 0x70); c.emu.w32(v + 0x44, g); c.emu.w8(v + 0x5e, c.rng.choice([0, 1]))
    end = c.rng.choice([0x401, 0x400, 0x1234, c.rng.getrandbits(16)]); c.emu.w16(v + 0x48, end) if hasattr(c.emu, 'w16') else c.emu.wbytes(v + 0x48, struct.pack('<H', end))
    gid = c.rng.choice([0x2222, c.rng.getrandbits(16)]); c.emu.wbytes(0x7002f8, struct.pack('<H', gid))
    c.emu.w32(v, c.emu.fake_vtable('va', 0x1b, {0x64: L('v64', 1), 0x68: L('v68', 2), 0x3c: L('v3c', 0)}))
    cmd = c.rng.choice([0x401, 0x400, end, gid, R(c) & 0xffff, (R(c) & 0xffff0000) | 0x401])
    return [v, cmd, R(c)]
S(0x4a48e0, 'ZVertAnim::Command', 'thiscall', None, ret='eax', gen=g_4a48e0)
