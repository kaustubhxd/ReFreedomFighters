"""specs_s72.py - inline session batch 72: opening a fence gate. ZFenceGate NotifyPrisoners, the "Activate"
broadcast and SetOpen; ZFFHeroMovementOpenGate TerminateControl, WantControl, GotControl, Move and GetActiveAnim.
RestoreItem, SetTempItem with GetItem (on a small inventory holding items of types 1 and 2, so the item type is
seen), SetUseAction, ProgressValue, the meter switch, mreset, vneg, mpul and the gate functions run as exe code.
ZFFHERO::AdjustHitPoints (0x58b9c0, damage code) is patched per run with a jump to a recorder that returns a random
hit-point value on the x87 stack (the image is marked dirty so the next run restores it). Gates hold handle lists
(prisoners +0x1ae, +0x100, +0x54) whose iterators are small stateful stubs; the render manager's slot 0x58 maps the
handles to recorder objects (some null)."""
import struct
from pilot import S
import specs_s53 as k53
import specs_s60 as k60
import specs_s70 as k70
import specs_s71 as k71

_rnd, _stub, _obj = k53._rnd, k53._stub, k53._obj
_seq, _fv = k60._seq, k60._fv
_mat, _vec, M9, XYZ = k71._mat, k71._vec, k71.M9, k71.XYZ
P = lambda v: struct.pack('<I', v & 0xffffffff)


def _code(c, b):
    a = c.emu.alloc(len(b) + 16, 16)
    c.emu.wbytes(a, b)
    return a


