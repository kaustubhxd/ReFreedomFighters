"""specs_s70.py - inline session batch 70: sewer-entry helpers. ZFFHERO::RestoreItem and SetTempItem (GetItem and
GetInventoryInfo as exe code on the batch 49 inventory walk), mmtmul and the in-place 0x4de4f0 (vmtmul as exe code),
and COpenSewer::ActivateMenu. The database lookup (slot 0x88) is a per-call stub that writes a per-call handle through
its out pointer; RegisterZMsg is a per-call log."""
import struct
from pilot import S
import specs_s53 as k53
import specs_s60 as k60
import specs_s49 as k49
import specs_s69 as k69

_rnd, _stub, _obj = k53._rnd, k53._stub, k53._obj
_seq, _fv = k60._seq, k60._fv
P = lambda v: struct.pack('<I', v & 0xffffffff)


def _dbstub(c, vals):
    """thiscall (name, out*), ret 8: logs the name per call and writes vals[call] to *out."""
    tab = c.emu.alloc(16, 4)
    c.emu.wbytes(tab, b''.join(P(v) for v in (list(vals) * 4)[:4]))
    cnt = c.emu.alloc(4, 4)
    log = c.emu.alloc(16, 4)
    code = b'\xa1' + P(cnt) + b'\x83\xe0\x03\x8b\x54\x24\x04\x89\x14\x85' + P(log)
    code += b'\x8b\x14\x85' + P(tab) + b'\x8b\x44\x24\x08\x89\x10\xff\x05' + P(cnt) + b'\xc2\x08\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _sys(c, rm):
    r = c.rng
    gobj = _rnd(c, 0x1ab0)
    c.emu.w32(gobj + 0x40, r.choice((r.randint(0, 1 << 22), r.getrandbits(32))))
    c.emu.w32(gobj + 0x9b, rm)
    c.emu.wf32(gobj + 0x9c7, 0.0)
    c.emu.w32(0x70039c, gobj)
    l = _obj(c, 0x10, {0x2c: k69._cdecl(c, 2)})
    c.emu.w32(0x700390, _obj(c, 0x10, {0x20: _stub(c, 2, ret=l)}))
    return gobj


def _restore(c):
    r = c.rng
    h = _obj(c, 0x900, {0x3dc: _stub(c, 0), 0x480: _stub(c, 1), 0x504: _stub(c, 0, ret=r.choice((0, r.getrandbits(32))))})
    c.emu.w32(h + 0x836, r.getrandbits(32) & r.choice((0x20, 0xffffffff, 0xffffffdf)))
    c.emu.w32(h + 0x832, r.choice((0, r.getrandbits(32))))
    c.emu.mu.ctl_flush_tb()
    return [h]


def _settemp(c):
    r = c.rng
    n = r.randint(1, 5)
    table = c.emu.alloc(4 * n + 4, 4)
    items = []
    for i in range(n):
        it = _obj(c, 0x20, {0x2e8: k49._code(c, b'\x8b\x41\x08\xc3')})
        c.emu.w32(it + 8, r.choice((0x1000, 0x2000, 0x3000)))
        c.emu.w32(table + 4 * i, it)
        items.append(it)
    rm = _obj(c, 0x60, {0x58: k49._code(c, b'\x8b\x44\x24\x04\x8b\x04\x85' + P(table) + b'\xc2\x04\x00'),
                        0x4c: _seq(c, 1, [r.getrandbits(32), r.getrandbits(32)])})
    _sys(c, rm)
    c.emu.w32(0x7003b0, _stub(c, 0))
    lst = _obj(c, 0x10, {0x48: k49._code(c, b'\x8b\x44\x24\x04\xc7\x00' + P(n) + b'\xc2\x04\x00'),
                         0x58: k49._code(c, b'\x8b\x4c\x24\x04\x8b\x01\x48\x89\x01\xc2\x04\x00')})
    inv = _obj(c, 0x10, {0xa0: _stub(c, 0, ret=lst if r.random() < 0.9 else 0)})
    cur = r.choice(items + [0, r.getrandbits(32)])
    h = _obj(c, 0x970, {0x464: _stub(c, 0, ret=inv), 0x504: _stub(c, 0, ret=cur), 0x3dc: _stub(c, 0),
                        0x480: _stub(c, 1)})
    ntype = r.randint(0, 3)
    c.emu.w32(h + 0x95b, ntype)
    for i in range(ntype):
        e = _rnd(c, 0x20)
        c.emu.w32(e, r.choice((0, 0x1000, 0x2000, 0x3000)))
        c.emu.w32(e + 0x10, r.randint(0, 3))
        c.emu.w32(h + 0x95f + 4 * i, e)
    c.emu.w32(h + 0x832, 0 if r.random() < 0.8 else r.getrandbits(32))
    c.emu.w32(h + 0x836, r.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return [h, r.randint(0, 3)]


def _m9(c):
    r = c.rng
    c.emu.alloc(0x10, 16)
    return _fv(c, [r.choice((r.uniform(-2, 2), r.uniform(-1e3, 1e3), 0.0, c.fv())) for _ in range(9)])


def _mmt(c):
    d, a, m = _m9(c), _m9(c), _m9(c)
    x = c.rng.random()
    if x < 0.2:
        return [d, a, d]           # dst aliases m: row order then matters
    return [d, a if x < 0.6 else d, m]


def _mmti(c):
    m, n = _m9(c), _m9(c)
    return [m, c.rng.choice((n, n, n, m))]


def _menu(c):
    r = c.rng
    hv, vv = r.choice((0, r.getrandbits(32))), r.getrandbits(32)
    db = _obj(c, 0x10, {0x88: _dbstub(c, [hv, vv])})
    x = _rnd(c, 0x100)
    wvt = c.emu.alloc(0x20, 4)
    c.emu.w32(wvt + 0x14, _stub(c, 0, ret=r.choice((0, 0, 1, r.getrandbits(32)))))
    c.emu.w32(x + 0xcb, wvt)
    menu = _obj(c, 0x20, {0x2c4: _stub(c, 0, ret=x)})
    rm = _obj(c, 0x120, {0x138: _stub(c, 0, ret=db), 0x114: _seq(c, 4, [r.getrandbits(32), r.getrandbits(32)]),
                         0x58: k60._map(c, [(vv, menu)], menu), 0xb4: _stub(c, 1)})
    g = _sys(c, rm)
    c.emu.w32(g + 0x1a9f, _obj(c, 0x140, {0x138: _stub(c, 1)}) if r.random() < 0.8 else 0)
    lid = _obj(c, 0x20, {0x12c: _stub(c, 3), 0x130: _stub(c, 3)})
    self = _rnd(c, 0x60)
    c.emu.w32(self + 0x44, lid)
    c.emu.mu.ctl_flush_tb()
    return [self, r.getrandbits(32)]


S(0x594590, 'ZFFHERO::RestoreItem', 'thiscall', None, ret=None, gen=_restore, note='batch70')
S(0x595010, 'ZFFHERO::SetTempItem', 'thiscall', None, ret=None, gen=_settemp, note='batch70; GetItem as exe code')
S(0x4de4b0, 'mmtmul', 'fastcall', None, ret=None, gen=_mmt, note='batch70; vmtmul as exe code')
S(0x4de4f0, 'mmtmul in place', 'fastcall', None, ret=None, gen=_mmti, note='batch70; vmtmul as exe code')
S(0x5c3860, 'COpenSewer::ActivateMenu', 'thiscall', None, ret=None, gen=_menu, note='batch70')
