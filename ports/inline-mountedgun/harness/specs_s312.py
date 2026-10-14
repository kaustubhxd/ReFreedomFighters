"""specs_s312.py - mounted gun batch 312: the vtable-0x6b48f0 object (ctor, dtor body, Load, Save)."""
from pilot import S
from mg_helpers import _rnd, _obj, flush, new_log, log_stub


def _plain(c):
    return [_rnd(c, 0x40)]


def _io(slot):
    def g(c):
        log = new_log(c)
        o = _obj(c, 0x80, {slot: log_stub(c, log, slot, 1)})
        flush(c)
        return [_rnd(c, 0x40), o]
    return g


S(0x5c7ed0, 'FFPointer-like ctor (vtable 0x6b48f0)', 'thiscall', None, ret='eax', gen=_plain, note='batch312')
S(0x5c7f00, 'FFPointer-like dtor body', 'thiscall', None, gen=_plain, note='batch312')
S(0x5c7f10, 'FFPointer::Load', 'thiscall', None, ret='al', gen=_io(0x6c), note='batch312')
S(0x5c7f30, 'FFPointer::Save', 'thiscall', None, ret='al', gen=_io(0x68), note='batch312')
