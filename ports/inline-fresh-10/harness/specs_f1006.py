"""specs_f1006.py - fresh-10 batch 6: save/hide/list helpers, DOS time packing, draw-array add (slice 10)."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from h10 import L, obj, rbuf, patch, iat, log_obj


def R(c): return c.rng.getrandbits(32)
def fbits(c): return struct.unpack('<I', struct.pack('<f', c.fv()))[0]
def AL(c): return c.rng.choice([0, 1, 0x100, R(c)])
def scene(c, slots, size=0x20):
    s = obj(c, 'scn', slots, size=size); rm = rbuf(c, 0x2000)
    c.emu.w32(rm + 0x9b, s); c.emu.w32(0x70039c, rm)
    return s


def _iter(elems, name='lst'):
    st = {'k': 0}
    def h4c(e, r):
        p = e.arg32(0)
        e.calllog.append((name + '4c', e.reg('ecx'), (p,)))
        e.wbytes(p, b'\x11' * 12); st['k'] = 0
        e.ret(eax=0x1234, argbytes=4)
    def h5c(e, r):
        p = e.arg32(0); k = st['k']; st['k'] += 1
        e.calllog.append((name + '5c', e.reg('ecx'), (p,)))
        e.w32(p, 1 if k < len(elems) else 0); e.w32(p + 4, k)
        e.ret(eax=elems[k] if k < len(elems) else 0x5555, argbytes=4)
    return {0x4c: h4c, 0x5c: h5c}


def g_4f0ce0(c):   # ZCHAROBJ::Save(ZSaveGame*)
    patch(c, 0x4f0d70, L('ZWINOBJ::Save', 1, ret=AL(c)))
    scene(c, {0x4c: L('scn4c', 1, ret=R(c))})
    sv = obj(c, 'sv', {0x44: L('sv44', 1), 0x3c: L('sv3c', 1), 0x5c: L('sv5c', 1)}, size=0x10)
    o = rbuf(c, 0xc0)
    if c.rng.random() < 0.3: c.emu.w32(o + 0x97, 0)
    return [o, sv]
S(0x4f0ce0, 'ZCHAROBJ::Save', 'thiscall', None, ret='al', gen=g_4f0ce0)


def g_5d49e0(c):   # GUESS creator + 0x469870 + fields
    patch(c, 0x469870, L('ctor', 0, ret=R(c)))
    f = obj(c, 'fac', {0x44: L('fac44', 1, ret=c.rng.choice([0, rbuf(c, 0x80)]))}, size=0x10)
    s = rbuf(c, 0x20); c.emu.w32(s + 8, f); rm = rbuf(c, 0x100); c.emu.w32(rm + 0x9b, s); c.emu.w32(0x70039c, rm)
    return [rbuf(c, 0x10)]
S(0x5d49e0, 'GUESS create + 0x469870 (vtable 0x6b5304)', 'thiscall', None, ret='eax', gen=g_5d49e0)


def g_428560(c):   # GUESS constructor (vtable 0x678dc0, "WintelMouse")
    patch(c, 0x4359f0, L('base', 1)); patch(c, 0x4361a0, L('setname', 1))
    return [rbuf(c, 0x60), R(c), R(c), R(c), R(c)]
S(0x428560, 'GUESS ctor 0x678dc0 WintelMouse', 'thiscall', None, ret='eax', gen=g_428560)


def g_4f3ee0(c):   # ZWINDOW::Hide(bool)
    patch(c, 0x45f070, L('ZGEOM::Hide', 1))
    me = c.emu.alloc(0x40, 4)
    k = c.rng.randint(0, 3); chain = [obj(c, 'p%d' % i, {}, size=0x10) for i in range(k)]
    last = c.rng.choice([me, 0])
    nodes = chain + [last]
    for i in range(k):
        c.emu.w32(chain[i], c.emu.fake_vtable('p', 9, {0x20: L('next', 0, ret=nodes[i + 1])}))
    first = nodes[0] if c.rng.random() < 0.85 else 0
    mgr = obj(c, 'mgr', {0x2ec: L('mgr2ec', 1, ret=R(c)), 0x2f0: L('mgr2f0', 0, ret=first), 0x2f4: L('mgr2f4', 2, ret=R(c))}, size=0x10)
    vt = c.emu.fake_vtable('wnd', 0x2e4 // 4 + 1, {0x2c4: L('wnd2c4', 0, ret=mgr), 0x2e0: L('wnd2e0', 0, ret=c.rng.choice([0, R(c)]))})
    c.emu.wbytes(me, bytes(c.rng.getrandbits(8) for _ in range(0x40))); c.emu.w32(me, vt)
    return [me, c.rng.choice([0, 1, 0x100, R(c)])]
S(0x4f3ee0, 'ZWINDOW::Hide', 'thiscall', None, ret=None, gen=g_4f3ee0)


def g_601ee0(c):   # CSdlDataExchange::setExportSymbol(const char*, const char*)
    patch(c, 0x41e290, L('new', 1, pop=0, ecx=False, ret=c.rng.choice([0, rbuf(c, 8)])))
    patch(c, 0x600c70, L('sym ctor', 2, ret=R(c))); patch(c, 0x5f4630, L('grow', 0))
    o = rbuf(c, 0x20); n = c.rng.randint(0, 6)
    c.emu.w32(o + 4, rbuf(c, 0x40)); c.emu.w32(o + 8, c.rng.choice([n, n + 1, n + 4])); c.emu.w32(o + 0xc, n)
    return [o, R(c), R(c)]
S(0x601ee0, 'CSdlDataExchange::setExportSymbol', 'thiscall', None, ret=None, gen=g_601ee0)


def g_44a160(c):   # ZLIST::CheckPointInside(const float*, float) const
    n = c.rng.randint(0, 5); elems = [R(c) for _ in range(n)]
    def g58(e, r):
        a = e.arg32(0); e.calllog.append(('scn58', e.reg('ecx'), (a,)))
        if a & 3 == 0: e.ret(eax=0, argbytes=4); return
        g = obj(c, 'g', {0x180: L('g180', 2, ret=AL(c))}, size=0x10)
        e.ret(eax=g, argbytes=4)
    scene(c, {0x58: g58})
    o = rbuf(c, 0x20); c.emu.w32(o + 0x18, 0 if c.rng.random() < 0.15 else obj(c, 'lst', _iter(elems), size=0x10))
    return [o, rbuf(c, 0x10), F(c.fv())]
S(0x44a160, 'ZLIST::CheckPointInside', 'thiscall', None, ret='al', gen=g_44a160, stack_arg_bytes=12)


def g_5b7660(c):   # ZFFHintBox::FrameUpdate()
    def cen(e, r):
        p = e.arg32(0); e.calllog.append(('GetCen', e.reg('ecx'), (p,)))
        for i in range(3): e.w32(p + 4 * i, 0x3f800000 + i)
        e.ret(eax=0, argbytes=4)
    patch(c, 0x4daf90, cen); patch(c, 0x597fc0, L('HintMessage', 2))
    hero = obj(c, 'hero', {0x84: L('hero84', 1)}, size=0x900); c.emu.w32(hero + 8, rbuf(c, 0x10))
    box = obj(c, 'box', {0x8c: L('box8c', 1), 0x180: L('box180', 2, ret=AL(c))}, size=0x10)
    o = obj(c, 'hint', {0x68: L('hint68', 2)}, size=0x60); c.emu.w32(o + 0x50, hero); c.emu.w32(o + 0x44, box)
    return [o]
S(0x5b7660, 'ZFFHintBox::FrameUpdate', 'thiscall', None, ret=None, gen=g_5b7660, stack_arg_bytes=12)


def g_454ca0(c):   # GUESS: resolve each material's geom (+0x20) and store 0x45be60(g, +0x34) at +0x38
    patch(c, 0x45be60, L('f45be60', 1, ret=R(c)))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert', L('assert', 0, ecx=False)))
    n = c.rng.randint(0, 5); elems = [rbuf(c, 0x40) for _ in range(n)]
    def g58(e, r):
        a = e.arg32(0); e.calllog.append(('scn58', e.reg('ecx'), (a,)))
        if a & 3 == 0: e.ret(eax=0, argbytes=4); return
        g = rbuf(c, 0x20); t = rbuf(c, 0x40); c.emu.w32(g + 0xc, t)
        if c.rng.random() < 0.7: c.emu.w32(t + 0x23, 0x2000ee)
        e.ret(eax=g, argbytes=4)
    scene(c, {0x58: g58})
    o = rbuf(c, 0x80); c.emu.w32(o + 0x5c, 0 if c.rng.random() < 0.15 else obj(c, 'lst', _iter(elems), size=0x10))
    return [o]
S(0x454ca0, 'GUESS material geom resolve', 'thiscall', None, ret=None, gen=g_454ca0, stack_arg_bytes=12)


def g_4d68e0(c):   # GUESS: DOS date/time of now into two words (date if pointer set; time if the word is non-zero)
    t = R(c)
    def tm(e, r):
        p = e.arg32(0); e.calllog.append(('_time32', 0, (p,))); e.w32(p, t); e.ret(eax=t, argbytes=0)
    tmb = rbuf(c, 0x24)
    for i, (lo, hi) in enumerate([(0, 61), (0, 59), (0, 23), (1, 31), (0, 11), (70, 140)]):
        c.emu.w32(tmb + 4 * i, c.rng.randint(lo, hi) if c.rng.random() < 0.8 else R(c))
    iat(c, 0x676438, '_time32', 0); c.emu.w32(0x676438, c.emu.stub_fn('_time32', tm))
    iat(c, 0x67643c, '_localtime32', 1, ret=tmb, pop=0)
    d = c.rng.choice([0, rbuf(c, 4)]); w = rbuf(c, 4)
    if c.rng.random() < 0.3: c.emu.w16(w, 0)
    return [rbuf(c, 4), d, w]
S(0x4d68e0, 'GUESS DOS date/time now', 'thiscall', None, ret=None, gen=g_4d68e0)


def g_4c8560(c):   # GUESS: toggle +0x52, Display(flag) for every 0x400000 geom of the scene list, scene+0xbae = flag
    patch(c, 0x4daa20, L('Display', 1))
    k = c.rng.randint(0, 5); gs = []
    for i in range(k):
        g = rbuf(c, 0x60)
        if c.rng.random() < 0.3: c.emu.w32(g + 0x54, 0)
        else:
            a = rbuf(c, 0x20); b = rbuf(c, 0x40); c.emu.w32(g + 0x54, a); c.emu.w32(a + 0xc, b)
            c.emu.w32(b + 0x23, c.rng.choice([0x400000, 0x200002, R(c)]))
        gs.append(g)
    nxt = {g: (gs[i + 1] if i + 1 < k else 0) for i, g in enumerate(gs)}
    def h50(e, r):
        p = e.arg32(0); cur = e.r32(p); e.calllog.append(('next', e.reg('ecx'), (cur,)))
        e.w32(p, nxt.get(cur, 0)); e.ret(eax=0, argbytes=4)
    lst = obj(c, 'lst', {0x50: h50}, size=0x10); c.emu.w32(lst + 8, gs[0] if k else 0)
    s = scene(c, {}, size=0xc00); c.emu.w32(s + 0xadc, lst)
    o = rbuf(c, 0x60); c.emu.w8(o + 0x52, c.rng.choice([0, 1, R(c)]))
    return [o]
S(0x4c8560, 'GUESS toggle display 0x400000 geoms', 'thiscall', None, ret=None, gen=g_4c8560)


def g_63ace0(c):   # ZDrawArray<ZCameraDrawEntry,...>::Add() (inlined take, 16-byte slots)
    def grow(e, r):
        s = e.reg('ecx'); ok = c.rng.random() < 0.7
        e.calllog.append(('grow', s, ()))
        if ok:
            b = e.alloc(0x200, 4); e.wbytes(b, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
            e.w16(b + 2, c.rng.choice([0xffff, c.rng.randint(0, 20)])); e.w32(s + 8, b)
        e.ret(eax=0x1 if ok else 0x100, argbytes=0)
    patch(c, 0x63b240, grow)
    n = c.rng.randint(0, 4); nodes = [rbuf(c, 0x200) for _ in range(n)]
    for nd in nodes: c.emu.w16(nd + 2, c.rng.choice([0xffff, 0xffff, c.rng.randint(0, 20)]))
    for i, nd in enumerate(nodes):
        c.emu.w32(nd + 8, nodes[i + 1] if i + 1 < n else (nodes[0] if c.rng.random() < 0.5 else 0))
    o = rbuf(c, 0x20); c.emu.w32(o + 8, nodes[c.rng.randint(0, n - 1)] if n else 0)
    return [o]
S(0x63ace0, 'ZDrawArray<ZCameraDrawEntry>::Add', 'thiscall', None, ret='eax', gen=g_63ace0)


def g_57d460(c):   # GUESS: map up to 4 ids (+0xac, -1 ends) through the range table [rm+0x190b], fetch each with 0x57dde0
    patch(c, 0x57dde0, L('f57dde0', 0, ret=c.rng.choice([R(c), R(c), R(c), 0])))
    rm = rbuf(c, 0x2000); c.emu.w32(0x70039c, rm)
    m = c.rng.randint(1, 4); tab = rbuf(c, 16 * m + 32); rngs = []
    base = 0
    for i in range(m):
        b = base + c.rng.choice([0, 0, c.rng.randint(1, 50)]); ln = c.rng.randint(1, 40); base = b + ln
        c.emu.w32(tab + 16 * i, b); c.emu.w32(tab + 16 * i + 12, ln); rngs.append((b, ln))
    c.emu.w32(tab + 16 * m, 0); c.emu.w32(tab + 16 * m + 12, 0x10000)   # catch-all row: every id below 0x10000 used matches
    nul = c.rng.random() < 0.15
    c.emu.w32(rm + 0x190b, 0 if nul else tab)
    o = rbuf(c, 0xc0)
    for j in range(4):
        b, ln = rngs[c.rng.randint(0, m - 1)]
        c.emu.w32(o + 0xac + 4 * j, c.rng.choice([b + c.rng.randint(0, ln - 1), b, b + ln - 1, b + ln, 0xffffffff, 0x10000 + c.rng.randint(0, 0xffff) * 0x10000 + c.rng.randint(0, 0xffff)]))
    return [o, rbuf(c, 0x20)]
S(0x57d460, 'GUESS map ids through range table', 'thiscall', None, ret='eax', gen=g_57d460)


def g_454b60(c):   # GUESS (fastcall): x = b ? 0x45c4f0(0x4c, b) : 0x45c4b0(0x4c); x ? 0x454980(x, a, ecx, edx) : 0
    patch(c, 0x45c4f0, L('alloc2', 2, pop=0, ecx=False, ret=c.rng.choice([0, R(c)])))
    patch(c, 0x45c4b0, L('alloc1', 1, pop=0, ecx=False, ret=c.rng.choice([0, R(c)])))
    patch(c, 0x454980, L('init', 3, ret=R(c)))
    return [R(c), R(c), R(c), c.rng.choice([0, R(c)])]
S(0x454b60, 'GUESS fastcall alloc + init', 'fastcall', None, ret='eax', gen=g_454b60)
