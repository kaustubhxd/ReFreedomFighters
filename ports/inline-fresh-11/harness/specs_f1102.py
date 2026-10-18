"""specs_f1102.py - fresh-11 batch 2: slice-11 functions of 53 to 90 bytes."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from h11 import L, obj, rbuf, fbuf, patch, log_obj


def r32(c): return c.rng.getrandbits(32)


def eng9b(c, slots, size=0x100):
    o = obj(c, 'eng9b', slots, size=size)
    eng = rbuf(c, 0x200)
    c.emu.w32(eng + 0x9b, o)
    c.emu.w32(0x70039c, eng)
    return o


def g_4b5970(c):
    patch(c, 0x6352f0, L('GetInput', 1, ret=r32(c)))
    o = obj(c, 'self', {0x98: L('vt98', 1, ret=r32(c)), 0x68: L('vt68', 2, ret=r32(c))})
    return [o]
S(0x4b5970, 'CCutSequenceSoundStartStop::Init', 'thiscall', None, ret='eax', gen=g_4b5970)


def g_60fd70(c):
    d = obj(c, 'dev', {0xc8: L('SetState', 3, ret=r32(c), ecx=False)})
    c.emu.w32(0x724a00, d)
    a = r32(c)
    c.emu.w32(0x72496c, a if c.rng.random() < 0.4 else r32(c))
    return [a, r32(c)]
S(0x60fd70, 'GUESS set states 0x19/0x18', 'fastcall', None, ret='eax', gen=g_60fd70)


def g_54e3f0(c):
    o = rbuf(c, 0x400)
    c.emu.w32(o + 0x1c5, c.rng.choice([0, 1, 2, 3, 4, 0xffffffff, 0x80000000]))  # 5+ overwrites the count (entry 4 +0x1c = this+0x1c8)
    return [o]
S(0x54e3f0, 'ZSoundStreamer::Initialize', 'thiscall', None, ret=None, gen=g_54e3f0)


def g_4d1cb0(c):
    r = rbuf(c, 0x20)
    patch(c, 0x4d1cf0, L('4d1cf0', 1, ret=c.rng.choice([0, r])))
    log_obj(c, 1)
    return [rbuf(c, 0x40), r32(c)]
S(0x4d1cb0, 'GUESS lookup 0x4d1cf0 or log', 'thiscall', None, ret='eax', gen=g_4d1cb0)


def _dbread(c, vals):
    def h(e, r):
        e.calllog.append(('dbread', e.reg('ecx'), ()))
        e.ret(eax=vals.pop(0) if vals else r32(c))
    return h


def g_4a2ff0(c):
    vals = [c.rng.choice([0, 0x100, r32(c)]) for _ in range(4)]
    h = _dbread(c, vals)
    patch(c, 0x4e5e60, h, 'uint')
    patch(c, 0x4e5e40, h, 'ushort')
    return [rbuf(c, 0x80), rbuf(c, 0x20)]
S(0x4a2ff0, 'ZPlaySound::CopyEventDataBlock', 'thiscall', None, ret='eax', gen=g_4a2ff0)


def g_4f11f0(c):
    o = obj(c, 'self', {0x70: L('vt70', 1, ret=r32(c))})
    return [o, r32(c), r32(c), r32(c)]
S(0x4f11f0, 'GUESS vt70(&{x,y,z})', 'thiscall', None, ret='eax', gen=g_4f11f0, stack_arg_bytes=12)


def g_57bcb0(c):
    patch(c, 0x563510, L('SetBackGroundPicture', 1, ret=r32(c)))
    v = r32(c)
    def h88(e, r):
        e.calllog.append(('o88', e.reg('ecx'), (e.arg32(0), e.r32(e.arg32(1)))))
        if c.rng.random() < 0.7:
            e.w32(e.arg32(1), v)
        e.ret(eax=r32(c), argbytes=8)
    o = obj(c, 'o', {0x88: h88})
    eng9b(c, {0x138: L('e138', 0, ret=o)})
    return [rbuf(c, 0xd00)]
S(0x57bcb0, 'ZFFLoadError::Init2', 'thiscall', None, ret='eax', gen=g_57bcb0)


def g_548ef0(c):
    vals = [r32(c) for _ in range(4)]
    patch(c, 0x4e5e60, _dbread(c, vals), 'uint')
    tb = rbuf(c, 0x10)
    c.emu.wbytes(tb, bytes([c.rng.choice([0xff, 0x0b, 0x4b, 0xcb, 0x8b, 0x0a, 0x3f, c.rng.getrandbits(8)])]))
    db = rbuf(c, 0x10)
    c.emu.w32(db, tb)
    return [rbuf(c, 0x80), db]
S(0x548ef0, 'CShatter::CopyEventDataBlock', 'thiscall', None, ret='eax', gen=g_548ef0)


def g_63ae30(c):
    n = c.rng.randint(0, 4)
    blks = [rbuf(c, 0x20) for _ in range(n)]
    for i, b in enumerate(blks):
        c.emu.wbytes(b + 2, struct.pack('<H', 0xffff if c.rng.random() < 0.6 else c.rng.getrandbits(16)))
        nxt = blks[i + 1] if i + 1 < n else c.rng.choice([0, blks[0]])
        c.emu.w32(b + 8, nxt)
    o = rbuf(c, 0x20)
    c.emu.w32(o + 8, blks[0] if blks else 0)
    nb = rbuf(c, 0x20)
    def h340(e, r):
        e.calllog.append(('63b340', e.reg('ecx'), ()))
        ok = c.rng.random() < 0.6
        if ok:
            e.w32(e.reg('ecx') + 8, nb)
        e.ret(eax=(r32(c) & 0xffffff00) | ok)
    patch(c, 0x63b340, h340)
    patch(c, 0x63b0c0, L('63b0c0', 0, ret=r32(c)))
    return [o]
S(0x63ae30, 'ZDrawArray<ZLightDrawEntry>::Add', 'thiscall', None, ret='eax', gen=g_63ae30)


def g_6401f0(c):
    patch(c, 0x42ab62, L('printf', 3, ret=r32(c), pop=0, ecx=False))
    return [rbuf(c, 0x40), c.rng.choice([0, 1, 0x7fffffff, 0x80000000, 0xffffffff, r32(c), c.rng.randint(0, 1 << 24)])]
S(0x6401f0, 'ZDrawBase::SetMemorySize', 'thiscall', None, ret='eax', gen=g_6401f0)


def g_4b41b0(c):
    s = rbuf(c, 0x80)
    c.emu.wbytes(s + 0x70, struct.pack('<f', c.rng.choice([0.0, -0.0, 1.5, -2.0, float('nan'), 1e-30, -1e-30])))
    eng9b(c, {0x60: L('e60', 1, ret=c.rng.choice([0, s]))})
    o = obj(c, 'self', {0xa0: L('vta0', 0, ret=r32(c)), 0x68: L('vt68', 2, ret=r32(c))}, size=0x200)
    c.emu.wbytes(o + 0x181, bytes([c.rng.choice([0, 1, 0x80])]))
    for off in (0x64, 0x6c):
        if c.rng.random() < 0.2:
            c.emu.w32(o + off, 0)
    return [o]
S(0x4b41b0, 'CCutSequenceCharacterSound::FrameUpdate', 'thiscall', None, ret=None, gen=g_4b41b0)


def g_57d830(c):
    n = c.rng.randint(1, 5)
    t = rbuf(c, 0x10 * (n + 1))
    ends = []
    for i in range(n):
        base = c.rng.choice([c.rng.randint(0, 0x8000), c.rng.randint(-0x8000, 0x8000) & 0xffffffff])
        ln = c.rng.choice([0, c.rng.randint(1, 0x4000), 0xffffffff, 0x80000000])
        c.emu.w32(t + 0x10 * i, base)
        c.emu.w32(t + 0x10 * i + 0xc, ln)
        ends += [(base + ln) & 0xffff, base & 0xffff, (base + ln - 1) & 0xffff]   # range edges
    c.emu.w32(t + 0x10 * n, 0x80000000)            # catch-all last range
    c.emu.w32(t + 0x10 * n + 0xc, 0xffffffff)
    eng = fbuf(c, 0x2000)
    c.emu.w32(eng + 0x190b, t if c.rng.random() < 0.9 else 0)
    c.emu.w32(0x70039c, eng)
    idv = c.rng.choice([c.rng.randint(0, 0xffff), c.rng.randint(0, 0x8000), r32(c), c.rng.choice(ends)])
    return [idv, 0]
S(0x57d830, 'GUESS id remap (table [0x70039c]+0x190b)', 'fastcall', None, ret='eax', gen=g_57d830)


def g_4e80f0(c):
    nil = r32(c)
    o = obj(c, 'tree', {0x1c: L('Depth', 1, ret=c.rng.randint(0, 50))}, size=0x20)
    c.emu.w32(o + 8, nil)
    node = rbuf(c, 0x20)
    for off in (4, 8):
        if c.rng.random() < 0.5:
            c.emu.w32(node + off, nil)
    if c.rng.random() < 0.3:
        c.emu.w32(o + 4, node)
        return [o, 0]
    return [o, node]
S(0x4e80f0, 'ZBinTree::Depth', 'thiscall', None, ret='eax', gen=g_4e80f0)


def g_659330(c):
    patch(c, 0x4cd9b0, L('Alloc', 2, ret=c.rng.choice([0xffffffff, r32(c)])))
    o2 = obj(c, 'log2', {0x30: L('log2_30', 2, pop=0, ret=r32(c), ecx=False)}, size=0x10)
    o1 = obj(c, 'log', {0x20: L('log20', 2, ret=o2)}, size=0x10)
    c.emu.w32(0x700390, o1)
    return [rbuf(c, 0x20), r32(c), r32(c)]
S(0x659330, 'GUESS init with ZOffsetAlloc::Alloc', 'thiscall', None, ret='eax', gen=g_659330)


def g_57a9f0(c):
    patch(c, 0x5626c0, L('Load2', 0, ret=r32(c)))
    eng9b(c, {0x4c: L('e4c', 1, ret=r32(c))})
    g = rbuf(c, 0x80)
    c.emu.w32(0x7003a0, g)
    o = rbuf(c, 0x200)
    c.emu.w32(o + 0x94, fbuf(c, 0x13300))
    c.emu.w32(o + 0x54, obj(c, 'w', {0x25c: L('w25c', 2, ret=r32(c))}))
    return [o]
S(0x57a9f0, 'ZFFMissingControllerDialog::Load2', 'thiscall', None, ret='eax', gen=g_57a9f0)


def g_4d0630(c):
    o = fbuf(c, 0x12140)
    c.emu.w32(o + 0x1c4, c.rng.choice([0, 0, 1, 2, 5, 30]))
    c.emu.w32(o + 0x12130, c.rng.randint(0, 20))
    c.emu.w32(o + 0xd628, c.rng.randint(0, 20))
    for i in range(21):
        c.emu.w32(o + 0xc628 + 4 * i, rbuf(c, 0x10))
    c.emu.w32(o + 0x1ea, c.emu.fake_vtable('pool', 1, {0: L('pool0', 1, ret=r32(c))}))
    return [o]
S(0x4d0630, 'GUESS pool get', 'thiscall', None, ret='eax', gen=g_4d0630)


def g_430c70(c):
    def h(e, r):
        e.calllog.append(('42b1e0', e.reg('ecx'), (e.reg('edx'), e.arg32(0), e.arg32(1), e.arg32(2))))
        e.ret(eax=c.rng.choice([e.reg('edx'), r32(c)]), argbytes=12)
    patch(c, 0x42b1e0, h)
    o = rbuf(c, 8)
    b = c.rng.getrandbits(31)
    c.emu.w32(o, b)
    c.emu.w32(o + 4, b + c.rng.randint(0, 0x200))
    v = rbuf(c, 8)
    s = r32(c)
    c.emu.w32(v, s)
    c.emu.w32(v + 4, (s + c.rng.randint(0, 0x100)) & 0xffffffff)
    room = (c.emu.r32(o + 4) - b - (c.emu.r32(v + 4) - s)) & 0xffffffff
    return [o, v, c.rng.choice([0, c.rng.randint(0, 0x200), r32(c), room, (room + 1) & 0xffffffff])]
S(0x430c70, 'GUESS find via 0x42b1e0', 'thiscall', None, ret='eax', gen=g_430c70)


def g_4c2170(c):
    patch(c, 0x4c0b00, L('GetValues', 1, ret=r32(c)))
    f = c.emu.stub_fn('cb', L('cb7003b0', 0, ret=r32(c), ecx=False))
    c.emu.w32(0x7003b0, f)
    ld = obj(c, 'ld', {0x40: L('ld40', 1, ret=r32(c)), 0x44: L('ld44', 1, ret=r32(c)), 0x50: L('ld50', 1, ret=r32(c))})
    return [rbuf(c, 0x80), ld]
S(0x4c2170, 'ZSoundAnimation::Load', 'thiscall', None, ret='al', gen=g_4c2170)


def g_622fb0(c):
    n = c.rng.randint(0, 12)
    src = rbuf(c, 0x20)
    m = c.rng.randint(0, 20)
    dst = rbuf(c, 0x20)
    ps = rbuf(c, 4); c.emu.w32(ps, src)
    pd = rbuf(c, 4); c.emu.w32(pd, dst)
    return [r32(c), ps, src + n, pd, dst + m]
S(0x622fb0, 'GUESS Latin-1 to UTF-8', 'cdecl', None, ret='eax', gen=g_622fb0)


def g_57b670(c):
    patch(c, 0x563510, L('SetBackGroundPicture', 1, ret=r32(c)))
    patch(c, 0x57b6d0, L('57b6d0', 0, ret=r32(c)))
    patch(c, 0x563110, L('OnWindowOpen', 2, ret=r32(c)))
    w = obj(c, 'w', {0x34c: L('w34c', 5, ret=r32(c))})
    o = obj(c, 'self', {0x84: L('vt84', 0, ret=w)})
    return [o, r32(c), r32(c)]
S(0x57b670, 'GUESS window open (0x6a6f98)', 'thiscall', None, ret='eax', gen=g_57b670)
