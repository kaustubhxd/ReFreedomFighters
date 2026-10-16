"""specs_f1003.py - fresh-10 batch 3: destructors, save/load helpers, list walkers (slice 10)."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from h10 import L, obj, rbuf, patch, iat, log_obj


def R(c): return c.rng.getrandbits(32)
def fbits(c): return struct.unpack('<I', struct.pack('<f', c.fv()))[0]


def g_4d4d60(c):   # ZBigFile::~ZBigFile (scalar deleting)
    patch(c, 0x634273, L('delete', 2, pop=0, ecx=False))
    return [rbuf(c, 0x40), R(c)]
S(0x4d4d60, 'ZBigFile::~ZBigFile (scalar deleting)', 'thiscall', None, ret='eax', gen=g_4d4d60)


def g_4f6820(c):   # CAutoScroller::FrameUpdate
    rm = rbuf(c, 0x100); c.emu.w32(0x70039c, rm); c.emu.w32(rm + 0x48, fbits(c))
    tgt = obj(c, 'tgt', {0x374: L('vt374', 2)}, size=0x100); c.emu.w32(tgt + 0xa3, fbits(c))
    o = rbuf(c, 0x60); c.emu.w32(o + 0x44, tgt); c.emu.w32(o + 0x4c, fbits(c))
    c.emu.w8(o + 0x50, c.rng.choice([0, 0, 1, R(c)])); c.emu.w8(o + 0x51, c.rng.choice([0, 0, 1, R(c)]))
    return [o]
S(0x4f6820, 'CAutoScroller::FrameUpdate', 'thiscall', None, ret=None, gen=g_4f6820)


def g_5f3160(c):   # SerialInfo_t::savebool(bool)
    buf = rbuf(c, 0x40); o = rbuf(c, 0x20)
    pos = buf + 4 * c.rng.randint(0, 8)
    c.emu.w32(o + 8, pos); c.emu.w32(o + 0xc, pos + c.rng.choice([0, 3, 4, 5, 8, 100]))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert', L('assert', 0, ecx=False)))
    return [o, R(c)]
S(0x5f3160, 'SerialInfo_t::savebool', 'thiscall', None, ret=None, gen=g_5f3160)


def g_4f42a0(c):   # ZWINPIC::SaveGeometry(ZSaveGame*)
    sv = obj(c, 'save', {0x3c: L('save3c', 1), 0x24: L('save24', 1)}, size=0x10)
    return [rbuf(c, 0x60), sv]
S(0x4f42a0, 'ZWINPIC::SaveGeometry', 'thiscall', None, ret=None, gen=g_4f42a0)


def g_49b2e0(c):   # ZLoadGame::Load(id): find the 16-byte entry whose first dword is id+1; else the assert hook
    n = c.rng.randint(0, 8)
    tab = rbuf(c, 16 * n + 16)
    ids = [c.rng.randint(0, 12) for _ in range(n)]
    for i, v in enumerate(ids): c.emu.w32(tab + 16 * i, v)
    o = rbuf(c, 0x20); c.emu.w32(o + 8, n); c.emu.w32(o + 0x10, tab)
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert', L('assert', 0, ret=R(c), ecx=False)))
    return [o, c.rng.choice([c.rng.randint(0, 12) - 1, 0xffffffff, R(c)])]
S(0x49b2e0, 'ZLoadGame::Load', 'thiscall', None, ret='eax', gen=g_49b2e0)


def g_4ce960(c):   # ALLOCREF::PrintRef(unsigned)
    log_obj(c, 4)
    return [rbuf(c, 0x20), R(c)]
S(0x4ce960, 'ALLOCREF::PrintRef', 'thiscall', None, ret=None, gen=g_4ce960)


def g_4cfae0(c):   # GUESS: pop every entry of the table at +8 (count +0x1c8), free(entry[-1]) each
    iat(c, 0x6762ec, 'free', 1, pop=0)
    o = rbuf(c, 0x200)
    n = c.rng.randint(0, 6)
    c.emu.w32(o + 0x1c8, n)
    for i in range(n): c.emu.w32(o + 8 + 4 * i, rbuf(c, 0x10) + 4)
    return [o]
S(0x4cfae0, 'GUESS free all (count +0x1c8)', 'thiscall', None, ret=None, gen=g_4cfae0)


def g_4b1c20(c):   # ZCutPushSceneOnKeyStart::FrameUpdate
    keys = obj(c, 'keys', {0x2c: L('keys2c', 2, ret=c.rng.choice([0, 1, 0x100, R(c)]))}, size=0x10)
    scn = obj(c, 'scn', {0xa8: L('scna8', 0), 0xa0: L('scna0', 1)}, size=0x10)
    rm = rbuf(c, 0x2000); c.emu.w32(rm + 0x1907, keys); c.emu.w32(rm + 0x9b, scn); c.emu.w32(0x70039c, rm)
    return [rbuf(c, 0x60)]
S(0x4b1c20, 'ZCutPushSceneOnKeyStart::FrameUpdate', 'thiscall', None, ret=None, gen=g_4b1c20)


def _w61ce20(v):
    def h(e, r):
        args = tuple(e.arg32(k) for k in range(5))
        e.calllog.append(('f61ce20', 0, args))
        e.w32(args[2], v)
        e.ret(eax=0, argbytes=0)
    return h


def g_61cce0(c):   # GUESS cdecl(obj, a, b, d): 0x61ce20(obj, [obj+0x8c], &a, b, d); if a: set +0x110, 0x61d090(...)
    patch(c, 0x61ce20, _w61ce20(c.rng.choice([0, R(c)])))
    patch(c, 0x61d090, L('f61d090', 6, pop=0, ecx=False))
    return [rbuf(c, 0x120), R(c), R(c), R(c)]
S(0x61cce0, 'GUESS 0x61ce20 then 0x61d090', 'cdecl', None, ret=None, gen=g_61cce0)


def g_444260(c):   # ZROOM::AttachGeom(ZBaseGeom*, bool, bool)
    patch(c, 0x43ef30, L('ZGROUP::AttachGeom', 3))
    scn = obj(c, 'scn', {0x50: L('scn50', 1, ret=R(c))}, size=0x10); rm = rbuf(c, 0x100)
    c.emu.w32(rm + 0x9b, scn); c.emu.w32(0x70039c, rm)
    g = rbuf(c, 0x60); r = c.rng.random()
    if r < 0.2: c.emu.w32(g + 0x54, 0)
    else:
        a = rbuf(c, 0x20); b = rbuf(c, 0x40); c.emu.w32(g + 0x54, a); c.emu.w32(a + 0xc, b)
        if r < 0.7: c.emu.w32(b + 0x23, 0x200015)
    return [obj(c, 'room', {0x360: L('room360', 1)}), g, R(c), R(c)]
S(0x444260, 'ZROOM::AttachGeom', 'thiscall', None, ret=None, gen=g_444260)


def _drawadd(grow, take):
    def g(c):
        patch(c, grow, L('grow', 0, ret=c.rng.choice([0, 1, 0x100, R(c)])))
        patch(c, take, L('take', 0, ret=R(c)))
        n = c.rng.randint(0, 5)
        nodes = [rbuf(c, 0x10) for _ in range(n)]
        for nd in nodes:
            c.emu.w16(nd + 2, c.rng.choice([0xffff, 0xffff, R(c) & 0xffff]))
        for i, nd in enumerate(nodes):
            nxt = nodes[i + 1] if i + 1 < n else (nodes[0] if c.rng.random() < 0.5 else 0)
            c.emu.w32(nd + 8, nxt)
        o = rbuf(c, 0x20); c.emu.w32(o + 8, nodes[c.rng.randint(0, n - 1)] if n else 0)
        return [o]
    return g
S(0x6482a0, 'ZDrawArray<ZCameraViewEntry>::Add', 'thiscall', None, ret='eax', gen=_drawadd(0x648c50, 0x648630))
S(0x6483e0, 'ZDrawArray<ZLightViewEntry>::Add', 'thiscall', None, ret='eax', gen=_drawadd(0x63b3c0, 0x648690))


def g_6361e0(c):   # GUESS constructor (vtable 0x6c2114, 'ABGR' at +4)
    return [rbuf(c, 0x40)]
S(0x6361e0, 'GUESS ctor 0x6c2114', 'thiscall', None, ret='eax', gen=g_6361e0)


def _new(c):
    def h(e, r):
        n = e.arg32(0)
        e.calllog.append(('new', 0, (n,)))
        e.ret(eax=e.alloc(min(n, 0x400) + 4, 4), argbytes=0)
    return h


def g_5ff0a0(c):   # GUESS: double a u16 array (new 4n bytes, copy n, free old)
    patch(c, 0x41e290, _new(c)); patch(c, 0x41e2c0, L('free', 1, pop=0, ecx=False))
    n = c.rng.randint(0, 64); o = rbuf(c, 0x10)
    c.emu.w32(o, rbuf(c, 2 * n + 4)); c.emu.w32(o + 4, n)
    return [o]
S(0x5ff0a0, 'GUESS u16 array grow x2', 'thiscall', None, ret=None, gen=g_5ff0a0)


def _iter(elems):
    st = {'k': 0}
    def h4c(e, r):
        p = e.arg32(0)
        e.calllog.append(('it4c', e.reg('ecx'), (p,)))
        e.wbytes(p, b'\x11' * 12); st['k'] = 0
        e.ret(eax=0x1234, argbytes=4)
    def h5c(e, r):
        p = e.arg32(0); k = st['k']; st['k'] += 1
        e.calllog.append(('it5c', e.reg('ecx'), (p,)))
        e.w32(p, 1 if k < len(elems) else 0); e.w32(p + 4, k)
        e.ret(eax=elems[k] if k < len(elems) else 0x5555, argbytes=4)
    return h4c, h5c


def g_454f20(c):   # ZMaterialDescGroup::GetMaterialDescriptor(id)
    n = c.rng.randint(0, 6)
    elems = [rbuf(c, 0x40) for _ in range(n)]
    for e_ in elems: c.emu.w32(e_ + 0x34, c.rng.randint(0, 8))
    h4c, h5c = _iter(elems)
    o = rbuf(c, 0x80)
    c.emu.w32(o + 0x5c, 0 if c.rng.random() < 0.15 else obj(c, 'grp', {0x4c: h4c, 0x5c: h5c}, size=0x10))
    return [o, c.rng.randint(0, 8)]
S(0x454f20, 'ZMaterialDescGroup::GetMaterialDescriptor', 'thiscall', None, ret='eax', gen=g_454f20, stack_arg_bytes=12)