def _copy2(c, nargs, ret=0):
    """thiscall recorder that copies three dwords from each of the first two (pointer) args, and the rest by value."""
    rec = c.emu.alloc(4 * (6 + nargs + 1), 4)
    code = b''
    for ai in (0, 1):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])
        for j in range(3):
            code += b'\x8b\x50' + bytes([4 * j]) + b'\x89\x15' + P(rec + 4 * (3 * ai + j))
    for i in range(2, nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + P(rec + 4 * (6 + i))
    code += b'\xff\x05' + P(rec + 4 * (6 + nargs)) + b'\xb8' + P(ret) + b'\xc2' + struct.pack('<H', 4 * nargs)
    return _code(c, code)


def _list(c, handles):
    """An embedded handle list's vtable: slot 0x4c(&it) starts, slot 0x5c(&it) returns the next handle, it 0 at the
    end. Returns the vtable."""
    k = len(handles)
    tab = c.emu.alloc(4 * (k + 2), 4)
    for i, h in enumerate(handles):
        c.emu.w32(tab + 4 * (i + 1), h)
    start = _code(c, b'\x8b\x4c\x24\x04\xc7\x01' + P(k + 1) + b'\xc2\x04\x00')
    nxt = _code(c, b'\x8b\x4c\x24\x04\x8b\x01\x85\xc0\x74\x0a\x48\x89\x01\x8b\x04\x85' + P(tab) + b'\xc2\x04\x00')
    vt = c.emu.alloc(0x60, 4)
    c.emu.w32(vt + 0x4c, start)
    c.emu.w32(vt + 0x5c, nxt)
    return vt


def _gate(c, pairs, hero_pos):
    """A ZFenceGate with geometry (handle +0x50) near the hero and three handle lists. Adds its handles to pairs."""
    r = c.rng
    g = _rnd(c, 0x280)
    c.emu.wbytes(g + 0x25a, bytes([r.choice((0, 0, 1)), r.choice((0, 0, 0, 1))]))
    c.emu.w16(g + 0x1ac, r.getrandbits(16))
    for off in (0x54, 0x100, 0x1ae):
        hs = []
        for _ in range(r.choice((0, 1, 2, 3))):
            h = r.getrandbits(32) | 1
            hs.append(h)
            if r.random() < 0.85:
                pairs.append((h, _obj(c, 0x140, {0x128: _seq(c, 3, [0])})))
        c.emu.w32(g + off, _list(c, hs))
    h = r.getrandbits(32) | 1
    c.emu.w32(g + 0x50, h)
    if r.random() < 0.9:
        near = [hero_pos[0] - 397.63, hero_pos[1] - 60.0, hero_pos[2] + 33.76]   # handle point + 60 lands near
        geo = _obj(c, 0x140, {0x84: _stub(c, 1, skip=(0,), adds=((0, _vec(c, near, 110), 3),)),
                              0x98: _stub(c, 2, skip=(0, 1), adds=((1, _vec(c, hero_pos, 120), 3),),
                                          fills=((0, _mat(c), 9),)),
                              0x128: _seq(c, 3, [0])})
        pairs.append((h, geo))
    return g


def _inventory(c, h, pairs):
    """Inventory info for types 1 and 2 (and a random one) and an inventory list holding their items."""
    r = c.rng
    vals = [0x1000, 0x2000, 0x3000]
    types = [1, 2, r.randint(0, 5)]
    r.shuffle(types)
    for i in range(3):
        e = _rnd(c, 0x20)
        c.emu.w32(e, vals[i])
        c.emu.w32(e + 0x10, types[i])
        c.emu.w32(h + 0x95f + 4 * i, e)
    c.emu.w32(h + 0x95b, 3)
    hs = []
    items = []
    for v in vals:
        it = _obj(c, 0x20, {0x2e8: _code(c, b'\x8b\x41\x08\xc3')})
        c.emu.w32(it + 8, v)
        hh = r.getrandbits(32) | 1
        pairs.append((hh, it))
        hs.append(hh)
        items.append(it)
    lst = _obj(c, 0x10, {0x48: _code(c, b'\x8b\x44\x24\x04\xc7\x00' + P(len(hs) + 1) + b'\xc2\x04\x00')})
    tab = c.emu.alloc(4 * (len(hs) + 2), 4)
    for i, hh in enumerate(hs):
        c.emu.w32(tab + 4 * (i + 1), hh)
    vt = c.emu.r32(lst)
    vt2 = c.emu.alloc(0x60, 4)
    c.emu.w32(vt2 + 0x48, c.emu.r32(vt + 0x48))
    c.emu.w32(vt2 + 0x58, _code(c, b'\x8b\x4c\x24\x04\x8b\x01\x85\xc0\x74\x0a\x48\x89\x01\x8b\x04\x85' + P(tab)
                                + b'\xc2\x04\x00'))
    c.emu.w32(lst, vt2)
    inv = _obj(c, 0x10, {0xa0: _stub(c, 0, ret=lst)})
    return inv, items


def _patch_ahp(c):
    """AdjustHitPoints(float, handle, bool) -> float on x87: jump to a recorder for this run."""
    r = c.rng
    hp = _fv(c, [r.choice((-50.0, -0.5, 0.0, 10.0, 150.0))])
    stub = _stub(c, 3, fld=hp)
    c.emu.wbytes(0x58b9c0, b'\xb8' + P(stub) + b'\xff\xe0')
    c.emu._image_dirty = True


def _world(c, hero_pos):
    r = c.rng
    pairs = []
    L = _rnd(c, 0x2c20)
    gates = [_gate(c, pairs, hero_pos) for _ in range(r.choice((0, 1, 1, 2, 3)))]
    c.emu.w32(L + 0xbe5, len(gates))
    for i, g in enumerate(gates):
        c.emu.w32(L + 0xbe9 + 4 * i, g)
    c.emu.w32(0x7003b8, L)
    return L, pairs, gates


def _finish(c, pairs):
    r = c.rng
    rm = _obj(c, 0x120, {0x58: k60._map(c, pairs, 0), 0x114: _seq(c, 4, [r.getrandbits(32) for _ in range(4)]),
                         0x4c: _seq(c, 1, [r.getrandbits(32) for _ in range(3)])})
    k70._sys(c, rm)
    c.emu.w32(0x7003b0, _stub(c, 0))
    _patch_ahp(c)
    return rm


def _hero(c, hero_pos, pairs):
    r = c.rng
    h = _obj(c, 0xa00, {0x59c: _stub(c, 2, skip=(0, 1), fills=((0, _mat(c), 9), (1, _fv(c, hero_pos), 3))),
                        0x438: _stub(c, 0, ret=r.choice((0, 0, 0, 0, 1, 0x100))),
                        0x5b4: _stub(c, 0, fld=_fv(c, [r.choice((0.0, 12.5, r.uniform(-50, 50)))])),
                        0x5bc: _copy2(c, 3), 0x3dc: _stub(c, 0), 0x480: _stub(c, 1),
                        0x504: _stub(c, 0, ret=0), 0x464: _stub(c, 0, ret=0)})
    inv, items = _inventory(c, h, pairs)
    # hand item: none, the crowbar (type 1's item), another item or junk
    c.emu.w32(c.emu.r32(h) + 0x504, _stub(c, 0, ret=r.choice([0, r.getrandbits(32)] + items)))
    c.emu.w32(c.emu.r32(h) + 0x464, _stub(c, 0, ret=inv))
    c.emu.w32(h + 0x852, _rnd(c, 0x2300))
    c.emu.w32(h + 0x832, r.choice((0, 0, r.getrandbits(32))))
    c.emu.w32(h + 0x836, r.getrandbits(32) & r.choice((0xffffffdf, 0xffffffff)))
    c.emu.w32(h + 0x9d3, r.choice((8, 8, 8, 10, 0, r.getrandbits(32))))
    c.emu.wbytes(h + 0x66c, bytes([r.choice((0, 1, 1))]))
    c.emu.wf32(h + 0x9e3, r.choice((0.0, 0.0, r.uniform(1, 100))))
    return h


def _anim(c):
    r = c.rng
    a = _rnd(c, 0x80)
    c.emu.w32(a + 0x60, r.choice((0, 0, 1)))
    c.emu.w32(a + 0x64, r.choice((60, 150, 170, r.randint(30, 260))))
    c.emu.w32(a + 0x6c, r.choice((25, 30, r.randint(1, 60))))
    return a


def _self(c, h, gates):
    r = c.rng
    s = _obj(c, 0x600, {0x48: _stub(c, 5, ret=r.choice((0, 1, 0x100)))})
    c.emu.w32(s + 0x36d, h)
    c.emu.wbytes(s + 0x54c, bytes([r.choice((0, 1, 1)), r.choice((0, 0, 1)), r.choice((0, 0, 1))]))
    now = c.emu.r32(c.emu.r32(0x70039c) + 0x40)
    nows = (now if now < 1 << 31 else now - (1 << 32)) / 1024.0
    c.emu.wf32(s + 0x54f, r.choice((nows, nows - r.uniform(0, 0.4), nows - r.uniform(0, 10), nows - r.uniform(1, 7))))
    c.emu.w32(s + 0x553, _anim(c) if r.random() < 0.95 else 0)
    c.emu.w32(s + 0x557, _anim(c) if r.random() < 0.9 else 0)
    c.emu.w32(s + 0x55b, r.choice(gates) if gates else 0)
    c.emu.wbytes(s + 0x55f, b''.join(struct.pack('<f', r.uniform(-500, 500)) for _ in range(6)))
    c.emu.wbytes(s + 0x577, b''.join(struct.pack('<f', r.uniform(-1, 1)) for _ in range(18)))
    return s


def _setup(c, need_gate=False):
    r = c.rng
    hp = [r.uniform(-2000, 2000) for _ in range(3)]
    if r.random() < 0.03:
        hp[r.randint(0, 2)] = float('nan')
    while True:
        L, pairs, gates = _world(c, hp)
        if gates or not need_gate:
            break
    h = _hero(c, hp, pairs)
    _finish(c, pairs)        # the game object (current time) must exist before _self reads it
    s = _self(c, h, gates)
    a = c.emu.r32(s + (0x557 if c.emu.r8(s + 0x54e) else 0x553))
    if r.random() < 0.3 and a:
        k71._exact_start(c, s, a, (36, 140, c.emu.r32(a + 0x64) - c.emu.r32(a + 0x60) + 1))
    return s, hp


def _gfn(c, open_arg=False):
    r = c.rng
    hp = [0.0, 0.0, 0.0]
    pairs = []
    g = _gate(c, pairs, hp)
    _finish(c, pairs)
    c.emu.mu.ctl_flush_tb()
    if open_arg:
        return [g, r.choice((0, 1, 1, 0x100, r.getrandbits(32)))]
    return [g, r.getrandbits(32)]


def _notify(c):
    return _gfn(c)


def _activate(c):
    return _gfn(c)[:1]


def _setopen(c):
    return _gfn(c, True)


def _term(c):
    s, _ = _setup(c)
    c.emu.mu.ctl_flush_tb()
    return [s, c.rng.choice((0, 1, 0x100))]


def _want(c):
    s, hp = _setup(c)
    c.emu.mu.ctl_flush_tb()
    return [s, _vec(c, hp, 1), _fv(c, hp), _vec(c, hp, 1)]


def _got(c):
    s, _ = _setup(c, need_gate=True)
    c.emu.mu.ctl_flush_tb()
    return [s]


def _move(c):
    r = c.rng
    s, hp = _setup(c)
    m = _mat(c) if r.random() < 0.5 else _fv(c, [1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0])
    k = r.random()
    if k < 0.3:
        c.emu.wbytes(s + 0x59b, c.emu.rbytes(s + 0x577, 36))
    elif k < 0.5:
        ident = b''.join(struct.pack('<f', v) for v in (1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0))
        c.emu.wbytes(s + 0x577, ident)
        c.emu.wbytes(s + 0x59b, b''.join(struct.pack('<f', v + r.uniform(-0.3, 0.3)) for v in
                                         (1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0)))
    outm, outp, outv = _rnd(c, 0x30), _rnd(c, 0x10), _rnd(c, 0x10)
    c.emu.mu.ctl_flush_tb()
    return [s, m, _vec(c, hp, 50), outm, outp, outv]


def _gaa(c):
    s, _ = _setup(c, need_gate=True)
    out = _rnd(c, 4)
    c.emu.mu.ctl_flush_tb()
    return [s, out, 0, 0, 0, 0]


S(0x5c27f0, 'ZFenceGate::NotifyPrisoners', 'thiscall', None, ret=None, gen=_notify, note='batch72')
S(0x5c26f0, 'ZFenceGate Activate broadcast', 'thiscall', None, ret=None, gen=_activate, note='batch72')
S(0x5c2940, 'ZFenceGate::SetOpen', 'thiscall', None, ret=None, gen=_setopen, note='batch72')
S(0x5e73c0, 'ZFFHeroMovementOpenGate::TerminateControl', 'thiscall', None, ret='al', gen=_term, note='batch72')
S(0x5e86f0, 'ZFFHeroMovementOpenGate::WantControl', 'thiscall', None, ret='al', gen=_want, note='batch72')
S(0x5e5460, 'ZFFHeroMovementOpenGate::GotControl', 'thiscall', None, ret=None, gen=_got, note='batch72')
S(0x5e6d60, 'ZFFHeroMovementOpenGate::Move', 'thiscall', None, ret=None, gen=_move, note='batch72; mpul as exe code')
S(0x5e2f20, 'ZFFHeroMovementOpenGate::GetActiveAnim', 'thiscall', None, ret='st0', gen=_gaa,
  note='batch72; AdjustHitPoints patched to a recorder')
