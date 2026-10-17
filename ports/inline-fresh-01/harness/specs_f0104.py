"""specs_f0104.py - fresh-01 batch 4 (docs/20-fresh-01.md)."""
from pilot import S
from helpers01 import rnd, hk, obj


def _com(c, name):
    def mk(off):
        def h(e, r):
            e.calllog.append((name, off, e.arg32(0)))
            e.ret(eax=0x7700 + off, argbytes=4)
        return h
    o = rnd(c, 0x20)
    c.emu.w32(o, c.emu.fake_vtable(name, 0x20, {8: mk(8), 0x48: mk(0x48)}))
    return o


def _rel(c):
    o = rnd(c, 0xa300)
    c.emu.w32(o + 0xa278, _com(c, 'dev') if c.rng.random() < 0.7 else 0)
    c.emu.w32(o + 0xa274, _com(c, 'res') if c.rng.random() < 0.7 else 0)
    return [o]


def _valid(c):
    n = c.rng.randint(0, 6)
    arr = rnd(c, 4 * n + 8)
    o = rnd(c, 0x40)
    c.emu.w32(o + 0x18, arr)
    c.emu.w32(o + 0x20, n)
    p = c.rng.getrandbits(32)
    if n and c.rng.random() < 0.6:
        p = c.emu.r32(arr + 4 * c.rng.randint(0, n - 1))
    return [o, p]


def _render(c, impl, argw):
    eng = rnd(c, 0x200)
    c.emu.w32(0x70039c, eng)
    r = obj(c, 0xb00, 'render', 0x60, impl, argw)
    c.emu.w32(eng + 0x9b, r)
    return r


def _detach(c):
    hk(c, 0x43fc30, 'ZGROUP::DetachGeom', 2)
    _render(c, {0x50: lambda e, a: (a[0] ^ 0x5050, None)}, {0x50: 1})
    g = rnd(c, 0x80)
    k = c.rng.random()
    if k < 0.2:
        c.emu.w32(g + 0x54, 0)
    else:
        a = rnd(c, 0x20)
        cls = rnd(c, 0x40)
        c.emu.w32(g + 0x54, a)
        c.emu.w32(a + 0xc, cls)
        if k < 0.75:
            c.emu.w32(cls + 0x23, 0x200015)
    room = obj(c, 0x40, 'room', 0xe0, {}, {0x35c: 1})
    return [room, g, c.rng.choice([0, 1, c.rng.getrandbits(32)])]


def _ctor(c):
    hk(c, 0x43de40, 'ZSTDOBJ ctor', 3)
    return [rnd(c, 0x40), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _gamesize(c):
    txt = bytes(c.rng.choice(b'abcdefgh0123 ') for _ in range(c.rng.randint(0, 40))) + b'\0'

    def s144(e, r):
        e.calllog.append(('fmt', e.arg32(1), e.arg32(2)))
        e.wbytes(e.arg32(0), txt)
        e.ret(argbytes=12)

    def s30(e, r):
        e.calllog.append(('print', e.rbytes(e.arg32(0), 0x400).hex(), e.arg32(1)))
        e.ret(argbytes=8)
    o = rnd(c, 0x40)
    c.emu.w32(o, c.emu.fake_vtable('file', 0x60, {0x144: s144}))
    con = rnd(c, 0x20)
    c.emu.w32(con, c.emu.fake_vtable('con', 0x20, {0x30: s30}))
    c.emu.w32(0x700394, con)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _gdtor(c):
    hk(c, 0x4dbb00, 'LightNotify', 1)
    hk(c, 0x45c3e0, '~ZGEOM', 0)
    return [rnd(c, 0x40)]


def _walk(c):
    n = c.rng.randint(0, 5)
    ents = [rnd(c, 0x40) for _ in range(n)]
    nxt = {ents[i]: (ents[i + 1] if i + 1 < n else 0) for i in range(n)}

    def s50(e, r):
        p = e.arg32(0)
        cur = e.r32(p)
        e.calllog.append(('next', e.reg('ecx'), cur))
        e.w32(p, nxt.get(cur, 0))
        e.ret(argbytes=4)
    lst = rnd(c, 0x20)
    c.emu.w32(lst, c.emu.fake_vtable('list', 0x20, {0x50: s50}))
    c.emu.w32(lst + 8, ents[0] if n else 0)
    r = _render(c, {}, {})
    c.emu.w32(r + 0xadc, lst)
    return []


def _read(c):
    o = rnd(c, 0x40)
    data = rnd(c, 0x100)
    pos = c.rng.randint(0, 0x100)
    end = c.rng.choice([pos, 0x100, c.rng.randint(pos, 0x100)])
    c.emu.w32(o + 4, data)
    c.emu.w32(o + 8, pos)
    c.emu.w32(o + 0xc, end)
    dst = rnd(c, 0x110)

    def mc(e, r):
        d, s_, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('memcpy', d, s_, n))
        e.wbytes(d, e.rbytes(s_, n))
        e.ret(eax=d)
    c.emu.stub_import('VCRUNTIME140.dll!memcpy', mc)

    def hnd(e, r):
        e.calllog.append(('handler',))
        e.ret(eax=0xbad)
    c.emu.w32(0x7003b0, c.emu.stub_fn('handler', hnd))
    fd = o + 4 if c.rng.random() < 0.85 else rnd(c, 0x10)
    return [o, dst, c.rng.choice([0, 1, 0x10, 0x200, c.rng.getrandbits(32)]), fd]


