"""specs_f1004.py - fresh-10 batch 4: menu/cutscene/window helpers, script VM helpers, destructors (slice 10)."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from h10 import L, obj, rbuf, patch, iat, log_obj


def R(c): return c.rng.getrandbits(32)
def fbits(c): return struct.unpack('<I', struct.pack('<f', c.fv()))[0]
def scene(c, slots):
    s = obj(c, 'scn', slots, size=0x20); rm = rbuf(c, 0x2000)
    c.emu.w32(rm + 0x9b, s); c.emu.w32(0x70039c, rm)
    return rm


S(0x570620, 'CSewerMenu::CopyData', 'thiscall', None, ret=None, gen=lambda c: [rbuf(c, 0x200), rbuf(c, 0x200)])


def g_4b14a0(c):   # CCutSequenceProxy::Command(unsigned short, void*)
    scene(c, {0x4c: L('scn4c', 1, ret=R(c))})
    tgt = obj(c, 'tgt', {0x12c: L('tgt12c', 3)}, size=0x10)
    o = rbuf(c, 0x60); c.emu.w32(o + 0x44, tgt)
    w = c.rng.getrandbits(16); c.emu.w16(o + 0x48, w)
    a = (R(c) & 0xffff0000) | (w if c.rng.random() < 0.6 else c.rng.getrandbits(16))
    return [o, a, R(c)]
S(0x4b14a0, 'CCutSequenceProxy::Command', 'thiscall', None, ret='eax', gen=g_4b14a0)


def g_4858a0(c):   # ZToggleStart::FrameUpdate
    sysd = obj(c, 'sys', {0xe8: L('syse8', 1, ret=c.rng.choice([0, 1, 0x100, R(c)]))}, size=0x10)
    c.emu.w32(0x70039c, sysd)
    lst = obj(c, 'list', {0x34: L('list34', 1, ret=c.rng.choice([0, rbuf(c, 0x40)])), 0x14: L('list14', 0, ret=c.rng.randint(0, 4))}, size=0x10)
    tgt = obj(c, 'tgt', {0x370: L('tgt370', 2)}, size=0x10)
    o = rbuf(c, 0x60); c.emu.w32(o + 0x44, tgt); c.emu.w32(o + 0x48, lst); c.emu.w32(o + 0x4c, c.rng.randint(0, 4) - 1)
    return [o]
S(0x4858a0, 'ZToggleStart::FrameUpdate', 'thiscall', None, ret=None, gen=g_4858a0)


def g_54f1a0(c):   # GUESS COM call slot 0x10 (stdcall, 7 args) with &arg; log on failure
    log_obj(c, 1)
    com = obj(c, 'com', {0x10: L('com10', 7, ret=c.rng.choice([0, 1, 0x80004005, R(c)]), ecx=False)}, size=0x10)
    o = rbuf(c, 0x20); c.emu.w32(o + 4, 0 if c.rng.random() < 0.15 else com)
    return [o, R(c)]
S(0x54f1a0, 'GUESS COM slot 0x10 + log', 'thiscall', None, ret='eax', gen=g_54f1a0)


def g_4c1ee0(c):   # ZSoundClock::Init(ZGEOM*, DBREAD&)
    patch(c, 0x4c0d70, L('GetValues', 1))
    o = obj(c, 'clk', {0x60: L('clk60', 1)}, size=0x200)
    if c.rng.random() < 0.5: c.emu.w32(o + 0x1cc, 0)
    c.emu.w32(o + 0x1ac, fbits(c))
    return [o, R(c), R(c)]
S(0x4c1ee0, 'ZSoundClock::Init', 'thiscall', None, ret=None, gen=g_4c1ee0)


def g_4f4020(c):   # ZWINDOW::WndMessage(ZWMEVENT*)
    w = obj(c, 'wnd', {0x2d8: L('wnd2d8', 2, ret=R(c)), 0x2dc: L('wnd2dc', 2, ret=R(c))}, size=0x10)
    e = rbuf(c, 0x20); c.emu.w32(e + 4, c.rng.choice([0x100, 0x200, 0x101, 0x1ff, R(c)]))
    if c.rng.random() < 0.4: c.emu.w32(e + 0xc, 0)
    return [w, e]
S(0x4f4020, 'ZWINDOW::WndMessage', 'thiscall', None, ret='al', gen=g_4f4020)


def g_5613a0(c):   # CBaseWindow::Align(unsigned, unsigned)
    log_obj(c, 1)
    o = rbuf(c, 0x100); c.emu.w32(o + 0xd8, c.rng.choice([0, 3, 7, 8, 9, 0x80000000, c.rng.randint(0, 7)]))
    return [o, R(c), R(c)]
S(0x5613a0, 'CBaseWindow::Align', 'thiscall', None, ret=None, gen=g_5613a0)


def g_604460(c):   # ScriptEventManager_t::sendEvent(Process_t*, unsigned short, void*)
    patch(c, 0x5fb550, L('checkValidProcess', 1, ret=c.rng.choice([0, 1, 0x100, R(c)])))
    patch(c, 0x5f4600, L('enqueue', 1)); patch(c, 0x5f4ac0, L('handleEvents', 0, ret=R(c)))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert', L('assert', 0, ret=R(c), ecx=False)))
    tab = rbuf(c, 0x40)
    for i in range(16):
        c.emu.w32(tab + 4 * i, 0 if c.rng.random() < 0.3 else obj(c, 'h%d' % i, {0: L('h0', 3, ret=c.rng.choice([0, R(c)]))}, size=0x10))
    o = rbuf(c, 0x20); c.emu.w32(o + 8, tab)
    return [o, rbuf(c, 0x20), (R(c) & 0xffff0000) | c.rng.randint(0, 15), R(c)]
S(0x604460, 'ScriptEventManager_t::sendEvent', 'thiscall', None, ret='eax', gen=g_604460)


def g_5fe920(c):   # VMImageInfo_t::constructProcessData(Process_t*, SdlHostDataExchange_t*)
    patch(c, 0x5ffb50, L('getDataSegSize', 0, ret=c.rng.randint(0, 0x100)))
    patch(c, 0x41e290, L('new', 1, pop=0, ecx=False, ret=0x30000000 + (R(c) & 0xfff0)))
    def cp(e, r):
        p = e.arg32(1)
        e.calllog.append(('copyAndInit', e.reg('ecx'), (e.arg32(0), p, e.arg32(2))))
        e.w32(p, 0x77)
        e.ret(eax=0, argbytes=12)
    patch(c, 0x5fe980, cp)
    b = rbuf(c, 0x100); c.emu.w32(b + 0x9c, 0 if c.rng.random() < 0.4 else rbuf(c, 0x10))
    return [b, rbuf(c, 0x100), R(c)]
S(0x5fe920, 'VMImageInfo_t::constructProcessData', 'thiscall', None, ret=None, gen=g_5fe920)


def g_4f7fe0(c):   # ZSlider::NotifyChange
    tgt = obj(c, 'tgt', {0x2dc: L('tgt2dc', 3)}, size=0x10)
    scene(c, {0x58: L('scn58', 1, ret=R(c)), 0x4c: L('scn4c', 1, ret=R(c))})
    return [obj(c, 'sld', {0x2c4: L('sld2c4', 0, ret=tgt), 0x368: L('sld368', 1, ret=R(c))})]
S(0x4f7fe0, 'ZSlider::NotifyChange', 'thiscall', None, ret=None, gen=g_4f7fe0)


def g_492820(c):   # GUESS lazy buffer: size = slot218(), buf = new(size), slot21c(buf, size)
    patch(c, 0x41e290, L('new', 1, pop=0, ecx=False, ret=R(c)))
    o = obj(c, 'o', {0x218: L('o218', 0, ret=c.rng.choice([0, 0xffffffff, 1, R(c)])), 0x21c: L('o21c', 2)}, size=0xb00)
    if c.rng.random() < 0.5: c.emu.w32(o + 0xaf8, 0)
    if c.rng.random() < 0.5: c.emu.w32(o + 0xafc, 0)
    return [o]
S(0x492820, 'GUESS lazy buffer 0xaf8/0xafc', 'thiscall', None, ret=None, gen=g_492820)


def g_5f1720(c):   # ZScriptDll::CleanMrProper
    patch(c, 0x5fb5a0, L('f5fb5a0', 0))
    b = rbuf(c, 0x100); x = rbuf(c, 0x10); c.emu.w32(x + 4, rbuf(c, 0x10))
    beg = rbuf(c, 0x40); c.emu.w32(b + 0xac, beg); c.emu.w32(b + 0xb0, c.rng.choice([beg, beg + 4 * c.rng.randint(0, 15), beg + c.rng.randint(0, 60), R(c)]))
    o = rbuf(c, 0x20); c.emu.w32(o + 0xc, b)
    return [o]
S(0x5f1720, 'ZScriptDll::CleanMrProper', 'thiscall', None, ret=None, gen=g_5f1720)


def g_54ea20(c):   # GUESS scalar deleting dtor with SEH frame: vtable 0x6a410c, release [this+4], delete(this, 8)
    patch(c, 0x634273, L('delete', 2, pop=0, ecx=False))
    o = rbuf(c, 0x10)
    c.emu.w32(o + 4, 0 if c.rng.random() < 0.3 else obj(c, 'com', {8: L('release', 1, ret=R(c), ecx=False)}, size=0x10))
    return [o, R(c)]
S(0x54ea20, 'GUESS SEH dtor 0x6a410c', 'thiscall', None, ret='eax', gen=g_54ea20)


def g_6487a0(c):   # GUESS block take: 36-byte slots after the header; free index in word +2, next in slot word +0x10
    b = rbuf(c, 0x400)
    c.emu.w16(b + 2, c.rng.choice([0xffff, c.rng.randint(0, 20)]))
    return [b]
S(0x6487a0, 'GUESS ZArrayBlock take slot', 'thiscall', None, ret='eax', gen=g_6487a0)


def g_4c3420(c):   # GUESS (SEH frame): o = [[rm+0x9b]+8].slot44(this); if o: 0x4c32a0(o); return o
    patch(c, 0x4c32a0, L('f4c32a0', 0, ret=R(c)))
    f = obj(c, 'fac', {0x44: L('fac44', 1, ret=c.rng.choice([0, R(c)]))}, size=0x10)
    s = rbuf(c, 0x20); c.emu.w32(s + 8, f); rm = rbuf(c, 0x100); c.emu.w32(rm + 0x9b, s); c.emu.w32(0x70039c, rm)
    return [rbuf(c, 0x10)]
S(0x4c3420, 'GUESS create via scene+8 slot44', 'thiscall', None, ret='eax', gen=g_4c3420)
