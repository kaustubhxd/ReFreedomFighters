"""specs_f1104.py - fresh-11 batch 4: slice-11 functions of 110 to 119 bytes."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from h11 import L, obj, rbuf, fbuf, patch, log_obj


def r32(c): return c.rng.getrandbits(32)


def set_eng9b(c, o9b, eng=None):
    eng = eng or rbuf(c, 0x200)
    c.emu.w32(eng + 0x9b, o9b)
    c.emu.w32(0x70039c, eng)
    return eng


def g_4fbab0(c):
    patch(c, 0x41e290, L('new', 1, pop=0, ret=c.rng.choice([0, rbuf(c, 0x18)]), ecx=False))
    inner = obj(c, 'cams', {4: L('cams4', 1, ret=r32(c))})
    h = rbuf(c, 0x20)
    c.emu.w32(h + 0x18, inner)
    o = rbuf(c, 0x60)
    c.emu.w32(o + 0x44, h)
    c.emu.w32(o + 0x4c, c.rng.choice([0, rbuf(c, 0x18)]))
    return [o, r32(c)]
S(0x4fbab0, 'ZSortCameraList::AddCamera', 'thiscall', None, ret='eax', gen=g_4fbab0)


def g_5ec5f0(c):
    n = c.rng.randint(0, 4)
    arr = rbuf(c, 0x28 * 5)
    h = rbuf(c, 0x10)
    c.emu.w32(h + 4, arr)
    o = rbuf(c, 0x60)
    c.emu.w32(o + 0x3a, h)
    c.emu.w32(o + 0x3e, n)
    return [o, rbuf(c, 0x10), c.rng.choice([0xffffffff, 0xffffffff, c.rng.randint(0, 4)])]
S(0x5ec5f0, 'CSprite3D::SetPosition', 'thiscall', None, ret=None, gen=g_5ec5f0)


def g_650eb0(c):
    patch(c, 0x634273, L('delete', 2, pop=0, ecx=False, ret=r32(c)))
    log_obj(c, 1)
    o = rbuf(c, 0x100)
    if c.rng.random() < 0.3:
        c.emu.w32(o + 0x74, 0)
    sz = rbuf(c, 8)
    vals = [1.0, 0.5, 0.0, -0.0, -1.0, float('nan'), 1e-40, float('inf'), -float('inf')]
    c.emu.wbytes(sz, struct.pack('<ff', c.rng.choice(vals), c.rng.choice(vals)))
    return [o, sz]
S(0x650eb0, 'ZRender::SetFontSize', 'thiscall', None, ret='eax', gen=g_650eb0)


def g_65e0b0(c):
    patch(c, 0x634123, L('eh_vector_ctor', 5, ret=r32(c), ecx=False))
    return [fbuf(c, 0x3700)]
S(0x65e0b0, 'ZGeometryDecal::ZGeometryDecal', 'thiscall', None, ret='eax', gen=g_65e0b0)


def g_65f0f0(c):
    patch(c, 0x634273, L('delete', 2, pop=0, ecx=False, ret=r32(c)))
    o = fbuf(c, 0x3700)
    c.emu.w32(o + 0xc8, c.rng.randint(0, 5))
    return [o]
S(0x65f0f0, 'ZGeometryDecal::End', 'thiscall', None, ret='eax', gen=g_65f0f0)


def _iter_list(c, elems, nb):
    """slot +0x4c(it) fills the iterator, slot +0x5c(it) returns the next element and sets it[0] (0 at the end)."""
    seq = list(elems)
    def h4c(e, r):
        p = e.arg32(0)
        e.calllog.append(('start', e.reg('ecx'), ()))
        e.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(nb)))
        e.ret(eax=r32(c), argbytes=4)
    def h5c(e, r):
        p = e.arg32(0)
        e.calllog.append(('next', e.reg('ecx'), (e.r32(p),)))
        if seq:
            e.w32(p, c.rng.randint(1, 0xffffffff))
            v = seq.pop(0)
        else:
            e.w32(p, 0)
            v = r32(c)
        e.ret(eax=v, argbytes=4)
    return obj(c, 'list', {0x4c: h4c, 0x5c: h5c})


def g_43ab30(c):
    xs = []
    for _ in range(c.rng.randint(0, 4)):
        r = c.rng.random()
        if r < 0.15:
            xs.append(0)
        else:
            b = rbuf(c, 0x40)
            if r < 0.7:
                c.emu.w32(b + 4, 0)
            xs.append(b + 4)
    o = rbuf(c, 0x40)
    c.emu.w32(o + 0x19, c.rng.choice([0] + [_iter_list(c, xs, 16)] * 6))
    return [o]
S(0x43ab30, 'GUESS clear geom flags (list +0x19)', 'thiscall', None, ret=None, gen=g_43ab30, stack_arg_bytes=16)


def g_5515f0(c):
    calls = []
    elems = [rbuf(c, 8) for _ in range(3)]
    def h3d0(e, r):
        i = e.arg32(0)
        e.calllog.append(('5003d0', e.reg('ecx'), (i,)))
        e.ret(eax=elems[i % 3], argbytes=4)
    patch(c, 0x5003d0, h3d0)
    patch(c, 0x500360, L('set_float', 1, ret=r32(c)))
    patch(c, 0x5002f0, L('set_int', 1, ret=r32(c)))
    ev = obj(c, 'ev', {0x4c: L('ev4c', 0, ret=rbuf(c, 0x10))})
    fac = obj(c, 'fac', {0x18: L('fac18', 1, ret=c.rng.choice([0, ev, ev]))})
    return [fac, r32(c), rbuf(c, 0x10)]
S(0x5515f0, 'Signature_ffi_EventTranslator_t::handleEventTranslation', 'stdcall', None, ret='eax', gen=g_5515f0)


def g_453130(c):
    ids = [r32(c) for _ in range(c.rng.randint(0, 4))]
    g = obj(c, 'gate', {0x228: L('g228', 0, ret=r32(c))})
    set_eng9b(c, obj(c, 'eng9b', {0x58: L('e58', 1, ret=c.rng.choice([0, g, g]))}))
    o = rbuf(c, 0x80)
    c.emu.wbytes(o + 0x5a, bytes([c.rng.choice([0, 1, 0x80])]))
    c.emu.w32(o + 0x52, c.rng.choice([0] + [_iter_list(c, ids, 12)] * 5))
    return [o]
S(0x453130, 'ZGATE::Close', 'thiscall', None, ret=None, gen=g_453130, stack_arg_bytes=12)


def g_factory(c):
    p = rbuf(c, 0x60)
    pool = obj(c, 'pool', {0x44: L('alloc', 1, ret=c.rng.choice([0, p, p]))})
    e = rbuf(c, 0x20)
    c.emu.w32(e + 8, pool)
    set_eng9b(c, e)
    patch(c, 0x469870, L('base_469870', 0, ret=r32(c)))
    return [r32(c)]
for a, vt in ((0x4b3170, 0x691b20), (0x4bebb0, 0x693564), (0x4c6c70, 0x6947d4), (0x57a130, 0x6a9b58)):
    S(a, 'GUESS factory (0x469870, vtable 0x%x)' % vt, 'thiscall', None, ret='eax', gen=g_factory)


def g_578d30(c):
    text = bytes(c.rng.getrandbits(8) for _ in range(0x40))
    def h198(e, r):
        buf = e.arg32(1)
        e.calllog.append(('fmt198', e.arg32(0), (e.arg32(2), e.arg32(3))))
        e.wbytes(buf, text)
        e.ret(eax=r32(c))
    s = obj(c, 's', {0x198: h198})
    ans = c.rng.getrandbits(8)
    def h90(e, r):
        buf, pa = e.arg32(0), e.arg32(1)
        e.calllog.append(('ask90', e.reg('ecx'), (e.rbytes(buf, 0x40).hex(), e.rbytes(pa, 1).hex())))
        if c.rng.random() < 0.7:
            e.wbytes(pa, bytes([ans]))
        e.ret(eax=r32(c), argbytes=8)
    o = obj(c, 'o', {0x90: h90})
    eng = obj(c, 'eng', {0x190: L('eng190', 0, ret=s)}, size=0x200)
    set_eng9b(c, obj(c, 'eng9b', {0x134: L('e134', 0, ret=o)}), eng)
    return [rbuf(c, 0x200)]
S(0x578d30, 'GUESS ask yes/no (fmt 0x6a9afc)', 'thiscall', None, ret='eax', gen=g_578d30)
