"""specs_f1002.py - fresh-10 batch 2: wrappers, destructors and small accessors from slice 10."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from h10 import L, obj, rbuf, patch, iat, log_obj


def R(c): return c.rng.getrandbits(32)


def g_64f820(c):   # ZRender::BeginScene: inner = this+0xbd; if inner.vt74() (AL) then inner.vt64(); return true
    inner = obj(c, 'inner', {0x74: L('vt74', 0, ret=c.rng.choice([0, 1, 0x100, 0xffffff00, R(c)])), 0x64: L('vt64', 0, ret=R(c))})
    o = rbuf(c, 0x200); c.emu.w32(o + 0xbd, inner)
    return [o]
S(0x64f820, 'ZRender::BeginScene', 'thiscall', None, ret='al', gen=g_64f820)


def g_6590a0(c):   # GUESS ctor: [this] = arg; ZOffsetAlloc ctor at this+4 (1, arg, 0x400)
    patch(c, 0x4ccdd0, L('ZOffsetAlloc', 3, ret=R(c)))
    return [rbuf(c, 0x40), R(c)]
S(0x6590a0, 'GUESS ctor (ZOffsetAlloc at +4)', 'thiscall', None, ret='eax', gen=g_6590a0)


def g_602ca0(c):   # RunTimeTypeLibrary_t::consume (GUESS name, low)
    patch(c, 0x6025f0, L('f6025f0', 0))
    patch(c, 0x634273, L('delete', 2, pop=0, ecx=False))
    c.emu.w32(0x724694, 0 if c.rng.random() < 0.3 else rbuf(c, 0x40))
    return []
S(0x602ca0, 'RunTimeTypeLibrary_t::consume', 'cdecl', None, ret=None, gen=g_602ca0)


def g_6078e0(c):   # GUESS scalar deleting dtor (vtable 0x6b9f00, base 0x64f530, size 0xa5)
    patch(c, 0x64f530, L('f64f530', 0))
    patch(c, 0x634273, L('delete', 2, pop=0, ecx=False))
    return [rbuf(c, 0xc0), R(c)]
S(0x6078e0, 'GUESS scalar deleting dtor 0x6b9f00', 'thiscall', None, ret='eax', gen=g_6078e0)


def _getinput(v):
    def h(e, r):
        p = e.arg32(0)
        e.calllog.append(('GetInput', e.reg('ecx'), (p,)))
        e.w32(p, v)
        e.ret(eax=0, argbytes=4)
    return h


def g_4cb120(c):   # ZScrollTexture::Load(ZLoadGame*)
    patch(c, 0x6352f0, _getinput(R(c)))
    patch(c, 0x4cb030, L('GetValues', 1))
    return [rbuf(c, 0x80), R(c)]
S(0x4cb120, 'ZScrollTexture::Load', 'thiscall', None, ret='al', gen=g_4cb120)


def g_5fa1e0(c):   # GUESS checked array get: [[this+4]][idx], assert hook [0x7003b0] when idx >= count
    arr = rbuf(c, 0x100); hdr = rbuf(c, 0x10); o = rbuf(c, 0x10)
    n = c.rng.randint(0, 40)
    c.emu.w32(hdr, arr); c.emu.w32(hdr + 8, n); c.emu.w32(o + 4, hdr)
    idx = c.rng.randint(0, min(n + 4, 63))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert', L('assert', 0, ecx=False)))
    return [o, idx]
S(0x5fa1e0, 'GUESS checked array get', 'thiscall', None, ret='eax', gen=g_5fa1e0)


def g_655220(c):   # GUESS: sys.vtcc(); SetFocus(hwnd); this.vt88(1); SetCursor(0)
    c.emu.w32(0x70039c, obj(c, 'sys', {0xcc: L('syscc', 0, ret=R(c))}, size=0x10))
    iat(c, 0x676204, 'SetFocus', 1, R(c)); iat(c, 0x67622c, 'SetCursor', 1, R(c))
    return [obj(c, 'wnd', {0x88: L('vt88', 1, ret=R(c))})]
S(0x655220, 'GUESS SetFocus wrapper', 'thiscall', None, ret='eax', gen=g_655220)


def _rm_draw(c, slots):
    """[0x70039c]+0x190f -> object whose slot 0x20 returns a draw object with the given slots."""
    draw = obj(c, 'draw', slots, size=0x40)
    o = obj(c, 'o190f', {0x20: L('vt20', 0, ret=draw)}, size=0x10)
    rm = rbuf(c, 0x2000); c.emu.w32(rm + 0x190f, o); c.emu.w32(0x70039c, rm)


def g_6563a0(c):   # GUESS: n = count*68; if n: draw.vt18(p, n)
    _rm_draw(c, {0x18: L('vt18', 2, ret=R(c))})
    return [rbuf(c, 0x10), R(c), c.rng.choice([0, 1, 2, 0x3c3c3c3c, 0xf0f0f0f1, R(c), c.rng.randint(0, 50)])]
S(0x6563a0, 'GUESS draw free count*68', 'thiscall', None, ret=None, gen=g_6563a0)


def g_656da0(c):   # ZPrimControlBase::SetPrimFrameNr(geom, float)
    ent = rbuf(c, 0x60)
    _rm_draw(c, {})
    patch(c, 0x63eab0, L('GetEntryFromId', 1, ret=ent))
    g = rbuf(c, 0x60)
    if c.rng.random() < 0.3: c.emu.w16(g + 0x5a, 0)
    return [rbuf(c, 0x10), g, F(c.fv())]
S(0x656da0, 'ZPrimControlBase::SetPrimFrameNr', 'thiscall', None, ret=None, gen=g_656da0)


def g_426620(c):   # GUESS (map says ZSysFileGC::ReadFrom): SetCurrentDirectoryA(path); log on failure
    iat(c, 0x6760fc, 'SetCurrentDirectoryA', 1, c.rng.choice([0, 1, R(c)]))
    log_obj(c, 1)
    return [rbuf(c, 0x10), R(c)]
S(0x426620, 'GUESS SetCurrentDirectoryA + log', 'thiscall', None, ret='eax', gen=g_426620)


def g_54baa0(c):   # GUESS: f54a0c0(); vtb4(); log line 0x2b4
    patch(c, 0x54a0c0, L('f54a0c0', 0, ret=R(c)))
    log_obj(c, 1)
    return [obj(c, 'o', {0xb4: L('vtb4', 0, ret=R(c))})]
S(0x54baa0, 'GUESS f54a0c0 + vtb4 + log', 'thiscall', None, ret='eax', gen=g_54baa0)


def g_6014e0(c):   # CHostInterface::consumeOpaque(OpaqueType_t*): log, then the assert hook
    log_obj(c, 2)
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert', L('assert', 0, ret=R(c), ecx=False)))
    return [rbuf(c, 0x10), R(c)]
S(0x6014e0, 'CHostInterface::consumeOpaque', 'thiscall', None, ret='eax', gen=g_6014e0)


def g_4958e0(c):   # GUESS dtor body with SEH frame: vtable 0x68e2e4, then 0x496db0
    patch(c, 0x496db0, L('f496db0', 0, ret=R(c)))
    return [rbuf(c, 0x40)]
S(0x4958e0, 'GUESS dtor body 0x68e2e4 (SEH frame)', 'thiscall', None, ret='eax', gen=g_4958e0)


def g_57f620(c):   # CSoundMenu::OnWindowClose(unsigned, bool)
    patch(c, 0x562e90, L('CBaseWindow::OnWindowClose', 2, ret=R(c)))
    snd = obj(c, 'snd', {0x350: L('vt350', 3, ret=R(c))}, size=0x10)
    return [obj(c, 'menu', {0x84: L('vt84', 0, ret=snd)}), R(c), R(c)]
S(0x57f620, 'CSoundMenu::OnWindowClose', 'thiscall', None, ret='al', gen=g_57f620)


def g_4cd1a0(c):   # ALLOCREF scalar deleting dtor
    patch(c, 0x634273, L('delete', 2, pop=0, ecx=False))
    o = rbuf(c, 0x40)
    c.emu.w32(o + 8, 0 if c.rng.random() < 0.3 else obj(c, 'ref', {0: L('dtor', 1, ret=R(c))}, size=0x10))
    return [o, R(c)]
S(0x4cd1a0, 'ALLOCREF::~ALLOCREF (scalar deleting)', 'thiscall', None, ret='eax', gen=g_4cd1a0)