def _add(c):
    n = c.rng.randint(0, 4)
    blocks = [rnd(c, 0x40) for _ in range(n)]
    for i, b in enumerate(blocks):
        c.emu.w16(b + 2, 0xffff if c.rng.random() < 0.6 else c.rng.getrandbits(16))
        nx = blocks[(i + 1) % n] if (i + 1 < n or c.rng.random() < 0.6) else 0
        c.emu.w32(b + 8, nx)
    o = rnd(c, 0x20)
    c.emu.w32(o + 8, blocks[c.rng.randint(0, n - 1)] if n else 0)
    grow = c.rng.random() < 0.6
    fresh = rnd(c, 0x20)

    def g(e, r):
        e.calllog.append(('grow', e.reg('ecx')))
        if grow:
            e.w32(e.reg('ecx') + 8, fresh)
        e.ret(eax=0x100 | int(grow))
    c.emu.hook(0x613c20, g)
    hk(c, 0x63b160, 'take', 0, eax=lambda e: e.reg('ecx') ^ 0x10)
    return [o]


def _draw(c):
    e_ = rnd(c, 0x40)
    c.emu.w32(e_ + 0xc, rnd(c, 0x40) if c.rng.random() < 0.7 else 0)
    hk(c, 0x64d030, 'OnGeomNotify', 4, eax=e_)
    hk(c, 0x4de420, 'mcpy', 0, regs=('ecx', 'edx'))
    return [rnd(c, 0x20), c.rng.getrandbits(32), c.rng.getrandbits(32), rnd(c, 0x10),
            c.rng.choice([0xff, 0x1ff, 0, c.rng.getrandbits(32)])]


S(0x54b650, 'render device release 0x54b650', 'thiscall', None, ret=None, gen=_rel)
S(0x5fb550, 'ScriptEngine_t::checkValidProcess', 'thiscall', None, ret='al', gen=_valid)
S(0x444450, 'ZROOM::DetachGeom', 'thiscall', None, ret=None, gen=_detach)
S(0x573650, 'ZSTDOBJ subclass ctor 0x573650', 'thiscall', None, ret='eax', gen=_ctor)
S(0x4270d0, 'ZSysFileGC::GameSize', 'thiscall', None, ret=None, gen=_gamesize)
S(0x4478d0, 'ZGEOM subclass dtor 0x4478d0', 'thiscall', None, ret=None, gen=_gdtor)
S(0x48d010, 'clear list flag 0x48d010', 'cdecl', None, ret=None, gen=_walk)
S(0x4d5310, 'IOFSMemoryAccess_t::nativeRead', 'thiscall', None, ret='eax', gen=_read)
S(0x63aed0, 'ZDrawArray::Add', 'thiscall', None, ret='eax', gen=_add)
S(0x65f410, 'ZDrawBuffer::DrawBaseGeom', 'thiscall', None, ret=None, gen=_draw)
