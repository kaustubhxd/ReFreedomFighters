"""specs_s306.py - mounted gun batch 306: ZEventBase ctor, nest ctor, allocator wrapper, deleting dtor, Save, Load.
Calls into the database and the save/load objects go to one ordered log (log_stub)."""
from pilot import S
from mg_helpers import _rnd, _stub, _obj, flush, new_log, log_stub


def _eng(c, slots, log):
    r = c.rng
    eng = _rnd(c, 0x200)
    db = _obj(c, 0xb00, slots)
    k = r.random()
    c.emu.wf32(db + 0xae0, r.choice([0.0, 0.9, 0.95, 1.0]) if k < 0.3 else (c.fv(0, 1.2) if k < 0.9 else c.fv()))
    c.emu.w32(eng + 0x40, r.getrandbits(32) if r.random() < 0.2 else r.randint(0, 1 << 24))
    c.emu.w32(eng + 0x9b, db)
    c.emu.w32(0x70039c, eng)
    return eng, db


def _base(c):
    log = new_log(c)
    _eng(c, {0x30: log_stub(c, log, 0x30, 1)}, log)
    flush(c)
    return [_rnd(c, 0xa0)]


def _ctor(c):
    log = new_log(c)
    _eng(c, {0x30: log_stub(c, log, 0x30, 1), 0x114: _reg4(c, log)}, log)
    flush(c)
    return [_rnd(c, 0xa0)]


def _reg4(c, log):
    """slot 0x114 (name, 0, file, line): logs the name and the line, returns a random u16 id."""
    return log_stub(c, log, 0x114, 4, ret=c.rng.getrandbits(16), args=(0, 3))


def _alloc(c):
    r = c.rng
    log = new_log(c)
    mem = _rnd(c, 0xa0) if r.random() < 0.8 else 0
    a = _obj(c, 0x60, {0x44: log_stub(c, log, 0x44, 1, ret=mem)})
    eng, db = _eng(c, {0x30: log_stub(c, log, 0x30, 1), 0x114: _reg4(c, log)}, log)
    c.emu.w32(db + 8, a)
    flush(c)
    return [r.getrandbits(32)]


def _dtor(c):
    r = c.rng
    log = new_log(c)
    _eng(c, {0x34: log_stub(c, log, 0x34, 1)}, log)
    k = r.random()
    c.emu.w32(0x7003b0, log_stub(c, log, 0xa55e, 0) if k < 0.7 else 0)
    flush(c)
    return [_rnd(c, 0xa0), r.choice([0, 1, 4, 5, 3, 7, r.getrandbits(32)])]


def _save(c):
    log = new_log(c)
    sg = _obj(c, 0x80, {0x4c: log_stub(c, log, 0x4c, 1), 0x3c: log_stub(c, log, 0x3c, 1),
                        0x64: log_stub(c, log, 0x64, 1)})
    flush(c)
    return [_rnd(c, 0xa0), sg]


def _load(c):
    r = c.rng
    log = new_log(c)
    stream = c.emu.alloc(4 * 40, 4)
    for i in range(40):
        c.emu.w32(stream + 4 * i, r.getrandbits(32))
    cur = c.emu.alloc(4, 4)
    c.emu.w32(cur, stream)
    lg = _obj(c, 0x80, {0x50: log_stub(c, log, 0x50, 1, stream=cur), 0x40: log_stub(c, log, 0x40, 1, stream=cur)})
    # the list ref read from the stream is the 15th dword (8 floats + 5 dwords + 1): map it with a logging slot 0x58
    eng = _rnd(c, 0x200)
    db = _obj(c, 0x100, {0x58: log_stub(c, log, 0x58, 1, ret=r.getrandbits(32))})
    c.emu.w32(eng + 0x9b, db)
    c.emu.w32(0x70039c, eng)
    flush(c)
    return [_rnd(c, 0xa0), lg]


S(0x469870, 'ZEventBase::ZEventBase', 'thiscall', None, ret='eax', gen=_base, note='batch306')
S(0x5c7f50, 'CMachinegunControlGroup::CMachinegunControlGroup', 'thiscall', None, ret='eax', gen=_ctor, note='batch306')
S(0x5c85e0, 'MGCG allocOne', 'thiscall', None, ret='eax', gen=_alloc, note='batch306')
S(0x5c81e0, 'CMachinegunControlGroup deleting dtor', 'thiscall', None, ret='eax', gen=_dtor, note='batch306')
S(0x5c9180, 'CMachinegunControlGroup::Save', 'thiscall', None, ret='al', gen=_save, note='batch306')
S(0x5c8fc0, 'CMachinegunControlGroup::Load', 'thiscall', None, ret='al', gen=_load, note='batch306')
