"""specs_s305.py - mounted gun batch 305: CopyEventDataBlock, Init2, Init.
DBREAD readers, ZBaseGeom::Hide are replaced by Python hooks that log their calls (both sides call the same address).
Name, GetPrev and striwcmp run as exe code on a fake geom-node array."""
from pilot import S, F
from mg_helpers import _rnd, _stub, _obj, flush, dispatch, crt_setup, cstr


def _hook_db(c, uvals, fvals):
    st = {'u': 0, 'f': 0}

    def hu(e, r):
        e.calllog.append(('db_u32', e.reg('ecx')))
        v = uvals[min(st['u'], len(uvals) - 1)]
        st['u'] += 1
        e.ret(eax=v)

    def hf(e, r):
        e.calllog.append(('db_f32', e.reg('ecx')))
        v = fvals[min(st['f'], len(fvals) - 1)]
        st['f'] += 1
        e.ret(st0=v)
    c.emu.hook(0x4e5e60, hu)
    c.emu.hook(0x4e5e80, hf)
    # per-case state is reset by re-hooking in every gen call; also reset when the port runs (same case)
    c.vars['dbstate'] = st


def _copy(c):
    r = c.rng
    k = r.random()
    deg = 0.0 if k < 0.08 else (r.uniform(0, 0.007) if k < 0.16 else (c.fv(0, 180) if k < 0.9 else c.fv()))
    _hook_db(c, [r.getrandbits(32), r.getrandbits(32)], [deg])
    s = _rnd(c, 0xa0)
    c.emu.wf32(s + 0x4c, c.fv(-3, 3))
    dbr = _rnd(c, 0x20)
    return [s, dbr]


NAMES = [b'PosBox', b'PosBox_Center', b'posbox_hand', b'PosBo', b'Gun', b'', b'PosBoxX', b'xPosBox']


def _db_fixture(c, extra_slots):
    r = c.rng
    eng = _rnd(c, 0x200)
    db = _obj(c, 0xb00, extra_slots)
    c.emu.w32(eng + 0x9b, db)
    c.emu.w32(0x70039c, eng)
    return eng, db


def _init2(c):
    r = c.rng
    crt_setup(c)
    hid = []

    def hide(e, rr):
        e.calllog.append(('Hide', e.reg('ecx'), e.arg32(0) & 0xff))
        e.ret(argbytes=4)
    c.emu.hook(0x4db860, hide)
    s = _rnd(c, 0xa0)
    n = r.randint(1, 8)
    arr = _rnd(c, 0x70 * n)
    for i in range(n):
        node = arr + 0x70 * i
        c.emu.w16(node + 0x5e, r.randint(0, i))
        if r.random() < 0.1:
            c.emu.w32(node + 0x54, 0)
        else:
            info = _rnd(c, 0x20)
            nm = r.choice(NAMES + [None])
            c.emu.w32(info + 4, 0 if nm is None else cstr(c, nm))
            cls = _rnd(c, 0x30)
            c.emu.w32(cls + 0x23, r.getrandbits(32) & (~0x100000 if r.random() < 0.85 else 0xffffffff))
            c.emu.w32(info + 0xc, cls)
            c.emu.w32(node + 0x54, info)
    arrobj = _obj(c, 0x10, {0x4c: _stub(c, 0, ret=arr)})
    cc = _rnd(c, 0x20) if r.random() < 0.7 else 0
    hh = _rnd(c, 0x20) if r.random() < 0.7 else 0
    g = _obj(c, 0x60, {0x25c: dispatch(c, {0x68886c: cc, 0x688860: hh}, argbytes=8)})
    c.emu.w32(g + 0x54, arr + 0x70 * (n - 1) if r.random() < 0.9 else 0)
    c.emu.w32(s + 0x44, g)
    gun = _obj(c, 0x20, {0x2f0: _stub(c, 3)})
    tmpl = _obj(c, 0x20, {0x2c4: _stub(c, 2, ret=gun)})
    ref = r.getrandbits(32)
    c.emu.w32(s + 0x68, ref)
    eng, db = _db_fixture(c, {0x58: dispatch(c, {ref: tmpl}), 0x4c: _stub(c, 1, ret=r.getrandbits(32))})
    c.emu.w32(db + 8, arrobj)
    flush(c)
    return [s]


def _init(c):
    r = c.rng
    s = _rnd(c, 0xa0)
    lst = _obj(c, 0x20, {0x218: _stub(c, 1)}) if r.random() < 0.5 else 0
    newl = _obj(c, 0x20, {0x218: _stub(c, 1)})
    root = _obj(c, 0x40, {0x25c: dispatch(c, {0x6b4a2c: lst}, argbytes=8), 0x294: _stub(c, 4, ret=newl)})
    sc = _obj(c, 0x80, {0x60: _stub(c, 3)})
    eng, db = _db_fixture(c, {0x4c: _stub(c, 1, ret=r.getrandbits(32)), 0x138: _stub(c, 0, ret=sc)})
    c.emu.w32(db + 0xadc, root)
    gd = _rnd(c, 0x2c40)
    c.emu.w32(0x7003b8, gd)
    flush(c)
    return [s]


S(0x5c8c50, 'CMachinegunControlGroup::CopyEventDataBlock', 'thiscall', None, gen=_copy, note='batch305; DBREAD hooked; CRT sin/cos')
S(0x5c8e00, 'CMachinegunControlGroup::Init2', 'thiscall', None, gen=_init2, note='batch305; Hide hooked')
S(0x5c8f10, 'CMachinegunControlGroup::Init', 'thiscall', None, gen=_init, note='batch305')
