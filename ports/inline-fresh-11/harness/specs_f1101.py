"""specs_f1101.py - fresh-11 batch 1: smallest slice-11 functions (getters, wrappers, deleting dtors)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from h11 import L, obj, rbuf, patch


def r32(c): return c.rng.getrandbits(32)


def g_this(n=0x200):
    def g(c):
        return [rbuf(c, n)]
    return g
S(0x606db0, 'SDLEventIds::GetSize', 'thiscall', None, ret='eax', gen=g_this())
S(0x626a70, 'GUESS return 0x6be898', 'cdecl', None, ret='eax', gen=lambda c: [])
S(0x63db30, 'ZDrawArray<ZTextureViewEntry>::EntrySize', 'thiscall', None, ret='eax', gen=g_this())
S(0x64c770, 'ZDrawArray<ZRoomViewEntry>::GetNrEntriesPerBlock', 'thiscall', None, ret='eax', gen=g_this())


def g_64fbf0(c):
    import struct
    o = rbuf(c, 0x100)
    if c.rng.random() < 0.7:
        c.emu.wbytes(o + 0xb9, struct.pack('<f', c.rng.uniform(-1e3, 1e3)))
    return [o]
S(0x64fbf0, 'ZRender::GetLetterSizeY', 'thiscall', None, ret='st0', gen=g_64fbf0)


def g_4cb4f0(c):
    ld = obj(c, 'ld', {0x48: L('ld48', 1, ret=r32(c))})
    return [rbuf(c, 0x100), ld]
S(0x4cb4f0, 'ZViewNotifyCheckBox::Load', 'thiscall', None, ret='al', gen=g_4cb4f0)


def g_65c030(c):
    patch(c, 0x6493d0, L('ViewBase::BeginCamera', 1, ret=r32(c)))
    cam = obj(c, 'cam', {0: L('cam0', 1, ret=r32(c))})
    return [rbuf(c, 0x100), cam]
S(0x65c030, 'ZViewGC::BeginCamera', 'thiscall', None, ret='eax', gen=g_65c030)


def g_4d8bf0(c):
    lst = obj(c, 'list', {0x84: L('list84', 1, ret=c.rng.choice([0, r32(c)]))})
    o = rbuf(c, 0x40)
    c.emu.w32(o + 4, lst)
    return [o, r32(c)]
S(0x4d8bf0, 'CConsoleCommandList::Find', 'thiscall', None, ret='eax', gen=g_4d8bf0)


def g_4c31b0(c):
    patch(c, 0x4c3740, L('UpdateWindElement', 1, ret=r32(c)))
    o = rbuf(c, 0x100)
    c.emu.w32(o + 0x44, rbuf(c, 0x40))
    cmd = c.rng.choice([0x401, 0x10401, 0xffff0401, 0x400, 0x402, 0x501, r32(c)])
    return [o, cmd, r32(c)]
S(0x4c31b0, 'ZWindElement::Command', 'thiscall', None, ret='eax', gen=g_4c31b0)


def g_dtor(body=None):
    def g(c):
        patch(c, 0x634273, L('delete', 2, pop=0, ecx=False))
        if body:
            patch(c, body, L('body_%x' % body, 0, ret=r32(c)))
        return [rbuf(c, 0x100), r32(c)]
    return g
S(0x636470, 'GUESS deleting dtor (0x6363a0, 0x2d)', 'thiscall', None, ret='eax', gen=g_dtor(0x6363a0))
S(0x5493f0, 'GUESS deleting dtor (vt 0x6a3298, 0x2326)', 'thiscall', None, ret='eax', gen=g_dtor())
S(0x54cd70, 'ZSynth::~ZSynth (deleting)', 'thiscall', None, ret='eax', gen=g_dtor())
S(0x607cb0, 'GUESS deleting dtor (vt 0x6b9fc4, 0x656e10, 4)', 'thiscall', None, ret='eax', gen=g_dtor(0x656e10))
S(0x4286b0, 'GUESS deleting dtor (vt 0x678df4, 0x435b50, 0xb2)', 'thiscall', None, ret='eax', gen=g_dtor(0x435b50))


def g_5f9570(c):
    a, b = r32(c), r32(c)
    seq = [a, b]
    def h(e, r):
        e.calllog.append(('605b90', e.reg('ecx'), ()))
        e.ret(eax=seq.pop(0))
    patch(c, 0x605b90, h)
    return [rbuf(c, 0x100)]
S(0x5f9570, 'GUESS size (0x605b90 x2)', 'thiscall', None, ret='eax', gen=g_5f9570)


def g_6392b0(c):
    o = obj(c, 'o', {0x58: L('vt58', 6, ret=r32(c))})
    return [o, r32(c), r32(c), r32(c), r32(c)]
S(0x6392b0, 'GUESS vt58(d, b*c*4, b, c, a, 1)', 'thiscall', None, ret='eax', gen=g_6392b0)


def g_5fef70(c):
    patch(c, 0x5fe560, L('5fe560', 1, ret=r32(c)))
    patch(c, 0x41e2c0, L('41e2c0', 1, ret=r32(c), pop=0, ecx=False))
    return [rbuf(c, 0x100), rbuf(c, 0x100)]
S(0x5fef70, 'GUESS remove (0x5fe560, 0x41e2c0)', 'thiscall', None, ret='eax', gen=g_5fef70)


def g_6568b0(c):
    prim = rbuf(c, 0x20)
    o = obj(c, 'prim', {0xc: L('vtc', 1, ret=prim)})
    tex = obj(c, 'tex', {0x80: L('tex80', 1, ret=r32(c))})
    eng = rbuf(c, 0x1b00)
    c.emu.w32(eng + 0x1aa3, tex)
    c.emu.w32(0x70039c, eng)
    return [o, r32(c)]
S(0x6568b0, 'ZPrimControlBase::GetTextureFromPrim', 'thiscall', None, ret='eax', gen=g_6568b0)


def g_55ffb0(c):
    e = rbuf(c, 8)
    if c.rng.random() < 0.4:
        c.emu.w32(e, 0)
    patch(c, 0x5003d0, L('5003d0', 1, ret=e))
    tgt = rbuf(c, 0x80)
    g = rbuf(c, 0x2d00)
    c.emu.w32(g + 0x2c21, tgt)
    c.emu.w32(0x7003b8, g)
    return [rbuf(c, 0x20)]
S(0x55ffb0, 'GUESS flag +0x5c from 0x5003d0', 'stdcall', None, ret='eax', gen=g_55ffb0)


def g_65ca30(c):
    return [rbuf(c, 0x500), r32(c), r32(c)]
S(0x65ca30, 'GUESS buffer set +0x400..+0x420', 'thiscall', None, ret='eax', gen=g_65ca30)


def g_4c5870(c):
    n = c.rng.randint(0, 4)
    items = [rbuf(c, 0x10) for _ in range(n)]
    patch(c, 0x4db860, L('Hide', 1, ret=r32(c)))
    nxt = items[1:] + [0]
    def h50(e, r):
        p = e.arg32(0)
        e.calllog.append(('grp50', e.reg('ecx'), (e.r32(p),)))
        e.w32(p, nxt.pop(0) if nxt else 0)
        e.ret(eax=r32(c), argbytes=4)
    g = obj(c, 'grp', {0x50: h50})
    c.emu.w32(g + 8, items[0] if items else 0)
    return [rbuf(c, 0x40), g, r32(c)]
S(0x4c5870, 'ZHideGroupObjects::Init', 'thiscall', None, ret='eax', gen=g_4c5870)
